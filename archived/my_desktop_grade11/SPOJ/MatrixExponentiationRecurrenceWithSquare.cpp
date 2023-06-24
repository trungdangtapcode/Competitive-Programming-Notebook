#include <bits/stdc++.h>

using namespace std;
const long long int p = 1e9+7;
long long int n, k, r1, r2, r3;

struct matrix{
	long long int a[15][15];
	int n, m;
	
	matrix(int n, int m){ //maxtrix
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				a[i][j] = 0;
			}
		}
		this->n = n;
		this->m = m;
	}
	
	void setNum(long long int x){
		for (int i = 0; i < n; i++){
			a[i][i] = x%p; 
		}
	}
	
	matrix operator*(matrix other){
		matrix product = matrix(n,other.m);
		for (int i = 0; i < product.n; i++){
			for (int j = 0; j < product.m; j++){
				for (int k = 0; k < m; k++){ //m = other.n
					product.a[i][j] = (product.a[i][j] + a[i][k]*other.a[k][j])%p; //cout << i << " " << j << " " << product.a[i][j] << '\n';
				}
			}
		}
//		cout << product.a[0][2] << '\n';
		return product;
	}
};

matrix AmuB(matrix x, int y){
	matrix product = matrix(x.n,x.m);
	product.setNum(1);
	
	while (y > 0){
		if (y%2 == 1) product = product*x;
		y /= 2;
		x = x*x;
	}

	return product;
}

long long int f(long long int x){
	x %= p; r1 %= p; r2 %= p; r3 %= p;
	long long int nni[10];
	nni[0] = nni[1] = 1;
	for (int i = 2; i < 10; i++) nni[i] = nni[p%i]*(p-p/i)%p;
	return (x*r1+x*(x+1)*nni[2]%p*r2+x*(x+1)%p*(2*x+1)*nni[6]%p*r3)%p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	r1 = r2 = r3 = 1;
//	cout << f(10000000000000);
	cin >> n >> k;
	matrix mat = matrix(n,n);
	matrix coso = matrix(1,n);
	for (int i = 0; i < n; i++) cin >> coso.a[0][i]; //a[]
	for (int i = 0; i < n; i++) cin >> mat.a[n-1-i][n-1]; //c[]
	for (int i = 0; i < n-1; i++) mat.a[i+1][i] = 1;
	cin >> r1 >> r2 >> r3;
	if (k>=n){
		cout << ((coso*AmuB(mat,k-n+1)).a[0][n-1]+f(k-n+1))%p << '\n';
	} else cout << coso.a[0][k] << '\n';


//	cout << (coso*mat*mat*mat).a[0][2];

//	matrix mat1 = matrix(2,3);
//	matrix mat2 = matrix(3,2);
//	mat1.a[0][0] = mat1.a[1][2] = mat2.a[0][0] = mat2.a[0][1] = mat2.a[2][0] = mat2.a[2][1] = 2;
//	mat1.a[0][1] = mat1.a[0][2] = mat1.a[1][0] = mat1.a[1][1] = mat2.a[1][0] = mat2.a[1][1] = 3;
//	cout << (mat1*mat2).a[0][0];
	return 0;
}
