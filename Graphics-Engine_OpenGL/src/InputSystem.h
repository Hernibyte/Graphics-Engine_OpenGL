#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "KeyCode.h"

struct InputSystem {
	InputSystem() = default;
	bool GetKey(int key);
	bool GetKeyMouse(int KeyCode);
};

#endif // !INPUTSYSTEM_H
