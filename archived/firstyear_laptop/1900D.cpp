#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e6+5;
int n, a[maxN], cnt[maxN], f[maxN];
vector<int> edge[maxN];
void solve(){
	cin >> n;
	memset(cnt,0,sizeof(cnt));
	memset(f,0,sizeof(f));
	for (int i = 1; i<= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i<= n; i++){
		for (int d: edge[a[i]]){
			f[d] += cnt[d]*(n-i);
		}
		for (int d: edge[a[i]]) cnt[d]++;
	}
	for (int i = 1e5; i >= 1; i--){
		for (int j = 2*i; j <= 1e5; j += i) f[i] -= f[j];
	}
	int res = 0;
	for (int i = 1; i <= 1e5; i++) res += i*f[i];
	cout << res << "\n";
//	for (int i = 1; i<= 20; i++) cout << i << ": "<< f[i] << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 1e5;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j+= i) edge[j].push_back(i);
	}
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
