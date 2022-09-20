#include <tdme/engine/logics/LogicMiniScript.h>

#include <span>
#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/logics/Context.h>
#include <tdme/engine/logics/Logic.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Object.h>
#include <tdme/engine/ParticleSystem.h>
#include <tdme/engine/Timing.h>
#include <tdme/gui/events/GUIKeyboardEvent.h>
#include <tdme/gui/events/GUIMouseEvent.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/utilities/Character.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/MiniScript.h>

using std::span;
using std::string;
using std::to_string;
using std::vector;

using tdme::engine::logics::LogicMiniScript;

using tdme::engine::model::Color4;
using tdme::engine::logics::Context;
using tdme::engine::logics::Logic;
using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Object;
using tdme::engine::ParticleSystem;
using tdme::engine::Timing;
using tdme::gui::events::GUIKeyboardEvent;
using tdme::gui::events::GUIMouseEvent;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::utilities::Character;
using tdme::utilities::Console;
using tdme::utilities::MiniScript;

LogicMiniScript::LogicMiniScript(): MiniScript() {
}

LogicMiniScript::~LogicMiniScript() {
}


void LogicMiniScript::registerStateMachineStates() {
	MiniScript::registerStateMachineStates();
}

void LogicMiniScript::registerMethods() {
	MiniScript::registerMethods();
	{
		//
		class ScriptMethodLogicGetId: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicGetId(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_STRING),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.getId";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue.setValue(miniScript->logic->getId());
			}
		};
		registerMethod(new ScriptMethodLogicGetId(this));
	}
	{
		//
		class ScriptMethodLogicSignalSend: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicSignalSend(LogicMiniScript* miniScript):
				ScriptMethod({
					{ .type = ScriptVariableType::TYPE_STRING, .name = "logicId", .optional = false },
					{ .type = ScriptVariableType::TYPE_STRING, .name = "signal", .optional = false }
				}),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.signal.send";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string logicId;
				string signal;
				if (miniScript->getStringValue(argumentValues, 0, logicId) == true &&
					miniScript->getStringValue(argumentValues, 1, signal) == true) {
					auto logic = static_cast<Logic*>(miniScript->context->getLogic(logicId));
					if (logic == nullptr) {
						Console::println("ScriptMethodLogicSignalSend::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": no logic with given id: " + logicId);
						return;
					} else {
						vector<ScriptVariable> arguments(argumentValues.size() - 2);
						for (auto i = 2; i < argumentValues.size(); i++) arguments.push_back(argumentValues[i]);
						logic->addSignal(signal, arguments);
					}
				} else {
					Console::println("ScriptMethodLogicSignalSend::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, argument 1: string expected");
					miniScript->startErrorScript();
				}
			}
			bool isVariadic() override {
				return true;
			}
		};
		registerMethod(new ScriptMethodLogicSignalSend(this));
	}
	{
		//
		class ScriptMethodLogicSignalHas: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicSignalHas(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.signal.has";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue.setValue(miniScript->logic->hasSignal());
			}
		};
		registerMethod(new ScriptMethodLogicSignalHas(this));
	}
	{
		//
		class ScriptMethodLogicSignalGetName: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicSignalGetName(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_STRING),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.signal.getName";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue.setValue(miniScript->logic->getSignalName());
			}
		};
		registerMethod(new ScriptMethodLogicSignalGetName(this));
	}
	{
		//
		class ScriptMethodLogicSignalGetArgument: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicSignalGetArgument(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_INTEGER, .name = "argumentIndex", .optional = false }
					},
					ScriptVariableType::TYPE_PSEUDO_MIXED
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.signal.getArgument";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				int64_t argumentIndex;
				if (miniScript->getIntegerValue(argumentValues, 0, argumentIndex) == true) {
					returnValue = miniScript->logic->getSignalArgument(argumentIndex);
				} else {
					Console::println("ScriptMethodLogicSignalGetArgument::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: integer expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodLogicSignalGetArgument(this));
	}
	{
		//
		class ScriptMethodLogicSignalNext: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodLogicSignalNext(LogicMiniScript* miniScript):
				ScriptMethod(),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "logic.signal.next";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				miniScript->logic->removeSignal();
			}
		};
		registerMethod(new ScriptMethodLogicSignalNext(this));
	}
	// keyboard input
	{
		//
		class ScriptMethodInputKeyboardIsKeyDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardIsKeyDown(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_INTEGER, .name = "keyCode", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.isKeyDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				int64_t keyCode;
				if (miniScript->getIntegerValue(argumentValues, 0, keyCode) == true) {
					returnValue = miniScript->keyboardKeys.find(keyCode) != miniScript->keyboardKeys.end();
				} else {
					Console::println("ScriptMethodInputKeyboardIsKeyDown::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: integer expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodInputKeyboardIsKeyDown(this));
	}
	{
		//
		class ScriptMethodInputKeyboardGetTypedString: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardGetTypedString(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_STRING),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.getTypedString";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->keyboardChars;
			}
		};
		registerMethod(new ScriptMethodInputKeyboardGetTypedString(this));
	}
	{
		//
		class ScriptMethodInputKeyboardIsControlDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardIsControlDown(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.isControlDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->keyboardControlDown == true;
			}
		};
		registerMethod(new ScriptMethodInputKeyboardIsControlDown(this));
	}
	{
		//
		class ScriptMethodInputKeyboardIsMetaDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardIsMetaDown(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.isMetaDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->keyboardControlDown == true;
			}
		};
		registerMethod(new ScriptMethodInputKeyboardIsMetaDown(this));
	}
	{
		//
		class ScriptMethodInputKeyboardIsAltDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardIsAltDown(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.isAltDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->keyboardAltDown == true;
			}
		};
		registerMethod(new ScriptMethodInputKeyboardIsAltDown(this));
	}
	{
		//
		class ScriptMethodInputKeyboardIsShiftDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputKeyboardIsShiftDown(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.keyboard.isShiftDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->keyboardShiftDown == true;
			}
		};
		registerMethod(new ScriptMethodInputKeyboardIsShiftDown(this));
	}
	// mouse input
	{
		//
		class ScriptMethodInputMouseIsButtonDown: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseIsButtonDown(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_INTEGER, .name = "button", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.isButtonDown";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				int64_t button;
				if (miniScript->getIntegerValue(argumentValues, 0, button) == true) {
					returnValue = button >= 0 && button <= 3?miniScript->mouseDown[button]:false;
				} else {
					Console::println("ScriptMethodInputMouseIsButtonDown::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: integer expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodInputMouseIsButtonDown(this));
	}
	{
		//
		class ScriptMethodInputMouseIsButtonUp: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseIsButtonUp(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_INTEGER, .name = "button", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.isButtonUp";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				int64_t button;
				if (miniScript->getIntegerValue(argumentValues, 0, button) == true) {
					returnValue = button >= 0 && button <= 3?miniScript->mouseUp[button]:false;
				} else {
					Console::println("ScriptMethodInputMouseIsButtonUp::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: integer expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodInputMouseIsButtonUp(this));
	}
	{
		//
		class ScriptMethodInputMouseIsDragging: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseIsDragging(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_INTEGER, .name = "button", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.isDragging";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				int64_t button;
				if (miniScript->getIntegerValue(argumentValues, 0, button) == true) {
					returnValue = button >= 0 && button <= 3?miniScript->mouseDragging[button]:false;
				} else {
					Console::println("ScriptMethodInputMouseIsDragging::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: integer expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodInputMouseIsDragging(this));
	}
	{
		//
		class ScriptMethodInputMouseHasMoved: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseHasMoved(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_BOOLEAN),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.hasMoved";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->mouseMoved;
			}
		};
		registerMethod(new ScriptMethodInputMouseHasMoved(this));
	}
	{
		//
		class ScriptMethodInputMouseGetX: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetX(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_INTEGER),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getX";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = static_cast<int64_t>(miniScript->mouseX);
			}
		};
		registerMethod(new ScriptMethodInputMouseGetX(this));
	}
	{
		//
		class ScriptMethodInputMouseGetXUnscaled: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetXUnscaled(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_INTEGER),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getXUnscaled";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = static_cast<int64_t>(miniScript->mouseXUnscaled);
			}
		};
		registerMethod(new ScriptMethodInputMouseGetXUnscaled(this));
	}
	{
		//
		class ScriptMethodInputMouseGetY: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetY(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_INTEGER),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getY";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = static_cast<int64_t>(miniScript->mouseY);
			}
		};
		registerMethod(new ScriptMethodInputMouseGetY(this));
	}
	{
		//
		class ScriptMethodInputMouseGetYUnscaled: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetYUnscaled(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_INTEGER),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getYUnscaled";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = static_cast<int64_t>(miniScript->mouseYUnscaled);
			}
		};
		registerMethod(new ScriptMethodInputMouseGetYUnscaled(this));
	}
	{
		//
		class ScriptMethodInputMouseGetWheelX: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetWheelX(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getWheelX";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->mouseWheelX;
			}
		};
		registerMethod(new ScriptMethodInputMouseGetWheelX(this));
	}
	{
		//
		class ScriptMethodInputMouseGetWheelY: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetWheelY(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getWheelY";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->mouseWheelX;
			}
		};
		registerMethod(new ScriptMethodInputMouseGetWheelY(this));
	}
	{
		//
		class ScriptMethodInputMouseGetWheelZ: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodInputMouseGetWheelZ(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "input.mouse.getWheelZ";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->mouseWheelX;
			}
		};
		registerMethod(new ScriptMethodInputMouseGetWheelZ(this));
	}
	// camera
	{
		//
		class ScriptMethodCameraGetLookFrom: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraGetLookFrom(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_VECTOR3),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.getLookFrom";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getCamera()->getLookFrom();
			}
		};
		registerMethod(new ScriptMethodCameraGetLookFrom(this));
	}
	{
		//
		class ScriptMethodCameraSetLookFrom: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraSetLookFrom(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_VECTOR3, .name = "lookFrom", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.setLookFrom";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				Vector3 lookFrom;
				if (miniScript->getVector3Value(argumentValues, 0, lookFrom) == true) {
					miniScript->context->getEngine()->getCamera()->setLookFrom(lookFrom);
				} else {
					Console::println("ScriptMethodCameraSetLookFrom::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: vector3 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodCameraSetLookFrom(this));
	}
	{
		//
		class ScriptMethodCameraGetLookAt: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraGetLookAt(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_VECTOR3),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.getLookAt";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getCamera()->getLookAt();
			}
		};
		registerMethod(new ScriptMethodCameraGetLookAt(this));
	}
	{
		//
		class ScriptMethodCameraSetLookAt: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraSetLookAt(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_VECTOR3, .name = "lookAt", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.setLookAt";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				Vector3 lookAt;
				if (miniScript->getVector3Value(argumentValues, 0, lookAt) == true) {
					miniScript->context->getEngine()->getCamera()->setLookAt(lookAt);
				} else {
					Console::println("ScriptMethodCameraSetLookAt::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: vector3 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodCameraSetLookAt(this));
	}
	{
		//
		class ScriptMethodCameraGetUpVector: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraGetUpVector(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_VECTOR3),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.getUpVector";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getCamera()->getUpVector();
			}
		};
		registerMethod(new ScriptMethodCameraGetUpVector(this));
	}
	{
		//
		class ScriptMethodCameraSetUpVector: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraSetUpVector(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_VECTOR3, .name = "upVector", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.setUpVector";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				Vector3 upVector;
				if (miniScript->getVector3Value(argumentValues, 0, upVector) == true) {
					miniScript->context->getEngine()->getCamera()->setUpVector(upVector);
				} else {
					Console::println("ScriptMethodCameraSetUpVector::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: vector3 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodCameraSetUpVector(this));
	}
	{
		//
		class ScriptMethodCameraComputeUpVector: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraComputeUpVector(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_VECTOR3, .name = "lookFrom", .optional = false },
						{ .type = ScriptVariableType::TYPE_VECTOR3, .name = "lookAt", .optional = false }
					},
					ScriptVariableType::TYPE_VECTOR3
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.computeUpVector";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				Vector3 lookFrom;
				Vector3 lookAt;
				if (miniScript->getVector3Value(argumentValues, 0, lookFrom) == true &&
					miniScript->getVector3Value(argumentValues, 1, lookAt) == true) {
					returnValue = Camera::computeUpVector(lookFrom, lookAt);
				} else {
					Console::println("ScriptMethodCameraComputeUpVector::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: vector3 expected, @ argument 1: vector3 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodCameraComputeUpVector(this));
	}
	{
		//
		class ScriptMethodCameraGetFovX: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraGetFovX(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.getFovX";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getCamera()->getFovX();
			}
		};
		registerMethod(new ScriptMethodCameraGetFovX(this));
	}
	{
		//
		class ScriptMethodCameraSetFovX: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodCameraSetFovX(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_FLOAT, .name = "fovX", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.camera.setFovX";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				float fovX;
				if (miniScript->getFloatValue(argumentValues, 0, fovX) == true) {
					miniScript->context->getEngine()->getCamera()->setFovX(fovX);
				} else {
					Console::println("ScriptMethodCameraSetFovX::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: float expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodCameraSetFovX(this));
	}
	// timing
	{
		//
		class ScriptMethodTimingGetDeltaTime: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodTimingGetDeltaTime(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_INTEGER),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.timing.getDeltaTime";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getTiming()->getDeltaTime();
			}
		};
		registerMethod(new ScriptMethodTimingGetDeltaTime(this));
	}
	{
		//
		class ScriptMethodTimingGetDeltaTimeSeconds: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodTimingGetDeltaTimeSeconds(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.timing.getDeltaTimeSeconds";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getTiming()->getDeltaTimeSeconds();
			}
		};
		registerMethod(new ScriptMethodTimingGetDeltaTimeSeconds(this));
	}
	{
		//
		class ScriptMethodTimingGetAvarageFPS: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodTimingGetAvarageFPS(LogicMiniScript* miniScript):
				ScriptMethod({}, ScriptVariableType::TYPE_FLOAT),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.timing.getAvarageFPS";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				returnValue = miniScript->context->getEngine()->getTiming()->getAvarageFPS();
			}
		};
		registerMethod(new ScriptMethodTimingGetAvarageFPS(this));
	}
	// engine
	{
		//
		class ScriptMethodEntityGetTransform: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityGetTransform(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_TRANSFORM
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.getTransform";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						returnValue = entity->getTransform();
					} else {
						Console::println("ScriptMethodEntityGetTransform::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityGetTransform::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityGetTransform(this));
	}
	{
		//
		class ScriptMethodEntitySetTransform: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetTransform(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_TRANSFORM, .name = "transform", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setTransform";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				Transform transform;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getTransformValue(argumentValues, 1, transform) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						entity->setTransform(transform);
					} else {
						Console::println("ScriptMethodEntitySetTransform::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetTransform::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: transform expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetTransform(this));
	}
	{
		//
		class ScriptMethodEntityIsEnabled: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityIsEnabled(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.isEnabled";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						returnValue = entity->isEnabled();
					} else {
						Console::println("ScriptMethodEntityIsEnabled::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityIsEnabled::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityIsEnabled(this));
	}
	{
		//
		class ScriptMethodEntitySetEnabled: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetEnabled(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_BOOLEAN, .name = "enabled", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setEnabled";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				bool enabled;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getBooleanValue(argumentValues, 1, enabled) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						entity->setEnabled(enabled);
					} else {
						Console::println("ScriptMethodEntitySetEnabled::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetEnabled::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: boolean expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetEnabled(this));
	}
	{
		//
		class ScriptMethodEntityIsPickable: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityIsPickable(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.isPickable";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						returnValue = entity->isPickable();
					} else {
						Console::println("ScriptMethodEntityIsPickable::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityIsPickable::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityIsPickable(this));
	}
	{
		//
		class ScriptMethodEntitySetPickable: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetPickable(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_BOOLEAN, .name = "pickable", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setPickable";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				bool pickable;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getBooleanValue(argumentValues, 1, pickable) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						entity->setEnabled(pickable);
					} else {
						Console::println("ScriptMethodEntitySetPickable::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetPickable::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: boolean expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetPickable(this));
	}
	{
		//
		class ScriptMethodEntityGetEffectColorMul: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityGetEffectColorMul(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_VECTOR4
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.getEffectColorMul";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						auto effectColorMul = entity->getEffectColorMul();
						returnValue.setValue(Vector4(effectColorMul.getRed(), effectColorMul.getGreen(), effectColorMul.getBlue(), effectColorMul.getAlpha()));
					} else {
						Console::println("ScriptMethodEntityGetEffectColorMul::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityGetEffectColorMul::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityGetEffectColorMul(this));
	}
	{
		//
		class ScriptMethodEntitySetEffectColorMul: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetEffectColorMul(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_VECTOR4, .name = "effectColorMul", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setEffectColorMul";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				Vector4 effectColorMul;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getVector4Value(argumentValues, 1, effectColorMul) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						entity->setEffectColorMul(Color4(effectColorMul.getX(), effectColorMul.getY(), effectColorMul.getZ(), effectColorMul.getW()));
					} else {
						Console::println("ScriptMethodEntitySetEffectColorMul::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetEffectColorMul::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: vector4 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetEffectColorMul(this));
	}
	{
		//
		class ScriptMethodEntityGetEffectColorAdd: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityGetEffectColorAdd(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_VECTOR4
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.getEffectColorAdd";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						auto effectColorMul = entity->getEffectColorAdd();
						returnValue.setValue(Vector4(effectColorMul.getRed(), effectColorMul.getGreen(), effectColorMul.getBlue(), effectColorMul.getAlpha()));
					} else {
						Console::println("ScriptMethodEntityGetEffectColorAdd::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityGetEffectColorAdd::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityGetEffectColorAdd(this));
	}
	{
		//
		class ScriptMethodEntitySetEffectColorAdd: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetEffectColorAdd(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_VECTOR4, .name = "effectColorAdd", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setEffectColorAdd";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				Vector4 effectColorAdd;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getVector4Value(argumentValues, 1, effectColorAdd) == true) {
					auto entity = miniScript->context->getEngine()->getEntity(entityId);
					if (entity != nullptr) {
						entity->setEffectColorAdd(Color4(effectColorAdd.getX(), effectColorAdd.getY(), effectColorAdd.getZ(), effectColorAdd.getW()));
					} else {
						Console::println("ScriptMethodEntitySetEffectColorAdd::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetEffectColorAdd::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: vector4 expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetEffectColorAdd(this));
	}
	{
		//
		class ScriptMethodEntityGetAnimation: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityGetAnimation(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false }
					},
					ScriptVariableType::TYPE_STRING
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.getAnimation";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						returnValue.setValue(object->getAnimation());
					} else {
						Console::println("ScriptMethodEntityGetAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityGetAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityGetAnimation(this));
	}
	{
		//
		class ScriptMethodEntitySetAnimation: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetAnimation(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_STRING, .name = "animation", .optional = false },
						{ .type = ScriptVariableType::TYPE_FLOAT, .name = "speed", .optional = true }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setAnimation";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				string animation;
				float speed = 1.0f;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getStringValue(argumentValues, 1, animation) == true &&
					miniScript->getFloatValue(argumentValues, 2, speed) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						object->setAnimation(animation, speed);
					} else {
						Console::println("ScriptMethodEntitySetAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: string expected, @ argument 2: optional float expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetAnimation(this));
	}
	{
		//
		class ScriptMethodEntitySetAnimationSpeed: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntitySetAnimationSpeed(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_FLOAT, .name = "speed", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.setAnimationSpeed";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				float speed;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getFloatValue(argumentValues, 1, speed) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						object->setAnimationSpeed(speed);
					} else {
						Console::println("ScriptMethodEntitySetAnimationSpeed::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntitySetAnimationSpeed::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: float expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntitySetAnimationSpeed(this));
	}
	{
		//
		class ScriptMethodEntityHasOverlayAnimation: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityHasOverlayAnimation(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_STRING, .name = "animation", .optional = false }
					},
					ScriptVariableType::TYPE_BOOLEAN
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.hasOverlayAnimation";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				string animation;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getStringValue(argumentValues, 1, animation) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						returnValue = object->hasOverlayAnimation(animation);
					} else {
						Console::println("ScriptMethodEntityHasOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityHasOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityHasOverlayAnimation(this));
	}
	{
		//
		class ScriptMethodEntityAddOverlayAnimation: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityAddOverlayAnimation(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_STRING, .name = "animation", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.addOverlayAnimation";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				string animation;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getStringValue(argumentValues, 1, animation) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						object->addOverlayAnimation(animation);
					} else {
						Console::println("ScriptMethodEntityAddOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityAddOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityAddOverlayAnimation(this));
	}
	{
		//
		class ScriptMethodEntityRemoveOverlayAnimation: public ScriptMethod {
		private:
			LogicMiniScript* miniScript { nullptr };
		public:
			ScriptMethodEntityRemoveOverlayAnimation(LogicMiniScript* miniScript):
				ScriptMethod(
					{
						{ .type = ScriptVariableType::TYPE_STRING, .name = "entityId", .optional = false },
						{ .type = ScriptVariableType::TYPE_STRING, .name = "animation", .optional = false }
					},
					ScriptVariableType::TYPE_VOID
				),
				miniScript(miniScript) {}
			const string getMethodName() override {
				return "engine.entity.removeOverlayAnimation";
			}
			void executeMethod(span<ScriptVariable>& argumentValues, ScriptVariable& returnValue, const ScriptStatement& statement) override {
				string entityId;
				string animation;
				if (miniScript->getStringValue(argumentValues, 0, entityId) == true &&
					miniScript->getStringValue(argumentValues, 1, animation) == true) {
					auto object = dynamic_cast<Object*>(miniScript->context->getEngine()->getEntity(entityId));
					if (object != nullptr) {
						object->removeOverlayAnimation(animation);
					} else {
						Console::println("ScriptMethodEntityRemoveOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": object entity not found: " + entityId);
					}
				} else {
					Console::println("ScriptMethodEntityRemoveOverlayAnimation::executeMethod(): " + getMethodName() + "(): " + miniScript->getStatementInformation(statement) + ": parameter type mismatch @ argument 0: string expected, @ argument 1: string expected");
					miniScript->startErrorScript();
				}
			}
		};
		registerMethod(new ScriptMethodEntityRemoveOverlayAnimation(this));
	}
	// physics
	// gui
	// sceneconnector
}

void LogicMiniScript::registerVariables() {
}

void LogicMiniScript::collectHIDEvents(vector<GUIMouseEvent>& mouseEvents, vector<GUIKeyboardEvent>& keyEvents) {
	Console::println("LogicMiniScript::collectHIDEvents()");
	// keyboard events
	keyboardChars.clear();
	keyboardControlDown = false;
	keyboardMetaDown = false;
	keyboardAltDown = false;
	keyboardShiftDown = false;
	for (auto& event: keyEvents) {
		// key pressed
		if (event.getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_PRESSED) {
			keyboardKeys.insert(event.getKeyCode());
		} else
		// key released
		if (event.getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_RELEASED) {
			keyboardKeys.erase(event.getKeyCode());
		} else
		// key typed
		if (event.getType() == GUIKeyboardEvent::KEYBOARDEVENT_KEY_TYPED) {
			Character::appendToString(keyboardChars, event.getKeyChar());
		}
		// extra keys
		if (event.isControlDown() == true) keyboardControlDown = true;
		if (event.isMetaDown() == true) keyboardMetaDown = true;
		if (event.isAltDown() == true) keyboardAltDown = true;
		if (event.isShiftDown() == true) keyboardShiftDown = true;
	}

	// mouse
	mouseDown.fill(false);
	mouseUp.fill(false);
	mouseDragging.fill(false);
	mouseMoved = false;
	mouseWheelX = 0.0f;
	mouseWheelY = 0.0f;
	mouseWheelZ = 0.0f;
	for (auto& event: mouseEvents) {
		// mouse move
		if (event.getType() == GUIMouseEvent::MOUSEEVENT_MOVED) {
			mouseMoved = true;
		} else
		// on press and drag
		//	store button and mouse dragging properties
		if (event.getType() == GUIMouseEvent::MOUSEEVENT_PRESSED) {
			if (event.getButton() != GUIMouseEvent::MOUSEEVENT_BUTTON_NONE) {
				mouseDragging[event.getButton() - 1] = true;
			}
		} else
		if (event.getType() == GUIMouseEvent::MOUSEEVENT_DRAGGED) {
			if (event.getButton() != GUIMouseEvent::MOUSEEVENT_BUTTON_NONE) {
				mouseDown[event.getButton() - 1] = true;
			}
		} else
		// on release
		//	store release
		if (event.getType() == GUIMouseEvent::MOUSEEVENT_RELEASED) {
			if (event.getButton() != GUIMouseEvent::MOUSEEVENT_BUTTON_NONE) {
				mouseUp[event.getButton() - 1] = true;
			}
		} else
		// wheel
		if (event.getType() == GUIMouseEvent::MOUSEEVENT_WHEEL_MOVED) {
			mouseWheelX+= event.getWheelX();
			mouseWheelY+= event.getWheelY();
			mouseWheelZ+= event.getWheelZ();
		}
		// always store mouse position
		mouseX = event.getX();
		mouseXUnscaled = event.getXUnscaled();
		mouseY = event.getY();
		mouseYUnscaled = event.getYUnscaled();
		// extra keys
		if (event.isControlDown() == true) keyboardControlDown = true;
		if (event.isMetaDown() == true) keyboardMetaDown = true;
		if (event.isAltDown() == true) keyboardAltDown = true;
		if (event.isShiftDown() == true) keyboardShiftDown = true;
	}
}
