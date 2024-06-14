#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, m;
ii a[maxN];
vector<int> vec;
int val[maxN];
void rs(){
	for (int i = 1; i <= n; i++) val[i] = -1e9;
}
void updt(int x, int v){
	for (; x <= n; x+=x&-x) val[x] = max(val[x],v);
}
int gett(int x){
	int res = -1e9;
	for (; x > 0; x-= x&-x) res = max(val[x],res);
	return res;
}
int solve0(vector<ii> a){
	vec.clear();
	rs();
	int res0 = 0;
	for (int i = 0; i < n; i++){
		vec.push_back(a[i].second);
		res0 += abs(abs(a[i].first)-abs(a[i].second));
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	sort(a.begin(),a.end());
	int res = res0;
	for (int i = 0; i < n; i++){
		int x = a[i].first, y = a[i].second;
		int yy = lower_bound(vec.begin(),vec.end(),y)-vec.begin()+1;
		int tmp = gett(yy);
//		cout << tmp << "\n";
		res = max(res,res0-abs(abs(x)-abs(y))+x+y+tmp);
		updt(yy,-(x+y)-abs(abs(x)-abs(y)));
	}	
	return res;
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i-1].first;
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i-1].second;
	}
	vector<ii> b(n);
	for (int i = 0; i < n; i++) b[i] = a[i];
	int res =-1e9;
	res = max(res,solve0(b));
	for (int c = 0; c< 4; c++){
		for (int i =0 ; i < n; i++){
			b[i].first = -a[i].second;
			b[i].second = a[i].first;
			a[i] = b[i];
//		res = max(res,solve0(b));
		}
		res = max(res,solve0(b));
//		for (auto it: b) cout << it.first << ", " << it.second << "\n";
//		cout << solve0(b) << ' ' << c << "\n";
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
