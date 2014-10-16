/*
ID: sai961
LANG: C++
PROG: friday
*/

#include <iostream>
#include <fstream>

/*
List of Utility functions.
*/
//Gets the number of years required to be checked.
int getN();
// Gets the start date.
void getInitialDate(int &curDay, int &curMonth, int &curYear, char* argv[]);

// The files to work with.
const std::string inputFile("friday.in");
const std::string outputFile("friday.out");

//The day of the month to check for.
const int checkDay = 13;

//The number of days in relavent time frames.
const int numWeekDays = 7;
const int numNonLeap = 365;
const int numLeap = 366;
const int longMonth = 31;
const int shortMonth = 30;
const int febNonLeap = 28;
const int febLeap = 29;

//Month names.
const int jan = 1;
const int feb = 2;
const int mar = 3;
const int apr = 4;
const int may = 5;
const int jun = 6;
const int jul = 7;
const int aug = 8;
const int sep = 9;
const int oct = 10;
const int nov = 11;
const int dec = 12;



/*
A program that solves the friday the thirteenth problem, specified in problem.txt
*/
int main(int argc, char* argv[]){
    int N = getN();
    // Intial date starts at 1/1/1900.
    int curYear = 0;
    int curMonth = 0;
    int curDay = 0;
    int initialYear = 0; // Required to know when to stop iterating.
    getInitialDate(curDay, curMonth, curYear, argv);
    initialYear = curYear;

    //Array that stores the frequencies of which days land on the 13th of a month.
    int frequency[numWeekDays];
    for(int i = 0; i < numWeekDays; i++){
        frequency[i] = 0;
    }
    int dayFreqIndex = 0; // frequency array is mon -> sun (i.e. 0 represents monday)
    int numDaysInMonth = 31;
    
    //Need to iterate until 31/12/(1900 + N - 1)
    while(curYear != (initialYear + N)){
        if(curDay == checkDay){
            frequency[dayFreqIndex]++;
        }


        //Increment day based of what month it is.
        if(curDay == 1){ // Put this in so the switch doesn't happen every iteration (just prevents redundancy).
            //Rules of incrementing the date.
            switch(curMonth){
                case feb:
                    numDaysInMonth = 28;
                    //Check for leap year.
                    if((curYear%4 == 0)){
                        if((curYear%400 == 0) || (curYear%100 != 0)){
                            numDaysInMonth = 29;
                        }
                    }
                    break;
                case apr:
                    numDaysInMonth = 30;
                    break;
                case jun:
                    numDaysInMonth = 30;
                    break;
                case sep:
                    numDaysInMonth = 30;
                    break;
                case nov:
                    numDaysInMonth = 30;
                    break;
                default:
                    numDaysInMonth = 31;
            }
        }
        curDay++;
        dayFreqIndex = (dayFreqIndex + 1)%numWeekDays;
        
        //This part does the incrementing of the date.
        if(curDay == numDaysInMonth + 1){
            curDay = 1;
            curMonth++;
            if(curMonth == dec + 1){
                curYear++;
                curMonth  = jan;
            }
        }
    }

    std::ofstream ofs(outputFile.c_str(), std::ofstream::out);

    //Print the output.
    //output starts from saturday.
    ofs << frequency[5] << " ";
    ofs << frequency[6] << " ";
    for(int i = 0; i < numWeekDays - 2; i++){
        if(i != numWeekDays - 3){
            ofs << frequency[i] << " ";
        }else {
            ofs << frequency[i];
        }
    }
    ofs << std::endl;

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

/*
 A Function that initialises the first date.
Function can be updated to allow for intiial date to come from the command line.
*/
void getInitialDate(int &curDay, int &curMonth, int &curYear, char* argv[]){
    curYear = 1900;
    curMonth = 1;
    curDay = 1;

}
