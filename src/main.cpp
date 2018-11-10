#include  "matrix.hpp"


int 	main()
{
	try{
		Matrix M(-1);
	}
	catch(int e)
	{
		cerr <<"ERROR: " << e << endl;
	}	

	try{
		Matrix N(-4,0);
	}
	catch(int e)
	{
		cerr <<"ERROR: " << e << endl;
	}	
	/*cout << "\n\t  @M : "<< &M ;
	cout << "\n\t  @N : "<< &N ;
	M=N;
	cout << "\n\t  @N : "<< &M ;
	
	
	M.Read();
	cout << "\n\t*********************** Matrice";
	M.Write();
	cout << "\n\t*********************** Transpose";
	(M.Trans()).Write();
	cout << "\n\t***********************\n\tM + M:";
	
	(M+M).Write();
	cout << "\n\t-----------------------\n\t2 * M:";
	(2*M).Write();
	cout << "\n\t***********************\n\tM * M:";
	
	(M*M).Write();
	cout << "\n\t-----------------------\n\tM ^ 2:";
	(M^2).Write();
	cout << "\n\t***********************\n\tM-M";
	(M-1*M).Write();
	
	cout << "\n\t***********************";
	
	cout << "\n\t  M == M : "<< (M==M);
*/
	return 0;
}
