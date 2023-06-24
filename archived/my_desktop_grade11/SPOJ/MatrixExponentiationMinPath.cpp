#include <bits/stdc++.h>

using namespace std;
const long long int INF = 2e18 + 5;
int n, m, k;

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
	
	void setAll(long long int x){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = x;
			}
		}
	}
	
	long long int getMin(){
		long long int res = INF;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				res = min(res,a[i][j]);
			}
		}
		return res;
	}
	
	matrix operator*(matrix other){
		matrix product = matrix();
		product.setAll(INF);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					product.a[i][j] =  min(product.a[i][j],a[i][k]+other.a[k][j]);
				}
			}
		}
		return product;
	}
};

matrix AmuB(matrix x, int y){
	matrix product = matrix();
	product.setAll(INF);
	product.setNum(0);
	
	while (y > 0){
		if (y%2 == 1) product = product*x;
		y /= 2;
		x = x*x;
	}

	return product;
}


int main(){
	
	cin >> n >> m >> k;
	matrix mat = matrix();
	mat.setAll(INF);
	for (int i = 0; i < m; i++){
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		mat.a[a-1][b-1] = c;
	}
	long long int res = AmuB(mat,k).getMin();
	//<INF/2 4/50 ko biet sao luon
	if (res<=INF/2) cout << res; else cout << "IMPOSSIBLE";
	return 0;
}
