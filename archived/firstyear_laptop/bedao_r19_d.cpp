#include<bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}
const int maxN = 2e5+5;
int n, a[maxN], b[maxN], q, l[maxN], r[maxN], x[maxN], y[maxN];
long long ha[maxN], hb[maxN], vquery1[maxN], vquery2[maxN];
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

long long val[maxN];
void rs(){
	for (int i = 1; i <= n; i++){
		val[i] = 0;
	}
}
void updt(int x, int y){
	for (; x <= n; x += x&-x) val[x] ^= y;
}
long long gett(int x){
	int res = 0;
	for (; x > 0; x -= x&-x) res ^= val[x];
	return res;
}

int nxt[maxN], added[maxN];
void calc(long long a[], vector<iii>&query, long long res[]){
	sort(query.begin(), query.end());
	map<long long, int> mp;
	for (int i = n; i > 0; i--){
		if (mp.count(a[i])) nxt[i] = mp[a[i]];
		else nxt[i] = -1;
		mp[a[i]] = i;
	}
	rs();
	mp.clear();
	for (int i = 1; i<= n; i++){
		added[i] = 0;
		if (mp.count(a[i])) continue;
		added[i] = 1;
		updt(i,a[i]);
		mp[a[i]] = 1;
	}
	
	int ptr = 1;
	for (auto it: query){
		int l = it.first.first, r = it.first.second, idx = it.second;
		while (ptr<l){
			if (added[ptr]==1){
				updt(ptr,a[ptr]);
				added[ptr] = 0;
				int x = nxt[ptr];
				if (x!=-1){
					updt(x,a[x]);
					added[x] = 1;
				}
			}
			ptr++;
		}
//		for (int i = 1; i <= n; i++) cout << added[i] << " ";cout << "\n";
		res[idx] = gett(r)^gett(l-1);
//		cout << l << " " << r << " = " << res[idx] << "\n";
	}
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	map<int, long long> mp;
	for (int i = 1; i <= n; i++){
		if (!mp.count(a[i])) mp[a[i]] = rd();
		ha[i] = mp[a[i]];
	}
	for (int i = 1; i <= n; i++){
		if (!mp.count(b[i])) mp[b[i]] = rd();
		hb[i] = mp[b[i]];
	}
	vector<iii> query1, query2;
	for (int i = 1; i <= q; i++){
		cin >> l[i] >> r[i] >> x[i] >> y[i];
		query1.push_back({{l[i],r[i]},i});
		query2.push_back({{x[i],y[i]},i});
	}
	calc(ha,query1, vquery1);
	calc(hb,query2, vquery2);
	for (int i = 1; i <= q; i++){
		cout << (vquery1[i]==vquery2[i]?"YES":"NO") << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}


