#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Camera/Camera.h"
#include "Objek/Cartesius.h"
#include "Objek/Pohon.h"
#include "Objek/Batu.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"

// Objek camera, mouse, keyboard, dll
Camera *camera;
Mouse* mouse;
Keyboard* keyboard;

// LookAt
float lookX = 0;
float lookY = 0;
float lookZ = 0;

// Lokasi Position
float cameraX = 0;
float cameraY = 0.75;
float cameraZ = 2;

// View port
int viewportWidth;
int viewportHeight;

// Lokasi cahaya LIGHT0
float LightPosition[] = {0.0f, 50.0f, 25.0f};

void setlight()
{
    float LightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float LightEmission[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float LightDiffuse[] = {1.0f, 1.0f, 0.8f, 1.0f};
    float LightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void init()
{
    camera = new Camera(&cameraX, &cameraY, &cameraZ, &lookX, &lookY, &lookZ);
    camera->setTranslationSpeed(0.5);

    mouse = new Mouse(camera, viewportWidth, viewportHeight);
    keyboard = new Keyboard(camera, mouse);

    srand(time(NULL));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    // glShadeModel(GL_FLAT);

    //kalau pakai color langsung material
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    mouse->cursorToggle();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //diganti dengan camera
    // gluLookAt(viewer[0],viewer[1],viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    gluLookAt(
        cameraX, cameraY, cameraZ,
        lookX, lookY, lookZ,
        0, 1, 0);

    setlight();

    Cartesius *cartesius = new Cartesius(
        50, 50, 50, 1, 1, 1);

    glPushMatrix();
    cartesius->draw();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    batu();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1, 0, 2);
    glScalef(0.15, 0.15, 0.15);
    batu();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5, 0, -1);
    glScalef(0.3, 0.3, 0.3);
    batu();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 0, -1);
    glScalef(0.3, 0.3, 0.3);
    batu();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, 25);
        glColor3ub(255, 0, 0);
        glutSolidSphere(0.5, 8, 8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, 0, 0);
    Pohon::Cemara(5, 0.75, 2, 0.75, 3.25);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1, 0, 1.75);
    glScalef(0.3, 0.3, 0.3);
    Pohon::Cemara(5, 0.75, 2, 0.75, 3.25);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5, 0, 1.5);
    Pohon::Cemara(3, 0.5, 1.5, 0.75, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25, 0, -2);
    Pohon::Cemara(3, 0.5, 1.25, 0.5, 2.85);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5, 0, 1.5);
    Pohon::Cemara(3, 0.6, 1.5, 0.75, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.25, 0, -2);
    Pohon::Cemara(3, 0.5, 1.25, 0.5, 2.85);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 60);
    Pohon::Cemara(3, 0.5, 1.25, 0.5, 2.85);
    glPopMatrix();

    // glPushMatrix();
    //     glTranslatef(LightPosition[0], LightPosition[1], LightPosition[2]);
    //     glColor3ub(255, 255, 255);
    //     glutSolidSphere(0.5, 10, 10);
    // glPopMatrix();

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
    keyboard->specialKeyAction(key, x, y);

    glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    keyboard->keyAction(key, x, y);

    glutPostRedisplay();
}

void mousePassive(int x, int y)
{
    mouse->passive(x, y);

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    viewportWidth = glutGet(GLUT_SCREEN_WIDTH) / 1.5;
    viewportHeight = glutGet(GLUT_SCREEN_HEIGHT) / 1.5;

    glutInitWindowSize(viewportWidth, viewportHeight);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
    glutMainLoop();

    return 0;
}
