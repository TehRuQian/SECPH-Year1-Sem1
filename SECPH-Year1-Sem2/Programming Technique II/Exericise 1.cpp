// NAME : TEH RU QIAN A23CS0191
// 		  TAN YI YA   A23CS0187

#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

const int MAXIMUM_STUDENT = 10;

//Class declaration
class Student {
	private:
		string subjectName;
		string subjectCode;
		int score;
		
	public:
		//constructor
		Student(string name, string code, int score){
			subjectName = name;
			subjectCode = code;
			score = score; }
		//mutators
		void setSubjectName();
		void setSubjectCode(string);
		void setScore();
		//accessors
		string getGred(int) const;
		char getCreditHour() const;
		double getGradePoint(int) const;
		double getPointEarned (char, double) const;
		//destructor
		~Student(){
		}
};

//Student::Student(string name, string code, int score){
//	subjectName = name;
//	subjectCode = code;
//	score = score;
//}

// void Student::setSubjectName(string name){
//	subjectName = name;
// }
//
// void Student::setSubjectCode(string code){
//	subjectCode = code;
// }

char Student::getCreditHour() const{
	char creditHour = '0';
	creditHour = subjectCode.at(7);
	return creditHour;
}

string Student::getGred(int score) const {
	string grade ;
	if (score <= 29)
		grade = 'E'; 
	else if (score <= 34)
		grade = "D-" ;
	else if (score <= 39)
		grade = 'D' ;
	else if (score <= 44)
		grade = "D+" ;
	else if (score <= 49)
		grade = "C-" ;
	else if (score <= 54)
		grade = 'C' ;
	else if (score <= 59)
		grade = "C+" ;
	else if (score <= 64)
		grade = "B-" ;
	else if (score <= 69)
		grade = 'B' ;
	else if (score <= 74)
		grade = "B+" ;
	else if (score <= 79)
		grade = "A-" ;
	else if (score <= 89)
		grade = 'A' ;
	else if (score <= 100)
		grade = "A+";
	else 
		cout << "Invalid\n" ;
	return grade;
}

double Student::getGradePoint(int score) const {
	double gradePoint = 0.0;
	
	if (score <= 29)
		gradePoint = 0.00;
	else if (score <= 34)
		gradePoint = 0.67;
	else if (score <= 39)
		gradePoint = 1.00;
	else if (score <= 44)
		gradePoint = 1.33;
	else if (score <= 49)
		gradePoint = 1.67;
	else if (score <= 54)
		gradePoint = 2.00;
	else if (score <= 59)
		gradePoint = 2.33;
	else if (score <= 64)
		gradePoint = 2.67;
	else if (score <= 69)
		gradePoint = 3.00;
	else if (score <= 74)
		gradePoint = 3.33;
	else if (score <= 79)
		gradePoint = 3.67;
	else if (score <= 100)
		gradePoint = 4.00;
	else
	cout << "invalid\n" ;
	return gradePoint; 
}

double Student::getPointEarned(char creditHour, double gradePoint) const {
	double pointEarned = 0.0, credit;
	
	if (creditHour == '1')
		credit = 1;
	else if(creditHour == '2')
		credit = 2;
	else if (creditHour == '3')
		credit = 3;
	else if (creditHour == '4')
		credit = 4;
	else if (creditHour == '5')
		credit = 5;
	else if (creditHour == '6')
		credit = 6;
	else if (creditHour == '7')
		credit = 7;
	else if (creditHour == '8')
		credit = 8;
	else if (creditHour == '9')
		credit = 9;
	pointEarned = static_cast<double>(credit)* gradePoint ;
	return pointEarned ;
}
int main (){
	string name; 
	string code; 
	int score;
	char creditHour;
	double gradePoint;


//	string subjectName;
//	string subjectCode;
	//Get info from user
	cout << "Enter the following data : \n" ;
	cout << "   Subject name => " ;
	getline(cin, name) ;
	
	cout << "   Subject code => " ;
	cin >> code ;
	
	cout << "   Score earned => " ;
	cin >> score ;
	
	Student s (name, code, score);
	
	creditHour = s.getCreditHour();
	gradePoint = s.getGradePoint(score);
	

	//store info in object
//	s.setSubjectCode(code);
	
	cout <<	left << setw(15)
		 << setw(15) << "\nTHE RESULT\n " 
		 << setw(15) << "\nSubject Code" <<  "  : " << code << endl 
		 <<	setw(15) << "Subject Name " << " : " << name << endl 
		 <<	setw(15) << "Credit Hour " << " : " << creditHour<< endl 
		 << setw(15) << "Score Earned " << " : " << score << endl
		 << setw(15) << "Grade Earned " << " : " << s.getGred(score) << endl
		 << setw(15) << "Grade Point " << " : " << gradePoint<< endl
		<< setw(15) << "Point Earned " << " : " << s.getPointEarned(creditHour, gradePoint);
	return 0;
}

