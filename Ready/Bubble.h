#ifndef READY_BUBBLE_H
#define READY_BUBBLE_H

#include "../Util/Util.h"
#include "../Util/Color.h"
#include "GL/glut.h"

// Untuk keperluan air terjun

struct Bubble{
    float radius;
    Color* color;
    Vertex v;
};

vector<Bubble> bubbleAirTerjun;

void initBubble()
{

    for(float i = -3; i <= 3; i += 0.5) {
        Bubble bub;
        bub.radius = (rand() % 4 + 1) * 0.2;
        bub.color = ColorList::putih()->setAlpha((rand() % 3 + 2) * 90);
        bub.v = Vertex(0, 0, i);
        bubbleAirTerjun.push_back(bub);
    }
}

void idleBubble()
{
    GLubyte minAlpha = 180;
    GLubyte maxAlpha = 220;

    float minRadius = 0.3;
    float maxRadius = 1;
    for(auto &bubble : bubbleAirTerjun) {
        bool kurangiAlpha = (rand() % 2 == 0);

        if(kurangiAlpha && bubble.color->a - 30 < minAlpha)
            kurangiAlpha = !kurangiAlpha;
        if(!kurangiAlpha && bubble.color->a + 30 > maxAlpha)
            kurangiAlpha = !kurangiAlpha;

        if(kurangiAlpha)
            bubble.color->a -= 30;
        else
            bubble.color->a += 30;

        bool kurangiRadius = (rand() % 2 == 0);

        if(kurangiRadius && bubble.radius - 0.15 < minRadius)
            kurangiRadius = !kurangiRadius;
        if(!kurangiRadius && bubble.radius + 0.15 > maxRadius)
            kurangiRadius = !kurangiRadius;

        if(kurangiRadius)
            bubble.radius -= 0.15;
        else
            bubble.radius += 0.15;
    }

}

void showBubble()
{
    for(auto &bubble : bubbleAirTerjun) {
        glPushMatrix();
        glTranslatef(bubble.v.x, bubble.v.y + 0.15, bubble.v.z);
        bubble.color->set();
        glutSolidSphere(bubble.radius, 8, 8);
        glPopMatrix();
    }
}

#endif