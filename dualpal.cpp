/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: dualpal
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, s, base;
    fin >> n >> s;
    while(n) {
        s++;
        int pcount = 0;
        if(is_palindrome(to_string(s))) pcount++;
        for(base = 2; base < 10 && pcount < 2; base++) {
            string translate = base_b(s, base);
            if(is_palindrome(translate)) {
                pcount++;
            }
        }
        if(pcount == 2) {
            fout << s << endl;
            n--;
        }
    }
    return 0;
}
