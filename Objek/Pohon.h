#ifndef POHON_H
#define POHON_H

#include "../Util/Util.h"

class Pohon {

public:
    GrupObjek* Cemara(
        unsigned short int jumlahCemara,
        float tinggiBatang,
        float radiusDasarCemara,
        float jarakCemara,
        float tinggiCemaraDasar);
    static void CemaraMati(float scale = 1);
    GrupObjek* Biasa(int jumlahRanting, float tinggiBatang);
    GrupObjek* CabangBanyak(int jumlahRanting);
    void EsKrim(float tinggiBatang, float tinggiDaun, float radiusDaun);

private:
    Objek* dahanCemara(float radius, float tinggi, int slices);
    Objek* batangCemara(float tinggi, float radiusBawah, float radiusAtas, int slices);

};

#endif
