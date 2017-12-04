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
#include "Objek/Burung.h"
#include "Ready/Terrain.h"
#include "Ready/Tebing.h"
#include "Ready/Danau.h"
#include "Ready/Bukit.h"
#include "Ready/AirTerjun.h"
#include "Ready/Pohon.h"
#include "Ready/Bunga.h"
#include "Ready/Batu.h"
#include "Ready/Semak.h"
#include "Ready/Jamur.h"
#include "Ready/Rumput.h"

using namespace std;

// Objek camera, mouse, keyboard, dll
Camera *camera;
Mouse* mouse;
Keyboard* keyboard;
Cartesius* cartesius;

// simulasi siang dan malam
int detikSatuHari = 360 * 24;
int pagiAwal = 360 * 4 + 1;
int pagiAkhir = 360 * 8;
int siangAwal = 360 * 8 + 1;
int siangAkhir = 360 * 14;
int soreAwal = 360 * 14 + 1;
int soreAkhir = 360 * 18;
int malamAwal = 360 * 18 + 1;
int malamAkhir = 360 * 4;
int waktuSekarang = 360 * 10;
float LightPosition[] = {0.0f, 0.0f, 0.0f};
float LightPosition1[] = {15.0f, 2.0f, 0.0f};


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
GrupObjek* tendaObjek;

// Untuk keperluan menaruh objek
Vertex taruhObjek(0, 0, 0);

void idleSimulasiWaktu();
void setlight();
void init();
void mousePassive(int x, int y);
void keyboardFunc(unsigned char key, int x, int y);
void idle();
void reshape(int w, int h);
void specialFunc(int key, int x, int y);
void setWarnaLangit();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setWarnaLangit();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        cameraX, cameraY, cameraZ,
        lookX, lookY, lookZ,
        0, 1, 0);

    setlight();

    glTranslatef(taruhObjek.x, taruhObjek.y, taruhObjek.z);
    pohonCemara();
    glPopMatrix();

    //cartesius->draw();

    lokasiPohon();
    lokasiBungaTeratai();
    lokasiBunga();
    lokasiBatu();
    lokasiSemak();
    lokasiJamur();
    lokasiRumput();
    bukit();
    danau();

    glPushMatrix();
    glTranslatef(42, 0, -23);
    tebing();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6, 0.16, -14);
    glRotatef(45, 0, 1, 0);
    tendaObjek->draw(false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.16, -4);
    glRotatef(90, 0, 1, 0);
    tendaObjek->draw(false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0.16, 8);
    glRotatef(135, 0, 1, 0);
    tendaObjek->draw(false);
    glPopMatrix();

    // Misc::bunga()->rotate(45, 0, 0, 1)->translate(0, 0.5, 0)->draw();

    glPushMatrix();
    glTranslatef(7, 0.16, 0);
    glScalef(1.5, 1.5, 1.5);
    Misc::kayuUnggun();
    glPopMatrix();

    //ColorList::batang()->set(true);
    //bebatuan();

    glPushMatrix();
    glTranslatef(-33.1, 0, 35);
    Misc::gapura();
    glPopMatrix();

    // TERRAIN
    terrainGroup();

    glPushMatrix();
    glTranslatef(LightPosition[0], LightPosition[1], LightPosition[2]);
    glColor4ub(255, 255, 255, 150);
    glutSolidSphere(5, 20, 20);
    glPopMatrix();
    tembelanDanau();
    lokasiBubble();

    // Bawah
    glPushMatrix();
    ColorList::batang()->set(true);
    trapesiumSamaSisi(60, 60, 84, 84, 30, 0, 1, 1, 1, 1, 1)->translate(-30, -30.1, -30)->draw();
    glPopMatrix();

    airDanau();

    airTerjunTingkat();



    glFlush();
    glutSwapBuffers();
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

    float LightAmbient1[] = {0.95f,0.43f,0.0f,1.0f};
    float LightDiffuse1[] = {0.6f,0.4f,0.2f,1.0f};
    float LightSpecular1[] = {0.99f,0.58f,0.11f,1.0f};
    float LightDirection[]    = {1, 1, 1, 0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION , 0.50f );
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION , 0.009f );
}

void init()
{
    camera = new Camera(&cameraX, &cameraY, &cameraZ, &lookX, &lookY, &lookZ);
    camera->setTranslationSpeed(5);

    mouse = new Mouse(camera, viewportWidth, viewportHeight);
    keyboard = new Keyboard(camera, mouse);
    cartesius = new Cartesius(
        42, 25, 42, 1, 1, 1);

    initAirTerjun();
    initBubble();
    tendaObjek = tenda()->scale(0.75, 0.75, 0.75);

    srand(time(NULL));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // kalau pakai color langsung material
    //glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);    

    mouse->cursorToggle();
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

void idleSimulasiWaktu()
{
    waktuSekarang += 1;

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

    if(waktuSekarang > 360 * 19 || waktuSekarang < 360 * 4) {
        glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
    }
    else{
        glEnable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
    }
}

void setWarnaLangit()
{
    glClearColor(0.529, 0.807, 0.98, 1);
}