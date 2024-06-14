#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], b[maxN], prv[maxN], nxt[maxN], f[maxN];
int ar[maxN], al[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		prv[i] = 0;
		nxt[i] = n+1;
		f[i] = 0;
	}
	deque<int> d1, d2;
	for (int i = n; i >= 1; i--){
		while (d2.size()&&a[d2.back()]<=a[i]) d2.pop_back();
		ar[i] = (d2.size()?d2.back():n+1);
		d2.push_back(i);
	} 
	for (int i = 1; i <= n; i++){
		prv[a[i]] = i;
		while (d1.size()&&b[d1.back()]>=b[i]) d1.pop_back();
//		cout << (d1.size()?d1.back():0) << " " << ar[prv[b[i]]] << " " << prv[b[i]] << "\n";
		if (prv[b[i]]&&(d1.size()?d1.back():0)<prv[b[i]]&&ar[prv[b[i]]]>i) 
			f[i] = 1;
//		cout << i << ". " << f[i] << "\n";
		d1.push_back(i);
	}
	d1.clear(); d2.clear();
	for (int i = 1; i <= n; i++){
		while (d2.size()&&a[d2.back()]<=a[i]) d2.pop_back();
		al[i] = (d2.size()?d2.back():0);
		d2.push_back(i);
	} 
	for (int i = n; i >= 1; i--){
		nxt[a[i]] = i;
		while (d1.size()&&b[d1.back()]>=b[i]) d1.pop_back();
//		cout << f[i] << " " << (d1.size()?d1.back():n+1) << " " << al[nxt[b[i]]] << " " << nxt[b[i]] << "\n";
		if (nxt[b[i]]<=n&&(d1.size()?d1.back():n+1)>nxt[b[i]]&&al[nxt[b[i]]]<i) 
			f[i] = 1;
//		cout << i << ". " << f[i] << "\n";
		d1.push_back(i);
		if (!f[i]){
			cout << "NO\n";
			return;
		}
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

//https://codeforces.com/contest/1904/submission/256896520

