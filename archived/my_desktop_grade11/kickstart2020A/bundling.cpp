#include <bits/stdc++.h>
using namespace std;

int n, k, c[2000001][26], m, cnt[2000001];
long long ans;

void dfs(int u = 0, int d = 0) {
	for(int v = 0; v < 26; ++v)
		if( c[u][v] ){
			char ch = v + 'A';
			cout << ch << " " << d <<  " ";
			for (int i = 0; i<10; i++) cout << cnt[i];
			cout << endl;
			
			dfs( c[u][v], d + 1), cnt[u] += cnt[ c[u][v] ];
		}
	while(cnt[u] >= k) {
		cnt[u] = cnt[u] - k;
		ans = ans + d;
	}
}

void solve() {
	cin >> n >> k;
	m = 1;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int u = 0;
		for(int i = 0; i<s.length(); i++) {
			char d = s[i];
			if(!c[u][d - 'A'])
				c[u][d -'A'] = m++;
			u = c[u][d-'A'];
		}
		++cnt[u];
	}
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 4; j++) cout << c[i][j];
		cout << endl;
	};
	cout << endl;
	ans = 0;
	dfs();
	cout << ans << endl;
	memset(c, 0, m*sizeof(c[0]));
	memset(cnt, 0, m*4);
}

int main() {
	int t, i=1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve();
		i++;
	}
}
