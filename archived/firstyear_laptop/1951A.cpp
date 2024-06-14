#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	int n;
	cin >> n >> s;
	vector<int> v;
	for (int i = 0;i <s.length(); i++) if (s[i]=='1') v.push_back(i);
	if (v.size()%2||v.size()==2&&v[0]==v[1]-1){
		cout << "NO" << "\n";
		return;
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

