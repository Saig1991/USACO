/*
ID: sai961
LANG: C++
PROG: milk2
*/

#include <iostream>
#include <fstream>
#include "milkSchedule.h"

//Creates a schedule from the input.
milkSchedule createShed();

// The input and output file names.
const std::string inputFile("milk2.in");
const std::string outputFile("milk2.out");

int main(int argc, char* argv[]){
    milkSchedule sched = createShed();

    return 0;
}

//Reads in the input file and makes a milking schedule object.
milkSchedule createShed(){
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);

    milkSchedule newSched;

    // Ensures that the input file is adequate.
    if(ifs.good()){
        int numFarmers = 0;
        ifs >> numFarmers;
        //Iterate through all the times and add them to the schedule.
        for(int i = 0; i < numFarmers; i++){
            std::pair<int,int> newTime;
            int startTime = 0;
            int endTime = 0;
            ifs >> startTime;
            ifs >> endTime;
            newSched.addTime(startTime,endTime);
        }
    } else {
        std::cerr << " Error reading input file." << std::endl;
    }

    return newSched;
}
