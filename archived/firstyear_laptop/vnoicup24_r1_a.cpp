#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	long long cnt2 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++){
		int a; cin >> a;
		if (a>1) cnt2++, a-= 2;
		cnt1 += a;
	}
	cout << cnt2/2 + cnt1/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}
