#pragma once
#include "ElectricPart.h"

class Resistor : public ElectricPart {
public:
    Resistor();
    void Force(int Vol, int Cur);
};

