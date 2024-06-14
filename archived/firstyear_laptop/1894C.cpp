#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], res[maxN], k;
void solve(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int pos = 0;
	for (int i = 0; i < n; i++) res[i] = 0;
//	res[pos] = 1;
	for (int i = 0; i < k; i++){
		int x = a[(pos+n-1)%n];
		if (x>n){
			cout << "No\n";
			return;
		}
		res[pos] = 1;
		pos = (pos+n-1)%n - x + 1;
		pos %= n;
		pos += n;
		pos %= n;
		if (res[pos]) break;
	}
	cout << "Yes\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
