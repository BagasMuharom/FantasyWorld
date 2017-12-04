#ifndef READY_RUMPUT_H
#define READY_RUMPUT_H

#include "GL/glut.h"
#include "../Util/Util.h"
#include "../Objek/Objek.h"

void lokasiRumput();
void rerumputan();
void alangAlang();
void lokasiAlangAlang();

void lokasiRumput()
{
    glPushMatrix();
    glTranslatef(-5, 0, 0);
    rerumputan();
    glPopMatrix();
    lokasiAlangAlang();
}

void rerumputan()
{
    ColorList::hijau(1)->set(true);
    for(float degree = 0; degree <= 360; degree += (360 / 6)) {
        Vertex v(0.3, 0, 0);
        v.rotate(degree, 0, 1, 0);
        rumput()->scale(1, 0.8, 1)->rotate(90 + degree, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        Vertex v2(0.2, 0, 0);
        v2.rotate(degree + 30, 0, 1, 0);
        rumput()->scale(1, 1, 1)->rotate(90 + degree, 0, 1, 0)->translate(v2.x, v2.y, v2.z)->draw();
    }
}

void lokasiAlangAlang()
{
    ColorList::hijau(1)->set(true);
    glPushMatrix();
    glTranslatef(12.5, -0.75, 0);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 10, 0, 0, 1);
    alangAlang();
    glPopMatrix();
}

void alangAlang()
{
    for(float degree = 0; degree <= 360; degree += (360 / 10)) {
        Vertex v(0.35, 0, 0);
        v.rotate(degree, 0, 1, 0);
        reed()->scale(0.5, 0.65, 1)->rotate(90 + degree, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        Vertex v2(0.3, 0, 0);
        v2.rotate(degree + 10, 0, 1, 0);
        reed()->scale(0.5, 1, 1)->rotate(90 + degree, 0, 1, 0)->translate(v2.x, v2.y, v2.z)->draw();
    }
}

#endif