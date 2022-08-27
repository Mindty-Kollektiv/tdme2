#include "MiniScriptTest.h"

#include <tdme/tdme.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/MiniScript.h>
#include <tdme/utilities/MiniScriptMath.h>

using tdme::utilities::Console;
using tdme::utilities::MiniScript;
using tdme::utilities::MiniScriptMath;

MiniScriptTest::MiniScriptTest(): MiniScript() {
	initializeNative();
}

/*__MINISCRIPT_TRANSPILEDMINISCRIPTCODE_DEFINITIONS_START__*/
void MiniScriptTest::initializeNative() {
	setNative(true);
	setHash("be408e70b9656476acf59f0fc5c7d743163e0bece2bc095c3678158a3ff87894");
	setNativeScripts(
		{
			{
				.scriptType = Script::SCRIPTTYPE_ON,
				.line = 2,
				.condition = "initialize",
				.name = "",
				.emitCondition = true,
				.statements = {
					{
						.line = 3,
						.statementIdx = 0,
						.statement = "console.log(\"------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 4,
						.statementIdx = 1,
						.statement = "console.log(\"Initialize\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 5,
						.statementIdx = 2,
						.statement = "console.log(\"------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 6,
						.statementIdx = 3,
						.statement = "console.log()",
						.gotoStatementIdx = -1
					},
					{
						.line = 7,
						.statementIdx = 4,
						.statement = "end",
						.gotoStatementIdx = -1
					}
				}
			},
			{
				.scriptType = Script::SCRIPTTYPE_ON,
				.line = 10,
				.condition = "nothing",
				.name = "",
				.emitCondition = true,
				.statements = {
					{
						.line = 11,
						.statementIdx = 0,
						.statement = "console.log(\"---------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 12,
						.statementIdx = 1,
						.statement = "console.log(\"Nothing\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 13,
						.statementIdx = 2,
						.statement = "console.log(\"----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 14,
						.statementIdx = 3,
						.statement = "console.log()",
						.gotoStatementIdx = -1
					},
					{
						.line = 15,
						.statementIdx = 4,
						.statement = "console.log(\"-----------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 16,
						.statementIdx = 5,
						.statement = "console.log(\"Check bool operations\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 17,
						.statementIdx = 6,
						.statement = "console.log(\"-----------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 18,
						.statementIdx = 7,
						.statement = "console.log(\"MiniScript will do the job: and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true): \", and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true))",
						.gotoStatementIdx = -1
					},
					{
						.line = 19,
						.statementIdx = 8,
						.statement = "console.log(\"-----------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 20,
						.statementIdx = 9,
						.statement = "console.log(\"Check int computation\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 21,
						.statementIdx = 10,
						.statement = "console.log(\"-----------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 22,
						.statementIdx = 11,
						.statement = "console.log(\"sub(add(1, 2, 3), 1)): \", sub(add(1, 2, 3), 1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 23,
						.statementIdx = 12,
						.statement = "console.log(\"div(20, 2): \", div(20, 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 24,
						.statementIdx = 13,
						.statement = "console.log(\"mul(11, 10): \", mul(11, 10))",
						.gotoStatementIdx = -1
					},
					{
						.line = 25,
						.statementIdx = 14,
						.statement = "console.log(\"greater(2, 1): \", greater(2, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 26,
						.statementIdx = 15,
						.statement = "console.log(\"lesser(2, 1): \", lesser(2, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 27,
						.statementIdx = 16,
						.statement = "console.log(\"---------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 28,
						.statementIdx = 17,
						.statement = "console.log(\"Check int computation (Operators)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 29,
						.statementIdx = 18,
						.statement = "console.log(\"---------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 30,
						.statementIdx = 19,
						.statement = "console.log(\"1 + 2 + 3 - 1: \",sub(add(1,add(2, 3)), 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 31,
						.statementIdx = 20,
						.statement = "console.log(\"20 / 2: \",div(20, 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 32,
						.statementIdx = 21,
						.statement = "console.log(\"11 * 10: \",mul(11, 10))",
						.gotoStatementIdx = -1
					},
					{
						.line = 33,
						.statementIdx = 22,
						.statement = "console.log(\"2 > 1: \",greater(2, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 34,
						.statementIdx = 23,
						.statement = "console.log(\"2 < 1: \",lesser(2, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 35,
						.statementIdx = 24,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 36,
						.statementIdx = 25,
						.statement = "console.log(\"Check float computation\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 37,
						.statementIdx = 26,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 38,
						.statementIdx = 27,
						.statement = "console.log(\"sub(add(1.1, 2.2, 3.3), 1.2)): \", sub(add(1.1, 2.2, 3.3), 1.2)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 39,
						.statementIdx = 28,
						.statement = "console.log(\"div(20, 1.5): \", div(20, 1.5))",
						.gotoStatementIdx = -1
					},
					{
						.line = 40,
						.statementIdx = 29,
						.statement = "console.log(\"mul(11.5, 10.5): \", mul(11.5, 10.5))",
						.gotoStatementIdx = -1
					},
					{
						.line = 41,
						.statementIdx = 30,
						.statement = "console.log(\"greater(2.2, 1.3): \", greater(2.2, 1.3))",
						.gotoStatementIdx = -1
					},
					{
						.line = 42,
						.statementIdx = 31,
						.statement = "console.log(\"lesser(2.5, 1.2): \", lesser(2.5, 1.2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 43,
						.statementIdx = 32,
						.statement = "console.log(\"-----------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 44,
						.statementIdx = 33,
						.statement = "console.log(\"Check float computation (Operators)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 45,
						.statementIdx = 34,
						.statement = "console.log(\"-----------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 46,
						.statementIdx = 35,
						.statement = "console.log(\"(1.1 + 2.2 + 3.3) - 1.2: \",sub(add(1.1,add(2.2, 3.3)), 1.2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 47,
						.statementIdx = 36,
						.statement = "console.log(\"20 / 1.5: \",div(20, 1.5))",
						.gotoStatementIdx = -1
					},
					{
						.line = 48,
						.statementIdx = 37,
						.statement = "console.log(\"11.5 * 10.5: \",mul(11.5, 10.5))",
						.gotoStatementIdx = -1
					},
					{
						.line = 49,
						.statementIdx = 38,
						.statement = "console.log(\"2.2 > 1.3: \",greater(2.2, 1.3))",
						.gotoStatementIdx = -1
					},
					{
						.line = 50,
						.statementIdx = 39,
						.statement = "console.log(\"2.5 < 1.2: \",lesser(2.5, 1.2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 51,
						.statementIdx = 40,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 52,
						.statementIdx = 41,
						.statement = "console.log(\"Check vector2 math\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 53,
						.statementIdx = 42,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 54,
						.statementIdx = 43,
						.statement = "console.log(\"vec2.computeLength(vec2(20, 10)): \", vec2.computeLength(vec2(20, 10)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 55,
						.statementIdx = 44,
						.statement = "console.log(\"vec2.computeLengthSquared(vec2(20, 10)): \", vec2.computeLengthSquared(vec2(20, 10)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 56,
						.statementIdx = 45,
						.statement = "console.log(\"vec2.computeDotProduct(vec2(0, 1), vec2(0, -1)): \", vec2.computeDotProduct(vec2(0, 1), vec2(0, -1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 57,
						.statementIdx = 46,
						.statement = "console.log(\"vec2.normalize(vec2(1, 2)): \", vec2.normalize(vec2(1, 2)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 58,
						.statementIdx = 47,
						.statement = "console.log(\"vec2.getX(vec2(1, 2)): \", vec2.getX(vec2(1, 2)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 59,
						.statementIdx = 48,
						.statement = "console.log(\"vec2.getY(vec2(1, 2)): \", vec2.getY(vec2(1, 2)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 60,
						.statementIdx = 49,
						.statement = "console.log(\"vec2(1.1, 2.2) - vec2(1.2, 1.0): \",sub(vec2(1.1, 2.2), vec2(1.2, 1.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 61,
						.statementIdx = 50,
						.statement = "console.log(\"vec2(20, 10) / vec2(1.5, 2.5): \",div(vec2(20, 10), vec2(1.5, 2.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 62,
						.statementIdx = 51,
						.statement = "console.log(\"vec2(20, 10) * vec2(1.5, 2.5)): \",mul(vec2(20, 10), vec2(1.5, 2.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 63,
						.statementIdx = 52,
						.statement = "console.log(\"vec2(20, 10) / 2): \",div(vec2(20, 10), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 64,
						.statementIdx = 53,
						.statement = "console.log(\"vec2(20, 10) * 2): \",mul(vec2(20, 10), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 65,
						.statementIdx = 54,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 66,
						.statementIdx = 55,
						.statement = "console.log(\"Check vector3 math\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 67,
						.statementIdx = 56,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 68,
						.statementIdx = 57,
						.statement = "console.log(\"vec3.computeLength(vec3(20, 10, 5)): \", vec3.computeLength(vec3(20, 10, 5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 69,
						.statementIdx = 58,
						.statement = "console.log(\"vec3.computeLengthSquared(vec3(20, 10, 5)): \", vec3.computeLengthSquared(vec3(20, 10, 5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 70,
						.statementIdx = 59,
						.statement = "console.log(\"vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1)): \", vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 71,
						.statementIdx = 60,
						.statement = "console.log(\"vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0)): \", vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 72,
						.statementIdx = 61,
						.statement = "console.log(\"vec3.normalize(vec3(1, 2, 3)): \", vec3.normalize(vec3(1, 2, 3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 73,
						.statementIdx = 62,
						.statement = "console.log(\"vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0)): \", vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 74,
						.statementIdx = 63,
						.statement = "console.log(\"vec3.getX(vec3(1, 2, 3)): \", vec3.getX(vec3(1, 2, 3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 75,
						.statementIdx = 64,
						.statement = "console.log(\"vec3.getY(vec3(1, 2, 3)): \", vec3.getY(vec3(1, 2, 3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 76,
						.statementIdx = 65,
						.statement = "console.log(\"vec3.getZ(vec3(1, 2, 3)): \", vec3.getZ(vec3(1, 2, 3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 77,
						.statementIdx = 66,
						.statement = "console.log(\"vec3(1.1, 2.2, 3.3) - vec3(1.2, 1.0, 1.0): \",sub(vec3(1.1, 2.2, 3.3), vec3(1.2, 1.0, 1.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 78,
						.statementIdx = 67,
						.statement = "console.log(\"vec3(20, 10, 5) / vec3(1.5, 2.5, 3.5): \",div(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 79,
						.statementIdx = 68,
						.statement = "console.log(\"vec3(20, 10, 5) * vec3(1.5, 2.5, 3.5)): \",mul(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 80,
						.statementIdx = 69,
						.statement = "console.log(\"vec3(20, 10, 5) / 2): \",div(vec3(20, 10, 5), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 81,
						.statementIdx = 70,
						.statement = "console.log(\"vec3(20, 10, 5) * 2): \",mul(vec3(20, 10, 5), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 82,
						.statementIdx = 71,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 83,
						.statementIdx = 72,
						.statement = "console.log(\"Check vector4 math\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 84,
						.statementIdx = 73,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 85,
						.statementIdx = 74,
						.statement = "console.log(\"vec4.computeLength(vec4(20, 10, 5, 2.5)): \", vec4.computeLength(vec4(20, 10, 5, 2.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 86,
						.statementIdx = 75,
						.statement = "console.log(\"vec4.computeLengthSquared(vec3(20, 10, 5)): \", vec4.computeLengthSquared(vec4(20, 10, 5, 2.5)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 87,
						.statementIdx = 76,
						.statement = "console.log(\"vec4.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1, 1)): \", vec4.computeDotProduct(vec4(0, 0, 1, 1), vec4(0, 0, -1, 1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 88,
						.statementIdx = 77,
						.statement = "console.log(\"vec4.normalize(vec4(1, 2, 3, 4)): \", vec4.normalize(vec4(1, 2, 3, 4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 89,
						.statementIdx = 78,
						.statement = "console.log(\"vec4.getX(vec4(1, 2, 3, 4)): \", vec4.getX(vec4(1, 2, 3, 4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 90,
						.statementIdx = 79,
						.statement = "console.log(\"vec4.getY(vec4(1, 2, 3, 4)): \", vec4.getY(vec4(1, 2, 3, 4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 91,
						.statementIdx = 80,
						.statement = "console.log(\"vec4.getZ(vec4(1, 2, 3, 4)): \", vec4.getZ(vec4(1, 2, 3, 4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 92,
						.statementIdx = 81,
						.statement = "console.log(\"vec4.getW(vec4(1, 2, 3, 4)): \", vec4.getZ(vec4(1, 2, 3, 4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 93,
						.statementIdx = 82,
						.statement = "console.log(\"vec4(1.1, 2.2, 3.3, 1.0) - vec4(1.2, 1.0, 1.0, 1.0): \",sub(vec4(1.1, 2.2, 3.3, 1.0), vec4(1.2, 1.0, 1.0, 1.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 94,
						.statementIdx = 83,
						.statement = "console.log(\"vec4(20, 10, 5, 1) / vec4(1.5, 2.5, 3.5, 1): \",div(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 95,
						.statementIdx = 84,
						.statement = "console.log(\"vec4(20, 10, 5, 1) * vec4(1.5, 2.5, 3.5, 1)): \",mul(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 96,
						.statementIdx = 85,
						.statement = "console.log(\"vec4(20, 10, 5, 1) / 2): \",div(vec4(20, 10, 5, 1), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 97,
						.statementIdx = 86,
						.statement = "console.log(\"vec4(20, 10, 5, 1) * 2): \",mul(vec4(20, 10, 5, 1), 2))",
						.gotoStatementIdx = -1
					},
					{
						.line = 98,
						.statementIdx = 87,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 99,
						.statementIdx = 88,
						.statement = "console.log(\"Check quaternion math\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 100,
						.statementIdx = 89,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 101,
						.statementIdx = 90,
						.statement = "console.log(\"quaternion.identity(): \", quaternion.identity())",
						.gotoStatementIdx = -1
					},
					{
						.line = 102,
						.statementIdx = 91,
						.statement = "console.log(\"quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0): \", quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))",
						.gotoStatementIdx = -1
					},
					{
						.line = 103,
						.statementIdx = 92,
						.statement = "console.log(\"quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): \", quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 104,
						.statementIdx = 93,
						.statement = "console.log(\"quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)): \", quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 105,
						.statementIdx = 94,
						.statement = "console.log(\"quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): \", quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 106,
						.statementIdx = 95,
						.statement = "console.log(\"quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): \", quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 107,
						.statementIdx = 96,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 108,
						.statementIdx = 97,
						.statement = "console.log(\"Check matrix4x4 math\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 109,
						.statementIdx = 98,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 110,
						.statementIdx = 99,
						.statement = "console.log(\"mat4.identity(): \", mat4.identity())",
						.gotoStatementIdx = -1
					},
					{
						.line = 111,
						.statementIdx = 100,
						.statement = "console.log(\"mat4.translate(vec3(1.0, 2.0, 3.0)): \", mat4.translate(vec3(1.0, 2.0, 3.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 112,
						.statementIdx = 101,
						.statement = "console.log(\"mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0): \", mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0))",
						.gotoStatementIdx = -1
					},
					{
						.line = 113,
						.statementIdx = 102,
						.statement = "console.log(\"mat4.scale(vec3(1.0, 2.0, 3.0)): \", mat4.scale(vec3(1.0, 2.0, 3.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 114,
						.statementIdx = 103,
						.statement = "console.log(\"mat4.scale(3.0): \", mat4.scale(3.0))",
						.gotoStatementIdx = -1
					},
					{
						.line = 115,
						.statementIdx = 104,
						.statement = "console.log(\"mat4.invert(mat4.scale(3.0)): \", mat4.invert(mat4.scale(3.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 116,
						.statementIdx = 105,
						.statement = "console.log(\"mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)): \", mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 117,
						.statementIdx = 106,
						.statement = "console.log(\"mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)): \", mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 118,
						.statementIdx = 107,
						.statement = "console.log(\"mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): \", mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 119,
						.statementIdx = 108,
						.statement = "console.log(\"mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0)): \", mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 120,
						.statementIdx = 109,
						.statement = "console.log(\"-----------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 121,
						.statementIdx = 110,
						.statement = "console.log(\"Check transform\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 122,
						.statementIdx = 111,
						.statement = "console.log(\"-----------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 123,
						.statementIdx = 112,
						.statement = "setVariable(\"$transform\", transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 124,
						.statementIdx = 113,
						.statement = "setVariable(\"$transform\", transform.setRotationAngle($transform, 0, 90)));",
						.gotoStatementIdx = -1
					},
					{
						.line = 125,
						.statementIdx = 114,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)): \", $transform)",
						.gotoStatementIdx = -1
					},
					{
						.line = 126,
						.statementIdx = 115,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getTranslation(): \", transform.getTranslation($transform))",
						.gotoStatementIdx = -1
					},
					{
						.line = 127,
						.statementIdx = 116,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setTranslation(vec3(-1,-2,-3)): \", transform.setTranslation($transform, vec3(-1,-2,-3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 128,
						.statementIdx = 117,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getScale(): \", transform.getScale($transform))",
						.gotoStatementIdx = -1
					},
					{
						.line = 129,
						.statementIdx = 118,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setScale(): \", transform.setScale($transform, vec3(-2,-3,-4)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 130,
						.statementIdx = 119,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAxis(): \", transform.getRotationAxis($transform, 0))",
						.gotoStatementIdx = -1
					},
					{
						.line = 131,
						.statementIdx = 120,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAngle(): \", transform.getRotationAngle($transform, 0))",
						.gotoStatementIdx = -1
					},
					{
						.line = 132,
						.statementIdx = 121,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setRotationAngle(): \", transform.setRotationAngle($transform, 0, 90))",
						.gotoStatementIdx = -1
					},
					{
						.line = 133,
						.statementIdx = 122,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).multiply(vec3(0,0,0)): \", transform.multiply($transform, vec3(0,0,0)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 134,
						.statementIdx = 123,
						.statement = "console.log(\"transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).rotate(vec3(0,0,1)): \", transform.rotate($transform, vec3(0,0,1)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 135,
						.statementIdx = 124,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 136,
						.statementIdx = 125,
						.statement = "console.log(\"Check string functions\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 137,
						.statementIdx = 126,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 138,
						.statementIdx = 127,
						.statement = "console.log(space(0), \"1\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 139,
						.statementIdx = 128,
						.statement = "console.log(space(2), \"1.1\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 140,
						.statementIdx = 129,
						.statement = "console.log(space(2), \"1.2\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 141,
						.statementIdx = 130,
						.statement = "console.log(toUpperCase(\"xxxyyyzzz\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 142,
						.statementIdx = 131,
						.statement = "console.log(toLowerCase(\"XXXYYYZZZ\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 143,
						.statementIdx = 132,
						.statement = "console.log(concatenate(\"abc\", \"def\", \"ghi\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 144,
						.statementIdx = 133,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 145,
						.statementIdx = 134,
						.statement = "console.log(\"Check string functions (Operators)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 146,
						.statementIdx = 135,
						.statement = "console.log(add(\"abc\",add(\"def\", \"ghi\")))",
						.gotoStatementIdx = -1
					},
					{
						.line = 147,
						.statementIdx = 136,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 148,
						.statementIdx = 137,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 149,
						.statementIdx = 138,
						.statement = "console.log(\"Variable\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 150,
						.statementIdx = 139,
						.statement = "console.log(\"------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 151,
						.statementIdx = 140,
						.statement = "setVariable(\"$variable\", string(\"1234\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 152,
						.statementIdx = 141,
						.statement = "console.log(getVariable(\"$variable\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 153,
						.statementIdx = 142,
						.statement = "console.log(\"--------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 154,
						.statementIdx = 143,
						.statement = "console.log(\"Lets check forTime\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 155,
						.statementIdx = 144,
						.statement = "console.log(\"--------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 156,
						.statementIdx = 145,
						.statement = "setVariable(\"$i\", 1)",
						.gotoStatementIdx = -1
					},
					{
						.line = 157,
						.statementIdx = 146,
						.statement = "forTime(2000)",
						.gotoStatementIdx = 151
					},
					{
						.line = 158,
						.statementIdx = 147,
						.statement = "console.log($i, \": Hello World\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 159,
						.statementIdx = 148,
						.statement = "script.wait(500)",
						.gotoStatementIdx = -1
					},
					{
						.line = 160,
						.statementIdx = 149,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 161,
						.statementIdx = 150,
						.statement = "end",
						.gotoStatementIdx = 146
					},
					{
						.line = 162,
						.statementIdx = 151,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 163,
						.statementIdx = 152,
						.statement = "console.log(\"Lets check forCondition\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 164,
						.statementIdx = 153,
						.statement = "console.log(\"-------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 165,
						.statementIdx = 154,
						.statement = "setVariable(\"$i\", 1)",
						.gotoStatementIdx = -1
					},
					{
						.line = 166,
						.statementIdx = 155,
						.statement = "forCondition(notequal($i, 6))",
						.gotoStatementIdx = 160
					},
					{
						.line = 167,
						.statementIdx = 156,
						.statement = "console.log($i, \": Hello World\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 168,
						.statementIdx = 157,
						.statement = "script.wait(500)",
						.gotoStatementIdx = -1
					},
					{
						.line = 169,
						.statementIdx = 158,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 170,
						.statementIdx = 159,
						.statement = "end",
						.gotoStatementIdx = 155
					},
					{
						.line = 171,
						.statementIdx = 160,
						.statement = "console.log(\"i -> \", $i)",
						.gotoStatementIdx = -1
					},
					{
						.line = 172,
						.statementIdx = 161,
						.statement = "console.log(\"---------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 173,
						.statementIdx = 162,
						.statement = "console.log(\"Lets check forCondition with if/elseif/else\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 174,
						.statementIdx = 163,
						.statement = "console.log(\"---------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 175,
						.statementIdx = 164,
						.statement = "setVariable(\"$i\", 1)",
						.gotoStatementIdx = -1
					},
					{
						.line = 176,
						.statementIdx = 165,
						.statement = "forCondition(lesser($i, 5))",
						.gotoStatementIdx = 180
					},
					{
						.line = 177,
						.statementIdx = 166,
						.statement = "console.log($i, \":\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 178,
						.statementIdx = 167,
						.statement = "if (equals($i, 0))",
						.gotoStatementIdx = 169
					},
					{
						.line = 179,
						.statementIdx = 168,
						.statement = "console.log(\"i -> 0\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 180,
						.statementIdx = 169,
						.statement = "elseif (equals($i, 1))",
						.gotoStatementIdx = 171
					},
					{
						.line = 181,
						.statementIdx = 170,
						.statement = "console.log(\"i -> 1\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 182,
						.statementIdx = 171,
						.statement = "elseif (equals($i, 2))",
						.gotoStatementIdx = 173
					},
					{
						.line = 183,
						.statementIdx = 172,
						.statement = "console.log(\"i -> 2\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 184,
						.statementIdx = 173,
						.statement = "elseif (equals($i, 3))",
						.gotoStatementIdx = 175
					},
					{
						.line = 185,
						.statementIdx = 174,
						.statement = "console.log(\"i -> 3\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 186,
						.statementIdx = 175,
						.statement = "else",
						.gotoStatementIdx = 177
					},
					{
						.line = 187,
						.statementIdx = 176,
						.statement = "console.log(\"else: \", $i)",
						.gotoStatementIdx = -1
					},
					{
						.line = 188,
						.statementIdx = 177,
						.statement = "end",
						.gotoStatementIdx = -1
					},
					{
						.line = 189,
						.statementIdx = 178,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 190,
						.statementIdx = 179,
						.statement = "end",
						.gotoStatementIdx = 165
					},
					{
						.line = 191,
						.statementIdx = 180,
						.statement = "setVariable(\"$i\", 1)",
						.gotoStatementIdx = -1
					},
					{
						.line = 192,
						.statementIdx = 181,
						.statement = "setVariable(\"$j\", 2)",
						.gotoStatementIdx = -1
					},
					{
						.line = 193,
						.statementIdx = 182,
						.statement = "setVariable(\"$k\", 3)",
						.gotoStatementIdx = -1
					},
					{
						.line = 194,
						.statementIdx = 183,
						.statement = "if (or(equals(getVariable(\"$i\"), $j),equals(getVariable(\"$i\"), $k)))",
						.gotoStatementIdx = 185
					},
					{
						.line = 195,
						.statementIdx = 184,
						.statement = "console.log(\"This should not happen, but look ok in preprocessor processed output\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 196,
						.statementIdx = 185,
						.statement = "end",
						.gotoStatementIdx = -1
					},
					{
						.line = 197,
						.statementIdx = 186,
						.statement = "console.log(\"-------------------------------------------------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 198,
						.statementIdx = 187,
						.statement = "console.log(add(\"Test: string concatenation with brackets in string literals: \",add($i,add(\"(\",add($j, \")\")))))",
						.gotoStatementIdx = -1
					},
					{
						.line = 199,
						.statementIdx = 188,
						.statement = "console.log(\"-------------------------------------------------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 200,
						.statementIdx = 189,
						.statement = "console.log(\"(4.0 + 2.0) / 2.0 + (20.0 / 10.0 * (2.0 + 5)): \",add(div(add(4.0, 2.0), 2.0),mul(div(20.0, 10.0), add(2.0, 5))), \" = 17\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 201,
						.statementIdx = 190,
						.statement = "console.log(\"---------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 202,
						.statementIdx = 191,
						.statement = "console.log(\"Arrays\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 203,
						.statementIdx = 192,
						.statement = "console.log(\"----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 204,
						.statementIdx = 193,
						.statement = "setVariable(\"$array\", array(1,2,3))",
						.gotoStatementIdx = -1
					},
					{
						.line = 205,
						.statementIdx = 194,
						.statement = "console.log(\"array initialized with: $array = array(1,2,3)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 206,
						.statementIdx = 195,
						.statement = "console.log(\"array now looks like: \", $array)",
						.gotoStatementIdx = -1
					},
					{
						.line = 207,
						.statementIdx = 196,
						.statement = "setVariable(\"$array\", array.push($array, 8, 9, 10, 99, 10))",
						.gotoStatementIdx = -1
					},
					{
						.line = 208,
						.statementIdx = 197,
						.statement = "console.log(\"array pushed values with: array.push($array, 8, 9, 10, 99, 10)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 209,
						.statementIdx = 198,
						.statement = "console.log(\"array now looks like: \", $array)",
						.gotoStatementIdx = -1
					},
					{
						.line = 210,
						.statementIdx = 199,
						.statement = "setVariable(\"$array[]\", 123)",
						.gotoStatementIdx = -1
					},
					{
						.line = 211,
						.statementIdx = 200,
						.statement = "setVariable(\"$array[]\", 1234)",
						.gotoStatementIdx = -1
					},
					{
						.line = 212,
						.statementIdx = 201,
						.statement = "setVariable(\"$array[]\", 12345)",
						.gotoStatementIdx = -1
					},
					{
						.line = 213,
						.statementIdx = 202,
						.statement = "setVariable(\"$array[]\", array(1,2,3))",
						.gotoStatementIdx = -1
					},
					{
						.line = 214,
						.statementIdx = 203,
						.statement = "console.log(\"array values added with [] operator: 123, 1234, 12345, array(1,2,3)\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 215,
						.statementIdx = 204,
						.statement = "console.log(\"array now looks like: \", $array)",
						.gotoStatementIdx = -1
					},
					{
						.line = 216,
						.statementIdx = 205,
						.statement = "console.log(\"array values added with [] operator to push to array of array: 50, 60\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 217,
						.statementIdx = 206,
						.statement = "setVariable(\"$array[11][]\", 50)",
						.gotoStatementIdx = -1
					},
					{
						.line = 218,
						.statementIdx = 207,
						.statement = "setVariable(\"$array[11][]\", 60)",
						.gotoStatementIdx = -1
					},
					{
						.line = 219,
						.statementIdx = 208,
						.statement = "setVariable(\"$array[11][sub(array.length($array[11]), 1)]\", 61)",
						.gotoStatementIdx = -1
					},
					{
						.line = 220,
						.statementIdx = 209,
						.statement = "console.log(\"array length: \", array.length($array))",
						.gotoStatementIdx = -1
					},
					{
						.line = 221,
						.statementIdx = 210,
						.statement = "console.log(\"array iteration with array.get(): \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 222,
						.statementIdx = 211,
						.statement = "setVariable(\"$i\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 223,
						.statementIdx = 212,
						.statement = "forCondition(lesser($i, array.length($array)))",
						.gotoStatementIdx = 216
					},
					{
						.line = 224,
						.statementIdx = 213,
						.statement = "console.log(add($i,add(\": \", array.get($array, $i))))",
						.gotoStatementIdx = -1
					},
					{
						.line = 225,
						.statementIdx = 214,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 226,
						.statementIdx = 215,
						.statement = "end",
						.gotoStatementIdx = 212
					},
					{
						.line = 227,
						.statementIdx = 216,
						.statement = "console.log(\"array iteration with [] operator: \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 228,
						.statementIdx = 217,
						.statement = "setVariable(\"$i\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 229,
						.statementIdx = 218,
						.statement = "forCondition(lesser($i, array.length($array)))",
						.gotoStatementIdx = 222
					},
					{
						.line = 230,
						.statementIdx = 219,
						.statement = "console.log(add($i,add(\": \", $array[$i])))",
						.gotoStatementIdx = -1
					},
					{
						.line = 231,
						.statementIdx = 220,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 232,
						.statementIdx = 221,
						.statement = "end",
						.gotoStatementIdx = 218
					},
					{
						.line = 233,
						.statementIdx = 222,
						.statement = "console.log(\"array iteration with [] opertator and some index math: \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 234,
						.statementIdx = 223,
						.statement = "setVariable(\"$i\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 235,
						.statementIdx = 224,
						.statement = "forCondition(lesser($i,div(array.length($array), 2)))",
						.gotoStatementIdx = 229
					},
					{
						.line = 236,
						.statementIdx = 225,
						.statement = "console.log(add($i,add(\"-a: \", $array[add(mul($i, 2), 0)])))",
						.gotoStatementIdx = -1
					},
					{
						.line = 237,
						.statementIdx = 226,
						.statement = "console.log(add($i,add(\"-b: \", $array[add(mul($i, 2), 1)])))",
						.gotoStatementIdx = -1
					},
					{
						.line = 238,
						.statementIdx = 227,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 239,
						.statementIdx = 228,
						.statement = "end",
						.gotoStatementIdx = 224
					},
					{
						.line = 240,
						.statementIdx = 229,
						.statement = "console.log(\"array removal of 123, 1234, 12345 using array.removeOf\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 241,
						.statementIdx = 230,
						.statement = "setVariable(\"$array\", array.removeOf($array, 123))",
						.gotoStatementIdx = -1
					},
					{
						.line = 242,
						.statementIdx = 231,
						.statement = "setVariable(\"$array\", array.removeOf($array, 1234))",
						.gotoStatementIdx = -1
					},
					{
						.line = 243,
						.statementIdx = 232,
						.statement = "setVariable(\"$array\", array.removeOf($array, 12345))",
						.gotoStatementIdx = -1
					},
					{
						.line = 244,
						.statementIdx = 233,
						.statement = "console.log(\"array now looks like: \", $array)",
						.gotoStatementIdx = -1
					},
					{
						.line = 245,
						.statementIdx = 234,
						.statement = "console.log(\"array indexOf 10: \", array.indexOf($array, 10))",
						.gotoStatementIdx = -1
					},
					{
						.line = 246,
						.statementIdx = 235,
						.statement = "console.log(\"array indexOf 10 beginning to search from 6: \", array.indexOf($array, 10, 6))",
						.gotoStatementIdx = -1
					},
					{
						.line = 247,
						.statementIdx = 236,
						.statement = "console.log(\"---------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 248,
						.statementIdx = 237,
						.statement = "console.log(\"Maps\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 249,
						.statementIdx = 238,
						.statement = "console.log(\"----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 250,
						.statementIdx = 239,
						.statement = "setVariable(\"$map\", map())",
						.gotoStatementIdx = -1
					},
					{
						.line = 251,
						.statementIdx = 240,
						.statement = "console.log(\"map initialized with: $map = map()\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 252,
						.statementIdx = 241,
						.statement = "console.log(\"map now looks like: \", $map)",
						.gotoStatementIdx = -1
					},
					{
						.line = 253,
						.statementIdx = 242,
						.statement = "console.log(\"put some key value pairs into map: $map = map.set()\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 254,
						.statementIdx = 243,
						.statement = "setVariable(\"$map\", map.set($map, \"test1\", 123))",
						.gotoStatementIdx = -1
					},
					{
						.line = 255,
						.statementIdx = 244,
						.statement = "setVariable(\"$map\", map.set($map, \"test2\", 456))",
						.gotoStatementIdx = -1
					},
					{
						.line = 256,
						.statementIdx = 245,
						.statement = "setVariable(\"$map\", map.set($map, \"test3\", 789))",
						.gotoStatementIdx = -1
					},
					{
						.line = 257,
						.statementIdx = 246,
						.statement = "setVariable(\"$map\", map.set($map, \"test4\", array(1,2,3)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 258,
						.statementIdx = 247,
						.statement = "setVariable(\"$map\", map.set($map, \"test5\", \"Yaaaa\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 259,
						.statementIdx = 248,
						.statement = "console.log(\"map now looks like: \", $map)",
						.gotoStatementIdx = -1
					},
					{
						.line = 260,
						.statementIdx = 249,
						.statement = "console.log(\"remove test2 via map.remove: \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 261,
						.statementIdx = 250,
						.statement = "setVariable(\"$map\", map.remove($map, \"test2\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 262,
						.statementIdx = 251,
						.statement = "console.log(\"map now looks like: \", $map)",
						.gotoStatementIdx = -1
					},
					{
						.line = 263,
						.statementIdx = 252,
						.statement = "setVariable(\"$map\", map.set($map, \"test2\", 456))",
						.gotoStatementIdx = -1
					},
					{
						.line = 264,
						.statementIdx = 253,
						.statement = "console.log(\"readding test2: \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 265,
						.statementIdx = 254,
						.statement = "console.log(\"map does have test2 key using map.has(): \", map.has($map, \"test2\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 266,
						.statementIdx = 255,
						.statement = "console.log(\"map does have test8 key using map.has(): \", map.has($map, \"test8\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 267,
						.statementIdx = 256,
						.statement = "console.log(\"map value for test1 key using map.get(): \", map.get($map, \"test1\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 268,
						.statementIdx = 257,
						.statement = "console.log(\"map value for test2 key using map.get(): \", map.get($map, \"test2\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 269,
						.statementIdx = 258,
						.statement = "console.log(\"map value for test3 key using map.get(): \", map.get($map, \"test3\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 270,
						.statementIdx = 259,
						.statement = "console.log(\"map value for test4 key using map.get(): \", map.get($map, \"test4\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 271,
						.statementIdx = 260,
						.statement = "console.log(\"map value for test5 key using map.get(): \", map.get($map, \"test5\"))",
						.gotoStatementIdx = -1
					},
					{
						.line = 272,
						.statementIdx = 261,
						.statement = "console.log(\"map value for test1 using map dot operator: \", $map.test1)",
						.gotoStatementIdx = -1
					},
					{
						.line = 273,
						.statementIdx = 262,
						.statement = "console.log(\"map value for test2 using map dot operator: \", $map.test2)",
						.gotoStatementIdx = -1
					},
					{
						.line = 274,
						.statementIdx = 263,
						.statement = "console.log(\"map value for test3 using map dot operator: \", $map.test3)",
						.gotoStatementIdx = -1
					},
					{
						.line = 275,
						.statementIdx = 264,
						.statement = "console.log(\"map value for test4 using map dot operator: \", $map.test4)",
						.gotoStatementIdx = -1
					},
					{
						.line = 276,
						.statementIdx = 265,
						.statement = "console.log(\"map value for test5 using map dot operator: \", $map.test5)",
						.gotoStatementIdx = -1
					},
					{
						.line = 277,
						.statementIdx = 266,
						.statement = "console.log(\"adding map values using map dot operator: \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 278,
						.statementIdx = 267,
						.statement = "setVariable(\"$map.test6\", 666)",
						.gotoStatementIdx = -1
					},
					{
						.line = 279,
						.statementIdx = 268,
						.statement = "setVariable(\"$map.test7\", 770)",
						.gotoStatementIdx = -1
					},
					{
						.line = 280,
						.statementIdx = 269,
						.statement = "setVariable(\"$map.test8\", 890)",
						.gotoStatementIdx = -1
					},
					{
						.line = 281,
						.statementIdx = 270,
						.statement = "console.log(\"map keys: \", map.getKeys($map))",
						.gotoStatementIdx = -1
					},
					{
						.line = 282,
						.statementIdx = 271,
						.statement = "console.log(\"map values: \", map.getValues($map))",
						.gotoStatementIdx = -1
					},
					{
						.line = 283,
						.statementIdx = 272,
						.statement = "console.log(\"iterating keys and values using map.getKeys(): \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 284,
						.statementIdx = 273,
						.statement = "setVariable(\"$mapKeys\", map.getKeys($map))",
						.gotoStatementIdx = -1
					},
					{
						.line = 285,
						.statementIdx = 274,
						.statement = "setVariable(\"$i\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 286,
						.statementIdx = 275,
						.statement = "forCondition(lesser($i, array.length($mapKeys)))",
						.gotoStatementIdx = 279
					},
					{
						.line = 287,
						.statementIdx = 276,
						.statement = "console.log(add($mapKeys[$i],add(\" = \", map.get($map, $mapKeys[$i]))))",
						.gotoStatementIdx = -1
					},
					{
						.line = 288,
						.statementIdx = 277,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 289,
						.statementIdx = 278,
						.statement = "end",
						.gotoStatementIdx = 275
					},
					{
						.line = 290,
						.statementIdx = 279,
						.statement = "console.log(\"--------------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 291,
						.statementIdx = 280,
						.statement = "console.log(\"Test if enabled naming condition will be emitted\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 292,
						.statementIdx = 281,
						.statement = "console.log(\"--------------------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 293,
						.statementIdx = 282,
						.statement = "script.enableNamedCondition(\"named_condition_1\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 294,
						.statementIdx = 283,
						.statement = "script.wait(2000)",
						.gotoStatementIdx = -1
					},
					{
						.line = 295,
						.statementIdx = 284,
						.statement = "script.disableNamedCondition(\"named_condition_1\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 296,
						.statementIdx = 285,
						.statement = "console.log(\"---------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 297,
						.statementIdx = 286,
						.statement = "console.log(\"Naming condition has not been emitted\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 298,
						.statementIdx = 287,
						.statement = "console.log(\"---------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 299,
						.statementIdx = 288,
						.statement = "script.stop()",
						.gotoStatementIdx = -1
					},
					{
						.line = 300,
						.statementIdx = 289,
						.statement = "end",
						.gotoStatementIdx = -1
					}
				}
			},
			{
				.scriptType = Script::SCRIPTTYPE_ON,
				.line = 302,
				.condition = "error",
				.name = "",
				.emitCondition = true,
				.statements = {
					{
						.line = 303,
						.statementIdx = 0,
						.statement = "console.log(\"An error occurred\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 304,
						.statementIdx = 1,
						.statement = "script.wait(1000)",
						.gotoStatementIdx = -1
					},
					{
						.line = 305,
						.statementIdx = 2,
						.statement = "end",
						.gotoStatementIdx = -1
					}
				}
			},
			{
				.scriptType = Script::SCRIPTTYPE_ON,
				.line = 307,
				.condition = "emittest",
				.name = "",
				.emitCondition = true,
				.statements = {
					{
						.line = 308,
						.statementIdx = 0,
						.statement = "console.log(\"---------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 309,
						.statementIdx = 1,
						.statement = "console.log(\"SCRIPT JUST EMITTED A CONDITION\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 310,
						.statementIdx = 2,
						.statement = "console.log(\"---------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 311,
						.statementIdx = 3,
						.statement = "console.log()",
						.gotoStatementIdx = -1
					},
					{
						.line = 312,
						.statementIdx = 4,
						.statement = "console.log(\"----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 313,
						.statementIdx = 5,
						.statement = "console.log(\"Benchmark \")",
						.gotoStatementIdx = -1
					},
					{
						.line = 314,
						.statementIdx = 6,
						.statement = "console.log(\"----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 315,
						.statementIdx = 7,
						.statement = "setVariable(\"$startTime\", time.getCurrentMillis())",
						.gotoStatementIdx = -1
					},
					{
						.line = 316,
						.statementIdx = 8,
						.statement = "setVariable(\"$i\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 317,
						.statementIdx = 9,
						.statement = "setVariable(\"$j\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 318,
						.statementIdx = 10,
						.statement = "setVariable(\"$k\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 319,
						.statementIdx = 11,
						.statement = "forCondition(lesser($i, 500000))",
						.gotoStatementIdx = 22
					},
					{
						.line = 320,
						.statementIdx = 12,
						.statement = "setVariable(\"$a\",sub(add(123,add(mul(456,div(25, 12)),mul(7.5, 12.25))), 8))",
						.gotoStatementIdx = -1
					},
					{
						.line = 321,
						.statementIdx = 13,
						.statement = "if (equals($j, 0))",
						.gotoStatementIdx = 15
					},
					{
						.line = 322,
						.statementIdx = 14,
						.statement = "setVariable(\"$k\",add($k, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 323,
						.statementIdx = 15,
						.statement = "end",
						.gotoStatementIdx = -1
					},
					{
						.line = 324,
						.statementIdx = 16,
						.statement = "setVariable(\"$i\",add($i, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 325,
						.statementIdx = 17,
						.statement = "setVariable(\"$j\",add($j, 1))",
						.gotoStatementIdx = -1
					},
					{
						.line = 326,
						.statementIdx = 18,
						.statement = "if (equals($j, 2))",
						.gotoStatementIdx = 20
					},
					{
						.line = 327,
						.statementIdx = 19,
						.statement = "setVariable(\"$j\", 0)",
						.gotoStatementIdx = -1
					},
					{
						.line = 328,
						.statementIdx = 20,
						.statement = "end",
						.gotoStatementIdx = -1
					},
					{
						.line = 329,
						.statementIdx = 21,
						.statement = "end",
						.gotoStatementIdx = 11
					},
					{
						.line = 330,
						.statementIdx = 22,
						.statement = "setVariable(\"$endTime\", time.getCurrentMillis())",
						.gotoStatementIdx = -1
					},
					{
						.line = 331,
						.statementIdx = 23,
						.statement = "console.log(add(\"Finished. Time: \", sub($endTime, $startTime)))",
						.gotoStatementIdx = -1
					},
					{
						.line = 332,
						.statementIdx = 24,
						.statement = "script.stop()",
						.gotoStatementIdx = -1
					},
					{
						.line = 333,
						.statementIdx = 25,
						.statement = "end",
						.gotoStatementIdx = -1
					}
				}
			},
			{
				.scriptType = Script::SCRIPTTYPE_ONENABLED,
				.line = 335,
				.condition = "equals(1,1)",
				.name = "named_condition_1",
				.emitCondition = false,
				.statements = {
					{
						.line = 336,
						.statementIdx = 0,
						.statement = "script.disableNamedCondition(\"named_condition_1\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 337,
						.statementIdx = 1,
						.statement = "console.log(\"------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 338,
						.statementIdx = 2,
						.statement = "console.log(\"named_condition_1 has been emitted\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 339,
						.statementIdx = 3,
						.statement = "console.log(\"------------------------------------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 340,
						.statementIdx = 4,
						.statement = "console.log()",
						.gotoStatementIdx = -1
					},
					{
						.line = 341,
						.statementIdx = 5,
						.statement = "console.log(\"-----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 342,
						.statementIdx = 6,
						.statement = "console.log(\"Test emit\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 343,
						.statementIdx = 7,
						.statement = "console.log(\"-----------\")",
						.gotoStatementIdx = -1
					},
					{
						.line = 344,
						.statementIdx = 8,
						.statement = "console.log()",
						.gotoStatementIdx = -1
					},
					{
						.line = 345,
						.statementIdx = 9,
						.statement = "script.emit(emittest)",
						.gotoStatementIdx = -1
					},
					{
						.line = 346,
						.statementIdx = 10,
						.statement = "end",
						.gotoStatementIdx = -1
					}
				}
			}
		}
	);
}

int MiniScriptTest::determineScriptIdxToStart() {
	if (native == false) return MiniScript::determineScriptIdxToStart();
	auto miniScript = this;

	//
	return 1;
}

int MiniScriptTest::determineNamedScriptIdxToStart() {
	if (native == false) return MiniScript::determineNamedScriptIdxToStart();
	auto miniScript = this;
	for (auto& enabledNamedCondition: scriptState.enabledNamedConditions) {

		// next statements belong to tested enabled named condition with name "named_condition_1"
		if (enabledNamedCondition == "named_condition_1")
			// equals(1, 1)
			{
				const ScriptStatement statement = {
					.line = 335,
					.statementIdx = 0,
					.statement = "<unavailable>",
					.gotoStatementIdx = -1
				};
				miniScript->scriptState.statementIdx = statement.statementIdx;
				// required method code arguments
				ScriptVariable returnValue;
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(1));
				// method code: equals
				returnValue.setValue(true);
				for (auto i = 1; i < argumentValues.size(); i++) {
					if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
						returnValue.setValue(false);
						break;
					}
				}
				bool returnValueBool; returnValue.getBooleanValue(returnValueBool); if (returnValueBool == true) return 4;
			}
	
	}

	//
	return -1;
}

void MiniScriptTest::emit(const string& condition) {
	if (native == false) {
		MiniScript::emit(condition);
		return;
	}
	if (condition == "initialize") {
		on_initialize(-1);
		return;
	}
	if (condition == "nothing") {
		on_nothing(-1);
		return;
	}
	if (condition == "error") {
		on_error(-1);
		return;
	}
	if (condition == "emittest") {
		on_emittest(-1);
		return;
	}
}

void MiniScriptTest::on_initialize(int miniScriptGotoStatementIdx) {
	// -1 means complete method call
	if (miniScriptGotoStatementIdx == -1) {
		resetScriptExecutationState(0, STATE_NEXT_STATEMENT);
	}
	auto miniScript = this;
	miniScript->scriptState.scriptIdx = 0;
	if (miniScriptGotoStatementIdx != -1 && miniScriptGotoStatementIdx != 0) Console::println("MiniScript::on_initialize(): Can not go to statement " + to_string(miniScriptGotoStatementIdx));

	// Statement: 0
	// console.log("------------")
	{
		const ScriptStatement& statement = scripts[0].statements[0];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 1
	// console.log("Initialize")
	{
		const ScriptStatement& statement = scripts[0].statements[1];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Initialize"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 2
	// console.log("------------")
	{
		const ScriptStatement& statement = scripts[0].statements[2];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 3
	// console.log()
	{
		const ScriptStatement& statement = scripts[0].statements[3];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 4
	// end()
	{
		const ScriptStatement& statement = scripts[0].statements[4];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}
	scriptState.scriptIdx = -1;
	scriptState.statementIdx = -1;
	setScriptState(STATE_WAIT_FOR_CONDITION);
}

void MiniScriptTest::on_nothing(int miniScriptGotoStatementIdx) {
	// -1 means complete method call
	if (miniScriptGotoStatementIdx == -1) {
		resetScriptExecutationState(1, STATE_NEXT_STATEMENT);
	}
	auto miniScript = this;
	miniScript->scriptState.scriptIdx = 1;
	if (miniScriptGotoStatementIdx == 147) goto miniscript_statement_147; else
	if (miniScriptGotoStatementIdx == 149) goto miniscript_statement_149; else
	if (miniScriptGotoStatementIdx == 151) goto miniscript_statement_151; else
	if (miniScriptGotoStatementIdx == 156) goto miniscript_statement_156; else
	if (miniScriptGotoStatementIdx == 158) goto miniscript_statement_158; else
	if (miniScriptGotoStatementIdx == 160) goto miniscript_statement_160; else
	if (miniScriptGotoStatementIdx == 166) goto miniscript_statement_166; else
	if (miniScriptGotoStatementIdx == 168) goto miniscript_statement_168; else
	if (miniScriptGotoStatementIdx == 170) goto miniscript_statement_170; else
	if (miniScriptGotoStatementIdx == 172) goto miniscript_statement_172; else
	if (miniScriptGotoStatementIdx == 174) goto miniscript_statement_174; else
	if (miniScriptGotoStatementIdx == 176) goto miniscript_statement_176; else
	if (miniScriptGotoStatementIdx == 178) goto miniscript_statement_178; else
	if (miniScriptGotoStatementIdx == 180) goto miniscript_statement_180; else
	if (miniScriptGotoStatementIdx == 184) goto miniscript_statement_184; else
	if (miniScriptGotoStatementIdx == 186) goto miniscript_statement_186; else
	if (miniScriptGotoStatementIdx == 213) goto miniscript_statement_213; else
	if (miniScriptGotoStatementIdx == 216) goto miniscript_statement_216; else
	if (miniScriptGotoStatementIdx == 219) goto miniscript_statement_219; else
	if (miniScriptGotoStatementIdx == 222) goto miniscript_statement_222; else
	if (miniScriptGotoStatementIdx == 225) goto miniscript_statement_225; else
	if (miniScriptGotoStatementIdx == 229) goto miniscript_statement_229; else
	if (miniScriptGotoStatementIdx == 276) goto miniscript_statement_276; else
	if (miniScriptGotoStatementIdx == 279) goto miniscript_statement_279; else
	if (miniScriptGotoStatementIdx == 284) goto miniscript_statement_284; else
	if (miniScriptGotoStatementIdx != -1 && miniScriptGotoStatementIdx != 0) Console::println("MiniScript::on_nothing(): Can not go to statement " + to_string(miniScriptGotoStatementIdx));

	// Statement: 0
	// console.log("---------")
	{
		const ScriptStatement& statement = scripts[1].statements[0];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 1
	// console.log("Nothing")
	{
		const ScriptStatement& statement = scripts[1].statements[1];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Nothing"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 2
	// console.log("----------")
	{
		const ScriptStatement& statement = scripts[1].statements[2];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 3
	// console.log()
	{
		const ScriptStatement& statement = scripts[1].statements[3];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 4
	// console.log("-----------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[4];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 5
	// console.log("Check bool operations")
	{
		const ScriptStatement& statement = scripts[1].statements[5];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check bool operations"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 6
	// console.log("-----------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[6];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 7
	// console.log("MiniScript will do the job: and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true): ", and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true))
	{
		const ScriptStatement& statement = scripts[1].statements[7];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("MiniScript will do the job: and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true): "));
		// argumentValues[1] --> returnValue of and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true)
		// depth = 1 / argument index = 1: and(or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will)), true)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will))
			argumentValues[1].setValue(true);
			// depth = 2 / argument index = 0: or(equals(MiniScript will do the job, MiniScript will not do the job), equals(it will, it will))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of equals(MiniScript will do the job, MiniScript will not do the job)
				// argumentValues[1] --> returnValue of equals(it will, it will)
				// depth = 3 / argument index = 0: equals(MiniScript will do the job, MiniScript will not do the job)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("MiniScript will do the job"));
					argumentValues[1].setValue(string("MiniScript will not do the job"));
					// method code: equals
					returnValue.setValue(true);
					for (auto i = 1; i < argumentValues.size(); i++) {
						if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
							returnValue.setValue(false);
							break;
						}
					}
				}
				// depth = 3 / argument index = 1: equals(it will, it will)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("it will"));
					argumentValues[1].setValue(string("it will"));
					// method code: equals
					returnValue.setValue(true);
					for (auto i = 1; i < argumentValues.size(); i++) {
						if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
							returnValue.setValue(false);
							break;
						}
					}
				}
				// method code: or
				returnValue.setValue(false);
				for (auto i = 0; i < argumentValues.size(); i++) {
					bool booleanValue;
					if (MiniScript::getBooleanValue(argumentValues, i, booleanValue, false) == false) {
						Console::println("ScriptMethodOr::executeMethod(): " + string("or") + "(): parameter type mismatch @ argument " + to_string(i) + ": boolean expected");
						miniScript->startErrorScript(); return;
					} else
					if (booleanValue == true) {
						returnValue.setValue(true);
						break;
					}
				}
			}
			// method code: and
			returnValue.setValue(true);
			for (auto i = 0; i < argumentValues.size(); i++) {
				bool booleanValue;
				if (MiniScript::getBooleanValue(argumentValues, i, booleanValue, false) == false) {
					Console::println("ScriptMethodAnd::executeMethod(): " + string("and") + "(): parameter type mismatch @ argument " + to_string(i) + ": boolean expected");
					miniScript->startErrorScript(); return;
				} else
				if (booleanValue == false) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 8
	// console.log("-----------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[8];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 9
	// console.log("Check int computation")
	{
		const ScriptStatement& statement = scripts[1].statements[9];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check int computation"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 10
	// console.log("-----------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[10];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 11
	// console.log("sub(add(1, 2, 3), 1)): ", sub(add(1, 2, 3), 1))
	{
		const ScriptStatement& statement = scripts[1].statements[11];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("sub(add(1, 2, 3), 1)): "));
		// argumentValues[1] --> returnValue of sub(add(1, 2, 3), 1)
		// depth = 1 / argument index = 1: sub(add(1, 2, 3), 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of add(1, 2, 3)
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: add(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 12
	// console.log("div(20, 2): ", div(20, 2))
	{
		const ScriptStatement& statement = scripts[1].statements[12];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("div(20, 2): "));
		// argumentValues[1] --> returnValue of div(20, 2)
		// depth = 1 / argument index = 1: div(20, 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(20));
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 13
	// console.log("mul(11, 10): ", mul(11, 10))
	{
		const ScriptStatement& statement = scripts[1].statements[13];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mul(11, 10): "));
		// argumentValues[1] --> returnValue of mul(11, 10)
		// depth = 1 / argument index = 1: mul(11, 10)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(11));
			argumentValues[1].setValue(static_cast<int64_t>(10));
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 14
	// console.log("greater(2, 1): ", greater(2, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[14];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("greater(2, 1): "));
		// argumentValues[1] --> returnValue of greater(2, 1)
		// depth = 1 / argument index = 1: greater(2, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// method code: greater
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA > floatValueB);
			} else {
				Console::println("ScriptMethodGreater::executeMethod(): " + string("greater") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 15
	// console.log("lesser(2, 1): ", lesser(2, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[15];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("lesser(2, 1): "));
		// argumentValues[1] --> returnValue of lesser(2, 1)
		// depth = 1 / argument index = 1: lesser(2, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 16
	// console.log("---------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[16];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 17
	// console.log("Check int computation (Operators)")
	{
		const ScriptStatement& statement = scripts[1].statements[17];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check int computation (Operators)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 18
	// console.log("---------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[18];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 19
	// console.log("1 + 2 + 3 - 1: ", sub(add(1,add(2, 3)), 1))
	{
		const ScriptStatement& statement = scripts[1].statements[19];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("1 + 2 + 3 - 1: "));
		// argumentValues[1] --> returnValue of sub(add(1,add(2, 3)), 1)
		// depth = 1 / argument index = 1: sub(add(1,add(2, 3)), 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of add(1,add(2, 3))
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: add(1, add(2, 3))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				// argumentValues[1] --> returnValue of add(2, 3)
				// depth = 3 / argument index = 1: add(2, 3)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(static_cast<int64_t>(2));
					argumentValues[1].setValue(static_cast<int64_t>(3));
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 20
	// console.log("20 / 2: ", div(20, 2))
	{
		const ScriptStatement& statement = scripts[1].statements[20];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("20 / 2: "));
		// argumentValues[1] --> returnValue of div(20, 2)
		// depth = 1 / argument index = 1: div(20, 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(20));
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 21
	// console.log("11 * 10: ", mul(11, 10))
	{
		const ScriptStatement& statement = scripts[1].statements[21];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("11 * 10: "));
		// argumentValues[1] --> returnValue of mul(11, 10)
		// depth = 1 / argument index = 1: mul(11, 10)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(11));
			argumentValues[1].setValue(static_cast<int64_t>(10));
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 22
	// console.log("2 > 1: ", greater(2, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[22];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("2 > 1: "));
		// argumentValues[1] --> returnValue of greater(2, 1)
		// depth = 1 / argument index = 1: greater(2, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// method code: greater
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA > floatValueB);
			} else {
				Console::println("ScriptMethodGreater::executeMethod(): " + string("greater") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 23
	// console.log("2 < 1: ", lesser(2, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[23];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("2 < 1: "));
		// argumentValues[1] --> returnValue of lesser(2, 1)
		// depth = 1 / argument index = 1: lesser(2, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 24
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[24];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 25
	// console.log("Check float computation")
	{
		const ScriptStatement& statement = scripts[1].statements[25];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check float computation"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 26
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[26];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 27
	// console.log("sub(add(1.1, 2.2, 3.3), 1.2)): ", sub(add(1.1, 2.2, 3.3), 1.2))
	{
		const ScriptStatement& statement = scripts[1].statements[27];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("sub(add(1.1, 2.2, 3.3), 1.2)): "));
		// argumentValues[1] --> returnValue of sub(add(1.1, 2.2, 3.3), 1.2)
		// depth = 1 / argument index = 1: sub(add(1.1, 2.2, 3.3), 1.2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of add(1.1, 2.2, 3.3)
			argumentValues[1].setValue(1.200000f);
			// depth = 2 / argument index = 0: add(1.1, 2.2, 3.3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.100000f);
				argumentValues[1].setValue(2.200000f);
				argumentValues[2].setValue(3.300000f);
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 28
	// console.log("div(20, 1.5): ", div(20, 1.5))
	{
		const ScriptStatement& statement = scripts[1].statements[28];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("div(20, 1.5): "));
		// argumentValues[1] --> returnValue of div(20, 1.5)
		// depth = 1 / argument index = 1: div(20, 1.5)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(20));
			argumentValues[1].setValue(1.500000f);
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 29
	// console.log("mul(11.5, 10.5): ", mul(11.5, 10.5))
	{
		const ScriptStatement& statement = scripts[1].statements[29];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mul(11.5, 10.5): "));
		// argumentValues[1] --> returnValue of mul(11.5, 10.5)
		// depth = 1 / argument index = 1: mul(11.5, 10.5)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(11.500000f);
			argumentValues[1].setValue(10.500000f);
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 30
	// console.log("greater(2.2, 1.3): ", greater(2.2, 1.3))
	{
		const ScriptStatement& statement = scripts[1].statements[30];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("greater(2.2, 1.3): "));
		// argumentValues[1] --> returnValue of greater(2.2, 1.3)
		// depth = 1 / argument index = 1: greater(2.2, 1.3)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(2.200000f);
			argumentValues[1].setValue(1.300000f);
			// method code: greater
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA > floatValueB);
			} else {
				Console::println("ScriptMethodGreater::executeMethod(): " + string("greater") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 31
	// console.log("lesser(2.5, 1.2): ", lesser(2.5, 1.2))
	{
		const ScriptStatement& statement = scripts[1].statements[31];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("lesser(2.5, 1.2): "));
		// argumentValues[1] --> returnValue of lesser(2.5, 1.2)
		// depth = 1 / argument index = 1: lesser(2.5, 1.2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(2.500000f);
			argumentValues[1].setValue(1.200000f);
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 32
	// console.log("-----------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[32];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 33
	// console.log("Check float computation (Operators)")
	{
		const ScriptStatement& statement = scripts[1].statements[33];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check float computation (Operators)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 34
	// console.log("-----------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[34];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 35
	// console.log("(1.1 + 2.2 + 3.3) - 1.2: ", sub(add(1.1,add(2.2, 3.3)), 1.2))
	{
		const ScriptStatement& statement = scripts[1].statements[35];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("(1.1 + 2.2 + 3.3) - 1.2: "));
		// argumentValues[1] --> returnValue of sub(add(1.1,add(2.2, 3.3)), 1.2)
		// depth = 1 / argument index = 1: sub(add(1.1,add(2.2, 3.3)), 1.2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of add(1.1,add(2.2, 3.3))
			argumentValues[1].setValue(1.200000f);
			// depth = 2 / argument index = 0: add(1.1, add(2.2, 3.3))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.100000f);
				// argumentValues[1] --> returnValue of add(2.2, 3.3)
				// depth = 3 / argument index = 1: add(2.2, 3.3)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(2.200000f);
					argumentValues[1].setValue(3.300000f);
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 36
	// console.log("20 / 1.5: ", div(20, 1.5))
	{
		const ScriptStatement& statement = scripts[1].statements[36];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("20 / 1.5: "));
		// argumentValues[1] --> returnValue of div(20, 1.5)
		// depth = 1 / argument index = 1: div(20, 1.5)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(20));
			argumentValues[1].setValue(1.500000f);
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 37
	// console.log("11.5 * 10.5: ", mul(11.5, 10.5))
	{
		const ScriptStatement& statement = scripts[1].statements[37];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("11.5 * 10.5: "));
		// argumentValues[1] --> returnValue of mul(11.5, 10.5)
		// depth = 1 / argument index = 1: mul(11.5, 10.5)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(11.500000f);
			argumentValues[1].setValue(10.500000f);
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 38
	// console.log("2.2 > 1.3: ", greater(2.2, 1.3))
	{
		const ScriptStatement& statement = scripts[1].statements[38];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("2.2 > 1.3: "));
		// argumentValues[1] --> returnValue of greater(2.2, 1.3)
		// depth = 1 / argument index = 1: greater(2.2, 1.3)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(2.200000f);
			argumentValues[1].setValue(1.300000f);
			// method code: greater
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA > floatValueB);
			} else {
				Console::println("ScriptMethodGreater::executeMethod(): " + string("greater") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 39
	// console.log("2.5 < 1.2: ", lesser(2.5, 1.2))
	{
		const ScriptStatement& statement = scripts[1].statements[39];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("2.5 < 1.2: "));
		// argumentValues[1] --> returnValue of lesser(2.5, 1.2)
		// depth = 1 / argument index = 1: lesser(2.5, 1.2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(2.500000f);
			argumentValues[1].setValue(1.200000f);
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 40
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[40];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 41
	// console.log("Check vector2 math")
	{
		const ScriptStatement& statement = scripts[1].statements[41];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check vector2 math"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 42
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[42];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 43
	// console.log("vec2.computeLength(vec2(20, 10)): ", vec2.computeLength(vec2(20, 10)))
	{
		const ScriptStatement& statement = scripts[1].statements[43];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.computeLength(vec2(20, 10)): "));
		// argumentValues[1] --> returnValue of vec2.computeLength(vec2(20, 10))
		// depth = 1 / argument index = 1: vec2.computeLength(vec2(20, 10))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.computeLength
			Vector2 vec2;
			if (MiniScript::getVector2Value(argumentValues, 0, vec2, false) == true) {
				returnValue.setValue(vec2.computeLength());
			} else {
				Console::println("ScriptMethodVec2ComputeLength::executeMethod(): " + string("vec2.computeLength") + "(): parameter type mismatch @ argument 0: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 44
	// console.log("vec2.computeLengthSquared(vec2(20, 10)): ", vec2.computeLengthSquared(vec2(20, 10)))
	{
		const ScriptStatement& statement = scripts[1].statements[44];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.computeLengthSquared(vec2(20, 10)): "));
		// argumentValues[1] --> returnValue of vec2.computeLengthSquared(vec2(20, 10))
		// depth = 1 / argument index = 1: vec2.computeLengthSquared(vec2(20, 10))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.computeLengthSquared
			Vector2 vec2;
			if (MiniScript::getVector2Value(argumentValues, 0, vec2, false) == true) {
				returnValue.setValue(vec2.computeLengthSquared());
			} else {
				Console::println("ScriptMethodVec2ComputeLengthSquared::executeMethod(): " + string("vec2.computeLengthSquared") + "(): parameter type mismatch @ argument 0: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 45
	// console.log("vec2.computeDotProduct(vec2(0, 1), vec2(0, -1)): ", vec2.computeDotProduct(vec2(0, 1), vec2(0, -1)))
	{
		const ScriptStatement& statement = scripts[1].statements[45];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.computeDotProduct(vec2(0, 1), vec2(0, -1)): "));
		// argumentValues[1] --> returnValue of vec2.computeDotProduct(vec2(0, 1), vec2(0, -1))
		// depth = 1 / argument index = 1: vec2.computeDotProduct(vec2(0, 1), vec2(0, -1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(0, 1)
			// argumentValues[1] --> returnValue of vec2(0, -1)
			// depth = 2 / argument index = 0: vec2(0, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(1));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec2(0, -1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(-1));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.computeDotProduct
			Vector2 a;
			Vector2 b;
			if (MiniScript::getVector2Value(argumentValues, 0, a, false) == true &&
				MiniScript::getVector2Value(argumentValues, 1, b, false) == true) {
				returnValue.setValue(Vector2::computeDotProduct(a, b));
			} else {
				Console::println("ScriptMethodVec2ComputeDotProduct::executeMethod(): " + string("vec2.computeDotProduct") + "(): parameter type mismatch @ argument 0: vector2 expected, @ argument 1: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 46
	// console.log("vec2.normalize(vec2(1, 2)): ", vec2.normalize(vec2(1, 2)))
	{
		const ScriptStatement& statement = scripts[1].statements[46];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.normalize(vec2(1, 2)): "));
		// argumentValues[1] --> returnValue of vec2.normalize(vec2(1, 2))
		// depth = 1 / argument index = 1: vec2.normalize(vec2(1, 2))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(1, 2)
			// depth = 2 / argument index = 0: vec2(1, 2)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.normalize
			Vector2 vec2;
			if (MiniScript::getVector2Value(argumentValues, 0, vec2, false) == true) {
				returnValue.setValue(vec2.normalize());
			} else {
				Console::println("ScriptMethodVec2Normalize::executeMethod(): " + string("vec2.normalize") + "(): parameter type mismatch @ argument 0: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 47
	// console.log("vec2.getX(vec2(1, 2)): ", vec2.getX(vec2(1, 2)))
	{
		const ScriptStatement& statement = scripts[1].statements[47];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.getX(vec2(1, 2)): "));
		// argumentValues[1] --> returnValue of vec2.getX(vec2(1, 2))
		// depth = 1 / argument index = 1: vec2.getX(vec2(1, 2))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(1, 2)
			// depth = 2 / argument index = 0: vec2(1, 2)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.getX
			Vector2 vec2;
			if (MiniScript::getVector2Value(argumentValues, 0, vec2, false) == true) {
				returnValue.setValue(vec2.getX());
			} else {
				Console::println("ScriptMethodVec2GetX::executeMethod(): " + string("vec2.getX") + "(): parameter type mismatch @ argument 0: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 48
	// console.log("vec2.getY(vec2(1, 2)): ", vec2.getY(vec2(1, 2)))
	{
		const ScriptStatement& statement = scripts[1].statements[48];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2.getY(vec2(1, 2)): "));
		// argumentValues[1] --> returnValue of vec2.getY(vec2(1, 2))
		// depth = 1 / argument index = 1: vec2.getY(vec2(1, 2))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(1, 2)
			// depth = 2 / argument index = 0: vec2(1, 2)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec2.getY
			Vector2 vec2;
			if (MiniScript::getVector2Value(argumentValues, 0, vec2, false) == true) {
				returnValue.setValue(vec2.getY());
			} else {
				Console::println("ScriptMethodVec2GetY::executeMethod(): " + string("vec2.getY") + "(): parameter type mismatch @ argument 0: vector2 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 49
	// console.log("vec2(1.1, 2.2) - vec2(1.2, 1.0): ", sub(vec2(1.1, 2.2), vec2(1.2, 1.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[49];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2(1.1, 2.2) - vec2(1.2, 1.0): "));
		// argumentValues[1] --> returnValue of sub(vec2(1.1, 2.2), vec2(1.2, 1.0))
		// depth = 1 / argument index = 1: sub(vec2(1.1, 2.2), vec2(1.2, 1.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(1.1, 2.2)
			// argumentValues[1] --> returnValue of vec2(1.2, 1.0)
			// depth = 2 / argument index = 0: vec2(1.1, 2.2)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.100000f);
				argumentValues[1].setValue(2.200000f);
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec2(1.2, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.200000f);
				argumentValues[1].setValue(1.000000f);
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 50
	// console.log("vec2(20, 10) / vec2(1.5, 2.5): ", div(vec2(20, 10), vec2(1.5, 2.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[50];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2(20, 10) / vec2(1.5, 2.5): "));
		// argumentValues[1] --> returnValue of div(vec2(20, 10), vec2(1.5, 2.5))
		// depth = 1 / argument index = 1: div(vec2(20, 10), vec2(1.5, 2.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			// argumentValues[1] --> returnValue of vec2(1.5, 2.5)
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec2(1.5, 2.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 51
	// console.log("vec2(20, 10) * vec2(1.5, 2.5)): ", mul(vec2(20, 10), vec2(1.5, 2.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[51];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2(20, 10) * vec2(1.5, 2.5)): "));
		// argumentValues[1] --> returnValue of mul(vec2(20, 10), vec2(1.5, 2.5))
		// depth = 1 / argument index = 1: mul(vec2(20, 10), vec2(1.5, 2.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			// argumentValues[1] --> returnValue of vec2(1.5, 2.5)
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec2(1.5, 2.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 52
	// console.log("vec2(20, 10) / 2): ", div(vec2(20, 10), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[52];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2(20, 10) / 2): "));
		// argumentValues[1] --> returnValue of div(vec2(20, 10), 2)
		// depth = 1 / argument index = 1: div(vec2(20, 10), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 53
	// console.log("vec2(20, 10) * 2): ", mul(vec2(20, 10), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[53];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec2(20, 10) * 2): "));
		// argumentValues[1] --> returnValue of mul(vec2(20, 10), 2)
		// depth = 1 / argument index = 1: mul(vec2(20, 10), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec2(20, 10)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec2(20, 10)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				// method code: vec2
				Vector3 result;
				float xValue;
				float yValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true) {
					returnValue.setValue(Vector2(xValue, yValue));
				} else {
					Console::println("ScriptMethodVec2::executeMethod(): " + string("vec2") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 54
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[54];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 55
	// console.log("Check vector3 math")
	{
		const ScriptStatement& statement = scripts[1].statements[55];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check vector3 math"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 56
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[56];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 57
	// console.log("vec3.computeLength(vec3(20, 10, 5)): ", vec3.computeLength(vec3(20, 10, 5)))
	{
		const ScriptStatement& statement = scripts[1].statements[57];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.computeLength(vec3(20, 10, 5)): "));
		// argumentValues[1] --> returnValue of vec3.computeLength(vec3(20, 10, 5))
		// depth = 1 / argument index = 1: vec3.computeLength(vec3(20, 10, 5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.computeLength
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.computeLength());
			} else {
				Console::println("ScriptMethodVec3ComputeLength::executeMethod(): " + string("vec3.computeLength") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 58
	// console.log("vec3.computeLengthSquared(vec3(20, 10, 5)): ", vec3.computeLengthSquared(vec3(20, 10, 5)))
	{
		const ScriptStatement& statement = scripts[1].statements[58];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.computeLengthSquared(vec3(20, 10, 5)): "));
		// argumentValues[1] --> returnValue of vec3.computeLengthSquared(vec3(20, 10, 5))
		// depth = 1 / argument index = 1: vec3.computeLengthSquared(vec3(20, 10, 5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.computeLengthSquared
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.computeLengthSquared());
			} else {
				Console::println("ScriptMethodVec3ComputeLengthSquared::executeMethod(): " + string("vec3.computeLengthSquared") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 59
	// console.log("vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1)): ", vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1)))
	{
		const ScriptStatement& statement = scripts[1].statements[59];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1)): "));
		// argumentValues[1] --> returnValue of vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1))
		// depth = 1 / argument index = 1: vec3.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(0, 0, 1)
			// argumentValues[1] --> returnValue of vec3(0, 0, -1)
			// depth = 2 / argument index = 0: vec3(0, 0, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(1));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0, 0, -1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(-1));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.computeDotProduct
			Vector3 a;
			Vector3 b;
			if (MiniScript::getVector3Value(argumentValues, 0, a, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, b, false) == true) {
				returnValue.setValue(Vector3::computeDotProduct(a, b));
			} else {
				Console::println("ScriptMethodVec3ComputeDotProduct::executeMethod(): " + string("vec3.computeDotProduct") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 60
	// console.log("vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0)): ", vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0)))
	{
		const ScriptStatement& statement = scripts[1].statements[60];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0)): "));
		// argumentValues[1] --> returnValue of vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0))
		// depth = 1 / argument index = 1: vec3.computeCrossProduct(vec3(1, 0, 0), vec3(0, 1, 0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1, 0, 0)
			// argumentValues[1] --> returnValue of vec3(0, 1, 0)
			// depth = 2 / argument index = 0: vec3(1, 0, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0, 1, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(1));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.computeCrossProduct
			Vector3 a;
			Vector3 b;
			if (MiniScript::getVector3Value(argumentValues, 0, a, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, b, false) == true) {
				returnValue.setValue(Vector3::computeCrossProduct(a, b));
			} else {
				Console::println("ScriptMethodVec3ComputeCrossProduct::executeMethod(): " + string("vec3.computeCrossProduct") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 61
	// console.log("vec3.normalize(vec3(1, 2, 3)): ", vec3.normalize(vec3(1, 2, 3)))
	{
		const ScriptStatement& statement = scripts[1].statements[61];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.normalize(vec3(1, 2, 3)): "));
		// argumentValues[1] --> returnValue of vec3.normalize(vec3(1, 2, 3))
		// depth = 1 / argument index = 1: vec3.normalize(vec3(1, 2, 3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1, 2, 3)
			// depth = 2 / argument index = 0: vec3(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.normalize
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.normalize());
			} else {
				Console::println("ScriptMethodVec3Normalize::executeMethod(): " + string("vec3.normalize") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 62
	// console.log("vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0)): ", vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0)))
	{
		const ScriptStatement& statement = scripts[1].statements[62];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0)): "));
		// argumentValues[1] --> returnValue of vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0))
		// depth = 1 / argument index = 1: vec3.computeAngle(vec3(0, 0, 1), vec3(1, 0, 0), vec3(0, 1, 0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(0, 0, 1)
			// argumentValues[1] --> returnValue of vec3(1, 0, 0)
			// argumentValues[2] --> returnValue of vec3(0, 1, 0)
			// depth = 2 / argument index = 0: vec3(0, 0, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(1));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(1, 0, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 2: vec3(0, 1, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[2];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX2 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(1));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.computeAngle
			Vector3 a;
			Vector3 b;
			Vector3 n;
			if (MiniScript::getVector3Value(argumentValues, 0, a, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, b, false) == true &&
				MiniScript::getVector3Value(argumentValues, 2, n, false) == true) {
				returnValue.setValue(Vector3::computeAngle(a, b, n));
			} else {
				Console::println("ScriptMethodVec3ComputeAngle::executeMethod(): " + string("vec3.computeAngle") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: vector3 expected @ argument 2: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 63
	// console.log("vec3.getX(vec3(1, 2, 3)): ", vec3.getX(vec3(1, 2, 3)))
	{
		const ScriptStatement& statement = scripts[1].statements[63];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.getX(vec3(1, 2, 3)): "));
		// argumentValues[1] --> returnValue of vec3.getX(vec3(1, 2, 3))
		// depth = 1 / argument index = 1: vec3.getX(vec3(1, 2, 3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1, 2, 3)
			// depth = 2 / argument index = 0: vec3(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.getX
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.getX());
			} else {
				Console::println("ScriptMethodVec3GetX::executeMethod(): " + string("vec3.getX") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 64
	// console.log("vec3.getY(vec3(1, 2, 3)): ", vec3.getY(vec3(1, 2, 3)))
	{
		const ScriptStatement& statement = scripts[1].statements[64];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.getY(vec3(1, 2, 3)): "));
		// argumentValues[1] --> returnValue of vec3.getY(vec3(1, 2, 3))
		// depth = 1 / argument index = 1: vec3.getY(vec3(1, 2, 3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1, 2, 3)
			// depth = 2 / argument index = 0: vec3(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.getY
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.getY());
			} else {
				Console::println("ScriptMethodVec3GetY::executeMethod(): " + string("vec3.getY") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 65
	// console.log("vec3.getZ(vec3(1, 2, 3)): ", vec3.getZ(vec3(1, 2, 3)))
	{
		const ScriptStatement& statement = scripts[1].statements[65];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3.getZ(vec3(1, 2, 3)): "));
		// argumentValues[1] --> returnValue of vec3.getZ(vec3(1, 2, 3))
		// depth = 1 / argument index = 1: vec3.getZ(vec3(1, 2, 3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1, 2, 3)
			// depth = 2 / argument index = 0: vec3(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec3.getZ
			Vector3 vec3;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3, false) == true) {
				returnValue.setValue(vec3.getZ());
			} else {
				Console::println("ScriptMethodVec3GetZ::executeMethod(): " + string("vec3.getZ") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 66
	// console.log("vec3(1.1, 2.2, 3.3) - vec3(1.2, 1.0, 1.0): ", sub(vec3(1.1, 2.2, 3.3), vec3(1.2, 1.0, 1.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[66];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3(1.1, 2.2, 3.3) - vec3(1.2, 1.0, 1.0): "));
		// argumentValues[1] --> returnValue of sub(vec3(1.1, 2.2, 3.3), vec3(1.2, 1.0, 1.0))
		// depth = 1 / argument index = 1: sub(vec3(1.1, 2.2, 3.3), vec3(1.2, 1.0, 1.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1.1, 2.2, 3.3)
			// argumentValues[1] --> returnValue of vec3(1.2, 1.0, 1.0)
			// depth = 2 / argument index = 0: vec3(1.1, 2.2, 3.3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.100000f);
				argumentValues[1].setValue(2.200000f);
				argumentValues[2].setValue(3.300000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(1.2, 1.0, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.200000f);
				argumentValues[1].setValue(1.000000f);
				argumentValues[2].setValue(1.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 67
	// console.log("vec3(20, 10, 5) / vec3(1.5, 2.5, 3.5): ", div(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[67];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3(20, 10, 5) / vec3(1.5, 2.5, 3.5): "));
		// argumentValues[1] --> returnValue of div(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5))
		// depth = 1 / argument index = 1: div(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			// argumentValues[1] --> returnValue of vec3(1.5, 2.5, 3.5)
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(1.5, 2.5, 3.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				argumentValues[2].setValue(3.500000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 68
	// console.log("vec3(20, 10, 5) * vec3(1.5, 2.5, 3.5)): ", mul(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[68];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3(20, 10, 5) * vec3(1.5, 2.5, 3.5)): "));
		// argumentValues[1] --> returnValue of mul(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5))
		// depth = 1 / argument index = 1: mul(vec3(20, 10, 5), vec3(1.5, 2.5, 3.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			// argumentValues[1] --> returnValue of vec3(1.5, 2.5, 3.5)
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(1.5, 2.5, 3.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				argumentValues[2].setValue(3.500000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 69
	// console.log("vec3(20, 10, 5) / 2): ", div(vec3(20, 10, 5), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[69];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3(20, 10, 5) / 2): "));
		// argumentValues[1] --> returnValue of div(vec3(20, 10, 5), 2)
		// depth = 1 / argument index = 1: div(vec3(20, 10, 5), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 70
	// console.log("vec3(20, 10, 5) * 2): ", mul(vec3(20, 10, 5), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[70];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec3(20, 10, 5) * 2): "));
		// argumentValues[1] --> returnValue of mul(vec3(20, 10, 5), 2)
		// depth = 1 / argument index = 1: mul(vec3(20, 10, 5), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(20, 10, 5)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec3(20, 10, 5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 71
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[71];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 72
	// console.log("Check vector4 math")
	{
		const ScriptStatement& statement = scripts[1].statements[72];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check vector4 math"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 73
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[73];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 74
	// console.log("vec4.computeLength(vec4(20, 10, 5, 2.5)): ", vec4.computeLength(vec4(20, 10, 5, 2.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[74];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.computeLength(vec4(20, 10, 5, 2.5)): "));
		// argumentValues[1] --> returnValue of vec4.computeLength(vec4(20, 10, 5, 2.5))
		// depth = 1 / argument index = 1: vec4.computeLength(vec4(20, 10, 5, 2.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 2.5)
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 2.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(2.500000f);
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.computeLength
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.computeLength());
			} else {
				Console::println("ScriptMethodVec4ComputeLength::executeMethod(): " + string("vec4.computeLength") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 75
	// console.log("vec4.computeLengthSquared(vec3(20, 10, 5)): ", vec4.computeLengthSquared(vec4(20, 10, 5, 2.5)))
	{
		const ScriptStatement& statement = scripts[1].statements[75];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.computeLengthSquared(vec3(20, 10, 5)): "));
		// argumentValues[1] --> returnValue of vec4.computeLengthSquared(vec4(20, 10, 5, 2.5))
		// depth = 1 / argument index = 1: vec4.computeLengthSquared(vec4(20, 10, 5, 2.5))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 2.5)
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 2.5)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(2.500000f);
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.computeLengthSquared
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.computeLengthSquared());
			} else {
				Console::println("ScriptMethodVec4ComputeLengthSquared::executeMethod(): " + string("vec4.computeLengthSquared") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 76
	// console.log("vec4.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1, 1)): ", vec4.computeDotProduct(vec4(0, 0, 1, 1), vec4(0, 0, -1, 1)))
	{
		const ScriptStatement& statement = scripts[1].statements[76];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.computeDotProduct(vec3(0, 0, 1), vec3(0, 0, -1, 1)): "));
		// argumentValues[1] --> returnValue of vec4.computeDotProduct(vec4(0, 0, 1, 1), vec4(0, 0, -1, 1))
		// depth = 1 / argument index = 1: vec4.computeDotProduct(vec4(0, 0, 1, 1), vec4(0, 0, -1, 1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(0, 0, 1, 1)
			// argumentValues[1] --> returnValue of vec4(0, 0, -1, 1)
			// depth = 2 / argument index = 0: vec4(0, 0, 1, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(1));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec4(0, 0, -1, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(-1));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.computeDotProduct
			Vector4 a;
			Vector4 b;
			if (MiniScript::getVector4Value(argumentValues, 0, a, false) == true &&
				MiniScript::getVector4Value(argumentValues, 1, b, false) == true) {
				returnValue.setValue(Vector4::computeDotProduct(a, b));
			} else {
				Console::println("ScriptMethodVec4ComputeDotProduct::executeMethod(): " + string("vec4.computeDotProduct") + "(): parameter type mismatch @ argument 0: vector4 expected, @ argument 1: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 77
	// console.log("vec4.normalize(vec4(1, 2, 3, 4)): ", vec4.normalize(vec4(1, 2, 3, 4)))
	{
		const ScriptStatement& statement = scripts[1].statements[77];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.normalize(vec4(1, 2, 3, 4)): "));
		// argumentValues[1] --> returnValue of vec4.normalize(vec4(1, 2, 3, 4))
		// depth = 1 / argument index = 1: vec4.normalize(vec4(1, 2, 3, 4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1, 2, 3, 4)
			// depth = 2 / argument index = 0: vec4(1, 2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				argumentValues[3].setValue(static_cast<int64_t>(4));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.normalize
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.normalize());
			} else {
				Console::println("ScriptMethodVec4Normalize::executeMethod(): " + string("vec4.normalize") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 78
	// console.log("vec4.getX(vec4(1, 2, 3, 4)): ", vec4.getX(vec4(1, 2, 3, 4)))
	{
		const ScriptStatement& statement = scripts[1].statements[78];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.getX(vec4(1, 2, 3, 4)): "));
		// argumentValues[1] --> returnValue of vec4.getX(vec4(1, 2, 3, 4))
		// depth = 1 / argument index = 1: vec4.getX(vec4(1, 2, 3, 4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1, 2, 3, 4)
			// depth = 2 / argument index = 0: vec4(1, 2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				argumentValues[3].setValue(static_cast<int64_t>(4));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.getX
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.getX());
			} else {
				Console::println("ScriptMethodVec4GetX::executeMethod(): " + string("vec4.getX") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 79
	// console.log("vec4.getY(vec4(1, 2, 3, 4)): ", vec4.getY(vec4(1, 2, 3, 4)))
	{
		const ScriptStatement& statement = scripts[1].statements[79];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.getY(vec4(1, 2, 3, 4)): "));
		// argumentValues[1] --> returnValue of vec4.getY(vec4(1, 2, 3, 4))
		// depth = 1 / argument index = 1: vec4.getY(vec4(1, 2, 3, 4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1, 2, 3, 4)
			// depth = 2 / argument index = 0: vec4(1, 2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				argumentValues[3].setValue(static_cast<int64_t>(4));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.getY
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.getY());
			} else {
				Console::println("ScriptMethodVec4GetY::executeMethod(): " + string("vec4.getY") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 80
	// console.log("vec4.getZ(vec4(1, 2, 3, 4)): ", vec4.getZ(vec4(1, 2, 3, 4)))
	{
		const ScriptStatement& statement = scripts[1].statements[80];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.getZ(vec4(1, 2, 3, 4)): "));
		// argumentValues[1] --> returnValue of vec4.getZ(vec4(1, 2, 3, 4))
		// depth = 1 / argument index = 1: vec4.getZ(vec4(1, 2, 3, 4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1, 2, 3, 4)
			// depth = 2 / argument index = 0: vec4(1, 2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				argumentValues[3].setValue(static_cast<int64_t>(4));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.getZ
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.getZ());
			} else {
				Console::println("ScriptMethodVec4GetZ::executeMethod(): " + string("vec4.getZ") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 81
	// console.log("vec4.getW(vec4(1, 2, 3, 4)): ", vec4.getZ(vec4(1, 2, 3, 4)))
	{
		const ScriptStatement& statement = scripts[1].statements[81];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4.getW(vec4(1, 2, 3, 4)): "));
		// argumentValues[1] --> returnValue of vec4.getZ(vec4(1, 2, 3, 4))
		// depth = 1 / argument index = 1: vec4.getZ(vec4(1, 2, 3, 4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1, 2, 3, 4)
			// depth = 2 / argument index = 0: vec4(1, 2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				argumentValues[3].setValue(static_cast<int64_t>(4));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: vec4.getZ
			Vector4 vec4;
			if (MiniScript::getVector4Value(argumentValues, 0, vec4, false) == true) {
				returnValue.setValue(vec4.getZ());
			} else {
				Console::println("ScriptMethodVec4GetZ::executeMethod(): " + string("vec4.getZ") + "(): parameter type mismatch @ argument 0: vector4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 82
	// console.log("vec4(1.1, 2.2, 3.3, 1.0) - vec4(1.2, 1.0, 1.0, 1.0): ", sub(vec4(1.1, 2.2, 3.3, 1.0), vec4(1.2, 1.0, 1.0, 1.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[82];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4(1.1, 2.2, 3.3, 1.0) - vec4(1.2, 1.0, 1.0, 1.0): "));
		// argumentValues[1] --> returnValue of sub(vec4(1.1, 2.2, 3.3, 1.0), vec4(1.2, 1.0, 1.0, 1.0))
		// depth = 1 / argument index = 1: sub(vec4(1.1, 2.2, 3.3, 1.0), vec4(1.2, 1.0, 1.0, 1.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(1.1, 2.2, 3.3, 1.0)
			// argumentValues[1] --> returnValue of vec4(1.2, 1.0, 1.0, 1.0)
			// depth = 2 / argument index = 0: vec4(1.1, 2.2, 3.3, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.100000f);
				argumentValues[1].setValue(2.200000f);
				argumentValues[2].setValue(3.300000f);
				argumentValues[3].setValue(1.000000f);
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec4(1.2, 1.0, 1.0, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.200000f);
				argumentValues[1].setValue(1.000000f);
				argumentValues[2].setValue(1.000000f);
				argumentValues[3].setValue(1.000000f);
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 83
	// console.log("vec4(20, 10, 5, 1) / vec4(1.5, 2.5, 3.5, 1): ", div(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1)))
	{
		const ScriptStatement& statement = scripts[1].statements[83];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4(20, 10, 5, 1) / vec4(1.5, 2.5, 3.5, 1): "));
		// argumentValues[1] --> returnValue of div(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1))
		// depth = 1 / argument index = 1: div(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 1)
			// argumentValues[1] --> returnValue of vec4(1.5, 2.5, 3.5, 1)
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec4(1.5, 2.5, 3.5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				argumentValues[2].setValue(3.500000f);
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 84
	// console.log("vec4(20, 10, 5, 1) * vec4(1.5, 2.5, 3.5, 1)): ", mul(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1)))
	{
		const ScriptStatement& statement = scripts[1].statements[84];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4(20, 10, 5, 1) * vec4(1.5, 2.5, 3.5, 1)): "));
		// argumentValues[1] --> returnValue of mul(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1))
		// depth = 1 / argument index = 1: mul(vec4(20, 10, 5, 1), vec4(1.5, 2.5, 3.5, 1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 1)
			// argumentValues[1] --> returnValue of vec4(1.5, 2.5, 3.5, 1)
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec4(1.5, 2.5, 3.5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(1.500000f);
				argumentValues[1].setValue(2.500000f);
				argumentValues[2].setValue(3.500000f);
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 85
	// console.log("vec4(20, 10, 5, 1) / 2): ", div(vec4(20, 10, 5, 1), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[85];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4(20, 10, 5, 1) / 2): "));
		// argumentValues[1] --> returnValue of div(vec4(20, 10, 5, 1), 2)
		// depth = 1 / argument index = 1: div(vec4(20, 10, 5, 1), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 1)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: div
			MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 86
	// console.log("vec4(20, 10, 5, 1) * 2): ", mul(vec4(20, 10, 5, 1), 2))
	{
		const ScriptStatement& statement = scripts[1].statements[86];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("vec4(20, 10, 5, 1) * 2): "));
		// argumentValues[1] --> returnValue of mul(vec4(20, 10, 5, 1), 2)
		// depth = 1 / argument index = 1: mul(vec4(20, 10, 5, 1), 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec4(20, 10, 5, 1)
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: vec4(20, 10, 5, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(20));
				argumentValues[1].setValue(static_cast<int64_t>(10));
				argumentValues[2].setValue(static_cast<int64_t>(5));
				argumentValues[3].setValue(static_cast<int64_t>(1));
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mul
			MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 87
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[87];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 88
	// console.log("Check quaternion math")
	{
		const ScriptStatement& statement = scripts[1].statements[88];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check quaternion math"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 89
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[89];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 90
	// console.log("quaternion.identity(): ", quaternion.identity())
	{
		const ScriptStatement& statement = scripts[1].statements[90];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.identity(): "));
		// argumentValues[1] --> returnValue of quaternion.identity()
		// depth = 1 / argument index = 1: quaternion.identity()
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 0> argumentValues;
			array<ScriptVariable, 0>& argumentValuesD1AIDX1 = argumentValues;
			// method code: quaternion.identity
			returnValue.setValue(Quaternion().identity());
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 91
	// console.log("quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0): ", quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))
	{
		const ScriptStatement& statement = scripts[1].statements[91];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0): "));
		// argumentValues[1] --> returnValue of quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
		// depth = 1 / argument index = 1: quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
			argumentValues[1].setValue(90.000000f);
			// depth = 2 / argument index = 0: vec3(0.0, 1.0, 0.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(0.000000f);
				argumentValues[1].setValue(1.000000f);
				argumentValues[2].setValue(0.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: quaternion.rotate
			Vector3 axis;
			float angle;
			if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
				returnValue.setValue(Quaternion().rotate(axis, angle));
			} else {
				Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 92
	// console.log("quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): ", quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[92];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): "));
		// argumentValues[1] --> returnValue of quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		// depth = 1 / argument index = 1: quaternion.normalize(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// depth = 2 / argument index = 0: quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: quaternion.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Quaternion().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: quaternion.normalize
			Quaternion quaternion;
			if (MiniScript::getQuaternionValue(argumentValues, 0, quaternion, false) == true) {
				returnValue.setValue(quaternion.normalize());
			} else {
				Console::println("ScriptMethodQuaternionNormalize::executeMethod(): " + string("quaternion.normalize") + "(): parameter type mismatch @ argument 0: quaternion expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 93
	// console.log("quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)): ", quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[93];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)): "));
		// argumentValues[1] --> returnValue of quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0))
		// depth = 1 / argument index = 1: quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// argumentValues[1] --> returnValue of quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)
			// depth = 2 / argument index = 0: quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: quaternion.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Quaternion().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: quaternion.rotate(vec3(1.0, 0.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(1.0, 0.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(1.0, 0.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(1.000000f);
					argumentValues[1].setValue(0.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: quaternion.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Quaternion().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: quaternion.multiply
			Quaternion quaternion;
			Quaternion quaternionValue;
			Vector3 vec3Value;
			if (argumentValues.size() != 2) {
				Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
				miniScript->startErrorScript(); return;
			} else
			if (MiniScript::getQuaternionValue(argumentValues, 0, quaternion, false) == true) {
				if (MiniScript::getQuaternionValue(argumentValues, 1, quaternionValue, false) == true) {
					returnValue.setValue(quaternion.multiply(quaternionValue));
				} else
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
					returnValue.setValue(quaternion.multiply(vec3Value));
				} else {
					Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 94
	// console.log("quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): ", quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[94];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): "));
		// argumentValues[1] --> returnValue of quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0))
		// depth = 1 / argument index = 1: quaternion.multiply(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// argumentValues[1] --> returnValue of vec3(0.0, 0.0, 1.0)
			// depth = 2 / argument index = 0: quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: quaternion.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Quaternion().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0.0, 0.0, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(0.000000f);
				argumentValues[1].setValue(0.000000f);
				argumentValues[2].setValue(1.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: quaternion.multiply
			Quaternion quaternion;
			Quaternion quaternionValue;
			Vector3 vec3Value;
			if (argumentValues.size() != 2) {
				Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
				miniScript->startErrorScript(); return;
			} else
			if (MiniScript::getQuaternionValue(argumentValues, 0, quaternion, false) == true) {
				if (MiniScript::getQuaternionValue(argumentValues, 1, quaternionValue, false) == true) {
					returnValue.setValue(quaternion.multiply(quaternionValue));
				} else
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
					returnValue.setValue(quaternion.multiply(vec3Value));
				} else {
					Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodQuaternionMultiply::executeMethod(): " + string("quaternion.multiply") + "(): parameter type mismatch @ argument 0: quaternion expected, @ argument 1: quaternion or vec3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 95
	// console.log("quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): ", quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[95];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)): "));
		// argumentValues[1] --> returnValue of quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		// depth = 1 / argument index = 1: quaternion.computeMatrix(quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// depth = 2 / argument index = 0: quaternion.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: quaternion.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Quaternion().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodQuaternionRotate::executeMethod(): " + string("quaternion.rotate") + "(): parameter type mismatch @ argument 0: vec3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: quaternion.computeMatrix
			Quaternion quaternion;
			if (MiniScript::getQuaternionValue(argumentValues, 0, quaternion, false) == true) {
				returnValue.setValue(quaternion.computeMatrix());
			} else {
				Console::println("ScriptMethodQuaternionComputeMatrix::executeMethod(): " + string("quaternion.computeMatrix") + "(): parameter type mismatch @ argument 0: quaternion expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 96
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[96];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 97
	// console.log("Check matrix4x4 math")
	{
		const ScriptStatement& statement = scripts[1].statements[97];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check matrix4x4 math"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 98
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[98];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 99
	// console.log("mat4.identity(): ", mat4.identity())
	{
		const ScriptStatement& statement = scripts[1].statements[99];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.identity(): "));
		// argumentValues[1] --> returnValue of mat4.identity()
		// depth = 1 / argument index = 1: mat4.identity()
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 0> argumentValues;
			array<ScriptVariable, 0>& argumentValuesD1AIDX1 = argumentValues;
			// method code: mat4.identity
			returnValue.setValue(Matrix4x4().identity());
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 100
	// console.log("mat4.translate(vec3(1.0, 2.0, 3.0)): ", mat4.translate(vec3(1.0, 2.0, 3.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[100];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.translate(vec3(1.0, 2.0, 3.0)): "));
		// argumentValues[1] --> returnValue of mat4.translate(vec3(1.0, 2.0, 3.0))
		// depth = 1 / argument index = 1: mat4.translate(vec3(1.0, 2.0, 3.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1.0, 2.0, 3.0)
			// depth = 2 / argument index = 0: vec3(1.0, 2.0, 3.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.000000f);
				argumentValues[1].setValue(2.000000f);
				argumentValues[2].setValue(3.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.translate
			Vector3 translation;
			if (MiniScript::getVector3Value(argumentValues, 0, translation, false) == true) {
				returnValue.setValue(Matrix4x4().identity().translate(translation));
			} else {
				Console::println("ScriptMethodMatrix4x4Translate::executeMethod(): " + string("mat4.translate") + "(): parameter type mismatch @ argument 0: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 101
	// console.log("mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0): ", mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0))
	{
		const ScriptStatement& statement = scripts[1].statements[101];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0): "));
		// argumentValues[1] --> returnValue of mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
		// depth = 1 / argument index = 1: mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
			argumentValues[1].setValue(90.000000f);
			// depth = 2 / argument index = 0: vec3(0.0, 1.0, 0.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(0.000000f);
				argumentValues[1].setValue(1.000000f);
				argumentValues[2].setValue(0.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.rotate
			Vector3 axis;
			float angle;
			if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
				returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
			} else {
				Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 102
	// console.log("mat4.scale(vec3(1.0, 2.0, 3.0)): ", mat4.scale(vec3(1.0, 2.0, 3.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[102];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.scale(vec3(1.0, 2.0, 3.0)): "));
		// argumentValues[1] --> returnValue of mat4.scale(vec3(1.0, 2.0, 3.0))
		// depth = 1 / argument index = 1: mat4.scale(vec3(1.0, 2.0, 3.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1.0, 2.0, 3.0)
			// depth = 2 / argument index = 0: vec3(1.0, 2.0, 3.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(1.000000f);
				argumentValues[1].setValue(2.000000f);
				argumentValues[2].setValue(3.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.scale
			Vector3 vec3Value;
			float floatValue;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3Value, false) == true) {
				returnValue.setValue(Matrix4x4().identity().scale(vec3Value));
			} else
			if (MiniScript::getFloatValue(argumentValues, 0, floatValue, false) == true) {
				returnValue.setValue(Matrix4x4().identity().scale(floatValue));
			} else {
				Console::println("ScriptMethodMatrix4x4Scale::executeMethod(): " + string("mat4.scale") + "(): parameter type mismatch @ argument 0: vector3 or float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 103
	// console.log("mat4.scale(3.0): ", mat4.scale(3.0))
	{
		const ScriptStatement& statement = scripts[1].statements[103];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.scale(3.0): "));
		// argumentValues[1] --> returnValue of mat4.scale(3.0)
		// depth = 1 / argument index = 1: mat4.scale(3.0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(3.000000f);
			// method code: mat4.scale
			Vector3 vec3Value;
			float floatValue;
			if (MiniScript::getVector3Value(argumentValues, 0, vec3Value, false) == true) {
				returnValue.setValue(Matrix4x4().identity().scale(vec3Value));
			} else
			if (MiniScript::getFloatValue(argumentValues, 0, floatValue, false) == true) {
				returnValue.setValue(Matrix4x4().identity().scale(floatValue));
			} else {
				Console::println("ScriptMethodMatrix4x4Scale::executeMethod(): " + string("mat4.scale") + "(): parameter type mismatch @ argument 0: vector3 or float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 104
	// console.log("mat4.invert(mat4.scale(3.0)): ", mat4.invert(mat4.scale(3.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[104];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.invert(mat4.scale(3.0)): "));
		// argumentValues[1] --> returnValue of mat4.invert(mat4.scale(3.0))
		// depth = 1 / argument index = 1: mat4.invert(mat4.scale(3.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of mat4.scale(3.0)
			// depth = 2 / argument index = 0: mat4.scale(3.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(3.000000f);
				// method code: mat4.scale
				Vector3 vec3Value;
				float floatValue;
				if (MiniScript::getVector3Value(argumentValues, 0, vec3Value, false) == true) {
					returnValue.setValue(Matrix4x4().identity().scale(vec3Value));
				} else
				if (MiniScript::getFloatValue(argumentValues, 0, floatValue, false) == true) {
					returnValue.setValue(Matrix4x4().identity().scale(floatValue));
				} else {
					Console::println("ScriptMethodMatrix4x4Scale::executeMethod(): " + string("mat4.scale") + "(): parameter type mismatch @ argument 0: vector3 or float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.invert
			Matrix4x4 mat4;
			if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
				returnValue.setValue(mat4.invert());
			} else {
				Console::println("ScriptMethodMatrix4x4Invert::executeMethod(): " + string("mat4.invert") + "(): parameter type mismatch @ argument 0: matrix4x4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 105
	// console.log("mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)): ", mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[105];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)): "));
		// argumentValues[1] --> returnValue of mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		// depth = 1 / argument index = 1: mat4.computeEulerAngles(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// depth = 2 / argument index = 0: mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: mat4.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.computeEulerAngles
			Matrix4x4 mat4;
			if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
				returnValue.setValue(mat4.computeEulerAngles());
			} else {
				Console::println("ScriptMethodMatrix4x4EulerAngles::executeMethod(): " + string("mat4.computeEulerAngles") + "(): parameter type mismatch @ argument 0: matrix4x4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 106
	// console.log("mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)): ", mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[106];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)): "));
		// argumentValues[1] --> returnValue of mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0))
		// depth = 1 / argument index = 1: mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// argumentValues[1] --> returnValue of mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)
			// depth = 2 / argument index = 0: mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: mat4.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: mat4.rotate(vec3(1.0, 0.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(1.0, 0.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(1.0, 0.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(1.000000f);
					argumentValues[1].setValue(0.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: mat4.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.multiply
			Matrix4x4 mat4;
			Matrix4x4 mat4Value;
			Vector3 vec3Value;
			Vector4 vec4Value;
			if (argumentValues.size() != 2) {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			} else
			if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
				if (MiniScript::getMatrix4x4Value(argumentValues, 1, mat4Value, false) == true) {
					returnValue.setValue(mat4.multiply(mat4Value));
				} else
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec3Value));
				} else
				if (MiniScript::getVector4Value(argumentValues, 1, vec4Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec4Value));
				} else {
					Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 107
	// console.log("mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): ", mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[107];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0)): "));
		// argumentValues[1] --> returnValue of mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0))
		// depth = 1 / argument index = 1: mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), vec3(0.0, 0.0, 1.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			// argumentValues[1] --> returnValue of vec3(0.0, 0.0, 1.0)
			// depth = 2 / argument index = 0: mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
				argumentValues[1].setValue(90.000000f);
				// depth = 3 / argument index = 0: vec3(0.0, 1.0, 0.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 3> argumentValues;
					array<ScriptVariable, 3>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(0.000000f);
					argumentValues[1].setValue(1.000000f);
					argumentValues[2].setValue(0.000000f);
					// method code: vec3
					Vector3 result;
					float xValue;
					float yValue;
					float zValue;
					if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
						MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
						returnValue.setValue(Vector3(xValue, yValue, zValue));
					} else {
						Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: mat4.rotate
				Vector3 axis;
				float angle;
				if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
					returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
				} else {
					Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0.0, 0.0, 1.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(0.000000f);
				argumentValues[1].setValue(0.000000f);
				argumentValues[2].setValue(1.000000f);
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.multiply
			Matrix4x4 mat4;
			Matrix4x4 mat4Value;
			Vector3 vec3Value;
			Vector4 vec4Value;
			if (argumentValues.size() != 2) {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			} else
			if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
				if (MiniScript::getMatrix4x4Value(argumentValues, 1, mat4Value, false) == true) {
					returnValue.setValue(mat4.multiply(mat4Value));
				} else
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec3Value));
				} else
				if (MiniScript::getVector4Value(argumentValues, 1, vec4Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec4Value));
				} else {
					Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 108
	// console.log("mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0)): ", mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0)))
	{
		const ScriptStatement& statement = scripts[1].statements[108];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0)): "));
		// argumentValues[1] --> returnValue of mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0))
		// depth = 1 / argument index = 1: mat4.multiply(mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0))), vec4(0.0, 0.0, 1.0, 0.0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0)))
			// argumentValues[1] --> returnValue of vec4(0.0, 0.0, 1.0, 0.0)
			// depth = 2 / argument index = 0: mat4.multiply(mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0), mat4.translate(vec3(1.0, 2.0, 3.0)))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
				// argumentValues[1] --> returnValue of mat4.translate(vec3(1.0, 2.0, 3.0))
				// depth = 3 / argument index = 0: mat4.rotate(vec3(0.0, 1.0, 0.0), 90.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX0 = argumentValues;
					// argumentValues[0] --> returnValue of vec3(0.0, 1.0, 0.0)
					argumentValues[1].setValue(90.000000f);
					// depth = 4 / argument index = 0: vec3(0.0, 1.0, 0.0)
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX0[0];
						array<ScriptVariable, 3> argumentValues;
						array<ScriptVariable, 3>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(0.000000f);
						argumentValues[1].setValue(1.000000f);
						argumentValues[2].setValue(0.000000f);
						// method code: vec3
						Vector3 result;
						float xValue;
						float yValue;
						float zValue;
						if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
							MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
							MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
							returnValue.setValue(Vector3(xValue, yValue, zValue));
						} else {
							Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
							miniScript->startErrorScript(); return;
						}
					}
					// method code: mat4.rotate
					Vector3 axis;
					float angle;
					if (MiniScript::getVector3Value(argumentValues, 0, axis, false) == true &&
						MiniScript::getFloatValue(argumentValues, 1, angle, false) == true) {
						returnValue.setValue(Matrix4x4().identity().rotate(axis, angle));
					} else {
						Console::println("ScriptMethodMatrix4x4Rotate::executeMethod(): " + string("mat4.rotate") + "(): parameter type mismatch @ argument 0: vector3 expected, @ argument 1: float expected");
						miniScript->startErrorScript(); return;
					}
				}
				// depth = 3 / argument index = 1: mat4.translate(vec3(1.0, 2.0, 3.0))
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					// argumentValues[0] --> returnValue of vec3(1.0, 2.0, 3.0)
					// depth = 4 / argument index = 0: vec3(1.0, 2.0, 3.0)
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[0];
						array<ScriptVariable, 3> argumentValues;
						array<ScriptVariable, 3>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(1.000000f);
						argumentValues[1].setValue(2.000000f);
						argumentValues[2].setValue(3.000000f);
						// method code: vec3
						Vector3 result;
						float xValue;
						float yValue;
						float zValue;
						if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
							MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
							MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
							returnValue.setValue(Vector3(xValue, yValue, zValue));
						} else {
							Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
							miniScript->startErrorScript(); return;
						}
					}
					// method code: mat4.translate
					Vector3 translation;
					if (MiniScript::getVector3Value(argumentValues, 0, translation, false) == true) {
						returnValue.setValue(Matrix4x4().identity().translate(translation));
					} else {
						Console::println("ScriptMethodMatrix4x4Translate::executeMethod(): " + string("mat4.translate") + "(): parameter type mismatch @ argument 0: vector3 expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: mat4.multiply
				Matrix4x4 mat4;
				Matrix4x4 mat4Value;
				Vector3 vec3Value;
				Vector4 vec4Value;
				if (argumentValues.size() != 2) {
					Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
					miniScript->startErrorScript(); return;
				} else
				if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
					if (MiniScript::getMatrix4x4Value(argumentValues, 1, mat4Value, false) == true) {
						returnValue.setValue(mat4.multiply(mat4Value));
					} else
					if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
						returnValue.setValue(mat4.multiply(vec3Value));
					} else
					if (MiniScript::getVector4Value(argumentValues, 1, vec4Value, false) == true) {
						returnValue.setValue(mat4.multiply(vec4Value));
					} else {
						Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
						miniScript->startErrorScript(); return;
					}
				} else {
					Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec4(0.0, 0.0, 1.0, 0.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 4> argumentValues;
				array<ScriptVariable, 4>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(0.000000f);
				argumentValues[1].setValue(0.000000f);
				argumentValues[2].setValue(1.000000f);
				argumentValues[3].setValue(0.000000f);
				// method code: vec4
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				float wValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 3, wValue, false) == true) {
					returnValue.setValue(Vector4(xValue, yValue, zValue, wValue));
				} else {
					Console::println("ScriptMethodVec4::executeMethod(): " + string("vec4") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected, @ argument 3: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: mat4.multiply
			Matrix4x4 mat4;
			Matrix4x4 mat4Value;
			Vector3 vec3Value;
			Vector4 vec4Value;
			if (argumentValues.size() != 2) {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			} else
			if (MiniScript::getMatrix4x4Value(argumentValues, 0, mat4, false) == true) {
				if (MiniScript::getMatrix4x4Value(argumentValues, 1, mat4Value, false) == true) {
					returnValue.setValue(mat4.multiply(mat4Value));
				} else
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec3Value));
				} else
				if (MiniScript::getVector4Value(argumentValues, 1, vec4Value, false) == true) {
					returnValue.setValue(mat4.multiply(vec4Value));
				} else {
					Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodMatrix4x4Multiply::executeMethod(): " + string("mat4.multiply") + "(): parameter type mismatch @ argument 0: matrix4x4 expected, @ argument 1: vec3 or vec4 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 109
	// console.log("-----------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[109];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 110
	// console.log("Check transform")
	{
		const ScriptStatement& statement = scripts[1].statements[110];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check transform"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 111
	// console.log("-----------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[111];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 112
	// setVariable("$transform", transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)))
	{
		const ScriptStatement& statement = scripts[1].statements[112];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$transform"));
		// argumentValues[1] --> returnValue of transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0))
		// depth = 1 / argument index = 1: transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of vec3(1,2,3)
			// argumentValues[1] --> returnValue of vec3(2, 3, 4)
			// argumentValues[2] --> returnValue of vec3(0, 1, 0)
			// depth = 2 / argument index = 0: vec3(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(2, 3, 4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(2));
				argumentValues[1].setValue(static_cast<int64_t>(3));
				argumentValues[2].setValue(static_cast<int64_t>(4));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 2: vec3(0, 1, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[2];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX2 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(1));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform
			Transform transform;
			Vector3 vec3Value;
			if (argumentValues.size() >= 1) {
				if (MiniScript::getVector3Value(argumentValues, 0, vec3Value, true) == true) {
					transform.setTranslation(vec3Value);
				} else {
					Console::println("ScriptMethodTransform::executeMethod(): " + string("transform") + "(): parameter type mismatch @ argument 0: vector3 expected");
					miniScript->startErrorScript(); return;
				}
			}
			if (argumentValues.size() >= 2) {
				if (MiniScript::getVector3Value(argumentValues, 1, vec3Value, true) == true) {
					transform.setScale(vec3Value);
				} else {
					Console::println("ScriptMethodTransform::executeMethod(): " + string("transform") + "(): parameter type mismatch @ argument 1: vector3 expected");
					miniScript->startErrorScript(); return;
				}
			}
			for (auto i = 2; i < argumentValues.size(); i++) {
				if (MiniScript::getVector3Value(argumentValues, i, vec3Value, true) == true) {
					transform.addRotation(vec3Value, 0.0f);
				} else {
					Console::println("ScriptMethodTransform::executeMethod(): " + string("transform") + "(): parameter type mismatch @ argument " + to_string(i) + ": vector3 expected");
					miniScript->startErrorScript(); return;
				}
			}
			transform.update();
			returnValue.setValue(transform);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 113
	// setVariable("$transform", transform.setRotationAngle($transform, 0, 90))
	{
		const ScriptStatement& statement = scripts[1].statements[113];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$transform"));
		// argumentValues[1] --> returnValue of transform.setRotationAngle($transform, 0, 90)
		// depth = 1 / argument index = 1: transform.setRotationAngle($transform, 0, 90)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			argumentValues[2].setValue(static_cast<int64_t>(90));
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.setRotationAngle
			int64_t idx;
			Transform transform;
			float angle;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getIntegerValue(argumentValues, 1, idx, false) == true &&
				MiniScript::getFloatValue(argumentValues, 2, angle, false) == true) {
				if (idx < transform.getRotationCount()) {
					transform.setRotationAngle(idx, angle);
					transform.update();
					returnValue.setValue(transform);
				} else {
					Console::println("ScriptMethodTransformSetRotationAngle::executeMethod(): " + string("transform.setRotationAngle") + "(): rotation index invalid: " + to_string(idx) + " / " + to_string(transform.getRotationCount()));
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodTransformSetRotationAngle::executeMethod(): " + string("transform.setRotationAngle") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: integer expected, @ argument 2: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 114
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)): ", $transform)
	{
		const ScriptStatement& statement = scripts[1].statements[114];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)): "));
		// argumentValues[1] --> returnValue of getVariable("$transform")
		// depth = 1 / argument index = 1: getVariable("$transform")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$transform"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 115
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getTranslation(): ", transform.getTranslation($transform))
	{
		const ScriptStatement& statement = scripts[1].statements[115];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getTranslation(): "));
		// argumentValues[1] --> returnValue of transform.getTranslation($transform)
		// depth = 1 / argument index = 1: transform.getTranslation($transform)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.getTranslation
			Transform transform;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true) {
				returnValue.setValue(transform.getTranslation());
			} else {
				Console::println("ScriptMethodTransformGetTranslation::executeMethod(): " + string("transform.getTranslation") + "(): parameter type mismatch @ argument 0: transform expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 116
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setTranslation(vec3(-1,-2,-3)): ", transform.setTranslation($transform, vec3(-1,-2,-3)))
	{
		const ScriptStatement& statement = scripts[1].statements[116];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setTranslation(vec3(-1,-2,-3)): "));
		// argumentValues[1] --> returnValue of transform.setTranslation($transform, vec3(-1,-2,-3))
		// depth = 1 / argument index = 1: transform.setTranslation($transform, vec3(-1,-2,-3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// argumentValues[1] --> returnValue of vec3(-1,-2,-3)
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(-1, -2, -3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(-1));
				argumentValues[1].setValue(static_cast<int64_t>(-2));
				argumentValues[2].setValue(static_cast<int64_t>(-3));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.setTranslation
			Transform transform;
			Vector3 translation;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, translation, false) == true) {
				transform.setTranslation(translation);
				transform.update();
				returnValue.setValue(transform);
			} else {
				Console::println("ScriptMethodTransformSetTranslation::executeMethod(): " + string("transform.setTranslation") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 117
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getScale(): ", transform.getScale($transform))
	{
		const ScriptStatement& statement = scripts[1].statements[117];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getScale(): "));
		// argumentValues[1] --> returnValue of transform.getScale($transform)
		// depth = 1 / argument index = 1: transform.getScale($transform)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.getScale
			Transform transform;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true) {
				returnValue.setValue(transform.getScale());
			} else {
				Console::println("ScriptMethodTransformGetScale::executeMethod(): " + string("transform.getScale") + "(): parameter type mismatch @ argument 0: transform expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 118
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setScale(): ", transform.setScale($transform, vec3(-2,-3,-4)))
	{
		const ScriptStatement& statement = scripts[1].statements[118];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setScale(): "));
		// argumentValues[1] --> returnValue of transform.setScale($transform, vec3(-2,-3,-4))
		// depth = 1 / argument index = 1: transform.setScale($transform, vec3(-2,-3,-4))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// argumentValues[1] --> returnValue of vec3(-2,-3,-4)
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(-2, -3, -4)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(-2));
				argumentValues[1].setValue(static_cast<int64_t>(-3));
				argumentValues[2].setValue(static_cast<int64_t>(-4));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.setScale
			Transform transform;
			Vector3 scale;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, scale, false) == true) {
				transform.setScale(scale);
				transform.update();
				returnValue.setValue(transform);
			} else {
				Console::println("ScriptMethodTransformSetScale::executeMethod(): " + string("transform.setScale") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 119
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAxis(): ", transform.getRotationAxis($transform, 0))
	{
		const ScriptStatement& statement = scripts[1].statements[119];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAxis(): "));
		// argumentValues[1] --> returnValue of transform.getRotationAxis($transform, 0)
		// depth = 1 / argument index = 1: transform.getRotationAxis($transform, 0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.getRotationAxis
			int64_t idx;
			Transform transform;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getIntegerValue(argumentValues, 1, idx, false) == true) {
				if (idx < transform.getRotationCount()) {
					returnValue.setValue(transform.getRotationAxis(idx));
				} else {
					Console::println("ScriptMethodTransformGetRotationAxis::executeMethod(): " + string("transform.getRotationAxis") + "(): rotation index invalid: " + to_string(idx) + " / " + to_string(transform.getRotationCount()));
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodTransformGetRotationAxis::executeMethod(): " + string("transform.getRotationAxis") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: integer expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 120
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAngle(): ", transform.getRotationAngle($transform, 0))
	{
		const ScriptStatement& statement = scripts[1].statements[120];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).getRotationAngle(): "));
		// argumentValues[1] --> returnValue of transform.getRotationAngle($transform, 0)
		// depth = 1 / argument index = 1: transform.getRotationAngle($transform, 0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.getRotationAngle
			int64_t idx;
			Transform transform;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getIntegerValue(argumentValues, 1, idx, false) == true) {
				if (idx < transform.getRotationCount()) {
					returnValue.setValue(transform.getRotationAngle(idx));
				} else {
					Console::println("ScriptMethodTransformGetRotationAngle::executeMethod(): " + string("transform.getRotationAngle") + "(): rotation index invalid: " + to_string(idx) + " / " + to_string(transform.getRotationCount()));
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodTransformGetRotationAngle::executeMethod(): " + string("transform.getRotationAngle") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: integer expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 121
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setRotationAngle(): ", transform.setRotationAngle($transform, 0, 90))
	{
		const ScriptStatement& statement = scripts[1].statements[121];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).setRotationAngle(): "));
		// argumentValues[1] --> returnValue of transform.setRotationAngle($transform, 0, 90)
		// depth = 1 / argument index = 1: transform.setRotationAngle($transform, 0, 90)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			argumentValues[2].setValue(static_cast<int64_t>(90));
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.setRotationAngle
			int64_t idx;
			Transform transform;
			float angle;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getIntegerValue(argumentValues, 1, idx, false) == true &&
				MiniScript::getFloatValue(argumentValues, 2, angle, false) == true) {
				if (idx < transform.getRotationCount()) {
					transform.setRotationAngle(idx, angle);
					transform.update();
					returnValue.setValue(transform);
				} else {
					Console::println("ScriptMethodTransformSetRotationAngle::executeMethod(): " + string("transform.setRotationAngle") + "(): rotation index invalid: " + to_string(idx) + " / " + to_string(transform.getRotationCount()));
					miniScript->startErrorScript(); return;
				}
			} else {
				Console::println("ScriptMethodTransformSetRotationAngle::executeMethod(): " + string("transform.setRotationAngle") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: integer expected, @ argument 2: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 122
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).multiply(vec3(0,0,0)): ", transform.multiply($transform, vec3(0,0,0)))
	{
		const ScriptStatement& statement = scripts[1].statements[122];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).multiply(vec3(0,0,0)): "));
		// argumentValues[1] --> returnValue of transform.multiply($transform, vec3(0,0,0))
		// depth = 1 / argument index = 1: transform.multiply($transform, vec3(0,0,0))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// argumentValues[1] --> returnValue of vec3(0,0,0)
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0, 0, 0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(0));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.multiply
			Transform transform;
			Vector3 vec3;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, vec3, false) == true) {
				returnValue.setValue(transform.getTransformMatrix() * vec3);
			} else {
				Console::println("ScriptMethodTransformSetScale::executeMethod(): " + string("transform.multiply") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 123
	// console.log("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).rotate(vec3(0,0,1)): ", transform.rotate($transform, vec3(0,0,1)))
	{
		const ScriptStatement& statement = scripts[1].statements[123];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("transform(vec3(1,2,3), vec3(2, 3, 4), vec3(0, 1, 0)).rotate(vec3(0,0,1)): "));
		// argumentValues[1] --> returnValue of transform.rotate($transform, vec3(0,0,1))
		// depth = 1 / argument index = 1: transform.rotate($transform, vec3(0,0,1))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$transform")
			// argumentValues[1] --> returnValue of vec3(0,0,1)
			// depth = 2 / argument index = 0: getVariable("$transform")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$transform"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: vec3(0, 0, 1)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(0));
				argumentValues[1].setValue(static_cast<int64_t>(0));
				argumentValues[2].setValue(static_cast<int64_t>(1));
				// method code: vec3
				Vector3 result;
				float xValue;
				float yValue;
				float zValue;
				if (MiniScript::getFloatValue(argumentValues, 0, xValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 1, yValue, false) == true &&
					MiniScript::getFloatValue(argumentValues, 2, zValue, false) == true) {
					returnValue.setValue(Vector3(xValue, yValue, zValue));
				} else {
					Console::println("ScriptMethodVec3::executeMethod(): " + string("vec3") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected, @ argument 2: float expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: transform.rotate
			Transform transform;
			Vector3 vec3;
			if (MiniScript::getTransformValue(argumentValues, 0, transform, false) == true &&
				MiniScript::getVector3Value(argumentValues, 1, vec3, false) == true) {
				returnValue.setValue(transform.getRotationsQuaternion() * vec3);
			} else {
				Console::println("ScriptMethodTransformSetScale::executeMethod(): " + string("transform.rotate") + "(): parameter type mismatch @ argument 0: transform expected, @ argument 1: vector3 expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 124
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[124];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 125
	// console.log("Check string functions")
	{
		const ScriptStatement& statement = scripts[1].statements[125];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check string functions"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 126
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[126];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 127
	// console.log(space(0), "1")
	{
		const ScriptStatement& statement = scripts[1].statements[127];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of space(0)
		argumentValues[1].setValue(string("1"));
		// depth = 1 / argument index = 0: space(0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(0));
			// method code: space
			int64_t spaces = 1;
			if (MiniScript::getIntegerValue(argumentValues, 0, spaces, true) == false) {
				Console::println("ScriptMethodSpace::executeMethod(): " + string("space") + "(): parameter type mismatch @ argument 0: integer expected");
				miniScript->startErrorScript(); return;
			} else {
				string spacesString;
				for (auto i = 0; i < spaces; i++) spacesString+= " ";
				returnValue.setValue(spacesString);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 128
	// console.log(space(2), "1.1")
	{
		const ScriptStatement& statement = scripts[1].statements[128];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of space(2)
		argumentValues[1].setValue(string("1.1"));
		// depth = 1 / argument index = 0: space(2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			// method code: space
			int64_t spaces = 1;
			if (MiniScript::getIntegerValue(argumentValues, 0, spaces, true) == false) {
				Console::println("ScriptMethodSpace::executeMethod(): " + string("space") + "(): parameter type mismatch @ argument 0: integer expected");
				miniScript->startErrorScript(); return;
			} else {
				string spacesString;
				for (auto i = 0; i < spaces; i++) spacesString+= " ";
				returnValue.setValue(spacesString);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 129
	// console.log(space(2), "1.2")
	{
		const ScriptStatement& statement = scripts[1].statements[129];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of space(2)
		argumentValues[1].setValue(string("1.2"));
		// depth = 1 / argument index = 0: space(2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(2));
			// method code: space
			int64_t spaces = 1;
			if (MiniScript::getIntegerValue(argumentValues, 0, spaces, true) == false) {
				Console::println("ScriptMethodSpace::executeMethod(): " + string("space") + "(): parameter type mismatch @ argument 0: integer expected");
				miniScript->startErrorScript(); return;
			} else {
				string spacesString;
				for (auto i = 0; i < spaces; i++) spacesString+= " ";
				returnValue.setValue(spacesString);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 130
	// console.log(toUpperCase("xxxyyyzzz"))
	{
		const ScriptStatement& statement = scripts[1].statements[130];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of toUpperCase("xxxyyyzzz")
		// depth = 1 / argument index = 0: toUpperCase("xxxyyyzzz")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("xxxyyyzzz"));
			// method code: toUpperCase
			string stringValue;
			if (MiniScript::getStringValue(argumentValues, 0, stringValue, false) == true) {
				returnValue.setValue(StringTools::toUpperCase(stringValue));
			} else {
				Console::println("ScriptMethodToUpperCase::executeMethod(): " + string("toUpperCase") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 131
	// console.log(toLowerCase("XXXYYYZZZ"))
	{
		const ScriptStatement& statement = scripts[1].statements[131];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of toLowerCase("XXXYYYZZZ")
		// depth = 1 / argument index = 0: toLowerCase("XXXYYYZZZ")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("XXXYYYZZZ"));
			// method code: toLowerCase
			string stringValue;
			if (MiniScript::getStringValue(argumentValues, 0, stringValue, false) == true) {
				returnValue.setValue(StringTools::toLowerCase(stringValue));
			} else {
				Console::println("ScriptMethodToLowerCase::executeMethod(): " + string("toLowerCase") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 132
	// console.log(concatenate("abc", "def", "ghi"))
	{
		const ScriptStatement& statement = scripts[1].statements[132];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of concatenate("abc", "def", "ghi")
		// depth = 1 / argument index = 0: concatenate("abc", "def", "ghi")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("abc"));
			argumentValues[1].setValue(string("def"));
			argumentValues[2].setValue(string("ghi"));
			// method code: concatenate
			string result;
			for (auto& argumentValue: argumentValues) {
				result+= argumentValue.getValueString();
			}
			returnValue.setValue(result);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 133
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[133];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 134
	// console.log("Check string functions (Operators)")
	{
		const ScriptStatement& statement = scripts[1].statements[134];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Check string functions (Operators)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 135
	// console.log(add("abc",add("def", "ghi")))
	{
		const ScriptStatement& statement = scripts[1].statements[135];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add("abc",add("def", "ghi"))
		// depth = 1 / argument index = 0: add("abc", add("def", "ghi"))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("abc"));
			// argumentValues[1] --> returnValue of add("def", "ghi")
			// depth = 2 / argument index = 1: add("def", "ghi")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string("def"));
				argumentValues[1].setValue(string("ghi"));
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 136
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[136];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 137
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[137];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 138
	// console.log("Variable")
	{
		const ScriptStatement& statement = scripts[1].statements[138];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Variable"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 139
	// console.log("------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[139];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 140
	// setVariable("$variable", string("1234"))
	{
		const ScriptStatement& statement = scripts[1].statements[140];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$variable"));
		// argumentValues[1] --> returnValue of string("1234")
		// depth = 1 / argument index = 1: string("1234")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("1234"));
			// method code: string
			string stringValue;
			if (MiniScript::getStringValue(argumentValues, 0, stringValue, false) == true) {
				returnValue.setValue(stringValue);
			} else {
				Console::println("ScriptMethodString::executeMethod(): " + string("string") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 141
	// console.log(getVariable("$variable"))
	{
		const ScriptStatement& statement = scripts[1].statements[141];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of getVariable("$variable")
		// depth = 1 / argument index = 0: getVariable("$variable")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("$variable"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 142
	// console.log("--------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[142];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("--------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 143
	// console.log("Lets check forTime")
	{
		const ScriptStatement& statement = scripts[1].statements[143];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Lets check forTime"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 144
	// console.log("--------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[144];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("--------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 145
	// setVariable("$i", 1)
	{
		const ScriptStatement& statement = scripts[1].statements[145];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(1));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 146
	miniscript_statement_146:
	// forTime(2000)
	{
		const ScriptStatement& statement = scripts[1].statements[146];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(static_cast<int64_t>(2000));
		// method code: forTime
		int64_t time;
		if (miniScript->getIntegerValue(argumentValues, 0, time) == false) {
			Console::println("ScriptMethodForTime::executeMethod(): " + string("forTime") + "(): parameter type mismatch @ argument 0: integer expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			auto timeWaitStarted = now;
			auto forTimeStartedIt = miniScript->scriptState.forTimeStarted.find(statement.line);
			if (forTimeStartedIt == miniScript->scriptState.forTimeStarted.end()) {
				miniScript->scriptState.forTimeStarted[statement.line] = timeWaitStarted;
			} else {
				timeWaitStarted = forTimeStartedIt->second;
			}
			//
			if (Time::getCurrentMillis() > timeWaitStarted + time) {
				miniScript->scriptState.forTimeStarted.erase(statement.line);
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_151;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 147
	miniscript_statement_147:
	// console.log($i, ": Hello World")
	{
		const ScriptStatement& statement = scripts[1].statements[147];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of getVariable("$i")
		argumentValues[1].setValue(string(": Hello World"));
		// depth = 1 / argument index = 0: getVariable("$i")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("$i"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 148
	// script.wait(500)
	{
		const ScriptStatement& statement = scripts[1].statements[148];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(static_cast<int64_t>(500));
		// method code: script.wait
		int64_t time;
		if (miniScript->getIntegerValue(argumentValues, 0, time) == true) {
			miniScript->scriptState.timeWaitStarted = Time::getCurrentMillis();
			miniScript->scriptState.timeWaitTime = time;
			miniScript->setScriptState(STATE_WAIT);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.wait") + "(): parameter type mismatch @ argument 0: integer expected");
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 149
	miniscript_statement_149:
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[149];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 150
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[150];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_146;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 151
	miniscript_statement_151:
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[151];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 152
	// console.log("Lets check forCondition")
	{
		const ScriptStatement& statement = scripts[1].statements[152];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Lets check forCondition"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 153
	// console.log("-------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[153];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 154
	// setVariable("$i", 1)
	{
		const ScriptStatement& statement = scripts[1].statements[154];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(1));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 155
	miniscript_statement_155:
	// forCondition(notequal($i, 6))
	{
		const ScriptStatement& statement = scripts[1].statements[155];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of notequal($i, 6)
		// depth = 1 / argument index = 0: notequal($i, 6)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(6));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: notequal
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() == argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_160;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 156
	miniscript_statement_156:
	// console.log($i, ": Hello World")
	{
		const ScriptStatement& statement = scripts[1].statements[156];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of getVariable("$i")
		argumentValues[1].setValue(string(": Hello World"));
		// depth = 1 / argument index = 0: getVariable("$i")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("$i"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 157
	// script.wait(500)
	{
		const ScriptStatement& statement = scripts[1].statements[157];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(static_cast<int64_t>(500));
		// method code: script.wait
		int64_t time;
		if (miniScript->getIntegerValue(argumentValues, 0, time) == true) {
			miniScript->scriptState.timeWaitStarted = Time::getCurrentMillis();
			miniScript->scriptState.timeWaitTime = time;
			miniScript->setScriptState(STATE_WAIT);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.wait") + "(): parameter type mismatch @ argument 0: integer expected");
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 158
	miniscript_statement_158:
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[158];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 159
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[159];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_155;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 160
	miniscript_statement_160:
	// console.log("i -> ", $i)
	{
		const ScriptStatement& statement = scripts[1].statements[160];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("i -> "));
		// argumentValues[1] --> returnValue of getVariable("$i")
		// depth = 1 / argument index = 1: getVariable("$i")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$i"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 161
	// console.log("---------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[161];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 162
	// console.log("Lets check forCondition with if/elseif/else")
	{
		const ScriptStatement& statement = scripts[1].statements[162];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Lets check forCondition with if/elseif/else"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 163
	// console.log("---------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[163];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 164
	// setVariable("$i", 1)
	{
		const ScriptStatement& statement = scripts[1].statements[164];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(1));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 165
	miniscript_statement_165:
	// forCondition(lesser($i, 5))
	{
		const ScriptStatement& statement = scripts[1].statements[165];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i, 5)
		// depth = 1 / argument index = 0: lesser($i, 5)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(5));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_180;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 166
	miniscript_statement_166:
	// console.log($i, ":")
	{
		const ScriptStatement& statement = scripts[1].statements[166];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of getVariable("$i")
		argumentValues[1].setValue(string(":"));
		// depth = 1 / argument index = 0: getVariable("$i")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("$i"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 167
	// if(equals($i, 0))
	{
		const ScriptStatement& statement = scripts[1].statements[167];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($i, 0)
		// depth = 1 / argument index = 0: equals($i, 0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: if
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodIfCondition::executeMethod(): " + string("if") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_IF);
			//
			miniScript->scriptState.conditionStack.push(booleanValue);
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_169;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 168
	miniscript_statement_168:
	// console.log("i -> 0")
	{
		const ScriptStatement& statement = scripts[1].statements[168];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("i -> 0"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 169
	miniscript_statement_169:
	// elseif(equals($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[169];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($i, 1)
		// depth = 1 / argument index = 0: equals($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: elseif
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): " + string("elseif") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else
		if (miniScript->scriptState.conditionStack.empty() == true) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): elseif without if");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto conditionStackElement = miniScript->scriptState.conditionStack.top();
			if (conditionStackElement == false) {
				miniScript->scriptState.conditionStack.pop();
				miniScript->scriptState.conditionStack.push(booleanValue);
			}
			if (conditionStackElement == true || booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_171;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 170
	miniscript_statement_170:
	// console.log("i -> 1")
	{
		const ScriptStatement& statement = scripts[1].statements[170];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("i -> 1"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 171
	miniscript_statement_171:
	// elseif(equals($i, 2))
	{
		const ScriptStatement& statement = scripts[1].statements[171];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($i, 2)
		// depth = 1 / argument index = 0: equals($i, 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: elseif
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): " + string("elseif") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else
		if (miniScript->scriptState.conditionStack.empty() == true) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): elseif without if");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto conditionStackElement = miniScript->scriptState.conditionStack.top();
			if (conditionStackElement == false) {
				miniScript->scriptState.conditionStack.pop();
				miniScript->scriptState.conditionStack.push(booleanValue);
			}
			if (conditionStackElement == true || booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_173;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 172
	miniscript_statement_172:
	// console.log("i -> 2")
	{
		const ScriptStatement& statement = scripts[1].statements[172];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("i -> 2"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 173
	miniscript_statement_173:
	// elseif(equals($i, 3))
	{
		const ScriptStatement& statement = scripts[1].statements[173];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($i, 3)
		// depth = 1 / argument index = 0: equals($i, 3)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(3));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: elseif
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): " + string("elseif") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else
		if (miniScript->scriptState.conditionStack.empty() == true) {
			Console::println("ScriptMethodElseIfCondition::executeMethod(): elseif without if");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto conditionStackElement = miniScript->scriptState.conditionStack.top();
			if (conditionStackElement == false) {
				miniScript->scriptState.conditionStack.pop();
				miniScript->scriptState.conditionStack.push(booleanValue);
			}
			if (conditionStackElement == true || booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_175;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 174
	miniscript_statement_174:
	// console.log("i -> 3")
	{
		const ScriptStatement& statement = scripts[1].statements[174];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("i -> 3"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 175
	miniscript_statement_175:
	// else()
	{
		const ScriptStatement& statement = scripts[1].statements[175];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: else
		if (miniScript->scriptState.conditionStack.empty() == true) {
			Console::println("ScriptMethodElse::executeMethod(): else without if");
			miniScript->startErrorScript(); return;
		} else {
			auto conditionStackElement = miniScript->scriptState.conditionStack.top();
			if (conditionStackElement == true) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_177;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 176
	miniscript_statement_176:
	// console.log("else: ", $i)
	{
		const ScriptStatement& statement = scripts[1].statements[176];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("else: "));
		// argumentValues[1] --> returnValue of getVariable("$i")
		// depth = 1 / argument index = 1: getVariable("$i")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$i"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 177
	miniscript_statement_177:
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[177];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 178
	miniscript_statement_178:
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[178];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 179
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[179];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_165;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 180
	miniscript_statement_180:
	// setVariable("$i", 1)
	{
		const ScriptStatement& statement = scripts[1].statements[180];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(1));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 181
	// setVariable("$j", 2)
	{
		const ScriptStatement& statement = scripts[1].statements[181];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$j"));
		argumentValues[1].setValue(static_cast<int64_t>(2));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 182
	// setVariable("$k", 3)
	{
		const ScriptStatement& statement = scripts[1].statements[182];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$k"));
		argumentValues[1].setValue(static_cast<int64_t>(3));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 183
	// if(or(equals(getVariable("$i"), $j),equals(getVariable("$i"), $k)))
	{
		const ScriptStatement& statement = scripts[1].statements[183];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of or(equals(getVariable("$i"), $j),equals(getVariable("$i"), $k))
		// depth = 1 / argument index = 0: or(equals(getVariable("$i"), $j), equals(getVariable("$i"), $k))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of equals(getVariable("$i"), $j)
			// argumentValues[1] --> returnValue of equals(getVariable("$i"), $k)
			// depth = 2 / argument index = 0: equals(getVariable("$i"), $j)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$i")
				// argumentValues[1] --> returnValue of getVariable("$j")
				// depth = 3 / argument index = 0: getVariable("$i")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$i"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// depth = 3 / argument index = 1: getVariable("$j")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$j"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: equals
				returnValue.setValue(true);
				for (auto i = 1; i < argumentValues.size(); i++) {
					if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
						returnValue.setValue(false);
						break;
					}
				}
			}
			// depth = 2 / argument index = 1: equals(getVariable("$i"), $k)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$i")
				// argumentValues[1] --> returnValue of getVariable("$k")
				// depth = 3 / argument index = 0: getVariable("$i")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$i"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// depth = 3 / argument index = 1: getVariable("$k")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$k"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: equals
				returnValue.setValue(true);
				for (auto i = 1; i < argumentValues.size(); i++) {
					if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
						returnValue.setValue(false);
						break;
					}
				}
			}
			// method code: or
			returnValue.setValue(false);
			for (auto i = 0; i < argumentValues.size(); i++) {
				bool booleanValue;
				if (MiniScript::getBooleanValue(argumentValues, i, booleanValue, false) == false) {
					Console::println("ScriptMethodOr::executeMethod(): " + string("or") + "(): parameter type mismatch @ argument " + to_string(i) + ": boolean expected");
					miniScript->startErrorScript(); return;
				} else
				if (booleanValue == true) {
					returnValue.setValue(true);
					break;
				}
			}
		}
		// method code: if
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodIfCondition::executeMethod(): " + string("if") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_IF);
			//
			miniScript->scriptState.conditionStack.push(booleanValue);
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_185;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 184
	miniscript_statement_184:
	// console.log("This should not happen, but look ok in preprocessor processed output")
	{
		const ScriptStatement& statement = scripts[1].statements[184];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("This should not happen, but look ok in preprocessor processed output"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 185
	miniscript_statement_185:
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[185];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 186
	miniscript_statement_186:
	// console.log("-------------------------------------------------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[186];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------------------------------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 187
	// console.log(add("Test: string concatenation with brackets in string literals: ",add($i,add("(",add($j, ")")))))
	{
		const ScriptStatement& statement = scripts[1].statements[187];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add("Test: string concatenation with brackets in string literals: ",add($i,add("(",add($j, ")"))))
		// depth = 1 / argument index = 0: add("Test: string concatenation with brackets in string literals: ", add($i,add("(",add($j, ")"))))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("Test: string concatenation with brackets in string literals: "));
			// argumentValues[1] --> returnValue of add($i,add("(",add($j, ")")))
			// depth = 2 / argument index = 1: add($i, add("(",add($j, ")")))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$i")
				// argumentValues[1] --> returnValue of add("(",add($j, ")"))
				// depth = 3 / argument index = 0: getVariable("$i")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$i"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// depth = 3 / argument index = 1: add("(", add($j, ")"))
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("("));
					// argumentValues[1] --> returnValue of add($j, ")")
					// depth = 4 / argument index = 1: add($j, ")")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[1];
						array<ScriptVariable, 2> argumentValues;
						array<ScriptVariable, 2>& argumentValuesD4AIDX1 = argumentValues;
						// argumentValues[0] --> returnValue of getVariable("$j")
						argumentValues[1].setValue(string(")"));
						// depth = 5 / argument index = 0: getVariable("$j")
						{
							// required method code arguments
							ScriptVariable& returnValue = argumentValuesD4AIDX1[0];
							array<ScriptVariable, 1> argumentValues;
							array<ScriptVariable, 1>& argumentValuesD5AIDX0 = argumentValues;
							argumentValues[0].setValue(string("$j"));
							// method code: getVariable
							string variable;
							if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
								returnValue = miniScript->getVariable(variable);
							} else {
								Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
								miniScript->startErrorScript(); return;
							}
						}
						// method code: add
						MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
					}
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 188
	// console.log("-------------------------------------------------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[188];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-------------------------------------------------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 189
	// console.log("(4.0 + 2.0) / 2.0 + (20.0 / 10.0 * (2.0 + 5)): ", add(div(add(4.0, 2.0), 2.0),mul(div(20.0, 10.0), add(2.0, 5))), " = 17")
	{
		const ScriptStatement& statement = scripts[1].statements[189];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 3> argumentValues;
		array<ScriptVariable, 3>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("(4.0 + 2.0) / 2.0 + (20.0 / 10.0 * (2.0 + 5)): "));
		// argumentValues[1] --> returnValue of add(div(add(4.0, 2.0), 2.0),mul(div(20.0, 10.0), add(2.0, 5)))
		argumentValues[2].setValue(string(" = 17"));
		// depth = 1 / argument index = 1: add(div(add(4.0, 2.0), 2.0), mul(div(20.0, 10.0), add(2.0, 5)))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of div(add(4.0, 2.0), 2.0)
			// argumentValues[1] --> returnValue of mul(div(20.0, 10.0), add(2.0, 5))
			// depth = 2 / argument index = 0: div(add(4.0, 2.0), 2.0)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				// argumentValues[0] --> returnValue of add(4.0, 2.0)
				argumentValues[1].setValue(2.000000f);
				// depth = 3 / argument index = 0: add(4.0, 2.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[0];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(4.000000f);
					argumentValues[1].setValue(2.000000f);
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: div
				MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
			}
			// depth = 2 / argument index = 1: mul(div(20.0, 10.0), add(2.0, 5))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of div(20.0, 10.0)
				// argumentValues[1] --> returnValue of add(2.0, 5)
				// depth = 3 / argument index = 0: div(20.0, 10.0)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(20.000000f);
					argumentValues[1].setValue(10.000000f);
					// method code: div
					MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
				}
				// depth = 3 / argument index = 1: add(2.0, 5)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(2.000000f);
					argumentValues[1].setValue(static_cast<int64_t>(5));
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: mul
				MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 190
	// console.log("---------")
	{
		const ScriptStatement& statement = scripts[1].statements[190];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 191
	// console.log("Arrays")
	{
		const ScriptStatement& statement = scripts[1].statements[191];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Arrays"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 192
	// console.log("----------")
	{
		const ScriptStatement& statement = scripts[1].statements[192];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 193
	// setVariable("$array", array(1,2,3))
	{
		const ScriptStatement& statement = scripts[1].statements[193];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array"));
		// argumentValues[1] --> returnValue of array(1,2,3)
		// depth = 1 / argument index = 1: array(1, 2, 3)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(1));
			argumentValues[1].setValue(static_cast<int64_t>(2));
			argumentValues[2].setValue(static_cast<int64_t>(3));
			// method code: array
			returnValue.setType(MiniScript::TYPE_ARRAY);
			for (auto& argumentValue: argumentValues) {
				returnValue.pushArrayValue(argumentValue);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 194
	// console.log("array initialized with: $array = array(1,2,3)")
	{
		const ScriptStatement& statement = scripts[1].statements[194];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array initialized with: $array = array(1,2,3)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 195
	// console.log("array now looks like: ", $array)
	{
		const ScriptStatement& statement = scripts[1].statements[195];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$array")
		// depth = 1 / argument index = 1: getVariable("$array")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$array"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 196
	// setVariable("$array", array.push($array, 8, 9, 10, 99, 10))
	{
		const ScriptStatement& statement = scripts[1].statements[196];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array"));
		// argumentValues[1] --> returnValue of array.push($array, 8, 9, 10, 99, 10)
		// depth = 1 / argument index = 1: array.push($array, 8, 9, 10, 99, 10)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 6> argumentValues;
			array<ScriptVariable, 6>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(8));
			argumentValues[2].setValue(static_cast<int64_t>(9));
			argumentValues[3].setValue(static_cast<int64_t>(10));
			argumentValues[4].setValue(static_cast<int64_t>(99));
			argumentValues[5].setValue(static_cast<int64_t>(10));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.push
			//
			if (argumentValues.size() < 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
				Console::println("ScriptMethodArrayPush::executeMethod(): " + string("array.push") + "(): parameter type mismatch @ argument 0: array expected");
			} else {
				returnValue = argumentValues[0];
				for (auto i = 1; i < argumentValues.size(); i++) {
					returnValue.pushArrayValue(argumentValues[i]);
				}
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 197
	// console.log("array pushed values with: array.push($array, 8, 9, 10, 99, 10)")
	{
		const ScriptStatement& statement = scripts[1].statements[197];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array pushed values with: array.push($array, 8, 9, 10, 99, 10)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 198
	// console.log("array now looks like: ", $array)
	{
		const ScriptStatement& statement = scripts[1].statements[198];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$array")
		// depth = 1 / argument index = 1: getVariable("$array")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$array"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 199
	// setVariable("$array[]", 123)
	{
		const ScriptStatement& statement = scripts[1].statements[199];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[]"));
		argumentValues[1].setValue(static_cast<int64_t>(123));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 200
	// setVariable("$array[]", 1234)
	{
		const ScriptStatement& statement = scripts[1].statements[200];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[]"));
		argumentValues[1].setValue(static_cast<int64_t>(1234));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 201
	// setVariable("$array[]", 12345)
	{
		const ScriptStatement& statement = scripts[1].statements[201];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[]"));
		argumentValues[1].setValue(static_cast<int64_t>(12345));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 202
	// setVariable("$array[]", array(1,2,3))
	{
		const ScriptStatement& statement = scripts[1].statements[202];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[]"));
		// argumentValues[1] --> returnValue of array(1,2,3)
		// depth = 1 / argument index = 1: array(1, 2, 3)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(static_cast<int64_t>(1));
			argumentValues[1].setValue(static_cast<int64_t>(2));
			argumentValues[2].setValue(static_cast<int64_t>(3));
			// method code: array
			returnValue.setType(MiniScript::TYPE_ARRAY);
			for (auto& argumentValue: argumentValues) {
				returnValue.pushArrayValue(argumentValue);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 203
	// console.log("array values added with [] operator: 123, 1234, 12345, array(1,2,3)")
	{
		const ScriptStatement& statement = scripts[1].statements[203];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array values added with [] operator: 123, 1234, 12345, array(1,2,3)"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 204
	// console.log("array now looks like: ", $array)
	{
		const ScriptStatement& statement = scripts[1].statements[204];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$array")
		// depth = 1 / argument index = 1: getVariable("$array")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$array"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 205
	// console.log("array values added with [] operator to push to array of array: 50, 60")
	{
		const ScriptStatement& statement = scripts[1].statements[205];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array values added with [] operator to push to array of array: 50, 60"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 206
	// setVariable("$array[11][]", 50)
	{
		const ScriptStatement& statement = scripts[1].statements[206];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[11][]"));
		argumentValues[1].setValue(static_cast<int64_t>(50));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 207
	// setVariable("$array[11][]", 60)
	{
		const ScriptStatement& statement = scripts[1].statements[207];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[11][]"));
		argumentValues[1].setValue(static_cast<int64_t>(60));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 208
	// setVariable("$array[11][sub(array.length($array[11]), 1)]", 61)
	{
		const ScriptStatement& statement = scripts[1].statements[208];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array[11][sub(array.length($array[11]), 1)]"));
		argumentValues[1].setValue(static_cast<int64_t>(61));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 209
	// console.log("array length: ", array.length($array))
	{
		const ScriptStatement& statement = scripts[1].statements[209];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array length: "));
		// argumentValues[1] --> returnValue of array.length($array)
		// depth = 1 / argument index = 1: array.length($array)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.length
			if (argumentValues.size() != 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
				Console::println("ScriptMethodArrayLength::executeMethod(): " + string("array.length") + "(): parameter type mismatch @ argument 0: array expected");
			} else {
				returnValue.setValue(static_cast<int64_t>(argumentValues[0].getArraySize()));
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 210
	// console.log("array iteration with array.get(): ")
	{
		const ScriptStatement& statement = scripts[1].statements[210];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array iteration with array.get(): "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 211
	// setVariable("$i", 0)
	{
		const ScriptStatement& statement = scripts[1].statements[211];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 212
	miniscript_statement_212:
	// forCondition(lesser($i, array.length($array)))
	{
		const ScriptStatement& statement = scripts[1].statements[212];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i, array.length($array))
		// depth = 1 / argument index = 0: lesser($i, array.length($array))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of array.length($array)
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: array.length($array)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$array")
				// depth = 3 / argument index = 0: getVariable("$array")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$array"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: array.length
				if (argumentValues.size() != 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
					Console::println("ScriptMethodArrayLength::executeMethod(): " + string("array.length") + "(): parameter type mismatch @ argument 0: array expected");
				} else {
					returnValue.setValue(static_cast<int64_t>(argumentValues[0].getArraySize()));
				}
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_216;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 213
	miniscript_statement_213:
	// console.log(add($i,add(": ", array.get($array, $i))))
	{
		const ScriptStatement& statement = scripts[1].statements[213];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add($i,add(": ", array.get($array, $i)))
		// depth = 1 / argument index = 0: add($i, add(": ", array.get($array, $i)))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of add(": ", array.get($array, $i))
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: add(": ", array.get($array, $i))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string(": "));
				// argumentValues[1] --> returnValue of array.get($array, $i)
				// depth = 3 / argument index = 1: array.get($array, $i)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					// argumentValues[0] --> returnValue of getVariable("$array")
					// argumentValues[1] --> returnValue of getVariable("$i")
					// depth = 4 / argument index = 0: getVariable("$array")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[0];
						array<ScriptVariable, 1> argumentValues;
						array<ScriptVariable, 1>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(string("$array"));
						// method code: getVariable
						string variable;
						if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
							returnValue = miniScript->getVariable(variable);
						} else {
							Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
							miniScript->startErrorScript(); return;
						}
					}
					// depth = 4 / argument index = 1: getVariable("$i")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[1];
						array<ScriptVariable, 1> argumentValues;
						array<ScriptVariable, 1>& argumentValuesD4AIDX1 = argumentValues;
						argumentValues[0].setValue(string("$i"));
						// method code: getVariable
						string variable;
						if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
							returnValue = miniScript->getVariable(variable);
						} else {
							Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
							miniScript->startErrorScript(); return;
						}
					}
					// method code: array.get
					int64_t index;
					if ((argumentValues.size() <= 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) ||
						MiniScript::getIntegerValue(argumentValues, 1, index, false) == false) {
						Console::println("ScriptMethodArrayGet::executeMethod(): " + string("array.get") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: integer expected");
					} else {
						returnValue = argumentValues[0].getArrayValue(index);
					}
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 214
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[214];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 215
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[215];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_212;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 216
	miniscript_statement_216:
	// console.log("array iteration with [] operator: ")
	{
		const ScriptStatement& statement = scripts[1].statements[216];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array iteration with [] operator: "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 217
	// setVariable("$i", 0)
	{
		const ScriptStatement& statement = scripts[1].statements[217];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 218
	miniscript_statement_218:
	// forCondition(lesser($i, array.length($array)))
	{
		const ScriptStatement& statement = scripts[1].statements[218];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i, array.length($array))
		// depth = 1 / argument index = 0: lesser($i, array.length($array))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of array.length($array)
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: array.length($array)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$array")
				// depth = 3 / argument index = 0: getVariable("$array")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$array"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: array.length
				if (argumentValues.size() != 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
					Console::println("ScriptMethodArrayLength::executeMethod(): " + string("array.length") + "(): parameter type mismatch @ argument 0: array expected");
				} else {
					returnValue.setValue(static_cast<int64_t>(argumentValues[0].getArraySize()));
				}
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_222;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 219
	miniscript_statement_219:
	// console.log(add($i,add(": ", $array[$i])))
	{
		const ScriptStatement& statement = scripts[1].statements[219];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add($i,add(": ", $array[$i]))
		// depth = 1 / argument index = 0: add($i, add(": ", $array[$i]))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of add(": ", $array[$i])
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: add(": ", $array[$i])
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string(": "));
				// argumentValues[1] --> returnValue of getVariable("$array[$i]")
				// depth = 3 / argument index = 1: getVariable("$array[$i]")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$array[$i]"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 220
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[220];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 221
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[221];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_218;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 222
	miniscript_statement_222:
	// console.log("array iteration with [] opertator and some index math: ")
	{
		const ScriptStatement& statement = scripts[1].statements[222];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array iteration with [] opertator and some index math: "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 223
	// setVariable("$i", 0)
	{
		const ScriptStatement& statement = scripts[1].statements[223];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 224
	miniscript_statement_224:
	// forCondition(lesser($i,div(array.length($array), 2)))
	{
		const ScriptStatement& statement = scripts[1].statements[224];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i,div(array.length($array), 2))
		// depth = 1 / argument index = 0: lesser($i, div(array.length($array), 2))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of div(array.length($array), 2)
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: div(array.length($array), 2)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of array.length($array)
				argumentValues[1].setValue(static_cast<int64_t>(2));
				// depth = 3 / argument index = 0: array.length($array)
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					// argumentValues[0] --> returnValue of getVariable("$array")
					// depth = 4 / argument index = 0: getVariable("$array")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX0[0];
						array<ScriptVariable, 1> argumentValues;
						array<ScriptVariable, 1>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(string("$array"));
						// method code: getVariable
						string variable;
						if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
							returnValue = miniScript->getVariable(variable);
						} else {
							Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
							miniScript->startErrorScript(); return;
						}
					}
					// method code: array.length
					if (argumentValues.size() != 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
						Console::println("ScriptMethodArrayLength::executeMethod(): " + string("array.length") + "(): parameter type mismatch @ argument 0: array expected");
					} else {
						returnValue.setValue(static_cast<int64_t>(argumentValues[0].getArraySize()));
					}
				}
				// method code: div
				MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_229;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 225
	miniscript_statement_225:
	// console.log(add($i,add("-a: ", $array[add(mul($i, 2), 0)])))
	{
		const ScriptStatement& statement = scripts[1].statements[225];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add($i,add("-a: ", $array[add(mul($i, 2), 0)]))
		// depth = 1 / argument index = 0: add($i, add("-a: ", $array[add(mul($i, 2), 0)]))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of add("-a: ", $array[add(mul($i, 2), 0)])
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: add("-a: ", $array[add(mul($i, 2), 0)])
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string("-a: "));
				// argumentValues[1] --> returnValue of getVariable("$array[add(mul($i, 2), 0)]")
				// depth = 3 / argument index = 1: getVariable("$array[add(mul($i, 2), 0)]")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$array[add(mul($i, 2), 0)]"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 226
	// console.log(add($i,add("-b: ", $array[add(mul($i, 2), 1)])))
	{
		const ScriptStatement& statement = scripts[1].statements[226];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add($i,add("-b: ", $array[add(mul($i, 2), 1)]))
		// depth = 1 / argument index = 0: add($i, add("-b: ", $array[add(mul($i, 2), 1)]))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of add("-b: ", $array[add(mul($i, 2), 1)])
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: add("-b: ", $array[add(mul($i, 2), 1)])
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string("-b: "));
				// argumentValues[1] --> returnValue of getVariable("$array[add(mul($i, 2), 1)]")
				// depth = 3 / argument index = 1: getVariable("$array[add(mul($i, 2), 1)]")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$array[add(mul($i, 2), 1)]"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 227
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[227];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 228
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[228];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_224;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 229
	miniscript_statement_229:
	// console.log("array removal of 123, 1234, 12345 using array.removeOf")
	{
		const ScriptStatement& statement = scripts[1].statements[229];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array removal of 123, 1234, 12345 using array.removeOf"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 230
	// setVariable("$array", array.removeOf($array, 123))
	{
		const ScriptStatement& statement = scripts[1].statements[230];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array"));
		// argumentValues[1] --> returnValue of array.removeOf($array, 123)
		// depth = 1 / argument index = 1: array.removeOf($array, 123)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(123));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.removeOf
			string stringValue;
			int64_t index;
			if (argumentValues.size() != 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY ||
				MiniScript::getStringValue(argumentValues, 1, stringValue, false) == false) {
				Console::println("ScriptMethodArraySet::executeMethod(): " + string("array.removeOf") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: mixed expected");
			} else {
				auto& array = argumentValues[0];
				returnValue.setType(ScriptVariableType::TYPE_ARRAY);
				for (auto i = 0; i < array.getArraySize(); i++) {
					auto arrayValue = array.getArrayValue(i);
					if (arrayValue.getValueString() == stringValue) continue;
					returnValue.pushArrayValue(arrayValue);
				}
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 231
	// setVariable("$array", array.removeOf($array, 1234))
	{
		const ScriptStatement& statement = scripts[1].statements[231];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array"));
		// argumentValues[1] --> returnValue of array.removeOf($array, 1234)
		// depth = 1 / argument index = 1: array.removeOf($array, 1234)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(1234));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.removeOf
			string stringValue;
			int64_t index;
			if (argumentValues.size() != 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY ||
				MiniScript::getStringValue(argumentValues, 1, stringValue, false) == false) {
				Console::println("ScriptMethodArraySet::executeMethod(): " + string("array.removeOf") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: mixed expected");
			} else {
				auto& array = argumentValues[0];
				returnValue.setType(ScriptVariableType::TYPE_ARRAY);
				for (auto i = 0; i < array.getArraySize(); i++) {
					auto arrayValue = array.getArrayValue(i);
					if (arrayValue.getValueString() == stringValue) continue;
					returnValue.pushArrayValue(arrayValue);
				}
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 232
	// setVariable("$array", array.removeOf($array, 12345))
	{
		const ScriptStatement& statement = scripts[1].statements[232];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$array"));
		// argumentValues[1] --> returnValue of array.removeOf($array, 12345)
		// depth = 1 / argument index = 1: array.removeOf($array, 12345)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(12345));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.removeOf
			string stringValue;
			int64_t index;
			if (argumentValues.size() != 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY ||
				MiniScript::getStringValue(argumentValues, 1, stringValue, false) == false) {
				Console::println("ScriptMethodArraySet::executeMethod(): " + string("array.removeOf") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: mixed expected");
			} else {
				auto& array = argumentValues[0];
				returnValue.setType(ScriptVariableType::TYPE_ARRAY);
				for (auto i = 0; i < array.getArraySize(); i++) {
					auto arrayValue = array.getArrayValue(i);
					if (arrayValue.getValueString() == stringValue) continue;
					returnValue.pushArrayValue(arrayValue);
				}
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 233
	// console.log("array now looks like: ", $array)
	{
		const ScriptStatement& statement = scripts[1].statements[233];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$array")
		// depth = 1 / argument index = 1: getVariable("$array")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$array"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 234
	// console.log("array indexOf 10: ", array.indexOf($array, 10))
	{
		const ScriptStatement& statement = scripts[1].statements[234];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array indexOf 10: "));
		// argumentValues[1] --> returnValue of array.indexOf($array, 10)
		// depth = 1 / argument index = 1: array.indexOf($array, 10)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(10));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.indexOf
			string stringValue;
			int64_t beginIndex = 0;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY ||
				MiniScript::getStringValue(argumentValues, 1, stringValue, false) == false ||
				MiniScript::getIntegerValue(argumentValues, 2, beginIndex, true) == false) {
				Console::println("ScriptMethodArraySet::executeMethod(): " + string("array.indexOf") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: mixed expected");
			} else {
				auto& array = argumentValues[0];
				returnValue.setValue(static_cast<int64_t>(-1));
				for (auto i = beginIndex; i < array.getArraySize(); i++) {
					auto arrayValue = array.getArrayValue(i);
					if (arrayValue.getValueString() == stringValue) {
						returnValue.setValue(static_cast<int64_t>(i));
						break;
					}
				}
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 235
	// console.log("array indexOf 10 beginning to search from 6: ", array.indexOf($array, 10, 6))
	{
		const ScriptStatement& statement = scripts[1].statements[235];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("array indexOf 10 beginning to search from 6: "));
		// argumentValues[1] --> returnValue of array.indexOf($array, 10, 6)
		// depth = 1 / argument index = 1: array.indexOf($array, 10, 6)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$array")
			argumentValues[1].setValue(static_cast<int64_t>(10));
			argumentValues[2].setValue(static_cast<int64_t>(6));
			// depth = 2 / argument index = 0: getVariable("$array")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$array"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: array.indexOf
			string stringValue;
			int64_t beginIndex = 0;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY ||
				MiniScript::getStringValue(argumentValues, 1, stringValue, false) == false ||
				MiniScript::getIntegerValue(argumentValues, 2, beginIndex, true) == false) {
				Console::println("ScriptMethodArraySet::executeMethod(): " + string("array.indexOf") + "(): parameter type mismatch @ argument 0: array expected, @argument 1: mixed expected");
			} else {
				auto& array = argumentValues[0];
				returnValue.setValue(static_cast<int64_t>(-1));
				for (auto i = beginIndex; i < array.getArraySize(); i++) {
					auto arrayValue = array.getArrayValue(i);
					if (arrayValue.getValueString() == stringValue) {
						returnValue.setValue(static_cast<int64_t>(i));
						break;
					}
				}
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 236
	// console.log("---------")
	{
		const ScriptStatement& statement = scripts[1].statements[236];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 237
	// console.log("Maps")
	{
		const ScriptStatement& statement = scripts[1].statements[237];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Maps"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 238
	// console.log("----------")
	{
		const ScriptStatement& statement = scripts[1].statements[238];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 239
	// setVariable("$map", map())
	{
		const ScriptStatement& statement = scripts[1].statements[239];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map()
		// depth = 1 / argument index = 1: map()
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 0> argumentValues;
			array<ScriptVariable, 0>& argumentValuesD1AIDX1 = argumentValues;
			// method code: map
			returnValue.setType(MiniScript::TYPE_MAP);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 240
	// console.log("map initialized with: $map = map()")
	{
		const ScriptStatement& statement = scripts[1].statements[240];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map initialized with: $map = map()"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 241
	// console.log("map now looks like: ", $map)
	{
		const ScriptStatement& statement = scripts[1].statements[241];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$map")
		// depth = 1 / argument index = 1: getVariable("$map")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 242
	// console.log("put some key value pairs into map: $map = map.set()")
	{
		const ScriptStatement& statement = scripts[1].statements[242];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("put some key value pairs into map: $map = map.set()"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 243
	// setVariable("$map", map.set($map, "test1", 123))
	{
		const ScriptStatement& statement = scripts[1].statements[243];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test1", 123)
		// depth = 1 / argument index = 1: map.set($map, "test1", 123)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test1"));
			argumentValues[2].setValue(static_cast<int64_t>(123));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 244
	// setVariable("$map", map.set($map, "test2", 456))
	{
		const ScriptStatement& statement = scripts[1].statements[244];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test2", 456)
		// depth = 1 / argument index = 1: map.set($map, "test2", 456)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test2"));
			argumentValues[2].setValue(static_cast<int64_t>(456));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 245
	// setVariable("$map", map.set($map, "test3", 789))
	{
		const ScriptStatement& statement = scripts[1].statements[245];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test3", 789)
		// depth = 1 / argument index = 1: map.set($map, "test3", 789)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test3"));
			argumentValues[2].setValue(static_cast<int64_t>(789));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 246
	// setVariable("$map", map.set($map, "test4", array(1,2,3)))
	{
		const ScriptStatement& statement = scripts[1].statements[246];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test4", array(1,2,3))
		// depth = 1 / argument index = 1: map.set($map, "test4", array(1,2,3))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test4"));
			// argumentValues[2] --> returnValue of array(1,2,3)
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 2: array(1, 2, 3)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[2];
				array<ScriptVariable, 3> argumentValues;
				array<ScriptVariable, 3>& argumentValuesD2AIDX2 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(1));
				argumentValues[1].setValue(static_cast<int64_t>(2));
				argumentValues[2].setValue(static_cast<int64_t>(3));
				// method code: array
				returnValue.setType(MiniScript::TYPE_ARRAY);
				for (auto& argumentValue: argumentValues) {
					returnValue.pushArrayValue(argumentValue);
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 247
	// setVariable("$map", map.set($map, "test5", "Yaaaa"))
	{
		const ScriptStatement& statement = scripts[1].statements[247];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test5", "Yaaaa")
		// depth = 1 / argument index = 1: map.set($map, "test5", "Yaaaa")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test5"));
			argumentValues[2].setValue(string("Yaaaa"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 248
	// console.log("map now looks like: ", $map)
	{
		const ScriptStatement& statement = scripts[1].statements[248];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$map")
		// depth = 1 / argument index = 1: getVariable("$map")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 249
	// console.log("remove test2 via map.remove: ")
	{
		const ScriptStatement& statement = scripts[1].statements[249];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("remove test2 via map.remove: "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 250
	// setVariable("$map", map.remove($map, "test2"))
	{
		const ScriptStatement& statement = scripts[1].statements[250];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.remove($map, "test2")
		// depth = 1 / argument index = 1: map.remove($map, "test2")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test2"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.remove
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapHas::executeMethod(): " + string("map.remove") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0];
				returnValue.removeMapValue(key);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 251
	// console.log("map now looks like: ", $map)
	{
		const ScriptStatement& statement = scripts[1].statements[251];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map now looks like: "));
		// argumentValues[1] --> returnValue of getVariable("$map")
		// depth = 1 / argument index = 1: getVariable("$map")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 252
	// setVariable("$map", map.set($map, "test2", 456))
	{
		const ScriptStatement& statement = scripts[1].statements[252];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map"));
		// argumentValues[1] --> returnValue of map.set($map, "test2", 456)
		// depth = 1 / argument index = 1: map.set($map, "test2", 456)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 3> argumentValues;
			array<ScriptVariable, 3>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test2"));
			argumentValues[2].setValue(static_cast<int64_t>(456));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.set
			//
			string key;
			if (argumentValues.size() < 3 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapSet::executeMethod(): " + string("map.set") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string, @ argument 2: mixed expected");
			} else {
				returnValue = argumentValues[0];
				returnValue.setMapValue(key, argumentValues[2]);
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 253
	// console.log("readding test2: ")
	{
		const ScriptStatement& statement = scripts[1].statements[253];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("readding test2: "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 254
	// console.log("map does have test2 key using map.has(): ", map.has($map, "test2"))
	{
		const ScriptStatement& statement = scripts[1].statements[254];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map does have test2 key using map.has(): "));
		// argumentValues[1] --> returnValue of map.has($map, "test2")
		// depth = 1 / argument index = 1: map.has($map, "test2")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test2"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.has
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapHas::executeMethod(): " + string("map.has") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue.setValue(argumentValues[0].hasMapValue(key));
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 255
	// console.log("map does have test8 key using map.has(): ", map.has($map, "test8"))
	{
		const ScriptStatement& statement = scripts[1].statements[255];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map does have test8 key using map.has(): "));
		// argumentValues[1] --> returnValue of map.has($map, "test8")
		// depth = 1 / argument index = 1: map.has($map, "test8")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test8"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.has
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapHas::executeMethod(): " + string("map.has") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue.setValue(argumentValues[0].hasMapValue(key));
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 256
	// console.log("map value for test1 key using map.get(): ", map.get($map, "test1"))
	{
		const ScriptStatement& statement = scripts[1].statements[256];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test1 key using map.get(): "));
		// argumentValues[1] --> returnValue of map.get($map, "test1")
		// depth = 1 / argument index = 1: map.get($map, "test1")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test1"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.get
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0].getMapValue(key);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 257
	// console.log("map value for test2 key using map.get(): ", map.get($map, "test2"))
	{
		const ScriptStatement& statement = scripts[1].statements[257];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test2 key using map.get(): "));
		// argumentValues[1] --> returnValue of map.get($map, "test2")
		// depth = 1 / argument index = 1: map.get($map, "test2")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test2"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.get
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0].getMapValue(key);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 258
	// console.log("map value for test3 key using map.get(): ", map.get($map, "test3"))
	{
		const ScriptStatement& statement = scripts[1].statements[258];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test3 key using map.get(): "));
		// argumentValues[1] --> returnValue of map.get($map, "test3")
		// depth = 1 / argument index = 1: map.get($map, "test3")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test3"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.get
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0].getMapValue(key);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 259
	// console.log("map value for test4 key using map.get(): ", map.get($map, "test4"))
	{
		const ScriptStatement& statement = scripts[1].statements[259];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test4 key using map.get(): "));
		// argumentValues[1] --> returnValue of map.get($map, "test4")
		// depth = 1 / argument index = 1: map.get($map, "test4")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test4"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.get
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0].getMapValue(key);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 260
	// console.log("map value for test5 key using map.get(): ", map.get($map, "test5"))
	{
		const ScriptStatement& statement = scripts[1].statements[260];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test5 key using map.get(): "));
		// argumentValues[1] --> returnValue of map.get($map, "test5")
		// depth = 1 / argument index = 1: map.get($map, "test5")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			argumentValues[1].setValue(string("test5"));
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.get
			//
			string key;
			if (argumentValues.size() < 2 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
				MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
				Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
			} else {
				returnValue = argumentValues[0].getMapValue(key);
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 261
	// console.log("map value for test1 using map dot operator: ", $map.test1)
	{
		const ScriptStatement& statement = scripts[1].statements[261];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test1 using map dot operator: "));
		// argumentValues[1] --> returnValue of getVariable("$map.test1")
		// depth = 1 / argument index = 1: getVariable("$map.test1")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map.test1"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 262
	// console.log("map value for test2 using map dot operator: ", $map.test2)
	{
		const ScriptStatement& statement = scripts[1].statements[262];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test2 using map dot operator: "));
		// argumentValues[1] --> returnValue of getVariable("$map.test2")
		// depth = 1 / argument index = 1: getVariable("$map.test2")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map.test2"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 263
	// console.log("map value for test3 using map dot operator: ", $map.test3)
	{
		const ScriptStatement& statement = scripts[1].statements[263];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test3 using map dot operator: "));
		// argumentValues[1] --> returnValue of getVariable("$map.test3")
		// depth = 1 / argument index = 1: getVariable("$map.test3")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map.test3"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 264
	// console.log("map value for test4 using map dot operator: ", $map.test4)
	{
		const ScriptStatement& statement = scripts[1].statements[264];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test4 using map dot operator: "));
		// argumentValues[1] --> returnValue of getVariable("$map.test4")
		// depth = 1 / argument index = 1: getVariable("$map.test4")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map.test4"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 265
	// console.log("map value for test5 using map dot operator: ", $map.test5)
	{
		const ScriptStatement& statement = scripts[1].statements[265];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map value for test5 using map dot operator: "));
		// argumentValues[1] --> returnValue of getVariable("$map.test5")
		// depth = 1 / argument index = 1: getVariable("$map.test5")
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			argumentValues[0].setValue(string("$map.test5"));
			// method code: getVariable
			string variable;
			if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
				returnValue = miniScript->getVariable(variable);
			} else {
				Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 266
	// console.log("adding map values using map dot operator: ")
	{
		const ScriptStatement& statement = scripts[1].statements[266];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("adding map values using map dot operator: "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 267
	// setVariable("$map.test6", 666)
	{
		const ScriptStatement& statement = scripts[1].statements[267];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map.test6"));
		argumentValues[1].setValue(static_cast<int64_t>(666));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 268
	// setVariable("$map.test7", 770)
	{
		const ScriptStatement& statement = scripts[1].statements[268];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map.test7"));
		argumentValues[1].setValue(static_cast<int64_t>(770));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 269
	// setVariable("$map.test8", 890)
	{
		const ScriptStatement& statement = scripts[1].statements[269];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$map.test8"));
		argumentValues[1].setValue(static_cast<int64_t>(890));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 270
	// console.log("map keys: ", map.getKeys($map))
	{
		const ScriptStatement& statement = scripts[1].statements[270];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map keys: "));
		// argumentValues[1] --> returnValue of map.getKeys($map)
		// depth = 1 / argument index = 1: map.getKeys($map)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.getKeys
			//
			if (argumentValues.size() != 1 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP) {
				Console::println("ScriptMethodMapGetKeys::executeMethod(): " + string("map.getKeys") + "(): parameter type mismatch @ argument 0: map expected");
			} else {
				auto keys = argumentValues[0].getMapKeys();
				returnValue.setType(TYPE_ARRAY);
				for (auto& key: keys) {
					returnValue.pushArrayValue(key);
				}
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 271
	// console.log("map values: ", map.getValues($map))
	{
		const ScriptStatement& statement = scripts[1].statements[271];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("map values: "));
		// argumentValues[1] --> returnValue of map.getValues($map)
		// depth = 1 / argument index = 1: map.getValues($map)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.getValues
			//
			if (argumentValues.size() != 1 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP) {
				Console::println("ScriptMethodMapGetValues::executeMethod(): " + string("map.getValues") + "(): parameter type mismatch @ argument 0: map expected");
			} else {
				auto values = argumentValues[0].getMapValues();
				returnValue.setType(TYPE_ARRAY);
				for (auto& value: values) {
					returnValue.pushArrayValue(value);
				}
			}
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 272
	// console.log("iterating keys and values using map.getKeys(): ")
	{
		const ScriptStatement& statement = scripts[1].statements[272];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("iterating keys and values using map.getKeys(): "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 273
	// setVariable("$mapKeys", map.getKeys($map))
	{
		const ScriptStatement& statement = scripts[1].statements[273];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$mapKeys"));
		// argumentValues[1] --> returnValue of map.getKeys($map)
		// depth = 1 / argument index = 1: map.getKeys($map)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 1> argumentValues;
			array<ScriptVariable, 1>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$map")
			// depth = 2 / argument index = 0: getVariable("$map")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$map"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: map.getKeys
			//
			if (argumentValues.size() != 1 ||
				argumentValues[0].getType() != ScriptVariableType::TYPE_MAP) {
				Console::println("ScriptMethodMapGetKeys::executeMethod(): " + string("map.getKeys") + "(): parameter type mismatch @ argument 0: map expected");
			} else {
				auto keys = argumentValues[0].getMapKeys();
				returnValue.setType(TYPE_ARRAY);
				for (auto& key: keys) {
					returnValue.pushArrayValue(key);
				}
			}
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 274
	// setVariable("$i", 0)
	{
		const ScriptStatement& statement = scripts[1].statements[274];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 275
	miniscript_statement_275:
	// forCondition(lesser($i, array.length($mapKeys)))
	{
		const ScriptStatement& statement = scripts[1].statements[275];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i, array.length($mapKeys))
		// depth = 1 / argument index = 0: lesser($i, array.length($mapKeys))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			// argumentValues[1] --> returnValue of array.length($mapKeys)
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: array.length($mapKeys)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$mapKeys")
				// depth = 3 / argument index = 0: getVariable("$mapKeys")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$mapKeys"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: array.length
				if (argumentValues.size() != 1 || argumentValues[0].getType() != ScriptVariableType::TYPE_ARRAY) {
					Console::println("ScriptMethodArrayLength::executeMethod(): " + string("array.length") + "(): parameter type mismatch @ argument 0: array expected");
				} else {
					returnValue.setValue(static_cast<int64_t>(argumentValues[0].getArraySize()));
				}
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_279;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 276
	miniscript_statement_276:
	// console.log(add($mapKeys[$i],add(" = ", map.get($map, $mapKeys[$i]))))
	{
		const ScriptStatement& statement = scripts[1].statements[276];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add($mapKeys[$i],add(" = ", map.get($map, $mapKeys[$i])))
		// depth = 1 / argument index = 0: add($mapKeys[$i], add(" = ", map.get($map, $mapKeys[$i])))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$mapKeys[$i]")
			// argumentValues[1] --> returnValue of add(" = ", map.get($map, $mapKeys[$i]))
			// depth = 2 / argument index = 0: getVariable("$mapKeys[$i]")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$mapKeys[$i]"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// depth = 2 / argument index = 1: add(" = ", map.get($map, $mapKeys[$i]))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				argumentValues[0].setValue(string(" = "));
				// argumentValues[1] --> returnValue of map.get($map, $mapKeys[$i])
				// depth = 3 / argument index = 1: map.get($map, $mapKeys[$i])
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					// argumentValues[0] --> returnValue of getVariable("$map")
					// argumentValues[1] --> returnValue of getVariable("$mapKeys[$i]")
					// depth = 4 / argument index = 0: getVariable("$map")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[0];
						array<ScriptVariable, 1> argumentValues;
						array<ScriptVariable, 1>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(string("$map"));
						// method code: getVariable
						string variable;
						if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
							returnValue = miniScript->getVariable(variable);
						} else {
							Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
							miniScript->startErrorScript(); return;
						}
					}
					// depth = 4 / argument index = 1: getVariable("$mapKeys[$i]")
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[1];
						array<ScriptVariable, 1> argumentValues;
						array<ScriptVariable, 1>& argumentValuesD4AIDX1 = argumentValues;
						argumentValues[0].setValue(string("$mapKeys[$i]"));
						// method code: getVariable
						string variable;
						if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
							returnValue = miniScript->getVariable(variable);
						} else {
							Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
							miniScript->startErrorScript(); return;
						}
					}
					// method code: map.get
					//
					string key;
					if (argumentValues.size() < 2 ||
						argumentValues[0].getType() != ScriptVariableType::TYPE_MAP ||
						MiniScript::getStringValue(argumentValues, 1, key, false) == false) {
						Console::println("ScriptMethodMapGet::executeMethod(): " + string("map.get") + "(): parameter type mismatch @ argument 0: map expected, @ argument 1: string");
					} else {
						returnValue = argumentValues[0].getMapValue(key);
					}
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 277
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[1].statements[277];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 278
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[278];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_275;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 279
	miniscript_statement_279:
	// console.log("--------------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[279];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("--------------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 280
	// console.log("Test if enabled naming condition will be emitted")
	{
		const ScriptStatement& statement = scripts[1].statements[280];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Test if enabled naming condition will be emitted"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 281
	// console.log("--------------------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[281];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("--------------------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 282
	// script.enableNamedCondition("named_condition_1")
	{
		const ScriptStatement& statement = scripts[1].statements[282];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("named_condition_1"));
		// method code: script.enableNamedCondition
		string name;
		if (MiniScript::getStringValue(argumentValues, 0, name, false) == true) {
			miniScript->scriptState.enabledNamedConditions.erase(
				remove(
					miniScript->scriptState.enabledNamedConditions.begin(),
					miniScript->scriptState.enabledNamedConditions.end(),
					name
				),
				miniScript->scriptState.enabledNamedConditions.end()
			);
			miniScript->scriptState.enabledNamedConditions.push_back(name);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.enableNamedCondition") + "(): parameter type mismatch @ argument 0: string expected");
			miniScript->startErrorScript(); return;
		}
	}

	// enabled named conditions
	{
		auto scriptIdxToStart = determineNamedScriptIdxToStart();
		if (scriptIdxToStart != -1 && scriptIdxToStart != scriptState.scriptIdx) {
		resetScriptExecutationState(scriptIdxToStart, STATE_NEXT_STATEMENT);
		scriptState.timeEnabledConditionsCheckLast = Time::getCurrentMillis();
		return;
		}
	}

	// Statement: 283
	// script.wait(2000)
	{
		const ScriptStatement& statement = scripts[1].statements[283];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(static_cast<int64_t>(2000));
		// method code: script.wait
		int64_t time;
		if (miniScript->getIntegerValue(argumentValues, 0, time) == true) {
			miniScript->scriptState.timeWaitStarted = Time::getCurrentMillis();
			miniScript->scriptState.timeWaitTime = time;
			miniScript->setScriptState(STATE_WAIT);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.wait") + "(): parameter type mismatch @ argument 0: integer expected");
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// enabled named conditions
	{
		auto scriptIdxToStart = determineNamedScriptIdxToStart();
		if (scriptIdxToStart != -1 && scriptIdxToStart != scriptState.scriptIdx) {
		resetScriptExecutationState(scriptIdxToStart, STATE_NEXT_STATEMENT);
		scriptState.timeEnabledConditionsCheckLast = Time::getCurrentMillis();
		return;
		}
	}

	// Statement: 284
	miniscript_statement_284:
	// script.disableNamedCondition("named_condition_1")
	{
		const ScriptStatement& statement = scripts[1].statements[284];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("named_condition_1"));
		// method code: script.disableNamedCondition
		string name;
		if (MiniScript::getStringValue(argumentValues, 0, name, false) == true) {
			miniScript->scriptState.enabledNamedConditions.erase(
				remove(
					miniScript->scriptState.enabledNamedConditions.begin(),
					miniScript->scriptState.enabledNamedConditions.end(),
					name
				),
				miniScript->scriptState.enabledNamedConditions.end()
			);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.disableNamedCondition") + "(): parameter type mismatch @ argument 0: string expected");
			miniScript->startErrorScript(); return;
		}
	}

	// Statement: 285
	// console.log("---------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[285];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 286
	// console.log("Naming condition has not been emitted")
	{
		const ScriptStatement& statement = scripts[1].statements[286];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Naming condition has not been emitted"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 287
	// console.log("---------------------------------------")
	{
		const ScriptStatement& statement = scripts[1].statements[287];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 288
	// script.stop()
	{
		const ScriptStatement& statement = scripts[1].statements[288];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: script.stop
		//
		miniScript->stopScriptExecutation();
	}
	if (scriptState.running == false) {
		return;
	}

	// Statement: 289
	// end()
	{
		const ScriptStatement& statement = scripts[1].statements[289];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}
	scriptState.scriptIdx = -1;
	scriptState.statementIdx = -1;
	setScriptState(STATE_WAIT_FOR_CONDITION);
}

void MiniScriptTest::on_error(int miniScriptGotoStatementIdx) {
	// -1 means complete method call
	if (miniScriptGotoStatementIdx == -1) {
		resetScriptExecutationState(2, STATE_NEXT_STATEMENT);
	}
	auto miniScript = this;
	miniScript->scriptState.scriptIdx = 2;
	if (miniScriptGotoStatementIdx == 2) goto miniscript_statement_2; else
	if (miniScriptGotoStatementIdx != -1 && miniScriptGotoStatementIdx != 0) Console::println("MiniScript::on_error(): Can not go to statement " + to_string(miniScriptGotoStatementIdx));

	// Statement: 0
	// console.log("An error occurred")
	{
		const ScriptStatement& statement = scripts[2].statements[0];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("An error occurred"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 1
	// script.wait(1000)
	{
		const ScriptStatement& statement = scripts[2].statements[1];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(static_cast<int64_t>(1000));
		// method code: script.wait
		int64_t time;
		if (miniScript->getIntegerValue(argumentValues, 0, time) == true) {
			miniScript->scriptState.timeWaitStarted = Time::getCurrentMillis();
			miniScript->scriptState.timeWaitTime = time;
			miniScript->setScriptState(STATE_WAIT);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.wait") + "(): parameter type mismatch @ argument 0: integer expected");
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 2
	miniscript_statement_2:
	// end()
	{
		const ScriptStatement& statement = scripts[2].statements[2];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}
	scriptState.scriptIdx = -1;
	scriptState.statementIdx = -1;
	setScriptState(STATE_WAIT_FOR_CONDITION);
}

void MiniScriptTest::on_emittest(int miniScriptGotoStatementIdx) {
	// -1 means complete method call
	if (miniScriptGotoStatementIdx == -1) {
		resetScriptExecutationState(3, STATE_NEXT_STATEMENT);
	}
	auto miniScript = this;
	miniScript->scriptState.scriptIdx = 3;
	if (miniScriptGotoStatementIdx == 12) goto miniscript_statement_12; else
	if (miniScriptGotoStatementIdx == 14) goto miniscript_statement_14; else
	if (miniScriptGotoStatementIdx == 16) goto miniscript_statement_16; else
	if (miniScriptGotoStatementIdx == 19) goto miniscript_statement_19; else
	if (miniScriptGotoStatementIdx == 21) goto miniscript_statement_21; else
	if (miniScriptGotoStatementIdx == 22) goto miniscript_statement_22; else
	if (miniScriptGotoStatementIdx != -1 && miniScriptGotoStatementIdx != 0) Console::println("MiniScript::on_emittest(): Can not go to statement " + to_string(miniScriptGotoStatementIdx));

	// Statement: 0
	// console.log("---------------------------------")
	{
		const ScriptStatement& statement = scripts[3].statements[0];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 1
	// console.log("SCRIPT JUST EMITTED A CONDITION")
	{
		const ScriptStatement& statement = scripts[3].statements[1];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("SCRIPT JUST EMITTED A CONDITION"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 2
	// console.log("---------------------------------")
	{
		const ScriptStatement& statement = scripts[3].statements[2];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("---------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 3
	// console.log()
	{
		const ScriptStatement& statement = scripts[3].statements[3];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 4
	// console.log("----------")
	{
		const ScriptStatement& statement = scripts[3].statements[4];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 5
	// console.log("Benchmark ")
	{
		const ScriptStatement& statement = scripts[3].statements[5];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Benchmark "));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 6
	// console.log("----------")
	{
		const ScriptStatement& statement = scripts[3].statements[6];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 7
	// setVariable("$startTime", time.getCurrentMillis())
	{
		const ScriptStatement& statement = scripts[3].statements[7];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$startTime"));
		// argumentValues[1] --> returnValue of time.getCurrentMillis()
		// depth = 1 / argument index = 1: time.getCurrentMillis()
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 0> argumentValues;
			array<ScriptVariable, 0>& argumentValuesD1AIDX1 = argumentValues;
			// method code: time.getCurrentMillis
			returnValue.setValue(Time::getCurrentMillis());
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 8
	// setVariable("$i", 0)
	{
		const ScriptStatement& statement = scripts[3].statements[8];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 9
	// setVariable("$j", 0)
	{
		const ScriptStatement& statement = scripts[3].statements[9];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$j"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 10
	// setVariable("$k", 0)
	{
		const ScriptStatement& statement = scripts[3].statements[10];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$k"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 11
	miniscript_statement_11:
	// forCondition(lesser($i, 500000))
	{
		const ScriptStatement& statement = scripts[3].statements[11];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of lesser($i, 500000)
		// depth = 1 / argument index = 0: lesser($i, 500000)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(500000));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: lesser
			float floatValueA;
			float floatValueB;
			if (MiniScript::getFloatValue(argumentValues, 0, floatValueA, false) == true &&
				MiniScript::getFloatValue(argumentValues, 1, floatValueB, false) == true) {
				returnValue.setValue(floatValueA < floatValueB);
			} else {
				Console::println("ScriptMethodLesser::executeMethod(): " + string("lesser") + "(): parameter type mismatch @ argument 0: float expected, @ argument 1: float expected");
				miniScript->startErrorScript(); return;
			}
		}
		// method code: forCondition
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodForCondition::executeMethod(): " + string("forCondition") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			auto now = Time::getCurrentMillis();
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_22;
			} else {
				miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_FOR);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 12
	miniscript_statement_12:
	// setVariable("$a", sub(add(123,add(mul(456,div(25, 12)),mul(7.5, 12.25))), 8))
	{
		const ScriptStatement& statement = scripts[3].statements[12];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$a"));
		// argumentValues[1] --> returnValue of sub(add(123,add(mul(456,div(25, 12)),mul(7.5, 12.25))), 8)
		// depth = 1 / argument index = 1: sub(add(123,add(mul(456,div(25, 12)),mul(7.5, 12.25))), 8)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of add(123,add(mul(456,div(25, 12)),mul(7.5, 12.25)))
			argumentValues[1].setValue(static_cast<int64_t>(8));
			// depth = 2 / argument index = 0: add(123, add(mul(456,div(25, 12)),mul(7.5, 12.25)))
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(static_cast<int64_t>(123));
				// argumentValues[1] --> returnValue of add(mul(456,div(25, 12)),mul(7.5, 12.25))
				// depth = 3 / argument index = 1: add(mul(456,div(25, 12)), mul(7.5, 12.25))
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX0[1];
					array<ScriptVariable, 2> argumentValues;
					array<ScriptVariable, 2>& argumentValuesD3AIDX1 = argumentValues;
					// argumentValues[0] --> returnValue of mul(456,div(25, 12))
					// argumentValues[1] --> returnValue of mul(7.5, 12.25)
					// depth = 4 / argument index = 0: mul(456, div(25, 12))
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[0];
						array<ScriptVariable, 2> argumentValues;
						array<ScriptVariable, 2>& argumentValuesD4AIDX0 = argumentValues;
						argumentValues[0].setValue(static_cast<int64_t>(456));
						// argumentValues[1] --> returnValue of div(25, 12)
						// depth = 5 / argument index = 1: div(25, 12)
						{
							// required method code arguments
							ScriptVariable& returnValue = argumentValuesD4AIDX0[1];
							array<ScriptVariable, 2> argumentValues;
							array<ScriptVariable, 2>& argumentValuesD5AIDX1 = argumentValues;
							argumentValues[0].setValue(static_cast<int64_t>(25));
							argumentValues[1].setValue(static_cast<int64_t>(12));
							// method code: div
							MiniScriptMath::div(miniScript, argumentValues, returnValue, statement);
						}
						// method code: mul
						MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
					}
					// depth = 4 / argument index = 1: mul(7.5, 12.25)
					{
						// required method code arguments
						ScriptVariable& returnValue = argumentValuesD3AIDX1[1];
						array<ScriptVariable, 2> argumentValues;
						array<ScriptVariable, 2>& argumentValuesD4AIDX1 = argumentValues;
						argumentValues[0].setValue(7.500000f);
						argumentValues[1].setValue(12.250000f);
						// method code: mul
						MiniScriptMath::mul(miniScript, argumentValues, returnValue, statement);
					}
					// method code: add
					MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
				}
				// method code: add
				MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
			}
			// method code: sub
			MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 13
	// if(equals($j, 0))
	{
		const ScriptStatement& statement = scripts[3].statements[13];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($j, 0)
		// depth = 1 / argument index = 0: equals($j, 0)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$j")
			argumentValues[1].setValue(static_cast<int64_t>(0));
			// depth = 2 / argument index = 0: getVariable("$j")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$j"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: if
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodIfCondition::executeMethod(): " + string("if") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_IF);
			//
			miniScript->scriptState.conditionStack.push(booleanValue);
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_15;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 14
	miniscript_statement_14:
	// setVariable("$k", add($k, 1))
	{
		const ScriptStatement& statement = scripts[3].statements[14];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$k"));
		// argumentValues[1] --> returnValue of add($k, 1)
		// depth = 1 / argument index = 1: add($k, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$k")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$k")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$k"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 15
	miniscript_statement_15:
	// end()
	{
		const ScriptStatement& statement = scripts[3].statements[15];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 16
	miniscript_statement_16:
	// setVariable("$i", add($i, 1))
	{
		const ScriptStatement& statement = scripts[3].statements[16];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$i"));
		// argumentValues[1] --> returnValue of add($i, 1)
		// depth = 1 / argument index = 1: add($i, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$i")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$i")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$i"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 17
	// setVariable("$j", add($j, 1))
	{
		const ScriptStatement& statement = scripts[3].statements[17];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$j"));
		// argumentValues[1] --> returnValue of add($j, 1)
		// depth = 1 / argument index = 1: add($j, 1)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX1 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$j")
			argumentValues[1].setValue(static_cast<int64_t>(1));
			// depth = 2 / argument index = 0: getVariable("$j")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX1[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$j"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 18
	// if(equals($j, 2))
	{
		const ScriptStatement& statement = scripts[3].statements[18];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of equals($j, 2)
		// depth = 1 / argument index = 0: equals($j, 2)
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			// argumentValues[0] --> returnValue of getVariable("$j")
			argumentValues[1].setValue(static_cast<int64_t>(2));
			// depth = 2 / argument index = 0: getVariable("$j")
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[0];
				array<ScriptVariable, 1> argumentValues;
				array<ScriptVariable, 1>& argumentValuesD2AIDX0 = argumentValues;
				argumentValues[0].setValue(string("$j"));
				// method code: getVariable
				string variable;
				if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
					returnValue = miniScript->getVariable(variable);
				} else {
					Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
					miniScript->startErrorScript(); return;
				}
			}
			// method code: equals
			returnValue.setValue(true);
			for (auto i = 1; i < argumentValues.size(); i++) {
				if (argumentValues[0].getValueString() != argumentValues[i].getValueString()) {
					returnValue.setValue(false);
					break;
				}
			}
		}
		// method code: if
		bool booleanValue;
		if (miniScript->getBooleanValue(argumentValues, 0, booleanValue, false) == false) {
			Console::println("ScriptMethodIfCondition::executeMethod(): " + string("if") + "(): parameter type mismatch @ argument 0: boolean expected");
			miniScript->startErrorScript(); return;
		} else {
			//
			miniScript->scriptState.endTypeStack.push(ScriptState::ENDTYPE_IF);
			//
			miniScript->scriptState.conditionStack.push(booleanValue);
			if (booleanValue == false) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_20;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 19
	miniscript_statement_19:
	// setVariable("$j", 0)
	{
		const ScriptStatement& statement = scripts[3].statements[19];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$j"));
		argumentValues[1].setValue(static_cast<int64_t>(0));
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 20
	miniscript_statement_20:
	// end()
	{
		const ScriptStatement& statement = scripts[3].statements[20];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 21
	miniscript_statement_21:
	// end()
	{
		const ScriptStatement& statement = scripts[3].statements[21];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
				goto miniscript_statement_11;
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}

	// Statement: 22
	miniscript_statement_22:
	// setVariable("$endTime", time.getCurrentMillis())
	{
		const ScriptStatement& statement = scripts[3].statements[22];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 2> argumentValues;
		array<ScriptVariable, 2>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("$endTime"));
		// argumentValues[1] --> returnValue of time.getCurrentMillis()
		// depth = 1 / argument index = 1: time.getCurrentMillis()
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[1];
			array<ScriptVariable, 0> argumentValues;
			array<ScriptVariable, 0>& argumentValuesD1AIDX1 = argumentValues;
			// method code: time.getCurrentMillis
			returnValue.setValue(Time::getCurrentMillis());
		}
		// method code: setVariable
		string variable;
		if (argumentValues.size() != 2 ||
			MiniScript::getStringValue(argumentValues, 0, variable, false) == false) {
			Console::println("ScriptMethodSetVariable::executeMethod(): " + string("setVariable") + "(): parameter type mismatch @ argument 0: string expected, @ argument 1: mixed expected");
			miniScript->startErrorScript(); return;
		} else {
			miniScript->setVariable(variable, argumentValues[1], &statement);
			returnValue = argumentValues[1];
		}
	}

	// Statement: 23
	// console.log(add("Finished. Time: ", sub($endTime, $startTime)))
	{
		const ScriptStatement& statement = scripts[3].statements[23];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		// argumentValues[0] --> returnValue of add("Finished. Time: ", sub($endTime, $startTime))
		// depth = 1 / argument index = 0: add("Finished. Time: ", sub($endTime, $startTime))
		{
			// required method code arguments
			ScriptVariable& returnValue = argumentValuesD0[0];
			array<ScriptVariable, 2> argumentValues;
			array<ScriptVariable, 2>& argumentValuesD1AIDX0 = argumentValues;
			argumentValues[0].setValue(string("Finished. Time: "));
			// argumentValues[1] --> returnValue of sub($endTime, $startTime)
			// depth = 2 / argument index = 1: sub($endTime, $startTime)
			{
				// required method code arguments
				ScriptVariable& returnValue = argumentValuesD1AIDX0[1];
				array<ScriptVariable, 2> argumentValues;
				array<ScriptVariable, 2>& argumentValuesD2AIDX1 = argumentValues;
				// argumentValues[0] --> returnValue of getVariable("$endTime")
				// argumentValues[1] --> returnValue of getVariable("$startTime")
				// depth = 3 / argument index = 0: getVariable("$endTime")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[0];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX0 = argumentValues;
					argumentValues[0].setValue(string("$endTime"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// depth = 3 / argument index = 1: getVariable("$startTime")
				{
					// required method code arguments
					ScriptVariable& returnValue = argumentValuesD2AIDX1[1];
					array<ScriptVariable, 1> argumentValues;
					array<ScriptVariable, 1>& argumentValuesD3AIDX1 = argumentValues;
					argumentValues[0].setValue(string("$startTime"));
					// method code: getVariable
					string variable;
					if (MiniScript::getStringValue(argumentValues, 0, variable, false) == true) {
						returnValue = miniScript->getVariable(variable);
					} else {
						Console::println("ScriptMethodGetVariable::executeMethod(): " + string("getVariable") + "(): parameter type mismatch @ argument 0: string expected");
						miniScript->startErrorScript(); return;
					}
				}
				// method code: sub
				MiniScriptMath::sub(miniScript, argumentValues, returnValue, statement);
			}
			// method code: add
			MiniScriptMath::add(miniScript, argumentValues, returnValue, statement);
		}
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 24
	// script.stop()
	{
		const ScriptStatement& statement = scripts[3].statements[24];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: script.stop
		//
		miniScript->stopScriptExecutation();
	}
	if (scriptState.running == false) {
		return;
	}

	// Statement: 25
	// end()
	{
		const ScriptStatement& statement = scripts[3].statements[25];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}
	scriptState.scriptIdx = -1;
	scriptState.statementIdx = -1;
	setScriptState(STATE_WAIT_FOR_CONDITION);
}

void MiniScriptTest::on_enabled_named_condition_1(int miniScriptGotoStatementIdx) {
	// -1 means complete method call
	if (miniScriptGotoStatementIdx == -1) {
		resetScriptExecutationState(4, STATE_NEXT_STATEMENT);
	}
	auto miniScript = this;
	miniScript->scriptState.scriptIdx = 4;
	if (miniScriptGotoStatementIdx != -1 && miniScriptGotoStatementIdx != 0) Console::println("MiniScript::on_enabled_named_condition_1(): Can not go to statement " + to_string(miniScriptGotoStatementIdx));

	// Statement: 0
	// script.disableNamedCondition("named_condition_1")
	{
		const ScriptStatement& statement = scripts[4].statements[0];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("named_condition_1"));
		// method code: script.disableNamedCondition
		string name;
		if (MiniScript::getStringValue(argumentValues, 0, name, false) == true) {
			miniScript->scriptState.enabledNamedConditions.erase(
				remove(
					miniScript->scriptState.enabledNamedConditions.begin(),
					miniScript->scriptState.enabledNamedConditions.end(),
					name
				),
				miniScript->scriptState.enabledNamedConditions.end()
			);
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.disableNamedCondition") + "(): parameter type mismatch @ argument 0: string expected");
			miniScript->startErrorScript(); return;
		}
	}

	// Statement: 1
	// console.log("------------------------------------")
	{
		const ScriptStatement& statement = scripts[4].statements[1];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 2
	// console.log("named_condition_1 has been emitted")
	{
		const ScriptStatement& statement = scripts[4].statements[2];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("named_condition_1 has been emitted"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 3
	// console.log("------------------------------------")
	{
		const ScriptStatement& statement = scripts[4].statements[3];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("------------------------------------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 4
	// console.log()
	{
		const ScriptStatement& statement = scripts[4].statements[4];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 5
	// console.log("-----------")
	{
		const ScriptStatement& statement = scripts[4].statements[5];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 6
	// console.log("Test emit")
	{
		const ScriptStatement& statement = scripts[4].statements[6];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("Test emit"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 7
	// console.log("-----------")
	{
		const ScriptStatement& statement = scripts[4].statements[7];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("-----------"));
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 8
	// console.log()
	{
		const ScriptStatement& statement = scripts[4].statements[8];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: console.log
		for (auto& argumentValue: argumentValues) {
			Console::print(argumentValue.getValueString());
		}
		Console::println();
	}

	// Statement: 9
	// script.emit(emittest)
	{
		const ScriptStatement& statement = scripts[4].statements[9];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 1> argumentValues;
		array<ScriptVariable, 1>& argumentValuesD0 = argumentValues;
		argumentValues[0].setValue(string("emittest"));
		// method code: script.emit
		string condition;
		if (MiniScript::getStringValue(argumentValues, 0, condition, false) == true) {
			miniScript->emit(condition); return;
		} else {
			Console::println("ScriptMethodScriptWait::executeMethod(): " + string("script.emit") + "(): parameter type mismatch @ argument 0: string expected");
			miniScript->startErrorScript(); return;
		}
	}

	// Statement: 10
	// end()
	{
		const ScriptStatement& statement = scripts[4].statements[10];
		miniScript->scriptState.statementIdx = statement.statementIdx;
		// required method code arguments
		ScriptVariable returnValue;
		array<ScriptVariable, 0> argumentValues;
		array<ScriptVariable, 0>& argumentValuesD0 = argumentValues;
		// method code: end
		if (miniScript->scriptState.endTypeStack.empty() == true) {
			if (miniScript->scriptState.statementIdx < miniScript->scripts[miniScript->scriptState.scriptIdx].statements.size() - 1) {
				Console::println("ScriptMethodEnd::executeMethod(): end without forXXX/if");
				miniScript->startErrorScript(); return;
			}
		} else {
			auto endType = miniScript->scriptState.endTypeStack.top();
			miniScript->scriptState.endTypeStack.pop();
			switch(endType) {
				case ScriptState::ENDTYPE_FOR:
					// no op
					break;
				case ScriptState::ENDTYPE_IF:
					miniScript->scriptState.conditionStack.pop();
					break;
			}
			if (statement.gotoStatementIdx != STATE_NONE) {
				miniScript->setScriptState(STATE_NEXT_STATEMENT);
			}
		}
	}
	if (scriptState.stateStack.top().state != STATE_NEXT_STATEMENT) {
		miniScript->scriptState.statementIdx++;
		return;
	}
	scriptState.scriptIdx = -1;
	scriptState.statementIdx = -1;
	setScriptState(STATE_WAIT_FOR_CONDITION);
}


/*__MINISCRIPT_TRANSPILEDMINISCRIPTCODE_DEFINITIONS_END__*/
