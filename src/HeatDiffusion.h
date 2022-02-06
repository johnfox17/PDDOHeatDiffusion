#pragma once
#include "Peri2DDF.h"
#include "Geometry.h"
using namespace std;


class HeatDiffusion{
private:
    
public:
    float solution[TOTALNODES];
    void InitialCondition(Geometry *B);
    HeatDiffusion(Geometry *B,Peri2DDF *peri2DD); // Constructor
    void initialize();
    
   
};