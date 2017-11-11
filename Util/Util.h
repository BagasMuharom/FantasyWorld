#ifndef UTIL_H
#define UTIL_H

#include <vector>

class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);
    float x, y, z;
};

class Vertex : public Vector3 {
public:
    Vertex(float x, float y, float z);
    Vertex(Vector3 &vector);
    void translate(float x, float y, float z);
    void rotate(float degree, float x, float y, float z);

private:
    void rotateX();
    void rotateY();
    void rotateZ();
};

class Face {
public:
    std::vector<Vertex> vertices;
private:
};

#endif