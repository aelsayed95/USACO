/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

bool is_palindrome(string s) {
    int i, j;
    for(i = 0, j = s.size() - 1; i < j; i++, j--) {
        if(s[i] != s[j]) return false;
    }
    return true;
}
string alpha_to_string(int n) {
    if(n < 10) return to_string(n);
    else {
        char alpha = 'A' + n - 10;
        string ret(1, alpha);
        return ret;
    }
}
string base_b(int n, int base) {
    if(base == 10) return to_string(n);
    string ret = "";
    while(n > 0) {
        ret = alpha_to_string(n%base) + ret;
        n = n / base;
    }
    return ret;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int base, s;
    fin >> base;

    int n;
    for(n = 1; n <= 300; n++) {
        string square = base_b(n*n, base);
        if(is_palindrome(square)) {
            fout << base_b(n, base) << " " << square << endl;
        }
    }
    return 0;
}
