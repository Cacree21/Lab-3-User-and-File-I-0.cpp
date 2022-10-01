/*
Caleb Acree
C++ Fall 2022
Due: September 28, 2022
Lab 3 Exploring Output
 Write an interactive C++ program that computes and outputs the mean and
 population standard deviation of a set of four integers that are inputted by a file called
 “inMeanStd.dat” and the user (should handle both). Although the individual values are
 integers, the results are floating-point values. Be sure to use proper formatting and
 appropriate comments in your code. Provide appropriate prompts to the user. The
 output should be to the screen for the user inputted values and to a file called
 “outMeanStd.dat”. The programs output should be labeled clearly and formatted
 neatly. You must calculate the mean and standard deviation in separate functions.
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Input from files

string inputfilename="inMeanStd.dat";
string outfilename="outMeanStd.dat";

int a;
int b;
int c;
int d;
float mean;
float population;

std::ifstream infile;
std::ofstream outfile;

void calculations();
void fileCalculations();
void userInput();
void fileInput();

int main()
{
    userInput();
    calculations();
    fileInput();
    fileCalculations();
    
    outfile.close();
    infile.close();
    return 0;
    
}

//UserInput
void userInput()
{
   cout << "Please type the value:\n";
    cin >> a;
    cout << "Please type the value:\n";
    cin >> b;
    cout << "Please type the value:\n";
    cin >> c;
    cout << "Please type the value:\n";
    cin >> d;
    
    cout << "The values you entered were: " << a << " " << b << " " << c << " " << d << endl;
}

void meanCalc()
{
    mean = float(a + b + c + d) / 4.0;
}

void popSDCalc()
{
    population = sqrt((pow((a - mean), 2) + pow((b - mean), 2) + pow ((c - mean), 2) + pow ((d - mean), 2)) /4);
}

void calculations()
{
    meanCalc();
    cout << "The mean is: " << mean;
    popSDCalc();
    cout << endl << "The population standard deviation is: " << population;
}

void fileInput()
{
    infile.open(inputfilename);
    
    if (!infile)
        cout << "Can't find file!\n";
        
        infile >> a >> b >> c >> d;
    outfile.open(outfilename);
}

void fileCalculations()
{
    meanCalc();
    outfile << "The mean is: " << mean << endl;
    
    popSDCalc();
    outfile << "The population standard deviation is: " << population;
}
