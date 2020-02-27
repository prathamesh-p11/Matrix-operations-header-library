//============================================================================
// Name        : matOps.cpp
// Author      : Prathamesh Paril
// Description : A portable linear algebra header-only library transpose and multiplication of MxN matrices.
//============================================================================

#include <iostream>
#include <vector>
#include "matOps.hpp"
using namespace std;
using namespace brainMat;

int main() {
	
	
	//Type: Int ..............TESTING =>
	//test vector =>
	vector<vector<int>> a = {{ {1,0,2} , {1,2,1} }};
	vector<vector<int>> b = {{ {1,2} , {0,1} , {0,9} }};
	

	//matrix t to store result of transpose
	vector<vector<int>> t = {};
	//matrix c to store result of multiplication
	vector<vector<int>> c = {};
	//initialize matrix elements with values from vectors
	Matop<int, 2,3> mat1(a);
	Matop<int, 3,2> matt(t);
	Matop<int, 3,2> mat2(b);
	Matop<int, 2,2> matres(c);
	
	
	/*
	//Type: Float ..............TESTING =>
	//test vectors <float> =>
	vector<vector<float>> a = {{ {1.5,0.0,0.4} , {1.0,0.2,0.3} }};
	vector<vector<float>> b = {{ {0.7,1.2} , {2.0,0.5} , {2.3,0.2} }};
	//matrix t to store result of transpose
	vector<vector<float>> t = {};
	//matrix c to store result of multiplication
	vector<vector<float>> c = {};
	//initialize matrix elements with values from vectors
	Matop<float, 2,3> mat1(a);
	Matop<float, 3,2> matt(t);
	Matop<float, 3,2> mat2(b);
	Matop<float, 2,2> matres(c);
	*/


	//This code remains same for all data types
	cout<<"Mat1 =>\n";
	mat1.print();
	
	cout<<"\nMat2=>\n";
	mat2.print();

	matt = mat1.transpose();
	cout<<"\nTranspose of mat1 =>\n";
	matt.print();
	
	cout<<"\nMat1 * Mat2 =>\n";
	matres = mat1 * mat2;
	matres.print();

return 0;
}