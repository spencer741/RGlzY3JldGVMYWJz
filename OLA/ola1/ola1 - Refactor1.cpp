/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA1
 *Purpose: The purpose of this program is to test whether or not the alternative expression for the circuit is equivalent to
 *         the original expression for the circuit. This problem boils down to testing whether or not two wff's are equivalent
 *         by creating truth tables.
 *Due date: October 04, 2018
*/

//Directives to bring in proper header files.
#include <iostream>
#include <iomanip>
//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;
//This function is responsible for parsing an expression one character at a time using cin and evaluating it.
void parseExpression(bool Expression[]);

//Entry point to application *******************************************************************************
int main()
{

    bool Expression1[8]; //Results from the expression evaluation are stored here for the first expression.
    bool Expression2[8]; //Results from the expression evaluation are stored here for the second expression.
    bool Equivalence[8]; //Results from the expression equivalency evaluation are stored here between the first and second expressions.
    int eCounter = 0; //Counter that keeps track of equivalencies to determine if the two expressions are equivalent all the way through.
   
    cout << "input the first expression:\n";
    
    parseExpression(Expression1); //since arrays are PBR, Expression1 gets the results of the evaluation without the function having to return a pointer or anything like that.
   
    cout << "input the second expression:\n";
    
    parseExpression(Expression2); //refer to line 28
    
    //Formatting the results columns for display to the user.
    cout << endl << setw(15) << left << "first" << setw(15) << "second" << setw(15) << left << "equivalence";

    //loop that prints the results to the screen.
    for (int i = 0; i < 8; i++)
    {
        //Assigning equivalence values from both expression results
        Equivalence[i] = (Expression1[i] == Expression2[i]);

        //Counting the amount of truthes for complete equivalence checking.
        if (Equivalence[i] == true)
        {
            eCounter += 1;
        }
        
        //Converts each boolean bit to the character 'T' or 'F' and adds to the output stream in an easy-to-read format for the user.
        Expression1[i] == 1 ? cout << endl << setw(15) << 'T' : cout << endl << setw(15) << 'F';
        Expression2[i] == 1 ? cout << setw(15) << 'T' : cout << setw(15) << 'F';
        Equivalence[i] == 1 ? cout << setw(15) << 'T' : cout << setw(15) << 'F';

    }

    if (eCounter == 8)
    {
        cout << "\nThe two expressions are equivalent.\n";
    }
    
    return 0;
}
//Generate Truth table for given expression
void parseExpression(bool Expression[])
{
    //Since we are assuming that three variables are entered in each time,
    //we can go ahead and hard-code the number of possible outcomes (rows)
    //that are present between these three variables of unknown boolean values.
    bool var1[8] = {false, false, false, false, true, true, true, true}; //Represents P
    bool var2[8] = {false, false, true, true, false, false, true, true}; //Represents Q
    bool var3[8] = {false, true, false, true, false, true, false, true}; //Represents R

    //Two helper arrays to make evaluating expressions in postfix easier.
    bool Helper1[8];
    bool Helper2[8];  
    
    //The tracker variable 'tracks' what operation occured last to determine which values to apply negation to if the 'N' character is parsed.
    int tracker = 0;
    //The count variable keeps track of the number of characters in the expression. This is useful when determining if there were no operators present in the expression.
    int count = 0;
    //Holds each character value from the expression as it is paresed. 
    char character;

    //priming read for (pre-check) while loop below.
    cin >> character;

    bool first = true;
  
    //Iterate through the loop as long as the parser hasn't reached the end of the expression.
    while (character != 'E')
    {
        
        count += 1; //Increment count for length evaluation later.

        switch (character) //This switch performs actions according to the values of each character parsed.
        {
            //Logic description For variables: P always goes into helper one, while Q and R go into helper2, since only two variables are processed at the same time.
            case 'P':
                if (first == true)
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper1[i] = var1[i];
                    }
                    first = false;
                    
                }
                else
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper2[i] = var1[i];
                    }
                }
               
                tracker = 1;
                break;
            
            case 'Q':
                if (first == true)
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper1[i] = var2[i];
                    }
                    first = false;
                    
                }
                else
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper2[i] = var2[i];
                    }
                }
                tracker = 2;
                break;

            case 'R':
                if (first == true)
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper1[i] = var3[i];
                    }
                    first = false;
                    
                }
                else
                {
                    for(int i = 0; i< 8 ; i++)
                    {
                        Helper2[i] = var3[i];
                    }
                }
                tracker = 2;
                break;
            //Logic description for operators: AND, OR, and IMP all compute the truth values and assign the result to Helper1.
            case 'A': //AND
                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (Helper1[i] && Helper2[i]);
                }
                tracker  = 1;
                break;

            case 'O': //OR
                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (Helper1[i] || Helper2[i]);
                }
                tracker = 1;
                break;

            case 'I': //Implication (A -> B == A' v B)
                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (!(Helper1[i]) || Helper2[i]);
                }
                tracker = 1;
                break;
            //Logic Description for NOT: The tracker variable is used to identify which helper array was modified last, so the negation can be applied to the correct truth set.
            //                           Results are stored in helper2 or helper1 accordingly.
            case 'N': //NOT
                if (tracker == 1)
                {
                    for (int i = 0 ; i< 8 ; i++)
                    {
                        Helper1[i] = (!(Helper1[i]));
                    }
                }
                else
                {
                    for (int i = 0 ; i< 8 ; i++)
                    {
                        Helper2[i] = (!(Helper2[i]));
                    }
                }   
                break;
        }
        //priming read for next iteration.
        cin >> character;
    }
    //After the end of the expression has been reached, we need to make sure that the correct result set is 'returned'.
    //There is one case in which the user enters only one variable per expression, in which case the results should take
    //from helper2 instead of helper1 (which is the results array for the rest of the conditions).
    if (count == 1 && tracker != 1)
    {
        for(int i = 0 ; i< 8 ; i++)
        {
            Expression[i] = Helper2[i];
        }
    }
    else
    {
        for(int i = 0 ; i< 8 ; i++)
        {
            Expression[i] = Helper1[i];
        }
    }
}
