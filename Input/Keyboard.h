#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../Util/Camera.h"
#include "Mouse.h"

class Keyboard {

public:
    Keyboard(Camera* camera, Mouse *mouse);
    bool keyAction(unsigned char key, int x, int y);
    bool specialKeyAction(int key, int x, int y);

private:
    Camera* camera;
    Mouse* mouse;

};

#endif