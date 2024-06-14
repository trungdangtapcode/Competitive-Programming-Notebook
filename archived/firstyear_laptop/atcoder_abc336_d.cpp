#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], b[maxN], f[maxN], g[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	multiset<int> ms;
	for (int i = 1; i <= n; i++){
		b[i] = a[i]-i;
		ms.insert(b[i]);
		while (*ms.begin()+i-(int)ms.size()<0) ms.erase(ms.find(b[i-(int)ms.size()+1]));
		f[i] = ms.size();
	}
	ms.clear();
	for (int i = n; i >= 1; i--){
		b[i] = a[i]-(n-i+1);
		ms.insert(b[i]);
		while (*ms.begin()+n-i-(int)ms.size()+1<0) ms.erase(ms.find(b[i+(int)ms.size()-1]));
		g[i] = ms.size();
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res,min(f[i],g[i]));
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

