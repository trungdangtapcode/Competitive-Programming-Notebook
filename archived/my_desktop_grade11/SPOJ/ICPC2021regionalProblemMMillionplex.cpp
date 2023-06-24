#include <bits/stdc++.h>

using namespace std;
int f1[1000005], f2[1000005], n, res, a[1000005];
string s;
const int p = 1e9+7;
int main(){
	
	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'0';
	
	for (int i = 1; i <= n; ++i){
		f1[i] = (10ll*f1[i-1] + 1ll*a[i]*i)%p;
		f2[i] = (100ll*f2[i-1] + 20ll*f1[i-1]*a[i] + 1ll*a[i]*a[i]%p*i)%p;
		res = (res+f2[i])%p;
	}
	cout << res;
	
	
	return 0;
}
