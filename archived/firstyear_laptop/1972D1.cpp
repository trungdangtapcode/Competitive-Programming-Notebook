#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e6+5;
int n, m, f[maxN*2];
vector<int> d[maxN*2];
void solve(){
	cin >> n >> m;
	long long res = 0;
	int mn = n+m;
	for (int g = 1; g <= m; g++){
//		for (int b = g; b <= m; b+=g){
//			f[g] += (mn/(b));
//			int t = 1ll*k/__gcd(k,g);
//			res += upper_bound(d[t].begin(),d[t].end(),m/g)-d[t].begin();
//		}
		res += (n+g)/g/g-1/g/g;
//		cout << g << " " << (n+g)/g/g-1/g/g << "\n";
	}
//	for (int i = 1; i <= mn; i++) cout << i << " = " << f[i] << "\n";
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	for (int i = 1; i <= maxN*2; i++) cnt[i] = 0;
//	for (int i = 1; i <= maxN*2; i++){
//		for (int j = i; j <= maxN*2; j+= i) d[j].push_back(i);
//	}
	int t; cin >> t;
	while (t--)
	solve();
}

