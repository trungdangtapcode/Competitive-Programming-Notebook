#include<bits/stdc++.h>

using namespace std;
int n;
struct block{
	int u = 0, l = 0, d = 0, r = 0, id = 0;
};
block a[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].u >> a[i].l >> a[i].d >> a[i].r;
			a[i].id = i;
		}
		sort(a+1,a+n+1,[](block a, block b){
			return (a.l==b.l?a.r<b.r:a.l<b.l);
		});
		int rmax[3] = {0,0,0};
		for (int i = 1; i <= n; i++){
			//update on [i]
			a[i].l = max(a[i].l,min(a[rmax[1]].r,a[rmax[2]].r)+1);
			//subarray => change row
			if (a[i].r<=a[rmax[1]].r) a[i].u = 2;
			if (a[i].r<=a[rmax[2]].r) a[i].d = 1;
			if (a[i].l>a[i].r||a[i].u>a[i].d){
				a[i].l = a[i].r = a[i].u = a[i].d = 0;
				continue;
			}
			//locked [i]
			for (int j = a[i].u; j <= a[i].d; j++){
				if (a[i].l<=a[rmax[j]].r) a[rmax[j]].r = a[i].l - 1; //
				rmax[j] = i;
			}
		}
		for (int i = 1; i <= n; i++){
			if (a[i].l>a[i].r||a[i].u>a[i].d) a[i].l = a[i].r = a[i].u = a[i].d = 0;
		}
		sort(a+1,a+n+1,[](block a, block b){
			return a.id<b.id;
		});
		int res = 0;
		for (int i = 1; i <= n; i++) if (a[i].l) res += (a[i].d-a[i].u+1)*(a[i].r-a[i].l+1);
		cout << res << "\n";
		for (int i = 1; i <= n; i++){
			cout << a[i].u << " " << a[i].l << " " << a[i].d << " " << a[i].r << "\n";
		}
	}
	return 0;
}
