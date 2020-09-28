// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)
// can compute both cost and alignment;

#include <iostream> 
#include <string> 
#include <stack> 
#include "matrix_seqAlign.h" 
using namespace std; 

//check

int main(){
    int t;
    t=1;
    while(t--){
        string s1, s2;
        int mmc, gc, n, m, cost;
        cin>>s1>>s2;
        // mmc is mismatch cost and gc is gap cost;
        cin>>mmc>>gc;
        pair< stack<char>, stack<char> > res = matrix_seqAlign(s1, s2, mmc, gc, cost);
        cout<<cost<<"\n";
        while(!res.first.empty()){
            cout<<res.first.top();
            res.first.pop();
        }
        cout<<"\n";
        while(!res.second.empty()){
            cout<<res.second.top();
            res.second.pop();
        }
        cout<<"\n";
    }
    return 0;
}