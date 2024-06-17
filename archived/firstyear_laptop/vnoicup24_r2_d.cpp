#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], k;
string s;
void solve(){
	cin >> n >> k >> s;
	s = " " + s;
	int cntO = 0;
	for (int i = 1; i <= n; i++){
		cntO += (s[i]=='O');
		for (int j = 0; j <= k; j++){
			
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

