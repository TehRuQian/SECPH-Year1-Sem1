// TEH RU QIAN A23CS0191 29.12.2023

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std ;

void readFile (double []) ;
void computeC (double[], double [], int, double []) ;
void average (double [], double&, double&) ;
string grade (double[], double[]) ;
void writeFile (double[], double[], string) ;


int main (){
	int i = 8, h = 0, m = 0, l = 0;
	double F[i], num[i], C[i], sum, avrg ;
	
	readFile (num) ;
	computeC (F, num, i, C) ;
	average (C, sum, avrg) ;
	string grades = grade (C, F) ;

	// output on the screen
	cout << fixed << showpoint << setprecision (1) << "Average of the temperature in Celcius: " << avrg << endl ;
	
	for (i = 0; i < 8; i++){
		
	if (C[i] >= 35)	{
		h++ ;
	}
	else if (C[i] < 35 && C[i] >= 20){
		m++ ;	
	}
	else 
		l++ ;
	}
	

	cout << "Number of high temperature: " << h << endl 
	     << "Number of medium temperature: " << m << endl 
	     << "Number of low temperature: " << l << endl ;


	writeFile (C, F, grades) ;            // call function of output file 
	return 0 ;
}


void readFile (double num[]){             // function for input file
	ifstream inputFile ;
	inputFile.open ("input.txt") ;
	
	for (int i = 0; i < 8; i++){
		inputFile >> num[i] ;
	//	cout << num[i] << endl ;
	}
	
	inputFile.close() ;

}

void computeC (double F[], double num [], int i, double C[]){               // function for store data F and calculate C by array
	
	for (int i = 0; i < 8; i++){
		F[i] = num [i];
	//	cout << "f " << F[i] << endl ;
	}
	
	for (int i = 0; i < 8; i++){
		C[i] = 5.0 / 9.0 * (F[i] - 32) ;
	//	cout << "c" << C[i] << endl ;
	}
}

void average (double C[], double& sum, double& avrg){            // function for calculate array
	
	for (int i = 0; i < 8; i++){
		sum += C[i] ;
	}
	avrg = sum / 8.0 ;
	// cout << "s" << sum << endl ;
	// cout << "a" << avrg << endl ;
}

string grade (double C[], double F[]){                            // function to determine the grades
	
	stringstream result ;
	for (int i = 0; i < 8; i++){
		
		result << fixed << showpoint << setprecision(2)  
			   << right << setw(7) << C[i] 
			   << right << setw(15) << F[i] ; 
		if (C[i] >= 35){
			
			result << right << setw(15) << "H\n" ;
			
		//	des1 = 'H' ;
		}
		else if (C[i] < 35 && C[i] >= 20){
			
			result << right << setw(15) << "M\n" ; 
			
		//	des2 = 'M' ;
		}
		else {
			
		result << right << setw(15) << "L\n" ; 
		
		//	des3 = 'L' ;
		}
	}
	return result.str() ;
	// cout << "s" << sum << endl ;
}

void writeFile (double C[], double F[], string grades){                  // function for output file
	
	ofstream outputFile ;
	outputFile.open("output.txt") ;
	
	outputFile << right << setw(10) << "C(Celcius)" << setw(17) << "F(Farenheit)" << setw(15) << "Description\n" 
			            << setw(10) << "==========" << setw(17) << "============" << setw(15) << "===========\n" ;
	outputFile << grades ;
	outputFile.close() ;				   
}


