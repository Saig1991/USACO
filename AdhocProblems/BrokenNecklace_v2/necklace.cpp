#include "necklace.h"

//Constructs a new necklace object defined by the input string.
necklace::necklace(std::string beadsString){
    this->beadsString = beadsString;
}

/*
Given a position this function returns the number of contiguous same-coloured beads at the break.
The number of contiguous same-coloured beads goes both ways from the break and is inclusive of whites.
If more clarification is needed on the same-coloured beads condition read problem.txt
if position = 1, then you break before the 1st element.
*/
int necklace::numBeadsAtBreak(int position){
    std::string::iterator it = this->beadsString.begin();
    int numBeads = 0;

    //Ensures the input is correct.i.e. you can't break the necklace at position that doesn't exist.
    if(position <= static_cast<int>(beadsString.size())){
        //iterate to the position of the break.
        for(int i = 1; i < position; i++){
            it++;
        }

        //Need to start one behind for backwards.
        std::string::iterator backwardsIt = it;
        if(backwardsIt != beadsString.begin()){
            backwardsIt--;
        } else {
            backwardsIt = beadsString.end();
            backwardsIt--;
        }
        //Utiliy functions that determine the number of continuous beads in both directions.
        numBeads += numBeadsBackward(backwardsIt);
        numBeads += numBeadsForward(it, numBeads);


    } 

    return numBeads;
}

// Iterates forwards from the given position and counts the number of same coloured beads.
// If the end is reached, it will cycle around to the start and continue.
int necklace::numBeadsForward(std::string::iterator forwardIt, int numBackwardBeads){
    char prevBead = nonBead;
    int  beadCount = 0;

    //Finds the point where the backwards beads ends. So if you cross this whilst going forward you're overlapping.
    std::string::iterator backwardsEndPoint = forwardIt;
    for(int i = 0; i < numBackwardBeads; i++){
        if(backwardsEndPoint == this->beadsString.begin()){
            backwardsEndPoint = this->beadsString.end();
        }
        backwardsEndPoint--;
    }

    
    do
    {
        if(prevBead == nonBead || prevBead == white) {
            prevBead = *forwardIt;
        }

        beadCount++;
        forwardIt++;

        if(forwardIt == this->beadsString.end()){
            forwardIt = this->beadsString.begin();
        }

        //std::cout << "in forward loop " <<  forwardIt - beadsString.begin() << " " << *forwardIt << " " << prevBead << std::endl;
    }
    //If forwardIT = backwardsEndPoint that means it's on the verge of crossing it.
    while(((*forwardIt == prevBead) || (*forwardIt == white) || (prevBead == white)) && (forwardIt != backwardsEndPoint));
    //std::cout << "exiting forward code " <<  beadCount<< " " <<  numBackwardBeads << std::endl;

    return beadCount;
}

// Iterates backwards from the given position and counts the number of same coloured beads.
// If the start is reached, it will cycle around to the end and continue.
int necklace::numBeadsBackward(std::string::iterator backwardIt){
    char prevBead = nonBead;
    int  beadCount = 0;

    //Count the number of contiguous beads going backwards at the break.
    do
    {
        if(backwardIt == this->beadsString.begin()){
            backwardIt = this->beadsString.end();
            backwardIt--;
        }
        if(prevBead == nonBead || prevBead == white) {
            prevBead = *backwardIt;
        }
        beadCount++;
        backwardIt--;
    }
    while((*backwardIt == prevBead) || (*backwardIt == white) || (prevBead == white));
    //std::cout << "exiting backward code " <<  beadCount<<  std::endl;
        
    return beadCount;
}

/*
This function returns the maximum number of contiguous beads possible for this necklace.
*/
int necklace::maxNumBeadsAtBreak(){
    int maxBeads = 0;
    for(int i = 1; i < static_cast<int>(this->beadsString.size() + 1); i++){
        int curNumBeads = numBeadsAtBreak(i);
        //std::cout << "max num beads fn " <<  i << " " << curNumBeads << std::endl;
        if( maxBeads < curNumBeads){
            maxBeads = curNumBeads;
        }
    }

    return maxBeads;
}
