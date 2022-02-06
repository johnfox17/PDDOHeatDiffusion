#include "HeatDiffusion.h"


void HeatDiffusion::initialize(){
    
};

void HeatDiffusion::InitialCondition(Geometry *B){
    //TODO:Initial conditions of plate
    node* p_nodes1=B->p_nodes;
    
    for (int i=0;i<TOTALNODES;i++){
        solution[i]=4*exp(-pow((p_nodes1->getX()-0.5),2)/(2*0.1*0.1))*exp(-pow((p_nodes1->getY()-0.5),2)/(2*0.1*0.1));
        p_nodes1++;
    };

};

HeatDiffusion::HeatDiffusion(Geometry *B, Peri2DDF *peri2DD){
    InitialCondition(B);

    ofstream myfile;
    myfile.open("/home/doctajfox/Documents/Thesis_Research/data/data.csv");
    
    for(int i = 0;i<TOTALNODES;i++){
        myfile<<solution[i]<<endl;
    }
};