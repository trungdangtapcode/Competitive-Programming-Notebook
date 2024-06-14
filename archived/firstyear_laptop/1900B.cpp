#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e6+5;
int n, a, b, c;
int calc(int a, int b, int c){
	if (b>c) swap(b,c);
	a += b, c -= b; b -= b;
	return c%2==0;
}
void solve(){
//	multiset<int> ms;
//	ms.insert(0);
	cin >>a >> b >> c;
	cout << calc(a,b,c) << " " << calc(b,c,a) << " " << calc(c,b,a) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
