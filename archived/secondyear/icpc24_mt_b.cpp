#include<bits/stdc++.h>

using namespace std;
const int maxL = 20, maxS = 1<<maxL, maxN = 5e5+5;
int n, a[maxN], f[maxS];
long long k;

void subsolve(int k, int x, int y){
	int cur = a[x]&a[y];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (cur&a[i]&a[j]) continue;
			k--;
			if  (k==0){
				cout << x << " " << y << " " << i << " " << j << "\n";
				return;
			}
		}
	}
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) f[a[i]&a[j]]++;
	}
	for (int i = 0; i < maxL; i++) for (int j = 0; j < maxS; j++) if (j>>i&1){
		f[j] += f[j^(1<<i)];
	}
	int tmp = maxS-1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x = f[tmp^(a[i]&a[j])];
			if (x>=k){
				subsolve(k,i,j);
				return;
			}
			k -= x;
		}
	}
	cout << -1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

