#include "Pohon.h"
#include "../Util/Util.h"
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "../Util/Color.h"
#include "../Util/Material.h"
#include "Objek.h"

using namespace std;

GrupObjek* Pohon::Cemara(
    unsigned short int jumlahCemara,
    float tinggiBatang,
    float radiusDasarCemara,
    float jarakCemara,
    float tinggiCemaraDasar)
{
    GrupObjek* pohon = new GrupObjek();
    pohon->addObjek(batangCemara(tinggiBatang, radiusDasarCemara / 5, radiusDasarCemara / 6, 8)->setColor( ColorList::batang()));

    // Membuat cemara
    for (unsigned short int i = 0; i < jumlahCemara; i++)
    {
        float lokasiCemara = tinggiBatang + jarakCemara * i;
        pohon->addObjek(dahanCemara(radiusDasarCemara -= 0.2, tinggiCemaraDasar -= 0.2, 10)->translate(0, lokasiCemara, 0)->setColor(ColorList::hijau(1)));
    }

    return pohon;

}

Objek* Pohon::dahanCemara(float radius, float tinggi, int slices)
{
    Vertex* base = new Vertex(radius, 0, 0);

    Objek* objek = new Objek();

    // Menggambar kerucut
    float kebawah = false;
    float minusIncr = radius / 10;
    for(float degree = 0; degree <= 360; degree += 360 / slices) {
        Face* face = new Face();
        if(kebawah)
            face->addVertex(base->clone()->translate(0, -minusIncr, 0)->rotate(degree, 0, 1 ,0));
        else
            face->addVertex(base->clone()->rotate(degree, 0, 1 ,0));

        if(kebawah)
            face->addVertex(base->clone()->rotate(degree + (360 / slices), 0, 1, 0));
        else
            face->addVertex(base->clone()->translate(0, -minusIncr, 0)->rotate(degree + (360 / slices), 0, 1, 0));

        face->addVertex(0, tinggi, 0);
        objek->addFace(face);

        Face* bawah = new Face();
        bawah->addVertex(face->getVertices()[0].clone());
        bawah->addVertex(face->getVertices()[1].clone());
        bawah->addVertex(new Vertex(0, 0, 0));
        objek->addFace(bawah);

        kebawah = !kebawah;
    }

    delete base;

    return objek;
}

Objek* Pohon::batangCemara(float tinggi, float radiusBawah, float radiusAtas, int slices)
{
    Objek* batang = new Objek();
    if(tinggi >= 0.5) {
        Objek* atas = tabung(radiusAtas, radiusBawah, tinggi / 2, slices, false, false)->translate(0, tinggi / 2, 0);
        batang->combine(atas);
        
        Objek* bawah = tabung(radiusBawah, radiusAtas, tinggi / 2, slices, false, false);
        batang->combine(bawah);
        
        delete atas;
        delete bawah;

        return batang;
    }
    else {
        return tabung(radiusBawah, radiusAtas, tinggi / 2, slices, false, false);
    }
}

GrupObjek* Pohon::Biasa(int jumlahRanting, float tinggiBatang)
{
    GrupObjek* pohon = new GrupObjek();

    pohon->addObjek(batangCemara(((float)2 /(float) 3 * tinggiBatang), 0.6, 0.5, 8)->setColor(ColorList::batang()));
    pohon->addObjek(tabung(0.6, 0.4, ((float)1 / (float) 3 * tinggiBatang) ,8, 0, 0)->translate(0, 4, 0));

    bool turun = true;
    for(float degree = 0; degree <= 360; degree += (360 / jumlahRanting)) {
        Vertex v(0.2, 0, 0);
        v.rotate(degree, 0, 1, 0);
        pohon->addObjek(ranting()->setColor(ColorList::batang())->scale(1, 1, 3)->rotate(25, 1, 0, 0)->translate(0, tinggiBatang - (tinggiBatang / 5) + (turun ? -0.3 : 0), -1.7)->rotate(degree, 0, 1, 0));

        pohon->addObjek(semak()->setColor(ColorList::hijau(1))->translate(0.5, tinggiBatang - (tinggiBatang / 10) + (turun ? -0.3 : 0), -2.5)->rotate(degree, 0, 1, 0));
        turun = !turun;
    }

    pohon->addObjek(semak()->scale(2.5, 2, 2.5)->translate(0, tinggiBatang, 0));

    return pohon;
}

GrupObjek* Pohon::CabangBanyak(int jumlahRanting)
{
    GrupObjek* pohon = new GrupObjek();

    for(float degree = 0; degree <= 360; degree += (360 / jumlahRanting)) {
        pohon->addObjek(batang2()->scale(1.5, 3, 1.5)->rotate(-15, 1, 0, 0)->rotate(degree, 0, 1 ,0)->setColor(ColorList::batang()));
        pohon->addObjek(batang2()->flip(0, 0, 1)->rotate(-15, 0, 1, 0)->translate(-0.7, 3, -0.75)->rotate(degree, 0, 1, 0));
        pohon->addObjek(semak()->setColor(ColorList::hijau(1))->scale(0.75, 0.75, 0.75)->translate(-0.85, 4, -0.85)->rotate(degree, 0, 1, 0));
        pohon->addObjek(semak()->setColor(ColorList::hijau(1))->scale(0.5, 0.5, 0.5)->translate(-0.25, 4.5, -0.4)->rotate(degree, 0, 1, 0));
    }

    return pohon;
}

void Pohon::EsKrim(float tinggiBatang, float tinggiDaun, float radiusDaun)
{
    batangCemara(tinggiBatang * 2, 0.25, 0.2, 8)->setColor(ColorList::batang())->draw();

    semak()->setColor(ColorList::hijau(1))->flip(0, 1, 0)->scale(radiusDaun / 1.5, tinggiDaun / 2, radiusDaun / 1.5)->translate(0, tinggiBatang * 3, 0)->draw();
}

void Pohon::CemaraMati(float scale)
{

}
