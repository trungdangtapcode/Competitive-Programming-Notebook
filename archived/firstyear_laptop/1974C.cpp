#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int a[maxN], n;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<iii,int> mp;
	map<ii,int> mpx, mpy, mpz;
	long long res = 0;
	for (int i = 3; i <= n; i++){
		int x = a[i-2], y = a[i-1], z = a[i];
		res += mpx[{y,z}]+mpy[{x,z}]+mpz[{x,y}]-3*mp[{{x,y},z}];
		mpx[{y,z}]++;
		mpy[{x,z}]++;
		mpz[{x,y}]++;
		mp[{{x,y},z}]++;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

