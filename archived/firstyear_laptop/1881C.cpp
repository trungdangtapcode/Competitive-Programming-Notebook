#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n;
string s[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int res = 0;
	for (int i = 0; i < n/2; i++){
		for (int j = i; j < n-1-i; j++){
			char a[] = {s[i][j],s[j][n-1-i],s[n-1-i][n-1-j],s[n-1-j][i]};
			char c = max({s[i][j],s[j][n-1-i],s[n-1-i][n-1-j],s[n-1-j][i]});
			res += 4*c-(s[i][j]+s[j][n-1-i]+s[n-1-i][n-1-j]+s[n-1-j][i]);
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

