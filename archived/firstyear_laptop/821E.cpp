#include<bits/stdc++.h>

using namespace std;
const int maxN = 105, mod = 1e9+7, maxC = 16;
int n, c[maxN];
long long k, a[maxN], b[maxN];
struct Matrix{
	int a[maxC][maxC], n, m;
	Matrix(int _n, int _m){
		n = _n;
		m = _m;
		set0();
	}
	void setMatrix(vector<int> &v){
		for (int i = 0, cnt = 0; i < n; i++) for (int j = 0; j < m; j++){
			a[i][j] = v[cnt++];
		}
	}
	void set0(){
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = 0;
	}
	void set1(){
		for (int i = 0; i < n; i++) a[i][i] = 1;
	}
	int* operator[](int idx){
		return a[idx];
	}
	Matrix operator*(Matrix other){
		Matrix res(n,other.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++){
			for (int k = 0; k < m; k++) (res[i][j] += 1ll*a[i][k]*other[k][j]%mod)%=mod;
		}
		return res;
	} 
	void print(){
		cout << n << "x" << m << ": \n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) cout << a[i][j] << " ";
			cout << "\n";
		}
	}
};
Matrix matPow(Matrix a, long long n){
	Matrix res(a.n,a.m);
	res.set1();
	while (n){
		if (n%2) res = res*a;
		a = a*a;
		n /= 2;
	}
	return res;
}

void solve(){
//	Matrix a(1,2);
//	cout << a[0][0];
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	Matrix f(1,maxC);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		Matrix base(maxC, maxC);
		for (int j = 0; j <= c[i]; j++) base[j][j] = 1;
		for (int j = 0; j < c[i]; j++) base[j][j+1] = 1;
		for (int j = 0; j < c[i]; j++) base[j+1][j] = 1;
		f = f*matPow(base,min(b[i],k)-a[i]);
	}
//	f.print();
	cout << f[0][0] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

