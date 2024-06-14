#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], cnt[maxN];
void solve(){
	cin >> n;
	for (int i = 0; i <= n; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
//	int res = n;
//	for (int i = n-1; i >= 0; i--){
//		if (cnt[i]<=i) res = i;
//	}
//	for (int i = 0; i < res; i++){
//		if (cnt[i]==0){
//			cout << i << "\n";
//			return;
//		}
//	}
//	cout << res << "\n";
	for (int i = 0, c = 0; i <= n; i++){
		if (cnt[i]==0){
			cout << i << "\n";
			return;
		} else if (cnt[i]==1){
			if (c) {
				cout << i << "\n";
				return;
			} 
			c = 1;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
