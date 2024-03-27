//Liv Young HW 3 part 1
//TimeCode.cpp

#include "TimeCode.h"
#include <iostream>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

//-----------------------------------
TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec)
//-----------------------------------
{
    t = ComponentsToSeconds(hr, min, sec);
}

//-----------------------------------
TimeCode::TimeCode(const TimeCode& tc)
//-----------------------------------
{
    t = tc.t;
}

//-----------------------------------
void TimeCode::SetHours(unsigned int hours)
//-----------------------------------
{
    unsigned int hr, min, sec; 
    GetComponents(hr, min, sec);
    hr = hours;
    t = ComponentsToSeconds(hr, min, sec);
}


//-----------------------------------
void TimeCode::SetMinutes(unsigned int minutes)
//-----------------------------------
{
    if(minutes > 59){
        throw invalid_argument("There are only 60 minutes in an hour.");
    }
    unsigned int hr, min, sec; 
    GetComponents(hr, min, sec);
    min = minutes;
    t = ComponentsToSeconds(hr, min, sec);
}

//-----------------------------------
void TimeCode::SetSeconds(unsigned int seconds)
//-----------------------------------
{
    if(seconds > 59){
        throw invalid_argument("There are only 60 seconds in an minute.");
    }
    unsigned int hr, min, sec; 
    GetComponents(hr, min, sec);
    sec = seconds;
    t = ComponentsToSeconds(hr, min, sec);
}
//-----------------------------------
void TimeCode::reset()
//-----------------------------------
{
    t = 0;
}

//-----------------------------------
unsigned int TimeCode::GetHours() const
//-----------------------------------
{
    unsigned int hr, min, sec;
    GetComponents(hr, min, sec);

    return hr;
}

//-----------------------------------
unsigned int TimeCode::GetMinutes() const
//-----------------------------------
{
    unsigned int hr, min, sec;
    GetComponents(hr, min, sec);

    return min;
}

//-----------------------------------      
unsigned int TimeCode::GetSeconds() const
//-----------------------------------
{
    unsigned int hr, min, sec;
    GetComponents(hr, min, sec);

    return sec;
}

//-----------------------------------
void TimeCode::GetComponents(unsigned int& hr, 
                             unsigned int& min, 
                             unsigned int& sec) const
//-----------------------------------
{
    hr = t / 3600;
    min = (t/60) % 60;
    sec = t % 60;
}

//-----------------------------------
long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, 
                                                     unsigned int min, 
                                                     unsigned long long int sec)
//-----------------------------------                                               
{
    return (hr*3600) + (min*60) + sec;
}

//-----------------------------------
string TimeCode::ToString() const
//-----------------------------------
{ 
    unsigned int hr, min, sec;
    string s;
    GetComponents(hr, min, sec);
    s.append(to_string(hr));
    s.append(":");
    s.append(to_string(min));
    s.append(":");
    s.append(to_string(sec));

    return s;
}

//-----------------------------------
TimeCode TimeCode::operator+(const TimeCode& other) const
//-----------------------------------
{
    int sum = this->GetTimeCodeAsSeconds() + other.GetTimeCodeAsSeconds();
    return TimeCode(0,0,sum);
}

//-----------------------------------
TimeCode TimeCode::operator-(const TimeCode& other) const
//-----------------------------------
{
    int diff = this->GetTimeCodeAsSeconds() - other.GetTimeCodeAsSeconds();
    if(diff < 0){
        throw invalid_argument("Negative arguments not allowed: " + to_string(diff));
    }
    return TimeCode(0,0,diff);
}
        
//-----------------------------------  
TimeCode TimeCode::operator*(double a) const
//-----------------------------------
{
    int product = this->GetTimeCodeAsSeconds() * a;
    return TimeCode(0,0,product);
}

//-----------------------------------
TimeCode TimeCode::operator/(double a) const
//-----------------------------------
{

    if(a == 0){
        throw invalid_argument("You can't divide by zero.");
    }
    int quotient = this->GetTimeCodeAsSeconds() / a;
    return TimeCode(0,0,quotient);
}

//-----------------------------------
bool TimeCode::operator == (const TimeCode& other) const
//-----------------------------------
{
    bool equals = false;
    if(this->GetTimeCodeAsSeconds() == other.GetTimeCodeAsSeconds()){
        equals = true;
    }
    return equals;
}

//-----------------------------------
bool TimeCode::operator != (const TimeCode& other) const
//-----------------------------------
{
    bool notEqual = true;
    if(this->GetTimeCodeAsSeconds() == other.GetTimeCodeAsSeconds()){
        notEqual = false;
    }
    return notEqual;
}

//-----------------------------------
bool TimeCode::operator < (const TimeCode& other) const
//-----------------------------------
{
    bool lessThan = false;
    if(this->GetTimeCodeAsSeconds() < other.GetTimeCodeAsSeconds()){
        lessThan = true;
    }
    return lessThan;
}

bool TimeCode::operator <= (const TimeCode& other) const
{
    bool lessThanOrEqual = false;
    if(this->GetTimeCodeAsSeconds() <= other.GetTimeCodeAsSeconds()){
        lessThanOrEqual = true;
    }
    return lessThanOrEqual;
}

bool TimeCode::operator > (const TimeCode& other) const
{
    bool greaterThan = false;
    if(this->GetTimeCodeAsSeconds() > other.GetTimeCodeAsSeconds()){
        greaterThan = true;
    }
    return greaterThan;
}

bool TimeCode::operator >= (const TimeCode& other) const
{
    bool greaterThanOrEqual = false;
    if(this->GetTimeCodeAsSeconds() >= other.GetTimeCodeAsSeconds()){
        greaterThanOrEqual = true;
    }
    return greaterThanOrEqual;
}