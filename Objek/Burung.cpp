#include "Burung.h"
#include "GL/glut.h"
#include <iostream>

Burung::Burung(float scale)
{
    this->scale = scale;
}

Burung* Burung::create(float scale)
{
    return new Burung(scale);
}

Burung* Burung::rotatePos(float degree, bool x, bool y, bool z, float a, float b)
{
    return this;
}

Burung* Burung::rotate(float degree, bool x, bool y, bool z)
{
    return this;
}

Burung* Burung::translate(float x, float y, float z)
{
    this->posX = x;
    this->posY = y;
    this->posZ = z;

    return this;
}

void Burung::draw()
{
    glPushMatrix();
        glColor3ub(255, 255, 255);
        glTranslatef(this->posX, this->posY, this->posZ);
        glScalef(this->scale, this->scale, this->scale);
        
        // Kepala
        glutSolidSphere(1, 10, 10);

        // Badan
        glPushMatrix();
            glTranslatef(1.5, 0, 0);
            glScalef(2, 1, 1);
            glutSolidSphere(1, 15, 15);
        glPopMatrix();

        // Paruh
        glPushMatrix();
            glColor3ub(120, 120, 255);
            glTranslatef(-0.85, -0.2, 0);
            glRotatef(15, 0, 0, 1);
            glRotatef(-90, 0, 1, 0);
            glutSolidCone(0.35, 0.7, 8, 1);
        glPopMatrix();

        // Mata kanan
        glPushMatrix();
            glColor3ub(120, 120, 0);
            glTranslatef(-0.55, 0.325, 0.6);
            glutSolidSphere(0.2, 8, 8);    
        glPopMatrix();

        // Mata kiri
        glPushMatrix();
            glColor3ub(120, 120, 0);
            glTranslatef(-0.55, 0.325, -0.6);
            glutSolidSphere(0.2, 8, 8);    
        glPopMatrix();

        // Ekor
        glPushMatrix();
            glColor3ub(255, 255, 255);
            glTranslatef(4.15, 0.5, 0);
            glRotatef(25, 0, 0, 1);
            glRotatef(-90, 0, 1, 0);
            glScalef(1, 0.25, 1);
            glutSolidCone(1, 1.75, 10, 1);
        glPopMatrix();

        // Sayap kanan
        glPushMatrix();
            glColor3ub(120, 120, 255);
            glPushMatrix();
                glTranslatef(1.5, 0, 0);
                glScalef(1, 0.25, 1);
                glutSolidCone(1.5, 3.5, 10, 1);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(2.25, 0, 0);
                glRotatef(15, 0, 1, 0);
                glScalef(1, 0.25, 1);
                glutSolidCone(0.75, 2.5, 10, 1);
            glPopMatrix();
        glPopMatrix();
        
        // Sayap kiri
        glPushMatrix();
            glColor3ub(120, 120, 255);
            glRotatef(180, 1, 0, 0);
            glPushMatrix();
                glTranslatef(1.5, 0, 0);
                glScalef(1, 0.25, 1);
                glutSolidCone(1.5, 3.5, 10, 1);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(2.25, 0, 0);
                glRotatef(15, 0, 1, 0);
                glScalef(1, 0.25, 1);
                glutSolidCone(0.75, 2.5, 10, 1);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    delete this;
}

Burung::~Burung()
{
    std::cout << "Burung deleted" << std::endl;
}