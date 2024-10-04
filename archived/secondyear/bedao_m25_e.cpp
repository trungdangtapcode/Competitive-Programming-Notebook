//NO PERSISTENT/MERGE, NO SEGMENT/DFS
//JUST OFFLINE+BIT, JUST SWEEPLINE+MULTISET
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, q, a[maxN], pref[maxN], l[maxN], r[maxN], x[maxN];
int bit1[maxN], bit2[maxN], res1[maxN], res2[maxN];
void bitrs(){
	for (int i = 1; i <= n; i++) bit1[i] = bit2[i] = 0;
}
void bitupdt(int u, int x, int y){
	for (; u <= n; u += u&-u)
		bit1[u] += x, bit2[u] += y;
}
void bitgett(int u, int& x, int& y){
	x = 0, y = 0;
	for (; u; u -= u&-u)
		x += bit1[u], y += bit2[u];
}
void bitrange(int l, int r, int& x, int& y){
	int tmp1 = 0, tmp2 = 0;
	bitgett(r,x,y);
	bitgett(l-1,tmp1,tmp2);
	x -= tmp1;
	y -= tmp2;
}

void solve1(){
	vector<ii> vec;
	for (int i = 1; i <= n; i++){
		vec.push_back({a[i],i});
	}
	for (int i = 1; i <= q; i++){
		vec.push_back({x[i],-i});
	}
	sort(vec.begin(),vec.end());
	bitrs();
	for (auto it: vec){
		int v = it.first, idx = it.second;
		if (idx>0){
			bitupdt(idx,1,a[idx]);
		} else {
			int ll = l[-idx], rr = r[-idx], cnt, sum;
			bitrange(ll,rr,cnt,sum);
			res1[-idx] = pref[n]-sum+cnt*x[-idx];
		}
	}
}

vector<ii> events[maxN];
void solve2(){
	multiset<ii> ms;
	for (int i = 1; i<= n; i++){
		events[i].push_back({a[i],-1});
		events[i+1].push_back({-a[i],-1});
	}
	for (int i = 1; i <= q; i++){
		events[l[i]].push_back({x[i],i});
		events[r[i]+1].push_back({-x[i],i});
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		for (auto it: events[i]){
			int x = it.first, y = it.second;
			if (x>0){
				ms.insert(it);
			} else {
				ms.erase(ms.find({-x,y}));
			}
		}
		auto it = ms.rbegin();
		int x = (*it).first, q = (*it).second;
		if (q!=-1&&ms.size()>1){
			++it;
			int y = (*it).first;
			res2[q] += y-x;
		}
		sum += x;
	}
	for (int i = 1; i <= q; i++) res2[i] += sum;
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	for (int i = 1; i <= q; i++){
		cin >> l[i] >> r[i] >> x[i];
	}
	solve1();
	solve2();
	for (int i = 1; i <= q; i++){
		cout << res1[i] << " " << res2[i] << "\n";
	}
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

