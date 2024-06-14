#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	set<char> st(s.begin(),s.end());
	string r(st.begin(),st.end());
	map<char,char> mp;
	for (int i = 0; i < r.length(); i++){
		int j = r.length()-1-i;
		mp[r[i]] = r[j];
	}
	for (char c: s) cout << mp[c];
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

