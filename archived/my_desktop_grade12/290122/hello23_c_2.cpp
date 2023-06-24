#include<bits/stdc++.h>

using namespace std;
#define int long long
int c[100005], d[100005], k, n, res;
vector<int> a[3];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	for (int i = 0; i < n; i++){
		cin >> d[i];
		a[d[i]%3].push_back(c[i]);
	}
	for (int i = 0; i < 3; i++) sort(a[i].begin(),a[i].end());
	for (int r = 0; r < 3; r++) for (int q = 0; q < 3; q++){
		if (r>a[1].size()||r>a[2].size()||q>a[0].size()) continue;
		vector<int> cur;
		for (int j = r; j + 2 < a[1].size(); j += 3) cur.push_back(a[1][j]+a[1][j+1]+a[1][j+2]);
		for (int j = r; j + 2 < a[2].size(); j += 3) cur.push_back(a[2][j]+a[2][j+1]+a[2][j+2]);
		for (int j = q; j + 2 < a[0].size(); j += 3) cur.push_back(a[0][j]+a[0][j+1]+a[0][j+2]);
		int kk = k;
		for (int j = 0; j < r; j++) kk -= a[1][j] + a[2][j];
		for (int j = 0; j < q; j++) kk -= a[0][j];
		if (kk>=0) res = max(res,2*r+q);
		sort(cur.begin(),cur.end());
		for (vector<int>::iterator x = cur.begin(); x != cur.end(); x++){
			kk -= *x;
			if (kk<0) break;
			res = max(res,2*r+q+3*(x-cur.begin()+1));
		}
	}
	cout << res;
	
	
	
	
	return 0;
}
