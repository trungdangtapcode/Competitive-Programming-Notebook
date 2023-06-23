#include<bits/stdc++.h>

using namespace std;
int n, k, sum111[1005], dp[1005], new_dp[1005], inNum[10], f[1005][5], new_f[1005][5];
const int p = 1e9+7;

int calc(int x, int pos){
	return 1ll*pos*x%k*sum111[n-pos+1]%k;
}

int main(){
	freopen("TUPLE.INP","r",stdin);
	freopen("TUPLE.OUT","w",stdout);
	
	inNum[0] = inNum[1] = 1;
	for (int i = 2; i <= 6; i++) inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) sum111[i] = (sum111[i-1]*10+1)%k; 
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++) for (int num = (i==1); num < 8; num++) 
			new_dp[(j+calc(num,i))%k] += dp[j], new_dp[(j+calc(num,i))%k] %= p;
		for (int j = 0; j < k; j++) dp[j] = new_dp[j], new_dp[j] = 0;
	}	
	f[0][0] = 1;
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			new_f[j][0] += f[j][0]; new_f[j][1] += f[j][1]; new_f[j][2] += f[j][2]; new_f[j][3] += f[j][3];
			new_f[(j+i)%k][1] += 1ll*f[j][0]*dp[i]%p, new_f[(j+i)%k][1] %= p;
			new_f[(j+2*i)%k][2] += 1ll*f[j][0]*dp[i]%p*(dp[i]-1)%p*inNum[2]%p, new_f[(j+2*i)%k][2] %= p;
			new_f[(j+3*i)%k][3] += 1ll*f[j][0]*dp[i]%p*(dp[i]-1)%p*(dp[i]-2)%p*inNum[6]%p, new_f[(j+3*i)%k][3] %= p;
			new_f[(j+i)%k][2] += 1ll*f[j][1]*dp[i]%p, new_f[(j+i)%k][2] %= p;
			new_f[(j+2*i)%k][3] += 1ll*f[j][1]*dp[i]%p*(dp[i]-1)%p*inNum[2]%p, new_f[(j+2*i)%k][3] %= p;
			new_f[(j+i)%k][3] += 1ll*f[j][2]*dp[i]%p, new_f[(j+i)%k][3] %= p;
		}
//		cout << i << ": \n";
//		for (int j = 0; j < k; j++) cout << new_f[j][0] << " " << new_f[j][1] << " " << new_f[j][2] << " " << new_f[j][3] << endl; 
		for (int j = 0; j < k; j++) 
			f[j][0] = new_f[j][0], f[j][1] = new_f[j][1], f[j][2] = new_f[j][2], f[j][3] = new_f[j][3],
			new_f[j][0] = new_f[j][1] = new_f[j][2] = new_f[j][3] = 0;
	}
	cout << f[0][3];
	
	return 0;
}
