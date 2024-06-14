#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
typedef pair<int,int> ii;
int n, a[maxN], d[maxN], prv[maxN], nxt[maxN], die[maxN];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> d[i];
	die[0] = die[n+1] = 1;
	a[0] = d[0] = a[n+1] = d[n+1] = 0;
	vector<int> vec;
	for (int i = 1; i <= n; i++){
		prv[i] = i-1;
		nxt[i] = i+1;
		if (d[i]<a[prv[i]]+a[nxt[i]]) vec.push_back(i);
		die[i] = (d[i]<a[prv[i]]+a[nxt[i]]);
	}
	
	for (int r = 1; r <= n ; r++){
		cout << vec.size() << " ";
		vector<int> tmp;
		for (int x: vec){
			prv[nxt[x]] = prv[x];
			nxt[prv[x]] = nxt[x];
		}
		for (int x: vec){
			if (!die[nxt[x]]&&d[nxt[x]]<a[nxt[nxt[x]]]+a[prv[nxt[x]]]) tmp.push_back(nxt[x]), die[nxt[x]] = 1;
			if (!die[prv[x]]&&d[prv[x]]<a[nxt[prv[x]]]+a[prv[prv[x]]]) tmp.push_back(prv[x]), die[prv[x]] = 1;
		}
		vec = tmp;
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

