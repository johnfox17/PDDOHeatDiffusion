
#include "Geometry.h"
#include "Peri2DDF.h"
#include "HeatDiffusion.h"
#include <iostream>
#include <fstream>

int main(void){
    //srand((unsigned)time(NULL));
    /*geometry B;
    node* p_nodes = B.p_nodes;
    //node nodes[TOTALNODES];
    //p_nodes = nodes;
    for(int i=0; i<5;i++){
        cout<<p_nodes->getX()<<" "<<p_nodes->getY()<<endl;
        p_nodes++;
    }*/
    //B.peri2DMesh();
    Geometry B; //Contructing geometry such as Peridynamic Mesh
    Peri2DDF peri2DD(&B); //Peridynamic object
    HeatDiffusion heatDiffusion(&B,&peri2DD); //Heat diffusion object
    



    
    
}