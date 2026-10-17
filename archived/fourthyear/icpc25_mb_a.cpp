#include<bits/stdc++.h>

using namespace std;
const int N = 155;
int p, q, r, c[N][N][N], f[N][N][N], h[N], rt[N], l[N];
int rres = 0;

void subsolve(){
	memset(f, 0, sizeof(f));
	for (int z = 1; z <= r; z++){
		for (int i = 1; i <= p; i++) for (int j = 1; j <= q; j++){
			f[z][i][j] = 1+min({f[z][i-1][j-1],f[z][i-1][j],f[z][i][j-1]});
			f[z][i][j] *= c[z][i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= p; i++) for (int j = 1; j <= q; j++){
		for (int z = 1; z <= r; z++){
			h[z] = f[z][i][j];	
			l[z] = rt[z] = z;
		}	
		deque<int> d;
		for (int z = 1; z <= r; z++){
			while (d.size()&&h[d.back()]>=h[z]){
				d.pop_back();
			}
			int ll = d.size()?d.back():0;
			l[z] = ll+1;
			d.push_back(z);
		}
		d.clear();
		for (int z = r; z >= 1; z--){
			while (d.size()&&h[d.back()]>=h[z]){
				d.pop_back();
			}
			int rr = d.size()?d.back():(r+1);
			rt[z] = rr-1;
			d.push_back(z);
		}
		for (int z = 1; z <= r; z++){
			res = max(res,(rt[z]-l[z]+1)*h[z]);	
		}
	}
	rres = max(res, rres);
}

int cc[N][N][N];
void solve(){
	int pp, qq, rr;
	cin >> pp >> qq >> rr;
	for (int i = 1; i <= qq; i++) for (int j = 1; j <= pp; j++) for (int k = 1; k <= rr; k++){
		char ch;
		cin >> ch;
		cc[k][i][j] = (ch=='N');
	}
	p = pp, q = qq, r = rr;
	for (int i = 1; i <= qq; i++) for (int j = 1; j <= pp; j++) for (int k = 1; k <= rr; k++){
		c[k][j][i] = cc[k][i][j];
	}
	subsolve();
	p = pp, q = rr, r = qq;
	for (int i = 1; i <= qq; i++) for (int j = 1; j <= pp; j++) for (int k = 1; k <= rr; k++){
		c[i][j][k] = cc[k][i][j];
	}
	subsolve();
	p = rr, q = qq, r = pp;
	for (int i = 1; i <= qq; i++) for (int j = 1; j <= pp; j++) for (int k = 1; k <= rr; k++){
		c[j][k][i] = cc[k][i][j];
	}
	subsolve();
	cout << rres*4 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

