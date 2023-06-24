#include <bits/stdc++.h>

using namespace std;
int n, x;
long long int dp[10000000];
bool appeared[1000000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	memset(appeared,false,sizeof(appeared));
	//appeared[0] = true;
	
	cin >> x>> n;
	for (int i = 1; i<= n; i++){
		long long int a;
		cin >> a;
		if (appeared[a]) continue;
		appeared[a] = true;
		for (int j = a; j<= x; j++){ //j+=a
			dp[j] += dp[j-a];
		}
	}
	//for (int i = 0; i<= x; i++) cout << dp[i] << " ";
	cout << dp[x];
	
	return 0;
}
