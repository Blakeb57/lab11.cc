/*
*   @file: lab11.cc
*  
* @author: Blake Boehringer
*
*   @date: 11-07-19
*
*  @brief: A program reads through a file called text.txt character by character to convert lowercase characters to uppercase characters and to also convert digits into asterisks and outputs the changes into a file called output.txt
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;


void getlines(ifstream &inStream, ofstream &outStream);

int main(int argc, char const *argv[]) {

    ifstream inStream;   //creates variable inStream
    ofstream outStream;  //creates variable outStream
    inStream.open("text.txt"); //opens the file text.txt
    outStream.open("output.txt"); //opens the output file output.txt

    if(inStream.fail() || outStream.fail()){  //this function tests if opening inStream and/or outStream fails
        cout << "File Failure, one of the files couldn't open" << endl; //tells the user if either file failed
        exit(0); // exits the program if failed
    }

    getlines(inStream, outStream); // calls the function getlines into main

}


void getlines(ifstream &inStream, ofstream &outStream){ // function get line changes lowcased characters to uppercase and converts numbers into asterisks

    char name;

    inStream.get(name);// gets the characters from ther text.txt file to go into the output.txt file
    while(!inStream.eof()){ // while not at the end of the file the function will continue through the loop

            if(islower(name)){ // checks if character is lower case
                name = toupper(name); //if character fpound to be lowercase gets converted top uppercase

            }

            if(isdigit(name)){ //checks if character is found to be a digit
                name = '*'; //if character is found to be a digit it will be converted into an asterisk
            }

        outStream.put(name); // this outstreams the changes made from the text.txt file to the output.txt fil
        inStream.get(name); // gets the characters from ther text.txt file to go into the output.txt file

    }

}
