#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//long long Rand(long long l, long long h) {
//    assert(l <= h);
//    return l + rd() * 1LL * rd() % (h - l + 1);
//}
//int mp[maxN*4];
void solve(){
	cin >> n;
//	for (int i = 0; i <= 4*n; i++) h[i] = rd();
//	int sum = 0;
//	for (int i = 0; i < n; i++) sum ^= i;
//	for (int i = 1; i < n; i++) mp[sum^i] = 1;
	for (int i = 2; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1];
//		cout << bitset<3>(a[i]) << " " << a[i] << "\n";
	}
//	if (n%2){
//		int cur = 0;
//		for (int i = 1; i <= n; i++) cur ^= a[i];
//		cur ^= sum;
//		for (int i = 1; i <= n; i++) cout << (a[i]^cur) << " "; cout << "\n";
//	} else {
//		int cur = 0;
//		for (int i = 2; i <= n; i++) cur ^= a[i];
//		for (int i = 1; i <= n; i++){
//			if (mp[cur^a[i]]){
//				for (int j = 1; j <= n; j++) cout << (a[j]^a[i]) << " "; cout << "\n";
//				return;
//			}
//			if (true){
//				for (int j = 1; j <= n; j++) cout << (a[j]^2) << " "; cout << "\n";
//				return;
//			}
//			if (cur^a[i]==sum^a[i]){
//				
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++) cout << (a[i]^a[j]) << " "; cout <<"\n";
//	}
	int res = 0;
	for (int bit = 1; bit <= n; bit <<= 1){
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (bool)(a[i]&bit);
		if (cnt>n-cnt) res |= bit;
	}
	for (int i = 1; i <= n; i++) cout << (a[i]^res) << " ";
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--) 
	solve();
	
	return 0;
}
