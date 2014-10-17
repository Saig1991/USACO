/*
ID: sai961
LANG: C++
PROG: beads
*/

#include <iostream>
#include <fstream>

//Function declarations.
//Get the input from the file.
void getInput(int &numBeads, std::string &beadsString);
//Turns the input string into a necklace
void stringToNecklace(std::string &beadsString);
//Create the Output
void createOutput(int maxChar);

//input and output filenames.
const std::string inputFile("beads.in");
const std::string outputFile("beads.out");

//bead colour
const char read = 'r';
const char blue = 'b';
const char white = 'w';

int main(int argc, char* argv[]){
    int numBeads = 0;
    std::string beadsString;
    getInput(numBeads,beadsString);
    stringToNecklace(beadsString);

    std::string::iterator it = beadsString.begin();
    int curCount = 1; // Starts at 1 because we start at the second bead. 
    char prevBead = *it;
    it++;
    while((it != beadsString.end()) && (prevBead == white)){
        prevBead = *it;
        curCount++;
        it++;
    }

    int maxCount = 0;
    bool secondHalf = false; // Specifies if we're checking the second half of the necklace.
    std::string::iterator secondHalfIt;
    while(it != beadsString.end()){
        if(*it == white || *it == prevBead){
            curCount++;
        } else if (secondHalf == false){
            prevBead = *it;
            curCount++;
            secondHalfIt = it;
            //Ensure that there's no whites before the break.
            if(secondHalfIt != beadsString.begin()){
                secondHalfIt--;
                if(*secondHalfIt == white){
                    while(*secondHalfIt == white) secondHalfIt--;
                } 
                //It goes back one further than all whites
                secondHalfIt++;
            }
            secondHalf = true;
        } else if (secondHalf == true) {
            if(curCount > maxCount){
                maxCount = curCount;
            } 
            secondHalf = false;
            curCount = 1;
            it = secondHalfIt;
        }
        it++;
    }
    //If there's only one colour throughout the necklace.
    if(maxCount == 0){
        maxCount = curCount/2;
    }else if(curCount > maxCount){
        maxCount = curCount;
    }
    
    createOutput(maxCount);
    return 0;
}

//Read in input and store in the relevant variables.
void getInput(int &numBeads, std::string &beadsString){
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);

    //ensure that the file is in working order.
    if(ifs.good()){
        ifs >> numBeads;
        ifs >> beadsString;

    } else {
        std::cerr << "Input file error" << std::endl;
    }


}

//Adds the first same coloured block to the end of the string to make it a necklace.
void stringToNecklace(std::string &beadsString){
    std::string::iterator it = beadsString.begin();
    char prevBead = *it;
    it++;
    //Add first same coloured chain to the back of the main string (because it's a necklace).
    int numChars = 0;
    while(prevBead == white){
        prevBead = *it;
        it++;
    }
    while(*it == white || *it == prevBead){
        it++;
    }
    numChars = it - beadsString.begin();
    beadsString.insert(beadsString.size(), beadsString.substr(0, numChars));
}

void createOutput(int maxChar){
    std::ofstream ofs(outputFile.c_str(), std::ofstream::out);
    ofs << maxChar << std::endl;
}
