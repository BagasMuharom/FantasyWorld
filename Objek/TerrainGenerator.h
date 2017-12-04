#ifndef TERRAINGENERATOR_H
#define TERRAINGENERATOR_H

#include <vector>
#include "../Util/Util.h"

using namespace std;

/**
 * Class ini berfungsi untuk me-generate array yang akan
 * digunakan untuk terrain (Terrain Generator)
 */
class TerrainGenerator {
public:

    /**
     * Jika terrain memiliki panjang 5, dan lebar 5, maka akan ada segitiga
     * sejumlah 50 (5 * 5 * 2)
     */
    TerrainGenerator();
    TerrainGenerator(float xLength, float zLength, float maxHeight, float minHeight, float iterasi);
    void setRoadArray();
    void generate();
    const void draw();
    void setTerrainArray();
    void recursiveLyGenerate(float posX, float posZ, float heightBefore);

private:
    /**
     * Vector ini hanya akan mencatat tinggi pada x dan z tertentu, sehingga
     * lebih hemat memori
     */
    vector<vector<float>> height;
    vector<vector<Vertex*>> vertices;
    float xLength, zLength, maxHeight, minHeight, iterasi;
};

#endif