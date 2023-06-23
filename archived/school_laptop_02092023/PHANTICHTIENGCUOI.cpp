#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long

int pow31[100005], n, l, dp[100005], hashS[100005], res;
vector<int> len;
string s, t;
const int MOD = 1e9+7;
gp_hash_table<int,bool> mp;

int getHash(int i, int j){
	return (hashS[j]-hashS[i-1]*pow31[j-i+1]%MOD+30*MOD)%MOD;
}
main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	pow31[0] = 1;
	for (int i = 1; i <= 1e5; i++) pow31[i] = (pow31[i-1]*31)%MOD;
	cin >> n;
	cin >> s;
	l = s.length();
	s = "#" + s;
	for (int i = 1; i <= l; i++){
		hashS[i] = (hashS[i-1]*31+s[i]-'a'+1)%MOD;
	}	
	for (int i = 0; i < n; i++){
		cin >> t;
		len.push_back(t.length());
		int tmp = 0;
		for (int j = 0; j < t.length(); j++) tmp = (tmp*31+t[j]-'a'+1)%MOD;
		mp[tmp] = 1;
	}
	sort(len.begin(),len.end());
	len.erase(unique(len.begin(),len.end()),len.end());
	n = len.size();
	for (int i = 1; i <= l; i++){
		for (int j = 0; j < n; j++) if (i-len[j]+1>0&&mp[getHash(i-len[j]+1,i)]){
			dp[i] = max(dp[i],dp[i-len[j]]+len[j]);			
		}
		res = max(res,dp[i]);
	}
	cout << res;
	
	return 0;
}
