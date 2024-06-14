#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n, p[maxN], res[maxN];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		res[i] = -1;
	}
	for (int l = 1, r = n, cntl = 0, cntr = 0; l<=r;){
		if (cntl<cntr){
			res[l] = !p[l];
			cntl += !p[l++];
		} else {
			res[r] = p[r];
			cntr += p[r--];
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >>t;
	while (t--) solve();
	
	return 0;
}
