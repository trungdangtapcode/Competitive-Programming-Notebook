#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e6+5;
int n, a[maxN], val[maxN], res[maxN];
void rs(){
	for (int i = 1; i <= 2*n; i++) val[i] = 0;
}
void updt(int x, int v = 1){
	for (; x <= 2*n; x += x&-x) val[x] += v;
}
int gett(int x){
	int res= 0;
	x = min(x,2*n);
	for (; x; x -= x&-x) res += val[x];
	return res;
}
void solve(){
//	multiset<int> ms;
//	ms.insert(0);
	cin >> n;
	string s; cin >> s;
	s = s + "#";
	int res = 0;
	for (int i = 1, last = -1; i <= n; i++){
		if (last==-1&&s[i-1]=='.') last = i;
		if (s[i-1]=='.'&&s[i]=='#'){
			if (i-last+1>2){
				cout << 2 << "\n";
				return;
			}
			res += min(2ll,i-last+1);
			last = -1;
			continue;
		}
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
