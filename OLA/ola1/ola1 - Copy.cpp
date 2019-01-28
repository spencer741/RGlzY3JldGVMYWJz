#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void parseExpression(bool Expression[]);
int main()
{
    
    bool Expression1[8]; //Results from the expression evaluation are stored here for the first expression.
    bool Expression2[8]; //Results from the expression evaluation are stored here for the second expression.
    bool Equivalence[8]; //Results from the expression equivalency evaluation are stored here between the first and second expressions.
    int eCounter = 0; //Counter that keeps track of equivalencies to determine if the two expressions are equivalent all the way through.
   
    cout << "input the first expression:\n";
    
    parseExpression(Expression1);
   
    cout << "input the second expression:\n";
    
    parseExpression(Expression2);
    
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
    

    //produce truth table based on standard values of p and q and calculate.


    return 0;
}
//Generate Truth table for given expression
void parseExpression(bool Expression[])
{
    //Since we are assuming that three variables are entered in each time,
    //we can go ahead and hard-code the number of possible outcomes (rows)
    //that are present between these three variables of unknown boolean values.
    bool var1[8] = {false, false, false, false, true, true, true, true};
    bool var2[8] = {false, false, true, true, false, false, true, true};
    bool var3[8] = {false, true, false, true, false, true, false, true};
    //Two helper arrays to make evaluating expressions in postfix easier.
    bool Helper1[8];
    bool Helper2[8];  
    
    //The tracker variable 'tracks' what operation occured last to determine which values to apply negation to if the 'N' character is parsed.
    int tracker = 0;
    //The count variable keeps track of the number of characters in the expression. This is useful when determining if there were no operators present in the expression.
    int count = 0;
    //Holds each character value from the expression as it is paresed. 
    char character;

    //initilization for (pre-check) while loop below.
    cin >> character;
  
    //Iterate through the loop as long as the parser hasn't reached the end of the expression.
    while (character != 'E')
    {
        
        count += 1; //Increment count for length evaluation later.

        switch (character)
        {
            case 'P':
                for(int i = 0; i < 8; i++ )
                {
                    Helper1[i] = var1[i];
                }
                tracker = 1;
                break;
            
            case 'Q':
                for(int i = 0; i < 8; i++ )
                {
                    Helper2[i] = var2[i];
                }
                tracker = 2;
                break;

            case 'R':
                for(int i = 0; i < 8; i++ )
                {
                    Helper2[i] = var3[i];
                }
                tracker = 2;
                break;

            case 'A':
                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (Helper1[i] && Helper2[i]);
                }
                tracker  = 1;
                break;

            case 'O':
                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (Helper1[i] || Helper2[i]);
                }
                tracker = 1;
                break;
            case 'I':

                for (int i = 0 ; i< 8 ; i++)
                {
                    Helper1[i] = (!(Helper1[i]) || Helper2[i]);
                }
                tracker = 1;
                break;
            case 'N':
            
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
        cin >> character;
    }
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



/*
        if (character == 'P')
        {
            for(int i = 0; i < 8; i++ )
            {
                Helper1[i] = var1[i];
            }
            tracker = 1;
        }
        else if (character == 'Q')
        {
            for(int i = 0; i < 8; i++ )
            {
                Helper2[i] = var2[i];
            }
            tracker = 2;
        }
        else if (character == 'R')
        {
            for(int i = 0; i < 8; i++ )
            {
                Helper2[i] = var3[i];
            }
            tracker = 2;
        }
        else if(character == 'A')
        {
            for (int i = 0 ; i< 8 ; i++)
            {
                Helper1[i] = (Helper1[i] && Helper2[i]);
            }
            tracker  = 1;
        }
        else if(character =='O')
        {
            for (int i = 0 ; i< 8 ; i++)
            {
                Helper1[i] = (Helper1[i] || Helper2[i]);
            }
            tracker = 1;
        }
        else if(character =='I')
        {
            for (int i = 0 ; i< 8 ; i++)
            {
                Helper1[i] = (!(Helper1[i]) || Helper2[i]);
            }
            tracker = 1;
        }
        else if(character =='N')
        {
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
        }
        cin >> character;
    }
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
    */

}