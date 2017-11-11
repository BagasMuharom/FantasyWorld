#ifndef CARTESIUS_H
#define CARTESIUS_H

class Cartesius {
    
public:
    Cartesius(
        float x,
        float y,
        float z,
        float incX,
        float incY,
        float incZ
    );
    void draw();

private:

    struct element {
        int start;
        int end;
        int increment;
    };

    Cartesius::element* x;
    Cartesius::element* y;
    Cartesius::element* z;

    void drawX();
    void drawY();
    void drawZ();

};

#endif