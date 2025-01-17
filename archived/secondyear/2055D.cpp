#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, k, l;
int a[maxN];
void solve(){
	cin >> n >> k >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int pos = (k)*2;
	int res = a[1]*2;
	for (int i = 2; i <= n; i++){
//		cout << pos*0.5 << " " << res*0.5 << "\n";
		if (a[i]*2<=pos){
			int x = min(pos,2*a[i]+res);
			pos = max(pos,x+2*k);
		} else {
			int t = (a[i]*2-pos);
//			cout << "t = " << a[i]*2-pos << " " << t << '\n';
			if  (t>res){
				int need = (t-res)/2; //need is in
//				cout << "need = " << need << "\n";
				pos += need;
				res += need;
				pos += k*2;
			} else {
				pos += k*2;
			}
		}
	}
	if (pos<=2*l){
		res += 2*l-pos;
	}
	cout << res << "\n";
	
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

