#include<bits/stdc++.h>

using namespace std;
int cnt[10005], a, mmax = -1, resMax, resI, n;
int main(){
	
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		cnt[a]++;
		mmax = max(mmax,a);
	}
	for (int i = 0; i <= mmax; i++) if (resMax<cnt[i]) resMax = cnt[i], resI = i;
	cout << resI;
	
	return 0;
}
