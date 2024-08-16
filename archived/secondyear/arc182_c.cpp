#include<bits/stdc++.h>

using namespace std;
const int numPrime = 6, mod = 998244353, maxN = (1<<numPrime)+5;
const int prime[] = {2,3,5,7,11,13};

struct Matrix{
	int n, m, a[maxN][maxN];
//	const int r = 1; CONST IN STRUCT -> ERROR (idk)
	Matrix(int n, int m){
		this->n = n;
		this->m = m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) a[i][j] = 0;
		}
	}
	int* operator[](const int i){
		return a[i];
	}
	void one(){
		for (int i = 0; i < min(n, m); i++) a[i][i] = 1;
	}
	Matrix operator*(Matrix& other){
		assert(m==other.n);
		Matrix res(n,other.m);
		for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++){
			for (int k = 0; k < m; k++) (res[i][j] += 1ll*a[i][k]*other[k][j]%mod)%=mod;
		}
		return res;
	}
	void print(){
		cout << n << "x" << m << "\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) cout << a[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
};
Matrix matPow(Matrix a, long long n){
	Matrix res(a.n,a.n);
	res.one();
	while (n){
		if (n%2) res = res*a;
		n /= 2;
		a = a*a;
	}
	return res;
}
void test(Matrix x){
	x.print();
}
long long n;
int m, nxt[maxN];

void solve(){
	cin >> n >> m;
	for (int mask = 0; mask < (1<<numPrime); mask++){
		for (int i = 1; i <= m; i++){
			int cur = 1;
			for (int p = 0; p < numPrime; p++) if(mask>>p&1){
				int cnt = 0, tmp = i;
				while (tmp%prime[p]==0) cnt++, tmp /= prime[p];
				cur *= cnt;
			}
			nxt[mask] += cur;
		}
	}
	Matrix mat((1<<numPrime)+1,(1<<numPrime)+1);
	for (int mask = 0; mask < (1<<numPrime); mask++){
		for (int nmask = 0; nmask < (1<<numPrime); nmask++){
			if ((nmask&mask)!=mask) continue;
			int v = nmask^mask;
			mat[mask][nmask] = nxt[v];
		}
	}
	mat[1<<numPrime][1<<numPrime] = 1;
	mat[(1<<numPrime)-1][1<<numPrime] = 1;
	Matrix base(1,(1<<numPrime)+1);
	for (int i = 0; i < (1<<numPrime); i++) base[0][i] = 1;
	auto pmat = matPow(mat,n+1);
	cout << (base*pmat)[0][1<<numPrime]-1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

