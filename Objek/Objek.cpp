#include "Objek.h"
#include "../Util/Util.h"
#include <iostream>

using namespace std;

float verticesBatu1[][10][3] = {
    {
        {-0.276388, -0.955261, -0.315154},
        {-0.858745, -0.604609, -0.315154},
        {-1.16508, 0.006849, -0.36948},
        {-0.787149, 0.484953, -0.35881},
        {-0.276389, 0.746036, -0.315152},
        {0.262867, 0.7044, -0.315152},
        {0.723608, 0.421114, -0.315152},
        {0.924464, -0.104611, -0.307173},
        {0.799278, -0.630337, -0.306974},
        {0.262867, -0.913623, -0.315152},
    },
    // Level 1
    {
        {-0.276388, -0.955261, -0.315154},
        {-0.08152, -1.10461, -0.029731},
        {-0.793031, -0.913628, -0.029732},
    },
    {
        {-0.793031, -0.913628, -0.029732},
        {-0.276388, -0.955261, -0.315154},
        {-0.858745, -0.604609, -0.315154}
    },
    {
        {-0.858745, -0.604609, -0.315154},
        {-0.793031, -0.913628, -0.029732},
        {-1.23953, -0.367864, -0.022304}
    },
    {
        {-0.858745, -0.604609, -0.315154},
        {-1.23953, -0.367864, -0.022304},
        {-1.16508, 0.006848, -0.36948}
    },
    {
        {-1.23953, -0.367864, -0.022304},
        {-1.16508, 0.006848, -0.36948},
        {-1.26781, 0.418119, -0.104168}
    },
    {
        {-1.26781, 0.418119, -0.104168},
        {-1.16508, 0.006848, -0.36948},
        {-0.787149, 0.484953, -0.35881}
    },
    {
        {-0.787149, 0.484953, -0.35881},
        {-1.26781, 0.418119, -0.104168},
        {-0.622365, 0.832534, -0.018049}
    },
    {
        {-0.622365, 0.832534, -0.018049},
        {-0.787149, 0.484953, -0.35881},
        {-0.276389, 0.746036, -0.315152}
    },
    {
        {-0.276389, 0.746036, -0.315152},
        {-0.622365, 0.832534, -0.018049},
        {0.007997, 0.967786, -0.00005}
    },
    {
        {0.007997, 0.967786, -0.00005},
        {-0.276389, 0.746036, -0.315152},
        {0.262867, 0.7044, -0.315152}
    },
    {
        {0.262867, 0.7044, -0.315152},
        {0.007997, 0.967786, -0.00005},
        {0.587786, 0.704405, 0}
    },
    {
        {0.262867, 0.7044, -0.315152},
        {0.723608, 0.421114, -0.315152},
        {0.587786, 0.704405, 0}
    },
    {
        {0.587786, 0.704405, 0},
        {0.723608, 0.421114, -0.315152},
        {1.07007, 0.199058, 0.033483}
    },
    {
        {1.07007, 0.199058, 0.033483},
        {0.723608, 0.421114, -0.315152},
        {0.924464, -0.104611, -0.307173}
    },
    {
        {1.07007, 0.199058, 0.033483},
        {0.924464, -0.104611, -0.307173},
        {1.1716, -0.418732, 0.044205}
    },
    {
        {0.924464, -0.104611, -0.307173},
        {1.1716, -0.418732, 0.044205},
        {0.799278, -0.630337, -0.306974}
    },
    {
        {1.1716, -0.418732, 0.044205},
        {0.799278, -0.630337, -0.306974},
        {0.623272, -0.913628, 0.003836}
    },
    {
        {0.799278, -0.630337, -0.306974},
        {0.623272, -0.913628, 0.003836},
        {0.262867, -0.913623, -0.315152}
    },
    {
        {0.623272, -0.913628, 0.003836},
        {0.262867, -0.913623, -0.315152},
        {-0.08152, -1.10461, -0.029731}
    },
    {
        {-0.08152, -1.10461, -0.029731},
        {-0.276388, -0.955261, -0.315154},
        {0.262867, -0.913623, -0.315152}
    },
    // Level 2
    {
        {-0.08152, -1.10461, -0.029731},
        {0.158321, -0.955261, 0.443813},
        {-0.606447, -0.913623, 0.402813}
    },
    {
        {-0.606447, -0.913623, 0.402813},
        {-0.08152, -1.10461, -0.029731},
        {-0.793031, -0.913628, -0.029732}
    },
    {
        {-0.793031, -0.913628, -0.029732},
        {-0.606447, -0.913623, 0.402813},
        {-0.987689, -0.630337, 0.40416}
    },
    {
        {-0.987689, -0.630337, 0.40416},
        {-0.793031, -0.913628, -0.029732},
        {-1.23953, -0.367864, -0.022304},
    },
    {
        {-1.23953, -0.367864, -0.022304},
        {-0.987689, -0.630337, 0.40416},
        {-0.999035, -0.052439, 0.500306}
    },
    {
        {-0.999035, -0.052439, 0.500306},
        {-1.26781, 0.418119, -0.104168},
        {-0.782686, 0.638765, 0.416836}
    },
    {
        {-0.999035, -0.052439, 0.500306},
        {-1.26781, 0.418119, -0.104168},
        {-1.23953, -0.367864, -0.022304}
    },
    {
        {-0.782686, 0.638765, 0.416836},
        {-1.26781, 0.418119, -0.104168},
        {-0.622365, 0.832534, -0.018049}
    },
    {
        {-0.782686, 0.638765, 0.416836},
        {-0.622365, 0.832534, -0.018049},
        {-0.229807, 1.00137, 0.525532}
    },
    {
        {-0.229807, 1.00137, 0.525532},
        {-0.622365, 0.832534, -0.018049},
        {0.007997, 0.967786, -0.00005}
    },
    {
        {0.007997, 0.967786, -0.00005},
        {-0.229807, 1.00137, 0.525532},
        {0.28797, 0.875144, 0.447148}
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.007997, 0.967786, -0.00005},
        {0.587786, 0.704405, 0}
    },
    {
        {0.587786, 0.704405, 0},
        {1.07007, 0.199058, 0.033483},
        {0.770812, 0.390536, 0.552645}
    },
    {
        {0.770812, 0.390536, 0.552645},
        {1.07007, 0.199058, 0.033483},
        {1.15686, -0.119863, 0.537402}
    },
    {
        {1.15686, -0.119863, 0.537402},
        {1.1716, -0.418732, 0.044205},
        {0.808181, -0.609808, 0.558422}
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.770812, 0.390536, 0.552645},
        {0.587786, 0.704405, 0}
    },
    {
        {0.808181, -0.609808, 0.558422},
        {0.623272, -0.913628, 0.003836},
        {0.158321, -0.955261, 0.443813}
    },
    {
        {0.158321, -0.955261, 0.443813},
        {-0.08152, -1.10461, -0.029731},
        {-0.606447, -0.913623, 0.402813}
    },
    {
        {0.158321, -0.955261, 0.443813},
        {-0.08152, -1.10461, -0.029731},
        {0.623272, -0.913628, 0.003836}
    },
    {
        {0.623272, -0.913628, 0.003836},
        {0.808181, -0.609808, 0.558422},
        {1.1716, -0.418732, 0.044205}
    },
    {
        {1.1716, -0.418732, 0.044205},
        {1.15686, -0.119863, 0.537402},
        {1.07007, 0.199058, 0.033483}
    },
    // Level 3
    {
        {0.158321, -0.955261, 0.443813},
        {0.808181, -0.609808, 0.558422},
        {0.116779, -0.703853, 0.876573}
    },
    {
        {0.158321, -0.955261, 0.443813},
        {0.116779, -0.703853, 0.876573},
        {-0.606447, -0.913623, 0.402813}
    },
    {
        {0.116779, -0.703853, 0.876573},
        {-0.606447, -0.913623, 0.402813},
        {-0.483381, -0.478594, 0.798076}
    },
    {
        {-0.483381, -0.478594, 0.798076},
        {-0.606447, -0.913623, 0.402813},
        {-0.987689, -0.630337, 0.40416}
    },
    {
        {-0.987689, -0.630337, 0.40416},
        {-0.483381, -0.478594, 0.798076},
        {-0.999035, -0.052439, 0.500306}
    },
    {
        {-0.483381, -0.478594, 0.798076},
        {-0.999035, -0.052439, 0.500306},
        {-0.394696, 0.274832, 0.757868}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.999035, -0.052439, 0.500306},
        {-0.782686, 0.638765, 0.416836}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.782686, 0.638765, 0.416836},
        {-0.229807, 1.00137, 0.525532}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.229807, 1.00137, 0.525532},
        {0.186989, 0.482376, 0.779228}
    },
    {
        {-0.229807, 1.00137, 0.525532},
        {0.28797, 0.875144, 0.447148},
        {0.186989, 0.482376, 0.779228}
    },
    {
        {0.28797, 0.875144, 0.447148},
        {0.186989, 0.482376, 0.779228},
        {0.770812, 0.390536, 0.552645}
    },
    {
        {0.186989, 0.482376, 0.779228},
        {0.770812, 0.390536, 0.552645},
        {0.650486, -0.205198, 0.856856}
    },
    {
        {0.770812, 0.390536, 0.552645},
        {0.650486, -0.205198, 0.856856},
        {1.15686, -0.119863, 0.537402}
    },
    {
        {1.15686, -0.119863, 0.537402},
        {0.650486, -0.205198, 0.856856},
        {0.808181, -0.609808, 0.558422}
    },
    {
        {0.650486, -0.205198, 0.856856},
        {0.808181, -0.609808, 0.558422},
        {0.116779, -0.703853, 0.876573}
    },
    //Level 4
    {
        {-0.394696, 0.274832, 0.757868},
        {-0.483381, -0.478594, 0.798076},
        {0.117802, -0.206886, 0.98599}
    },
    {
        {-0.394696, 0.274832, 0.757868},
        {0.117802, -0.206886, 0.98599},
        {0.186989, 0.482376, 0.779228}
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.186989, 0.482376, 0.779228},
        {0.650486, -0.205198, 0.856856}
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.650486, -0.205198, 0.856856},
        {0.116779, -0.703853, 0.876573}
    },
    {
        {0.117802, -0.206886, 0.98599},
        {0.116779, -0.703853, 0.876573},
        {-0.483381, -0.478594, 0.798076}
    }
};

void batu() {
    glPushMatrix();
    glColor3ub(120, 120, 120);
    glTranslatef(0, 0.3, 0);
    glRotatef(-90, 1, 0, 0);
    for (auto &point : verticesBatu1) {
        Face* face = new Face();
        for(auto &vertex : point) {
            face->addVertex(Vertex(vertex[0], vertex[1], vertex[2]));
        }
        face->drawNormal();

        delete face;
    }
    glPopMatrix();
}

float verticesBatu2[][3] = {
    //0
    {-0.23, 0.2, 0.04},
    // 1
    {-0.13577, 0, 0.20909},
    // 2
    {-0.34, 0, -0.015},
    // 3
    {0.14703, 0, 0.28337},
    // 4
    {0.08, 0.2, 0.1},
    // 5
    {0.14703, 0, 0.28337},
    // 6
    {-0.04, 0.25, -0.1},
    // 7
    {-0.16, 0.2, -0.2},
    // 8
    {-0.3, 0.05, -0.15},
    // 9
    {0.18, 0.22, -0.1},
    // 10
    {0.3, 0, 0.11497},
    // 11
    {-0.00798, 0, -0.29784},
    // 12
    {0.24751, 0, -0.15308}
};

int facesBatu2[][6] = {
    {0, 1, 2},
    {0, 1, 3},
    {0, 4, 5},
    {0, 6, 4},
    {0, 6, 7},
    {0, 7, 8},
    {0, 8, 2},
    {6, 7, 9},
    {6, 4, 9},
    {4, 9, 5},
    {5, 9, 10},
    {7, 8, 11},
    {2, 8, 11},
    {7, 9, 11},
    {9, 10, 12},
    {9, 12, 11},
    {5, 10, 12, 11, 2, 1},
};

void batu2() {
    glPushMatrix();
    (new Color(120, 120, 120))->set(true);
    for(auto &point : facesBatu2) {
        Face* face = new Face();
        for(auto &index : point) {
            face->addVertex(Vertex(verticesBatu2[index][0], verticesBatu2[index][1], verticesBatu2[index][2]));
        }
        face->drawNormal();

        delete face;
    }
    glPopMatrix();
}

float verticessemak[][3] = {
    {0, 0, 0},
    {-1.022434, 0.248791, -0.095557},
    {-0.476122, -0.652270, 0.788318},
    {0.473428, -0.705925, 0.624071},
    {-0.781381, -0.671891, -0.404078},
    {0.282202, -0.994406, -0.247732},
    {0.029852, -0.490258, -0.925941},
    {0.936297, -0.492541, -0.269424},
    {0.405108, 0.258762, -0.948066},
    {0.539645, 0.868872, -0.188019},
    {1.065255, 0.142590, -0.094934},
    {-0.096856, 0.792813, -0.702258},
    {0.708869, 0.119915, 0.821170},
    {-0.563573, 0.875689, 0.008611},
    {0.247114, 0.884328, 0.569624},
    {-0.586108, 0.305673, -0.833709},
    {-0.535167, 0.434908, 0.841142}
};


int facessemak[][3] = {
    {1, 4, 2},
    {1, 15, 4},
    {5, 2, 4},
    {2, 5, 3},
    {4, 6, 5},
    {6, 15, 8},
    {7, 6, 8},
    {12, 7, 10},
    {15, 11, 8},
    {8, 9, 10},
    {9, 8, 11},
    {12, 10, 9},
    {14, 11, 13},
    {15, 1, 13},
    {14, 13, 16},
    {14, 16, 12},
    {13, 1, 16},
    {16, 2, 12},
    {3, 12, 2},
    {16, 1, 2},
    {3, 5, 7},
    {4, 15, 6},
    {12, 3, 7},
    {5, 6, 7},
    {7, 8, 10},
    {14, 12, 9},
    {14, 9, 11},
    {13, 11, 15}
};

Objek* semak()
{
    Objek* semak = new Objek();
    for(auto &point : facessemak) {
        Face* face = new Face();
        for(auto &index : point) {
            face->addVertex(Vertex(verticessemak[index][0], verticessemak[index][1], verticessemak[index][2]));
        }
        semak->addFace(face);
    }

    return semak;
}

float verticesRumput[][3] = {
    {-0.025, 0.1, -0.06},
    {-0.007, 0.1, -0.07},
    {0.006, 0.012, -0.075},
    {-0.04, 0.01, -0.06},
    {0.008, 0.1, -0.009},
    {0.04, 0.01, 0.07},
    {-0.01, 0.09, -0.004},
    {-0.004, 0.01, 0.08},
    {0.002, 0.3, 0.02},
    {0.01, 0.3, 0.02},
    {0.003, 0.3, 0.004},
    {-0.001, 0.3, 0.005},
    {-0.006, 0.2, 0.002},
    {0.006, 0.2, 0},
    {0.02, 0.2, 0.04},
    {0.004, 0.2, 0.04}
};

int facesRumput[][4] = {
    {1, 2, 3, 4},
    {2, 5, 6, 3},
    {5, 7, 8, 6},
    {7, 1, 4, 8},
    {4, 3, 6, 8},
    {9, 10, 11, 12},
    {13, 14, 2, 1},
    {14, 15, 5, 2},
    {15, 16, 7, 5},
    {16, 13, 1, 7},
    {12, 11, 14, 13},
    {11, 10, 15, 14},
    {10, 9, 16, 15},
    {9, 12, 13, 16}
};

Objek* rumput()
{
    Objek* objek = new Objek();
    for(auto &point : facesRumput) {
        Face* face = new Face();
        for(auto &index : point) {
            face->addVertex(Vertex(verticesRumput[index - 1][0], verticesRumput[index - 1][1], verticesRumput[index - 1][2]));
        }
        objek->addFace(face);
    }

    return objek->translate(0, 0.15, 0);
}

float verticesKayuArah[][3] = {
    // 1
    {-2.0, 0.0, 1.0},
    // 2
    {2.0, 0.0, 1.0},
    // 3
    {-2.0, 0.0, -0.5},
    // 4
    {2.0, 0.0, -0.5},
    // 5
    {3.0, 0.0, 0.250000},
    // 6
    {-3.0, 0.0, 0.250000},
    // 7
    {2.098813, 0.0, 0.090353},
    // 8
    {2.545700, 0.0, -0.043572},
    // 9
    {2.472165, 0.0, -0.156186},
    // 10
    {-1.822522, 0.0, 0.287970},
    // 11
    {-2.638273, -0.008100, 0.498985},
    // 12
    {-2.462743, 0.018944, 0.656960},
    // 13
    {-1.999396, 0.2, 1.000615},
    // 14
    {2.000604, 0.2, 1.000615},
    // 15
    {-1.999396, 0.2, -0.499385},
    // 16
    {2.000604, 0.2, -0.499385},
    // 17
    {3.000604, 0.2, 0.250615},
    // 18
    {-2.999396, 0.2, 0.250615},
    // 19
    {2.099417, 0.2, 0.090967},
    // 20
    {2.546304, 0.2, -0.042957},
    // 21
    {2.472769, 0.2, -0.155572},
    // 22
    {-1.821918, 0.2, 0.288585},
    // 23
    {-2.637668, 0.2, 0.499600},
    // 24
    {-2.462139, 0.2, 0.657575}
};

int facesKayuArah[][7] = {
    {10, 12, 24, 22},
    {11, 10, 22, 23},
    {6, 11, 23, 18},
    {7, 9, 21, 19},
    {8, 7, 19, 20},
    {5, 8, 20, 17},
    {3, 6, 18, 15},
    {2, 5, 17, 14},
    {4, 3, 15, 16},
    {9, 4, 16, 21},
    {1, 2, 14, 13},
    {12, 1, 13, 24},
    {16, 15, 22, 19, 21},
    {15, 18, 23, 22},
    {14, 17, 20, 19},
    {12, 10, 7, 2, 1},
    {2, 7, 8, 5},
    {3, 10, 11, 6},
    {9, 7, 10, 3, 4},
    {24, 13, 14, 19, 22}
};

void kayuArah()
{
    glPushMatrix();
    ColorList::batang()->set();
    for(auto &point : facesKayuArah) {
        Face* face = new Face();
        for(auto &index : point) {
            if(index != 0)
                face->addVertex(verticesKayuArah[index - 1]);
        }
        face->drawNormal();

        delete face;
    }
    glPopMatrix();
}

float verticesTenda[][3] = {
    {0.6, 2, -1},
    {0.6, -4, -1},
    {0, 2, 0},
    {0, -4, 0},
    {-2.1, 2, -3},
    {-2.1, -4, -3},
    {-3.1, 2, -4.2},
    {-3.1, -4, -4.2},
    {-3.5, 2, -5},
    {-3.5, -4, -5},
    {-3.5, 2, 0},
    {-3.5, -4, 0},
    {-3.5, 1.9, -4.1},
    {-2.6, 1.8, -2.7},
    {-1.6, 1.4, -1.1},
    {-2.3, 2, 0},
    {-3.5, -3, -5},
    {-3.1, -3.003, -4.2},
    {-2.1, -3, -3},
    {-0.38, -3, -1.7},
    {-0.1, 1, -1.9},
    {-0.1, -3, -1.9},
    {-1.9, 1, -3.2},
    {-1.9, -3, -3.2},
    {-2.9, 1, -4.2},
    {-2.9, -3, -4.2},
    {-3.5, 1, -5.4},
    {-3.5, -3, -5.4},
    {-3.5, 1, -5},
    {-3.1, 1, -4.2},
    {-2.1, 1, -3},
    {-0.38, 1, -1.7},
    {-3.5, -4, -4.2},
    {-3.5, -4, -3},
    {-3.5, -4, -1}
};

int facesTenda[][4] = {
    {1, 2, 4, 3},
    {2, 1, 5, 6},
    {6, 5, 7, 8},
    {8, 7, 9, 10},
    {3, 4, 12, 11},
    {9, 7, 13},
    {5, 14, 13, 7},
    {1, 15, 14, 5},
    {3, 16, 15, 1},
    {4, 2, 35, 12},
    {28, 17, 18, 26},
    {22, 24, 19, 20},
    {26, 18, 19, 24},
    {22, 21, 23, 24},
    {24, 23, 25, 26},
    {26, 25, 27, 28},
    {27, 25, 30, 29},
    {23, 31, 30, 25},
    {21, 32, 31, 23},
    {20, 32, 21, 22},
    {6, 34, 35, 2},
    {8, 33, 34, 6},
    {10, 33, 8}
};

GrupObjek* tenda()
{
    GrupObjek* grupTenda = new GrupObjek();
    Objek* tenda = new Objek();
    for(auto &point : facesTenda) {
        Face* faceKanan = new Face();
        Face* faceKiri = new Face();
        for(auto &index : point) {
            if(index != 0) {
                faceKanan->addVertex(verticesTenda[index - 1]);
                faceKiri->addVertex(Vertex(verticesTenda[index - 1][0], verticesTenda[index - 1][1], verticesTenda[index - 1][2]));
            }
        }
        faceKiri->flip(1, 0)->translate(-7, 0, 0);

        tenda->addFace(faceKiri);
        tenda->addFace(faceKanan);
    }

    tenda->setColor(ColorList::jingga());
    tenda->rotate(90, 1, 0, 0);

    grupTenda->addObjek(tenda);

    // aksesoris tenda

    // Tiang
    grupTenda->addObjek(tabung(0.12, 0.12, 5.5, 8, 1, 0)->translate(-3.5, 0, 1.75)->setColor(ColorList::batang()));

    grupTenda->addObjek(tabung(0.12, 0.12, 5.5, 8, 1, 0)->translate(-3.5, 0, -3.75));

   // tali ikat kiri depan
   GrupObjek* kiriDepan = new GrupObjek();
   kiriDepan->addObjek(tabung(0.15, 0.15, 0.5, 8, 1, 0)->translate(2, 0, 2)->setColor(ColorList::batang()));
   kiriDepan->addObjek(tabung(0.25, 0.25, 0.15, 8)->translate(2, 0.25, 2)->setColor(ColorList::putih()));
   kiriDepan->addObjek(tabung(0.05, 0.05, 3.5, 8, 1, 1)->rotate(57, 1, 0, 0)->rotate(-120, 0, 1, 0)->translate(2, 0.2, 2));
   kiriDepan->addObjek(tabung(0.05, 0.05, 2, 8, 1, 1)->rotate(70, 1, 0, 0)->rotate(-100, 0, 1, 0)->translate(2, 0.2, 2));
   
   grupTenda->addGrupObjek(kiriDepan);
   GrupObjek* kananDepan  = kiriDepan->clone()->flip(1, 0)->translate(-7, 0, 0);
   grupTenda->addGrupObjek(kananDepan);

   // tali ikat kiri belakang
   GrupObjek* kiriBelakang = new GrupObjek();
   kiriBelakang->addObjek(tabung(0.15, 0.15, 0.5, 8, 1, 0)->setColor(ColorList::batang())->translate(2, 0, -4));
   kiriBelakang->addObjek(tabung(0.25, 0.25, 0.15, 8)->setColor(ColorList::putih())->translate(2, 0.25, -4));
   kiriBelakang->addObjek(tabung(0.05, 0.05, 3.5, 8, 1, 1)->rotate(57, 1, 0, 0)->rotate(-60, 0, 1, 0)->translate(2, 0.2, -4));
   kiriBelakang->addObjek( tabung(0.05, 0.05, 2, 8, 1, 1)->rotate(70, 1, 0, 0)->rotate(-80, 0, 1, 0)->translate(2, 0.2, -4));

   grupTenda->addGrupObjek(kiriBelakang);
   GrupObjek* kananBelakang = kiriBelakang->clone()->flip(1, 0)->translate(-7, 0, 0);
   grupTenda->addGrupObjek(kananBelakang);

   delete kiriBelakang;
   delete kananBelakang;
   delete kiriDepan;
   delete kananDepan;

   return grupTenda;
}

float verticesRanting1[][3] = {
    // 1
    {-0.031892, -0.291891, 0.5},
    // 2
    {0.129402, -0.270182, 0.5},
    // 3
    {-0.189414, -0.274032, 0.5},
    // 4
    {-0.061504, 0.017197, 0.082191},
    // 5
    {0.019485, 0.029418, 0.023855},
    // 6
    {0.008997, 0.258195, -0.442532},
    // 7
    {-0.017956, 0.254129, -0.423119},
    // 8
    {0.145628, -0.005216, 0.5},
    // 9
    {0.097970, -0.019346, 0.057366},
    // 10
    {0.035116, 0.241967, -0.431380},
    // 11
    {0.027438, 0.068217, 0.5},
    // 12
    {-0.094524, 0.049814, 0.5},
    // 13
    {-0.004114, 0.178615, -0.454865},
    // 14
    {-0.038925, 0.182562, -0.434223},
    // 15
    {0.031530, 0.183413, -0.440101},
    // 16
    {0.087195, -0.195297, 0.031162},
    // 17
    {-0.124516, -0.197854, 0.048822},
    // 18
    {-0.019913, -0.209713, -0.013203},
};

int facesRanting1[][6] = {
    {4, 5, 6, 7},
    {5, 9, 10, 6},
    {9, 16, 15, 10},
    {17, 4, 7, 14},
    {16, 18, 13, 15},
    {12, 11, 5, 4},
    {11, 8, 9, 5},
    {8, 2, 16, 9},
    {3, 12, 4, 17},
    {1, 3, 17, 18},
    {2, 1, 18, 16},
    {13, 16, 17, 14},
    {14, 7, 6, 13},
    {15, 13, 6, 10},
    {1, 2, 8, 11, 12, 3}
};

Objek* ranting()
{
    Objek* objek = new Objek();
    for(auto &point : facesRanting1) {
        Face* face = new Face();
        for(auto &index : point) {
            if(index != 0) {
                face->addVertex(verticesRanting1[index - 1]);
            }
        }
        objek->addFace(face);
    }

    return objek;
}

float verticesBatang1[][3] = {
    // 1
    {1.051231, 1.906587, 2.145407},
    // 2
    {1.217161, 1.934948, 2.372225},
    // 3
    {1.217161, 1.886114, 2.372225},
    // 4
    {1.034899, 2.522174, 2.513387},
    // 5
    {0.756094, 2.003048, 2.401768},
    // 6
    {0.827764, 1.953705, 2.533518},
    // 7
    {1.151993, 2.639001, 2.265206},
    // 8
    {1.342153, 3.448640, 2.342264},
    // 9
    {1.452317, 3.445952, 2.322097},
    // 10
    {0.989057, -0.056692, 2.093860},
    // 11
    {1.189069, -0.054295, 2.183975},
    // 12
    {1.208612, 0.015763, 2.373020},
    // 13
    {1.186031, -0.056915, 2.569200},
    // 14
    {0.980779, -0.054407, 2.646884},
    // 15
    {0.834643, 0.022913, 2.524968},
    // 16
    {0.710583, -0.056815, 2.372225},
    // 17
    {0.797539, -0.051990, 2.180735},
    // 18
    {1.485597, 3.433751, 2.336778},
    // 19
    {1.405252, 3.463208, 2.372226},
    // 20
    {1.419037, 3.458154, 2.407671},
    // 21
    {1.452317, 3.445952, 2.422354},
    // 22
    {1.485597, 3.433751, 2.407671},
    // 23
    {1.499382, 3.428697, 2.372226},
    // 24
    {0.977555, 2.649610, 2.359138},
    // 25
    {1.214754, 2.401829, 2.372226},
    // 26
    {1.197155, 2.585004, 2.441133},
    // 27
    {1.215533, 2.275079, 2.372226},
    // 28
    {1.081275, 0.995533, 2.184412},
    // 29
    {1.071074, 1.008458, 2.565968},
    // 30
    {0.809511, 1.638114, 2.247143},
    // 31
    {0.926425, 2.278327, 2.287776}
};

int facesBatang1[][8] = {
    {15, 29, 4, 5, 6},
    {8, 24, 19},
    {4, 26, 22, 21},
    {4, 21, 20},
    {26, 7, 18, 23},
    {10, 17, 30, 28},
    {26, 2, 27},
    {30, 1, 28},
    {15, 6, 5},
    {24, 4, 20, 19},
    {3, 12, 28, 1, 2},
    {26, 27, 25},
    {23, 18, 9, 8, 19, 20, 21, 22},
    {17, 10, 11, 12, 13, 14, 15, 16},
    {29, 12, 3, 2, 26},
    {2, 1, 7, 26, 25, 27},
    {5, 31, 24, 8, 7, 1, 30},
    {7, 8, 9},
    {22, 26, 23},
    {18, 7, 9},
    {30, 15, 5},
    {10, 28, 11},
    {11, 28, 12},
    {13, 12, 29},
    {13, 29, 14},
    {14, 29, 15},
    {16, 15, 30},
    {16, 30, 17},
    {26, 4, 29},
    {4, 24, 5},
    {24, 3,1, 5}
};

Objek* batang(){
    Objek* batang = new Objek();
    for(auto &point : facesBatang1) {
        Face* face = new Face();
        for(auto &index : point) {
            if(index != 0)
                face->addVertex(verticesBatang1[index - 1]);
        }
        face->translate(-1, 0, -2.5);
        batang->addFace(face);
    }
    batang->setColor(ColorList::batang());

    return batang;
}

float verticesBatangBunga[][3] = {
    {0.05, -0.1, -0.1},
    {0.14, -0.03, -0.05},
    {-0.07, 0.2, -0.04},
    {0.139850, -0.030283, 0.045000},
    {-0.068057, 0.185112, 0.048262},
    {0.043694, -0.099482, 0.090023},
    {0.029195, -0.140081, 0.045000},
    {-0.200127, 0.101392, 0.046854},
    {-0.019071, -0.137434, -0.048185},
    {-0.432569, 0.895928, -0.026689},
    {-0.461260, 0.979292, 0.062347},
    {-0.501757, 0.870511, 0.108150},
    {-0.567786, 0.831896, 0.063585},
    {-0.569976, 0.838196, -0.026321},
    {-0.457440, 0.767575, -0.069375},
    {-0.583367, 1.324180, -0.075550},
    {-0.533028, 1.376692, 0.019795},
    {-0.572542, 1.330155, 0.105333},
    {-0.634367, 1.282692, 0.060333},
    {-0.634367, 1.282692, -0.029667}
};

int facesBatangBunga[][6] = {
    {15, 1, 9, 14},
    {6, 8, 7},
    {2, 3, 5, 4},
    {1, 2, 4, 6, 7, 9},
    {9, 8, 13, 14},
    {8, 6, 12, 13},
    {6, 5, 11, 12},
    {11, 5, 3, 10},
    {10, 3, 1, 15},
    {14, 13, 19, 20},
    {10, 15, 16},
    {16, 14, 20},
    {13, 12, 18, 19},
    {12, 11, 17, 18},
    {11, 10, 17},
    {2, 1, 3},
    {4, 5, 6},
    {7, 8, 9},
    {16, 15, 14},
    {17, 10, 16}
};

Objek* batang2()
{
    Objek* batang = new Objek();
    for(auto &faces : facesBatangBunga) {
        Face* face = new Face();
        for(auto &index : faces) {
            if(index != 0)
                face->addVertex(verticesBatangBunga[index - 1]);
        }
        batang->addFace(face);
    }

    return batang;
}

float verticesMahkotaBunga[][3] = {
    {-0.968384, 0.008238, 0.113604},
    {0.031616, 0.008238, 0.113604},
    {-1.968384, 0.008238, -5.106396},
    {0.031616, 0.008238, -5.106396},
    {-1.168384, -0.160970, -7.106396},
    {0.031616, -0.160970, -7.606396}
};

int facesMahkotaBunga[][4] = {
    {1, 2, 4, 3},
    {3, 4, 6, 5}
};

Objek* mahkotaBunga()
{
    Objek* mahkota = new Objek();
    for(auto &faces : facesMahkotaBunga) {
        Face* face = new Face();
        for(auto &index : faces) {
            if(index != 0)
                face->addVertex(verticesMahkotaBunga[index - 1]);
        }
        mahkota->addFace(face);
        mahkota->addFace(face->clone()->flip(1, 0)->translate(0.05, 0, 0));
    }

    return mahkota->scale(0.1, 0.1, 0.1);
}

float verticesDaunTeratai[][3] = {
    {-0.3, -0.35, 1.24},
    {-0.7, -0.35, 1.33},
    {-1.04, -0.35, 1.57},
    {-1.25, -0.35, 1.9},
    {-1.3, -0.35, 2.35},
    {-1.16, -0.35, 2.74},
    {-0.884141, -0.35, 3.051829},
    {-0.504267, -0.35, 3.220960},
    {-0.088444, -0.35, 3.220959},
    {0.291430, -0.35, 3.051829},
    {0.569670, -0.35, 2.742812},
    {0.698166, -0.35, 2.347340},
    {0.654701, -0.35, 1.933795},
    {0.446789, -0.35, 1.573681},
    {0.110381, -0.35, 1.329266},
    {-0.296374, -0.26, 1.242810},
    {-0.275310, -0.349187, 2.234165},
    {-0.703110, -0.26, 1.329265},
    {-1.039518, -0.26, 1.573679},
    {-1.247430, -0.26, 1.933793},
    {-1.290895, -0.26, 2.347338},
    {-1.162399, -0.26, 2.742810},
    {-0.884159, -0.26, 3.051827},
    {-0.504285, -0.26, 3.22},
    {-0.088462, -0.26, 3.22},
    {0.291412, -0.26, 3.051827},
    {0.569652, -0.26, 2.742810},
    {0.698148, -0.26, 2.347338},
    {0.654683, -0.26, 1.933793},
    {0.446771, -0.26, 1.573679},
    {0.110363, -0.26, 1.329264},
    {-0.275328, -0.260581, 2.234163}
};

int facesDaunTeratai[][9] = {
    {18, 19, 20, 32, 28, 29, 30, 31, 16},
    {8, 9, 25, 24},
    {6, 7, 23, 22},
    {17, 5, 21, 32},
    {4, 17, 32, 20},
    {15, 1, 16, 31},
    {2, 3, 19, 18},
    {13, 14, 30, 29},
    {11, 12, 28, 27},
    {9, 10, 26, 25},
    {7, 8, 24, 23},
    {5, 6, 22, 21},
    {3, 4, 20, 19},
    {14, 15, 31, 30},
    {1, 2, 18, 16},
    {12, 13, 29, 28},
    {10, 11, 27, 26},
    {22, 23, 24, 25, 26, 27, 28, 32, 21},
    {6, 5, 17, 12, 11, 10, 9, 8, 7},
    {2, 1, 15, 14, 13, 12, 17, 4, 3}
};

Objek* daunTeratai()
{
    Objek* objek = new Objek();
    for(auto &faces : facesDaunTeratai) {
        Face* face = new Face();
        for(auto &index : faces) {
            if(index != 0)
                face->addVertex(verticesDaunTeratai[index - 1]);
        }
        objek->addFace(face);
    }

    return objek;
}

float verticesMahkotaTeratai[][3] = {
    {-0.776925, 0.076725, 1.002138},
    {0.819155, 0.091338, 0.985649},
    {-0.999924, 0.196611, 0.008720},
    {0.999885, 0.214922, -0.011940},
    {-0.113776, 1.235504, -2.949503},
    {-1.027418, 0.417440, -0.982802},
    {0.972391, 0.435751, -1.003462},
    {-0.775393, 0.753936, -1.933755},
    {0.709386, 0.767530, -1.949094},
    {0.030768, 0.024745, 1.966588}
};

int facesMahkotaTeratai[][4] = {
    {1, 2, 4, 3},
    {10, 2, 1},
    {3, 4, 7, 6},
    {6, 7, 9, 8},
    {5, 8, 9}
};

Objek* mahkotaTeratai()
{
    Objek* objek = new Objek();
    for(auto &faces : facesMahkotaTeratai) {
        Face* face = new Face();
        for(auto &index : faces) {
            if(index != 0)
                face->addVertex(verticesMahkotaTeratai[index - 1]);
        }
        objek->addFace(face);
    }

    objek->translate(0, 0, -2)->scale(0.1, 0.1, 0.1);

    return objek;
}

float verticesReed[][3] = {
    {-0.127489, -0.271634, -0.105701},
    {0.082253, -0.271634, -0.105701},
    {-0.120050, -0.032505, -0.099775},
    {0.072044, -0.032505, -0.099775},
    {-0.115124, 0.178125, -0.075841},
    {0.061316, 0.178125, -0.075841},
    {-0.108494, 0.359291, -0.046412},
    {0.049586, 0.359291, -0.046412},
    {-0.100414, 0.528725, -0.002218},
    {0.037563, 0.528725, -0.002218},
    {-0.082844, 0.650867, 0.048593},
    {0.029519, 0.650867, 0.048593},
    {-0.071044, 0.719665, 0.096895},
    {0.024417, 0.719665, 0.096895},
    {-0.063504, 0.776244, 0.169768},
    {0.021365, 0.776244, 0.169768},
    {-0.056137, 0.795758, 0.242762},
    {0.017680, 0.795758, 0.242762},
    {-0.043637, 0.794501, 0.328001},
    {0.009079, 0.794501, 0.328001},
    {-0.010236, 0.768653, 0.405202}
};

int facesReed[][4] = {
    {2, 1, 3, 4},
    {4, 3, 5, 6},
    {6, 5, 7, 8},
    {8, 7, 9, 10},
    {10, 9, 11, 12},
    {12, 11, 13, 14},
    {14, 13, 15, 16},
    {16, 15, 17, 18},
    {18, 17, 19, 20},
    {20, 19, 21}
};

Objek* reed()
{
    Objek* objek = new Objek();
    for(auto &faces : facesReed) {
        Face* face = new Face();
        for(auto &index : faces) {
            if(index != 0)
                face->addVertex(verticesReed[index - 1]);
        }
        objek->addFace(face);
    }

    return objek->translate(0, 0.45, 0);
}