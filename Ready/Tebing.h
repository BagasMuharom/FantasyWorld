#ifndef READY_TEBING_H
#define READY_TEBING_H

#include "../Util/Util.h"
#include "../Objek/Objek.h"


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

#endif