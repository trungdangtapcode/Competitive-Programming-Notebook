#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e4;
int val[maxN+5];
void updt(int x, int y){
	for (; x <= maxN; x+=x&-x) val[x] = max(val[x],y);
}
int gett(int x){
	int res = 0;
	for (; x; x -= x&-x) res = max(res, val[x]);
	return res;
}
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int n;
iii a[maxN+5];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;
	}
	sort(a+1,a+n+1);
	int res = 0;
	for (int i = 1; i <= n; i++){
//		cout << a[i].first.first << " "  << a[i].first.second << " " <<a[i].second << "\n";
		int f = gett(a[i].first.second)+a[i].second;
		res = max(res,f);
		updt(a[i].first.second,f);
	}
	cout << res << "\n";
}


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	solve();
}

