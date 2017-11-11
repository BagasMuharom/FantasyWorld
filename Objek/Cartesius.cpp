#include "Cartesius.h"
#include "GL/glut.h"
#include <iostream>

Cartesius::Cartesius(float x, float y, float z, float incX, float incY, float incZ )
{
    this->x = new Cartesius::element;
    this->x->start = -x;
    this->x->end = x;
    this->x->increment = incX;

    this->y = new Cartesius::element;
    this->y->start = -y;
    this->y->end = y;
    this->y->increment = incY;

    this->z = new Cartesius::element;
    this->z->start = -z;
    this->z->end = z;
    this->z->increment = incZ;
}

void Cartesius::draw()
{
    glLineWidth(1.5);
    
    // Draw the x
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(this->x->start, 0, 0);
    glVertex3f(this->x->end, 0, 0);
    glEnd();
    
    // Draw the y
    glColor3ub(0, 255, 0); 
    glBegin(GL_LINES);
    glVertex3f(0, this->y->start, 0);
    glVertex3f(0, this->y->end, 0);
    glEnd();
    
    // Draw the z
    glColor3ub(0, 0, 255); 
    glBegin(GL_LINES);
    glVertex3f(0, 0, this->z->start);
    glVertex3f(0, 0, this->z->end);
    glEnd();

    // Draw the white line in x and z
    glColor3ub(255, 255, 255);
    for(float x = this->x->start; x <= this->x->end; x++) {
        glBegin(GL_LINES);
            glVertex3f(x, 0, this->z->start);
            glVertex3f(x, 0, this->z->end);
        glEnd();
    }
    
    for(float z = this->z->start; z <= this->z->end; z++) {
        glBegin(GL_LINES);
            glVertex3f(this->x->start, 0, z);
            glVertex3f(this->x->end, 0, z);
        glEnd();
    }
}