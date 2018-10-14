/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

bool valid[10] = {false, false, false, false, false, false, false, false, false, false};
int choice[9];

bool valid_digits(int n, int desired_num_digits) {
    int num_digits = 0;
    while(n) {
        if(!valid[n % 10]){ return false; }
        num_digits++;
        n/=10;
    }
    if(num_digits != desired_num_digits) { return false; }
    return true;
}

bool is_product_valid() {
    int n1 = choice[0] * 100 + choice[1] * 10 + choice[2];
    int p1 = n1 * choice[3];
    int p2 = n1 * choice[4];
    int tot = p1*10 + p2;
    return valid_digits(p1, 3) && valid_digits(p2, 3) && valid_digits(tot, 4);
}

int find_solutions(int num_picked) {
    if(num_picked == 5) {
        return is_product_valid();
    }

    int i, sum = 0;
    for(i = 1; i <= 9; i++) {
        if(valid[i]) {
            choice[num_picked] = i;
            sum += find_solutions(num_picked + 1);
        }
    }
    return sum;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n, i, num;
    fin >> n;
    for(i = 0; i < n; i++) {
        fin >> num;
        valid[num] = true;
    }
    fout << find_solutions(0) << endl;
    return 0;
}
