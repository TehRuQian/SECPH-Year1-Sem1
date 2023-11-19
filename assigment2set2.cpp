/*
Assignment 2 Set 2
Tan Yi Ya A23CS0187
Teh Ru Qian A23CS0191
19/11/2023
 */

#include<iostream>
#include<iomanip>
using namespace std;

int main (){
    cout << "Proton Car Loan Calculator " << endl;

    int model, variant, region;
    double price,
            down_payment,
            mp,
            rate,
            r,
            n, t;               //n=month, t=time (years)

    bool repeat;
    char data;

    do
    {
        cout << endl << "Model [1-X50, 2-Exora, 3-Persona] :" ;
        cin >> model;

        // model == X-50
        if (model == 1)
        {
            cout << "Variants [1-1.5T Standard , 2-1.5T Premium] :";
            cin >> variant;
            if (variant == 1 || variant == 2 )
            {
                cout << "Region [1-Peninsular Malaysia, 2-East Malaysia] :";
                cin >> region;
            }
        }

            // model == Exora
        else if (model == 2)
        {
            cout << "Variants [1-1.6T Executive CVT , 2-1.6T Premium CVT] :";
            cin >> variant;
            if (variant == 1 || variant == 2 )
            {
                cout << "Region [1-Peninsular Malaysia, 2-East Malaysia] :";
                cin >> region;
            }
        }

            // model == Persona
        else if (model == 3)
        {
            cout << "Variants [1-1.6L Standard CVT , 2-1.6L Premium CVT] :";
            cin >> variant;
            if (variant == 1 || variant == 2 )
            {
                cout << "Region [1-Peninsular Malaysia, 2-East Malaysia] :";
                cin >> region;
            }
        }

        cout << endl << "Car info" << endl;
        if (model == 1)                //X50
        {
            cout << "Model : X50 " << endl;
            if(variant == 1)
            {
                cout << "Variant : 1.5T Standard" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 86300.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 88300.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }
            else
            {
                cout << "Variant : 1.5T Premium" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 101800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 103800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }

        }

        if (model == 2)                //Exora
        {
            cout << "Model : Exora " << endl;
            if(variant == 1)
            {
                cout << "Variant : 1.6T Executive CVT" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 62800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 65300.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }
            else
            {
                cout << "Variant : 1.5T Premium" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 69800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 72300.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }
        }

        if (model == 3)                //Persona
        {
            cout << "Model : Persona " << endl;
            if(variant == 1)
            {
                cout << "Variant : 1.6L Standard CVT" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 47800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 49800.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }
            else
            {
                cout << "Variant : 1.6L Premium CVT" << endl;
                if(region == 1)
                {
                    cout << "Region : Peninsular Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 54600.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
                else
                {
                    cout << "Region : East Malaysia" << endl;
                    cout << "Paint Type : Metallic" << endl;
                    price = 60300.00;
                    cout << "Price (MYR): " << fixed << showpoint << setprecision(2) << price << endl;
                }
            }

        }

        cout << endl << "Down Payment (MYR) :" ;
        cin >> down_payment ;
        cout << "Interest Rate (%) :" ;
        cin >> rate;
        cout << "Repayment period (in years) :";
        cin >> t;
        r = rate/100;
        n = 12;
        price -= down_payment;
        mp = (price * (1 + (r*t))) / (t*n);
        cout << "MONTHLY INSTALLMENT (MYR) :" << mp << endl;
        cout << endl;

        repeat = false;
        cout << "Do you want to enter other data ? [Y @ N] :" ;
        cin >> data ;
        if (data == 'Y')
        {
            repeat = true;
        }
    } while (repeat);

    cout << endl;
    cout << "Thank you :) ";
}

/*
C:\h\cmake-build-debug\h.exe
Proton Car Loan Calculator

Model [1-X50, 2-Exora, 3-Persona] :3
Variants [1-1.6L Standard CVT , 2-1.6L Premium CVT] :2
Region [1-Peninsular Malaysia, 2-East Malaysia] :1

Car info
Model : Persona
Variant : 1.6L Premium CVT
Region : Peninsular Malaysia
Paint Type : Metallic
Price (MYR): 54600.00

Down Payment (MYR) :5460
Interest Rate (%) :3.5
Repayment period (in years) :9
MONTHLY INSTALLMENT (MYR) :598.32

Do you want to enter other data ? [Y @ N] :N

Thank you :)
Process finished with exit code 0

 */