#include "Material.h"
#include "GL/glut.h"

void Material::green()
{
    GLfloat ambient[] = {0, 0, 0, 1};
    GLfloat diffuse[] = {0.1f, 0.35f, 0.1f, 1.0f};
    GLfloat specular[] = {0.45f, 0.55f, 0.45f, 1.0f};
    GLfloat shininess[] = {32.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void Material::gold()
{
    float ambient[] = {0.329412f, 0.223529f, 0.027451f, 1.0f};
    float diffuse[] = {0.780392f, 0.568627f, 0.113725f, 1.0f};
    float specular[] = {0.992157f, 0.941176f, 0.807843f, 1.0f};
    float shininess = 27.8974f;
    float black[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}