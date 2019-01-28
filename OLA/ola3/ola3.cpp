/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA3
 *Your program should do the following 9 things using only arrays (no classes or pointers):
 *1.  read in a left-child, middle-child, right-child array representation for a ternary tree
 *2.  store the tree as an adjacency matrix and as a left child, middle child, right child array.
 *3.  print out the adjacency matrix and the left child, middle child, right child array representation.
 *4.  print the preorder, inorder, and postorder traversals of the tree using the left,middle,right child array.
 *5.  do a separate run for each graph.
 *6.  do input from the keyboard.
 *7.  print only the portion of the matrix that actually refers to the current graph (there will be at most 10 nodes in a graph)
 *8.  have a function that does items 1 and 2, another function that does item 3, and three separate functions for item 4 (i.e., one for each of preorder, inorder, and postorder).
 *
 */

//Directives to bring in proper header files.
#include <iostream>

//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//Funcional prototypes (Descriptions are by function definitions)
void readStore(int numNodes, int childArr[][3], int adjMatrix[][10]);
void printRep(int numNodes, int childArr[][3], int adjMatrix[][10]);
void inorder(int childArr[][3], int root, int row);
void preorder(int childArr[][3], int root, int row);
void postorder(int childArr[][3], int root, int row);

int main()
{
    int numNodes = 0; // Holds the value of the number of nodes.
    
    cout << "Input graph data:\n"; // Prompts user for graph data.
    cin >> numNodes; // Reads in the number of nodes (the first value)
    
    int childArr[numNodes][3]; // This is the array definition for the Left, Middle, Right Child array.
    int adjMatrix[10][10]; // This is the array definition fo the adjacency matrix.
    
    readStore(numNodes, childArr, adjMatrix);
    
    printRep(numNodes, childArr, adjMatrix);
    
    cout << "The preorder traversal is:\n";
    preorder(childArr, 1 ,0);
    cout << "\nThe inorder traversal is:\n";
    inorder(childArr, 1 ,0);
    cout << "\nThe postorder traversal is:\n";
    postorder(childArr, 1 ,0);
    cout << endl;
    
    return 0;
    
}

//read in a left-child, middle-child, right-child array rep0o-ki 8uv bgb/;.'presentation for a ternary tree.
//store the tree as an adjacency matrix and as a lc, mc, rc array.
void readStore(int numNodes, int childArr[][3], int adjMatrix[][10]) //read and store
{
    
    
   
    int targetNode = 0; // Holds the value of the target node.
    // This is a nested loop that handles reading in the values for the Left, Middle, Right Child Array
    for (int i = 0; i < numNodes; i++) //Rows (same # of rows for both data representations)
    {
        cin >> targetNode; // Read in the target node.
        
        //Going through each column, reading in each value, and putting 1's in the appropriate places.
        for (int j = 0; j < 3; j++)
        {
            //Read in single value
            cin >> childArr[i][j];
            
            //Check to see if value doesn't equal -1 (indicating that that particular left, middle, or
            // right child exists)
            if (childArr[i][j] != -1)
            {
                //If it exists, the mapped value in the adjacency matrix is equal to 1.
                //Note: Subtracting by 1 from the mapped value to adjust for arrays starting at 0.
                adjMatrix[i][childArr[i][j]-1] = 1;
            }
        }
        
        // Going through each column (after all of the necessary 1's have been assigned above)
        // and assigning 0's in each slot that does not contain a 1.
        for (int j = 0; j < numNodes; j++)
        {
            if(adjMatrix[i][j] != 1)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    cout << endl;
}
//Print out the adjacency matrix and the left child, middle child, right child array representation.
void printRep(int numNodes, int childArr[][3], int adjMatrix[][10]) //print representations
{
    cout << endl << "The Adjacency Matrix is:" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "The left child, middle child, right child array representation is:" << endl;
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << childArr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Below are the traversal functions using a recursive technique with a left child, middle child, right child array.

//Preorder traversal and print
void preorder(int childArr[][3], int root, int row)
{
    
    cout << root << " ";
    
    if (childArr[row][0] != -1)
        preorder(childArr, childArr[row][0], childArr[row][0]-1);
    
    if (childArr[row][1] != -1)
        preorder(childArr, childArr[row][1], childArr[row][1]-1);
    
    if (childArr[row][2] != -1)
        preorder(childArr, childArr[row][2], childArr[row][2]-1);
    
}

//inorder traversal and print
void inorder(int childArr[][3], int root, int row)
{
    if (childArr[row][0] != -1)
        inorder(childArr, childArr[row][0], childArr[row][0]-1);
    
    cout << root << " ";
    
    if (childArr[row][1] != -1)
        inorder(childArr, childArr[row][1], childArr[row][1]-1);
    
    if (childArr[row][2] != -1)
        inorder(childArr, childArr[row][2], childArr[row][2]-1);
}

//post order traversal and print
void postorder(int childArr[][3], int root, int row)
{
    if (childArr[row][0] != -1)
        postorder(childArr, childArr[row][0], childArr[row][0]-1);
    
    if (childArr[row][1] != -1)
        postorder(childArr, childArr[row][1], childArr[row][1]-1);
    
    if (childArr[row][2] != -1)
        postorder(childArr, childArr[row][2], childArr[row][2]-1);
    
    cout << root << " ";
}
