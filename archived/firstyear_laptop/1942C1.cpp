#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, x, y, a[maxN];
void solve(){
	cin >> n >> x >> y;
	for (int i = 0; i < x; i++){
		cin >> a[i];
		a[i]--;
	}
	sort(a,a+x);
	int res = 0;
	for (int i = 0; i < x; i++){
		res += (a[(i+1)%x]-a[i]+n)%n==2;
	}
	cout << res+x-2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

