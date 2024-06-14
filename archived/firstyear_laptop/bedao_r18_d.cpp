#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
typedef pair<int,int> ii;
int n;
ii a[maxN];
int dist(ii a, ii b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	sort(a+1,a+n+1,[](ii x, ii y){
		return max(x.first,x.second)<max(y.first,y.second);
	});
	ii lastmax = ii{0,0}, lastmin = ii{0,0};
	long long fmax = 0, fmin = 0;
	for (int i = 1, j = 1; i <= n; i++){
//		cout << i << ": " << a[i].first << ", " << a[i].second << "\n";
		if (i==n||max(a[i+1].first,a[i+1].second)!=max(a[i].first,a[i].second)){
			ii posmax = ii{1e9,0}, posmin = ii{0,1e9};
			for (; j <= i; j++){
//				cout << j << ".." << i << "\n";
				if (posmax.second-posmax.first<a[j].second-a[j].first) posmax = a[j];
				if (posmin.second-posmin.first>a[j].second-a[j].first) posmin = a[j];
			}
			tie(fmax,fmin) = make_tuple(
				min(fmax+dist(lastmax,posmin)+dist(posmin,posmax),
					fmin+dist(lastmin,posmin)+dist(posmin,posmax)),
				min(fmax+dist(lastmax,posmax)+dist(posmax,posmin),
					fmin+dist(lastmin,posmax)+dist(posmax,posmin)));
			lastmax = posmax, lastmin = posmin;
//			cout << fmax << " " << fmin << " " << posmax.first << "," << posmax.second << " " << posmin.first << "," << posmin.second << "\n";
		}
	}
	cout << min(fmax,fmin) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

