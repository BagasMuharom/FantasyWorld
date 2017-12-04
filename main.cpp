#include "GL/glut.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include "Input/Mouse.h"
#include "Input/Keyboard.h"
#include "Util/Camera.h"
#include "Util/Util.h"
#include "Util/Color.h"
#include "Util/Material.h"
#include "Objek/Cartesius.h"
#include "Objek/Pohon.h"
#include "Objek/Objek.h"
#include "Objek/Misc.h"
#include "Objek/Terrain.h"
#include "Objek/Burung.h"

#define UKURAN_BESAR 0
#define UKURAN_SEDANG 1
#define UKURAN_KECIL 2
#define UKURAN_SANGAT_KECIL 3

using namespace std;

// Objek camera, mouse, keyboard, dll
Camera *camera;
Mouse* mouse;
Keyboard* keyboard;
Cartesius* cartesius;

// simulasi siang dan malam
int detikSatuHari = 3600 * 24;
int pagiAwal = 3600 * 4 + 1;
int pagiAkhir = 3600 * 8;
int siangAwal = 3600 * 8 + 1;
int siangAkhir = 3600 * 14;
int soreAwal = 3600 * 14 + 1;
int soreAkhir = 3600 * 18;
int malamAwal = 3600 * 18 + 1;
int malamAkhir = 3600 * 4;
int waktuSekarang = 3600 * 10;
float LightPosition[] = {0.0f, 0.0f, 0.0f};

// LookAt
float lookX = 0;
float lookY = 0;
float lookZ = 0;

// Lokasi kamera
float cameraX = 0;
float cameraY = 3;
float cameraZ = 4;

// View port
int viewportWidth;
int viewportHeight;

float angleY = 0;

// Untuk keperluan danau

float minTinggi = 0;
float maxTinggi = 0.15;
float minTranslasiArus = -0.2;
float maxTranslasiArus = 0.3;
float translasiArus = minTranslasiArus;
float translasiTinggi = minTinggi; 
float penambahanTranslasiArus = 0.025;
float penambahanTranslasiTinggi = 0.01;

bool tambahTranslasiArus = true;
bool tambahTranslasiTinggi = true;

// Untuk keperluan air terjun

struct Bubble{
    float radius;
    Color* color;
    Vertex v;
};

vector<Face*> blocksAirTerjun;
vector<Face*> blocksAirTerjun2;
vector<Bubble> bubbleAirTerjun;

// Untuk keperluan menaruh objek
Vertex taruhObjek(0, 0, 0);

void initAirTerjun();
void terrainGroup();
void tebing();
void rumputTebing();
void semakSemak();
GrupObjek* semakBesar();
GrupObjek* semakKecil();
GrupObjek* semakSedang();
void idleDanau();
void idleSimulasiWaktu();
void pohonCemara(int ukuran = UKURAN_BESAR);
void pohonBiasa(int ukuran = UKURAN_BESAR);
void pohonCabangBanyak(int ukuran = UKURAN_BESAR);
void pohonEsKrim(int ukuran = UKURAN_BESAR);
void bukit();
void tembelanDanau();
void danau();
void airDanau();
void idleAirTerjun();
void airTerjunTingkat();
void bebatuan();
void initBubble();
void idleBubble();
void showBubble();

void setlight()
{
//     float LightPosition[] = {cameraX, cameraY, cameraZ};
    float LightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float LightEmission[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float LightDiffuse[] = {1.0f, 1.0f, 0.8f, 1.0f};
    float LightSpecular[] = {.2f, .2f, .2f, 1.0f};
    float LightPositionLocal[] = {LightPosition[0], LightPosition[1], LightPosition[2]};
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPositionLocal);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    //glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 50);
//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0f);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 25.0f);
    glEnable(GL_LIGHTING);

    float LightPosition1[] = {18, 1, 0};
    float LightAmbient1[] = {0.95f,0.43f,0.0f,1.0f};
    float LightDiffuse1[] = {0.6f,0.4f,0.2f,1.0f};
    float LightSpecular1[] = {0.99f,0.58f,0.11f,1.0f};
    float LightDirection[]    = {1, 1, 1, 0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 5);
    glLightf( GL_LIGHT1, GL_LINEAR_ATTENUATION , 0.2f );
    glLightf( GL_LIGHT1, GL_QUADRATIC_ATTENUATION , 0.0009f );

    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
}

void init()
{
    camera = new Camera(&cameraX, &cameraY, &cameraZ, &lookX, &lookY, &lookZ);
    camera->setTranslationSpeed(1);

    mouse = new Mouse(camera, viewportWidth, viewportHeight);
    keyboard = new Keyboard(camera, mouse);
    cartesius = new Cartesius(
        42, 25, 42, 1, 1, 1);

    initAirTerjun();
    initBubble();

    srand(time(NULL));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // kalau pakai color langsung material
    //glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    mouse->cursorToggle();
    glClearColor(0.529, 0.807, 0.98, 1);
    //glClearColor(0, 0, 0, 0);
}

void idle()
{
//    angleY += 0.01;
    idleDanau();
    idleBubble();
    idleAirTerjun();
    idleSimulasiWaktu();
    glutPostRedisplay();
}

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

void idleDanau()
{
    if(tambahTranslasiArus && translasiArus + penambahanTranslasiArus > maxTranslasiArus)
        tambahTranslasiArus = !tambahTranslasiArus;
    
    if(!tambahTranslasiArus && translasiArus - penambahanTranslasiArus < minTranslasiArus)
        tambahTranslasiArus = !tambahTranslasiArus;

    if(tambahTranslasiArus)
        translasiArus += penambahanTranslasiArus;
    else
        translasiArus -= penambahanTranslasiArus;
    
    if(tambahTranslasiTinggi && translasiTinggi + penambahanTranslasiTinggi > maxTinggi)
        tambahTranslasiTinggi = !tambahTranslasiTinggi;
    
    if(!tambahTranslasiTinggi && translasiTinggi - penambahanTranslasiTinggi < minTinggi)
        tambahTranslasiTinggi = !tambahTranslasiTinggi;

    if(tambahTranslasiTinggi)
        translasiTinggi += penambahanTranslasiTinggi;
    else
        translasiTinggi -= penambahanTranslasiTinggi;
}

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        cameraX, cameraY, cameraZ,
        lookX, lookY, lookZ,
        0, 1, 0);

    setlight();

    //cartesius->draw();

    // Misc::bungaTeratai();

    glPushMatrix();
    glTranslatef(taruhObjek.x, taruhObjek.y, taruhObjek.z);
    pohonCemara();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0, 0);
    Misc::serumpunBunga1();
    glPopMatrix();

    // Jamur start

    glPushMatrix();
    Misc::jamur();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0 ,-0.5);
    Misc::jamur(0.6, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0 ,-0.5);
    Misc::jamur(0.6, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0 ,-0.7);
    Misc::jamur(0.4, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6, 0 ,-0.9);
    Misc::jamur(0.2, 1);
    glPopMatrix();

    // Jamur end

    bukit();

    danau();

    // Tebing mulai

    glPushMatrix();
    glTranslatef(42, 0, -23);
    tebing();
    glPopMatrix();

    // glPushMatrix();
    // pohonCemara();
    // glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    pohonCemara(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6, 0, 0);
    pohonCemara(UKURAN_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9, 0, 0);
    pohonCemara(UKURAN_SANGAT_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -5);
    pohonBiasa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, -5);
    pohonBiasa(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, -5);
    pohonBiasa(UKURAN_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 0, -5);
    pohonBiasa(UKURAN_SANGAT_KECIL);
    glPopMatrix();
    
    // glPushMatrix();
    // glTranslatef(0, 0, 5);
    // pohonCabangBanyak();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-5, 0, 5);
    // pohonCabangBanyak(UKURAN_SEDANG);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-10, 0, 5);
    // pohonCabangBanyak(UKURAN_KECIL);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-15, 0, 5);
    // pohonCabangBanyak(UKURAN_SANGAT_KECIL);
    // glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 10);
    pohonEsKrim();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5, 0, 10);
    pohonEsKrim(UKURAN_SEDANG);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, 10);
    pohonEsKrim(UKURAN_KECIL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 0, 10);
    pohonEsKrim(UKURAN_SANGAT_KECIL);
    glPopMatrix();

    // Tebing akhir

    // Tenda mulai

    // glPushMatrix();
    // glTranslatef(6, 0.16, -14);
    // glRotatef(45, 0, 1, 0);
    // tenda()->scale(0.75, 0.75, 0.75)->draw();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(0, 0.16, -4);
    // glRotatef(90, 0, 1, 0);
    // tenda()->scale(0.75, 0.75, 0.75)->draw();
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(1.5, 0.16, 8);
    // glRotatef(135, 0, 1, 0);
    // tenda()->scale(0.75, 0.75, 0.75)->draw();
    // glPopMatrix();

    //Misc::bunga()->rotate(45, 0, 0, 1)->translate(0, 0.5, 0)->draw();

    glPushMatrix();
    glTranslatef(7, 0.16, 0);
    glScalef(1.5, 1.5, 1.5);
    Misc::kayuUnggun();
    glPopMatrix();

    // Tenda akhir

    glPushMatrix();
    glTranslatef(4, 0, 0);
    semakSemak();
    glPopMatrix();

    //ColorList::batang()->set(true);
    //bebatuan();

    glPushMatrix();
    glTranslatef(0, 0, 5);
    Misc::gapura();
    glPopMatrix();

    // TERRAIN
    terrainGroup();

    // Bawah
    glPushMatrix();
    ColorList::batang()->set(true);
    trapesiumSamaSisi(60, 60, 84, 84, 30, 0, 1, 1, 1, 1, 1)->translate(-30, -30.1, -30)->draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14 + (translasiArus / 5), translasiTinggi - 0.2, 0);
    glRotatef(-(translasiArus + translasiTinggi) / 2 * 20, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0.25, 0.25, -2.2);
    daunTeratai()->setColor(ColorList::hijau(1))->draw();
    glPopMatrix();
    glPushMatrix();
    Misc::bungaTeratai();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(LightPosition[0], LightPosition[1], LightPosition[2]);
    glColor4ub(255, 255, 255, 150);
    glutSolidSphere(5, 20, 20);
    glPopMatrix();

    airDanau();

    tembelanDanau();

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

    airTerjunTingkat();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    viewportWidth = w;
    viewportHeight = h;

    gluPerspective(45, (GLfloat)w / (GLfloat)h, 1.0, 5000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (camera->isFPSMode())
        glutWarpPointer(viewportWidth / 2, viewportHeight / 2);
}

void specialFunc(int key, int x, int y)
{
    if(keyboard->specialKeyAction(key, x, y))
        glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch(key) {
        case 'u':
            taruhObjek.translate(0, 0, -1);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
        case 'j':
            taruhObjek.translate(0, 0, 1);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
        case 'k':
            taruhObjek.translate(1, 0, 0);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
        case 'h':
            taruhObjek.translate(-1, 0, 0);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
        case 'y':
            taruhObjek.translate(0, 0.1, 0);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
        case 'i':
            taruhObjek.translate(0, -0.1, 0);
            cout << taruhObjek.x << " " << taruhObjek.y << " " << taruhObjek.z << endl;
            break;
    }
    if(keyboard->keyAction(key, x, y))
        glutPostRedisplay();
}

void mousePassive(int x, int y)
{
    mouse->passive(x, y);

    // Meningkatkan efisiensi penggunaan CPU
    // OpenGL akan merender ulang hanya jika mode camera adalah
    // fps, jika tidak, maka tidak perlu merender
    if(camera->isFPSMode())
        glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    viewportWidth = glutGet(GLUT_SCREEN_WIDTH) / 1.5;
    viewportHeight = glutGet(GLUT_SCREEN_HEIGHT) / 1.5;

    glutInitWindowSize(viewportWidth, viewportHeight);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(
        (glutGet(GLUT_SCREEN_WIDTH) - viewportWidth) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - viewportHeight) / 2
    );
    glutCreateWindow("Fantasy World");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mousePassive);
    glutKeyboardFunc(keyboardFunc);
    glutSpecialFunc(specialFunc);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}

void pohonCemara(int ukuran)
{
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            (new Pohon())->Cemara(7, 1.5, 2, 1, 3)->draw();
            break;
        case UKURAN_SEDANG:
            (new Pohon())->Cemara(5, 1.5, 1.8, 1, 2.8)->draw();
            break;
        case UKURAN_KECIL:
            (new Pohon())->Cemara(4, 1, 1.4, 0.75, 2.4)->draw();
            break;
        case UKURAN_SANGAT_KECIL:
            (new Pohon())->Cemara(3, 0.75, 1, 0.5, 1.75)->draw();
            break;
    }
    glPopMatrix();
}

void pohonCabangBanyak(int ukuran)
{
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            (new Pohon())->CabangBanyak(5)->draw();
            semak()->setColor(ColorList::hijau(1))->scale(0.4, 0.4, 0.4)->translate(0, 5, 0)->draw();
            break;
        case UKURAN_SEDANG:
            (new Pohon())->CabangBanyak(4)->scale(0.75, 0.75, 0.75)->draw();
            semak()->setColor(ColorList::hijau(1))->scale(0.3, 0.3, 0.3)->translate(0, 3.75, 0)->draw();
            break;
        case UKURAN_KECIL:
            (new Pohon())->CabangBanyak(3)->scale(0.5, 0.5, 0.5)->draw();
            break;
        case UKURAN_SANGAT_KECIL:
            (new Pohon())->CabangBanyak(2)->scale(0.25, 0.25, 0.25)->draw();
            break;
    }
    glPopMatrix();
}

void pohonBiasa(int ukuran)
{
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            (new Pohon())->Biasa(8, 6)->draw();
            break;
        case UKURAN_SEDANG:
            (new Pohon())->Biasa(6, 6)->scale(0.75, 0.75, 0.75)->draw();
            break;
        case UKURAN_KECIL:
            (new Pohon())->Biasa(4, 6)->scale(0.5, 0.5, 0.5)->draw();
            break;
        case UKURAN_SANGAT_KECIL:
            (new Pohon())->Biasa(3, 6)->scale(0.25, 0.25, 0.25)->draw();
            break;
    }
    glPopMatrix();
}

void pohonEsKrim(int ukuran)
{
    glPushMatrix();
    switch(ukuran) {
        case UKURAN_BESAR:
            (new Pohon())->EsKrim(1.5, 5, 1.5);
            break;
        case UKURAN_SEDANG:
            (new Pohon())->EsKrim(1, 4, 1);
            break;
        case UKURAN_KECIL:
            (new Pohon())->EsKrim(0.7, 3, 0.8);
            break;
        case UKURAN_SANGAT_KECIL:
            (new Pohon())->EsKrim(0.5, 2, 0.7);        
            break;
    }
    glPopMatrix();
}

void semakSemak()
{
    semakBesar()->scale(1.25, 1, 1.25)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(1, 0, 0.6)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(-1, 0, 0.6)->draw();
    semakSedang()->scale(1, 0.8, 1)->translate(-0.975, 0, -0.375)->draw();
    semakKecil()->translate(0.375, 0, 0.975)->draw();
    semakKecil()->translate(-0.375, 0, -0.95)->draw();
    semakKecil()->translate(1, 0, -0.15)->draw();
}

GrupObjek* semakBesar()
{
    GrupObjek* semakObjek = new GrupObjek();
    semakObjek->addObjek(semak()->translate(0, 0.9, 0)->setColor(ColorList::hijau(1)));
    semakObjek->addObjek(semak()->scale(0.15, 0.15, 0.15)->translate(0.5, 1.2, 0.75)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.15, 0.15, 0.15)->translate(0, 1.8, 0)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.08, 0.08, 0.08)->translate(-0.55, 1.4, 0.8)->setColor(new Color(200, 0, 0)));
    semakObjek->addObjek(semak()->scale(0.08, 0.08, 0.08)->translate(0.4, 1.4, -0.7)->setColor(new Color(200, 0, 0)));

    return semakObjek->scale(0.75, 0.75, 0.75);
}

GrupObjek* semakKecil()
{
    return semakBesar()->rotate(-45, 0, 1, 0)->scale(0.5, 0.5, 0.5);
}

GrupObjek* semakSedang()
{
    return semakBesar()->rotate(180, 0, 1, 0)->scale(0.75, 0.75, 0.75);
}

void tebing()
{
    // LEVEL 1
    (new Color(186, 131, 79))->set(true);
    GrupObjek* partTebing1 = new GrupObjek();

    partTebing1->addObjek(trapesiumSiku(6, 20, 5, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 0));

    partTebing1->addObjek(trapesiumSiku(6, 20, 5, 20, 4)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0));

    partTebing1->translate(0, 0, 0)->draw(false);

    partTebing1->clone()->scale(1, 1, 1.5)->translate(0, 0, 10)->draw();

    partTebing1->clone()->scale(1, 1, 0.5)->translate(0, 0, 18)->draw();

    delete partTebing1;

    // balok air terjun
    balok(4, 6, 19)->translate(-4, 0, 20)->draw();

    trapesiumSiku(7, 20, 5, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 30)->draw();

    balok(7, 2, 20)->translate(-7, 0, 30)->draw();

    trapesiumSiku(7, 20, 6, 20, 2)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, 32)->draw();

    balok(6, 3, 20)->translate(-6, 0, 34)->draw();

    trapesiumSiku(6, 20, 8, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 41)->draw();

    trapesiumSiku(6, 20, 9, 20, 8)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, 41)->draw();

    trapesiumSiku(4, 20, 9, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 53)->draw();

    // LEVEL 2
    // balok air terjun
    balok(7, 6, 14)->translate(-11, 0, 20)->draw();

    trapesiumSiku(6, 15, 7, 15, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 14)->draw();

    balok(6, 4, 15)->translate(-11, 0, 11)->draw();

    trapesiumSiku(6, 15, 10, 15, 8)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 15, 11)->draw();

    balok(10, 3, 15)->translate(-15, 0, 0)->draw();

    trapesiumSiku(13, 15, 15, 15, 12)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, -10)->draw();

    // kiri

    trapesiumSiku(7, 15, 10, 15, 7)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 26)->draw();

    balok(10, 5, 15)->translate(-15, 0, 33)->draw();

    trapesiumSiku(9, 15, 10, 15, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-6, 0, 38)->draw();

    trapesiumSiku(10, 15, 5, 15, 7)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 44)->draw();

    // LEVEL 3
    // balok air terjun
    balok(5, 6, 9)->translate(-15, 0, 20)->draw();

    balok(6, 3, 10)->translate(-16, 0, 17)->draw();

    trapesiumSiku(8, 10, 6, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-10, 0, 11)->draw();

    trapesiumSiku(4, 10, 8, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-10, 0, 5)->draw();

    // kiri

    trapesiumSiku(4, 10, 6, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-12, 0, 26)->draw();
    
    trapesiumSiku(6, 10, 4, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-12, 0, 32)->draw();

    rumputTebing();

}

void rumputTebing()
{
    ColorList::rumput()->set();
    GrupObjek* level1 = new GrupObjek();

    level1->addObjek(trapesiumSiku(6, 20, 5, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 0));

    level1->addObjek(trapesiumSiku(6, 20, 5, 20, 4)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0));

    GrupObjek* temp1 = level1->clone()->scale(1, 1, 1.5)->translate(0, 0, 10);

    GrupObjek* temp2 = level1->clone()->scale(1, 1, 0.5)->translate(0, 0, 18);

    level1->addGrupObjek(temp1)->addGrupObjek(temp2);

    delete temp1;
    delete temp2;

    // balok air terjun
    //balok(4, 6, 19)->translate(-4, 0, 20)->draw();

    level1->addObjek(trapesiumSiku(7, 20, 5, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 30));

    level1->addObjek(balok(7, 2, 20)->translate(-7, 0, 30));

    level1->addObjek(trapesiumSiku(7, 20, 6, 20, 2)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, 32));

    level1->addObjek(balok(6, 3, 20)->translate(-6, 0, 34));

    level1->addObjek(trapesiumSiku(6, 20, 8, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 41));

    level1->addObjek(trapesiumSiku(6, 20, 9, 20, 8)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, 41));

    level1->addObjek(trapesiumSiku(4, 20, 9, 20, 4)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 20, 53));

    level1->scale(1, 0.025, 1)->translate(0, 20, 0)->draw();

    // LEVEL 2
    GrupObjek* level2 = new GrupObjek();

    level2->addObjek(trapesiumSiku(6, 15, 7, 15, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 14));

    level2->addObjek(balok(6, 4, 15)->translate(-11, 0, 11));

    level2->addObjek(trapesiumSiku(6, 15, 10, 15, 8)->rotate(90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 15, 11));

    level2->addObjek(balok(10, 3, 15)->translate(-15, 0, 0));

    level2->addObjek(trapesiumSiku(13, 15, 15, 15, 12)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(0, 0, -10));

    // kiri

    level2->addObjek(trapesiumSiku(7, 15, 10, 15, 7)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 26));

    level2->addObjek(balok(10, 5, 15)->translate(-15, 0, 33));

    level2->addObjek(trapesiumSiku(9, 15, 10, 15, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-6, 0, 38));

    level2->addObjek(trapesiumSiku(10, 15, 5, 15, 7)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-5, 0, 44));

    level2->scale(1, 0.03, 1)->translate(0, 15, 0)->draw();

    // LEVEL 3
    GrupObjek* level3 = new GrupObjek();

    level3->addObjek(balok(6, 3, 10)->translate(-16, 0, 17));

    level3->addObjek(trapesiumSiku(8, 10, 6, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-10, 0, 11));

    level3->addObjek(trapesiumSiku(4, 10, 8, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-10, 0, 5));

    // kiri

    level3->addObjek(trapesiumSiku(4, 10, 6, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-12, 0, 26));
    
    level3->addObjek(trapesiumSiku(6, 10, 4, 10, 6)->rotate(-90, 1, 0, 0)->rotate(180, 0, 1, 0)->translate(-12, 0, 32));

    level3->scale(1, 0.05, 1)->translate(0, 10, 0)->draw();
}

void terrainGroup()
{
    terrainGrass()->translate(-39, 0, 39)->draw();
    terrainGround()->translate(-33, 0, 39)->draw();
    terrainGrass()->translate(-27, 0, 39)->draw();
    terrainGrass()->translate(-21, 0, 39)->draw();
    terrainGrass()->translate(-15, 0, 39)->draw();
    terrainGrass()->translate(-9, 0, 39)->draw();
    terrainGrass()->translate(-3, 0, 39)->draw();
    terrainGrass()->translate(3, 0, 39)->draw();
    terrainGrass()->translate(9, 0, 39)->draw();
    terrainGrass()->translate(15, 0, 39)->draw();
    terrainGrass()->translate(21, 0, 39)->draw();
    terrainGrass()->translate(27, 0, 39)->draw();
    terrainGrass()->translate(33, 0, 39)->draw();
    terrainGrass()->translate(39, 0, 39)->draw(); //
    terrainGrass()->translate(-39, 0, 33)->draw();
    terrainRoadRight()->translate(-33, 0, 33)->draw();
    terrainRoadStraight()->rotate(90, 0, 1, 0)->translate(-27, 0, 33)->draw();
    terrainRoadStraight()->rotate(90, 0, 1, 0)->translate(-21, 0, 33)->draw();
    terrainRoadLeft()->rotate(270, 0, 1, 0)->translate(-15, 0, 33)->draw();
    terrainGrass()->translate(-9, 0, 33)->draw();
    terrainGrass()->translate(-3, 0, 33)->draw();
    terrainGrass()->translate(3, 0, 33)->draw();
    terrainGrass()->translate(9, 0, 33)->draw();
    terrainGrass()->translate(15, 0, 33)->draw();
    terrainGrass()->translate(21, 0, 33)->draw();
    terrainGrass()->translate(27, 0, 33)->draw();
    terrainGrass()->translate(33, 0, 33)->draw();
    terrainGrass()->translate(39, 0, 33)->draw(); //
    terrainGrass()->translate(-39, 0, 27)->draw();
    terrainGrass()->translate(-33, 0, 27)->draw();
    terrainGrass()->translate(-27, 0, 27)->draw();
    terrainGrass()->translate(-21, 0, 27)->draw();
    terrainRoadStraight()->translate(-15, 0, 27)->draw();
    terrainGrass()->translate(-9, 0, 27)->draw();
    terrainGrass()->translate(-3, 0, 27)->draw();
    terrainGrass()->translate(3, 0, 27)->draw();
    terrainGrass()->translate(9, 0, 27)->draw();
    terrainGrass()->translate(15, 0, 27)->draw();
    terrainGrass()->translate(21, 0, 27)->draw();
    terrainGrass()->translate(27, 0, 27)->draw();
    terrainGrass()->translate(33, 0, 27)->draw();
    terrainGrass()->translate(39, 0, 27)->draw(); //
    terrainGrass()->translate(-39, 0, 21)->draw();
    terrainGrass()->translate(-33, 0, 21)->draw();
    terrainGrass()->translate(-27, 0, 21)->draw();
    terrainRoadRight()->rotate(90, 0, 1, 0)->translate(-21, 0, 21)->draw();
    terrainRoadLeft()->translate(-15, 0, 21)->draw();
    terrainGrass()->translate(-9, 0, 21)->draw();
    terrainGrass()->translate(-3, 0, 21)->draw();
    terrainGrass()->translate(3, 0, 21)->draw();
    terrainGrass()->translate(9, 0, 21)->draw();
    //terrainGrass()->translate(15, 0, 21)->draw();
    //terrainGrass()->translate(21, 0, 21)->draw();
    terrainGrass()->translate(27, 0, 21)->draw();
    terrainGrass()->translate(33, 0, 21)->draw();
    terrainGrass()->translate(39, 0, 21)->draw(); //
    terrainGrass()->translate(-39, 0, 15)->draw();
    terrainGrass()->translate(-33, 0, 15)->draw();
    terrainGrass()->translate(-27, 0, 15)->draw();
    terrainRoadStraight()->translate(-21, 0, 15)->draw();
    terrainGrass()->translate(-15, 0, 15)->draw();
    terrainRoadLeft()->rotate(180, 0, 1, 0)->translate(-9, 0, 15)->draw();
    terrainRoadStraight()->rotate(90, 0, 1, 0)->translate(-3, 0, 15)->draw();
    terrainGrass()->translate(3, 0, 15)->draw();
    terrainGrass()->translate(9, 0, 15)->draw();
    //terrainGrass()->translate(15, 0, 15)->draw();
    //terrainGrass()->translate(21, 0, 15)->draw();
    terrainGrass()->translate(27, 0, 15)->draw();
    terrainGrass()->translate(33, 0, 15)->draw();
    terrainGrass()->translate(39, 0, 15)->draw(); //
    terrainGrass()->translate(-39, 0, 9)->draw();
    terrainGrass()->translate(-33, 0, 9)->draw();
    terrainGrass()->translate(-27, 0, 9)->draw();
    terrainRoadRight()->translate(-21, 0, 9)->draw();
    terrainRoadTjunction()->rotate(180, 0, 1, 0)->translate(-15, 0, 9)->draw();
    terrainRoadRight()->rotate(270, 0, 1, 0)->translate(-9, 0, 9)->draw();
    terrainGrass()->translate(-3, 0, 9)->draw();
    terrainGrass()->translate(3, 0, 9)->draw();
    terrainGrass()->translate(9, 0, 9)->draw();
    //terrainGrass()->translate(15, 0, 9)->draw();
    //terrainGrass()->translate(21, 0, 9)->draw();
    terrainGrass()->translate(27, 0, 9)->draw();
    terrainGrass()->translate(33, 0, 9)->draw();
    terrainGrass()->translate(39, 0, 9)->draw(); //
    terrainGrass()->translate(-39, 0, 3)->draw();
    terrainGrass()->translate(-33, 0, 3)->draw();
    terrainGrass()->translate(-27, 0, 3)->draw();
    terrainGrass()->translate(-21, 0, 3)->draw();
    terrainRoadStraight()->translate(-15, 0, 3)->draw();
    terrainGrass()->translate(-9, 0, 3)->draw();
    terrainGrass()->translate(-3, 0, 3)->draw();
    terrainGrass()->translate(3, 0, 3)->draw();
    terrainGrass()->translate(9, 0, 3)->draw();
    //terrainGrass()->translate(15, 0, 3)->draw();
    //terrainGrass()->translate(21, 0, 3)->draw();
    //terrainGrass()->translate(27, 0, 3)->draw();
    //terrainGrass()->translate(33, 0, 3)->draw();
    //terrainGrass()->translate(39, 0, 3)->draw(); //
    terrainGrass()->translate(-39, 0, -3)->draw();
    terrainRoadRight()->rotate(90, 0, 1, 0)->translate(-33, 0, -3)->draw();
    terrainRoadStraight()->rotate(90, 0, 1, 0)->translate(-27, 0, -3)->draw();
    terrainRoadStraight()->rotate(90, 0, 1, 0)->translate(-21, 0, -3)->draw();
    terrainRoadLeft()->translate(-15, 0, -3)->draw();
    terrainGrass()->translate(-9, 0, -3)->draw();
    terrainGrass()->translate(-3, 0, -3)->draw();
    terrainGrass()->translate(3, 0, -3)->draw();
    terrainGrass()->translate(9, 0, -3)->draw();
    //terrainGrass()->translate(15, 0, -3)->draw();
    //terrainGrass()->translate(21, 0, -3)->draw();
    //terrainGrass()->translate(27, 0, -3)->draw();
    //terrainGrass()->translate(33, 0, -3)->draw();
    terrainGrass()->translate(39, 0, -3)->draw(); //
    terrainGrass()->translate(-39, 0, -9)->draw();
    terrainRoadStraight()->translate(-33, 0, -9)->draw();
    terrainGrass()->translate(-27, 0, -9)->draw();
    terrainGrass()->translate(-21, 0, -9)->draw();
    terrainGrass()->translate(-15, 0, -9)->draw();
    terrainGrass()->translate(-9, 0, -9)->draw();
    terrainGrass()->translate(-3, 0, -9)->draw();
    terrainGrass()->translate(3, 0, -9)->draw();
    terrainGrass()->translate(9, 0, -9)->draw();
    //terrainGrass()->translate(15, 0, -9)->draw();
    //terrainGrass()->translate(21, 0, -9)->draw();
    terrainGrass()->translate(27, 0, -9)->draw();
    terrainGrass()->translate(33, 0, -9)->draw();
    terrainGrass()->translate(39, 0, -9)->draw(); //
    terrainGrass()->translate(-39, 0, -15)->draw();
    terrainGrass()->translate(-33, 0, -15)->draw();
    terrainGrass()->translate(-27, 0, -15)->draw();
    terrainGrass()->translate(-21, 0, -15)->draw();
    terrainGrass()->translate(-15, 0, -15)->draw();
    terrainGrass()->translate(-9, 0, -15)->draw();
    terrainGrass()->translate(-3, 0, -15)->draw();
    terrainGrass()->translate(3, 0, -15)->draw();
    terrainGrass()->translate(9, 0, -15)->draw();
    //terrainGrass()->translate(15, 0, -15)->draw();
    //terrainGrass()->translate(21, 0, -15)->draw();
    terrainGrass()->translate(27, 0, -15)->draw();
    terrainGrass()->translate(33, 0, -15)->draw();
    terrainGrass()->translate(39, 0, -15)->draw(); //
    terrainGrass()->translate(-39, 0, -21)->draw();
    terrainGrass()->translate(-33, 0, -21)->draw();
    terrainGrass()->translate(-27, 0, -21)->draw();
    terrainGrass()->translate(-21, 0, -21)->draw();
    terrainGrass()->translate(-15, 0, -21)->draw();
    terrainGrass()->translate(-9, 0, -21)->draw();
    terrainGrass()->translate(-3, 0, -21)->draw();
    terrainGrass()->translate(3, 0, -21)->draw();
    terrainGrass()->translate(9, 0, -21)->draw();
    terrainGrass()->translate(15, 0, -21)->draw();
    terrainGrass()->translate(21, 0, -21)->draw();
    terrainGrass()->translate(27, 0, -21)->draw();
    terrainGrass()->translate(33, 0, -21)->draw();
    terrainGrass()->translate(39, 0, -21)->draw(); //
    terrainGrass()->translate(-39, 0, -27)->draw();
    terrainGrass()->translate(-33, 0, -27)->draw();
    terrainGrass()->translate(-27, 0, -27)->draw();
    terrainGrass()->translate(-21, 0, -27)->draw();
    terrainGrass()->translate(-15, 0, -27)->draw();
    terrainGrass()->translate(-9, 0, -27)->draw();
    terrainGrass()->translate(-3, 0, -27)->draw();
    terrainGrass()->translate(3, 0, -27)->draw();
    terrainGrass()->translate(9, 0, -27)->draw();
    terrainGrass()->translate(15, 0, -27)->draw();
    terrainGrass()->translate(21, 0, -27)->draw();
    terrainGrass()->translate(27, 0, -27)->draw();
    terrainGrass()->translate(33, 0, -27)->draw();
    terrainGrass()->translate(39, 0, -27)->draw(); //
    terrainGrass()->translate(-39, 0, -33)->draw();
    terrainGrass()->translate(-33, 0, -33)->draw();
    terrainGrass()->translate(-27, 0, -33)->draw();
    terrainGrass()->translate(-21, 0, -33)->draw();
    terrainGrass()->translate(-15, 0, -33)->draw();
    terrainGrass()->translate(-9, 0, -33)->draw();
    terrainGrass()->translate(-3, 0, -33)->draw();
    terrainGrass()->translate(3, 0, -33)->draw();
    terrainGrass()->translate(9, 0, -33)->draw();
    terrainGrass()->translate(15, 0, -33)->draw();
    terrainGrass()->translate(21, 0, -33)->draw();
    terrainGrass()->translate(27, 0, -33)->draw();
    terrainGrass()->translate(33, 0, -33)->draw();
    terrainGrass()->translate(39, 0, -33)->draw(); //
    terrainGrass()->translate(-39, 0, -39)->draw();
    terrainGrass()->translate(-33, 0, -39)->draw();
    terrainGrass()->translate(-27, 0, -39)->draw();
    terrainGrass()->translate(-21, 0, -39)->draw();
    terrainGrass()->translate(-15, 0, -39)->draw();
    terrainGrass()->translate(-9, 0, -39)->draw();
    terrainGrass()->translate(-3, 0, -39)->draw();
    terrainGrass()->translate(3, 0, -39)->draw();
    terrainGrass()->translate(9, 0, -39)->draw();
    terrainGrass()->translate(15, 0, -39)->draw();
    terrainGrass()->translate(21, 0, -39)->draw();
    terrainGrass()->translate(27, 0, -39)->draw();
    terrainGrass()->translate(33, 0, -39)->draw();
    terrainGrass()->translate(39, 0, -39)->draw(); //
}

void tembelanDanau()
{
    ColorList::rumput()->set(true);
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 21)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, 21)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(17.85, 0, 21)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 18)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, 18)->draw();

    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, 15)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -18.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, -18.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(17.85, 0, -18.15)->draw();
    
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -15.15)->draw();
    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(14.85, 0, -15.15)->draw();

    trapesiumSamaSisi(3.3, 3.3, 3, 3, 0.15, 1, 0, 0, 0, 0, 0)->translate(11.85, 0, -12.15)->draw();
}

void bukit()
{
    ColorList::batu()->set(true);
    trapesiumSiku(12, 10, 11.6, 9.6, 1, 0, 0, 1, 1, 1, 1)->translate(-42, 0, 12)->draw();
    trapesiumSiku(12, 10, 11.6, 9.6, 1, 0, 0, 1, 1, 1, 1)->flip(1, 0, 0)->translate(-42, 0, 12)->draw();
    trapesiumSiku(6, 5, 5.6, 4.6, 1, 0, 0, 1, 1, 1, 1)->translate(-42, 1.15, 12)->draw();
    trapesiumSiku(6, 5, 5.6, 4.6, 1, 0, 0, 1, 1, 1, 1)->flip(1, 0, 0)->translate(-42, 1.15, 12)->draw();

    ColorList::rumput()->set(true);
    trapesiumSiku(11.6, 9.6, 11.5, 9.5, 0.15, 1, 0, 1, 1, 1, 1)->translate(-42, 1, 12)->draw();
    trapesiumSiku(11.6, 9.6, 11.5, 9.5, 0.15, 1, 0, 1, 1, 1, 1)->flip(1, 0, 0)->translate(-42, 1, 12)->draw();
    trapesiumSiku(5.6, 4.6, 5.5, 4.5, 0.15, 1, 0, 1, 1, 1, 1)->translate(-42, 2.15, 12)->draw();
    trapesiumSiku(5.6, 4.6, 5.5, 4.5, 0.15, 1, 0, 1, 1, 1, 1)->flip(1, 0, 0)->translate(-42, 2.15, 12)->draw();
    trapesiumSiku(50, 30, 49, 29, 0.75, 1, 0, 1, 1, 1, 1)->translate(-42, 0.15, -42)->draw();
    trapesiumSiku(45, 25, 44, 24, 0.75, 1, 0, 1, 1, 1, 1)->translate(-42, 0.8, -42)->draw();

    ColorList::batu()->set(true);
    trapesiumSiku(20, 15, 18, 13, 5, 0, 0, 1, 1, 1, 1)->translate(-42, 0.8, -42)->draw();
    trapesiumSiku(15, 10, 14, 9, 3, 0, 0, 1, 1, 1, 1)->translate(-26, 0.8, -42)->draw();

    ColorList::rumput()->set(true);      
    trapesiumSiku(18, 13, 17.8, 12.8, 0.15, 1, 0, 1, 1, 1, 1)->translate(-42, 5.8, -42)->draw();
    trapesiumSiku(14, 9, 13.8, 8.8, 0.15, 1, 0, 1, 1, 1, 1)->translate(-26, 3.8, -42)->draw();

    (new Color(186, 131, 79))->set(true);
    trapesiumSiku(25, 20, 23, 18,5, 0, 0, 1, 1, 1, 1)->flip(0, 0, 1)->translate(42, 0.15, -42)->draw();

    ColorList::rumput()->set(true);
    trapesiumSiku(23, 18, 22.8, 17.8, 0.15, 1, 0, 1, 1, 1, 1)->flip(0, 0, 1)->translate(42, 5.15, -42)->draw();
}

void bebatuan()
{
    Misc::batuKotak2(1);
}

void airDanau()
{
    array<array<float, 2>, 12> satuSisiKiri = {{
        {12, -6},
        {12, -3},
        {12, 0},
        {12, 3},
        {12, 6},
        {12, 9},
        {12, 12},
        {15, 15}, 
        {18, 18},
        {12, -9},
        {15, -12},
        {18, -15}
    }};

    for(auto &sisiKiri : satuSisiKiri) {
        glPushMatrix();
        glTranslatef(sisiKiri[0], -0.25, sisiKiri[1]);
        Misc::blokDanauSatuSisi(translasiTinggi, translasiArus);
        glPopMatrix();
    }

    array<array<float, 2>, 10> satuSisiKanan = {{
        {21, -15},
        {21, -18},
        {21, -9},
        {21, -12},
        {21, 18},
        {21, 21},
        {21, 6},
        {21, 9},
        {21, 12},
        {21, 15},
    }};

    for(auto &sisiKiri : satuSisiKanan) {
        glPushMatrix();
        glTranslatef(sisiKiri[0] + 3, -0.25, sisiKiri[1] + 3);
        glRotatef(180, 0, 1, 0);
        Misc::blokDanauSatuSisi(translasiTinggi, translasiArus);
        glPopMatrix();
    }

    // Level 2
    array<array<float, 2>, 28> air = {{
        {18,  -9},
        {18,  -6},
        {15, -6},
        {15,  -3},
        {15,  0},
        {15,  3},
        {15,  6},
        {15,  9},
        {18,  0},
        {18,  3},
        {18,  6},
        {18,  9},
        {18,  12},
        {18,  -3},
        {21,  0},
        {21,  -3},
        {24,  -3},
        {24,  0},
        {18, -12},
        {15, -9},
        {24, -3},
        {24, -6},
        {21, -6},
        {24, 0},
        {24, 3},
        {21, 3},
        {15, 12},
        {18, 15}
    }};

    for(auto &arr : air) {
        glPushMatrix();
        glTranslatef(arr[0], -0.25, arr[1]);
        Misc::blokDanau(translasiTinggi);
        glPopMatrix();
    }
}

void danau()
{
    ColorList::coklatMuda()->set(true);

    // Level 1
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(12, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(15, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(15, -0.6, -12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(18, -0.6, -12)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 0, 1)->translate(18, -0.6, -15)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -15)->draw();
    balok(3, 3, 0.75, 0, 1, 1, 0, 1, 1)->translate(21, -0.6, -18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, -3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, -3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(21, -0.6, -6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, -12)->draw();

    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 0)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6, 6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 1)->translate(12, -0.6,  9)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(12, -0.6,  12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(15, -0.6,  12)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(15, -0.6,  15)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(18, -0.6,  15)->draw();
    balok(3, 3.15, 0.75, 0, 1, 0, 1, 0, 1)->translate(18, -0.6,  18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6,  18)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 1, 1, 1)->translate(21, -0.6,  21)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, 0)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(24, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 0, 0)->translate(21, -0.6, 3)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 6)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 9)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 12)->draw();
    balok(3, 3, 0.75, 0, 1, 0, 0, 1, 0)->translate(21, -0.6, 15)->draw();

    // Level 2
    balok(3, 3, 1, 0, 1, 1, 0, 1, 1)->translate(18, -1.6, -9)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, -6)->draw();
    balok(3, 3, 1, 0, 1, 1, 0, 0, 1)->translate(15, -1.6, -6)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, -3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 1)->translate(15, -1.6, 6)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 0, 1)->translate(15, -1.6, 9)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 0)->translate(18, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 3)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 6)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 1, 0)->translate(18, -1.6, 9)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 1, 1)->translate(18, -1.6, 12)->draw();
    balok(3, 3, 1, 0, 1, 0, 0, 0, 0)->translate(18, -1.6, -3)->draw();
    balok(3, 3, 1, 0, 1, 0, 1, 1, 0)->translate(21, -1.6, 0)->draw();
    balok(3, 3, 1, 0, 1, 1, 0, 1, 0)->translate(21, -1.6, -3)->draw();
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


void idleSimulasiWaktu()
{
    waktuSekarang += 10;

    if(waktuSekarang > detikSatuHari)
        waktuSekarang = 0;
    
    //cout <<  (float) ((float) waktuSekarang / 3600) << endl;
    
    float derajatMatahari = (float) waktuSekarang / (float) (detikSatuHari) * 360;

    //cout << derajatMatahari << endl;

    Vertex v(100, 0, 0);
    v.rotate(-derajatMatahari - 90, 0, 0, 1);
    LightPosition[0] = v.x;
    LightPosition[1] = v.y;
    LightPosition[2] = v.z;
}