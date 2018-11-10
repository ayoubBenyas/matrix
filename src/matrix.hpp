#include <iostream>
#include <stdlib.h>
#define Max 20
#define pair(x) (x%2==0?1:-1) 

/***************************
	Calcule Matricielle
***************************/

using namespace std; // pour pouvoir enlever 'std ::'

class	Matrix{
	private:
		float  Mat2[Max][Max];
		int l,c ;
	public:
		Matrix(int a=1){
			if(a<=0) throw -1;
			c=l=a;}
		Matrix(int a, int b){
			if(a<=0 || b<=0) throw -2;
			l=a;c=b;}
		~Matrix(){ /*std::cout << "\nfree >> Matrix("<<l<<","<<c<<")" ;*/ }
	
	    void 	Aff(){ cout << "\n\tMatrix("<<l<<","<<c<<")"; }
	    bool 	Valid()	{ return(l<0 || c<0) ? false:true; }
	    bool 	Carre()	{ return(l!=c) ? false:true; }
		void 	Init();
		void 	Read();
		void 	Write();
		Matrix	Trans();
		float 	Det();
		
		friend 	bool operator==(const Matrix,const Matrix);
		friend 	bool operator!=(const Matrix M1,const Matrix M2){return !(M1==M2);}
		
		friend 	Matrix operator+(const Matrix,const Matrix);
		friend 	Matrix operator-(const Matrix,const Matrix);
		friend 	Matrix operator*(const int,const Matrix);
        friend 	Matrix operator*(const Matrix,const Matrix);
        friend 	Matrix operator^(const Matrix,const  int);
		
		friend 	void  operator+=( Matrix &M,const Matrix M0){ M=M+M0;}
		friend 	void  operator-=( Matrix &M,const Matrix M0){ M=M-M0;}
		friend 	void  operator*=( Matrix &M,const int x)	{ M=x*M;}
        friend 	void  operator*=( Matrix &M,const Matrix M0){ M=M*M0;}
};


inline 	bool operator==(const Matrix M1,const Matrix M2)
{
	
	if(M1.c!=M2.c || M1.l!=M2.l) return false;
	
	for(int i=0; i<M1.c;i++)
		for(int j=0; j<M1.l ;j++)
		{
			if(M1.Mat2[i][j]!=M2.Mat2[i][j]) return false;
		}
		
		return true;
}

inline 	Matrix operator*(const int x,const Matrix M)
{
    Matrix M0;
  
	M0.c=M.c;
	M0.l=M.l;
	M0=M;
	for(int i=0 ; i<M0.l ; i++)
	{
		for(int j=0;j<M0.c ; j++)
		M0.Mat2[i][j] *=	x;
	}
      
	return M0;
}

inline 	Matrix operator+(const Matrix Mg,const Matrix Md)
{
    Matrix M0;
    if( Mg.l!=Md.l || Mg.c!=Md.c )	// Type non Compatible ( Somme )
            M0.l=-1;
         else
         {
            M0.c=Mg.c;
			M0.l=Mg.l;
            for(int i=0 ; i<M0.l ; i++)
            {
                for(int j=0;j<M0.c ; j++)
                M0.Mat2[i][j] = Mg.Mat2[i][j] + Md.Mat2[i][j];
            }
         }
	return M0;
}

inline 	Matrix operator-(const Matrix Mg,const Matrix Md)
{
    Matrix M0;
    if( Mg.l!=Md.l || Mg.c!=Md.c )	// Type non Compatible ( Somme )
            M0.l=-1;
         else
         {
            M0.c=Mg.c;
			M0.l=Mg.l;
			M0=Mg+ -1*Md;
         }
	return M0;
}

inline 	Matrix operator*(const Matrix Mg,const Matrix Md)
{
    Matrix M0;
    if( Mg.c != Md.l )	// Type non Compatible ( Produit )
            M0.l=-1; 
         else
         {
            M0.l=Mg.l;
			M0.c=Md.c;
            for(int i=0 ; i<M0.l ; i++)
            {
                for(int j=0;j<M0.c ; j++)
                {   M0.Mat2[i][j]=0;
                    for(int k=0;k<Md.l ; k++)
                        M0.Mat2[i][j] += Mg.Mat2[i][k] * Md.Mat2[k][j];
                }
            }
         }
	return M0;
}

inline 	Matrix operator^(const Matrix Mg,const int p)
{
    Matrix M0=Mg;
		for(int i =1 ; i<p;  i++)
			M0= M0*Mg;
	
	return M0;
}

