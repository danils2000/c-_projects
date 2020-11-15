#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Time.h"  

using namespace std;

class Day {
public:
    Day();
    bool from_str(const string &s);
    string to_str();
    void dst(int offset);
private:
    int day;
    string month;
    vector<Time> list;
};

int main()
{
    ifstream inputFile("calendar.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line)) {
        if (day.from_str(line)) {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal) {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}

Day::Day() : day(0), month("undefined")
{
}

bool Day::from_str(const string& s)
{
    string montemp;
    string temp;
    int daytemp;
    Time timetemp;
 
    *this = Day(); // Clear the object

    istringstream stringInput(s);

    // Read day and month
    if (stringInput >> daytemp >> montemp) {
        day = daytemp;
        month = montemp;
    }
    else {
        return false;
    }

    // Read times
    while (stringInput >> temp) {
        istringstream tempInput(temp);
        if (tempInput >> timetemp) {
            list.push_back(timetemp);
        }
    }
    if (list.size() == 0) {
        return false;
    }

    sort(list.begin(), list.end());

    return true;
}

string Day::to_str() 
{
    ostringstream eventOut;

    eventOut << to_string(day) << " " << month;

    // Convert vector to string
    for (auto& element : list) {
        eventOut << ' ' << element;
    }

    return eventOut.str();
}

void Day::dst(int offset) 
{
    if (offset < 0) offset += 24; // In case offset is given as negative number
    Time additional(offset);

    for (auto& element : list) {
        element = element + additional;
    }
}