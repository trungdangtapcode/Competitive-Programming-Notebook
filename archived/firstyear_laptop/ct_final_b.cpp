#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, a[maxN], k;
string s;
void merge(){
	n = n/2;
	k -= 1;
	for (int i = 1; i <= n; i++){
		a[i] += a[i+n];
	}
}
void split(){
//	cout << "splited \n";
	for (int i = 1; i <= n; i++){
		a[i+n] = a[i];
		a[i] = 0;
	}
	n = 2*n;
	k += 1;
}
void solve(){
	for (int i = 1; i <= (1<<16); i++) a[i] = 0;
	cin >> k;
	n = (1<<k);
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	int peak = 0, last = 0;
	for (char c: s){
		int x = (c=='0'?1:-1);
		last += x;
		peak = max(last,peak);
	}
	for (int i = 0; i < peak; i++){
		merge();
	}
	for (int i = peak; i > last; i--){
		split();
	}
//	cout << peak << " " << last << "\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
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

