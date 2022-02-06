#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "CommonConstant.h"
#include <fstream>

using namespace std;


class node{
private:
    int nodeNum; 
    float xCoord, yCoord; // coordinates of the point
public:
   node(){
   }
   node(int currentNode, float x, float y){
        nodeNum = currentNode;
        xCoord=x;
        yCoord=y;
   }
   int getNodeNum(){
       return nodeNum;
   }
   float getX(){
       return xCoord;
   }
   float getY(){
       return yCoord;
   }
   void setNodeNum(int currentNode){
       nodeNum = currentNode;
   }
   void setX(float x){
       xCoord=x;
   }
   void setY(float y){
       yCoord=y;
   }
   
};

class Geometry{
private:
    

public:
    Geometry(); // Constructor
    //Creating array of Peridynamic nodes 
    node nodes[TOTALNODES];
    node *p_nodes;

    float delX, delY; 
    
    float euclideanDist(float x1, float y1,float x2, float y2);
    void peri2DMesh(); // Initializer for Discretization Class.
    void initialize();

};

//Class Point represents points in the Cartesian coordinate
// class Node
// {
// private:
//     double XCoord, YCoord; // coordinates of the point

// public:
//     Node(double, double);

// };