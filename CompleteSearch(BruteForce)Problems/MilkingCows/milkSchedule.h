#ifndef MILKSCHEDULE
#define MILKSCHEDULE

#include <utility>
#include <list>

/*
A class designed for the construction of a milking schedule
Essentially a number of farmers are designated a time period of which they have to milk their respective cows.
*/
class milkSchedule {
public:
    //Constructor.
    milkSchedule();
    //Add a new time to the schedule.
    void addTime(int startTime, int endTime); 
    //Returns the number of entries in the schedule.
    int getNumTimes();
    //Returns the times in order. i.e. every time you call this function you get the next time.
    std::pair<int,int> getNextTime();
    //Resets the schedule so that getNextTime() will return the first time.
    void resetSchedule();
    //Sort the list so that the input is ordered.
    void sortList();
    //A comparator function required for sorting the input.
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right);
private:
    //Store the entries in a list, 
    std::list<std::pair<int,int> > schedule;
    //Iterator for returning the next time.
    std::list<std::pair<int,int> >::const_iterator nextTime;
};

#endif 
