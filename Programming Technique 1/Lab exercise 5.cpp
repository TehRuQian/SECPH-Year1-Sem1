// TEH RU QIAN A23CS0191

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int act_case, tot_cases, new_cases, tot_death, tot_recov , tot , average, largest ;
int count = 0;
string state_name, state;
char enterkey ;

// Function for display the status
void dispStatus ()
{	
	cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>" << endl;
	cout << left << setw(20) << " Active cases  " << ": " << act_case << endl;
	if (act_case > 40)
	{
		cout << left << setw(20) << " Status" << ": Red Zone" << endl;
	}
	else if (act_case >20 && act_case <= 40)
	{
		cout << left << setw(20) << " Status" << ": Orange Zone" << endl;
	}
	else if (act_case > 0 && act_case <= 20)
	{
		cout << left << setw(20) <<  " Status" << ": Yellow Zone" << endl;
	}
	else
	{
		cout << left << setw(20) <<  " Status" << " : Green Zone" << endl;
	}
}

// Function for user enter the cases
void getInput ()
{
	cout << " <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>> " << endl;
	cout << left << setw(20) << " State name" << ": " ;
	getline (cin ,state_name) ;
	cout << left << setw(20) << " Total cases" << ": " ;
	cin >> tot_cases ;
	cout << left << setw(20) << " New cases" << ": " ;
	cin >> new_cases ;
	cout << left << setw(20) << " Total death" << ": " ;
	cin >> tot_death ;
	cout << left << setw(20) << " Total recovered" << ": " ;
	cin >> tot_recov ;
	
}


void dispOutput()
{
	act_case = tot_cases + new_cases - tot_death - tot_recov ;  //Calculate active cases
		while (act_case > largest)                              // Find the highest cases among them 
	{
		state = state_name ;
		largest = act_case ;
	}
	tot += act_case ;
	dispStatus ();
}


//	int highestCases(int first, int second, int third) {
//    // Compare the values and return the highest one
//    return std::max({first, second, third});
//}


void calcAverage ()
{
	// high_cases = highestCases (act_case, act_case) ;
	cout << " <<<<<<<<<<<< ACTIVE CASES >>>>>>>>>>>>> " << endl;
	average = (tot / ::count);
	cout << "Total : " << tot << endl
		<< "Highest : " << largest << " (" << state << ")"<< endl
		<< "Average for " << ::count << " states : " << average ;
}


int main ()
{
	do
	{ 
	getInput() ;
	dispOutput() ;
	::count ++ ;
	cin.ignore();
	cout << " Press <Enter> to continue..." ;
	cin.get(enterkey) ;
//	enterkey = cin.get();
	} while (enterkey == '\n') ;

	calcAverage() ;
	return 0;
}






/* <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>
 State name         : Negeri Sembilan
 Total cases        : 7103
 New cases          : 57
 Total death        : 11
 Total recovered    : 6274
<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>
 Active cases       : 875
 Status             : Red Zone
 Press <Enter> to continue...
 <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>
 State name         : Johor
 Total cases        : 3421
 New cases          : 167
 Total death        : 32
 Total recovered    : 1985
<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>
 Active cases       : 1571
 Status             : Red Zone
 Press <Enter> to continue...
 <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>
 State name         : Perak
 Total cases        : 2888
 New cases          : 17
 Total death        : 16
 Total recovered    : 2503
<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>
 Active cases       : 386
 Status             : Red Zone
 Press <Enter> to continue...
 <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>
 State name         : Perlis
 Total cases        : 44
 New cases          : 1
 Total death        : 2
 Total recovered    : 41
<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>
 Active cases       : 2
 Status             : Yellow Zone
 Press <Enter> to continue...
 <<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>
 State name         : Pulau Pinang
 Total cases        : 2978
 New cases          : 23
 Total death        : 9
 Total recovered    : 2743
<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>
 Active cases       : 249
 Status             : Red Zone
 Press <Enter> to continue...N
 <<<<<<<<<<<< ACTIVE CASES >>>>>>>>>>>>>
Total : 3083
Highest : 1571 (Johor)
Average for 5 states : 616
--------------------------------
Process exited after 121.5 seconds with return value 0
//Press any key to continue . . . */ 

