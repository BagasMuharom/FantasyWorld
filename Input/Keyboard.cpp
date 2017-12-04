#include "Keyboard.h"
#include "../Util/Camera.h"
#include "GL/glut.h"
#include "Mouse.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Keyboard::Keyboard(Camera *camera, Mouse *mouse)
{
    this->camera = camera;
    this->mouse = mouse;
}

bool Keyboard::keyAction(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        this->camera->toggleFPS();
        mouse->cursorToggle();
        return true;
    case 'w':
        this->camera->move();
        return true;
    case 's':
        this->camera->move(-this->camera->getTranslationSpeed());
        return true;
    case 'd':
        this->camera->strafe(-this->camera->getTranslationSpeed());
        return true;
    case 'a':
        this->camera->strafe();
        return true;
    case 'q':
        if(!this->camera->isFPSMode())
            camera->rotateCamera(-3);
        return true;
    case 'e':
        if(!this->camera->isFPSMode())
            camera->rotateCamera(3);
        return true;
    }

    return false;
}

bool Keyboard::specialKeyAction(int key, int x, int y)
{
    if (!this->camera->isFPSMode())
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            this->camera->rotateAngleX(M_PI / 180 * 3);
            return true;
            break;
        case GLUT_KEY_DOWN:
            this->camera->rotateAngleX(M_PI / 180 * -3);
            return true;
            break;
        case GLUT_KEY_LEFT:
            this->camera->rotateAngleY(M_PI / 180 * -3);
            return true;
            break;
        case GLUT_KEY_RIGHT:
            this->camera->rotateAngleY(M_PI / 180 * 3);
            return true;
            break;
        case GLUT_KEY_PAGE_UP:
            this->camera->fly(1);
            return true;
            break;
        case GLUT_KEY_PAGE_DOWN:
            this->camera->fly(-1);
            return true;
            break;
        }
    }

    return false;
}
