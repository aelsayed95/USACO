/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: wormhole
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
//following USACO tutorial
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_N 12

int X[MAX_N + 1], Y[MAX_N + 1];
int partners[MAX_N + 1], N;
int next_on_right[MAX_N + 1];

bool valid_solution() {
    int start, pos, count;
    for(start = 1; start <= N; start++) {
        pos = start;
        for(count = 0; count < N; count++) {
            pos = partners[next_on_right[pos]];
        }
        if(pos != 0) return true;
    }
    return false;
}

int solutions() {

    int i;
    for(i = 1; i <= N; i++)
        if(partners[i] == 0) break;

    if(i > N) {
        if(valid_solution()) return 1;
        return 0;
    }

    int j, sum = 0;
    for(j = i+1; j <= N; j++) {
        if(partners[j] == 0) {
            partners[i] = j;
            partners[j] = i;
            sum += solutions();
            partners[i] = 0;
            partners[j] = 0;
        }
    }
    return sum;
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    int i, j;
    fin >> N;
    for(i = 1; i <= N; i++) {
        fin >> X[i] >> Y[i];
    }
    fin.close();

    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            if(i == j) continue;
            if((X[j] > X[i] && Y[j] == Y[i]) &&
               (next_on_right[i] == 0 || (X[j] - X[i] < X[next_on_right[i]] - X[i]))) {
                next_on_right[i] = j;
               }
        }
    } 

    fout << solutions() << endl;
    fout.close();
    return 0;
}
