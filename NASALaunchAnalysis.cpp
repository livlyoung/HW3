//NASALaunchAnalysis.cpp
//Homework 3 part 2
//Liv Young 

#include <vector>
#include <iostream> 
#include <string> 
#include <cassert> 
#include "TimeCode.h"
#include <fstream>


TimeCode parse_line(string s){
    
    TimeCode tc;

    for(size_t i = 0; i < s.size(); i++){
        if(s.at(i) == 'U' && s.at(i+1) == 'T' && s.at(i+2) == 'C' ){
            string hoursStr;
            hoursStr.push_back(s.at(i-6));
            hoursStr.push_back(s.at(i-5));
            unsigned int hours = stoi(hoursStr);

            string minutesStr;
            minutesStr.push_back(s.at(i-3));
            minutesStr.push_back(s.at(i-2));
            unsigned int minutes = stoi(minutesStr);

            tc = TimeCode(hours, minutes, 0); 
        }
    }
    
    return tc;
}


int main(){
    //get one line then discard
    ifstream nasaData;
    string currLine;
    nasaData.open("Space_Corrected.csv");
    if (!nasaData.is_open()) {
      cout << "Could not open file Space_Corrected.csv" << endl;
      return 1;
    }

    getline(nasaData, currLine); //to skip over first line of categories
    TimeCode currSum(0,0,0);
    int numDataPoints = 0;
    
    while (!nasaData.fail()){
        getline(nasaData, currLine);
        parse_line(currLine);
        currSum = currSum + parse_line(currLine);
        //<<currSum.ToString()<<endl;
        bool found = currLine.find("UTC") != std::string::npos;  
        if(found){
            numDataPoints += 1; //to find how many data points there are to get average
        }
                  
    }
    TimeCode average = currSum/numDataPoints;
    cout<<numDataPoints<<" data points."<<endl;
    cout<< "Average: " << average.ToString() << endl;

    nasaData.close();

}