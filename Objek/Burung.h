#ifndef BURUNG_H
#define BURUNG_H

class Burung {
public:
    Burung(float scale);
    void draw();
    Burung* rotatePos(float degree, bool x, bool y, bool z, float a, float b);
    Burung* rotate(float degree, bool x, bool y, bool z);
    Burung* translate(float x, float y, float z);
    static Burung* create(float scale);
    ~Burung();

private:
    float scale;
    float rotation;
    float posX = 0, posY = 0, posZ = 0, a = 0, b = 0;
    float rotateX = 0, rotateY = 0, rotateZ = 0;
};

#endif