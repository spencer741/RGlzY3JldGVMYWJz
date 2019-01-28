/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA5
 
 
 The program you write for this lab will read in the number of nodes and a binary relation representing a graph. The adjacency relation MUST be entered as a list of ordered pairs with commas as separators. The program will create an adjacency matrix from the binary relation and print it. It will then generate the reachability matrix using Warshall's algorithm and print it.
 */

//Directives to bring in proper header files.
#include <iostream>

//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

void printMenu();

//Funcional prototypes (Descriptions are by function definitions)
int main()
{
    int numNodes; //number of nodes
    char charac; //Stores current character during Adj Rel parsing.
    int setFlag = false; //Determines when there are two numbers stored for storing.
    
    char x,y; //stores the x and the y indecie for the translation from relation to matrix
    
    //getting number of nodes from user.
    cout << "Please input the number of nodes: ";
    cin >> numNodes;
    
    int adjMatrix[numNodes][numNodes];//Adjacency Matrix.
    
    
    //Initializing 2d array to 0 so 1s can be inserted accordingly later.
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    
    
    
    
    /*****************************************************************************/
    /*Parsing loop: Parses Adjacency relation input and creates adjacency matrix.*/
    /*****************************************************************************/
    
    cout << "Please input the adjacency relation:\n"; //getting adjacency relation input
    cin >> charac; //priming read
    
    while(charac != '}')
    {
        if (charac != '{' && charac != '(' && charac != ')' && charac != ',')
        {
            if (!setFlag)
            {
                //Store first value in ordered pair.
                x = charac;
                //reset flag to opposite scenario.
                setFlag = true;
            }
            else
            {
                //Store second value in ordered pair.
                y = charac;
                //inserting complete ordered pair into matrix, since there are
                //only two items per pair, this is where it takes place.
                //ALSO: Subracting '0' from each to convert into face integer value.
                adjMatrix[(int)(x - '0') - 1][(int)(y - '0') - 1] = 1;
                //reset flag to opposite scenario
                setFlag = false;
            }
        }
        cin >> charac; //Priming read for next iteration.
    }
    
    
    //Printing out the adjacency matrix
    cout << "\nThe Adjacency Matrix is:\n";
    for (int i = 0; i < numNodes; i++)
    {
        //Loops through each row
        for (int j = 0; j < numNodes; j++)
        {
            //Loops through each column
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
    //end of looping
    
    
    /*
     1. Consider column k + 1 in mk.
     2. For each row with a 0 entry in this column, copy that row to mk+1.
     3. For each row with a 1 entry in this column, or that row with row k + 1 and write
     the resulting row in mk+1.
     */
    //Computing Reachability Matrix
    //For this project's purpose, we will reuse the adjacency matrix.
    for(int k = 0; k < numNodes; k++)
    { //keeps track of which column the iteration is currently on.
        for(int i = 0; i < numNodes; i++)
        {//keeps track of scanning each row
            if (adjMatrix[i][k] != 0)
            {
                for(int j = 0; j < numNodes; j++)
                { //iterates through specific row if
                    adjMatrix[i][j] = (adjMatrix[i][j] || adjMatrix[k][j]);
                }
            }
        }
    }
    
    //Printing out the adjacency matrix
    cout << "\nThe Reachablility is:\n";
    for (int i = 0; i < numNodes; i++)
    {
        //Loops through each row
        for (int j = 0; j < numNodes; j++)
        {
            //Loops through each column
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
