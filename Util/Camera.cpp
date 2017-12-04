#include "Camera.h"
#include "GL/glut.h"
#include <math.h>
#include <iostream>
#include "../Util/Util.h"

using namespace std;

// Menggunakan pointer agar lebih efektif, wkwk
Camera::Camera(float *cameraX, float *cameraY, float *cameraZ, float *lookX, float *lookY, float *lookZ)
{
    this->cameraX = cameraX;
    this->cameraY = cameraY;
    this->cameraZ = cameraZ;

    this->lookX = lookX;
    this->lookY = lookY;
    this->lookZ = lookZ;
}

void Camera::rotateAngleX(float angle)
{
    // Memberi batasan agar camera tidak bisa
    // melihat ke belakang secara vertical
    float batasan = 89 * M_PI / 180;

    this->angleX += angle;

    if (this->angleX < -batasan)
        this->angleX = -batasan;

    if (this->angleX > batasan)
        this->angleX = batasan;

    this->update();
}

void Camera::rotateAngleY(float angle)
{
    this->angleY += angle;

    this->update();
}

void Camera::update()
{
    float lookX = cos(this->angleY) * cos(this->angleX);
    float lookY = sin(this->angleX);
    float lookZ = sin(this->angleY) * cos(this->angleX);

    *this->lookX = lookX + *this->cameraX;
    *this->lookY = lookY + *this->cameraY;
    *this->lookZ = lookZ + *this->cameraZ;

    this->strafeX = cos(this->angleY - M_PI_2);
	this->strafeZ = sin(this->angleY - M_PI_2);
}

void Camera::toggleFPS()
{
    this->fpsmode = !this->fpsmode;
}

bool Camera::isFPSMode()
{
    return this->fpsmode;
}

void Camera::setAngleX(float angle)
{
    this->angleX = angle;
}

void Camera::setAngleY(float angle)
{
    this->angleY = angle;
}

void Camera::move(float speed)
{
    float lx = cos(this->angleY) * cos(this->angleX);
    float ly = sin(this->angleX);
    float lz = sin(this->angleY) * cos(this->angleX);

    *this->cameraX += ((speed == 0) ? this->translationSpeed : speed) * lx;
    *this->cameraZ += ((speed == 0) ? this->translationSpeed : speed) * lz;

    // Jika melakukan mode spectate
    // maka camera bisa merubah posisi y
    if(!this->fpsmode)
        *this->cameraY += ((speed == 0) ? this->translationSpeed : speed) * ly;

    this->update();
}

void Camera::strafe(float speed)
{
    *this->cameraX += ((speed == 0) ? this->translationSpeed : speed) * this->strafeX;
    *this->cameraZ += ((speed == 0) ? this->translationSpeed : speed) * this->strafeZ;

    this->update();
}

void Camera::fly(float incr)
{
    if(!this->fpsmode) {
        *this->cameraY += incr;
        *this->lookY += incr;
    }
}

void Camera::rotateCamera(float angle)
{
    Vertex* v = new Vertex(1, 0, 0);
    v->rotate(angle, 0, 1, 0);
    v->translate(*this->lookX, *this->lookY, *this->lookZ);

    *this->cameraX = v->x;
    *this->cameraY = v->y;
    *this->cameraZ = v->z;
}

void Camera::setTranslationSpeed(float speed)
{
    this->translationSpeed = speed;
}

float Camera::getTranslationSpeed()
{
    return this->translationSpeed;
}