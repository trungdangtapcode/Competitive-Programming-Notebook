#include<bits/stdc++.h>

using namespace std;

int n;
string s;
vector<int> a;
vector<char> p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		p.assign(55,'#');
		for (int i = 0; i < n; i++) cin >> a[i];
		bool res = true;
		cin >> s;
		for (int i = 0; i < n; i++){
			char c = s[i];
			if (p[a[i]]=='#') p[a[i]] = c;
			if (p[a[i]]!=c) res = false;
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
