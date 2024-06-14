#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], cnt[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) cnt[a[i]]++;
	int yr = 0, al = 0;
	for (int i = 1; i <= n; i++) yr += (cnt[i]==2), al += (cnt[i]==0);
	cout << (yr<=al?yr:n-al) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

