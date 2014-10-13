/*
ID: sai961
LANG: C++
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <sstream>

//Input and Output file names.
const std::string inputFile("ride.in");
const std::string outputFile("ride.out");

//correct and incorrect output strings.
const std::string correct("GO");
const std::string incorrect("STAY");

//Ascii value for A.
const int Aascii = 65;

//The number that is to be used to mod the multiplied value.
const int modNum = 47;

/* A simple program that reads in two words and determines if (assuming A=1... Z=26) when there letters are converted to numbers and then multiplied if they are equivalent when modded by 47.
*/
int main(int argc, char* argv[]){
    //Open the file for reading.
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);

    // Ensure that the file is in working order.
    if(ifs.good()){
        //Read the names.
        std::string commet;
        ifs >> commet;
        std::string group;
        ifs >> group;

        // Determine the commets number.
        int commetNum = 1;
        for(std::string::iterator it = commet.begin(); it != commet.end(); it++){
            commetNum *= (static_cast<int>(*it) - Aascii + 1); // Need to add 1 since we assume A is 1.
        }
        commetNum %= modNum; 

        // Determine the groups number.
        int groupNum = 1;
        for(std::string::iterator it = group.begin(); it != group.end(); it++){
            groupNum *= (static_cast<int>(*it) - Aascii + 1);
        }
        groupNum %= modNum;

        //Construct the output file with the correct output.
        std::ofstream ofs;
        ofs.open(outputFile.c_str());

        if(commetNum == groupNum){
            ofs <<  correct << std::endl;
        } else {
            ofs << incorrect << std::endl;
        }
        
    } else {
        std::cout << "The file " << inputFile << " didn't open" << std::endl;
    }

    ifs.close();

    return 0;
}
