 #include "Geometry.h"
 #include <iostream>


void Geometry::initialize(){
    //p_nodes=NULL;

    delX = static_cast< float >(XLENGTH)/static_cast< float >(XMATERIALPOINTS-1);
    delY = static_cast< float >(YLENGTH)/static_cast< float >(YMATERIALPOINTS-1);
    //node nodes[TOTALNODES];
};

float Geometry::euclideanDist(float x1, float y1,float x2, float y2){
    float dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    
    return dist;
};




void Geometry::peri2DMesh(){
    //XLENGTH, YLENGTH, XMATERIALPOINTS, YMATERIALPOINTS, HORIZON
    cout<<"-----Creating Peridynamic Mesh-----"<<endl;
    
    for(int j = 0;j<YMATERIALPOINTS;j++){
        for(int i =0;i<XMATERIALPOINTS;i++){
            nodes[YMATERIALPOINTS * j + i].setNodeNum(YMATERIALPOINTS * j + i);
            nodes[YMATERIALPOINTS * j + i].setX(i*delX);
            nodes[YMATERIALPOINTS * j + i].setY(j*delY);
            
        }
    }

    p_nodes=nodes;
    
    ofstream myfile;
    myfile.open("/home/doctajfox/Documents/Thesis_Research/data/data.csv");
    
    for(int i = 0;i<TOTALNODES;i++){
        myfile<<p_nodes[i].getNodeNum()<<","<<p_nodes[i].getX()<<","<<p_nodes[i].getY()<<endl;
    }
    
 }

Geometry::Geometry(){
    initialize();
    peri2DMesh();
    
};