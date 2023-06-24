#include <bits/stdc++.h>

using namespace std;
int n, a;
int cnt[10000005], cntMax[10000005]; //thuc ra co the toi uu
//sqrt(10^7)
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a==0) {
			cout << "impossible" << '\n';
			return 0;
		}
		for (int j = 2; j*j <= a; j++){
			int dem = 0;
			while (a%j==0) cnt[j]++, a/=j, dem++; //
			cntMax[j] = max(cntMax[j],dem);
		}
		if (a!=1) cnt[a]++, cntMax[a] = max(cntMax[a],1);
	}
//	int maxCnt = *max_element(cnt,cnt+1e7+1);
	long long int res = 1;
	for (int i = 2; i <= 1e7; i++){
		for (int j = 0; j < cnt[i]-cntMax[i]; j++) res *= i;
	}
	if (n!=0) cout << res << '\n'; //n ko am lua vc =))
	else cout << "impossible" << '\n';
	
	
	return 0;
}
