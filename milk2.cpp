/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct interval_t {
    int b;
    int e;
    bool operator<(const interval_t& rhs) const { return b < rhs.b; }
} intervals[5000];

bool in_range(int time, int begin, int end) {
    return (time >= begin && time <= end);
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n, i, max_milking = 0, max_idle = 0;
    fin >> n;
    for(i = 0; i < n; i++) {
        fin >> intervals[i].b >> intervals[i].e;
    }

    //sort by beginning intervals
    sort(intervals, intervals+n);

    int round_b, round_e, j;
    for(i = 0; i < n; i++) {
        round_b = intervals[i].b;
        round_e = intervals[i].e;

        for(j = i+1; j < n; j++){
            if(in_range(intervals[j].b, round_b, round_e)) {
                round_e = intervals[j].e > round_e ? intervals[j].e : round_e;
            }
            else {
                max_idle = (intervals[j].b - round_e) > max_idle ?
                            (intervals[j].b - round_e) : max_idle;
                break;
            }
        }
        //skip ahead to after this interval
        i = j - 1;
        max_milking = (round_e - round_b) > max_milking ? (round_e - round_b) : max_milking; 
    }
    fout << max_milking << " " << max_idle << endl;
    return 0;
}
