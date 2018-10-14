/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: combo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int john[3];
int mast[3];

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    fin >> n;
    fin >> john[0] >> john[1] >> john[2];
    fin >> mast[0] >> mast[1] >> mast[2];

    if(n <= 5) {
        fout << to_string((int)pow(n,3)) << endl;
    } else {
        //5 x 5 x 5 = 125 possibilites per lock
        //subtract intersection between locks
        int inter[3] = {0, 0, 0};
        int i, j, k, jdigit, mdigit;
        for(i = 0; i < 3; i++) {
            for(j = -2; j <= 2; j++) {
                for ( k = -2; k <= 2; k++) {
                    jdigit = (john[i] + j) % n;
                    if(jdigit < 0) jdigit += n;
                    mdigit = (mast[i] + k) % n;
                    if(mdigit < 0) mdigit += n;
                    inter[i] += (jdigit == mdigit);
                }
            }
        }
        int result = 250 - (inter[0] * inter[1] * inter[2]);
        fout << result << endl;
    }
    return 0;
}
