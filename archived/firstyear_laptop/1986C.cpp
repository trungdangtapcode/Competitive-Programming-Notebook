#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, m, a[maxN];
string s, t;
void solve(){
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) cin >> a[i];
	sort(a+1,a+m+1);
	cin >> t;
	priority_queue<char,vector<char>,greater<char>> pq;
	for (char c: t) pq.push(c);
	for (int i = 0; i < m; i++) t[i] = '?';
	for (int i = 1; i <= m; i++){
		if (i==m||a[i]!=a[i+1]){
			t[i-1] = pq.top();
			s[a[i]-1] = pq.top();
			pq.pop();
		}
	}
	cout << s << "\n";
	for (int i = 1; i <= m; i++) if (t[i-1]=='?'){
		t[i-1] = pq.top();
		pq.pop();
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

