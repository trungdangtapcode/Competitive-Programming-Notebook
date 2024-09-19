#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
//	int pos = s.find('0');
//	if (pos==string::npos){
//		if (n>3) cout << "Yes\n";
//		return;
//	}
	int m = sqrt(n);
	if (m*m!=n){
		cout << "No\n";
		return; 
	}
	for (int i = 0; i < n; i++){
		int x = i%m, y = i/m;
		if (x!=0&&x!=m-1&&y!=0&&y!=m-1){
			if (s[i]=='1') return cout << "No\n",void();
		} else {
			if (s[i]=='0') return cout << "No\n",void();
		}
	}	cout << "Yes\n";
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

