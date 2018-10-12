/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int num_day[12] = {31, 28, 31, 30,
                   31, 30, 31, 31,
                   30, 31, 30, 31};
int START_YEAR = 1900;

bool is_leap(int year) {
    if( year % 100 == 0 ){
        return (year % 400 == 0);
    }
    return (year % 4 == 0);
}

int num_days(int month, int year) {
    if(month == 1) { // feb
        if(is_leap(year)) {
            return 29;
        }
    }
    return num_day[month];
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int n;
    fin >> n;

    int day, month, year;
    int total_day_idx = 2; //start on a monday
    int count13[7] = {0, 0, 0, 0, 0, 0, 0};

    for(year = START_YEAR; year < START_YEAR + n; year++) {
        for(month = 0; month < 12; month++) {
            for(day = 1; day <= num_days(month, year); day++) {
                if(day == 13) {
                    count13[total_day_idx % 7]++;
                }
                total_day_idx++;
            }
        } 
    }
    for(day = 0; day < 6; day++) {
        fout << count13[day] << " ";
    }
    fout << count13[day] << endl;
    return 0;
}
