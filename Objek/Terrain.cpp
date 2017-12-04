#include <iostream>
#include "GL/glut.h"
#include "Objek.h"
#include "../Util/Util.h"
#include "Terrain.h"

// Terrain berupa padang hijau
Objek *terrainGrass(bool depan, bool belakang, bool kanan, bool kiri)
{
    float bawah = 6.3;
    float atas = 6;
    Objek *grass = trapesiumSamaSisi(bawah, bawah, atas, atas, 0.15, 1, 0, depan, belakang, kanan, kiri);
    grass->getFaces()[0]->setColor(ColorList::rumput());
    grass->translate(-3.15, 0, -3.15);

    return grass;
}

Objek *terrainGround(bool depan, bool belakang, bool kanan, bool kiri)
{
    float bawah = 6.3;
    float atas = 6;
    Objek *ground = trapesiumSamaSisi(bawah, bawah, atas, atas, 0.15, 1, 0, depan, belakang, kanan, kiri);
    ground->getFaces()[0]->setColor(ColorList::jalan());
    ground->translate(-3.15, 0, -3.15);

    return ground;
}

Objek *terrainRoad(int type, bool depan, bool belakang, bool kanan, bool kiri)
{
    switch (type)
    {
    case TR_STRAIGHT:
        return terrainRoadStraight(depan, belakang, kanan, kiri);
    case TR_LEFT:
        return terrainRoadLeft(depan, belakang, kanan, kiri);
    case TR_RIGHT:
        return terrainRoadRight(depan, belakang, kanan, kiri);
    case TR_TJUNCTION:
        return terrainRoadTjunction(depan, belakang, kanan, kiri);
    }

    return new Objek();
}

Objek *terrainRoadLeft(bool depan, bool belakang, bool kanan, bool kiri)
{
    Objek *objek = new Objek();
    Face *rumput = new Face();
    rumput->addVertex(Vertex(-3, 0.15, 3))
        ->addVertex(Vertex(-1, 0.15, 3))
        ->addVertex(Vertex(-1, 0.15, 1))
        ->addVertex(Vertex(-3, 0.15, 1));
    rumput->setColor(ColorList::rumput());
    objek->addFace(rumput);

    Face *rumput2 = new Face();
    rumput2->addVertex(Vertex(1, 0.15, 3))
        ->addVertex(Vertex(3, 0.15, 3))
        ->addVertex(Vertex(3, 0.15, -3))
        ->addVertex(Vertex(1, 0.15, -3));
    objek->addFace(rumput2);

    Face *rumput3 = new Face();
    rumput3->addVertex(Vertex(1, 0.15, -3))
        ->addVertex(Vertex(-3, 0.15, -3))
        ->addVertex(Vertex(-3, 0.15, -1))
        ->addVertex(Vertex(1, 0.15, -1));
    objek->addFace(rumput3);

    Face *jalan = new Face();
    jalan->addVertex(Vertex(0.85, 0, 3))
        ->addVertex(Vertex(0.85, 0, -0.85))
        ->addVertex(Vertex(-0.85, 0, -0.85))
        ->addVertex(Vertex(-0.85, 0, 3));
    jalan->setColor(ColorList::jalan());
    objek->addFace(jalan);

    Face *jalan2 = new Face();
    jalan2->addVertex(Vertex(0.85, 0, 0.85))
        ->addVertex(Vertex(0.85, 0, -0.85))
        ->addVertex(Vertex(-3, 0, -0.85))
        ->addVertex(Vertex(-3, 0, 0.85));
    objek->addFace(jalan2);

    Face *bahu1 = new Face();
    bahu1->addVertex(Vertex(0.85, 0, 3))
        ->addVertex(Vertex(1, 0.15, 3))
        ->addVertex(Vertex(1, 0.15, -1))
        ->addVertex(Vertex(0.85, 0, -0.85));
    bahu1->setColor(new Color(170, 183, 81));
    objek->addFace(bahu1);

    Face *bahu2 = new Face();
    bahu2->addVertex(Vertex(1, 0.15, -1))
        ->addVertex(Vertex(0.85, 0, -0.85))
        ->addVertex(Vertex(-3, 0, -0.85))
        ->addVertex(Vertex(-3, 0.15, -1));
    objek->addFace(bahu2);

    Face *bahu3 = new Face();
    bahu3->addVertex(Vertex(-0.85, 0, 3))
        ->addVertex(Vertex(-1, 0.15, 3))
        ->addVertex(Vertex(-1, 0.15, 1))
        ->addVertex(Vertex(-0.85, 0, 0.85));
    objek->addFace(bahu3);

    Face *bahu4 = new Face();
    bahu4->addVertex(Vertex(-1, 0.15, 1))
        ->addVertex(Vertex(-0.85, 0, 0.85))
        ->addVertex(Vertex(-3, 0, 0.85))
        ->addVertex(Vertex(-3, 0.15, 1));
    objek->addFace(bahu4);

    return objek;
}

Objek *terrainRoadRight(bool depan, bool belakang, bool kanan, bool kiri)
{
    Objek *objek = terrainRoadLeft(depan, belakang, kanan, kiri);
    objek->flip(1, 0);

    return objek;
}

Objek *terrainRoadStraight(bool depan, bool belakang, bool kanan, bool kiri)
{
    Objek *objek = new Objek();
    Face *face = new Face();
    face->addVertex(Vertex(-1, 0.15, 3))
        ->addVertex(Vertex(-1, 0.15, -3))
        ->addVertex(Vertex(-3, 0.15, -3))
        ->addVertex(Vertex(-3, 0.15, 3));

    Face *road = new Face();
    road->addVertex(Vertex(0.85, 0, 3))
        ->addVertex(Vertex(0.85, 0, -3))
        ->addVertex(Vertex(-0.85, 0, -3))
        ->addVertex(Vertex(-0.85, 0, 3));
    road->setColor(ColorList::jalan());

    Face *bahuJalan = new Face();
    bahuJalan->addVertex(Vertex(0.85, 0, 3))
        ->addVertex(Vertex(1, 0.15, 3))
        ->addVertex(Vertex(1, 0.15, -3))
        ->addVertex(Vertex(0.85, 0, -3));
    bahuJalan->setColor(new Color(170, 183, 81));

    face->setColor(ColorList::rumput());

    objek->addFace(face);
    objek->addFace(face->clone()->flip(1, 0));
    objek->addFace(road);
    objek->addFace(bahuJalan);
    objek->addFace(bahuJalan->clone()->flip(1, 0));

    return objek;
}

Objek *terrainRoadTjunction(bool depan, bool belakang, bool kanan, bool kiri)
{
    Objek *objek = new Objek();
    Face *rumput = new Face();
    rumput->addVertex(Vertex(2, 0.15, 3))
        ->addVertex(Vertex(2, 0.15, 1))
        ->addVertex(Vertex(0, 0.15, 1))
        ->addVertex(Vertex(0, 0.15, 3));

    objek->addFace(rumput->clone()->translate(-3, 0, 0)->setColor(ColorList::rumput()));
    objek->addFace(rumput->clone()->translate(1, 0, 0));
    objek->addFace(rumput->clone()->translate(1, 0, -4));
    objek->addFace(rumput->clone()->translate(-1, 0, -4));
    objek->addFace(rumput->clone()->translate(-3, 0, -4));

    delete rumput;

    Face *jalanKecil = new Face();
    jalanKecil->addVertex(Vertex(0.85, 0, 3))
        ->addVertex(Vertex(0.85, 0, 0.85))
        ->addVertex(Vertex(-0.85, 0, 0.85))
        ->addVertex(Vertex(-0.85, 0, 3))
        ->setColor(ColorList::jalan());
    objek->addFace(jalanKecil);

    Face *jalanBesar = new Face();
    jalanBesar->addVertex(Vertex(-3, 0, 0.85))
        ->addVertex(Vertex(3, 0, 0.85))
        ->addVertex(Vertex(3, 0, -0.85))
        ->addVertex(Vertex(-3, 0, -0.85));
    objek->addFace(jalanBesar);

    Face *bahu1 = new Face();
    bahu1->addVertex(Vertex(-0.85, 0, 3))
        ->addVertex(Vertex(-1, 0.15, 3))
        ->addVertex(Vertex(-1, 0.15, 1))
        ->addVertex(Vertex(-0.85, 0, 0.85))
        ->setColor(new Color(170, 183, 81));
    objek->addFace(bahu1);
    objek->addFace(bahu1->clone()->flip(1, 0));

    Face *bahu2 = new Face();
    bahu2->addVertex(Vertex(-1, 0.15, 1))
        ->addVertex(Vertex(-0.85, 0, 0.85))
        ->addVertex(Vertex(-3, 0, 0.85))
        ->addVertex(Vertex(-3, 0.15, 1));
    objek->addFace(bahu2);
    objek->addFace(bahu2->clone()->flip(1, 0));

    Face *bahu3 = new Face();
    bahu3->addVertex(Vertex(3, 0, -0.85))
        ->addVertex(Vertex(3, 0.15, -1))
        ->addVertex(Vertex(-3, 0.15, -1))
        ->addVertex(Vertex(-3, 0, -0.85));
    objek->addFace(bahu3);

    return objek;
}

Objek* terrainHill(float tinggi, float panjang, float lebar)
{
    Objek* objek = trapesiumSamaSisi(panjang + 0.3, lebar + 0.3, panjang, lebar, tinggi, 1, 0, 1, 1, 1, 1);
    objek->getFaces()[0]->setColor(ColorList::rumput());
    objek->translate(-(panjang + 0.3) / 2, 0, -(lebar + 0.3) / 2);

    return objek;
}