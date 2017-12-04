#ifndef READY_DANAU_H
#define READY_DANAU_H

#include <array>
#include "GL/glut.h"
#include "../Util/Util.h"
#include "../Objek/Misc.h"

using namespace std;

// Untuk keperluan danau

float minTinggi = 0;
float maxTinggi = 0.15;
float minTranslasiArus = -0.2;
float maxTranslasiArus = 0.3;
float translasiArus = minTranslasiArus;
float translasiTinggi = minTinggi; 
float penambahanTranslasiArus = 0.025;
float penambahanTranslasiTinggi = 0.01;

bool tambahTranslasiArus = true;
bool tambahTranslasiTinggi = true;

void idleDanau()
{
    if(tambahTranslasiArus && translasiArus + penambahanTranslasiArus > maxTranslasiArus)
        tambahTranslasiArus = !tambahTranslasiArus;
    
    if(!tambahTranslasiArus && translasiArus - penambahanTranslasiArus < minTranslasiArus)
        tambahTranslasiArus = !tambahTranslasiArus;

    if(tambahTranslasiArus)
        translasiArus += penambahanTranslasiArus;
    else
        translasiArus -= penambahanTranslasiArus;
    
    if(tambahTranslasiTinggi && translasiTinggi + penambahanTranslasiTinggi > maxTinggi)
        tambahTranslasiTinggi = !tambahTranslasiTinggi;
    
    if(!tambahTranslasiTinggi && translasiTinggi - penambahanTranslasiTinggi < minTinggi)
        tambahTranslasiTinggi = !tambahTranslasiTinggi;

    if(tambahTranslasiTinggi)
        translasiTinggi += penambahanTranslasiTinggi;
    else
        translasiTinggi -= penambahanTranslasiTinggi;
}

void airDanau()
{
    array<array<float, 2>, 12> satuSisiKiri = {{
        {12, -6},
        {12, -3},
        {12, 0},
        {12, 3},
        {12, 6},
        {12, 9},
        {12, 12},
        {15, 15}, 
        {18, 18},
        {12, -9},
        {15, -12},
        {18, -15}
    }};

    for(auto &sisiKiri : satuSisiKiri) {
        glPushMatrix();
        glTranslatef(sisiKiri[0], -0.25, sisiKiri[1]);
        Misc::blokDanauSatuSisi(translasiTinggi, translasiArus);
        glPopMatrix();
    }

    array<array<float, 2>, 10> satuSisiKanan = {{
        {21, -15},
        {21, -18},
        {21, -9},
        {21, -12},
        {21, 18},
        {21, 21},
        {21, 6},
        {21, 9},
        {21, 12},
        {21, 15},
    }};

    for(auto &sisiKiri : satuSisiKanan) {
        glPushMatrix();
        glTranslatef(sisiKiri[0] + 3, -0.25, sisiKiri[1] + 3);
        glRotatef(180, 0, 1, 0);
        Misc::blokDanauSatuSisi(translasiTinggi, translasiArus);
        glPopMatrix();
    }

    // Level 2
    array<array<float, 2>, 28> air = {{
        {18,  -9},
        {18,  -6},
        {15, -6},
        {15,  -3},
        {15,  0},
        {15,  3},
        {15,  6},
        {15,  9},
        {18,  0},
        {18,  3},
        {18,  6},
        {18,  9},
        {18,  12},
        {18,  -3},
        {21,  0},
        {21,  -3},
        {24,  -3},
        {24,  0},
        {18, -12},
        {15, -9},
        {24, -3},
        {24, -6},
        {21, -6},
        {24, 0},
        {24, 3},
        {21, 3},
        {15, 12},
        {18, 15}
    }};

    for(auto &arr : air) {
        glPushMatrix();
        glTranslatef(arr[0], -0.25, arr[1]);
        Misc::blokDanau(translasiTinggi);
        glPopMatrix();
    }
}

void danau()
{
    ColorList::coklatMuda()->set(true);

    // Level 1
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(12, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(15, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(15, -0.6, -12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(18, -0.6, -12)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(18, -0.6, -15)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -15)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 1, 1)->translate(21, -0.6, -18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, -3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, -3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(21, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -12)->draw();

    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 0)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6,  9)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(12, -0.6,  12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(15, -0.6,  12)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(15, -0.6,  15)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(18, -0.6,  15)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(18, -0.6,  18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6,  18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 1, 1, 1)->translate(21, -0.6,  21)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, 0)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(21, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 15)->draw();

    // Level 2
    balok(3, 3, 1, 0, 1, 1, 0, 1, 1)->translate(18, -1.6, -9)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, -6)->draw();
    balok(3, 3, 1, 0, 1, 1, 0, 0, 1)->translate(15, -1.6, -6)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, -3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 6)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 0, 1)->translate(15, -1.6, 9)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 0)->translate(18, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 6)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 9)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 1, 1)->translate(18, -1.6, 12)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 0)->translate(18, -1.6, -3)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 1, 0)->translate(21, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 1, 0, 1, 0)->translate(21, -1.6, -3)->draw();
}

void tembelanDanau()
{
    ColorList::rumput()->set(true);
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 21)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, 21)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(17.85, 0, 21)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 18)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, 18)->draw();

    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 15)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -18.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, -18.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(17.85, 0, -18.15)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -15.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, -15.15)->draw();

    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -12.15)->draw();
}

#endif