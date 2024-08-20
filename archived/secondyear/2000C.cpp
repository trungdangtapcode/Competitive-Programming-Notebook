#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<int> vec;
	for (auto it: mp) vec.push_back(it.second);
	sort(vec.begin(),vec.end());
	int q; cin >> q; //cout << q << "\n";
	for (int i = 1; i <= q; i++){
		string s; cin >> s;
		if (s.length()!=n){
			cout << "NO\n";
			continue;
		}
//		s = " " + s;
		map<int,int> mp;
		for (char c: s) mp[c]++;
		vector<int> vec2;
		for (auto it: mp) vec2.push_back(it.second);
		cout << (vec==vec2?"YES\n":"NO\n");
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

