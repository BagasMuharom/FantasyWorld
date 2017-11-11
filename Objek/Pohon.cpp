#include "Pohon.h"
#include "../Util/Util.h"
#include "../Warna/Material.h"
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<vector>

using namespace std;

void Pohon::Cemara(
    unsigned short int jumlahCemara,
    float tinggiBatang,
    float radiusDasarCemara,
    float jarakCemara,
    float tinggiCemaraDasar)
{   
    glColor3f(0.8, 0.8, 0.3);
    batangCemara(tinggiBatang, radiusDasarCemara / 3, radiusDasarCemara / 4, 8);

    // Membuat cemara
    for (unsigned short int i = 0; i < jumlahCemara; i++)
    {
        float lokasiCemara = tinggiBatang + jarakCemara * i;
        glPushMatrix();
        glColor3ub(20, 255, 20);
        glTranslatef(0, lokasiCemara, 0);
        cemara(radiusDasarCemara -= 0.2, tinggiCemaraDasar -= 0.2, 8);
        glPopMatrix();
    }
    
}

void Pohon::cemara(float radius, float tinggi, int slices)
{
    vector<Vertex> vertices;
    glBegin(GL_POLYGON);
    for(float rad = 0; rad < 2 * M_PI; rad += M_PI / (slices / 2)) {
        float x = radius * cos(rad);
        float z = radius * sin(rad);
        glNormal3f(x, 0, z);
        glVertex3f(x, 0, z);

        // Menyimpan vertex agar nanti tidak perlu hitung lagi
        vertices.push_back(Vertex(x, 0, z));
    }
    glEnd();

    // Draw the triangles
    for(int point = 0; point < vertices.size(); point++) {
        // cout << vertices[point].x << " " << vertices[point].y << " " << vertices[point].z << endl;
        glBegin(GL_POLYGON);
            float vertexBefore[3] = {vertices[point].x, vertices[point].y, vertices[point].z};
            float vertexAfter[3];

            if(point == vertices.size() - 1) {
                vertexAfter[0] = vertices[0].x;
                vertexAfter[1] = vertices[0].y;
                vertexAfter[2] = vertices[0].z;
            }
            else {
                vertexAfter[0] = vertices[point + 1].x;
                vertexAfter[1] = vertices[point + 1].y;
                vertexAfter[2] = vertices[point + 1].z;
            }
            
            glNormal3f(vertexBefore[0], vertexBefore[1], vertexBefore[2]);
            glVertex3f(vertexBefore[0], vertexBefore[1], vertexBefore[2]);
            glNormal3f(vertexAfter[0], vertexAfter[1], vertexAfter[2]);
            glVertex3f(vertexAfter[0], vertexAfter[1], vertexAfter[2]);
            glNormal3f(0, tinggi, 0);
            glVertex3f(0, tinggi, 0);
        glEnd();
    }

}

void Pohon::batangCemara(float tinggi, float radiusBawah, float radiusAtas, int slices)
{
    glPushMatrix();
    
    float xPutarBawah = 0;
    float zPutarBawah = radiusBawah / 2;
    float xPutarAtas = 0;
    float zPutarAtas = radiusAtas / 2;
    for(float sudut = 0; sudut <= 360; sudut += (360 / slices)) {
        glBegin(GL_POLYGON);
        float radBefore = sudut * M_PI / 180;
        float radAfter = (sudut + (360 / slices)) * M_PI / 180;

        // vertices bawah
        float x = xPutarBawah * cos(radBefore) + zPutarBawah * sin(radBefore);
        float z = - xPutarBawah * sin(radBefore) + zPutarBawah * cos(radBefore);
        glNormal3f(x, 0, z);
        glVertex3f(x, 0, z);

        x = xPutarBawah * cos(radAfter) + zPutarBawah * sin(radAfter);
        z = -xPutarBawah * sin(radAfter) + zPutarBawah * cos(radAfter);
        glNormal3f(x, 0, z);
        glVertex3f(x, 0, z);

        // vertices atas
        x = xPutarAtas * cos(radAfter) + zPutarAtas * sin(radAfter);
        z = -xPutarAtas * sin(radAfter) + zPutarAtas * cos(radAfter);
        glNormal3f(x, tinggi, z);
        glVertex3f(x, tinggi, z);

        x = xPutarAtas * cos(radBefore) + zPutarAtas * sin(radBefore);
        z = - xPutarAtas * sin(radBefore) + zPutarAtas * cos(radBefore);
        glNormal3f(x, tinggi, z);
        glVertex3f(x, tinggi, z);
        glEnd();
    }
    glPopMatrix();
}