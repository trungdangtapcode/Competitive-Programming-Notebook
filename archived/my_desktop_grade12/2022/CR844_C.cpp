#include<bits/stdc++.h>

using namespace std;
typedef pair<int,char> ic;
int n, cnt[26];
vector<int> pos[26];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		for (int i = 0; i < 26; i++) pos[i].clear(), cnt[i] = 0;
		s = "$" + s;
		for (int i = 1; i <= n; i++){
			cnt[s[i]-'a']++;
			pos[s[i]-'a'].push_back(i);
		}
		vector<ic> v;
		for (int i = 0; i < 26; i++) v.push_back({cnt[i],i+'a'});
		sort(v.begin(),v.end());
		int res = 1e9, res_idx = 0;
		for (int i = 0; i < v.size(); i++) if (n%(v.size()-i)==0){
			queue<int> q;
			int cur = n/(v.size()-i);
			for (int j = 0; j < i; j++){
				for (auto it: pos[v[j].second-'a']) q.push(it);
			}
			for (int j = i; j < v.size(); j++){
				for (int k = 0; k < cnt[v[j].second-'a']-cur; k++) q.push(pos[v[j].second-'a'][k]);
			}
			if (res>q.size()) res = q.size(), res_idx = i;
		}
		queue<int> q;
		int cur = n/(v.size()-res_idx);
		for (int j = 0; j < res_idx; j++){
			for (auto it: pos[v[j].second-'a']) q.push(it);
		}
		for (int j = res_idx; j < v.size(); j++){
			for (int k = 0; k < cnt[v[j].second-'a']-cur; k++) q.push(pos[v[j].second-'a'][k]);
		}
		cout << q.size() << "\n";
		for (int j = res_idx; j < v.size(); j++){
			for (int k = 0; k < cur-cnt[v[j].second-'a']; k++) s[q.front()] = v[j].second, q.pop();
		}
		cout << s.substr(1,n) << "\n";
	}
	
	return 0;
}
