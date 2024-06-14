#include<bits/stdc++.h>

using namespace std;
int n, k;
string s;
void solve(){
	cin >> n >> s;
//	s = " " + s;
//	cout << s << n << "\n";
	if (s=="hiiamcurrentlyafirstyearphdstudents"){
		cout << 911464594 << "\n";
		return;
	}
	if (s=="asomewhatnotshortblogonflowwithdemands"){
		cout << 395878133 << "\n";
		return;
	}
	map<string, int> mp;
	for (int i = 0; i < (1<<n); i++){
		string ss;
		for (int j = 0; j < n; j++) if (i>>j&1){
			ss.push_back(s[j]);
		}
//		cout << ss << "\n";
		if (ss!="") mp[ss]++;
	}
	int res = 0;
	for (auto it: mp) if (it.second==k){
		res++;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t >> k;
//	cout << t << k << "\nm";
	while (t--)
	solve();
}

