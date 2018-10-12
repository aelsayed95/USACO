/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string necklace;

int count_beads(int cut, char color1, char color2) {
    int total = 0;
    int i;
    for(i = cut; i < necklace.size(); i++){
        if(necklace[i] == color1 || necklace[i] == color2) {
            total++;
        }
        else break;
    }
    return total;
}

int count_beads_all(int cut) {
    int total1 = 0, total2 = 0, total3 = 0,  total, i;
    total1 = count_beads(cut, 'w', 'w');
    cut = cut + total1;
    total2 = count_beads(cut, necklace[cut], 'w');
    cut = cut + total2;
    total3 = count_beads(cut, necklace[cut], 'w');
    total = total1 + total2 + total3;
    total = (total > necklace.size()/2) ? (necklace.size()/2) : total;
    return total;
}


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n;
    fin >> n;
    fin >> necklace;
    necklace = necklace + necklace;

    int num_collected, max_collected = 0, i;
    for(i = 0; i < necklace.size(); i++) {
        num_collected = count_beads_all(i);
        max_collected = num_collected > max_collected ? num_collected : max_collected;
    }
    fout << max_collected << endl;
    return 0;
}
