#ifndef MILKSCHEDULE
#define MILKSCHEDULE

#include <utility>
#include <forward_list>

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
private:
    //Need a size variable, since the forward list doesn't provide this option.
    int listSize;
    //Store the entries in a forward_list, 
    std::forward_list<std::pair<int,int> > schedule;
    //Iterator for returning the next time.
    std::forward_list<std::pair<int,int> >::const_iterator next_time;
};

#endif 
