#ifndef READY_SEMAK_H
#define READY_SEMAK_H

#include "../Util/Util.h"
#include "../Objek/Objek.h"
#include "../Util/Color.h"

void lokasiSemak();
void semakSemak();
GrupObjek* semakBesar();
GrupObjek* semakKecil();
GrupObjek* semakSedang();

void lokasiSemak()
{
    glPushMatrix();
    glTranslatef(4, 0, 0);
    semakSemak();
    glPopMatrix();
}

void semakSemak()
{
    semakBesar()->scale(1.25, 1, 1.25)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(1, 0, 0.6)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(-1, 0, 0.6)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(-0.975, 0, -0.375)->draw();
    semakKecil()->translate(0.375, 0, 0.975)->draw();
    semakKecil()->translate(-0.375, 0, -0.95)->draw();
    semakKecil()->translate(1, 0, -0.15)->draw();
}

GrupObjek* semakBesar()
{
    GrupObjek* semakObjek = new GrupObjek();
    semakObjek->addObjek(semak()->translate(0, 0.9, 0)->setColor(ColorList::hijau(1)));
    semakObjek->addObjek(semak()->scale(0.15, 0.15, 0.15)->translate(0.5, 1.2, 0.75)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.15, 0.15, 0.15)->translate(0, 1.8, 0)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.08, 0.08, 0.08)->translate(-0.55, 1.4, 0.8)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.08, 0.08, 0.08)->translate(0.4, 1.4, -0.7)->setColor(new Color(200, 0, 0)));

    return semakObjek->scale(0.75, 0.75, 0.75);
}

GrupObjek* semakKecil()
{
    return semakBesar()->rotate(-45, 0, 1, 0)->scale(0.5, 0.5, 0.5);
}

GrupObjek* semakSedang()
{
    return semakBesar()->rotate(180, 0, 1, 0)->scale(0.75, 0.75, 0.75);
}

#endif