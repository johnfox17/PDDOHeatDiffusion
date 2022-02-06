#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "CommonConstant.h"
#include "Geometry.h"
using namespace std;

class Peri2DDF{
private:
    Geometry *p_B; //Constructing Geometric Object
    vector<vector<int>> nodeFamilies;
    vector<vector<int>> xiVector;
    void CalcGPolynomials();
    void GenBMatrix();
    void GenAMatrix();
    void GenWeights();
    void FindPDDOFamilies();
public:
    //node *p_nodes;
    //node nodes[TOTALNODES];
    //Geometry B; //Constructing Geometric Object
    //vector<vector<int>> nodeFamilies;
    //Peri2DDF(); // Constructor
    Peri2DDF(Geometry *B);
    void initialize(Geometry *B);
    
   
};