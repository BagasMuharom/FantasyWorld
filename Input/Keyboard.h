#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../Camera/Camera.h"
#include "Mouse.h"

class Keyboard {

public:
    Keyboard(Camera* camera, Mouse *mouse);
    void keyAction(unsigned char key, int x, int y);
    void specialKeyAction(int key, int x, int y);

private:
    Camera* camera;
    Mouse* mouse;

};

#endif