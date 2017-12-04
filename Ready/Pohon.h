#ifndef READY_POHON_H
#define READY_POHON_H

#include "../Util/Util.h"
#include "../Objek/Objek.h"
#include "../Objek/Pohon.h"
#include "../Objek/Misc.h"

#define UKURAN_BESAR 0
#define UKURAN_SEDANG 1
#define UKURAN_KECIL 2
#define UKURAN_SANGAT_KECIL 3

void lokasiPohon();
void pohonCemara(int ukuran = UKURAN_BESAR);
void pohonCabangBanyak(int ukuran = UKURAN_BESAR);
void pohonBiasa(int ukuran = UKURAN_BESAR);
void pohonEsKrim(int ukuran = UKURAN_BESAR);

/////////////////////////////////////////////////////////////////////

void lokasiPohon()
{
    glPushMatrix();
    glTranslatef(-28, 0, 40);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-38, 0, 40);
    pohonBiasa();
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-31, 0, 35);
    // pohonCemara();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-35, 0, 31);
    // pohonCemara();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-17, 0, 31);
    // pohonCemara();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-13, 0, 35);
    // pohonCemara();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-13, 0, 19);
    // pohonCemara();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-17, 0, 23);
    // pohonCemara();
    // glPopMatrix();

    glPushMatrix();
    glTranslatef(-19, 0, 19);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-23, 0, 23);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-19, 0, 11);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-23, 0, 7);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17, 0, 7);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13, 0, 7);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, 7);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-11, 0, 11);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, 0, 13);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-11, 0, 17);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 17);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 0, 13);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13, 0, -5);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-17, 0, -1);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 0, -1);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-31, 0, -5);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-31, 0, -11);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 0, -11);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-41, 2.3, 12);
    pohonBiasa(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 2.3, 14);
    pohonEsKrim(UKURAN_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-37, 2.3, 10);
    pohonEsKrim(UKURAN_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-41, 2.6, 8);
    pohonCabangBanyak(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-41, 2.6, 16);
    pohonCabangBanyak(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-41, 1.1, 5);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-41, 1.1, 19);
    pohonCemara();
    glPopMatrix();
}

void pohonCemara(int ukuran)
{
    static GrupObjek* cemaraBesar = nullptr;
    static GrupObjek* cemaraSedang = nullptr;
    static GrupObjek* cemaraKecil = nullptr;
    static GrupObjek* cemaraSangatKecil = nullptr;
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            if(nullptr == cemaraBesar)
                cemaraBesar = (new Pohon())->Cemara(7, 1.5, 2, 1, 3);
            
            cemaraBesar->draw(false);
            break;
        case UKURAN_SEDANG:
            if(nullptr == cemaraSedang)
                cemaraSedang = (new Pohon())->Cemara(5, 1.5, 1.8, 1, 2.8);
            
            cemaraSedang->draw(false);
            break;
        case UKURAN_KECIL:
            if(nullptr == cemaraKecil)
                cemaraKecil = (new Pohon())->Cemara(4, 1, 1.4, 0.75, 2.4);
            
            cemaraKecil->draw(false);
            break;
        case UKURAN_SANGAT_KECIL:
            if(nullptr == cemaraSangatKecil)
                cemaraSangatKecil = (new Pohon())->Cemara(3, 0.75, 1, 0.5, 1.75);

            cemaraSangatKecil->draw(false);
            break;
    }
    glPopMatrix();
}

void pohonCabangBanyak(int ukuran)
{
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            (new Pohon())->CabangBanyak(5)->draw();
            semak()->setColor(ColorList::hijau(1))->scale(0.4, 0.4, 0.4)->translate(0, 5, 0)->draw();
            break;
        case UKURAN_SEDANG:
            (new Pohon())->CabangBanyak(4)->scale(0.75, 0.75, 0.75)->draw();
            semak()->setColor(ColorList::hijau(1))->scale(0.3, 0.3, 0.3)->translate(0, 3.75, 0)->draw();
            break;
        case UKURAN_KECIL:
            (new Pohon())->CabangBanyak(3)->scale(0.5, 0.5, 0.5)->draw();
            break;
        case UKURAN_SANGAT_KECIL:
            (new Pohon())->CabangBanyak(2)->scale(0.25, 0.25, 0.25)->draw();
            break;
    }
    glPopMatrix();
}

void pohonBiasa(int ukuran)
{
    static GrupObjek* besar = nullptr;
    static GrupObjek* sedang = nullptr;
    static GrupObjek* kecil = nullptr;
    static GrupObjek* sangatKecil = nullptr;
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            if(nullptr == besar)
                besar = (new Pohon())->Biasa(8, 6);
            
            besar->draw(false);
            break;
        case UKURAN_SEDANG:
            if(nullptr == sedang)
                sedang = (new Pohon())->Biasa(6, 6)->scale(0.75, 0.75, 0.75);
            
            sedang->draw(false);
            break;
        case UKURAN_KECIL:
            if(nullptr == kecil)
                kecil = (new Pohon())->Biasa(4, 6)->scale(0.5, 0.5, 0.5);

            kecil->draw(false);
            break;
        case UKURAN_SANGAT_KECIL:
            if(sangatKecil == nullptr)
                sangatKecil = (new Pohon())->Biasa(3, 6)->scale(0.25, 0.25, 0.25);

            sangatKecil->draw(false);
            break;
    }
    glPopMatrix();
}

void pohonEsKrim(int ukuran)
{
    static GrupObjek* besar = nullptr;
    static GrupObjek* sedang = nullptr;
    static GrupObjek* kecil = nullptr;
    static GrupObjek* sangatKecil = nullptr;
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            if(nullptr == besar)
                besar = (new Pohon())->EsKrim(1.5, 5, 1.5);
            
            besar->draw(false);
            break;
        case UKURAN_SEDANG:
            if(nullptr == sedang)
                sedang = (new Pohon())->EsKrim(1, 4, 1);
            
            sedang->draw(false);
            break;
        case UKURAN_KECIL:
            if(nullptr == kecil)
                kecil = (new Pohon())->EsKrim(0.7, 3, 0.8);

            kecil->draw(false);
            break;
        case UKURAN_SANGAT_KECIL:
            if(nullptr == sangatKecil)
                sangatKecil = (new Pohon())->EsKrim(0.5, 2, 0.7);

            sangatKecil->draw(false);      
            break;
    }
    glPopMatrix();
}

#endif