#include "milkSchedule.h"

/*
Initialises the scheduling iterator.
*/
milkSchedule::milkSchedule(){
    this->nextTime = this->schedule.begin();
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
    nextTime++;
    if(nextTime == this->schedule.end()){
        nextTime = this->schedule.begin();
    }
    std::pair<int,int> retVal = *nextTime;
    return retVal;
}

/*
Resets the iterator, effectively reseting the schedule.
*/
void milkSchedule::resetSchedule(){
    nextTime = schedule.begin();
}

//Comparison function that checks if the first pairs first element is less than that of the second. Used for sorting the input.
bool milkSchedule::operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
            return left.first < right.first;
}

//Sort the input based of if the first value of the pair.
void milkSchedule::sortList(){
    this->schedule.sort(*this);
}
