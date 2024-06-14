#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e6+5;
int a[maxN], n, q, fcnt[maxN], fsum[maxN][20];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	int thres = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
//		cout << bitset<4>(a[i]) << "\n";
		fcnt[a[i]]++;
		for (int j = 0; j < 20; j++)
			fsum[a[i]][j] += a[i]&((1<<j)-1);
		thres += (1<<20)-a[i];
	}
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < (1<<20); j++) if ((1<<i)&j){
			fcnt[j^(1<<i)] += fcnt[j];
			for (int k = 0; k < 20; k++) fsum[j^(1<<i)][k] += fsum[j][k];
		}
	}
	while (q--){
		int x;
		cin >> x;
		if (x>=thres){
			cout << (1<<20) + (x-thres)/n << "\n";
			continue;
		}
		int res = 0;
		for (int i = 19; i >= 0; i--){
			int tmp = (n-fcnt[res])*(1ll<<i);
			tmp += (fcnt[res]-fcnt[res|(1<<i)])*(1ll<<i) - (fsum[res][i]-fsum[res|(1<<i)][i]);
//			cout << i << ". " << (n-fcnt[res]) << " " << (fcnt[res]-fcnt[res|(1<<i)]) << " " << (fsum[res][i]-fsum[res|(1<<i)][i]) << " = " << tmp<< "\n";
			if (tmp>x) continue;
			x -= tmp;
			res |= (1<<i);
		}
		cout << res << "\n";
	}
//	cout << fcnt[2];
	
	return 0;
}
