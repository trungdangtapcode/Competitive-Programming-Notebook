#include<bits/stdc++.h>

using namespace std;
string s;
string sli(string& s, int i, int j, bool rv = 0){
	string res = s.substr(i,j-i);
	if (rv) reverse(res.begin(),res.end());
	return res; 
}

void solve(){
	cin >> s;
	int n = s.length();
	if (s!=sli(s,0,n,1)){
		cout << "YES\n1\n" << s << "\n";
		return;
	}
	int idx = -1;
	for (int i = n-1; i >= 0; i--) if (s[i]!=s[n-1]){
		idx = i;
		break;
	}
	if (idx==-1) return cout << "NO\n", void();
	if (sli(s,0,idx)!=sli(s,0,idx,-1)){
		cout << "YES\n2\n" << sli(s,0,idx) << " " << sli(s,idx,n) << "\n";
		return;
	}
	if (idx==n-2||2*idx==n-1) return cout << "NO\n", void();
	cout << "YES\n2\n" << sli(s,0,idx-1) << " " << sli(s,idx-1,n) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

