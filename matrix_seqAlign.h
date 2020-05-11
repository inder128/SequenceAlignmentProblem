#ifndef MATRIX_SEQALIGN_H
#define MATRIX_SEQALIGN_H

#include <iostream> 
#include <string> 
#include <stack> 
using namespace std; 

pair< stack<char>, stack<char> > matrix_seqAlign(string, string, int, int, int*);
pair< stack<char>, stack<char> > matrix_seqAlign(string, string, int, int);

pair< stack<char>, stack<char> > matrix_seqAlign(
    string s1, string s2, int mmc, int gc, int &cost){
	pair< stack<char>, stack<char> > res = matrix_seqAlign(s1, s2, mmc, gc);
	stack<char> stk1 = res.first, stk2 = res.second;
	cost = 0;
    while(!stk1.empty()){
        if(stk1.top()=='-' or stk2.top()=='-')
        	cost += gc;
        else if(stk1.top()!=stk2.top())
        	cost += mmc;
        stk1.pop(); stk2.pop();
    }
    return res;
}

pair< stack<char>, stack<char> > matrix_seqAlign(
    string s1, string s2, int mmc, int gc){
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for (int i = 0; i < n+1; ++i)
        dp[i][0] = i*gc;
    for (int i = 0; i < m+1; ++i)
        dp[0][i] = i*gc;
    for (int i = 1; i < n+1; ++i){
        for (int j = 1; j < m+1; ++j){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1]+mmc, min(dp[i-1][j], dp[i][j-1])+gc);
        }
    }
    // for (int i = 0; i < n+1; ++i){
    //     for (int j = 0; j < m+1; ++j)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    int x=n, y=m;
    stack <char> stk1, stk2;
    while(x and y){
        // cout<<x<<" "<<y<<endl;
        // cout<<s1[x-1]<<" "<<s2[y-1]<<endl;
        if(s1[x-1]==s2[y-1] or dp[x][y]==dp[x-1][y-1]+mmc){
            stk1.push(s1[x-1]);
            stk2.push(s2[y-1]);
            x--; y--;
            continue;
        }
        if(dp[x][y]==dp[x-1][y]+gc){
            stk1.push(s1[x-1]);
            stk2.push('-');
            x--;
        }
        else{
            stk1.push('-');
            stk2.push(s2[y-1]);
            y--;
        }
    }
    while(x>0){
        stk1.push(s1[x-1]);
        stk2.push('-');
        x--;
    }
    while(y>0){
        stk1.push('-');
        stk2.push(s2[y-1]);
        y--;
    }
    return make_pair(stk1, stk2);
};

#endif