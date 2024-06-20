#pragma once
#include "ElectricPart.h"

class Inductor : public ElectricPart {
public:
    Inductor();
    void Force(int Vol, int Cur);
};

