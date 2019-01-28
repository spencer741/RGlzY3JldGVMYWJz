/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA2
 *Program #2
 *Purpose: This program main will use a for loop inside main to determine the value for the nth term.
 *Recurrance Relation: S(1) = 1
 *                     S(n) = S(n-1) + n^3
 *Due date: October 18, 2018
*/


//Directives to bring in proper header files.
#include <iostream>
//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//Main entry point to application*********************************************
int main()
{
    //Repesents the sum of each nth expression that is used to compute the value wanted by the user.
    int S = 1;
    
    //This variable represents the user's input on the nth value he or she wants.
    int n;

    //output that prompts the user for his or her input.
    cout << "This program determines the value of the nth term for the Recurrance Relation by using a for loop:\nS(1) = 1\nS(n) = S(n-1) + n^3\nPlease enter a value for n : ";
    //Reads the user input into the variable n.
    cin >> n;
    
    //This is the for loop that determines the value for the nth term defined by the user.
    //It loops all the way from 2 to n and adds the value of the previous n-term's expression to the working sum, as defined by the recurrance relation in the description.
    for (int i = 2 ; i <= n; i++ )
    {
        S += i*i*i;
    }
    //output statement that contains the function call that computes the nth value of the expression.
    cout << "S(" << n << ") = " << S << endl;
    
    return 0;
}
