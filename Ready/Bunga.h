#ifndef READY_BUNGA_H
#define READY_BUNGA_H

#include "GL/glut.h"
#include "../Util/Util.h"
#include "../Util/Color.h"
#include "../Objek/Objek.h"

void lokasiBunga()
{
    glPushMatrix();
    glTranslatef(6, 0, 0);
    Misc::serumpunBunga1();
    glPopMatrix();
}

void lokasiBungaTeratai()
{
    glPushMatrix();
    glTranslatef(14 + (translasiArus / 5), translasiTinggi - 0.2, 0);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->draw();
    glPopMatrix();
    glPushMatrix();
    Misc::bungaTeratai();
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(14 + (translasiArus / 5), translasiTinggi - 0.2, 2.5);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glRotatef(45, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->scale(0.75, 1, 0.75)->draw();
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(15.5 + (translasiArus / 5), translasiTinggi - 0.2, 2.4);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glRotatef(45, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->scale(0.5, 1, 0.5)->draw();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4, 0, 13.5);
    glPushMatrix();
    glTranslatef(14 + (translasiArus / 5), translasiTinggi - 0.2, 0);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->draw();
    glPopMatrix();
    glPushMatrix();
    Misc::bungaTeratai();
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(14 + (translasiArus / 5), translasiTinggi - 0.2, 2.5);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glRotatef(45, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->scale(0.75, 1, 0.75)->draw();
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(14.5 + (translasiArus / 5), translasiTinggi - 0.2, 2.4);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glRotatef(45, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->scale(0.5, 1, 0.5)->draw();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

#endif