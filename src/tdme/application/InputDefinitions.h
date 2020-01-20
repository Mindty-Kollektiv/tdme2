#pragma once

#if defined(VULKAN)
	#define GLFW_INCLUDE_VULKAN
	#include <GLFW/glfw3.h>

	#define KEYBOARD_MODIFIER_SHIFT	GLFW_MOD_SHIFT
	#define KEYBOARD_MODIFIER_CTRL GLFW_MOD_CONTROL
	#define KEYBOARD_MODIFIER_ALT GLFW_MOD_ALT

	#define MOUSE_BUTTON_DOWN GLFW_PRESS
	#define MOUSE_BUTTON_UP GLFW_RELEASE

	#define MOUSE_BUTTON_NONE 0
	#define MOUSE_BUTTON_LEFT (GLFW_MOUSE_BUTTON_LEFT + 1)
	#define MOUSE_BUTTON_RIGHT (GLFW_MOUSE_BUTTON_RIGHT + 1)
	#define MOUSE_BUTTON_MIDDLE (GLFW_MOUSE_BUTTON_MIDDLE + 1)

	#define KEYBOARD_KEYCODE_TAB GLFW_KEY_TAB
	#define KEYBOARD_KEYCODE_TAB_SHIFT -2
	#define KEYBOARD_KEYCODE_BACKSPACE GLFW_KEY_BACKSPACE
	#define KEYBOARD_KEYCODE_RETURN GLFW_KEY_ENTER
	#define KEYBOARD_KEYCODE_DELETE GLFW_KEY_DELETE
	#define KEYBOARD_KEYCODE_SPACE GLFW_KEY_SPACE
	#define KEYBOARD_KEYCODE_LEFT GLFW_KEY_LEFT
	#define KEYBOARD_KEYCODE_UP GLFW_KEY_UP
	#define KEYBOARD_KEYCODE_RIGHT GLFW_KEY_RIGHT
	#define KEYBOARD_KEYCODE_DOWN GLFW_KEY_DOWN
	#define KEYBOARD_KEYCODE_POS1 GLFW_KEY_HOME
	#define KEYBOARD_KEYCODE_END GLFW_KEY_END
	#define KEYBOARD_KEYCODE_ESCAPE GLFW_KEY_ESCAPE
	#define KEYBOARD_KEYCODE_F1 GLFW_KEY_F1
	#define KEYBOARD_KEYCODE_F2 GLFW_KEY_F2
	#define KEYBOARD_KEYCODE_F3 GLFW_KEY_F3
	#define KEYBOARD_KEYCODE_F4 GLFW_KEY_F4
	#define KEYBOARD_KEYCODE_F5 GLFW_KEY_F5
	#define KEYBOARD_KEYCODE_F6 GLFW_KEY_F6
	#define KEYBOARD_KEYCODE_F7 GLFW_KEY_F7
	#define KEYBOARD_KEYCODE_F8 GLFW_KEY_F8
	#define KEYBOARD_KEYCODE_F9 GLFW_KEY_F9
	#define KEYBOARD_KEYCODE_F10 GLFW_KEY_F10
	#define KEYBOARD_KEYCODE_F11 GLFW_KEY_F11
	#define KEYBOARD_KEYCODE_F12 GLFW_KEY_F12

#else
	#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__linux__) || defined(_WIN32)
		#include <GL/freeglut.h>
	#elif defined(__APPLE__)
		#include <GLUT/glut.h>
	#elif defined(__HAIKU__)
		#include <GL/glut.h>
	#endif

	#define KEYBOARD_MODIFIER_SHIFT	GLUT_ACTIVE_SHIFT
	#define KEYBOARD_MODIFIER_CTRL GLUT_ACTIVE_CTRL
	#define KEYBOARD_MODIFIER_ALT GLUT_ACTIVE_ALT

	#define MOUSE_BUTTON_DOWN GLUT_DOWN
	#define MOUSE_BUTTON_UP GLUT_UP

	#define MOUSE_BUTTON_NONE 0
	#define MOUSE_BUTTON_LEFT (GLUT_LEFT_BUTTON + 1)
	#define MOUSE_BUTTON_RIGHT (GLUT_RIGHT_BUTTON + 1)
	#define MOUSE_BUTTON_MIDDLE (GLUT_MIDDLE_BUTTON + 1)

	#define KEYBOARD_KEYCODE_TAB 9
	#define KEYBOARD_KEYCODE_TAB_SHIFT 25
	#define KEYBOARD_KEYCODE_BACKSPACE 8
	#define KEYBOARD_KEYCODE_RETURN 13
	#define KEYBOARD_KEYCODE_DELETE 46
	#define KEYBOARD_KEYCODE_SPACE 32
	#define KEYBOARD_KEYCODE_LEFT GLUT_KEY_LEFT
	#define KEYBOARD_KEYCODE_UP GLUT_KEY_UP
	#define KEYBOARD_KEYCODE_RIGHT GLUT_KEY_RIGHT
	#define KEYBOARD_KEYCODE_DOWN GLUT_KEY_DOWN
	#define KEYBOARD_KEYCODE_POS1 106
	#define KEYBOARD_KEYCODE_END 107
	#define KEYBOARD_KEYCODE_ESCAPE 27
	#define KEYBOARD_KEYCODE_F1 GLUT_KEY_F1
	#define KEYBOARD_KEYCODE_F2 GLUT_KEY_F2
	#define KEYBOARD_KEYCODE_F3 GLUT_KEY_F3
	#define KEYBOARD_KEYCODE_F4 GLUT_KEY_F4
	#define KEYBOARD_KEYCODE_F5 GLUT_KEY_F5
	#define KEYBOARD_KEYCODE_F6 GLUT_KEY_F6
	#define KEYBOARD_KEYCODE_F7 GLUT_KEY_F7
	#define KEYBOARD_KEYCODE_F8 GLUT_KEY_F8
	#define KEYBOARD_KEYCODE_F9 GLUT_KEY_F9
	#define KEYBOARD_KEYCODE_F10 GLUT_KEY_F10
	#define KEYBOARD_KEYCODE_F11 GLUT_KEY_F11
	#define KEYBOARD_KEYCODE_F12 GLUT_KEY_F12

#endif
