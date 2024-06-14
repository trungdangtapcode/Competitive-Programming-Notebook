#include<bits/stdc++.h>

using namespace std;

int n, a[3][500005], val[2000005], t[500005][4], res[500005];
typedef pair<int,int> ii;
vector<ii> query[500005];

void build(int k, int l, int r){
	val[k] = -1;
	if (l==r) return;
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
}
void down(int k, int l, int r, int m){
	if (val[k]==-1) return;
	val[2*k] = val[k];
	val[2*k+1] = val[k];
	val[k] = -1;
}
int getVal(int k, int l, int r, int u){
	if (l>u||r<u) return -1;
	if (l==r){
		return val[k];
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	return max(getVal(2*k,l,m,u),getVal(2*k+1,m+1,r,u));
}
void updt(int k, int l, int r, int u, int v, int st){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] = st;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updt(2*k,l,m,u,v,st);
	updt(2*k+1,m+1,r,u,v,st);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int q; cin >> q;
	for (int j = 0; j < 3; j++) for (int i = 1; i <= n; i++){
		cin >> a[j][i];
	}
	build(1,1,n);
	for (int i = 1; i <= q; i++){
		cin >> t[i][0];
		if (t[i][0]==3){
			cin >> t[i][1];
		} else cin >> t[i][1] >> t[i][2] >> t[i][3]; //st u v
		t[i][3] = t[i][3] + t[i][2] - 1;
		if (t[i][0]==2){
			updt(1,1,n,t[i][2],t[i][3],i);
		}
		if (t[i][0]==3){
			int u = t[i][1];
			int x = getVal(1,1,n,u);
			if (x==-1) res[i] = a[2][u];
			else {
				query[x].push_back({u-t[x][2]+t[x][1],i});
			}
		}
	}
	build(1,1,n);
	for (int i = 1; i <= q; i++){
		if (t[i][0]==1){
			updt(1,1,n,t[i][2],t[i][3],i);
		}
		for (ii x: query[i]){
			int p = x.first, idx = x.second;
			int y = getVal(1,1,n,p);
			if (y==-1) res[idx] = a[1][p];
			else res[idx] = a[0][p - t[y][2] + t[y][1]];
		}
	}
	for (int i = 1; i <= q; i++) if (t[i][0]==3) cout << res[i] << "\n";
	return 0;
}
