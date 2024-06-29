#include<bits/stdc++.h>

using namespace std;
int l, r;
bool ask(int x){
	cout << x << endl;
	string s; cin >> s;
	return (s=="<");
}
void solve(){
	l = 1, r = 1e6;
	while (l<r){
		int m = (l+r+1)/2;
		bool isSmaller = ask(m);
		if (isSmaller){
			r = m-1;
		} else l = m;
	}
	cout << "! "<< l << endl;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
//	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

