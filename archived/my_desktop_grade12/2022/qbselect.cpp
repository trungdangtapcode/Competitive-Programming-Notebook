#include<bits/stdc++.h>

using namespace std;
int f[10005][16], a[10005][4], res = -1e9, n;

int main(){
	cin >> n;
	for (int row = 0; row < 4; row++) for (int i = 1; i <= n; i++){
		cin >> a[i][row];
//		res = max(res,a[i][row]);
		for (int mask = 0; mask < (1<<4); mask++) f[i][mask] = -1e9;
	}
	for (int i = 1; i <= n; i++){
		for (int mask1 = 0; mask1 < (1<<4); mask1++) for (int mask2 = 0; mask2 < (1<<4); mask2++){
			bool ok = !(mask1&mask2);
			for (int j = 0; j < 3; j++) if ((mask1&(3<<j))==(3<<j)) ok = false;
			for (int j = 0; j < 3; j++) if ((mask2&(3<<j))==(3<<j)) ok = false;
			int curr = 0;
			for (int j = 0; j < 4; j++) if (mask1&(1<<j)) curr += a[i][j];
//			if (ok) cout << bitset<4>(mask1) << " " << bitset<4>(mask2) << endl;
			if (ok) f[i][mask1] = max(f[i][mask1],f[i-1][mask2]+curr);
			if (mask1!=0) res = max(res,f[i][mask1]);
		}
	}
	cout << res;
	
	
	return 0;
}
