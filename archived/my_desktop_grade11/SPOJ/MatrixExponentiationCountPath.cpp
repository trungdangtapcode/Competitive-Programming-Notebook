#include <bits/stdc++.h>

using namespace std;
int n, m, k;
long long int p = 1e9+7;
struct matrix{
	long long int a[105][105];
	
	matrix(){ //maxtrix
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
	}
	
	void setNum(long long int x){
		for (int i = 0; i < n; i++){
			a[i][i] = x; 
		}
	}
	
	long long int getSum(){
		long long int res = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				res += a[i][j];
			}
		}
		return res%p;
	}
	
	matrix operator*(matrix other){
		matrix product = matrix();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					product.a[i][j] += a[i][k]*other.a[k][j]%p;
					product.a[i][j] %= p; 
				}
			}
		}
		return product;
	}
};

matrix AmuB(matrix x, int y){
	matrix product = matrix();
	product.setNum(1);
	
	while (y > 0){
		if (y%2 == 1) product = product*x;
		y /= 2;
		x = x*x;
	}

	return product;
}

int main(){
	
//	n = 3;
//	matrix m = matrix();
//	m.a[0][0] = m.a[1][0] = m.a[2][2] = 1;
//	m.a[0][1] = m.a[1][1] = m.a[2][1] = 2;
//	m.a[0][2] = m.a[1][2] = m.a[2][0] = 3;
	//cin >> n;
	//cout << (m*m).a[2][2];
	cin >> n >> m >> k;
	matrix mat = matrix();
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		mat.a[x-1][y-1] = 1;
	}
//	matrix product = matrix();
//	product.setNum(1);
//	for (int i = 1; i <= k; i++){
//		product = product*mat;
//	}
	cout << AmuB(mat,k).getSum();
	
	
	return 0;
}
