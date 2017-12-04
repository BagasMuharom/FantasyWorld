#include "TerrainGenerator.h"
#include <vector>
#include <stdlib.h>
#include "../Util/Util.h"
#include "GL/glut.h"
#include "../Util/Color.h"

using namespace std;

TerrainGenerator::TerrainGenerator() {}

TerrainGenerator::TerrainGenerator(float xLength, float zLength, float maxHeight, float minHeight, float iterasi)
{
    this->xLength = xLength;
    this->zLength = zLength;
    this->maxHeight = maxHeight;
    this->minHeight = minHeight;
    this->iterasi = iterasi;
}

void TerrainGenerator::generate()
{
    float heights[20];
    heights[0] = this->minHeight;
    heights[19] = this->maxHeight;
    for(int i = 1;i < 19; i++) {
        heights[i] = heights[i - 1] + (this->maxHeight - this->minHeight) / 20;
    }

    for(float x = - (this->xLength / 2); x <= this->zLength / 2; x += iterasi) {
        vector<Vertex*> vertex;
        for(float z = - (this->zLength / 2); z <= this->zLength / 2; z += iterasi) {
            float y = heights[rand() % 20];
            vertex.push_back(new Vertex(x, y, z));
        }
        this->vertices.push_back(vertex);
    }
}

const void TerrainGenerator::draw()
{
    for(unsigned int x = 0; x < this->vertices.size() - 1; x++) {
        for(int z = 0; z < this->vertices[x].size() - 1; z++) {
            ColorList::rumput()->set();
            glPushMatrix();
                glBegin(GL_POLYGON);
                    this->vertices[x][z]->drawVertex();
                    this->vertices[x + 1][z]->drawVertex();
                    this->vertices[x][z + 1]->drawVertex();
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glBegin(GL_POLYGON);
                    this->vertices[x + 1][z]->drawVertex();
                    this->vertices[x][z + 1]->drawVertex();
                    this->vertices[x + 1][z + 1]->drawVertex();
                glEnd();
            glPopMatrix();
        }
    }
}
