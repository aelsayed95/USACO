/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int translate_code(string s) {
    int product = 1;
    int i, intVal;
    for(i = 0; i < s.size(); i++) {
        intVal = s[i] - 'A' + 1;
        product = product * intVal;
    }
    product = product % 47;
    return product;
}


int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;

    int product_a = translate_code(a);
    int product_b = translate_code(b);

    if (product_a == product_b ) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
