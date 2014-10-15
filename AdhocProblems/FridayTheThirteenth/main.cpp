/*
ID: sai961
LANG: C++
PROG: friday
*/

#include <iostream>
#include <fstream>

//Returns the value of N by reading in the input file.
int getN();

// The files to work with.
const std::string inputFile("friday.in");
const std::string outputFile("friday.out");

//The number of days in relavent time frames.
const int numWeekDays = 7;
const int numNonLeap = 365;
const int numLeap = 366;



/*
A program that solves the friday the thirteenth problem, specified in problem.txt
*/
int main(int argc, char* argv[]){
    int N = getN();




    return 0;
}

//Returns the value of N by reading in the input file.
int getN(){
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);
    int N = 0;

    // Ensure that the file is readable.
    if(ifs.good()){
        ifs >> N;
    } else {
        std::cerr << "File was not readable" << std::endl;
    }

    ifs.close();

    return N;
}
