#ifndef READY_BUKIT_H
#define READY_BUKIT_H

#include "../Util/Color.h"
#include "../Util/Util.h"

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

    // bukit sebelah kanan tenda
    ColorList::batu()->set(true);    
    trapesiumSiku(12, 20, 11.5, 19.5, 0.75, 0, 0, 1, 1, 1, 0)->flip(1, 0, 0)->translate(3, 0, 42)->draw();
    trapesiumSiku(12, 20, 11.5, 19.5, 0.75, 0, 0, 1, 1, 1, 0)->flip(1, 0, 1)->translate(3, 0, 42)->draw();
    trapesiumSiku(8, 16, 7.5, 15.5, 0.75, 0, 0, 1, 1, 1, 0)->flip(1, 0, 0)->translate(3, 0.9, 42)->draw();
    trapesiumSiku(8, 16, 7.5, 15.5, 0.75, 0, 0, 1, 1, 1, 0)->flip(1, 0, 1)->translate(3, 0.9, 42)->draw();

    ColorList::rumput()->set(true);    
    trapesiumSiku(11.5, 19.5, 11.4, 19.4, 0.15, 1, 0, 1, 1, 1, 0)->flip(1, 0, 0)->translate(3, 0.75, 42)->draw();
    trapesiumSiku(11.5, 19.5, 11.4, 19.4, 0.15, 1, 0, 1, 1, 1, 0)->flip(1, 0, 1)->translate(3, 0.75, 42)->draw();
    trapesiumSiku(7.5, 15.5, 7.4, 15.4, 0.15, 1, 0, 1, 1, 1, 0)->flip(1, 0, 0)->translate(3, 1.65, 42)->draw();
    trapesiumSiku(7.5, 15.5, 7.4, 15.4, 0.15, 1, 0, 1, 1, 1, 0)->flip(1, 0, 1)->translate(3, 1.65, 42)->draw();
}

#endif