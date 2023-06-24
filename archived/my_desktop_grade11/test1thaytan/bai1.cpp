#include <bits/stdc++.h>
#define fix cout<<"fix"<<endl;
using namespace std;


int main(){
	string s;
	cin >> s;
	long int n = s.length();
	//cout << n;
	s = " " + s;
	long int a, b;
	cin >> b >> a;
	long int *sum0 = new long int[300005];
	long int *sum1 = new long int[300005];
	sum0[0] = 0;
	sum1[0] = 0;
	for (long int i = 1; i <= n; i++){
		if (s[i]=='0') {
			sum0[i] = sum0[i-1] + 1;
			sum1[i] = sum1[i-1];
		}
		if (s[i]=='1') {
			sum1[i] = sum1[i-1] + 1;
			sum0[i] = sum0[i-1];
		}
	}
	//cout << s << endl;
	//for (long int i = 1; i <= n; i++) cout << sum0[i] << " "; cout << endl;
	//for (long int i = 1; i <= n; i++) cout << sum1[i] << " "; cout << endl;
	long int result = 1e7;
	long int j = 1;
	for (long int i = 1; i <= n; i++){
		while (sum0[i] - sum0[j-1] >= a && sum1[i]-sum1[j-1] >= b){
			result = min(result,i-j+1);
			j++;
		}
	}
	if (result == 1e7) cout << -1; else cout << result;
	

	return 0;
	//memset(dp,-1,sizeof(dp));
	//cout << dp_set(0,n-1,0) - dp_set(0,n-1,1);
}	
