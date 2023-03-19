#include <tdme/tools/editor/misc/TextFormatter.h>

#include <string>

#include <tdme/tdme.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/gui/nodes/GUIStyledTextNode.h>
#include <tdme/os/filesystem/FileSystem.h>
#include <tdme/os/filesystem/FileSystemInterface.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/ExceptionBase.h>
#include <tdme/utilities/Float.h>
#include <tdme/utilities/Integer.h>
#include <tdme/utilities/Properties.h>
#include <tdme/utilities/StringTools.h>

#include <ext/tinyxml/tinyxml.h>

#define AVOID_NULLPTR_STRING(arg) (arg == nullptr?"":arg)

using std::string;
using std::to_string;

using tdme::tools::editor::misc::TextFormatter;

using tdme::gui::GUIParser;
using tdme::gui::nodes::GUIStyledTextNode;
using tdme::os::filesystem::FileSystem;
using tdme::os::filesystem::FileSystemInterface;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::ExceptionBase;
using tdme::utilities::Float;
using tdme::utilities::Integer;
using tdme::utilities::Properties;
using tdme::utilities::StringTools;

using tinyxml::TiXmlAttribute;
using tinyxml::TiXmlDocument;
using tinyxml::TiXmlElement;

TextFormatter* TextFormatter::instance = nullptr;

TextFormatter::TextFormatter() {
	// read colors from theme
	commentLineColor = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.commentline", "#888a85"));
	commentInlineColor = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.commentinline", "#888a85"));
	literalColor = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.literalcolor", "#8ae234"));
	keyword1Color = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.keyword1color", "#cb551a"));
	keyword2Color = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.keyword2color", "#eabc19"));
	preprocessorColor = GUIColor(GUIParser::getEngineThemeProperties()->get("color.text.preprocessorcolor", "#ab7779"));
	//
	for (auto& language: languages) {
		language.preprocessorLineKeywordsTokenized = StringTools::tokenize(language.preprocessorLineKeywords, " ");
		language.keywords1Tokenized = StringTools::tokenize(language.keywords1, " ");
		language.keywords2Tokenized = StringTools::tokenize(language.keywords2, " ");
		language.datatypeLiteralSuffixesTokenized = StringTools::tokenize(language.datatypeLiteralSuffixes, " ");
	}
}

void TextFormatter::format(const string& extension, GUIStyledTextNode* textNode, int charStartIdx, int charEndIdx) {
	if (std::find(xmlLanguage.extensions.begin(), xmlLanguage.extensions.end(), extension) != xmlLanguage.extensions.end()) {
		textNode->unsetStyles();
		auto& language = xmlLanguage;
		auto& code = textNode->getText().getString();
		auto startIdx = 0;
		auto endIdx = -1;
		auto lc = '\0';
		auto llc = '\0';
		auto lllc = '\0';
		auto nc = '\0';
		auto inlineComment = false;
		auto quote = '\0';
		auto tag = false;
		auto tagMode = 0;
		auto attribute = false;
		for (auto i = 0; i < code.size(); i++) {
			auto c = code[i];
			auto nc = i + 1 < code.size()?code[i + 1]:'\0';
			auto nnc = i + 2 < code.size()?code[i + 2]:'\0';
			auto nnnc = i + 3 < code.size()?code[i + 3]:'\0';
			if (tag == false && inlineComment == false && quote == '\0') {
				if (language.commentInlineStart.empty() == false &&
					c == language.commentInlineStart[0] &&
					nc == language.commentInlineStart[1] &&
					nnc == language.commentInlineStart[2] &&
					nnnc == language.commentInlineStart[3]) {
					inlineComment = true;
					startIdx = i - 1;
					endIdx = -1;
				} else
				if (c == '<') {
					tag = true;
					tagMode = 0;
					startIdx = i;
					endIdx = -1;
				}
			} else
			if (inlineComment == true) {
				if (language.commentInlineEnd.empty() == false &&
					llc == language.commentInlineEnd[0] &&
					lc == language.commentInlineEnd[1] &&
					c == language.commentInlineEnd[2]) {
					inlineComment = false;
					endIdx = i + 1;
					textNode->setTextStyle(startIdx, endIdx - 1, commentInlineColor);
					startIdx = endIdx + 2;
					endIdx = -1;
				}
			} else
			if (quote != '\0') {
				if (c == quote) {
					quote = '\0';
					endIdx = i + 1;
					textNode->setTextStyle(startIdx, endIdx - 1, literalColor);
					startIdx = endIdx;
					endIdx = -1;
				}
			} else
			if (tag == true) {
				if (quote == '\0' && language.quotes.find(c) != string::npos) {
					endIdx = i;
					if (startIdx != endIdx) {
						textNode->setTextStyle(startIdx, endIdx - 1, tagMode == 0?keyword1Color:keyword2Color);
						tagMode++;
					}
					quote = c;
					startIdx = i;
					endIdx = -1;
				} else
				if (lc == '/' && c == '>') {
					endIdx = i - 1;
					if (startIdx != endIdx) {
						textNode->setTextStyle(startIdx, endIdx - 1, tagMode == 0?keyword1Color:keyword2Color);
					}
					textNode->setTextStyle(endIdx, endIdx - 1 + 2, keyword1Color);
					startIdx = i + 1;
					endIdx = -1;
					tag = false;
					tagMode = 0;
				} else
				if (c == '>') {
					endIdx = i;
					if (startIdx != endIdx) {
						textNode->setTextStyle(startIdx, endIdx - 1, tagMode == 0?keyword1Color:keyword2Color);
					}
					textNode->setTextStyle(endIdx, endIdx - 1 + 1, keyword1Color);
					startIdx = i + 1;
					endIdx = -1;
					tag = false;
					tagMode = 0;
				} else
				if (language.delimiters.find(c) != string::npos) {
					endIdx = i;
					if (startIdx != endIdx) {
						textNode->setTextStyle(startIdx, endIdx - 1, tagMode == 0?keyword1Color:keyword2Color);
					}
					startIdx = i + 1;
					endIdx = -1;
					tagMode++;
				}
			}
			lllc = llc;
			llc = lc;
			lc = c;
		}
	} else
	if (std::find(propertiesLanguage.extensions.begin(), propertiesLanguage.extensions.end(), extension) != propertiesLanguage.extensions.end()) {
		auto& language = propertiesLanguage;
		auto& code = textNode->getText().getString();
		auto commentCount = 0;
		auto delimiterCount = 0;
		auto nonWhitespaceCount = 0;
		auto startIdx = -1;
		auto endIdx = -1;
		auto commentLine = false;
		if (charStartIdx == -1) {
			charStartIdx = 0;
		} else {
			// find index of previous newline and store difference
			auto previousNewLineIndex = charStartIdx;
			while (previousNewLineIndex >= 0 && code[previousNewLineIndex] != '\n') previousNewLineIndex--;
			previousNewLineIndex = Math::min(previousNewLineIndex + 1, code.size() - 1);
			charStartIdx = previousNewLineIndex;
		}
		if (charEndIdx == -1) {
			charEndIdx = code.size() - 1;
		} else {
			// find index of next newline
			auto nextNewLineIndex = Math::min(code[charEndIdx] == '\n'?charEndIdx + 1:charEndIdx, code.size() - 1);
			while (nextNewLineIndex < code.size() && code[nextNewLineIndex] != '\n') nextNewLineIndex++;
			nextNewLineIndex = Math::min(nextNewLineIndex + 1, code.size() - 1);
			charEndIdx = nextNewLineIndex;
		}
		textNode->unsetTextStyle(charStartIdx, charEndIdx);
		for (auto i = charStartIdx; i >= 0 && i <= charEndIdx; i++) {
			auto c = code[i];
			if (c == '\n') {
				endIdx = i;
				if (commentLine == true) {
					if (startIdx != -1 && endIdx != -1 && startIdx != endIdx) {
						textNode->setTextStyle(startIdx, endIdx - 1, commentLineColor);
					}
				} else
				if (startIdx != -1 && endIdx != -1 && startIdx != endIdx) {
					textNode->setTextStyle(startIdx, endIdx - 1, literalColor);
				}
				commentCount = 0;
				delimiterCount = 0;
				nonWhitespaceCount = 0;
				startIdx = -1;
				endIdx = -1;
				commentLine = false;
			} else
			if (language.whitespaces.find(c) != string::npos) {
				// no op
			} else
			if (c == language.comment && nonWhitespaceCount == 0) {
				startIdx = i;
				endIdx = -1;
				commentLine = true;
				nonWhitespaceCount++;
			} else
			if (c == language.delimiter && nonWhitespaceCount > 0) {
				endIdx = i;
				if (startIdx != -1 && startIdx != endIdx) {
					textNode->setTextStyle(startIdx, endIdx - 1, keyword2Color);
				}
				startIdx = i + 1;
				endIdx = -1;
				nonWhitespaceCount++;
			} else {
				if (nonWhitespaceCount == 0) startIdx = i;
				nonWhitespaceCount++;
			}
		}
		endIdx = charEndIdx;
		if (commentLine == true) {
			textNode->setTextStyle(startIdx, endIdx - 1, commentLineColor);
		} else
		if (startIdx != -1 && startIdx != endIdx) {
			textNode->setTextStyle(startIdx, endIdx - 1, literalColor);
		}
	} else {
		auto foundLanguage = false;
		for (auto& language: languages) {
			if (std::find(language.extensions.begin(), language.extensions.end(), extension) != language.extensions.end()) {
				// Console::println("void TextFormatter::format(): " + to_string(charStartIdx) + " ... " + to_string(charEndIdx));
				foundLanguage = true;
				auto& code = textNode->getText().getString();
				auto& preprocessorLineKeywords = language.preprocessorLineKeywordsTokenized;
				auto& keywords1 = language.keywords1Tokenized;
				auto& keywords2 = language.keywords2Tokenized;
				auto& datatypeLiteralSuffixes = language.datatypeLiteralSuffixesTokenized;
				auto startIdx = 0;
				auto endIdx = -1;
				auto lc = '\0';
				auto llc = '\0';
				auto inlineComment = false;
				auto lineComment = false;
				auto preprocessorLine = false;
				auto quote = '\0';
				if (charStartIdx == -1) {
					charStartIdx = 0;
				} else {
					// TODO: maybe find last quote also or last inline comment start
					// find index of previous newline and store difference
					auto previousNewLineIndex = Math::max(code[charStartIdx] == '\n'?charStartIdx - 1:charStartIdx, 0);
					while (previousNewLineIndex >= 0 && code[previousNewLineIndex] != '\n') previousNewLineIndex--;
					previousNewLineIndex = Math::min(previousNewLineIndex + 1, code.size() - 1);
					charStartIdx = previousNewLineIndex;
					startIdx = previousNewLineIndex;
				}
				if (charEndIdx == -1) {
					charEndIdx = code.size() - 1;
				} else {
					// TODO: maybe find next quote also or next inline comment start
					// find index of next newline
					auto nextNewLineIndex = charEndIdx;
					while (nextNewLineIndex < code.size() && code[nextNewLineIndex] != '\n') nextNewLineIndex++;
					charEndIdx = nextNewLineIndex;
				}
				// Console::println("void TextFormatter::format2(): " + to_string(charStartIdx) + " ... " + to_string(charEndIdx));
				textNode->unsetTextStyle(charStartIdx, charEndIdx);
				lc = charStartIdx - 1 >= 0 && charStartIdx - 1 < code.size()?code[charStartIdx - 1]:'\0';
				llc = charStartIdx - 2 >= 0 && charStartIdx - 2 < code.size()?code[charStartIdx - 2]:'\0';
				for (auto i = charStartIdx; i >= 0 && i <= charEndIdx; i++) {
					auto c = code[i];
					auto nc = i + 1 < code.size()?code[i + 1]:'\0';
					auto nnc = i + 2 < code.size()?code[i + 2]:'\0';
					auto nnnc = i + 3 < code.size()?code[i + 3]:'\0';
					if (inlineComment == false && lineComment == false && preprocessorLine == false && quote == '\0') {
						if (language.commentLine.empty() == false &&
							(c == language.commentLine[0]) &&
							(language.commentLine.size() <= 1 || nc == language.commentLine[1]) &&
							(language.commentLine.size() <= 2 || nnc == language.commentLine[2]) &&
							(language.commentLine.size() <= 3 || nnnc == language.commentLine[3])) {
							lineComment = true;
							startIdx = i;
							endIdx = -1;
						} else
						if (language.commentInlineStart.empty() == false && (language.commentInlineStart.size() == 1 || c == language.commentInlineStart[0]) && nc == language.commentInlineStart[language.commentInlineStart.size() - 1]) {
							inlineComment = true;
							startIdx = i;
							endIdx = -1;
						} else
						if (quote == '\0' && language.keywordQuotes.find(c) != string::npos) {
							quote = c;
							startIdx = i;
							endIdx = -1;
						} else {
							// delimiter
							if (language.keywordDelimiters.find(c) != string::npos) {
								endIdx = i;
							} else
							if (i == charEndIdx) {
								endIdx = charEndIdx;
							}
							if (startIdx != -1 && endIdx != -1 && startIdx != endIdx) {
								while (code[startIdx] == ' ' || code[startIdx] == '\t') startIdx++;
								auto word = StringTools::trim(StringTools::substring(code, startIdx, endIdx));
								if (word.empty() == true) continue;
								auto literalWord = word;
								for (auto& datatypeLiteralSuffix: datatypeLiteralSuffixes) {
									if (StringTools::endsWith(word, datatypeLiteralSuffix) == true) {
										auto dotCount = 0;
										auto valid = true;
										for (auto j = 0; j < word.size() - datatypeLiteralSuffix.size(); j++) {
											if (word[j] == '.') {
												dotCount++;
												if (dotCount > 1) {
													valid = false;
													break;
												}
											} else
											if (isdigit(word[j]) == 0) {
												valid = false;
												break;
											}
										}
										if (valid == true) {
											literalWord = StringTools::substring(word, 0, word.size() - datatypeLiteralSuffix.size());
											break;
										}
									}
								}
								if (Integer::is(literalWord) == true || Float::is(literalWord) == true) {
									textNode->setTextStyle(startIdx, endIdx - 1, literalColor);
								} else {
									// Console::println("Word: '" + word + "'; " + to_string(startIdx) + " ... " + to_string(endIdx));
									for (auto& keyword: keywords1) {
										if (word == keyword) {
											textNode->setTextStyle(startIdx, endIdx - 1, keyword1Color);
											break;
										}
									}
									for (auto& keyword: keywords2) {
										if (word == keyword) {
											textNode->setTextStyle(startIdx, endIdx - 1, keyword2Color);
											break;
										}
									}
									for (auto& keyword: preprocessorLineKeywords) {
										if (word == keyword) {
											if (c == '\n' || i == charEndIdx) {
												textNode->setTextStyle(startIdx, endIdx - 1, preprocessorColor);
											} else {
												preprocessorLine = true;
												endIdx = startIdx - 1;
											}
											break;
										}
									}
								}
								startIdx = endIdx + 1;
								endIdx = -1;
							}
						}
					} else
					if (lineComment == true) {
						if (c == '\n' || i == charEndIdx) {
							lineComment = false;
							endIdx = i;
							textNode->setTextStyle(startIdx, endIdx, commentLineColor);
							startIdx = endIdx + 1;
							endIdx = -1;
						}
					} else
					if (inlineComment == true) {
						if (language.commentInlineEnd.empty() == false && (language.commentInlineEnd.size() == 1 || lc == language.commentInlineEnd[0]) && c == language.commentInlineEnd[language.commentInlineEnd.size() - 1]) {
							inlineComment = false;
							endIdx = i;
							textNode->setTextStyle(startIdx, endIdx - 1, commentInlineColor);
							startIdx = endIdx + 1;
							endIdx = -1;
						}
					} else
					if (preprocessorLine == true) {
						if (c == '\n' || i == charEndIdx) {
							preprocessorLine = false;
							endIdx = i;
							textNode->setTextStyle(startIdx, endIdx, preprocessorColor);
							startIdx = endIdx + 1;
							endIdx = -1;
						}
					} else
					if (quote != '\0') {
						if (c == quote && (lc != '\\' || llc == '\\')) {
							quote = '\0';endIdx = -1;
							endIdx = i + 1;
							textNode->setTextStyle(startIdx, endIdx - 1, literalColor);
							startIdx = endIdx + 1;
							endIdx = -1;
						}
					}
					llc = lc;
					lc = c;
				}

				// done
				break;
			}
		}
		// unset styles if no language found
		if (foundLanguage == false) textNode->unsetStyles();
	}
}

const vector<TiXmlElement*> TextFormatter::getChildrenByTagName(TiXmlElement* parent, const char* name)
{
	vector<TiXmlElement*> elementList;
	for (auto *child = parent->FirstChildElement(name); child != nullptr; child = child->NextSiblingElement(name)) {
		elementList.push_back(child);
	}
	return elementList;
}

const vector<TiXmlElement*> TextFormatter::getChildren(TiXmlElement* parent)
{
	vector<TiXmlElement*> elementList;
	for (auto *child = parent->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
		elementList.push_back(child);
	}
	return elementList;
}

const TextFormatter::CodeCompletion* TextFormatter::loadCodeCompletion(const string& extension) {
	for (auto& language: languages) {
		if (std::find(language.extensions.begin(), language.extensions.end(), extension) != language.extensions.end()) {
			try {
				// load dae xml document
				auto xmlContent = FileSystem::getInstance()->getContentAsString("resources/engine/code-completion", StringTools::toLowerCase(language.name) + ".xml");
				TiXmlDocument xmlDocument;
				xmlDocument.Parse(xmlContent.c_str());
				if (xmlDocument.Error() == true) {
					throw ExceptionBase(string("Could not parse XML. Error='") + string(xmlDocument.ErrorDesc()) + string("'"));
				}
				TiXmlElement* xmlRoot = xmlDocument.RootElement();
				auto codeCompletion = new CodeCompletion();
				codeCompletion->name = language.name;
				for (auto xmlKeywordElement: getChildrenByTagName(xmlRoot, "keyword")) {
					auto symbol = CodeCompletion::CodeCompletionSymbol();
					symbol.name = string(AVOID_NULLPTR_STRING(xmlKeywordElement->Attribute("name")));
					for (auto xmlOverloadElement: getChildrenByTagName(xmlKeywordElement, "overload")) {
						auto methodOverload = CodeCompletion::CodeCompletionSymbol::CodeCompletionMethodOverload();
						methodOverload.returnValue = string(AVOID_NULLPTR_STRING(xmlOverloadElement->Attribute("return-value")));
						for (auto xmlParameterElement: getChildrenByTagName(xmlOverloadElement, "parameter")) {
							methodOverload.parameters.push_back(string(AVOID_NULLPTR_STRING(xmlParameterElement->Attribute("name"))));
						}
						symbol.overloadList.push_back(methodOverload);
					}
					codeCompletion->symbols.push_back(symbol);
				}
				codeCompletion->delimiters = language.keywordDelimiters;
				codeCompletion->statementDelimiter = language.statementDelimiter;
				return codeCompletion;
			} catch (Exception &exception) {
				Console::println("TextFormatter::loadCodeCompletion(): found language: '" + language.name + "': An error occurred: " + string(exception.what()));
			}
			break;
		}
	}
	return nullptr;
}

const string TextFormatter::createMarkdownGUIXML(const string& pathName, const string& fileName) {
	vector<string> markdownLines;
	FileSystem::getInstance()->getContentAsStringArray(pathName, fileName, markdownLines);
	string xml;
	xml+= "<screen id='markdown' min-width='1024' min-height='768' max-width='3200' max-height='1800'>\n";
	xml+= "\t<scrollarea width='100%' height='100%'>\n";
	xml+= "\t\t<layout alignment='vertical' width='100%' height='auto'>\n";
	auto inTable = false;
	auto inTableIdx = 0;
	auto inCode = false;
	string inCodeString;
	for (auto markdownLine: markdownLines) {
		// TODO: we should not have here \r \n
		markdownLine = StringTools::replace(markdownLine, "\r", "");
		markdownLine = StringTools::replace(markdownLine, "\n", "");
		//
		markdownLine = StringTools::replace(markdownLine, "\\<", "<");
		markdownLine = StringTools::replace(markdownLine, "\\>", ">");
		//
		auto markdownLineTrimmed = StringTools::trim(markdownLine);
		//
		if (inTable == true && StringTools::startsWith(markdownLine, "|") == false) {
			inTable = false;
			inTableIdx = 0;
			xml+= "</table>\n";
		}
		if (StringTools::startsWith(markdownLine, "```") == true) {
			if (inCode == false) {
				inCode = true;
			} else {
				xml+= "<space height='10'/>\n";
				xml+= "<styled-text font='{$font.default}' size='{$fontsize.default}' color='{$color.font_normal}' background-color='{$color.element_midground}' border-color='{$color.element_frame}' border='1' padding='5' width='*' height='auto' preformatted='true'>\n";
				xml+= "	<![CDATA[\n";
				xml+= StringTools::replace(StringTools::replace(inCodeString, "[", "\\["), "]", "\\]");
				xml+= "	]]>\n";
				xml+= "</styled-text>\n";
				xml+= "<space height='10'/>\n";
				inCodeString.clear();
				inCode = false;
			}
		} else
		if (inCode == true) {
			inCodeString+= markdownLine + "\n";
		} else
		if (inTable == false && markdownLineTrimmed.empty() == true) {
			xml+= "<space height='20'/>\n";
		} else
		if (inTable == false && StringTools::startsWith(markdownLineTrimmed, "-") == true) {
			string textSize = "{$fontsize.default}";
			auto bulletPointIdx = StringTools::firstIndexOf(markdownLine, '-');
			auto bulletPoint = StringTools::trim(StringTools::substring(markdownLine, bulletPointIdx + 1));
			auto indent = bulletPointIdx / 2;
			xml+= "<layout alignment='horizontal' width='100%' height='auto'>\n";
			xml+= "\t<space width='" + to_string((bulletPointIdx + 1) * 10) + "'/>\n";
			xml+= "\t<styled-text font='{$font.default}' size='" + textSize + "' color='{$color.font_normal}' width='*' height='auto'>• " + GUIParser::escapeQuotes(bulletPoint) + "</styled-text>\n";
			xml+= "</layout>\n";
		} else
		// image
		if (StringTools::startsWith(markdownLine, "!") == true) {
			string tooltip;
			{
				auto tooltipStartPosition = StringTools::indexOf(markdownLine, '[');
				auto tooltipEndPosition = StringTools::indexOf(markdownLine, ']');
				if (tooltipStartPosition != string::npos &&
					tooltipEndPosition != string::npos &&
					tooltipEndPosition > tooltipStartPosition) {
					tooltip = StringTools::substring(markdownLine, tooltipStartPosition + 1, tooltipEndPosition);
				}
			}
			string source;
			{
				string url;
				auto urlStartPosition = StringTools::indexOf(markdownLine, '(');
				auto urlEndPosition = StringTools::indexOf(markdownLine, ')');
				if (urlStartPosition != string::npos &&
					urlEndPosition != string::npos &&
					urlEndPosition > urlStartPosition) {
					url = StringTools::substring(markdownLine, urlStartPosition + 1, urlEndPosition);
				}
				if (StringTools::startsWith(url, "https://raw.githubusercontent.com/andreasdr/tdme2/master/") == true) {
					source = StringTools::substring(url, string("https://raw.githubusercontent.com/andreasdr/tdme2/master/").size());
				}
			}
			//
			if (source.empty() == false) {
				xml+= "<image src='" + GUIParser::escapeQuotes(FileSystem::getInstance()->getCurrentWorkingPathName() + "/" + source) + "' tooltip='" + GUIParser::escapeQuotes(tooltip) + "' />\n";
			}
		} else
		if (StringTools::startsWith(markdownLine, "|") == true) {
			if (inTable == false) {
				inTable = true;
				xml+= "<table width='auto' height='auto'>\n";
			}
			markdownLine = StringTools::trim(markdownLine);
			vector<string> tableColumnStrings = { "" };
			auto separator = true;
			for (auto i = 1; i < markdownLine.size(); i++) {
				if (markdownLine[i - 1] != '\\' && markdownLine[i] == '|') {
					if (i != markdownLine.size() - 1) tableColumnStrings.push_back(string());
					continue;
				}
				tableColumnStrings[tableColumnStrings.size() - 1]+= markdownLine[i];
				if (markdownLine[i] != '-' && markdownLine[i] != ' ' && markdownLine[i] != '\t' && markdownLine[i] != '|') separator = false;
			}
			if (separator == false) {
				xml+= "<table-row>\n";
				for (auto tableColumnString: tableColumnStrings) {
					tableColumnString = StringTools::replace(tableColumnString, "\\<", "<");
					tableColumnString = StringTools::replace(tableColumnString, "\\>", ">");
					tableColumnString = StringTools::replace(tableColumnString, "\\|", "|");
					string textSize = "{$fontsize.default}";
					string backgroundColor = (inTableIdx % 2) == 0?"{$color.element_midground}":"{$color.element_background}";
					xml+= "<table-cell padding='5' background-color='" + backgroundColor + "' border='1' border-color='{$color.element_frame}'>\n";
					xml+= "\t<text font='{$font.default}' size='" + textSize + "' text='" + GUIParser::escapeQuotes(StringTools::trim(tableColumnString)) + "' color='{$color.font_normal}' width='auto' height='auto' />\n";
					xml+= "</table-cell>\n";
				}
				xml+= "</table-row>\n";
				inTableIdx++;
			}
		} else {
			// text
			string textSize = "{$fontsize.default}";
			if (StringTools::startsWith(markdownLine, "####") == true) {
				markdownLine = StringTools::trim(StringTools::substring(markdownLine, 4));
				textSize = "{$fontsize.h4}";
			} else
			if (StringTools::startsWith(markdownLine, "###") == true) {
				markdownLine = StringTools::trim(StringTools::substring(markdownLine, 3));
				textSize = "{$fontsize.h3}";
			} else
			if (StringTools::startsWith(markdownLine, "##") == true) {
				markdownLine = StringTools::trim(StringTools::substring(markdownLine, 2));
				textSize = "{$fontsize.h2}";
			} else
			if (StringTools::startsWith(markdownLine, "#") == true) {
				markdownLine = StringTools::trim(StringTools::substring(markdownLine, 1));
				textSize = "{$fontsize.h1}";
			}
			xml+= "<styled-text font='{$font.default}' size='" + textSize + "' color='{$color.font_normal}' width='*' height='auto'>" + GUIParser::escapeQuotes(markdownLine) + "</styled-text>\n";
		}
	}
	if (inCode == true) {
		xml+= "<space height='10'/>\n";
		xml+= "<styled-text font='{$font.default}' size='{$fontsize.default}' color='{$color.font_normal}' background-color='{$color.element_midground}' border-color='{$color.element_frame}' border='1' padding='5' width='*' height='auto' preformatted='true'>\n";
		xml+= "	<![CDATA[\n";
		xml+= StringTools::replace(StringTools::replace(inCodeString, "[", "\\["), "]", "\\]");
		xml+= "	]]>\n";
		xml+= "</styled-text>\n";
		xml+= "<space height='10'/>\n";
	}
	if (inTable == true) xml+= "</table>\n";
	//
	xml+= "\t\t</layout>\n";
	xml+= "\t</scrollarea>\n";
	xml+= "</screen>\n";
	// FileSystem::getStandardFileSystem()->setContentFromString(".", "xxx.xml", xml);
	return xml;
}
