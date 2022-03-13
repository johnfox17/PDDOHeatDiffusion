#include "VectorMath.h"

//Function that calculates the outer product of two arrays
void OuterProduct(vector<float> &output, vector<float> &V1,  vector<float> &V2) {    
    int rows = V1.size();
    int columns = V2.size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            output.push_back(V1[i] * V2[j]) ;
        }
    }      
}
//Multiplies vector times scalar
void ScalarTimesMatrix(vector<float> &output, float scalar){
    int sizeOfArray = output.size();
    for (int i = 0; i < sizeOfArray; i++) {
        output[i] = scalar*output[i];
    }
}
//Initializes array to zeros
void InitializeZeroVector(vector<float> &output, int sizeOfArray){
    for (int i = 0; i < sizeOfArray; i++) {
        output.push_back(0.0);
    }

}
//Function that does element by element sum of arrays
void AddArrays(vector<float> &output, vector<float>array1, vector<float>array2){
    //TODO: check if arrays are same size and if not report an error and end SIM
    int sizeOfArray1 = array1.size();
    int sizeOfArray2 = array2.size();
    if (sizeOfArray1 == sizeOfArray2)
    {
        for (int i = 0; i < sizeOfArray1; i++) {
            output[i] = array1[i]+array2[i];
        }    
    }
}