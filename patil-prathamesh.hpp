/*
 * matOps.hpp
 *
 *  Created on: Feb 24, 2020
 *      Author: prathamesh
 */

#ifndef MATOPS_HPP_
#define MATOPS_HPP_

#include <vector>

namespace brainMat
{

template<class T, int m, int n>
class Matop
{
private:
	//2-D vector(vector of vectors) to store matrix elements
	std::vector<std::vector<T>> elements;
public:
	int numRows;
	int numCols;

	//constructor and destructor
	Matop(std::vector<std::vector<T>> &);
	~Matop();

	//Operations
	//display matrix
	void print();
	//transpose
	friend class Matop<T,n,m>;
	//result of transpose operation on matrix of dimension (m x n) => matrix of dimension (n x m)
	Matop<T,n,m> transpose();

	//Multiplication
	//multiplying two matrices with dimensions (m x n) and (p x  q)
	template <class _T, int _m, int _n, int p, int q>
	//result of multiplication => a matrix with dimensions (m x q)
	friend Matop<_T,_m,q> operator *(const Matop<_T, _m,_n>&, const Matop<_T, p, q>&);
};


//constructor to create matrix
//@param vector of vectors used to define the matrix
//@return created matrix as an object (vector of vectors)
template <class T, int m, int n>
Matop<T,m,n>::Matop(std::vector<std::vector<T>> & t_a) : numRows(m), numCols(n)
{
	//check for invalid dimensions
	try
	{
		if(m<0 || n<0)
		{
			throw std::invalid_argument("Matrix dimensions cannot be negative!!");
		}
		for(std::vector<T> i: t_a)
		{
			elements.push_back(i);
		}
	}
	catch(std::exception &e)
	{
		std::cerr <<"Exception : "<<e.what()<<std::endl;
	}
}

//destructor
template <class T, int m, int n>
Matop<T,m,n>::~Matop()
{
}


//Function to create transpose
//@return transposed matrix object

template <class T, int m, int n>
Matop<T, n, m> Matop<T,m,n>::transpose()
{
	//temporary matrix to initialize transpose matrix witb all 0s
	std::vector<std::vector<T>> temp;
	for(int i=0; i<n; i++)
	{
		std::vector<T> row;
		for(int j=0; j<m; j++)
		{
			row.push_back(0);	//initialize temp with all 0s
		}
		temp.push_back((row));
	}
	Matop <T, n, m> tran(temp);
	for(int i=0; i<numRows; ++i)
	{
		for(int j=0;j<numCols;++j)
		{
			tran.elements[j][i] = elements[i][j];
		}
	}

	return tran;
}

//Function to multiply matrices using operator overloading
//@param mat1 is the object of matrix 1
//@param mat2 is the object of matrix 2
//@return result of multiplication - matrix object
template<class T, int m, int n, int p, int q>
Matop <T,m,q> operator*(const Matop<T,m,n> &mat1, const Matop<T,p,q> &mat2)
{
	//return empty matrix if dimensions mismatch
	std::vector<std::vector<T>> emptyVec( n , std::vector<T> (m, 0));
	Matop <T,m,q> emptyMat(emptyVec);

	try
	{
		if(n != p)
		{
			throw std::invalid_argument("Dimensions mismatch");
		}
		int nrow = mat1.numRows;
		int ncol = mat2.numCols;
		std::vector<std::vector<T>> temp;	//temporary matrix used to initialize result matrix

		//initialize matrix with 0s
		for(int i=0;i<m;i++)
		{
			std::vector<T> row;
			for(int j=0; j<q;j++)
			{
				row.push_back(0);
			}
			temp.push_back(row);
		}

		//define result matrix with all 0s

		//Multiplication operation T(n) => O(n^3)
		Matop<T,m,q> result(temp);
		for(int i=0;i<nrow;++i)
		{
			for(int j=0;j<ncol;++j)
			{
				for(int k=0;k<mat1.numCols;k++)
				{
					result.elements[i][j] += mat1.elements[i][k] * mat2.elements[k][j];
				}
			}
		}
		return result;
	}

	catch(std::exception &e)
	{
		std::cerr <<"Exception: "<<e.what()<<std::endl;
	}

	return emptyMat;
}

//procedure to display matrix
template <class T, int m, int n>
void Matop<T,m,n>::print()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			std::cout<<elements[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

}//namespace scope end
#endif /* MATOPS_HPP_ */

