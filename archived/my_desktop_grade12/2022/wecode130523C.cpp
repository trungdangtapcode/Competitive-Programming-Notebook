#include<bits/stdc++.h>

using namespace std;
string s;
int cnt[30], fact[100005], inv[100005];
const int mod = 1e9+7;
int main(){
	cin >> s;
	for (char c: s) cnt[c-'a']++;
	for (int i = 0, ch = 0; i < 'z'-'a'; i++){
		if (cnt[i]%2){
			if (ch) return cout << 0, 0;
			ch = 1;
		}
	}
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 1e5; i++){
		fact[i] = 1ll*fact[i-1]*i%mod;
		inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
	}
	for (int i = 2; i <= 1e5; i++) inv[i] = 1ll*inv[i-1]*inv[i]%mod;
	int res = fact[s.length()/2];
	for (int i = 0; i < 'z'-'a'; i++){
		res = 1ll*res*inv[cnt[i]/2]%mod;
	}
	cout << res;
	
	return 0;
}
