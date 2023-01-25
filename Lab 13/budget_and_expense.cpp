//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 6, 2022
//This program asks the user for their annual budget for a task...
//... and estimated montly expenses. Suppose due to inflation, monthly...
//... expense in July to Decmber is 15% than that in January to June 
// Print out month, monthly expense, and remaining balance in the budget in ...
//... the end of a month. The remaining balance can be negative, ...
//...meaning a user under-estimated the expenses. If the remaining ...
//...balance after a year is nagative, print "need higher budget".

#include <iostream>
using namespace std;

int main(){
    int annual;
    int monthly;
    double budget;
    double monExpense;

    //The annual spendings will be equal to annual 
    //the monthly expense will be equal to monthly, until it hits month 7 (july)
    cout << "Input our annual budget: ";
    cin >> annual;
    budget = double(annual);
    cout << "Input your month expense: ";
    cin >> monthly;
    monExpense = double(monthly);
    cout << "month	expense	remaining balance of budget\n";

    //1. every month, expenses is equal to monthly budget and remaining balance from last month
    for (int month = 1; month < 13; month++){
        //2. when month == 7, expense will be equal to monthly*1.15
        if (month == 7){
            monExpense = monExpense * 1.15;
        }
        budget = budget - monExpense;
        //format: month (int) | expense (double) | remaining balance of budget (double)
        printf("%5d\t%7.2f\t%27.2f\n", month, monExpense, budget);
        //3. when month == 12, if the budget is less than 0, print "need higher budget"
        if (month == 12){
            if (budget < 0){
                cout << "need higher budget";
            }
        }
    }
}