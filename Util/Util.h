#ifndef UTIL_H
#define UTIL_H

#include "GL/glut.h"
#include "Color.h"
#include <vector>
#include <math.h>
#include <array>

class Vector3
{
  public:
    Vector3();
    Vector3(float x, float y, float z);
    float x, y, z;
};

class Vertex : public Vector3
{
  public:
    Vertex(float x, float y, float z);
    Vertex(Vector3 &vector);
    Vertex();
    static void pushGlobalScale(float x, float y, float z);
    static void popGlobalScale();
    static void pushGlobalTranslate(float x, float y, float z);
    static void popGlobalTranslate();
    Vertex *translate(float x, float y, float z);
    Vertex *rotate(float degree, bool x, bool y, bool z, float a = 0, float b = 0, float c = 0);
    Vertex *flip(bool horizontal, bool vertical);
    Vertex *clone();
    Vertex *reset();
    Vertex *flip(bool x, bool y, bool z);
    Vertex *scale(float scaleX, float scaleY, float scaleZ);
    void drawNormalVertex();
    void drawVertex();
    ~Vertex();

  private:
    static vector<array<float, 3>> stackScale;
    static vector<array<float, 3>> stackTranslate;
    static float globalScaleX, globalScaleY, globalScaleZ;
    static float globalTranslateX, globalTranslateY, globalTranslateZ;
    static bool useGlobalTranslate;
    float realX, realY, realZ;
    void rotateX(float degree, float a, float b, float c);
    void rotateY(float degree, float a, float b, float c);
    void rotateZ(float degree, float a, float b, float c);
};

class Face
{
  public:
    Face();
    Face(std::vector<Vertex> vertices);
    Face *flip(bool horizontal, bool vertical);
    Face *flip(bool x, bool y, bool z);
    const void drawFace();
    const void drawNormal();
    Face *translate(float x, float y, float z);
    Face *addVertex(Vertex vertex);
    Face *addVertex(float x, float y, float z);
    Face *addVertex(float *vertex);
    Face *addVertex(Vertex *vertex);
    Face *rotate(float degree, bool x, bool y, bool z);
    Face *setColor(Color *color);
    Face *scale(float scaleX, float scaleY, float scaleZ);
    Color *getColor();
    Face *clone();
    Face *reset();
    ~Face();
    std::vector<Vertex> getVertices();

  private:
    std::vector<Vertex> vertices;
    Color *color = nullptr;
};

class Objek
{

  public:
    Objek();
    Objek *addFace(Face *face);
    Objek *translate(float x, float y, float z);
    Objek *flip(bool horizontal, bool vertical);
    Objek *flip(bool x, bool y, bool z);
    Objek *rotate(float degree, bool x, bool y, bool z);
    Objek *scale(float scaleX, float scaleY, float scaleZ);
    Objek* deleteFace(int index);
    Objek *clone();
    Objek *reset();
    Objek *combine(Objek* objek, bool autoDelete = false);
    void printFacesMemory();
    Objek *setColor(Color *color);
    vector<Face *> getFaces();
    void draw(bool autoDelete = true);
    ~Objek();

  protected:
    vector<Face *> faces;
};

class GrupObjek
{
  public:
    GrupObjek();
    GrupObjek *addObjek(Objek *objek);
    GrupObjek *translate(float x, float y, float z);
    GrupObjek *flip(bool horizontal, bool vertical);
    GrupObjek *flip(bool x, bool y, bool z);
    GrupObjek *rotate(float degree, bool x, bool y, bool z);
    GrupObjek *scale(float scaleX, float scaleY, float scaleZ);
    GrupObjek *clone();
    GrupObjek* reset();
    GrupObjek *addGrupObjek(GrupObjek* grupObjek);
    vector<Objek*> getObjek();
    void draw(bool autoDelete = true);
    ~GrupObjek();

  protected:
    vector<Objek *> daftarObjek;
};

// Function

Face* persegi(float sis);

Objek *kubus(float sisi, bool atas = true, bool bawah = true, bool depan = true, bool belakang = true, bool kanan = true, bool kiri = true);

Objek *balok(float panjang, float lebar, float tinggi, bool atas = true, bool bawah = true, bool depan = true, bool belakang = true, bool kanan = true, bool kiri = true);

Objek *trapesiumSiku(float panjangBawah, float lebarBawah, float panjangAtas, float lebarAtas, float tinggi, bool atas = true, bool bawah = true, bool depan = true, bool belakang = true, bool kanan = true, bool kiri = true);

Objek *trapesiumSamaSisi(float panjangBawah, float lebarBawah, float panjangAtas, float lebarAtas, float tinggi, bool atas = true, bool bawah = true, bool depan = true, bool belakang = true, bool kanan = true, bool kiri = true);

Objek *tabung(float radiusBawah, float radiusAtas, float tinggi, int slices = 8, bool atas = true, bool bawah = true);

Objek *from2Dto3D(Face *face, float scale);

float toRad(float degree);

void normalize(float *v);

float *cross_product(float *a, float *b);

float *calculate_normal(float *a, float *b, float *c);

#endif
