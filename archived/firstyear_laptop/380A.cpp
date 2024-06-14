#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5, maxL = 1e5;
int n, t[maxN], x[maxN], l[maxN], c[maxN], s[maxN];
long long querylen[maxN];
void solve(){
	cin >> n;
	int len = 0;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		if (t[i]==1){
			cin >> x[i];
			if (len<maxL) s[len++] = x[i];
			querylen[i] = querylen[i-1]+1;
		} else {
			cin >> l[i] >> c[i];
			if (len<maxL){
				for (int j = 0; j < c[i]&&len<maxL; j++) for (int k = 0; k < l[i]&&len<maxL; k++){
					s[len++] = s[k];
				}
			}
			querylen[i] = querylen[i-1]+l[i]*c[i];
		}
//		querylen[i] = len;
	}
	int q; cin >> q;
	while (q--){
		long long pos; cin >> pos;
		int idx = lower_bound(querylen+1, querylen+n+1, pos)-querylen;
		if (t[idx]==1){
			cout << x[idx] << " ";
		} else {
			int tmp = (pos-querylen[idx-1]-1)%l[idx];
			cout << s[tmp] << " ";
		}
	}
//	for (int i = 0; i < len; i++) cout << s[i] << " ";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

