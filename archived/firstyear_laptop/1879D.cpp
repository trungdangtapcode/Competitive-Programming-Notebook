#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5, mod = 998244353;
int n, a[maxN], ch[maxN][2], cnt[maxN][2];
int main(){
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < 30; i++) ch[i][0] = 1;
	for (int i = 1; i <= n; i++){
		a[i] ^= a[i-1];
		for (int j = 0; j < 30; j++){
			bool x = (1<<j)&a[i];
			(res += (1ll*i*ch[j][!x]%mod-cnt[j][!x])*(1<<j)%mod)%=mod;
		}
		for (int j = 0; j < 30; j++) (cnt[j][(bool)((1<<j)&a[i])] += i)%=mod, ch[j][(bool)((1<<j)&a[i])]++;
	}
	cout << (res+mod)%mod;
	
	return 0;
}
