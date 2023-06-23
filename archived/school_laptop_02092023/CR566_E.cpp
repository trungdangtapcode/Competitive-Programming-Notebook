#include<bits/stdc++.h>

using namespace std;
long long int p = 1e9+7;
struct matrix{
	int a[105][105], n, m;
	matrix(int n, int m){
		this->n = n, this->m = m;
		memset(a,0,sizeof(a));
	}
	void setNum(int x){
		for (int i = 1; i <= min(n,m); i++) a[i][i] = x;
	};
	int getSum(){
		int res =0;
		for (int i = 1; i<= n; i++) for (int j = 1; j<= m; j++) (res+=a[i][j])%=p;
		return res;
	}
	matrix operator*(matrix other){
		matrix res = matrix(n,other.m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= other.m; j++) for (int k = 1; k <= m; k++) (res.a[i][j] += 1ll*a[i][k]*other.a[k][j]%p)%=p;
		return res;
	}
};
matrix getPow(matrix a, long long n){
	matrix res = matrix(a.n,a.m);
	res.setNum(1);
	while (n){
		if (n&1) res = res*a;
		a = a*a;
		n >>= 1;
	}
	return res;
}
int getPow(long long a, long long n){
	long long res = 1;
	while (n){
		if (n&1) res = res*a%p;
		a = a*a%p;
		n >>= 1;
	}
	return res;
}
int main(){
	long long n, c, f1, f2,f3;
	cin >> n >> f1 >> f2 >> f3 >> c;
//	cin >> n;
	//x = c^n*f(n)
	//tinh f1
	p--; //phi p
	matrix mat_f1 = matrix(3,3);
	mat_f1.a[1][1] = 1;
	matrix mat_f2 = matrix(3,3);
	mat_f2.a[1][2] = 1;
	matrix mat_f3 = matrix(3,3);
	mat_f3.a[1][3] = 1;
	matrix mat_c = matrix(3,3);
	mat_c.a[1][1] = 1; mat_c.a[1][2] = 2; mat_c.a[1][3] = 3;
	matrix base = matrix(3,3);
	base.a[1][1] = 0; base.a[1][2] = 0; base.a[1][3] = 1;
	base.a[2][1] = 1; base.a[2][2] = 0; base.a[2][3] = 1;
	base.a[3][1] = 0; base.a[3][2] = 1; base.a[3][3] = 1;
	base = getPow(base,n-3);
	long long int powf1 = (mat_f1*base).a[1][3];
	long long int powf2 = (mat_f2*base).a[1][3];
	long long int powf3 = (mat_f3*base).a[1][3];
	int powc = (mat_c*base).a[1][3];
	powc = (powc-n%p+p)%p;
//	cout << powf1 << " " << powf2 << " " << powf3 << " " << powc;
//	cout << (mat_c*base).a[1][3];
	p++;
	cout << 1ll*getPow(f1,powf1)*getPow(f2,powf2)%p*getPow(f3,powf3)%p*getPow(c,powc)%p;
	
	return 0;
}
