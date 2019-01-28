/*Author:  spencer741
 *Course:  CSCI 3080
 *Lab number: OLA6
 
 
 Your algorithm should read a packet, check for error in transmission, if there is an error correct it, extract the gray code word from the packet, convert the gray to binary, convert binary to decimal then correct for the excess 127, and print the answer as a char (static_cast <char> (ans)). Then get the next packet.
 */

//Directives to bring in proper header files.
#include <iostream>

//Using the std namespace. (since there are no conflicting functions, this should be safe for now)
using namespace std;

//Main entry point for the application**********************************
int main()
{
    
    char temp; //Temp variable to load in each character
    while(cin>>temp) //Reads the packets until there are no more. (Acts as priming read for each iteration.)
    {
        //reading in packet of size 13************************************
        //read in 13 characters at a time.
        int hammingCode[4]; //array that holds hamming code.
        int arr[13]; //array that holds all characters in a packet.
        arr[0] = (int)(temp - '0'); //This captures the first char due read structure.
        for (int i = 1 ; i < 13 ; i++) //Gets the rest of the packet bits.
        {
            cin >> temp; //reads in one char
            arr[i] = (int)(temp - '0'); //loads into array and converts to int for processing.
            
        }
        
        //Checking for error in transmission*******************************
        int parityCounter = 0; //This var is used to keep track of parity information throughout the iteration.
        //cout << "Parity Count for each set\n";
        for(int i = 0; i < 4 ; i++)
        {
            switch(i) //each case contains a tailored for loop for parsing each subset of the packet, according to calculating the hamming code for error checking and correction.
            {
                case 0: //for eights position
                    for (int j = 7; j < 13; j++)
                    {
                        if(arr[j] == 1)
                        {
                            parityCounter ++;
                        }
                    }
                    //cout << parityCounter << endl;
                    break;
                case 1: //for fours position
                    for (int j = 3; j < 13; j++)
                    {
                        if(arr[j] == 1)
                        {
                            parityCounter ++;
                        }
                        if(j == 6)
                        {
                            j += 4;
                        }
                    }
                    //cout << parityCounter << endl;
                    break;
                case 2: //for threes position
                    for (int j = 1; j < 11; j++)
                    {
                        if(arr[j] == 1)
                        {
                            parityCounter ++;
                        }
                        if(j % 2 == 0)
                        {
                            j += 2;
                        }
                    }
                    //cout << parityCounter << endl;
                    break;
                case 3:
                    for (int j = 0; j < 13; j+=2)
                    {
                        if(arr[j] == 1)
                        {
                            parityCounter ++;
                        }
                    }
                    //cout << parityCounter << endl;
                    break;
                
            }
            //Determining hamming code
            if(parityCounter % 2 == 0)
            {
                //has even parity. No errors.
                //store 0 in eights position
                hammingCode[i] = 0;
            }
            else
            {
                //has odd parity. There is an error
                //store 1 in eights position
                hammingCode[i] = 1;
            }
            parityCounter = 0; //Reset count to 0.
            
        }
        /*cout << "Final Hamming Before Correction:\n";
        cout << hammingCode[0] <<endl;
        cout << hammingCode[1]<<endl;
        cout << hammingCode[2]<<endl;
        cout << hammingCode[3]<<endl <<endl;*/
    
        //Correcting any errors, if any************************************
        parityCounter = 0; //reuse parityCounter from before, since it is doing something similar. setting = 0 is redundant at this point.
        
        //Going through each bit in the hamming code and determining parity for processing.
        if(hammingCode[0] == 1)
        {
            parityCounter += 8;
        }
        if(hammingCode[1] == 1)
        {
            parityCounter += 4;
        }
        if(hammingCode[2] == 1)
        {
            parityCounter += 2;
        }
        if(hammingCode[3] == 1)
        {
            parityCounter += 1;
        }
        //Change the corrupted bit, if there is any.
        if (parityCounter > 0)
        {
            if (arr[parityCounter-1] == 0)
            {
                arr[parityCounter-1] = 1;
            }
            else
            {
                arr[parityCounter-1] = 0;
            }
        }
        
        /*cout << "Packet after correction\n";
        for (int i = 0; i < 13; i++)
        {
            cout << arr[i];
        }
        cout << endl;*/
        
        //Extract Gray Code word from the packet*********************************
        //Don't forget to ignore parity bits.
        //p bits are in positions 0 1 3 7 for the array.
        int grayCode[9]; //Holds the gray code
        int count = 0; //count variable.
        for(int i = 0; i < 13 ; i++)
        {
            if(i != 0 && i != 1 && i != 3 && i != 7)
            {
                grayCode[count] = arr[i];
                count++;
            }
            
        }
        
        /*cout << "Extracted Code from packet\n";
        for (int i = 0; i < 9; i++)
        {
            cout << grayCode[i];
        }
        cout << endl;*/
    
    
        //Convert Gray to Binary********************************************
        int binaryCode[9]; //Stores binary
        //copy first element down.
        grayCode[0] = binaryCode[0];
        for (int i = 0; i < 9; i++)
        { //XOR with proper element from each array.
            binaryCode[i+1] = (binaryCode[i] ^ grayCode[i+1]);
        }
    
    
        //Convert Binary to decimal*****************************************
        //Pretty self explanatory.
        int decimalNumber = 0;
        for (int i = 0; i < 9; i++)
        {
            switch(i)
            {
                case 0: //256
                    if (binaryCode[i] == 1)
                        decimalNumber += 256;
                    break;
                case 1: //128
                    if (binaryCode[i] == 1)
                        decimalNumber += 128;
                    break;
                case 2: //64
                    if (binaryCode[i] == 1)
                        decimalNumber += 64;
                    break;
                case 3: //32
                    if (binaryCode[i] == 1)
                        decimalNumber += 32;
                    break;
                case 4: //16
                    if (binaryCode[i] == 1)
                        decimalNumber += 16;
                    break;
                case 5: //8
                    if (binaryCode[i] == 1)
                        decimalNumber += 8;
                    break;
                case 6: //4
                    if (binaryCode[i] == 1)
                        decimalNumber += 4;
                    break;
                case 7: //2
                    if (binaryCode[i] == 1)
                        decimalNumber += 2;
                    break;
                case 8: //1
                    if (binaryCode[i] == 1)
                        decimalNumber += 1;
                    break;
            }
        }
        
    
    
        //128 64 32 16 8 4 2 1
        //Correct for excess-127********************************************
        decimalNumber -= 127;

    
        //Print the answer as a char (static_cast <char> (ans))*************
        //cout << "Final letter:\n";
        cout << static_cast <char> (decimalNumber);// << endl;
        //Get the next packet.

        //Array index notes
        //Check 7 8 9 10 11 12 for 8
        //Check 3 4 5 6 11 12 for 4
        //Check 1 2 5 6 9 10 for 2
        //Check 0 2 4 6 8 10 12 for 1
        
    }
    cout << endl;
    return 0;
}
