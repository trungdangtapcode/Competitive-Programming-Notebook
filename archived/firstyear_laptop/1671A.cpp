#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	int n = s.length(), cnt = 0, res = 1;
	char last = 'a'-1;
	for (char c: s){
		if (c!=last){
			if (cnt==1) res = 0;
			cnt = 0;
		}
		cnt++;
		if (--n==0&&cnt==1) res = 0;
		last = c;
	}
	cout << (res?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

