#include "Peri2DDF.h"


void Peri2DDF::initialize(Geometry* B){
    p_B = B;
    
    
};



//Function that created B matrix
void Peri2DDF::GenBMatrix(){

};
//Function that calculates Peridynamic Weight
float Peri2DDF::CalculateWeight(float distance){
    float delta = HORIZON*p_B->delX;
    return exp(-4.0*pow(distance/delta,2));
};

//Function that calculates A vector
vector<float> Peri2DDF::CalculateAVector(float xCoordCurrentNode,float yCoordCurrentNode, float xCoordFamilyMember, float yCoordFamilyMember){
    vector<float> AVector;
    float ksi1, ksi2;
  
    ksi1 = xCoordCurrentNode-xCoordFamilyMember;
    ksi2 = yCoordCurrentNode-yCoordFamilyMember;
    AVector.push_back(1);
	AVector.push_back(ksi1);
	AVector.push_back(ksi2);
	AVector.push_back(ksi1 * ksi1);
	AVector.push_back(ksi2 * ksi2);
	AVector.push_back(ksi1 * ksi2);    
    return AVector;
};

//Function that created A matrix
void Peri2DDF::GenAMatrix(int currentNode){
    //float aVector[KSIVECTSIZE];
    
    float xCoordFamilyMember, yCoordFamilyMember;
    vector<float> AVector;
   
    
    float weight;
    float xCoordCurrentNode = p_B->nodes[currentNode].getX(); 
    float yCoordCurrentNode = p_B->nodes[currentNode].getY(); 
    float deltaV = p_B->delX*p_B->delY;
    float distanceBetweenNodes; 

    cout<<"Current Node--> "<<currentNode<<endl;
    InitializeZeroVector(AMat, AMATSIZE); 
    for(int i=0;i<currentNodeFamily.size();i++){
        vector<float> AMatAux;
        cout<< "Node--> "<<currentNodeFamily[i]<<endl;
        xCoordFamilyMember = p_B->nodes[currentNodeFamily[i]].getX();  
        yCoordFamilyMember = p_B->nodes[currentNodeFamily[i]].getY(); 
        //Calculate AVectors of each family member of current node 
        AVector = CalculateAVector(xCoordCurrentNode, yCoordCurrentNode, xCoordFamilyMember, yCoordFamilyMember);
        //Generate Peridynamic weights for each family member of current node
        distanceBetweenNodes = p_B->euclideanDist(xCoordCurrentNode, yCoordCurrentNode, xCoordFamilyMember, yCoordFamilyMember);
        //Calculate Peridynamic Weight
        weight = CalculateWeight(distanceBetweenNodes);
        //Calculate outer product of two AVectors
        OuterProduct(AMatAux, AVector, AVector);
        //Scalar times vector multiplication
        ScalarTimesMatrix(AMatAux, weight);
        //Add A matrices of node family
        AddArrays(AMat, AMat, AMatAux);               
    };
};


//void Peri2DDF::findPDDOFamilies(node* p_nodes){
void Peri2DDF::FindPDDOFamilies(){
    float dist;
    node* p_nodes1=p_B->p_nodes;
    //node* p_nodes1=p_nodes;
    node* p_nodes2;
    float horizonDist = HORIZON*p_B->delX;
    for(int i=0; i<TOTALNODESEXTENDED; i++){
        vector<int> currentNodeFamily;
        //p_nodes2=p_nodes;
        p_nodes2=p_B->p_nodes;
        for(int j=0; j<TOTALNODESEXTENDED;j++){
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
    for(int currentNode = 0; currentNode<TOTALNODESEXTENDED; currentNode++){
        currentNodeFamily = nodeFamilies[currentNode];
        GenAMatrix(currentNode);
        

        cout<<"here"<<endl;
        //Generate A matrix
        
        //Generate 'a' matrix (inverse A matrix)

        //Generate g polynomials
    };



};

Peri2DDF::Peri2DDF(Geometry *B){
    
    initialize(B);
    FindPDDOFamilies();
    CalcGPolynomials();
    //p_nodes = B.p_nodes; //Exctracting node coordinates
    //p_nodes = B->p_nodes;
   

   
    //p_nodes = nodes;
    
    
};




 