#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+50;
int n, l, r, z[maxN], rmq[18][maxN], f[maxN];
string s;
void calcz(){
	int l = 1, r = 1;
	for (int i = 2; i <= n; i++){
		if (i<r) z[i] = min(r-i,z[i-l+1]); else z[i] = 0;
		while (i+z[i]<=n&&s[1+z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]>r){
			r = i+z[i];
			l = i;
		}
	}
}
int query(int l, int r){
	int h = __lg(r-l+1);
	return max(rmq[h][l],rmq[h][r-(1<<h)+1]);
}

void solve(){
	cin >> n >> l >> r;
	cin >> s;
//	n = 200000, l = 1, r = 200000;
//	for (int i = 1; i <= n; i++) s.push_back('a');
//	s[13992] = 'c';
	s = " " + s;
	calcz();
	for (int i = 1; i <= n; i++) rmq[0][i] = z[i];
	for (int b = 1; b < 18; b++) for (int i = 1; i+(1<<b)-1 <= n; i++){
		rmq[b][i] = max(rmq[b-1][i],rmq[b-1][i+(1<<(b-1))]);
	}
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int lcp = 1; lcp <= n; lcp++){
		int pos = 1, cnt = 1;
		while (true){
			int l = pos+lcp, r = n-lcp+1, res = -1;
			while (l<=r){
				int m = (l+r)/2;
				if (query(pos+lcp,m)>=lcp){
					res = m;
					r = m-1;
				} else l = m+1;
			}
			if (res==-1) break;
			cnt++;
			pos = res;
		}
		f[cnt] = max(f[cnt],lcp);
//		cout << lcp << " -> " << cnt << "\n";
	}
	for (int i = n; i > 1; i--) f[i-1] = max(f[i-1],f[i]); 
	for (int i = l; i <= r; i++) cout << f[i] << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

