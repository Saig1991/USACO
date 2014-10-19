#include "milkSchedule.h"

/*
Initialises the scheduling iterator.
*/
milkSchedule::milkSchedule(){
    this->nextTime = schedule.cbegin();
}

/*
Adds a new time pair to the list.
*/
void milkSchedule::addTime(int startTime, int endTime){
    std::pair<int,int> time = std::make_pair(startTime, endTime);
    this->schedule.push_back(time);
}
/*
Returns the size of the list(schedule).
*/
int milkSchedule::getNumTimes(){
    return this->schedule.size();
}

/*
Returns the next pair of times in the list, increments the iterator to the next pair of times
*/
std::pair<int,int> milkSchedule::getNextTime(){
    std::pair<int,int> retVal = *nextTime;
    nextTime++;
    return retVal;
}

/*
Resets the iterator, effectively reseting the schedule.
*/
void milkSchedule::resetSchedule(){
    nextTime = schedule.cbegin();
}
