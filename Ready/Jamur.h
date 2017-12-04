#ifndef READY_JAMUR_H
#define READY_JAMUR_H

void lokasiJamur();
void grupJamurMerah();

void lokasiJamur()
{
    grupJamurMerah();
}

void grupJamurMerah()
{
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
}

#endif