//dmmmmmmmmmmcskotest
#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 50;
int n, a[maxN], f[maxN], trace[maxN];
int mex(int i, int j){
	for (int x = 0; x <= j-i+1+1000; x++){
		bool flag = 1;
		for (int k = i; k <= j; k++) if (a[k]==x){
			flag = 0;
			break;
		}
		if (flag) return x;
	}
	assert(0);
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0] = 0;
	for (int i = 1; i <= n; i++){
		f[i] = f[i-1] + a[i];
		trace[i] = i;
		for (int j = 0; j < i; j++){
			if (f[i]<f[j]+(i-j)*(i-j)) trace[i] = j;
			f[i] = max(f[i],f[j]+(i-j)*(i-j));
		}
	}
	int pos = n;
	vector<ii> res;
	while (pos>0){
		int tmp = trace[pos]+1;
		if (tmp>pos){
			pos -= 1;
		} else {
			if (mex(tmp,pos)!=0) res.push_back({tmp,pos});
			res.push_back({tmp,pos});
			res.push_back({tmp,tmp});
			function<void(int,int)> add = [&](int x, int y)->void{
				if (x==y){
					res.push_back({x,x});
					return;
				}
				add(x,y-1);
				res.push_back({x,y});
				add(x,y-1);
			};
//			for (int i = tmp; i <= pos; i++){
//				res.push_back({i,pos});
//			}
			add(tmp,pos);
			res.push_back({tmp,pos});
			pos = tmp-1;
		}
	}
	cout << f[n] << " "<< res.size() << "\n";
	for (auto it: res){ 
		cout << it.first  << " " << it.second << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

