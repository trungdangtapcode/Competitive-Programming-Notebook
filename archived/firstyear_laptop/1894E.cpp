#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int m, a[maxN], b[maxN];
void solve(){
	cin >> m;
	set<int> st;
	map<int,int> minA, maxB, removeB;
	int ll = 0, rr = 0;
	for (int i = 1; i <= m; i++){
		int n, l, r, sum = 0;
		cin >> n >> l >> r;
		ll += l;
		rr += r;
		for (int j = 1; j <= n; j++) cin >> a[j];
		for (int j = 1; j <= n; j++){
			cin >> b[j];
			sum += b[j];
			st.insert(a[j]);
		};
		for (int j = 1; j <= n; j++){ //A is a[j], B is not a[j]
			minA[a[j]] += max((int)0,l-sum+b[j]); // >= l
			maxB[a[j]] += min(r,sum-b[j]); // <= r
			removeB[a[j]] += r; 
			//a[j] is in this set and was counted on maxB so rr-removeB[a[j]] left
		}
	}
	if (st.size()<rr-ll+1){
		cout << 0 << "\n";
		return;
	}
	int res = 1e18;
	for (int i = ll; i <= rr; i++){
//		cout << i << " = "<< minA[i] << " " << rr-removeB[i]+maxB[i] << "\n";
		res = min(res,max((int)0,i-minA[i]-(rr-removeB[i]+maxB[i]))+minA[i]);
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
