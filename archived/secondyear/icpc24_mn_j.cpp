#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 5;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)

int pref[26*2+5], n, mask[26*2+6];
char dict[26*2+5];
map<char,int> inv_dict;
string s;
const int base = 31, modhash = (1ll<<51)-1, modres = 1e9+7;
int gethash(){
	int fi = 0;
	for (int i = 0; i < 26*2; i++) if (mask[i]){
		fi = i;
		break;
	}
	int res = 0;
	for (int i = 0; i < 26*2; i++){
		int cur = pref[i]-pref[fi]+1;
		if (mask[i]==0) cur = 0;
		res = (res*base+cur)%modhash;
	}
	return res;
}

void solve(){
	cin >> n >> s;
	s = " " + s;
	for (int i = 0; i < 26; i++) dict[i] = 'a'+i;
	for (int i = 0; i < 26; i++) dict[i+26] = 'A'+i;
	for (int i = 0; i < 26*2; i++) inv_dict[dict[i]] = i;	
	for (int i = 0; i < 26*2; i++){
		if (s.find(dict[i])==string::npos) continue;
		mask[i] = 1;
	}
	map<int,int> mp;
	mp[gethash()] = 1;
	int res = 0;
	for (int i = 1; i <= n; i++){
		pref[inv_dict[s[i]]]++;
//		for (int i = 0; i < 5; i++) cout << pref[i] << " "; cout << "\n";
//		for (int i = 0; i < 5; i++) cout << pref[i]-pref[0] << " "; cout << "\n";
		int cur = gethash();
		if (mp.count(cur)) res += mp[cur];
//		cout << mp[cur] << "\n";
		mp[cur]++;
	} 
	cout << res%modres << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif

	int tc = 1;
//	cin >> tc;
	while(tc--){
		solve();
	}

}



