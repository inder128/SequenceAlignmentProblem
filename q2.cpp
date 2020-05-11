// Time Complexity :- O(n*m)
// Space Complexity :- O(n)
// can compute both cost and but not alignment;

#include <iostream> 
#include <string> 
using namespace std; 

int n, m, gc, mmc;
string s1, s2;

void two1dArr(int a[], int b[], int i){
    if(i==n+1) return;
    b[0] = i*gc;
    for (int j = 1; j < m+1; ++j){
        if(s2[j-1]==s1[i-1])
            b[j] = a[j-1];
        else
            b[j] = min(a[j-1]+mmc, min(a[j]+gc, b[j-1]+gc));
    }
    for (int i = 0; i < m+1; ++i)
        swap(a[i], b[i]);
    two1dArr(a, b, i+1);
}

int main(){
    int t;
    t=1;
    while(t--){
        cin>>s1>>s2;
        // mmc is mismatch cost and gc is gap cost;
        cin>>mmc>>gc;
        n = s1.length();
        m = s2.length();
        int a[m+1], b[m+1];
        for (int i = 0; i < m+1; ++i)
            a[i] = i*gc;
        two1dArr(a, b, 1);
        for (int i = 0; i < m+1; ++i)
            cout<<a[i]<<" ";
        cout<<endl<<a[m]<<endl;
    }
    return 0;
}