#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5;
int n, c[maxN], f[maxN][maxN];
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		mp[a]++;
	}
	int m = 0;
	for (auto it: mp){
		c[++m] = it.second;
	}
	priority_queue<int> b;
	int skip = 0;
	for (int i = 1; i <= m; i++){
		if (c[i]<=skip){
			skip -= c[i];
			b.push(c[i]);
			continue;	
		}
		if (b.size()&&b.top()>c[i]){
			skip += b.top();
			b.pop();
			skip -= c[i];
			b.push(c[i]);
		}
		skip++;
	}
	cout << m-b.size() << "\n";
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

