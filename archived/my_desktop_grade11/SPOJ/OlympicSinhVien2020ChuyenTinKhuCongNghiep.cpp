#include <bits/stdc++.h>

using namespace std;

long long int n;
const long long int mod = 998244353;// mod =10000000 ;1000000000// 
map <long long int, long long int> dp;

long long int get_DP(long long int x){
	//cout << x << endl;
	if (x<=2) return 1;
	if (dp[x]!=0) return dp[x];
	long long int t = x/2;
	//cout << " -"<< x << endl;
	if (x%2==0){
		dp[x] = get_DP(t)%mod*(2*get_DP(t+1)%mod-get_DP(t)%mod)%mod;
		dp[x] = (dp[x] + mod)%mod; //for negative
		//cout << x <<"  " << dp[x] << endl;
		return dp[x];
	}
	if (x%2==1){
		dp[x] = (get_DP(t+1)%mod*get_DP(t+1)%mod + get_DP(t)%mod*get_DP(t)%mod)%mod;
		//cout << x << " "<< dp[x] << endl;
		return dp[x];
	}
}

int main(){
	cin >> n;
	
	//cout << get_DP(n);
	//for (int i = 1; i < n; i++) cout << get_DP(i+1)*get_DP(i)%mod << endl;
	cout << get_DP(n+2)*get_DP(n+1)%mod << endl; //quen mod :)))
	
	return 0;
}
