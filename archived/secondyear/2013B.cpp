#include<bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
int n, a;
void solve(){
//	int i;
//	for (i = 0; i < 2; i++){
//		fork();
//		printf("hello\n");
//	}
	cin >> n;
	long long s = 0;
	for (int i = 1; i <= n-2; i++){
		cin >> a;
		s += a;
	} 
	cin >> a;
	s -= a;
	cin >> a;
	cout << s+a << "\n";
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

