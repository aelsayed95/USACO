/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: milk
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

struct milk_t {
    int cost;
    int amount;
    bool operator<(const milk_t& rhs) const { return cost < rhs.cost; }
} milk[5000];

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int i, m, n;
    fin >> m >> n;
    for(i = 0; i < n; i++) {
        fin >> milk[i].cost >> milk[i].amount;
    }
    sort(milk, milk+n);

    int cost = 0;
    for(i = 0; i < n && m > 0; i++) {
        int to_purchase = min(m, milk[i].amount);
        m-= to_purchase;
        cost += milk[i].cost * to_purchase;
    }
    fout << cost << endl;
    return 0;
}
