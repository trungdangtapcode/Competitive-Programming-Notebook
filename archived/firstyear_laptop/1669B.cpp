#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	a[n+1] = a[n]+1;
	for (int i = 2, cnt = 1; i <= n+1; i++){
		if (a[i]!=a[i-1]){
			cnt = 0;
		}
		cnt++;
		if (cnt==3){
			cout << a[i] << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

