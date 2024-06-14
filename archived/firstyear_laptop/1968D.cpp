#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, m, a[maxN], p[maxN], t[maxN], k, b, s;

int play(int x){
	int res = 0, sum = 0;
	int cnt = k;
	set<int> s;
	while (cnt>0){
		res = max(res,sum + cnt*a[x]);
		sum += a[x];
		cnt--;
		x = p[x];
		if (s.count(x)) break;
		s.insert(x);
	}
	return res;
}
void solve(){
	cin >> n >> k >> b >> s;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int rb = play(b), rs = play(s);
	cout << (rb==rs?"Draw":rb>rs?"Bodya":"Sasha") << "\n";	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
//https://pastebin.pl/view/5766e721
//https://pastebin.pl/view/b51ea48a

