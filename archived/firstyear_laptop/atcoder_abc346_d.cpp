#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, c[maxN];
string s;
void solve(){
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> c[i];
	string s1, s2;
	for (int i = 0; i < n; i++) s1.push_back(i%2+'0'), s2.push_back(!(i%2)+'0'); 
	s1[0] = '1';
	s2[0] = '0';
	int res = 1e18;
	
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += (s[i]!=s1[i])*c[i];
	}
	res = min(res,sum);
	for (int i = 1; i < n-1; i++){
		sum -= (s[i]!=s1[i])*c[i];
		s1[i] = '1'-s1[i]+'0';
		sum += (s[i]!=s1[i])*c[i];
		res = min(res,sum);
	}
	
	sum = 0;
	for (int i = 0; i < n; i++){
		sum += (s[i]!=s2[i])*c[i];
	}
	res = min(res,sum);
	for (int i = 1; i < n-1; i++){
		sum -= (s[i]!=s2[i])*c[i];
		s2[i] = '1'-s2[i]+'0';
		sum += (s[i]!=s2[i])*c[i];
		res = min(res,sum);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

