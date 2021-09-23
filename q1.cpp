// Time Complexity :- O(n*m)
// Space Complexity :- O(n*m)
// can compute both cost and alignment;

#include <bits/stdc++.h> 
#include "matrix_seqAlign.h" 
using namespace std; 


int main () {
    int t = 1;
    while (t--) {
        string s1, s2;
        int mmc, gc, n, m, cost;
        cin >> s1 >> s2;
        // mmc is mismatch cost and gc is gap cost;
        cin >> mmc >> gc;
        pair <string, string> res = matrix_seqAlign(s1, s2, mmc, gc, cost);
        cout << cost << endl;
        cout << res.first << endl << res.second << endl;
    }
    return 0;
}