#pragma once
#include "ElectricPart.h"

class Capacitor : public ElectricPart {
public:
    Capacitor();
    void Force(int Vol, int Cur);
};

