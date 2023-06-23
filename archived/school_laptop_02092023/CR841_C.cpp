#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
//bool p[200005];
int cnt[200005*2];
int main(){
//	n = 2e5;
//	for (int i = 2; i <= n; i++) for (int j = 2*i; j <= n; j+= i){
//		p[j] ^= 1;
//	}
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) a[i] ^= a[i-1];
		fill(cnt,cnt+2*n+1,0);
		cnt[0] = 1;
		long long res = 1ll*n*(n+1)/2;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j*j <= 2*n; j++) if ((a[i]^(j*j))<=2*n) res -= cnt[a[i]^(j*j)];
			cnt[a[i]]++;
		}
		cout << res << "\n";
	}
	
	return 0;
}
