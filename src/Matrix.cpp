#include  "matrix.hpp"
		
void 	Matrix :: Init()
{
	std :: cout <<" ( l , c ) !<20    ? ";
	std :: cin	>> l >> c;

}

void 	Matrix :: Read()
{
	if(!Valid()) 
	{
		printf("\n\t Erreur de lecture");
		return;
	}
	
    for(int i =0; i<l; i++)
        for(int j =0; j<c; j++)
        {
             // std :: cout<< "\nM["<<i+1<<"]["<<j+1<<"] ?=  ";
             std :: cin  >> Mat2[i][j];
        }
}

void 	Matrix :: Write()
{
	if(!Valid()) 
	{
		printf("\n\t Erreur de lecture");
		return ;
	}
	Aff();
    for(int i =0; i<l; i++)
        { std::cout << "\n";
            for(int j =0; j<c; j++)
            {
                // std:: cout <<"\t"<< Mat2[i][j];
				printf("\t%.2f",Mat2[i][j]);
            }
        }
}

Matrix	Matrix :: Trans()
{
	Matrix M0(c,l);
	
	for(int i=0 ; i<M0.l ; i++)
		for(int j=0;j<M0.c ; j++)		
			M0.Mat2[i][j]=Mat2[j][i];
	
	return M0;
}

float	Matrix :: Det()
{	
	if(!this->Carre() || !this->Valid() ) 
	{
		cout << "\n\tMatrice n'est pas Valide";
		return 0;
	}
	
	Matrix D=*this;
	float m;
	for(int k=0;k<D.l;k++)
	{
		for(int i=k+1;i<D.l;i++)
		{	
			if(D.Mat2[k][k])
				m = D.Mat2[i][k] / D.Mat2[k][k];
			else {
					int ind=k+1;
					while(!D.Mat2[ind][k] && ind++<D.l);
					if(ind==D.l)  return 0;
					for(int t=0;t<D.l+1;t++){	D.Mat2[k][t]=D.Mat2[k][t]+D.Mat2[ind][t];	D.Mat2[ind][t]=D.Mat2[k][t]-D.Mat2[ind][t];	D.Mat2[k][t]=D.Mat2[k][t]-D.Mat2[ind][t];}
				}
			for(int j=k+1;j<D.l+1;j++)
				D.Mat2[i][j]-= m * D.Mat2[k][j];
				
			D.Mat2[i][k] = 0;
		}
		
	}
	float det=D.Mat2[0][0];
	for(int k=1 ;k<D.l; k++) det*=D.Mat2[k][k];

		return det;
}
