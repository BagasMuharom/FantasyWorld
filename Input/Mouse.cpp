#include "Mouse.h"
#include "../Camera/Camera.h"
#include "GL/glut.h"
#include <math.h>

Mouse::Mouse(Camera* camera, int vw, int vh)
{
    this->camera = camera;
    this->vw = vw;
    this->vh = vh;
}

void Mouse::passive(int x, int y)
{
    static bool just_warped = false;
    
    if (just_warped)
    {
        just_warped = false;
        return;
    }

    if (this->camera->isFPSMode())
    {
        glutWarpPointer(this->vw / 2, this->vh / 2);

        int dx = x - this->vw / 2;
        int dy = y - this->vh / 2;

        if (dx)
            this->camera->rotateAngleY(M_PI / 180 * 0.2 * dx);

        if (dy)
            this->camera->rotateAngleX(-M_PI / 180 * 0.2 * dy);

        just_warped = true;
    }
}

void Mouse::cursorToggle()
{
    if (this->camera->isFPSMode())
    {
        glutSetCursor(GLUT_CURSOR_NONE);
        glutWarpPointer(this->vw / 2, this->vh / 2);
    }
    else
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
}