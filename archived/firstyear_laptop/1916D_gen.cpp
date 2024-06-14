#include<bits/stdc++.h>

using namespace std;
void solve(){
	int n; cin >> n;
    map<string,vector<int>> mp;
	for (int i = 1; i <= 10000; i++){
	    string s = to_string(i*i);
	    sort(s.begin(),s.end());
	    if (s.length()==n) mp[s].push_back(i);
	}
	for (auto it: mp){
		if (it.second.size()<n) continue;
	    cout << it.first << ": ";
	    for (auto x: it.second){
	        cout << x*x << "(" << x << ")  ";
	    }
	    cout << "\n";
	}
}

main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
// 	int t; cin >> t;
// 	while (t--)
	solve();
	
	return 0;
}
