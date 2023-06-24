//C++ 17

#include <bits/stdc++.h>

using namespace std;
int n, m, q, s, t, k; //10^9 < max_int
const int p = 1e9+7;
//struct Matrix{
//	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
//	
//	
//	Matrix operator*(Matrix& other){
//		vector<vector<int>> product(n, vector<int>(n));
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				for (int k = 0; k < n; k++){
//					product[i][j] = (product[i][j]+(long long int)a[i][k]*other.a[k][j])%p; 
//				}
//			}
//		}
//		Matrix retu{product};
//		return retu;
//	}
//};
struct Matrix {
	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
	Matrix operator *(const Matrix& other) {
		vector<vector<int>> product(n, vector<int>(n));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int k = 0; k < n; ++k) {
					product[i][k] = (product[i][k] + (long long) a[i][j] * other.a[j][k]) % p;
				}
			}
		}
		Matrix retu{product};
		return retu;
	}
};

int main() {
	scanf("%d%d%d", &n, &m, &q);
	Matrix base;
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		base.a[a-1][b-1]++;
	}
	vector<Matrix> powers{base};
	for(int i = 1; i <= 30; ++i) {
		powers.push_back(powers.back() * powers.back());
	}
	while(q--) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		a--;
		b--;
		vector<int> dp(n);
		dp[a]++;
		for(int bit = 0; (1 << bit) <= k; ++bit) {
			if(k & (1 << bit)) {
				vector<int> new_dp(n);
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {
						new_dp[j] = (new_dp[j] + (long long) dp[i] * powers[bit].a[i][j]) % p;
					}
				}
				dp = new_dp;
			}
		}
		printf("%d\n", dp[b]);
	}
}
