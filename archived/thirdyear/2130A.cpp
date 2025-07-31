#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	int s = 0;
	int c[] = {0,0};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i]>=2)
			s += a[i];
		else {
			c[a[i]]++;
		}
	}
	int b = min(c[0],c[1]);
	c[0] -= b;
	c[1] -= b;
	b *= 2;
	b += c[0]+c[1];
	cout << s + b<< "\n";
	
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

