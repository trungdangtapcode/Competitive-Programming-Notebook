#include <bits/stdc++.h>

using namespace std;

struct matrix{
	double a[2][2];
	int n = 2;
	
	matrix(){ //maxtrix
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
	}
	
	void setNum(double x){
		for (int i = 0; i < n; i++){
			a[i][i] = x; 
		}
	}
	
//	long long int getSum(){
//		long long int res = 0;
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				res += a[i][j];
//			}
//		}
//		return res;
//	}
	
	matrix operator*(matrix& other){
		matrix product = matrix();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					product.a[i][j] += a[i][k]*other.a[k][j];
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

double p;
int n;
int main(){
	
	cin >> n >> p;
	matrix mat = matrix();
	mat.a[0][0] = 1-p;
	mat.a[1][0] = p;
	mat.a[0][1] = p;
	mat.a[1][1] = 1-p;
	matrix base = matrix();
	base.a[0][0] = 1;
	cout << fixed << setprecision(7) <<(AmuB(mat,n)*base).a[0][0];
	
	return 0;
}
