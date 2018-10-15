/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: numtri
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int r;
int board[1000][1000];
int calc[1000][1000];

int max_sum(int i, int j) {
    if(i == r) {
        return 0;
    }
    if(calc[i][j] != -1) return calc[i][j];
    int right = max_sum(i+1, j);
    int left = max_sum(i+1, j+1);
    return calc[i][j] = board[i][j] + max(right, left);
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    
    fin >> r;
    int i, j;
    for(i = 0; i < r; i++) {
        for(j = 0; j < i + 1; j++) {
            fin >> board[i][j];
            calc[i][j] = -1;
        }
    }
    fin.close(); 
    fout << max_sum(0,0) << endl;
    fout.close();
    return 0;
}
