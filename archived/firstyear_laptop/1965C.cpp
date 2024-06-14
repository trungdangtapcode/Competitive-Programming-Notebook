#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	int l = 0, r = 1, cur = 1;
	for (int i = 1, x = 1; i < n; i++){
		if (s[i-1]==s[i]) x *= -1;
		cur += x;
		l = min(l,cur);
		r = max(r,cur);
	}
	cout << r-l << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

