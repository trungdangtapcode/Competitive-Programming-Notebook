#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, c[2];
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	c[0] = c[1] = 0;
	for (int i = 1; i <= n; i++){
		if (s[i]=='1') c[1]++;
	}
	ii res = {1e9,-1};
	for (int i = 1; i <= n; i++){
		if (c[0]>=i/2&&c[1]>=(n-i+2)/2) res = min(res,{abs(n-2*(i-1)),i-1});
		if (s[i]=='1'){
			c[1]--;
		} else c[0]++;
		if (c[0]>=(i+1)/2&&c[1]>=(n-i+1)/2) res = min(res,{abs(n-2*i),i});
	}
	cout << res.second << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

