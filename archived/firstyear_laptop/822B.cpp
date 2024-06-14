#include<bits/stdc++.h>

using namespace std;
int n, m;
string s, t;
void solve(){
	cin >> n >> m >> s >> t;
	int pos =-1, mmin = 1e9;
	for (int i = 0; i < m-n+1; i++){
		int cur = 0;
		for (int j = 0; j < n; j++) cur += s[j]!=t[j+i];
		if (cur<mmin) mmin = cur, pos = i;
	}
	cout << mmin << "\n";
	for (int j = 0; j < n; j++) if (s[j]!=t[j+pos]) cout << j+1 << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

