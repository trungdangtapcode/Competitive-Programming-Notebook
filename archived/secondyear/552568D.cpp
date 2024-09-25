#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5;
int n, m, q, check[maxN], pos[maxN], posi[maxN], len;
string s;
int cha[maxN];
int timcha(int x){
	return x==cha[x]?x:cha[x]=timcha(cha[x]);
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[u] = v;
	return true;
}

int val[maxN];
void updt(int x, int y){
	for (; x <= len; x += x&-x) val[x] += y;
}
int gett(int x){
	int res = 0;
	for (; x; x -= x&-x) res += val[x];
	return res;
}

void solve(){
	cin >> n >> m >> q;
	cin >> s;
	s = ' ' + s;
	len = 0;
	for (int i = 1; i <= n; i++) cha[i] = i, check[i] = 0, posi[i] = -1;
	for (int i = 1, l, r; i <= m; i++){
		cin >> l >> r;
		int cur = l;
		while (cur<=r){
			if (check[cur]){
				cur = timcha(cur)+1;
				continue;
			}
			len++;
			pos[len] = cur;
			posi[cur] = len;	
//			cout << cur << " -> ";
			if (cur<r) hop(cur,cur+1);
			check[cur] = 1;
			cur++;
		}
	}
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) cnt1 += s[i]=='1';
	
	string t = " ";
	for (int i = 1; i <= len; i++) t += s[pos[i]];
	for (int i = 1; i <= len; i++) val[i] = 0;
	for (int i = 1; i <= len; i++){
		if (t[i]=='1'){
			updt(i,1);
		}
	}
//	cout << t << "\n";
	for (int i = 1; i <= q; i++){
		int x;
		cin >> x;
		if (s[x]=='1') cnt1--;
		s[x] = '1'-s[x]+'0';
		if (s[x]=='1') cnt1++;
		if (posi[x]!=-1){
			x = posi[x];
			if (t[x]=='1') updt(x,-1);
			t[x] = '1'-t[x]+'0';
			if (t[x]=='1') updt(x,+1);
		}
//		if (posi[x]==-1){
//			cout << "hi" << "\n";
//			continue;
//		}
//		x = posi[x];
//		cout << t << "\n";
		int cur = gett(min(cnt1,len));
		cout << min(cnt1,len)-cur << '\n';
	}
	exit(0);
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
//https://codeforces.com/contest/1847/problem/D
