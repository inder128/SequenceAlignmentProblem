#ifndef MATRIX_SEQALIGN_H
#define MATRIX_SEQALIGN_H

#include <bits/stdc++.h> 
using namespace std; 

pair <string, string> matrix_seqAlign (string, string, int, int, int*);
pair <string, string> matrix_seqAlign (string, string, int, int);

pair <string, string> matrix_seqAlign (string s1, string s2, int mmc, int gc, int &cost) {
	pair <string, string> res = matrix_seqAlign(s1, s2, mmc, gc);
	string stk1 = res.first, stk2 = res.second;
	cost = 0;
    while (stk1.size()) {
        if (stk1.back() == '-' or stk2.back() == '-')
        	cost += gc;
        else if (stk1.back() != stk2.back())
        	cost += mmc;
        stk1.pop_back(); 
        stk2.pop_back();
    }
    return res;
}

pair <string, string> matrix_seqAlign (string s1, string s2, int mmc, int gc) {
    int n = s1.length();
    int m = s2.length();
    int DP[n+1][m+1];
    for (int i = 0; i < n + 1; ++i)
        DP[i][0] = i * gc;
    for (int i = 0; i < m + 1; ++i)
        DP[0][i] = i * gc;
    for (int i = 1; i < n + 1; ++i){
        for (int j = 1; j < m + 1; ++j){
            if (s1[i - 1] == s2[j - 1])
                DP[i][j] = DP[i - 1][j - 1];
            else
                DP[i][j] = min(DP[i - 1][j - 1] + mmc, min(DP[i - 1][j], DP[i][j - 1]) + gc);
        }
    }

    int x = n, y = m;
    string stk1, stk2;
    while (x and y) {
        if (s1[x - 1] == s2[y - 1] or DP[x][y] == DP[x - 1][y - 1] + mmc) {
            stk1.push_back(s1[x - 1]);
            stk2.push_back(s2[y - 1]);
            x--; 
            y--;
            continue;
        }
        if (DP[x][y] == DP[x - 1][y] + gc) {
            stk1.push_back(s1[x - 1]);
            stk2.push_back('-');
            x--;
        }
        else {
            stk1.push_back('-');
            stk2.push_back(s2[y - 1]);
            y--;
        }
    }
    while (x > 0) {
        stk1.push_back(s1[x - 1]);
        stk2.push_back('-');
        x--;
    }
    while (y > 0) {
        stk1.push_back('-');
        stk2.push_back(s2[y - 1]);
        y--;
    }
    return {stk1, stk2};
};

#endif