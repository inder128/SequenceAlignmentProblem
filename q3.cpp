// Time Complexity :- O(log(n)*n*m)
// Space Complexity :- O(n)
// can compute both cost and alignment;

#include <bits/stdc++.h> 
#include "matrix_seqAlign.h" 
using namespace std; 

string s1, s2, f1, f2;
int mmc, gc;

void handleBaseCase (string sub_s1, string sub_s2) {
	pair <string, string> res = matrix_seqAlign(sub_s1, sub_s2, mmc, gc);
	while (res.first.size()) {
		f1.push_back(res.first.back());
		res.first.pop_back();
	}
	while (res.second.size()) {
		f2.push_back(res.second.back());
		res.second.pop_back();
	}
}

void two1dArr (int a[], int b[], int i, int n, int m, string sub_s1, string sub_s2) {
    if (i == n + 1) 
    	return;
    b[0] = i * gc;
    for (int j = 1; j < m + 1; ++j) {
        if (sub_s2[j - 1] == sub_s1[i - 1])
            b[j] = a[j - 1];
        else
            b[j] = min(a[j - 1] + mmc, min(a[j] + gc, b[j - 1] + gc));
    }
    for (int i = 0; i < m + 1; ++i)
        swap(a[i], b[i]);
    two1dArr(a, b, i + 1, n, m, sub_s1, sub_s2);
}

// divide and conqueer, two 1d arry, squence alingnment function;
void DandC_seqAlign (string sub_s1, string sub_s2) {
	int n = sub_s1.length();
	int m = sub_s2.length();

	if (n <= 2 or m <= 2)
		return handleBaseCase(sub_s1, sub_s2);

	int a1[n + 1], a2[n + 1], b[n + 1];
	for (int i = 0; i < n + 1; ++i)
    	a1[i] = a2[i] = i * gc;

	string tmp_s1 = sub_s2.substr(0, m / 2);
    two1dArr(a1, b, 1, m / 2, n, tmp_s1, sub_s1);

    string tmp_s2 = sub_s2.substr(m / 2, m - m / 2);
    string rev_s1 = sub_s1;
	reverse(rev_s1.begin(), rev_s1.end());
	reverse(tmp_s2.begin(), tmp_s2.end());
    two1dArr(a2, b, 1, m - m / 2, n, tmp_s2, rev_s1);

    int mid, sum = INT_MAX;
    for (int i = 0; i < n + 1; ++i) {
    	if (a1[i] + a2[n - i] < sum) {
    		sum = a1[i] + a2[n - i]; 
    		mid = i;
    	}
    }

    DandC_seqAlign(sub_s1.substr(0, mid), tmp_s1);

    reverse(tmp_s2.begin(), tmp_s2.end());
    DandC_seqAlign(sub_s1.substr(mid, n - mid), tmp_s2);
}


int main () {
	cin >> s1 >> s2;
	cin >> mmc >> gc;
	DandC_seqAlign(s1, s2);
	cout << f1 << endl;
	cout << f2 << endl;
	return 0;
}