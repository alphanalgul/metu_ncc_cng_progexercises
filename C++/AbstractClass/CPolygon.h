#ifndef CPOLYGON_H
#define CPOLYGON_H

#include <iostream>
#include <string>

using namespace std;

class CPolygon {
protected:
    int width;
    int height;
    static int counter;

public:
    CPolygon() {
        width = 0;
        height = 0;
        counter++;
    }

    void setup(int w, int h) {
        width = w;
        height = h;
    }

    virtual float area(void) = 0;

    virtual string getName(void) = 0;

    void onscreen(void) {
        cout << getName() << " area: " << area() << endl;
    }

    static int getCounter(void) {
        return counter;
    }
};

int CPolygon::counter = 0;

#endif
