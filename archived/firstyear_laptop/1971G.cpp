#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n;
typedef pair<int,int> ii;
int a[maxN];
vector<int> vec[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
//		a[i].second = i;
	}
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		if (!mp.count(a[i]/4)){
			mp[a[i]/4] = mp.size()+1;
			vec[mp[a[i]/4]].clear();
		}
		int idx = mp[a[i]/4];
		vec[idx].push_back(i);
	}
	for (auto &it: mp){
		vector<int> tmp = vec[it.second]; 
		sort(vec[it.second].begin(),vec[it.second].end(),[&](int i, int j){
			return a[i] < a[j];
		});
		for (int i = 0; i < tmp.size(); i++) vec[it.second][i] = a[vec[it.second][i]];
//		for (int i: tmp) cout << i << " "; cout << "\n";
		for (int i = 0; i < tmp.size(); i++) a[tmp[i]] = vec[it.second][i];
//		sort(it.second.begin(),it.second.end());
	}
//	for (int i = 1; i <= n; i++) cout << a[i].first << " ";
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

