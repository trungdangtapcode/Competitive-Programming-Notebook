#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], c[maxN];
void solve(){
	cin >> n;
	int mex = 0;
	for (int i = 0; i < n; i++) c[i] = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i]>=0){
			c[mex] = 1;
			cout << mex << " ";
			while (c[mex]) mex++;
		} else {
			int x = mex-a[i];
			c[x] = 1;
			cout << x << " ";
		}
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

