/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: barn1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int stall[200];
int gaps[200];

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int max_boards, num_stalls, num_occupied, i;
    fin >> max_boards >> num_stalls >> num_occupied;
    for(i = 0; i < num_occupied; i++) {
        fin >> stall[i];
    }
    sort(stall, stall+num_occupied);

    for(i = 1; i < num_occupied; i++) {
        gaps[i] = stall[i] - stall[i-1] - 1;
    }
    sort(gaps, gaps+num_occupied);
    int covered = stall[num_occupied - 1] - stall[0] + 1;
    for(i = num_occupied - 1; i >= 0 && max_boards > 1; i--, max_boards--) {
        covered -= gaps[i];
    }
    fout << covered << endl;
    return 0;
}
