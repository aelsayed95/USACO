/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: sprime
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

ofstream fout ("sprime.out");

int n;
int single_digits[4] = {2,3,5,7};

bool is_prime(int num, int digit) {
    int i;
    int new_num = num*10+digit;
    for(i = 2 ; i*i <= new_num; i++) {
        if(new_num % i == 0) return false;
    }
    return true;
}

void create_num(int digit, int num) {
    if(digit == n) {
        fout << num << endl;
        return;
    }
    int i;
    if(digit == 0) {
        for(i = 0; i < 4; i++) {
            create_num(1, single_digits[i]);
        }
    } else {
        for(i = 1; i <= 9; i+=2) {
            if(is_prime(num, i)) {
                create_num(digit+1, num*10 + i);
            }
        }
    }
}

int main() {
    ifstream fin ("sprime.in");
    
    fin >> n;
    fin.close(); 
    create_num(0, 0);
    fout.close();
    return 0;
}
