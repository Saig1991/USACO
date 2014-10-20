/*
ID: sai961
LANG: C++
PROG: milk2
*/

#include <iostream>
#include <fstream>
#include "milkSchedule.h"

//Creates a schedule from the input.
void createShed(milkSchedule& newShed);
//Create the output file.
void createOutput(int farmingTime, int nonFarmingTime);

// The input and output file names.
const std::string inputFile("milk2.in");
const std::string outputFile("milk2.out");

//Assumes input file doesn't have any errors.
int main(int argc, char* argv[]){
    milkSchedule sched;
    createShed(sched);
    
    std::pair<int,int> prevTime = sched.getNextTime();
    //Used to find the longest farming time.
    int curLongBlock = prevTime.second - prevTime.first;
    int maxLongBlock = curLongBlock;
    //Used to find the longest non-farming time.
    int maxLongNonFarmBlock = 0;

        std::cout << prevTime.first << " " << prevTime.second << std::endl;
    int curLastFarmTime = prevTime.second;// Used to ensure when there's no farming happening.
    for(int i = 0; i < sched.getNumTimes() - 1; i++){
        std::pair<int,int> nextTime = sched.getNextTime();
        std::cout << nextTime.first << " " << nextTime.second << std::endl;
        //The possible cases.
        if(nextTime.second < prevTime.second){ // Don't need to check the front because the list has been sorted.
            std::cout << "1 " << curLongBlock << " " << maxLongBlock << std::endl;
        } else if ( nextTime.first <= curLastFarmTime && nextTime.second > curLastFarmTime){
            curLongBlock += nextTime.second - curLastFarmTime;
            if(curLongBlock > maxLongBlock) maxLongBlock = curLongBlock;
            std::cout << "2 " << curLongBlock << " " << maxLongBlock << std::endl;

        } else if ((nextTime.first <= prevTime.second) && (nextTime.second > prevTime.second)) {
            curLongBlock += nextTime.second - prevTime.second; 
            if(curLongBlock > maxLongBlock){
                maxLongBlock = curLongBlock;
            }
            std::cout << "3 " << curLongBlock << " "  << maxLongBlock << std::endl;

        } else if((nextTime.first > prevTime.second) && (nextTime.second > prevTime.second)){
            curLongBlock = nextTime.second - nextTime.first;
            if(curLongBlock > maxLongBlock){
                maxLongBlock = curLongBlock;    
            }
            std::cout << "4 " << curLongBlock << " " << maxLongBlock << std::endl;
            if((curLastFarmTime < nextTime.second) &&(nextTime.first - prevTime.second > maxLongNonFarmBlock)){
                maxLongNonFarmBlock = nextTime.first - prevTime.second;
            }
        }

        if(nextTime.second > curLastFarmTime) curLastFarmTime = nextTime.second;
        prevTime = nextTime;
    }

    createOutput(maxLongBlock, maxLongNonFarmBlock);

    return 0;
}

//Reads in the input file and makes a milking schedule object.
void createShed(milkSchedule& newSched){
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);

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
        newSched.sortList();
    } else {
        std::cerr << " Error reading input file." << std::endl;
    }
}

void createOutput(int farmingTime, int nonFarmingTime){
    std::ofstream ofs;
    ofs.open(outputFile.c_str(), std::ofstream::out);

    ofs << farmingTime;
    ofs << " ";
    ofs << nonFarmingTime;
    ofs << std::endl;

}
