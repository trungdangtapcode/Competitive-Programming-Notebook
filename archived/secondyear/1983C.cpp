#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, arr[3][maxN], pref[maxN], suff[maxN];
void solve(){
	int p[] = {0,1,2};
	cin >> n;
	for (int idx = 0; idx < 3; idx++) for (int i = 1; i <= n; i++){
		cin >> arr[idx][i];
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) tot += arr[0][i];
	do {
		int* a = arr[p[0]], *b = arr[p[1]], *c = arr[p[2]];
//		int ip[] = {-1,-1,-1}; 
		int resl[] = {-1,-1,-1}; 
		int resr[] = {-1,-1,-1}; 
//		for (int i = 0; i < 3; i++) ip[p[i]] = i;
		pref[0] = 0; suff[n+1] = 0;
		for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+a[i];
		for (int i = n; i >= 1; i--) suff[i] = suff[i+1]+c[i];
		int sum = 0;
		for (int i = 1, j = 0; i <= n; i++){
			while (j<n&&sum<(tot+2)/3){
				sum += b[++j];
			}
			if (sum>=(tot+2)/3){
				if (pref[i-1]>=(tot+2)/3&&suff[j+1]>=(tot+2)/3){
					resl[p[0]] = 1; resr[p[0]] = i-1;
					resl[p[1]] = i; resr[p[1]] = j;
					resl[p[2]] = j+1; resr[p[2]] = n;
					for (int ri = 0; ri < 3; ri++) cout << resl[ri] << " " << resr[ri] << " ";
					cout << "\n";
					return;
				}
			}
			sum -= b[i];
		}
	} while (next_permutation(p,p+3));;
	cout << "-1\n";
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

