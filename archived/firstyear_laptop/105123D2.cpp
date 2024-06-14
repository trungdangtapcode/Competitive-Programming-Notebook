#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a, b, x[maxN], y[maxN];
int cnt(int l, int r){
	int posl = lower_bound(x+1,x+n+1,l)-x, posr = upper_bound(x+1,x+n+1,r)-x-1;
	return posr-posl+1;
}
void solve(){
	cin >> n >> a >> b; b--;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
		y[i] = x[i];
	}
	sort(x+1,x+n+1);
	for (int i = 1; i <= n; i++){
		cout << cnt(y[i]+a,y[i]+b) << " " << cnt(y[i]-b,y[i]-a) << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

