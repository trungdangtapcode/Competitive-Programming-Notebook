#include <bits/stdc++.h>

using namespace std;
int n, t;
int p[4] = {2,3,5,7};
int dp[1000005];

bool check(int x){
	if (x==0||x==1) return false;
	for (int i = 2; i*i <= x; i++){
		if (x%i==0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i <= 1e5; i++) dp[i] = i;
	
	dp[0] = 0; 
	for (int i = 2; i <= 1e5; i++){
		//int x = 1;
		if (dp[i] == i) for (int j = i; j <= 1e5; j += i){
			dp[j]-= dp[j]/i;
			//x++;
			//if (j==90) cout << i <<" va " << x-1<< endl;
		}
	}
//	for (int i = 1; i <= 100; i++){
//		cout << i << " " << dp[i] << endl;
//	}
	
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		cout << (check(dp[n])?"TRUE":"FALSE") << '\n';
	}
	
	return 0;
}
