#pragma once
#include <vector>
#include <iostream>
using namespace std;
void OuterProduct(vector<float> &output, vector<float> &V1,  vector<float> &V2);
void ScalarTimesMatrix(vector<float> &output, float scalar);
void InitializeZeroVector(vector<float> &output, int sizeOfArray);
void AddArrays(vector<float> &output, vector<float>array1, vector<float>array2);