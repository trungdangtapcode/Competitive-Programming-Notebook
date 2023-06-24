#include<bits/stdc++.h>

using namespace std;
#define int long long
struct matrix{
	vector<vector<int>> a;
	int n, m;
	matrix(int _n, int _m){
		n = _n; m = _m;
		a.resize(n+1,vector<int>(m+1,0));
	}
	matrix operator *(const matrix &x){
		matrix res(n,x.m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= x.m; j++) for (int k = 1; k <= m; k++) (res.a[i][j] += a[i][k]*x.a[k][j]);
		return res;
	}
	bool operator==(const matrix &x){
		for (int i = 1; i<= n; i++) for (int j = 1; j <= m; j++) if (a[i][j]!=x.a[i][j]) return 0;
		return 1;
	}
};
istream& operator >>(istream& cin, matrix& x){
	for (int i = 1; i <= x.n; i++) for (int j = 1; j <= x.m; j++) cin >> x.a[i][j];
	return cin;
}
ostream& operator <<(ostream& cout, const matrix& x){
	for (int i = 1; i <= x.n; i++){
		cout << "[ ";
		for (int j = 1; j<= x.m; j++) cout << x.a[i][j] << " ";
		cout << "]\n";
	}
	return cout;
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
	return rd()%(r-l+1)+l;
}

int n;
matrix a(1,1), b(1,1);
void solve(){
	cin >> n;
	a = matrix(n,n);
	cin >> a;
	matrix b(n,n);
	cin >> b;
	int k = 40;
	while (k--){
		matrix test(1,n);
		for (int i =1; i <= n; i++) test.a[1][i] = rand(1,3);
		if (!(test*a*a*a==test*b)) return cout << "NO\n", void();
	}
	cout << "YES\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

//modula locac: https://tinhoctre.vn/src/112203, vua modula vua long long =))
