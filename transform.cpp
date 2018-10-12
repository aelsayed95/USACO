/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: ayah.eh1
PROG: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

char** malloc_board(int n) {
    char** ret = (char **) malloc(n * sizeof(char *));
    int i;
    for(i = 0; i < n; i++) {
        ret[i] = (char *) malloc(n * sizeof(char));
    }
    return ret;
}

void free_board(char** board, int n) {
    int i;
    for(i = 0; i < n; i++){
        free(board[i]);
    }
    free(board);
}

char** mirror(char** start, int n) {
    char** ret = malloc_board(n);

    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            ret[i][n-j-1] = start[i][j];
        }
    }
    return ret;

}

char** rotate90(char** start, int n) {
    char** ret = malloc_board(n);

    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            ret[j][n-i-1] = start[i][j];
            //cout << j <<"," << n-i << " ==> " << i << "," << j << endl;
        }
    }
    return ret;
}

void print_board(char** src, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << src[i][j] << " ";
        }
        cout << endl;
    }
}

bool equal_boards(char** b1, char** b2, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(b1[i][j] != b2[i][j]) return false;
        }
    }
    return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int i, j;
    char** board;
    char** rotated;
    int n;
    fin >> n;

    board = malloc_board(n);
    rotated = malloc_board(n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            fin >> board[i][j];
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            fin >> rotated[i][j];
        }
    }

    char** rot90 = rotate90(board, n);
    if(equal_boards(rot90, rotated, n)){
        fout << "1" << endl;
    } else {
        char** rot180 = rotate90(rot90, n);
        if(equal_boards(rot180, rotated, n)){
            fout << "2" << endl;
        } else {
            char** rot270 = rotate90(rot180, n);
            if(equal_boards(rot270, rotated, n)){
                fout << "3" << endl;
            } else {
                char** mirrored = mirror(board, n);
                if(equal_boards(mirrored, rotated, n)){
                    fout << "4" << endl;
                } else {
                    char** comb1 = rotate90(mirrored, n);
                    if(equal_boards(comb1, rotated, n)){
                        fout << "5" << endl;
                    } else {
                        char** comb2 = rotate90(comb1, n);
                        if(equal_boards(comb2, rotated, n)){
                            fout << "5" << endl;
                        } else {
                            char** comb3 = rotate90(mirrored, n);
                            if(equal_boards(comb3, rotated, n)){
                                fout << "5" << endl;
                            } else {
                                if(equal_boards(board, rotated, n)) {
                                    fout << "6" << endl;
                                }
                                else{
                                    fout << "7" << endl;
                                }
                                free_board(comb3, n);
                            }
                            free_board(comb2, n);
                        }
                        free_board(comb1, n);
                    }
                    free_board(mirrored, n);
                }
                free_board(rot270, n);
            }
            free_board(rot180, n);
        } 
        free_board(rot90, n);
    }
    free_board(board, n);
    free_board(rotated, n);
    return 0;
}
