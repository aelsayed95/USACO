/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    unordered_map<string, int> friends;     //insertion/search cost of O(1)
    string names[10];                       //to maintain name order for printing output
    int num_friends, money, num_gifted;
    string name, gifted;
    int i, j;

    fin >> num_friends;
    for(i = 0; i < num_friends; i++) {
        fin >> names[i];
        friends[names[i]] = 0;
    }

    for(i = 0; i < num_friends; i++) {
        fin >> name;
        fin >> money >> num_gifted;
        if( num_gifted > 0 ) {
            money = money / num_gifted;
        }
        friends[name] -= money * num_gifted;
        for(j = 0; j < num_gifted; j++) {
            fin >> gifted;
            friends[gifted] += money;
        }
    }

    for(i = 0; i < num_friends; i++) {
        fout << names[i] << " " << friends[names[i]] << endl; 
    }
    return 0;
}
