#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, c;
int nCr(int n, int r){
	if (r<0||r>n) return 0;
	vector<int> v(r);
	for (int i = 0; i < r; i++) v[i] = i+1;
	int res = 1;
	for (int i = n-r+1; i <= n; i++){
		int tmp = i;
		for (int& x: v){
			int g = __gcd(tmp,x);
			x /= g;
			tmp /= g;
		}
		res *= tmp;
	}
	return res;
}
void solve(){
	cin >> a >> b >> c;
	int cnt = __builtin_popcountll(c);
	int k = (a+b-cnt)/2;
	if ((a+b-cnt)%2||k<0||k>a||k>b){
		cout << -1 << "\n";
		return;
	};
//	cout << nCr(60-cnt,k)*nCr(cnt,a-k) << "\n";
	int x = 0, in = a-k, out = k;
	for (int i = 0; i < 60; i++){
		if ((c>>i&1)&&in>0){
			x ^= (1ll<<i);
			in--;
		} 
		if (!(c>>i&1)&&out>0){
			x ^= (1ll<<i);
			out--;
		}
	}
	if (in!=0||out!=0){
		cout << -1;
		return;
	}
	cout << (x) << " " << (c^x) << "\n";
//	cout << __builtin_popcountll(x) << " " << __builtin_popcountll(c^x) << "\n";
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

