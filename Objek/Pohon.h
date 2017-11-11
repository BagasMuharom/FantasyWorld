#ifndef POHON_H
#define POHON_H

#include "../Util/Util.h"

class Pohon {

public:
    static void Cemara(
        unsigned short int jumlahCemara,
        float tinggiBatang,
        float radiusDasarCemara,
        float jarakCemara,
        float tinggiCemaraDasar);

private:
    static void cemara(float radius, float tinggi, int slices);
    static void batangCemara(float tinggi, float radiusBawah, float radiusAtas, int slices);

};

#endif