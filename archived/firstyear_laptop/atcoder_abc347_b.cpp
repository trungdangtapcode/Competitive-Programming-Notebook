#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	set<string> st;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		for (int j = 1; i + j - 1 < s.length(); j++){
			st.insert(s.substr(i,j));
		}
	}
	cout << st.size();
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

