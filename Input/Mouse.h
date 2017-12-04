#ifndef MOUSE_H
#define MOUSE_H

#include "../Util/Camera.h"

class Mouse {
public:
    Mouse(Camera* camera, int vw, int vh);
    void passive(int x, int y);
    void cursorToggle();

private:
    Camera* camera;
    int vw;
    int vh;  
};

#endif