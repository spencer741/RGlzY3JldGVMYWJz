/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA2
 *Program #1
 *Purpose: This program main will call a recursive functions S to determine the value for the nth term.
 *Recurrance Relation: S(1) = 1
 *                     S(n) = S(n-1) + n^3
 *Due date: October 18, 2018
*/

//Directives to bring in proper header files.
#include <iostream>

//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//This is a recursive function that computees values from 1 to n for the recurrnace relation S(n) as defined in the description above.
int S(int n);

//Main Entry point to the application******************************************
int main()
{
    //This variable represents the user's input on the nth value he or she wants.
    int n;
    
    //output that prompts the user for his or her input.
    cout << "This program determines the value of the nth term for the Recurrance Relation by calling a recursive function:\nS(1) = 1\nS(n) = S(n-1) + n^3\nPlease enter a value for n : ";
    
    //Reads user input into the variable n.
    cin >> n;
    
    //output statement that contains the function call that computes the nth value of the expression.
    cout << "S(" << n << ") = " << S(n) << endl;
    
    return 0;
}

//Recursive function that computes the nth value.
int S(int n)
{
    //If n is equal to one, we know to return 1, thus popping all called functions off of the call stack and bubbling up through each n value > 1.
    if(n == 1)
    {
        return 1;
    }
    else //We haven't reached one yet, so call S(n-1) to probe another layer into the expression.
    {
        return S(n-1) + n*n*n;
    }
    
}

