#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "CommonConstant.h"
#include "Geometry.h"
#include "VectorMath.h"

using namespace std;

class Peri2DDF{
private:
    Geometry *p_B; //Constructing Geometric Object
    vector<vector<int>> nodeFamilies;
    vector<vector<int>> xiVector;
    vector<int> currentNodeFamily;
    float GPolynomials[TOTALNODES];
    float AMat[AMATSIZE]; 
    int currentNode;
    //node nodes[TOTALNODESEXTENDED];



    void CalcGPolynomials();
    void GenBMatrix();
    void GenAMatrix(int currentNode);
    float CalculateWeight(float distance);
    void FindPDDOFamilies();
    vector<float> CalculateAVector(float xCoordCurrentNode,float yCoordCurrentNode, float xCoordFamilyMember, float yCoordFamilyMember);
public:
    //node *p_nodes;
    //node nodes[TOTALNODES];
    //Geometry B; //Constructing Geometric Object
    //vector<vector<int>> nodeFamilies;
    //Peri2DDF(); // Constructor
    Peri2DDF(Geometry *B);
    void initialize(Geometry *B);
    
   
};