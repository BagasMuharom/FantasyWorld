#ifndef COLOR_H
#define COLOR_H

#include "GL/glut.h"
#include "Material.h"
#include <iostream>

using namespace std;

#define MATERIAL_HIJAU 0
#define MATERIAL_BIRU_MUDA 1
#define MATERIAL_BIRU 2
#define MATERIAL_COKLATMUDA 3
#define MATERIAL_COKLATTUA 4
#define MATERIAL_PUTIH 5


class Color {

public:
    Color(GLubyte r, GLubyte g, GLubyte b) {
        this->r = r;
        this->g = g;
        this->b = b;
    };

    Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        this->useAlpha = !this->useAlpha;
    };

    void set(bool autoDelete = false) {
        if(!this->useAlpha)
            glColor3ub(this->r, this->g, this->b);
        else
            glColor4ub(this->r, this->g, this->b, this->a);

        switch(this->material) {
            case MATERIAL_BIRU:
                Material::biru();
                break;
            case MATERIAL_BIRU_MUDA:
                Material::biruMuda();
                break;
            case MATERIAL_COKLATMUDA:
                Material::coklatMuda();
                break;
            case MATERIAL_COKLATTUA:
                Material::coklatTua();
                break;
            case MATERIAL_HIJAU:
                Material::hijau();
                break;
            case MATERIAL_PUTIH:
                Material::putih();
                break;
        }

        if(autoDelete)
            delete this;
    }

    Color* setAlpha(GLubyte alpha) {
        this->a = alpha;
        this->useAlpha = true;
    }

    void setMaterial(short int material) {
        this->material = material;
    }

    Color operator+(Color color) {
        GLubyte r = color.r + r;
        GLubyte g = color.g + g;
        GLubyte b = color.b + b;

        return Color(r, g, b);
    }

    Color operator-(Color color) {
        GLubyte r = r - color.r;
        GLubyte g = g - color.g;
        GLubyte b = b - color.b;

        return Color(r, g, b);
    }

    GLubyte r, g, b, a;

private:
    bool useAlpha = false;
    short int material = -1;
};

class ColorList {
public:

    static Color* batang() {
        Color* color = new Color(150, 106, 74);
        color->setMaterial(MATERIAL_COKLATTUA);
        return color;
//        return new Color(134, 103, 59);
    }

    static Color* jalan() {
        return new Color(210, 150, 100);
//        return new Color(216, 192, 102);
    }

    static Color* daun() {
        Color* color = new Color(140, 193, 66);
        color->setMaterial(MATERIAL_HIJAU);
        return color;
//        return new Color(119, 181, 69);
    }

    static Color* rumput() {
        Color* color = new Color(124, 173, 60);
        color->setMaterial(MATERIAL_HIJAU);
        // return new Color(193, 212, 82);
       return color;
        // return new Color(128, 165, 51);
    }

    static Color* kuning() {
        return new Color(240, 205, 39);
    }

    static Color* jingga() {
        return new Color(233, 153, 12);
    }

    static Color* hijau(int option) {
        Color* color;
        switch(option) {
        case 1:
            color = new Color(75, 171, 74);
            break;
        }
        color->setMaterial(MATERIAL_HIJAU);
    }

    static Color* putih() {
        Color* color = new Color(255, 255, 255);
        color->setMaterial(MATERIAL_PUTIH);
        return color;
    }

    static Color* air() {
        return new Color(19, 165, 214);
    }

    static Color* batu() {
        return new Color(150, 150, 150);
    }

    static Color* coklatMuda() {
        Color* color = new Color(238, 171, 114);
        color->setMaterial(MATERIAL_COKLATMUDA);
        return color;
    }

};

#endif
