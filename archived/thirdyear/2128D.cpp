#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert(i);
	}
	for (int i = 1; i <= n; i++){
		int x = *s.rbegin();
		if (a[i]==x) b[i] = 1;
		else b[i] = 0;
		s.erase(a[i]);
//		cout << b[i] << " ";
	}
//	cout << "\n";
	int res = 0, sm = 0;
	for (int i = n; i >= 1; i--){
		if (b[i]==1){
			sm += (n-i+1);
			res += sm;
		} else {
			sm++;
			res += sm;
		}
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

