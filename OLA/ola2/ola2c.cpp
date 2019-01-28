/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA2
 *Program #3
 *Purpose: This program main will use a single arithmetic expression to determine the value for the nth term.
 *Recurrance Relation: S(1) = 1
 *                     S(n) = S(n-1) + n^3
 * Solved: 1 + (n^2(n+1)^2) / (4) ***since the expression for n^3 is (n^2(n+1)^2) / (4)***
 *Due date: October 18, 2018
*/

//NOTE: I am using the double datatype because of its ability to store very large numbers (via the mantissa of course. I chose double over float, because doubles have more precision.)

//Directives to bring in proper header files.
#include <iostream>
//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//Main entry point to application*********************************************
int main()
{
    //Repesents the sum of each nth expression that is used to compute the value wanted by the user.
    int S = 0;
    
    //This variable represents the user's input on the nth value he or she wants.
    int n;
    
    //output that prompts the user for his or her input.
    cout << "This program determines the value of the nth term for the Recurrance Relation by using a single arithmetic expression:\nS(1) = 1\nS(n) = S(n-1) + n^3\nPlease enter a value for n : ";
    
    //Reads the user input into the variable n.
    cin >> n;
    
    //Single arithmetic expression that 'instantly' computes the value of the nth term wanted by the user.
    S = ((n*n) * ((n+1)*(n+1))) / (4) ;
    
    //output statement that contains the function call that computes the nth value of the expression.
    cout << "S(" << n << ") = " << S << endl;
    
    return 0;
}
