#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e4 + 1, maxN = 1e4;

int sg[4*N];
void update(int id, int l, int r, int pos, int val){
	if(pos < l || pos > r) return;
	if(l == r) return sg[id] = val, void();
	
	int m = l + r >> 1;
	update(id << 1, l, m, pos, val);
	update(id << 1 | 1, m + 1, r, pos, val);
	sg[id] = min(sg[id << 1], sg[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 1e15;
	if(l >= u && r <= v) return sg[id];
	int m =l + r >> 1;
	int m1 = get(id << 1, l, m, u, v);
	int m2 = get(id << 1 | 1, m + 1, r, u, v);
	return min(m1, m2);
}
int n, d, h, a[maxN+5], f[maxN+5];
multiset<int> cur[maxN+5];

void solve(){
	cin >> n >> d >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= maxN; i++){
		cur[i].clear();	
		update(1,1,maxN, i,1e15);
	}
//	memset(sg,0x3f,sizeof(sg));
	memset(f,-1,sizeof(f));
	f[1] = a[1];
	update(1,1,maxN,a[1],f[1]);
	cur[a[1]].insert(f[1]);
	for (int i = 2; i <= n; i++){
		int l = max(1ll,a[i]-h), r = min(maxN,a[i]+h);
		int x = get(1,1,maxN,l,r);
//		cout << i << " get " << x << "\n";
		if (x<1e15){
			f[i] = x+a[i];
			cur[a[i]].insert(f[i]);	
			update(1,1,maxN,a[i],*cur[a[i]].begin());
		}
//		cout << "f["<< i << "] = " << f[i] << "\n";
		if (i>d){
			int j = i-d;
			if (f[j]!=-1){
				cur[a[j]].erase(cur[a[j]].find(f[j]));	
				if (cur[a[j]].size())
					update(1,1,maxN,a[j],*cur[a[j]].begin());
				else update(1,1,maxN,a[j],1e15);	
			}
		}
	}
	cout << f[n] << "\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	solve();
}

