#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int maxN = 2e5+5;
int n, m, k, w, a[maxN];
void solve(){
	cin >> n >> m >> k;
	vvi s(n+2,vi(m+3));
	for (int i = 1; i <= n-k+1; i++){
		for (int j = 1; j <= m-k+1; j++){
			s[i][j]++;
			s[i][j+k]--;
			s[i+k][j]--;
			s[i+k][j+k]++;
		}
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			pq.push(s[i][j]);
		}
	}
	cin >> w;
	for (int i = 1; i <= w; i++){
		cin >> a[i];
	}
	sort(a+1,a+w+1);
	long long res = 0;
	for (int i = w; i >= 1; i--){
		res += 1ll*a[i]*pq.top();
		pq.pop();
	}
	cout << res << "\n";
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

