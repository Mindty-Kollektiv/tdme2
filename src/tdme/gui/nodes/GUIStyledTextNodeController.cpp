#include <tdme/gui/nodes/GUIStyledTextNodeController.h>

#include <algorithm>
#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/application/Application.h>
#include <tdme/gui/events/GUIKeyboardEvent.h>
#include <tdme/gui/events/GUIMouseEvent.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUIStyledTextNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/math/Math.h>
#include <tdme/utilities/Character.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/StringTools.h>
#include <tdme/utilities/Time.h>

using std::remove;
using std::string;
using std::to_string;
using std::vector;

using tdme::application::Application;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUIStyledTextNode;
using tdme::gui::nodes::GUIStyledTextNodeController;
using tdme::gui::GUI;
using tdme::utilities::Character;
using tdme::utilities::Console;
using tdme::utilities::StringTools;
using tdme::utilities::Time;

GUIStyledTextNodeController::GUIStyledTextNodeController(GUINode* node)
	: GUINodeController(node)
{
}

void GUIStyledTextNodeController::resetCursorMode()
{
	cursorModeStarted = Time::getCurrentMillis();
	cursorMode = CURSORMODE_SHOW;
}

GUIStyledTextNodeController::CursorMode GUIStyledTextNodeController::getCursorMode()
{
	if (cursorModeStarted == -1) {
		resetCursorMode();
		return cursorMode;
	}
	if (Time::getCurrentMillis() - cursorModeStarted > CURSOR_MODE_DURATION) {
		cursorMode = cursorMode == CURSORMODE_SHOW?CURSORMODE_HIDE:CURSORMODE_SHOW;
		cursorModeStarted = Time::getCurrentMillis();
	}
	return cursorMode;
}

bool GUIStyledTextNodeController::isDisabled()
{
	return false;
}

void GUIStyledTextNodeController::setDisabled(bool disabled)
{
}

void GUIStyledTextNodeController::initialize()
{
}

void GUIStyledTextNodeController::dispose()
{
}

void GUIStyledTextNodeController::postLayout()
{
}

void GUIStyledTextNodeController::handleMouseEvent(GUINode* node, GUIMouseEvent* event)
{
	auto styledTextNode = required_dynamic_cast<GUIStyledTextNode*>(this->node);
	Vector2 nodeMousePosition;
	if (node == styledTextNode) {
		if (styledTextNode->isEventBelongingToNode(event, nodeMousePosition) == true) {
			switch(event->getType()) {
				/*
				case GUIMouseEvent::MOUSEEVENT_PRESSED:
				case GUIMouseEvent::MOUSEEVENT_DRAGGED:
					{
						styledTextNode->setSelectionPosition(event->getX(), event->getY());
						break;
					}
				*/
				case GUIMouseEvent::MOUSEEVENT_MOVED:
				case GUIMouseEvent::MOUSEEVENT_RELEASED:
					{
						// find URL area that had a hit and setup corresponding cursor
						auto& urlAreas = styledTextNode->getURLAreas();
						const GUIStyledTextNode::URLArea* urlAreaHit = nullptr;
						for (auto& urlArea: urlAreas) {
							if (nodeMousePosition.getX() < urlArea.left ||
								nodeMousePosition.getY() < urlArea.top ||
								nodeMousePosition.getX() > urlArea.left + urlArea.width ||
								nodeMousePosition.getY() > urlArea.top + urlArea.height) {
								continue;
							}
							if (Application::getMouseCursor() != MOUSE_CURSOR_HAND) Application::setMouseCursor(MOUSE_CURSOR_HAND);
							urlAreaHit = &urlArea;
							break;
						}
						if (urlAreaHit == nullptr) {
							if (Application::getMouseCursor() != MOUSE_CURSOR_ENABLED) Application::setMouseCursor(MOUSE_CURSOR_ENABLED);
						}
						// if release open browser if URL is valid
						if (urlAreaHit != nullptr) {
							node->getScreenNode()->getGUI()->addMouseOutCandidateNode(styledTextNode);
							if (event->getType() == GUIMouseEvent::MOUSEEVENT_RELEASED) {
								if (StringTools::startsWith(urlAreaHit->url, "http://") == true || StringTools::startsWith(urlAreaHit->url, "https://") == true) {
									Application::openBrowser(urlAreaHit->url);
									return;
								}
							}
						}
						//
						event->setProcessed(true);
					}
					break;
				default:
					break;
			}
		} else {
			if (Application::getMouseCursor() != MOUSE_CURSOR_ENABLED) Application::setMouseCursor(MOUSE_CURSOR_ENABLED);
		}
	}
}

void GUIStyledTextNodeController::handleKeyboardEvent(GUIKeyboardEvent* event)
{
	//
	auto maxLength = 0;
	auto disabled = false;
	auto styledTextNode = required_dynamic_cast<GUIStyledTextNode*>(this->node);
	auto keyControl = event->isControlDown();
	auto keyChar = event->getKeyChar();
	if (disabled == false &&
		keyControl == false &&
		keyChar >= 32 && keyChar < 127) {
		event->setProcessed(true);
		if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_TYPED) {
			if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
				styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
				styledTextNode->scrollToIndex();
				forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
				index = Math::min(index, selectionIndex);
				selectionIndex = -1;
			}
			if (maxLength == 0 || styledTextNode->getTextSize() < maxLength) {
				styledTextNode->insertText(index, event->getKeyChar());
				styledTextNode->scrollToIndex();
				forwardInsertText(index, 1);
				index++;
				resetCursorMode();
			}
		}
	} else {
		auto keyControlA = false;
		auto keyControlX = false;
		auto keyControlC = false;
		auto keyControlV = false;
		auto isKeyDown = event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED;
		// determine select all, copy, paste, cut
		if (Character::toLowerCase(event->getKeyChar()) == 'a' && keyControl == true) {
			keyControlA = isKeyDown;
			event->setProcessed(true);
		}
		if (Character::toLowerCase(event->getKeyChar()) == 'x' && keyControl == true) {
			keyControlX = isKeyDown;
			event->setProcessed(true);
		}
		if (Character::toLowerCase(event->getKeyChar()) == 'c' && keyControl == true) {
			keyControlC = isKeyDown;
			event->setProcessed(true);
		}
		if (Character::toLowerCase(event->getKeyChar()) == 'v' && keyControl == true) {
			keyControlV = isKeyDown;
			event->setProcessed(true);
		}
		// handle them ...
		if (keyControlA == true) {
			auto& text = styledTextNode->getText();
			index = 0;
			selectionIndex = text.size() - 1;
		} else
		if (keyControlX == true) {
			Application::getApplication()->setClipboardContent(StringTools::substring(styledTextNode->getText().getString(), Math::min(index, selectionIndex), Math::max(index, selectionIndex)));
			if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
				styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
				styledTextNode->scrollToIndex();
				forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
				index = Math::min(index, selectionIndex);
				selectionIndex = -1;
			}
		} else
		if (keyControlC == true) {
			if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
				Application::getApplication()->setClipboardContent(StringTools::substring(styledTextNode->getText().getString(), Math::min(index, selectionIndex), Math::max(index, selectionIndex)));
			}
		} else
		if (keyControlV == true) {
			auto clipboardContent = Application::getApplication()->getClipboardContent();
			if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
				if (maxLength == 0 || styledTextNode->getTextSize() - Math::abs(index - selectionIndex) + clipboardContent.size() < maxLength) {
					styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
					styledTextNode->scrollToIndex();
					forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
					index = Math::min(index, selectionIndex);
					selectionIndex = -1;
				}
			}
			if (maxLength == 0 || styledTextNode->getTextSize() + clipboardContent.size() < maxLength) {
				styledTextNode->insertText(index, clipboardContent);
				styledTextNode->scrollToIndex();
				forwardInsertText(index, clipboardContent.size());
				index+= clipboardContent.size();
			}
		} else {
			// navigation, delete, return
			switch (event->getKeyCode()) {
			case GUIKeyboardEvent::KEYCODE_LEFT: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						if (index > 0) {
							index--;
							styledTextNode->scrollToIndex();
							resetCursorMode();
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_RIGHT: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						if (index < styledTextNode->getTextSize()) {
							index++;
							styledTextNode->scrollToIndex();
							resetCursorMode();
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_UP: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						// find index of current line newline and store difference
						auto lineNewLineIndex = styledTextNode->getPreviousNewLine(index) + (index == 0?0:1);
						// current line index
						auto lineIndex = Math::max(index - lineNewLineIndex, 0);
						// find index of previous newline and iterate to difference if possible
						auto previousNewLineIndex = styledTextNode->getPreviousNewLine(styledTextNode->getPreviousNewLine(index - 1) - 1);
						if (previousNewLineIndex != 0) previousNewLineIndex++;
						// find next index of previous 2 newline as upper bound
						auto nextNewLineIndex = styledTextNode->getNextNewLine(previousNewLineIndex);
						//
						index = Math::min(previousNewLineIndex + lineIndex, nextNewLineIndex);
						styledTextNode->scrollToIndex();
						//
						resetCursorMode();
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_DOWN: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						// find index of current line newline and store difference
						auto lineNewLineIndex = styledTextNode->getPreviousNewLine(index) + (index == 0?0:1);
						// current line index
						auto lineIndex = Math::max(index - lineNewLineIndex, 0);
						// find index of next newline
						auto nextNewLineIndex = styledTextNode->getNextNewLine(index);
						// find index of next * 2 newline as upper bound
						auto next2NewLineIndex = styledTextNode->getNextNewLine(nextNewLineIndex + 1);
						// iterate to difference if possible
						index = Math::min(nextNewLineIndex + 1 + lineIndex, next2NewLineIndex);
						//
						styledTextNode->scrollToIndex();
						resetCursorMode();
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_PAGE_UP: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						index = styledTextNode->doPageUp();
						resetCursorMode();
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_PAGE_DOWN: {
					event->setProcessed(true);
					if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						index = styledTextNode->doPageDown();
						resetCursorMode();
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_BACKSPACE: {
					if (disabled == false) {
						event->setProcessed(true);
						if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
							if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
								styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								styledTextNode->scrollToIndex();
								forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								index = Math::min(index, selectionIndex);
								selectionIndex = -1;
							} else
							if (index > 0) {
								styledTextNode->removeText(index - 1, 1);
								styledTextNode->scrollToIndex();
								forwardRemoveText(index - 1, 1);
								index--;
								resetCursorMode();
							}
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_DELETE: {
					if (disabled == false) {
						event->setProcessed(true);
						if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
							if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
								styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								styledTextNode->scrollToIndex();
								forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								index = Math::min(index, selectionIndex);
								selectionIndex = -1;
							} else
							if (index < styledTextNode->getTextSize()) {
								styledTextNode->removeText(index, 1);
								styledTextNode->scrollToIndex();
								forwardRemoveText(index, 1);
								resetCursorMode();
							}
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_RETURN:{
					if (disabled == false) {
						event->setProcessed(true);
						if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
							if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
								styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								styledTextNode->scrollToIndex();
								forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								index = Math::min(index, selectionIndex);
								selectionIndex = -1;
							}
							if (maxLength == 0 || styledTextNode->getTextSize() < maxLength) {
								styledTextNode->insertText(index, '\n');
								styledTextNode->scrollToIndex();
								forwardInsertText(index, 1);
								index++;
								resetCursorMode();
							}
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_TAB:{
					if (disabled == false) {
						event->setProcessed(true);
						if (event->getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
							if (index != -1 && selectionIndex != -1 && index != selectionIndex) {
								styledTextNode->removeText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								styledTextNode->scrollToIndex();
								forwardRemoveText(Math::min(index, selectionIndex), Math::abs(index - selectionIndex));
								index = Math::min(index, selectionIndex);
								selectionIndex = -1;
							}
							if (maxLength == 0 || styledTextNode->getTextSize() < maxLength) {
								styledTextNode->insertText(index, '\t');
								styledTextNode->scrollToIndex();
								forwardInsertText(index, 1);
								index++;
								resetCursorMode();
							}
						}
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_POS1: {
					if (disabled == false) {
						event->setProcessed(true);
						resetCursorMode();
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						if (keyControl == true) {
							index = 0;
						} else {
							// find index of previous newline
							index = styledTextNode->getPreviousNewLine(index - 1);
							if (index != 0) index++;
						}
						styledTextNode->scrollToIndex();
					}
				}
				break;
			case GUIKeyboardEvent::KEYCODE_END: {
					if (disabled == false) {
						resetCursorMode();
						if (event->isShiftDown() == false) {
							selectionIndex = -1;
						} else {
							if (selectionIndex == -1) selectionIndex = index;
						}
						if (keyControl == true) {
							index = styledTextNode->getTextSize() - 1;
						} else {
							// find index of next newline
							index = styledTextNode->getNextNewLine(index);;
						}
						styledTextNode->scrollToIndex();
					}
				}
				break;
			}
		}
	}
}

void GUIStyledTextNodeController::tick()
{
}

void GUIStyledTextNodeController::onFocusGained()
{
}

void GUIStyledTextNodeController::onFocusLost()
{
}

bool GUIStyledTextNodeController::hasValue()
{
	return false;
}

const MutableString& GUIStyledTextNodeController::getValue()
{
	auto styledTextNode = required_dynamic_cast<GUIStyledTextNode*>(this->node);
	return styledTextNode->getText();
}

void GUIStyledTextNodeController::setValue(const MutableString& value)
{
	auto styledTextNode = required_dynamic_cast<GUIStyledTextNode*>(this->node);
	styledTextNode->setText(value);
}

void GUIStyledTextNodeController::onSubTreeChange()
{
}

void GUIStyledTextNodeController::addChangeListener(ChangeListener* listener)
{
	removeChangeListener(listener);
	changeListeners.push_back(listener);
}

void GUIStyledTextNodeController::removeChangeListener(ChangeListener* listener)
{
	changeListeners.erase(std::remove(changeListeners.begin(), changeListeners.end(), listener), changeListeners.end());
}
