#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 3e5+5;
int n, k, a[maxN], pref[maxN], t[maxN];
vector<int> pos[maxN];

int calc(vector<int> x){
//	for (int y: x) cout << y <<" "; cout << "\n";
	int res = 0, cur = 0;
	for (int y: x){
		cur = max(cur,0ll);
		cur += y;
		res = max(res, cur);
	}
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		pos[t[i]].push_back(i);
//		cout << pref[i] << " ";
	}
//	cout << "\n";
	int res = 0;
	for (int i = 1; i <= k; i++){
//		calc(pos[i]);
		if (pos[i].empty()){
			cout << pref[n];
			return 0;
		}
		vector<int> cur;
		if (pos[i][0]>1) cur.push_back(pref[pos[i][0]-1]); 
		for (int j = 0; j < pos[i].size(); j++){
			if (j) cur.push_back(pref[pos[i][j]-1]-pref[pos[i][j-1]]);
			cur.push_back(-a[pos[i][j]]*(k-1));
		}
		if (pos[i][pos[i].size()-1]<n) cur.push_back(pref[n]-pref[pos[i][pos[i].size()-1]]);
		res = max(res,calc(cur));
	}
	cout << res;
	
	
	return 0;
}
