/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string valid_names[5000];

int num_digits(long long int n) {
    int count = 0;
    while(n) {
        count++;
        n = n/10;
    }
    return count;
}

int letter_to_num(char letter) {
    if( letter > 'Q') letter--;
    int res = (letter - 'A')/3 + 2;
    return res;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    ifstream din ("dict.txt");

    long long int n;
    fin >> n;

    int valid_count = 0;
    while(din>>valid_names[valid_count++]);

    int i, j, num_len;
    long long int code;
    bool found = false;

    num_len = num_digits(n);

    for(i = 0; i < valid_count; i++) {
        if(valid_names[i].size() != num_len) continue;
        code = 0;
        for(j = 0; j < valid_names[i].size(); j++) {
            code += (long long int) letter_to_num(valid_names[i][j]) *
                    (long long int) pow(10, valid_names[i].size() - j - 1);
        }
        if(code == n) {
            fout << valid_names[i] << endl;
            found = true;
        }
    }
    if(!found) fout << "NONE" << endl;
    return 0;
}
