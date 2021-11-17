#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

bool isNight(string daynight) {
    if(daynight[0] == 'P' && daynight[1] == 'M') {
        return true;
    }
    return false;
}

int parseHour(string s) {
    string hour = "";
    hour = s.substr(0, 2);
        
    int hourInt = stoi(hour);
    return hourInt;
}

string intToString(int hour, bool isNight) {
    if(!isNight && hour == 12) {
        return "00";
    }
    
    if(hour >= 10) {
        string hourString = to_string(hour);
        return hourString;
    }
    
    string hourString = to_string(hour);
    return "0"+hourString;
    
}

string convertTime(string hour, string s) {
     s = hour += s.substr(2);
     return s;
}

string timeConversion(string s) {
    string tmp = s.substr(8, 10);
    bool flag = isNight(tmp);
    
    if(flag) {
        int hourInt = parseHour(s);
        if(hourInt != 12) {
             hourInt+=12;
        
            string hourString = intToString(hourInt, flag);
            s = convertTime(hourString, s);
        }
    } else {
        int hourInt = parseHour(s);
        
        string hourString = intToString(hourInt, flag);
        s = convertTime(hourString, s);
    }

    return s.substr(0, 8);
}

int main() {
    cout << timeConversion("12:45:54PM");
}