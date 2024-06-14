#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+6;
int n, a[maxN], b[maxN], q;
int val[maxN];
void updt(int x, int y){
	for (; x <= n+q; x += x&-x) val[x] += y;
}
int gett(int x){
	int res =0;
	x= min(x,n+q);
	for (; x>0; x -= x&-x) res += val[x];
	return res;
}
void solve(){
	cin >> n >> q;
	vector<int> vec;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> b[i];
	for (int i = 1; i <= n; i++){
		vec.push_back(a[i]);
	}
	for (int i = 1; i <= q; i++){
		vec.push_back(b[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 1; i <= n; i++){
		int x = lower_bound(vec.begin(),vec.end(), a[i])-vec.begin()+1;
		updt(x,1);
//		cout << x << " ";
	}	
	for (int i = 1; i <= q; i++){
		int x = lower_bound(vec.begin(),vec.end(), b[i])-vec.begin()+1;
		cout << gett(x)+1 << "\n";
		updt(x,1);
	}	
	
//	for (int x: vec) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

