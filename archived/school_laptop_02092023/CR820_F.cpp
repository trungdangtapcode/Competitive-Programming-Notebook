#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, w, m, pref[200005], l, r, k, mp[10][2], pow10[200005];
string s;

int f(int i, int j){
	return ((pref[j]-pref[i-1]*pow10[j-i+1])%9+9)%9;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	pow10[0] = 1;
	for (int i = 1; i <= 2e5; i++) pow10[i] = 10*pow10[i-1]%9;
	
	int t; cin >> t;
	while (t--){
		cin >> s >> w >> m;
		n = s.length();
		s = "#" + s;
	//	suff[n+1] = 0;
	//	for (int i = n; i >= 1; i--) suff[i] = (suff[i+1]*10 + s[i] - '0')%9;
	//	for (int i = 0; i <= 8; i++) mp[i] = -1;
	//	for (int i = n; i >= w; i--) mp[((suff[i-w+1]-suff[i+1]*pow10[w])%9+9)%9] = i-w+1;
		pref[0] = 0;
		for (int i = 1; i <= n; i++) pref[i] = (pref[i-1]*10 + s[i] - '0')%9;
		for (int i = 0; i <= 8; i++) mp[i][0] = mp[i][1] = -1;
		for (int i = n-w+1; i >= 1; i--){
			mp[f(i,i+w-1)][1] = mp[f(i,i+w-1)][0];
			mp[f(i,i+w-1)][0] = i;
		}
		while (m--){
			cin >> l >> r >> k;
			int x = (f(l,r));
			pair<int,int> ans = {1e9,1e9};
			for (int i = 0; i < 9; i++) if (mp[i][0]!=-1){
				int j = ((k-x*i)%9+9)%9;
				if (mp[j][0]!=-1){
	//				ans1 = mp[i], ans2 = mp[((k-x*i)%9+9)%9];
					if (j!=i) ans = min(ans,{mp[i][0],mp[j][0]});
					else if (mp[i][1]!=-1) ans = min(ans,{mp[i][0],mp[i][1]});
//					cout << i << "*" << x << " + " << ((k-x*i)%9+9)%9 << "\n";
				}
			}
			cout << (ans.first==1e9?-1:ans.first) << " " << (ans.second==1e9?-1:ans.second) << "\n";
		}
	}
	
	return 0;
}
