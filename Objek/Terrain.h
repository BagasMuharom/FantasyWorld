#ifndef TERRAIN_H
#define TERRAIN_H

#include "Objek.h"

//////////////////////////////////////////////////////////////////
/// File ini merupakan kumpulan fungsi untuk menggambar terrain///
//////////////////////////////////////////////////////////////////

// Konstanta
#define TR_LEFT         0
#define TR_RIGHT        1
#define TR_STRAIGHT     2
#define TR_TJUNCTION    3

Objek* terrainGrass(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainGround(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainRoad(int type, bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainRoadLeft(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainRoadRight(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainRoadStraight(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainRoadTjunction(bool depan = false, bool belakang = false, bool kanan = false, bool kiri = false);

Objek* terrainHill(float tinggi, float panjang, float lebar);

#endif