#include "Util.h"
#include "GL/glut.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <array>

using namespace std;

Vector3::Vector3(){}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vertex::globalScaleX = -1;
float Vertex::globalScaleY = -1;
float Vertex::globalScaleZ = -1;
bool Vertex::useGlobalTranslate = false;
float Vertex::globalTranslateX = 0;
float Vertex::globalTranslateY = 0;
float Vertex::globalTranslateZ = 0;
vector<array<float, 3>> Vertex::stackScale(1, {1, 1, 1});
vector<array<float, 3>> Vertex::stackTranslate(1, {0, 0, 0});

Vertex::Vertex() {}

Vertex::Vertex(float x, float y, float z) : Vector3(x, y, z){
    this->realX = x;
    this->realY = y;
    this->realZ = z;
}

Vertex::Vertex(Vector3 &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

Vertex* Vertex::translate(float x, float y, float z)
{
    this->x += x;
    this->y += y;
    this->z += z;

    return this;
}

Vertex* Vertex::scale(float scaleX, float scaleY, float scaleZ)
{
    this->x *= scaleX;
    this->y *= scaleY;
    this->z *= scaleZ;
}

Vertex* Vertex::rotate(float degree, bool x, bool y, bool z, float a, float b, float c)
{

    if(x)
        this->rotateX(degree, a, b, c);
    if(y)
        this->rotateY(degree, a, b, c);
    if(z)
        this->rotateZ(degree, a, b, c);

    return this;
}

void Vertex::rotateX(float degree, float a, float b, float c)
{
    float tempX = 0, tempY = 0, tempZ = 0;

    tempX = this->x + a;
    tempY = this->y * cos(toRad(degree)) + (-1 * this->z * sin(toRad(degree))) + b;
    tempZ = this->y * sin(toRad(degree)) + this->z * cos(toRad(degree)) + c;

    this->x = tempX;
    this->y = tempY;
    this->z = tempZ;
}

void Vertex::rotateY(float degree, float a, float b, float c)
{
    float tempX = 0, tempY = 0, tempZ = 0;

    tempX = this->x * cos(toRad(degree)) + this->z * sin(toRad(degree)) + a;
    tempY = this->y + b;
    tempZ = this->x * -1 * sin(toRad(degree)) + this->z * cos(toRad(degree)) + c;

    this->x = tempX;
    this->y = tempY;
    this->z = tempZ;
}

void Vertex::rotateZ(float degree, float a, float b, float c)
{
    float tempX = 0, tempY = 0, tempZ = 0;

    tempX = this->x * cos(toRad(degree)) + (-1 * this->y * sin(toRad(degree))) + a;
    tempY = this->x * sin(toRad(degree)) + this->y * cos(toRad(degree)) + b;
    tempZ = this->z + c;

    this->x = tempX;
    this->y = tempY;
    this->z = tempZ;
}

Vertex* Vertex::reset()
{
    this->x = this->realX;
    this->y = this->realY;
    this->z = this->realZ;

    return this;
}

Vertex* Vertex::flip(bool horizontal, bool vertical)
{
    if(horizontal)
        this->x  = - this->x;
    if(vertical)
        this->y = - this->y;

    return this;
}

Vertex* Vertex::flip(bool xy, bool xz, bool yz)
{
    if(xy) {
        this->z = -this->z;
    }
    if(xz) {
        this->y = -this->y;
    }
    if(yz) {
        this->x = -this->x;
    }

    return this;
}

void Vertex::pushGlobalScale(float x, float y, float z)
{
    Vertex::stackScale.push_back({x, y, z});
}

void Vertex::popGlobalScale()
{
    Vertex::stackScale.pop_back();
}

void Vertex::pushGlobalTranslate(float x, float y, float z)
{
    Vertex::stackTranslate.push_back({x, y, z});
}

void Vertex::popGlobalTranslate()
{
    Vertex::stackTranslate.pop_back();
}

Vertex* Vertex::clone()
{
    return new Vertex(this->x, this->y, this->z);
}

void Vertex::drawNormalVertex()
{
    glNormal3f(this->x, this->y, this->z);
    glVertex3f(this->x, this->y, this->z);
}

void Vertex::drawVertex()
{
    if(Vertex::stackScale.size() > 0) {
        for(auto &vertex : Vertex::stackScale) {
            this->scale(vertex[0], vertex[1], vertex[2]);
        }
    }

    if(Vertex::stackTranslate.size() > 0) {
        for(auto &vertex : Vertex::stackTranslate) {
            this->translate(vertex[0], vertex[1], vertex[2]);
        }
    }

    glVertex3f(this->x, this->y, this->z);
}

Vertex::~Vertex()
{
    // cout << "Vertex deleted" << endl;
}

/**
 * Face Class
 */

Face::Face()
{

}

Face::Face(std::vector<Vertex> vertices)
{
    for(int i = 0; i < vertices.size(); i++)
        this->vertices.push_back(vertices[i]);
}

Face* Face::addVertex(Vertex vertex)
{
    this->vertices.push_back(vertex);

    return this;
}

Face* Face::addVertex(float x, float y, float z)
{
    this->addVertex(Vertex(x, y, z));

    return this;
}

Face* Face::addVertex(Vertex* vertex)
{
    this->addVertex(
        vertex->x,
        vertex->y,
        vertex->z
    );

    delete vertex;

    return this;
}

Face* Face::addVertex(float *vertex)
{
    this->addVertex(Vertex(*vertex, *(vertex + 1), *(vertex + 2)));

    return this;
}

Face* Face::flip(bool horizontal, bool vertical)
{
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].flip(horizontal, vertical);

    return this;
}

Face* Face::flip(bool xy, bool xz, bool yz)
{
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].flip(xy, xz, yz);

    return this;
}

Face* Face::translate(float x, float y, float z)
{
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].translate(x, y, z);

    return this;
}

Face* Face::setColor(Color* color) {
    this->color = color;

    return this;
}

Color* Face::getColor() {
    return this->color;
}

const void Face::drawFace()
{
    if(this->color != nullptr)
        this->color->set();

    glBegin(GL_POLYGON);
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].drawVertex();
    glEnd();
}

const void Face::drawNormal()
{
    if(this->color != nullptr)
        this->color->set(false);

    glBegin(GL_POLYGON);
    if(this->vertices.size() >= 3) {
        float a[] = {this->vertices[0].x, this->vertices[0].y, this->vertices[0].z};
        float b[] = {this->vertices[1].x, this->vertices[1].y, this->vertices[1].z};
        float c[] = {this->vertices[2].x, this->vertices[2].y, this->vertices[2].z};
        float* calc = calculate_normal(a, b, c);

        glNormal3fv(calc);

        delete calc;
    }

    for(int i = 0; i < this->vertices.size(); i++) {
        this->vertices[i].drawVertex();
    }

    glEnd();
}

Face* Face::clone()
{
    Face* temp = new Face();
    for(int i = 0; i < this->vertices.size(); i++)
        temp->addVertex(Vertex(this->vertices[i].x, this->vertices[i].y, this->vertices[i].z));

    if(this->color != nullptr)
        temp->setColor(this->color);

    return temp;
}

Face* Face::reset()
{
    for(int i = 1; i <= this->vertices.size(); i++)
        this->vertices[i].reset();

    return this;
}

Face* Face::rotate(float degree, bool x, bool y, bool z)
{
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].rotate(degree, x, y, z);

    return this;
}

Face* Face::scale(float scaleX, float scaleY, float scaleZ)
{
    for(int i = 0; i < this->vertices.size(); i++)
        this->vertices[i].scale(scaleX, scaleY, scaleZ);

    return this;
}

std::vector<Vertex> Face::getVertices()
{
    return this->vertices;
}

Face::~Face()
{
    if(this->color != nullptr)
        delete this->color;

    this->vertices.clear();

    // cout << "Face deleted" << endl;
}

Objek::Objek()
{

}

Objek* Objek::addFace(Face* face)
{
    this->faces.push_back(face);

    return this;
}

Objek* Objek::deleteFace(int index)
{
    Face* face = this->faces[index];

    this->faces.erase(this->faces.begin() + index);

    delete face;
}

Objek* Objek::combine(Objek* objek, bool autoDelete)
{
    vector<Face*> daftarFaces = objek->getFaces();
    for(int i = 0; i < daftarFaces.size(); i++) {
        this->addFace(daftarFaces[i]->clone());
    }

    if(autoDelete)
        delete objek;

    return this;
}

void Objek::draw(bool autoDelete)
{
    for(int i = 0; i < this->faces.size(); i++)
        this->faces[i]->drawNormal();

    if(autoDelete)
        delete this;
}

Objek* Objek::translate(float x, float y, float z)
{
    for(int i = 0; i < this->faces.size(); i++)
        this->faces[i]->translate(x, y, z);

    return this;
}

Objek* Objek::clone()
{
    Objek* objek = new Objek();
    for(int i = 0; i < this->faces.size(); i++)
        objek->addFace(this->faces[i]->clone());

    return objek;
}

Objek* Objek::flip(bool horizontal, bool vertical)
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
        this->faces[i]->flip(horizontal, vertical);

    return this;
}

Objek* Objek::flip(bool xy, bool xz, bool yz)
{
    for(int i = 0; i < this->faces.size(); i++)
        this->faces[i]->flip(xy, xz, yz);

    return this;
}

Objek* Objek::rotate(float degree, bool x, bool y, bool z)
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
        this->faces[i]->rotate(degree, x, y, z);

    return this;
}

Objek* Objek::scale(float scaleX, float scaleY, float scaleZ)
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
        this->faces[i]->scale(scaleX, scaleY, scaleZ);

    return this;
}

Objek* Objek::setColor(Color* color)
{
    this->faces[0]->setColor(color);

    return this;
}

Objek* Objek::reset()
{
    for(unsigned int i = 0; i < this->faces.size(); i++)
        this->faces[i]->reset();

    return this;
}

vector<Face*> Objek::getFaces()
{
    return this->faces;
}

void Objek::printFacesMemory()
{
    for(int i = 0; i < this->faces.size(); i++)
        cout << "Face " << i << " : " << this->faces[i] << endl;
}

Objek::~Objek()
{
    for(int i = this->faces.size() - 1; i >= 0; i--) {
        Face* temp = this->faces[i];
        this->faces.pop_back();
        delete temp;
    }

}

/////////////////////
// GrupObjek
/////////////////////

GrupObjek::GrupObjek() {}

GrupObjek* GrupObjek::addObjek(Objek* objek)
{
    this->daftarObjek.push_back(objek);
}

GrupObjek* GrupObjek::translate(float x, float y, float z)
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->translate(x, y, z);

    return this;
}

GrupObjek* GrupObjek::flip(bool horizontal, bool vertical)
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->flip(horizontal, vertical);

    return this;
}

GrupObjek* GrupObjek::flip(bool xy, bool xz, bool yz)
{
    for(int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->flip(xy, xz, yz);

    return this;
}

GrupObjek* GrupObjek::rotate(float degree, bool x, bool y, bool z)
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->rotate(degree, x, y, z);

    return this;
}

GrupObjek* GrupObjek::scale(float scaleX, float scaleY, float scaleZ)
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->scale(scaleX, scaleY, scaleZ);

    return this;
}

GrupObjek* GrupObjek::clone()
{
    GrupObjek* cloning = new GrupObjek();

    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        cloning->addObjek(this->daftarObjek[i]->clone());

    return cloning;
}

GrupObjek* GrupObjek::reset()
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->reset();

    return this;
}

GrupObjek* GrupObjek::addGrupObjek(GrupObjek* grupObjek)
{
    vector<Objek*> daftarObjek = grupObjek->getObjek();
    for(unsigned int i = 0; i < daftarObjek.size(); i++)
        this->addObjek(daftarObjek[i]->clone());

    return this;
}

vector<Objek*> GrupObjek::getObjek()
{
    return this->daftarObjek;
}

void GrupObjek::draw(bool autoDelete)
{
    for(unsigned int i = 0; i < this->daftarObjek.size(); i++)
        this->daftarObjek[i]->draw(false);

    if(autoDelete)
        delete this;
}

GrupObjek::~GrupObjek()
{
    for(int i = this->daftarObjek.size() - 1; i >= 0; i--) {
        Objek* objek = this->daftarObjek[i];
        // cout << "Alamat faces : " << endl;
        // for(int j = 0; j < this->daftarObjek[i]->getFaces().size(); j ++) {
        //     cout << this->daftarObjek[i]->getFaces()[j] << endl;
        // }
    //    cout << " end Alamat faces" << endl;
        this->daftarObjek.pop_back();
        // cout << objek << endl;
        delete objek;
    }
}


////////////
// Function
////////////

Face* persegi(float sisi)
{
    float vertices[][3] = {
        {0, 0, 0},
        {0, 0, sisi},
        {sisi, 0, sisi},
        {sisi, 0, 0}
    };

    Face* persegi = new Face();

    for(auto &vertex : vertices) {
        persegi->addVertex(vertex);
    }

    return persegi;
}

Objek* kubus(float sisi, bool atas, bool bawah, bool depan, bool belakang, bool kanan, bool kiri)
{
    return balok(sisi, sisi, sisi, atas, bawah, depan, belakang, kanan, kiri);
}

Objek* balok(float panjang, float lebar, float tinggi, bool atas, bool bawah, bool depan, bool belakang, bool kanan, bool kiri)
{
    float vertices[][3] = {
        // 0
        {0, 0, 0},
        // 1
        {panjang, 0, 0},
        // 2
        {panjang, 0, lebar},
        // 3
        {0, 0, lebar},
        // 4
        {0, tinggi, 0},
        // 5
        {panjang, tinggi, 0},
        // 6
        {panjang, tinggi, lebar},
        // 7
        {0, tinggi, lebar}
    };

    vector<array<int, 4>> indexVertices;

    if(atas)
        indexVertices.push_back({4, 5, 6, 7});
    if(bawah)
        indexVertices.push_back({0, 1, 2, 3});
    if(kanan)
        indexVertices.push_back({5, 1, 2, 6});
    if(kiri)
        indexVertices.push_back({0, 4, 7, 3});
    if(depan)
        indexVertices.push_back({0, 4, 5, 1});
    if(belakang)
        indexVertices.push_back({3, 2, 6, 7});

    Objek* objek = new Objek();
    for(auto &a : indexVertices) {
        Face* face = new Face();
        for(auto &b : a) {
            face->addVertex(vertices[b]);
        }
        objek->addFace(face);
    }

    return objek;
}

Objek* trapesiumSiku(float panjangBawah, float lebarBawah, float panjangAtas, float lebarAtas, float tinggi, bool atas, bool bawah, bool depan, bool belakang, bool kanan, bool kiri)
{
    float selisihPanjang = 0;
    float selisihLebar = 0;

    float vertices[][3] = {
        // 0
        {0, 0, 0},
        // 1
        {panjangBawah, 0, 0},
        // 2
        {panjangBawah, 0, lebarBawah},
        // 3
        {0, 0, lebarBawah},
        // 4
        {selisihPanjang, tinggi, selisihLebar},
        // 5
        {panjangAtas + selisihPanjang, tinggi, selisihLebar},
        // 6
        {panjangAtas + selisihPanjang, tinggi, lebarAtas + selisihLebar},
        // 7
        {selisihPanjang, tinggi, lebarAtas + selisihLebar},
    };

    vector<array<int, 4>> indexVertices;

    if(atas)
        indexVertices.push_back({4, 5, 6, 7});
    if(bawah)
        indexVertices.push_back({0, 1, 2, 3});
    if(kanan)
        indexVertices.push_back({6, 2, 1, 5});
    if(kiri)
        indexVertices.push_back({0, 4, 7, 3});
    if(depan)
        indexVertices.push_back({0, 1, 5, 4});
    if(belakang)
        indexVertices.push_back({7, 6, 2, 3});

    Objek* objek = new Objek();
    for(auto &a : indexVertices) {
        Face* face = new Face();
        for(auto &b : a) {
            face->addVertex(vertices[b]);
        }
        objek->addFace(face);
    }

    return objek;
}

Objek* trapesiumSamaSisi(float panjangBawah, float lebarBawah, float panjangAtas, float lebarAtas, float tinggi, bool atas, bool bawah, bool depan, bool belakang, bool kanan, bool kiri)
{
    float selisihPanjang = (panjangBawah - panjangAtas) / 2;
    float selisihLebar = (lebarBawah - lebarAtas) / 2;

    float vertices[][3] = {
        // 0
        {0, 0, 0},
        // 1
        {panjangBawah, 0, 0},
        // 2
        {panjangBawah, 0, lebarBawah},
        // 3
        {0, 0, lebarBawah},
        // 4
        {selisihPanjang, tinggi, selisihLebar},
        // 5
        {panjangAtas + selisihPanjang, tinggi, selisihLebar},
        // 6
        {panjangAtas + selisihPanjang, tinggi, lebarAtas + selisihLebar},
        // 7
        {selisihPanjang, tinggi, lebarAtas + selisihLebar},
    };

    vector<array<int, 4>> indexVertices;

    if(atas)
        indexVertices.push_back({4, 5, 6, 7});
    if(bawah)
        indexVertices.push_back({0, 1, 2, 3});
    if(kanan)
        indexVertices.push_back({6, 2, 1, 5});
    if(kiri)
        indexVertices.push_back({0, 4, 7, 3});
    if(depan)
        indexVertices.push_back({0, 1, 5, 4});
    if(belakang)
        indexVertices.push_back({7, 6, 2, 3});

    Objek* objek = new Objek();
    for(auto &a : indexVertices) {
        Face* face = new Face();
        for(auto &b : a) {
            face->addVertex(vertices[b]);
        }
        objek->addFace(face);
    }

    return objek;
}

Objek* tabung(float radiusBawah, float radiusAtas, float tinggi, int slices, bool atas, bool bawah)
{
    Objek* objek = new Objek();
    Face* faceBawah = new Face();
    Face* faceAtas = new Face();
    // tidak perlu inisialisasi vertex dan indexnya
    for(float sudut = 0; sudut <= 360; sudut += (360 / slices)) {
        Face* face = new Face();

        Vertex* awalBawah = Vertex(radiusBawah, 0, 0).rotate(sudut, 0, 1, 0);
        faceBawah->addVertex(awalBawah);
        face->addVertex(awalBawah);
        face->addVertex(Vertex(radiusBawah, 0, 0).rotate(sudut + (360 / slices), 0, 1, 0));
        face->addVertex(Vertex(radiusAtas, tinggi, 0).rotate(sudut + (360 / slices), 0, 1, 0));
        Vertex* awalAtas = Vertex(radiusAtas, tinggi, 0).rotate(sudut, 0, 1, 0);
        face->addVertex(awalAtas);
        faceAtas->addVertex(awalAtas);

        objek->addFace(face);
    }

    if(bawah)
        objek->addFace(faceBawah);
    else
        delete faceBawah;

    if(atas)
        objek->addFace(faceAtas);
    else
        delete faceAtas;

    return objek;
}

Objek* from2Dto3D(Face* face, float scale)
{
    float xScale = 0;
    float yScale = 0;
    float zScale = 0;
    vector<Vertex> vertices = face->getVertices();

    for(int i = 0; i < vertices.size(); i++) {
        xScale += vertices[i].x;
        yScale += vertices[i].y;
        zScale += vertices[i].z;
    }

    xScale = vertices[0].x == (xScale / vertices.size()) ? 1 : -1;
    yScale = vertices[0].y == (yScale / vertices.size()) ? 1 : -1;
    zScale = vertices[0].z == (zScale / vertices.size()) ? 1 : -1;

    if(xScale == -1 && yScale == -1 && zScale == -1)
        return (new Objek())->addFace(face);

    Objek* objek = new Objek();
    Face* scaled = new Face();

    for(int i = 0; i < vertices.size(); i++) {
        Face* face = new Face();
        face->addVertex(vertices[i]);
        int indexFinish = (i == vertices.size() - 1) ? 0 : i + 1;
        face->addVertex(vertices[indexFinish]);

        Vertex* scaledVertex = new Vertex();
        Vertex* scaledVertexFinish = new Vertex();

        if(xScale == 1) {
            scaledVertex = vertices[i].clone()->translate(-scale, 0, 0);
            scaledVertexFinish = vertices[indexFinish].clone()->translate(-scale, 0, 0);
        }
        else if(yScale == 1) {
            scaledVertex = vertices[i].clone()->translate(0, -scale, 0);
            scaledVertexFinish = vertices[indexFinish].clone()->translate(0, -scale, 0);
        }
        else {
            scaledVertex = vertices[i].clone()->translate(0, 0, -scale);
            scaledVertexFinish = vertices[indexFinish].clone()->translate(0, 0, -scale);
        }
        face->addVertex(scaledVertexFinish);
        face->addVertex(scaledVertex);

        scaled->addVertex(scaledVertexFinish);
        scaled->addVertex(scaledVertex);

        objek->addFace(face);
    }

    objek->addFace(face);
    objek->addFace(scaled);

    return objek;
}

float toRad(float degree) {
    return degree * M_PI / 180;
}

void normalize(float *v)
{
    float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

    for (int i = 0; i < 3; i++)
    {
        v[i] = v[i] / length;
    }
}

float *cross_product(float *a, float *b)
{
    float* result = new float[3];
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] =  -(a[0] * b[2] - a[2] * b[0]);
    result[2] = a[0] * b[1] - a[1] * b[0];

    normalize(result);

    return result;
}

float *calculate_normal(float *a, float *b, float *c)
{
    float x[] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
    float y[] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};

    float *result = cross_product(x, y);

    return result;
}
