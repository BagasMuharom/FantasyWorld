#include "Keyboard.h"
#include "../Camera/Camera.h"
#include "GL/glut.h"
#include "Mouse.h"
#include <math.h>

Keyboard::Keyboard(Camera *camera, Mouse *mouse)
{
    this->camera = camera;
    this->mouse = mouse;
}

void Keyboard::keyAction(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        this->camera->toggleFPS();
        mouse->cursorToggle();
        break;
    case 'w':
        this->camera->move();
        break;
    case 's':
        this->camera->move(-this->camera->getTranslationSpeed());
        break;
    case 'd':
        this->camera->strafe(-this->camera->getTranslationSpeed());
        break;
    case 'a':
        this->camera->strafe();
        break;
        // case '+':
        //     LightPosition[2] += 2.0f;
        //     break;
        // case '-':
        //     LightPosition[2] -= 2.0f;
        //     break;
    }
}

void Keyboard::specialKeyAction(int key, int x, int y)
{
    if (!this->camera->isFPSMode())
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            this->camera->rotateAngleX(M_PI / 180 * 3);
            break;
        case GLUT_KEY_DOWN:
            this->camera->rotateAngleX(M_PI / 180 * -3);
            break;
        case GLUT_KEY_LEFT:
            this->camera->rotateAngleY(M_PI / 180 * -3);
            break;
        case GLUT_KEY_RIGHT:
            this->camera->rotateAngleY(M_PI / 180 * 3);
            break;
        case GLUT_KEY_PAGE_UP:
            this->camera->fly(1);
            break;
        case GLUT_KEY_PAGE_DOWN:
            this->camera->fly(-1);
            break;
        }
    }
}