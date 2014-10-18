/*
ID: sai961
LANG: C++
PROG: beads
*/
#include <iostream>
#include <fstream>
#include "necklace.h"

//Input and Output file names.
const std::string inputFile("beads.in");
const std::string outputFile("beads.out");

int main(int argc, char *argv[]){
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);

    //Ensure that the file opens correctly.
    if(ifs.good()){
        std::string beadsString;
        int numBeads;
        ifs >> numBeads;
        ifs >> beadsString;

        necklace newNecklace(beadsString);
        int maxBeads = newNecklace.maxNumBeadsAtBreak();
        std::cout << maxBeads << std::endl;

        std::ofstream ofs(outputFile.c_str());
        ofs << maxBeads << std::endl;


    } else {
        std::cerr << " Error opening file." << std::endl;
    }
    return 0;
}
