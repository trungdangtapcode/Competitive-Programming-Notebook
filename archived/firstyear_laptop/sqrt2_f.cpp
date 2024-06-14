#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5, maxNs = (int)sqrt(maxN);
bitset<maxN> sb[maxNs];
set<int> s[maxN];
int n, m, q, cnt[maxN][maxNs], isBig[maxN], pos2big[maxN], nb;
long long lazyBig[maxNs], addedBig[maxNs], a[maxN];
vector<int> biglist;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++){
		int l; cin >> l;
		if (l>sqrt(maxN)){
			isBig[i] = 1;
			biglist.push_back(i);
			pos2big[i] = ++nb;
		}
		for (int j = 0; j < l; j++){
			int x; cin >> x;
			s[i].insert(x);
			if (isBig[i]){
				sb[nb][x] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++){
		for (int j: s[i]){
			for (int k: biglist){
				int kk = pos2big[k];
				cnt[i][kk] += sb[kk][j];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j: biglist){
			int jj = pos2big[j];
			if (!sb[jj][i]) continue;
			lazyBig[jj] += a[i];
		}
//		a[i] = 0;
	}
	
//	cout << "Big: "; for (int x: biglist) cout << x << " "; cout << "\n";
//	for (int i = 1; i <= m; i++){
//		cout << i << ": "; for (int x: biglist) cout << cnt[i][pos2big[x]] << " "; cout << "\n";
//	}
	if (nb>=maxNs) while (1);
	
	while (q--){
		char c;
		int k;
		long long x;
		cin >> c;
		if (c=='+'){
			cin >> k >> x;
			if (isBig[k]){
				int kk = pos2big[k];
				addedBig[kk] += x;
			} else {
				for (int p: s[k]){
					a[p] += x;
				}
			}
			for (int i: biglist){
				int ii = pos2big[i];
				lazyBig[ii] += x*cnt[k][ii];
			}
		} else {
			cin >> k;
			if (isBig[k]){
				int kk = pos2big[k];
				cout << lazyBig[kk] << "\n";
			} else {
				long long sum = 0;
				for (int i: s[k]) sum += a[i];
				for (int i: biglist){
					int ii = pos2big[i];
					sum += addedBig[ii]*cnt[k][ii];
				}
				cout << sum << "\n";
			}
		}
	}
	
	
	return 0;
}

//https://pastebin.com/PBD3Nqxy
