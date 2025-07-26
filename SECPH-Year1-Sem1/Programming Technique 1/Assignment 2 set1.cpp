#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int age, height, weight;
    double bmr;
    char gender, data;
    bool repeat;
    
do{
    cout << endl << "Basal Metabolic Rate (BMR) Calculator" << endl;

    do {
        repeat = false;
        cout << endl << "Age [15-80] : ";
        cin >> age;
        if (age < 15 || age > 80) {
            repeat = true;
            cout << "Please enter a valid age between 15 and 80." << endl;
        }
    } while (repeat);

    do {
        repeat = false;
        cout << "Gender [F or M] : ";
        cin >> gender;
        if (gender != 'F' && gender != 'M') {
            repeat = true;
            cout << "Please enter 'F' for Female or 'M' for Male." << endl;
        }
    } while (repeat);

    cout << "Height (cm) : ";
    cin >> height;

    cout << "Weight (kg) : ";
    cin >> weight;

    // Calculate BMR based on gender
    if (gender == 'F') {
        bmr = (10 * weight) + (6.25 * height) - (5 * age) - 161;
    } else {
        bmr = (10 * weight) + (6.25 * height) - (5 * age) + 5;
    }

    cout << endl <<"Basal Metabolic Rate (BMR) is: " << fixed << showpoint << setprecision(2) << bmr << " calories/day (using Mifflin-St Jeor Equation)" << endl;
    cout << endl << "Daily calorie needs based on activity level"<<endl;
    cout << left << setw(70) << endl << "Activity level " << "Calorie" << endl;
    cout << left << setw(70) << "Sedentary : little or no exercise " << bmr*1.2 << endl;
    cout << left << setw(70) << "Exercise 1-3 times/week " << bmr*1.38 << endl;
    cout << left << setw(70) << "Exercise 4-5 times/week " << bmr*1.46 << endl;
    cout << left << setw(70) << "Daily exercise or intense exercise 3-4 times/week " << bmr*1.55 << endl;
    cout << left << setw(70) << "Intense exercise 6-7 times/week " << bmr*1.72 << endl;
	cout << left << setw(70) << "Very intense exercise daily, or physical job" << bmr*1.9 << endl;
	
	cout << endl <<"Exercise : 15-30 minutes of elevated heart rate activity." << endl;
	cout << "Intense exercise : 45-120 minutes of elevated heart rate activity." << endl;
	cout << "Very intense exercise : 2+ hours of elevated heart rate activity." << endl;
	
	repeat = false;
	cout << endl << "Do you want to enter other data? [Y @ N] : ";
	cin >> data;
	if (data == 'Y')
	{
		repeat = true;
	}
}while(repeat);

cout << endl << "Thank you :)";
    return 0;
}
