#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a1[maxN], a2[maxN], b[maxN], c[maxN];
int calc(int a[]){
	std::iota(b+1, b+n+1, 1);
	sort(b+1, b+n+1, [&](int x, int y){
		return a[x]<a[y];
	});
	long long s1 = 0;
	for (int i = 1; i <= n; i++){
		while (b[i]!=i){
			s1 += 2*abs(b[i]-i)-1;
			swap(b[i],b[b[i]]);
		}
	}
	return s1&1;
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a1[i];
	for (int i = 1; i <= n; i++) cin >> a2[i];
	if (calc(a1)!=calc(a2)){
		cout << "NO\n";
		return;
	};
	sort(a1+1,a1+n+1);
	sort(a2+1,a2+n+1);
	for (int i = 1; i <= n; i++) if (a1[i]!=a2[i]){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
//	cout << s1 << " " << s2 << "\n";
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

