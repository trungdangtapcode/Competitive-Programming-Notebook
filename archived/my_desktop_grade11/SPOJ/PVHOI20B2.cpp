#include <bits/stdc++.h>

using namespace std;
int n, l, r, d;
long long int p[15], dp[105][200005], cnt[1100005], mod = 998244353; //cnt[d+l]

long long int countCNT(int l, int r){
	long long int res = 1;
	for (int i = 0; i < n; i++){
		if (p[i]>r) return 0;
		
		long long int cur = cnt[r-p[i]];
		if (l-p[i]>0) cur = (cur - cnt[l-p[i]-1] + mod*mod)%mod;
		res = (res*cur)%mod;
	}
	
	return res;
}

int main(){
	
	cin >> n >> l >> r >> d;
	
	for (int i = 0; i <= 100000; i++) dp[0][i] = 1; //dp[0][0] = 1 => prefix dp
	for (int i = 1; i <= r; i++){
		for (int j = 0; j <= i*l; j++){
			dp[i][j] = dp[i-1][j];
			if (j>l) dp[i][j] = (dp[i][j] - dp[i-1][j-l-1]+mod*mod)%mod;
		}
		for (int j = 1; j <= 100000; j++){
			dp[i][j] = (dp[i][j-1]+dp[i][j])%mod;
		}
	}
	for (int i = 0; i <= 1100000; i++){
		if (i <= r*l){
			cnt[i] = dp[r][i];
		} else {
			cnt[i] = cnt[i-1];
		}
	}
	
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p,p+n);
	for (int i = n-1; i >= 0; i--) p[i] -= p[0];
	
	long long int res = 0;
	for (int i = 0; i <= l*r; i++){
		int l = i, r = i + d;
		long long int cur = (countCNT(l,r) - countCNT(l+1,r) + mod*mod)%mod;
		res = (res + cur)%mod;
	}
	cout << res << '\n';
	
	return 0;
}

//deo hieu sao o tren AC >:v
//p[] can be integer

//#include <bits/stdc++.h>
//
//using namespace std;
//int n, l, r, d, mod = 998244353;
//int p[15], dp[105][100005], cnt[1100005]; //cnt[d+l]
//
//int countCNT(int l, int r){
//	int res = 1;
//	for (int i = 0; i < n; i++){
//		if (p[i]>r) return 0;
//		
//		int cur = cnt[r-p[i]];
//		if (l-p[i]>0) cur = (cur - cnt[l-p[i]-1] + mod)%mod;
//		res = (res*cur)%mod;
//	}
//	
//	return res;
//}
//
//int main(){
//	
//	cin >> n >> l >> r >> d;
//	
//	for (int i = 0; i <= 100000; i++) dp[0][i] = 1; //dp[0][0] = 1 => prefix dp
//	for (int i = 1; i <= r; i++){
//		for (int j = 0; j <= i*l; j++){
//			dp[i][j] = dp[i-1][j];
//			if (j>l) dp[i][j] = (dp[i][j] - dp[i-1][j-l-1]+mod)%mod;
//		}
//		for (int j = 1; j <= 100000; j++){
//			dp[i][j] = (dp[i][j-1]+dp[i][j])%mod;
//		}
//	}
//	for (int i = 0; i <= 1100000; i++){
//		if (i <= r*l){
//			cnt[i] = dp[r][i];
//		} else {
//			cnt[i] = cnt[i-1];
//		}
//	}
//	
//	for (int i = 0; i < n; i++) cin >> p[i];
//	sort(p,p+n);
//	for (int i = n-1; i >= 0; i--) p[i] -= p[0];
//	for (int i = 0; i <= l*r+1; i++) cout << dp[r][i] <<" "; cout << endl;
//	
//	int res = 0;
//	for (int i = 0; i <= l*r; i++){
//		int l = i, r = i + d;
//		int cur = (countCNT(l,r) - countCNT(l+1,r) + mod)%mod;
//		res = (res + cur)%mod;
//	}
//	cout << res << '\n';
//	
//	return 0;
//}
