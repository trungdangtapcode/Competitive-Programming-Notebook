/*
i => k/(2*i)*i + min(k mod (2*i) + 1, i)
o lai che de a =))
i => (k mod (2*i) >= i)
k/i = 2*n + 1 (so le)
*/

#include<bits/stdc++.h>

using namespace std;
int k;

int calc(int i){
	if (i%2==0) return 0;
	int x = k/i, y = k/(i+1)+1;
	if (y>x) return 0;
//	cout << i << " " << x << " " << y << "\n";
	return x-y+1;
}

void solve(){
	
	cin >> k;
	int res = 0;
//	int res1 = 0;
//	for (int i = 1; i <= 1e2; i++){
//		res1 += (k%(2*i)>=i);
//		cout << i << " " << (k%(2*i)>=i) << "\n";
//	}
//	cout << res1 << "\n";
	for (int i = 1; i*i <= k; i++){
		res += calc(i) + calc(k/i);
		if (i==k/i) res -= calc(i);
//		cout << i << " " << x << ".." << y << "\n"; 
	}
	cout << res << "\n"; 
	
//	for (int i = 1; i <= k; i++) calc(i);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
