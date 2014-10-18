#ifndef NECKLACE
#define NECKLACE

#include <iostream>

class necklace{
public:
    //Construct a necklace object with the string as input.
    necklace(std::string beadsString);
    //Finds the number of same coloured beads in both directions at the break 
    int numBeadsAtBreak(int position);
    //Finds the max number of same coloured beads by breaking the necklace at any point.
    int maxNumBeadsAtBreak();
private:
    static const char white = 'w';
    static const char red = 'r';
    static const char blue = 'b';
    static const char nonBead = 'a';

    //The main string that contains the necklact.
    std::string beadsString;

    /* Utility Functions */
    //Utility function that finds the number of continuous same coloured beads in the backwards direction from the given iterator.
    int numBeadsBackward(std::string::iterator backwardIt);
    //Utility function that finds the number of continuous same coloured beads in the forwards direction from the given iterator.
    //Takes in a second parameter to prevent overlap of beads with the backwards function.
    //The code assumes you do the backwards one first.
    int numBeadsForward(std::string::iterator  forwardIt, int numBackwardBeads);
};
#endif
