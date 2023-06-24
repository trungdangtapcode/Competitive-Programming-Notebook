#include <bits/stdc++.h>

using namespace std;
bool prime[10005];
int dp[10005], new_dp[10005];
int n, a, m, c[5005], mnho, mlon;
const int p = 1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= 1e4; i++) if (prime[i]){
		for (int j = i*i; j <= 1e4; j += i) prime[j] = false;
	}
	int t; cin >> t;
	while (t--){
		memset(c,0,sizeof(c));
		cin >> n;
		mnho = 1e5; mlon = -1e5;
		for (int i = 0; i < n; i++) cin >> a, mnho = min(mnho,a), mlon = max(mlon,a), c[a]++;//, cout << bitset<13>(a) << " "; cout << endl;
		
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for (int i = mnho; i <= mlon; i++){
			memset(new_dp,0,sizeof(new_dp));
			for (int j = 0; j < 8192; j++){
				new_dp[j^i] += 1ll*dp[j]*((c[i]+1)/2)%p;
				new_dp[j] += 1ll*dp[j]*(c[i]/2+1)%p;
			}
			for (int j = 0; j < 8192; j++) dp[j] = new_dp[j]%p;
		}
		int res = 0;
		for (int j = 0; j < 8192; j++) res = (res+prime[j]*dp[j])%p;
		cout << res << '\n'; 
	}
	
//	for (int j = 0; j < 8192/2; j++) cout << bitset<13>(j) << " " << dp[j] << endl;
	return 0;
}
