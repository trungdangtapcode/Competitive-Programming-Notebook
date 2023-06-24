#include <bits/stdc++.h>

using namespace std;

int tinhS(int x){
	int res = 0;
	while (x != 0) res += (x%10)*(x%10), x/= 10;
	return res;
}
const int maxSRR = 9*9*50;
bool isSRR[maxSRR];
void doSoRoRang(){
	bool onWay[maxSRR];
	memset(isSRR,false,sizeof(isSRR));
	isSRR[1] = true;
	int pos = 0;
	for (int i = 2; i < 9*9*20; i++){
		//cout << i << " " << isSRR[i-1] << endl;
		memset(onWay,false,sizeof(onWay));
		pos = i;
		while (!onWay[pos]&&(pos>=i)){
			//if (i==2) cout << pos << endl;
			onWay[pos] = true;
			pos = tinhS(pos);
		}
		if (pos<i) isSRR[i] = isSRR[pos];
		if (onWay[pos]) isSRR[i] = false;
		//if (i==10) cout << isSRR[1] << endl;
	}
	return;
}

long long int n, m, result;
int sum;
int d[50];
bool bigger;
long long int dp[20][2][maxSRR]; //dp[i,bigger,sum] i vi tri cua n, 
//bigger la so dang sau co lon hon khong de tinh toan thoai mai hon (co the bat dau tu 0), neu = thi nhut dau vi so sanh nhu theo THU TU TU DIEN
//sum la tongS de sau khi ve toi isSRR co the check
//dp co nghia la so nghiem vi tri i co dang sau thoai mai ko va tong lai = sum

long long int getDP(int i, bool bigger, long long int sum){
	//cout << i << " " << bigger << " " << sum << " -> " << dp[i][bigger][sum]<< endl;
	if (i<0) return bigger&&isSRR[sum]; //must bigger if equal mean k-th = 0 chinh la so do (n)
	if (dp[i][bigger][sum] != -1) return dp[i][bigger][sum];
	long long int res = 0;
	for (int j = bigger?0:d[i]; j<=9; j++){
		res += getDP(i-1,bigger||(j>d[i]),sum+j*j);	
	}
	dp[i][bigger][sum] = res;
	return res;
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i<17; i++) d[i] = n%10, n/=10;
	
	memset(dp,-1,sizeof(dp));
	bigger = false;
	sum = 0;
	result = 0;
	long long int dem = 0;
	for (int i = 16; i >= 0; i--){
		for (int j = bigger?0:d[i]; j <= 9; j++){
			dem = getDP(i-1,bigger||(j>d[i]),sum+j*j);
			if (m>dem) m -= dem;
			else {
				result = result*10+j;
				bigger = bigger||(j>d[i]);
				sum += j*j;
				break;
			}
		}
	}
	cout << result << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	doSoRoRang();
	//cout << isSRR[68];
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
