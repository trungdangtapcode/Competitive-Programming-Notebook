#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	if (n==2){
		cout << stoi(s) << "\n";
		return;
	}
	
	int res = 1e9;
	for (int i = 1; i < n; i++){
		int sm = 0;
		for (int j = 0; j < i-1; j++){
			if (s[j]!='1') sm += s[j]-'0';
			if (s[j]=='0') return cout << 0 << "\n", void();
		}
		int tmp = ((s[i-1]-'0')*10+s[i]-'0');
		if (tmp!=1) sm += tmp;
		if (tmp==0){
			cout << 0 << "\n";
			return;
		}
		for (int j = i+1; j < n; j++){
			if (s[j]!='1') sm += s[j]-'0';
			if (s[j]=='0') return cout << 0 << "\n", void();
		}
		sm = max(sm,1);
		res = min(res,sm);
	}
	cout << res << "\n";
	
	return;
	if (n==3&&s[1]=='0'){
		cout << min(s[0],s[2]) << "\n";
	} else {
		for (int i = 0; i < n-0; i++){
			char c = s[i];
			if (c=='0'){
				cout << 0 << "\n";
				return;
			}
		}
	}
	int sm = 0;
	for (char c: s){
		if (c!='1') sm += c-'0';
	}
	res = 1e9;
	for (int i = 0; i < n-1; i++){
		res = min(res,sm+9*(s[i]-'0'));
	}
	cout << res << "\n";
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

