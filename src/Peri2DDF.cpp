#include "Peri2DDF.h"


void Peri2DDF::initialize(Geometry* B){
    p_B = B;
    FindPDDOFamilies();
    
};



//Function that created B matrix
void Peri2DDF::GenBMatrix(){

};

//Function that created A matrix
void Peri2DDF::GenAMatrix(){

};

//Function that created Peridynamic Weights
void Peri2DDF::GenWeights(){

};
//void Peri2DDF::findPDDOFamilies(node* p_nodes){
void Peri2DDF::FindPDDOFamilies(){
    float dist;
    node* p_nodes1=p_B->p_nodes;
    //node* p_nodes1=p_nodes;
    node* p_nodes2;
    float horizonDist = HORIZON*p_B->delX;
    for(int i=0; i<TOTALNODES;i++){
        vector<int> currentNodeFamily;
        //p_nodes2=p_nodes;
        p_nodes2=p_B->p_nodes;
        for(int j=0; j<TOTALNODES;j++){
            dist = p_B->euclideanDist(p_nodes1->getX(),p_nodes1->getY(),p_nodes2->getX(),p_nodes2->getY());
            if(dist <= horizonDist && dist!=0.0){
                currentNodeFamily.push_back(p_nodes2->getNodeNum());
            }    
            p_nodes2++;
        }
        nodeFamilies.push_back(currentNodeFamily);
        p_nodes1++;
    }

};

void Peri2DDF::CalcGPolynomials(){

};

Peri2DDF::Peri2DDF(Geometry *B){
    
    initialize(B);
    CalcGPolynomials();
    //p_nodes = B.p_nodes; //Exctracting node coordinates
    //p_nodes = B->p_nodes;
   

   
    //p_nodes = nodes;
    
    
};




 