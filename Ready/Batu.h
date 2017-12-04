#ifndef READY_BATU_H
#define READY_BATU_H

#include "../Objek/Misc.h"
#include "GL/glut.h"
#include "../Util/Util.h"

void lokasiBatu()
{
    glPushMatrix();
    glTranslatef(15, -0.5, 15);
    batu();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(17, -0.5, 18);
    batu();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(18, -0.5, 19);
    batu();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(18, -0.35, -15.5);
    batu();
    glPopMatrix();
}

#endif