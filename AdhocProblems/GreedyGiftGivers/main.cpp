/*
ID: sai961
LANG: C++
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <map>

const std::string inputFile("gift1.in");
const std::string outputFile("gift1.out");

/*
Solution to the Greedy Gift Givers problem. (An adhoc problem, i.e. it doesn't fit the mold of any generic algorithms e.g. greedy algo)
My algorithm design is specified in algorithm.txt.
*/
int main(int argc, char* argv[]){
    //Open the input file for reading.
    std::ifstream ifs;
    ifs.open(inputFile.c_str(), std::ifstream::in);
    
    if(ifs.good()){
        // Get the number of people in the group.
        int numPeople = 0;
        ifs >> numPeople;
        
        // Construct the map (name to array index);
        std::map<std::string, int> getArrayIndex;
        for(int i = 0; i < numPeople; i++){
            std::string getName;
            ifs >> getName;
            getArrayIndex.insert(std::pair<std::string, int>(getName, i));
        }

        //Arrays to store the initial and final money for each person.
        int initMoney[numPeople];
        int finMoney[numPeople];
        for(int i = 0; i < numPeople; i++){
            initMoney[i] = 0;
            finMoney[i] = 0;
        }
        
        //The outer loop iterates through the names of people giving money.
        std::string getName;
        while(ifs >> getName){
            //Find the starting money for this particular person.
            int startMoney = 0;
            ifs >> startMoney;
            int index = getArrayIndex.find(getName)->second;
            initMoney[index] = startMoney;
            
            //Find the money left over after splitting it out.
            int leftOver = 0;
            int numSplit;
            ifs >> numSplit;
            //Ensure we don't divide by 0.
            if(startMoney != 0 || numSplit != 0){
                leftOver = startMoney % numSplit;
            } else {
                leftOver = startMoney;
            }
            finMoney[index] += leftOver;

            // Find out how much money your giving out to each person and give it to them.
            int distMoney = 0;
            if(numSplit != 0) {
                distMoney = startMoney / numSplit;
            }
            for(int i = 0; i < numSplit; i++){
                std::string name;
                ifs >> name;
                int curIndex = getArrayIndex.find(name)->second;
                finMoney[curIndex] += distMoney;
            }
        }
        std::ofstream ofs;
        ofs.open(outputFile.c_str());

        std::string getOutputOrder[numPeople];

        //Display the output.
        std::map<std::string, int>::const_iterator it = getArrayIndex.begin();
        while(it != getArrayIndex.end()){
            int index = it->second;
          //  ofs << it->first << " " << finMoney[index] - initMoney[index] << std::endl;
            getOutputOrder[index] = it->first;
            it++;
        }

        for(int i = 0; i < numPeople; i++){
            ofs << getOutputOrder[i] << " " << finMoney[i] - initMoney[i] << std::endl;
        }
        ofs.close();

    } else {
        std::cerr << "Input file error." << std::endl;
    }

    ifs.close();

    return 0;
}
