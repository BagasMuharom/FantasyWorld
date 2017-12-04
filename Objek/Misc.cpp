#include "Misc.h"
#include "GL/glut.h"
#include "../Util/Util.h"
#include "Objek.h"
#include "../Util/Color.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void Misc::pocong()
{
    glColor3f(1,1,1);

    // Ikat atas
    glPushMatrix();
    glTranslatef(0, 2.15, 0);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.15, 0.3, 6, 6);
    glPopMatrix();

    // kepala
    glPushMatrix();
    glTranslatef(0, 1.55, 0);
    glScalef(0.8, 1.15, 1);
    glutSolidSphere(0.4, 8, 8);
    glPopMatrix();

    // Mata kanan
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-0.1, 1.65, 0.4);
    glutSolidSphere(0.06, 8, 8);
    glPopMatrix();

    // Mata kiri
    glPushMatrix();
    glColor3f(1, 0, 0);

    glTranslatef(0.1, 1.65, 0.4);
    glutSolidSphere(0.06, 8, 8);
    glPopMatrix();

    // Badan
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0, 0.65, 0);
    glScalef(0.8, 1.55, 1);
    glutSolidSphere(0.45, 8, 8);
    glPopMatrix();

    // Wajah
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0, 1.55, 0.1);
    glScalef(0.8, 1.15, 1);
    glutSolidSphere(0.35, 8, 8);
    glPopMatrix();
}

void Misc::burung()
{
    glPushMatrix();

    glPopMatrix();
}

Objek* Misc::bunga()
{
    Objek* objek = new Objek();
    Objek* atas = tabung(0.5, 0, 0.3, 8, 0, 0)->flip(0, 1, 0)->setColor(new Color(255, 255, 255));
    Objek* kuncup = tabung(0.2, 0, 0.2)->setColor(new Color(255, 255, 0))->translate(0, -0.15, 0);

    objek->combine(atas);
    objek->combine(kuncup);

    delete atas, kuncup;

    return objek;
}

Objek* Misc::bunga1()
{
    Objek* bunga = new Objek();
    ColorList::kuning()->set(true);
    for(float degree = 0; degree <= 360; degree += (360 / 8)) {
        Vertex* v = new Vertex(0.5, 0, 0);
        v->rotate(degree, 0, 1, 0);
        Objek* mahkota = mahkotaBunga();
        mahkota->rotate(15, 1, 0, 0);
        mahkota->rotate(degree, 0, 1, 0);
        //mahkota->translate(v->x, v->y, v->z);

        bunga->combine(mahkota, true);

        delete v;
    }

    Objek* serbuk1 = tabung(0.3, 0.2, 0.1, 8, 0, 0)->translate(0, 0.1, 0)->setColor(ColorList::batang());
    Objek* serbuk2 = tabung(0.2, 0.08, 0.05, 8, 0, 0)->translate(0, 0.2, 0);
    Objek* serbuk3 = tabung(0.08, 0, 0.02, 8, 0, 0)->translate(0, 0.25, 0);

    bunga->combine(serbuk1);
    bunga->combine(serbuk2);
    bunga->combine(serbuk3);

    delete serbuk1;
    delete serbuk2;
    delete serbuk3;

    return bunga;
}

void Misc::kayuUnggun()
{

    glPushMatrix();
    for(float degree = 0; degree <= 360; degree += (360 / 8)) {
        Vertex* v = new Vertex(0.5, 0, 0);
        v->rotate(degree, 0, 1, 0);

        Objek* objek = nullptr;
        objek = balok(0.1, 0.1, 1);
        objek->rotate(30, 0, 0, 1);
        objek->rotate(degree, 0, 1, 0);
        ColorList::batang()->set(true);
        objek->translate(v->x, v->y, v->z)->draw();

        Vertex* vBatu = new Vertex(0.7, 0, 0);
        vBatu->rotate(degree, 0, 1, 0);
        glPushMatrix();
        glTranslatef(vBatu->x, vBatu->y, vBatu->z);
        batu2();
        glPopMatrix();

        delete v;
        delete vBatu;
    }

    glPopMatrix();
}

void Misc::gapura()
{
    glPushMatrix();
    glTranslatef(0, 4.5, 0);
    glRotatef(90, 1, 0, 0);
    kayuArah();
    glPopMatrix();

    ColorList::batu()->set();
    trapesiumSiku(0.5, 0.5, 0.35, 0.35, 1, 1, 1, 1, 1, 1, 1)->translate(1.5, 0, 0)->draw();
    trapesiumSiku(0.5, 0.5, 0.35, 0.35, 1, 1, 1, 1, 1, 1, 1)->flip(1, 0)->translate(-1.35, 0, 0)->draw();

    ColorList::batang()->set();
    balok(0.25, 0.25, 4, 1, 0, 1, 1, 1, 1)->translate(1.15, 0, 0)->draw();
    balok(0.25, 0.25, 4, 1, 0, 1, 1, 1, 1)->translate(-1.25, 0, 0)->draw();
}

void Misc::pos()
{

}

void Misc::setangkaiBunga1()
{
    bunga1()->scale(0.5, 0.5, 0.5)->rotate(15, 1, 0, 0)->rotate(15, 0, 0, 1)->translate(-0.6, 1.2, 0)->draw();
    batang2()->setColor(ColorList::hijau(1))->scale(0.5, 1, 0.5)->rotate(15, 0, 0, 1)->draw();
}

void Misc::serumpunBunga1()
{
    glPushMatrix();
    glTranslatef(0, 0.15, 0);
    Misc::setangkaiBunga1();
    glPushMatrix();
    glRotatef(120, 0, 1, 0);
    Misc::setangkaiBunga1();
    glPopMatrix();
    glPushMatrix();
    glRotatef(240, 0, 1, 0);
    Misc::setangkaiBunga1();
    glPopMatrix();

    ColorList::hijau(1)->set();
    for(float degree = 0; degree <= 360; degree += (360 / 6)) {
        mahkotaTeratai()->scale(2, 2, 2)->rotate(180, 0, 0, 1)->rotate(45, 1, 0, 0)->rotate(degree, 0, 1, 0)->draw();        
    }
    glPopMatrix();
}

void Misc::bungaTeratai()
{
    for(float degree = 0; degree <= 360; degree += (360 / 10)) {
        Vertex v(0.02, 0, 0);
        v.rotate(degree, 0, 1, 0);
        (new Color(255, 130, 180))->set(true);
        mahkotaTeratai()->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        (new Color(255, 150, 210))->set(true);
        mahkotaTeratai()->scale(0.8, 0.8, 0.8)->rotate(15, 1, 0, 0)->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        (new Color(255, 180, 230))->set(true);
        mahkotaTeratai()->scale(0.7, 0.7, 0.7)->rotate(30, 1, 0, 0)->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        (new Color(255, 200, 255))->set(true);
        mahkotaTeratai()->scale(0.6, 0.6, 0.6)->rotate(45, 1, 0, 0)->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
         ColorList::kuning()->set(true);
        mahkotaTeratai()->scale(0.5, 0.5, 0.5)->rotate(60, 1, 0, 0)->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
        mahkotaTeratai()->scale(0.5, 0.5, 0.5)->rotate(75, 1, 0, 0)->rotate(degree - 90, 0, 1, 0)->translate(v.x, v.y, v.z)->draw();
    }

}

void Misc::jamur(float ukuran, float batang)
{
    Vertex::pushGlobalScale(ukuran, ukuran, ukuran);
    glTranslatef(0, 0.15, 0);
    (new Color(180, 0, 0))->set(true);

    // glPushMatrix();
    // glTranslatef(0, 0.7, 0);
    // atas
    tabung(0.5, 0.4, 0.2, 8, 0, 0)->translate(0, 0.1 + batang, 0)->draw();
    tabung(0.4, 0.25, 0.1, 8, 0, 0)->translate(0, 0.3 + batang, 0)->draw();
    tabung(0.25, 0.1, 0.05, 8, 0, 0)->translate(0, 0.4 + batang, 0)->draw();
    tabung(0.1, 0, 0.025, 8, 0, 0)->translate(0, 0.45 + batang, 0)->draw();

    // bawah
    tabung(0.5, 0.4, 0.1, 8, 1, 0)->flip(0, 1.7, 0)->translate(0,  0.1 + batang, 0)->draw();
    // glPopMatrix();
    (new Color(215, 189, 156))->set(true);
    float tinggi1 = (5.0 / 6.0 * batang);
    float tinggi2 = (1.0 / 6.0 * batang);
    tabung(0.2, 0.1, tinggi1, 8, 0, 0)->translate(0, tinggi2, 0)->draw();
    tabung(0.15, 0.2, tinggi2, 8, 0, 0)->draw();

    Vertex::popGlobalScale();
}

void Misc::blokDanau(float translasiTinggi)
{
    glPushMatrix();
    glTranslatef(0, translasiTinggi, 0);
    persegi(3)->setColor(ColorList::air()->setAlpha(100))->drawNormal();    
    glPopMatrix();
}

void Misc::blokDanauSatuSisi(float translasiTinggi, float translasiArus)
{
    glPushMatrix();
    glTranslatef(0, translasiTinggi, 0);
    Face* obj = persegi(3)->setColor(ColorList::air()->setAlpha(100));
    obj->drawNormal();
    delete obj;
    obj = nullptr;

    glPushMatrix();
    glTranslatef(translasiArus, 0, 0);
    obj = persegi(3)->scale(0.5, 1, 1)->translate(0, 0.001, 0)->setColor(ColorList::putih()->setAlpha(50));
    obj->drawNormal();
    delete obj;
    obj = nullptr;
    obj = persegi(3)->scale(0.4, 1, 1)->translate(0, 0.002, 0)->setColor(ColorList::putih()->setAlpha(50));
    obj->drawNormal();
    delete obj;
    obj = nullptr;
    obj = persegi(3)->scale(0.3, 1, 1)->translate(0, 0.003, 0)->setColor(ColorList::putih()->setAlpha(50));
    obj->drawNormal();
    delete obj;
    obj = nullptr;
    obj = persegi(3)->scale(0.2, 1, 1)->translate(0, 0.004, 0)->setColor(ColorList::putih()->setAlpha(50));
    obj->drawNormal();
    delete obj;
    glPopMatrix();
    glPopMatrix();
}

void Misc::batuKotak()
{
    Vertex::pushGlobalTranslate(0, 0.15, 0);
    trapesiumSamaSisi(1, 1, 1.2, 1.2, 0.5, 0, 1, 1, 1, 1, 1)->draw();
    trapesiumSamaSisi(1.2, 1.2, 1.5, 1.5, 2, 0, 0, 1, 1, 1, 1)->translate(-0.1, 0.5, -0.1)->draw();
    trapesiumSamaSisi(1.5, 1.5, 1.2, 1.2, 2, 0, 0, 1, 1, 1, 1)->translate(-0.25, 2.5, -0.25)->draw();
    trapesiumSamaSisi(1.2, 1.2, 1, 1, 0.5, 1, 0, 1, 1, 1, 1)->translate(-0.1, 4.5, -0.1)->draw();
    Vertex::popGlobalTranslate();
}

void Misc::batuKotak2(float tinggi)
{
    Vertex::pushGlobalTranslate(0, 0.15, 0);
    tabung(tinggi / 1.25, tinggi, tinggi / 8, 6, 0, 1)->draw();
    tabung(tinggi, tinggi, tinggi, 6,  0, 0)->translate(0, tinggi / 8, 0)->draw();
    tabung(tinggi / 1.25, tinggi, tinggi / 8, 6, 0, 1)->flip(0, 1, 0)->translate(0, tinggi + (tinggi / 8 * 2), 0)->draw();
    Vertex::popGlobalTranslate();
}
