#include <bits/stdc++.h>

using namespace std;
int n, m, q, s, t, k; //10^9 < max_int
const int p = 1e9+7;
int dp[35][205];
struct matrix{
	int a[205][205];
	
	matrix(){ //maxtrix
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				a[i][j] = 0;
			}
		}
	}
	
	void setNum(int x){
		for (int i = 0; i < n; i++){
			a[i][i] = x; 
		}
	}
	
	int getSum(){
		int res = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				res += a[i][j];
			}
		}
		return res%p;
	}
	
	matrix operator*(matrix& other){
		matrix product = matrix();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					product.a[i][j] = (product.a[i][j] + (long long int)a[i][k]*other.a[k][j])%p;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> q;
	matrix mat = matrix();
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		mat.a[x-1][y-1] = 1;
	}
	
	vector<matrix> matrix2power(35);
	for (int i = 1; i <= 30; i++) matrix2power[i] = matrix();
	matrix2power[1] = mat;
	for (int i = 2; i <= 30; i++) matrix2power[i] = matrix2power[i-1]*matrix2power[i-1];
	
	while (q--){
		cin >> s >> t >> k;
		memset(dp,0,sizeof(dp));
		dp[0][s-1] = 1;
		int logK = 0;
		for (int bit = 0; (1<<bit) <= k; bit++){
			if (k&(1<<bit)){
				for (int i = 0; i < n; i++){
					for (int j = 0; j < n; j++){
						dp[bit+1][i] = (dp[bit+1][i]+(long long int)dp[bit][j]*matrix2power[bit+1].a[j][i])%p;
					}
				}
			} else {
				for (int i = 0; i < n; i++) dp[bit+1][i] = dp[bit][i];
			}
			logK = bit;
		}
		cout << dp[logK+1][t-1] << '\n';
	}
	
	
	
	
	return 0;
}

