// Loan and interest rate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// the payments are always assumed to be 1 twentieth of the amount left
#include <iostream>
using namespace std;
int main()
{
    double loan, interestRate, monthlyPayment, interest, loanReduction, totalInterest{0}, monthNumber{0}, yearNumber{}, originalLoan, annualPercentage;
    cout << "Input the loan amount: $";
    cin >> loan;
    cout << "Now input the interest rate: %";
    cin >> interestRate;
    interestRate = interestRate / 100; // this is so we can times by the interest rate to get the interest ammount for each month (10% / 100 = 0.10)
    originalLoan = loan;
    monthlyPayment = loan / 20; // the payments for each month are 1 twentieth of the total loan

    while (loan > monthlyPayment)
    {
        cout << "------------------------------------------" << endl;
        
        monthNumber++;
        
        cout << "This is the statement for month " << monthNumber << endl;
       
        
        cout << "This months payment is $" << monthlyPayment << endl;
        
        interest = (loan * interestRate) / 12;
        
        cout << "The interest for this month is $" << interest << endl;
        
        loanReduction = monthlyPayment - interest;
        
        totalInterest = totalInterest + interest;
        
        loan = loan - loanReduction;
        
        cout << "The loan left after this month is $" << loan << endl;
        
        cout << "--------------------------------------------------" << endl;
        if (monthNumber >= 12)
        {
            yearNumber = 1;
            if (monthNumber >= 24)
            {
                yearNumber = 2;
            }
        }
    }
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "The total interest paid over the " << monthNumber << " month period was $" << totalInterest << endl;
    annualPercentage = (totalInterest / originalLoan) / yearNumber;
    cout << "The annualized percenatge of the orignal balance paid in interest was " << annualPercentage << "% of the original loan" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
