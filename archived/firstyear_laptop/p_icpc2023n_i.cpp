#include<bits/stdc++.h>

using namespace std;
#define int long long
//int p[] = {0,4,3,1,2};
bool check(int i, int j){ //p[i] < p[j]???
	int x1, x2;
	cout << "? " << i << " " << j << endl;
	cin >> x1;
	cout << "? " << i << " " << j << endl;
	cin >> x2;
	return (x2<x1)^(i>j);
//	return p[i]<p[j];
}
int n, res[10005];
vector<int> memo[10005];
int midx = 1;
int ran(int idx){
	return memo[idx][memo[idx].size()/2];
}
void solve(int p, int idx, int greater){
//	cout << p << " ==== " << greater << "\n";
//	for (int x: memo[idx]){
//		cout << x << " ";
//	}
//	cout << "\n";
	int idxl = midx++, idxr = midx++, cur_greater = 0;
	for (int i: memo[idx]){
		if (i==p) continue;
		bool c = check(i,p);
		if (c){
			memo[idxl].push_back(i);
			cur_greater++;
		} else {
			memo[idxr].push_back(i);
		}
	}
	res[p] = greater+cur_greater+1;
	if (memo[idxl].size()) solve(ran(idxl),idxl,greater);
	if (memo[idxr].size()) solve(ran(idxr),idxr,greater+cur_greater+1);
}


main(){
//	cin >> n;
//	while (1){
//		
//	}
	cin >> n;
	for (int i = 1; i <= n; i++) memo[0].push_back(i);
	solve(ran(0),0,0);
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << endl;
	
	return 0;
}
