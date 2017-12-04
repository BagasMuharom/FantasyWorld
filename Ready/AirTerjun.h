#ifndef READY_AIR_TERJUN_H
#define READY_AIR_TERJUN_H

#include "../Util/Util.h"
#include "../Util/Color.h"
#include "GL/glut.h"
#include "Bubble.h"

vector<Face*> blocksAirTerjun;
vector<Face*> blocksAirTerjun2;

void initAirTerjun()
{
    float lebar = 3;
    float tinggi = 1;

    for(float x = -lebar; x < lebar; x += 0.2) {
        Face* face = new Face();
        // face->setColor(new Color(0.529, 0.807, 0.98));
        face->setColor(ColorList::putih());
        face->addVertex(x, 0, 0);
        face->addVertex(x + 0.2, 0, 0);
        face->addVertex(x + 0.2, tinggi, 0);
        face->addVertex(x, tinggi, 0);

        blocksAirTerjun.push_back(face);
        blocksAirTerjun2.push_back(face->clone()->translate(0, 0, -0.5)->setColor(ColorList::putih()));
    }

}

void idleAirTerjun()
{
    for(unsigned int i = 0; i < blocksAirTerjun.size(); i++) {
        GLubyte penambah = 3;
        bool kurangi = (rand() % 2 == 0);
        Color* temp = blocksAirTerjun[i]->getColor();
        Color* temp2 = blocksAirTerjun2[i]->getColor();

        if((temp->a - penambah < 125 && kurangi) || (!kurangi && temp->a + penambah > 170))
            kurangi = !kurangi;

        if(kurangi) {
            GLubyte alpha = temp->a - penambah;
            Color* baru = new Color(temp->r, temp->g, temp->b, alpha);
            blocksAirTerjun[i]->setColor(baru);
            blocksAirTerjun2[i]->setColor(new Color(temp2->r, temp2->g, temp2->b, alpha));
        }
        else {
            GLubyte alpha = temp->a + penambah;
            Color* baru = new Color(temp->r, temp->g, temp->b, alpha);
            blocksAirTerjun[i]->setColor(baru);
            blocksAirTerjun2[i]->setColor(new Color(temp2->r, temp2->g, temp2->b, alpha));
        }

        delete temp;
        delete temp2;
    }

}

void airTerjun()
{
    for(unsigned int i = 0; i < blocksAirTerjun2.size(); i++ ) {
        blocksAirTerjun2[i]->drawNormal();
    }
}

void lokasiBubble()
{
    glPushMatrix();
    glTranslatef(26.5, 0, 0);
    showBubble();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(30.5, 10, 0);
    showBubble();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(37, 15, 0);
    showBubble();
    glPopMatrix();
}

void airTerjunTingkat()
{
    glPushMatrix();
    glTranslatef(42, 20.5, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(1, 5, 1);
    airTerjun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(37.5, 15 , 0);
    glScalef(1, 5, 1);
    glRotatef(90, 0, 1, 0);
    airTerjun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(37, 15.5, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(1, 7, 1);
    airTerjun();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(30.5, 10 , 0);
    glScalef(1, 5, 1);
    glRotatef(90, 0, 1, 0);
    airTerjun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 10.5, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(1, 4, 1);
    airTerjun();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 10, 1);
    glTranslatef(26.5, 0 , 0);
    glRotatef(90, 0, 1, 0);
    airTerjun();
    glPopMatrix();
}

#endif