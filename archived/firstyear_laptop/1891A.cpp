#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int a[maxN], n;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mx = 0;
	for (int i = 1; (1<<i) <= n; i++){
//		cout << (1<<(i-1))+1 << ".." << min(n,(1<<i)) << "\n";
		for (int j = (1<<(i-1))+1; j < min(n,(1<<i)); j++){
			if (a[j]>a[j+1]) {
				cout << "NO\n";
				return;
			}
		}
		mx = i;
	}
	for (int j = (1<<mx)+1; j < n; j++){
		if (a[j]>a[j+1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
	return 0;
}
