/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA4
 
 The program you write for this lab will read in the number of nodes and a binary relation representing a graph.
 The program will create an adjacency matrix from the binary relation.
 */

//Directives to bring in proper header files.
#include <iostream>

//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//Descr in definition.
void printMenu();

//Funcional prototypes (Descriptions are by function definitions)
int main()
{
    int userInput; //Stores user's menu choice
    int numNodes; //number of nodes
    char charac; //Stores current character during Adj Rel parsing.
    int setFlag = false; //Determines when there are two numbers stored for storing.
    int adjMatrix[10][10];//Adjacency Matrix.
    char x,y; //stores the x and the y indecie for the translation from relation to matrix
    
    
    //Initializing 2d array to 0 so 1s can be inserted accordingly later.
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            adjMatrix[i][j] = 0;
        }
    
    }
    
    
    //getting number of nodes from user.
    cout << "Please input the number of nodes: ";
    cin >> numNodes;
    
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
    
    
    /***********/
    /*menu loop*/
    /***********/
    int degreeCount; //counter variable that is used my multiple functions to keep track of the amount of degrees a single node has.
    int oddCount; //used to keep track of each node that has an odd degree throughout the entire set.
    int node1; //used as the first node in checking for adjacency.
    int node2; //used as the second node in checking for adjacency.
    
    printMenu(); //prints menu
    cin >> userInput; //priming read for menu choice
    
    while (userInput != 6) //While the user hasn't selected 'quit' (6)
    {
        //This switch statement is the main control mechanism that executes operations based on the user's menu choices.
        //As you can see below, each case has similar functionality, but not enough to convince me to make one helper function for all of it.
        //Creating multiple different functions for each case seems like a layer of abstraction that is not needed here as well.
        switch(userInput)
        {
                
            case 1: //Print the adjacency matrix
                cout << "The Adjacency Matrix is:\n";
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
                break;
                
            case 2: //Determine if there are any isolated nodes
                degreeCount = 0;
                cout << "The isolated nodes are:\n";
                for (int i = 0; i < numNodes; i++)
                {
                    //Loops through each row
                    for (int j = 0; j < numNodes; j++)
                    {
                        //Loops through each column
                        if (adjMatrix[i][j] == 1)
                        {
                            degreeCount++;
                        }
                    }
                    //If there are no arcs on ith node...
                    if (degreeCount == 0)
                    {
                        cout << i+1 << " ";
                        cout << endl;
                    }
                    //reset degree count for next iteration (i+1)
                    degreeCount = 0;
                    
                }
                //end of looping
                
                cout << endl;
                
                break;
                
            case 3: //Determine the degree of a node
                
                //set degree count to 0 in case it is not.
                degreeCount = 0;
                
                //Get node in question.
                cout << "Please Input the Node:\n";
                cin >> node1;
                
                //loop through each colum in target node to determine degree.
                for (int i = 0; i < numNodes; i++)
                {
                    if (adjMatrix[node1-1][i] == 1)
                    {
                        degreeCount++;
                    }
                }
                
                //end of looping
                cout << "The degree of node " << node1 << " is " << degreeCount << endl;
                
                break;
                
            case 4: //Determine if an Euler path exists
                //init oddCount to 0.
                oddCount = 0;
                
                //looping through every node, getting a degree count for each node.
                for (int i = 0; i < numNodes; i++)
                {
                    //Loops through each row
                    for (int j = 0; j < numNodes; j++)
                    {
                        //Loops through each column
                        if (adjMatrix[i][j] == 1)
                        {
                            degreeCount++;
                        }
                    }
                    //if the degree is odd on a particular node, increment oddCount.
                    if (degreeCount % 2 != 0)
                    {// odd degree count
                        
                        oddCount++;
                    }
                    
                    //reset degree count for next iteration (i+1)
                    degreeCount = 0;
                }
                //end of looping
                
                //If there are 0 nodes with an odd degree or 2 nodes with an odd degree, Euler Path Exists. Else, not.
                if (oddCount == 0 || oddCount == 2)
                {
                    cout << "An Euler path does exist for this graph.\n";
                }
                else
                {
                    cout << "An Euler path does NOT exist for this graph.\n";
                }
                break;
                
            case 5: //Determine if one node is adjacent to another
                
                //get target node 1 and 2.
                cout << "Please input the two nodes in question.\n";
                cin >> node1;
                cin >> node2;
                
                //see if one is adjacent to the other (in both rows), even though it should
                // be listed in both rows if they are adjacent, we check both here, implying
                //  the possibility for corrupt data or a directed graph.
                if (adjMatrix[node1-1][node2-1] == 1 || adjMatrix[node2-1][node1-1] == 1)
                {
                    cout << "Node " << node1 << " is adjacent to " << node2 << endl;
                }
                else
                {
                    cout << "Node " << node1 << " is NOT adjacent to " << node2 << endl;
                }
                break;
                
            default:
                break; //break is technically not needed here.
        }
        
        printMenu(); //prints menu
        cin >> userInput; //priming read for menu choice
        
    }
    //After menu loop has been exited.
    cout << "Goodbye\n\n";
    return 0;
    
}

//Function that prints the menu for user choice.
void printMenu()
{
    cout << "\nWhat would you like to do?\n\n"
    << "1.  Print the adjacency matrix\n"
    << "2.  Determine if there are any isolated nodes\n"
    << "3.  Determine the degree of a node\n"
    << "4.  Determine if an Euler path exists\n"
    << "5.  Determine if one node is adjacent to another\n"
    << "6.  Quit\n\n";
}
