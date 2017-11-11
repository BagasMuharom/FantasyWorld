#include "Util.h"
#include "GL/glut.h"
#include <math.h>

Vector3::Vector3(){}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vertex::Vertex(float x, float y, float z) : Vector3(x, y, z){}

Vertex::Vertex(Vector3 &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

void Vertex::translate(float x, float y, float z)
{
    this->x += x;
    this->y += y;
    this->z += z;
}

void Vertex::rotateX()
{

}

void Vertex::rotateY()
{

}

void Vertex::rotateZ()
{

}
