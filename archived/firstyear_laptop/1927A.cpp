#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	int mmax = -1, mmin = 1e9;
	for (int i = 0; i < n; i++){
		if (s[i]=='B') mmax = i, mmin = min(mmin,i);
	}
	cout << mmax-mmin+1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
