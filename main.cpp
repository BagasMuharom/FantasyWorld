#include "Camera/FPS.h"
#include "Keyboard.h"
#include "Objek/Cartesius.h"
#include "GL/glut.h"
#include "Camera/Camera.h"
#include "Objek/Pohon.h"
#include<math.h>
#include<iostream>
#define WIDTH 500
#define HEIGHT 500

using namespace std;

Camera* camera;
Keyboard* keyboard;

// Look
float lookX = 0;
float lookY = 0;
float lookZ = 0;

// Camera Position
float cameraX = -2;
float cameraY = 1;
float cameraZ = 10;

// View port
int viewportWidth;
int viewportHeight;

// Ratio
float ratio;

// Debug Option
bool lookAtDebug = false;

float LightPosition[] = { 0.0f, 50.0f, 50.0f};

void display();
void keyboardSpecial(int key, int x, int y);
void lighting();
void init();
void reshape(int width, int height);
void setLight();
void cursorToggle();
void keyboardFunc(unsigned char key, int x, int y);
void mousePassive(int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(WIDTH, HEIGHT);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Camera Rotation");
    glutInitWindowPosition(
        (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2
    );

    init();
    
    // Feature
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboardSpecial);
    glutPassiveMotionFunc(mousePassive);
    glutKeyboardFunc(keyboardFunc);

    glutMainLoop();
    return 0;
}

void init()
{
    camera = new Camera(&cameraX, &cameraY, &cameraZ, &lookX, &lookY, &lookZ);
    // keyboard = new Keyboard(fps);

    viewportWidth = WIDTH;
    viewportHeight = HEIGHT;

    cursorToggle();

    glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    // glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    
    // glClearColor(1,1,1,1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // gluPerspective(45, ratio, 1, 5000);

    camera->update();
    
    gluLookAt(
        cameraX, cameraY, cameraZ,
        lookX, lookY, lookZ,
        0, 1, 0
    );

    setLight();

    if(lookAtDebug)
        cout << lookX << " " << lookY << " " << lookZ <<  endl;

    glPushMatrix();
    // glTranslatef(LightPosition[0] + 1, LightPosition[1] + 1, LightPosition[2] + 1);
    glTranslatef(LightPosition[0] + 1, LightPosition[1] + 1, LightPosition[2] + 1);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();

    Cartesius* cartesius = new Cartesius(
        50, 50, 50, 5, 5, 5
    );

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    glScalef(0.5, 0.5, 0.5);
    glColor3ub(120, 120, 255);
    glBegin(GL_POLYGON);
        glVertex3f(3, 0, 0);
        glNormal3f(3, 0, 0);
        glVertex3f(0, 3, 0);
        glNormal3f(0, 3, 0);
        glVertex3f(0, 0, 3);
        glNormal3f(0, 0, 3);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 3);
        glVertex3f(0, 3, 0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(0, 0, 0);
        glVertex3f(3, 0, 0);
        glVertex3f(0, 3, 0);
    glEnd();
    glPopMatrix();

    cartesius->draw();

    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glColor3ub(120, 120, 255);
    glutSolidTeapot(1);
    // Pohon::Cemara(5, 0.5, 1.25, 0.85, 2.25);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 5000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboardSpecial(int key, int x, int y)
{
    // keyboard->runAction(key, x, y);

    glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch(key) {
        case ' ':
            camera->toggleFPS();
            cursorToggle();
            break;
        case 'w':
            lookZ--;
            cameraZ--;
            break;
        case 's':
            lookZ++;
            cameraZ++;
            break;
        case '+':
            LightPosition[2] += 2.0f;
            break;
        case '-':
            LightPosition[2] -= 2.0f;
            break;
    }

    glutPostRedisplay();
}

void cursorToggle() {
    if(camera->isFPSMode()) {
        glutSetCursor(GLUT_CURSOR_NONE);
        glutWarpPointer(viewportWidth / 2, viewportHeight / 2);
    }
    else {
        glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    }
}

void mousePassive(int x, int y) {
    static bool just_warped = false;
    
    if(just_warped) {
        just_warped = false;
        return;
    }

    if(camera->isFPSMode()) {
        glutWarpPointer(viewportWidth / 2, viewportHeight / 2);

        int dx = x - viewportWidth/2;
        int dy = y - viewportHeight/2;

        if(dx)
            camera->rotateAngleY(PI / 180 * 0.2 * dx);
        
        if(dy)
            camera->rotateAngleX(-PI / 180 * 0.2 * dy);

        just_warped = true;
    }
    
    glutPostRedisplay();
}

void setLight() {
    float LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float LightEmission[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float LightDiffuse[] = { 1.0f, 1.0f, 0.8f, 1.0f };
    float LightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}