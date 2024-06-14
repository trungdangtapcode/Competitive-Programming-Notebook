#include<bits/stdc++.h>

using namespace std;

const int maxN = 7005;
int n, m, t[maxN], l[maxN], r[maxN], x[maxN], v[maxN];
vector<int> add_set, query, level_updt[maxN], res[maxN];
int push_left(int k){
	int h = (int)__lg(k)+1;
	if (k&(k-1)) return h+k;
	return h+k-1;
}
int push_right(int k){
	int h = (int)__lg(k)+1;
	return h+k;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int op; cin >> op;
		if (op==1){
			cin >> t[i] >> l[i] >> r[i] >> x[i];
			add_set.push_back(i);
			level_updt[t[i]].push_back(i);
		} else {
			cin >> t[i] >> v[i];
			query.push_back(i);
		}
	}
	
	for (int qidx: query){
		int tt = t[qidx], ll = v[qidx], rr = v[qidx];
		for (int idx: level_updt[tt]) if (ll<=r[idx]&&l[idx]<=rr&&idx<qidx){
			res[qidx].push_back(x[idx]);
		}
		for (int i = tt; i < n; i++){
			ll = push_left(ll);
			rr = push_right(rr);
//			cout << qidx << " " << ll << ".." << rr << "\n";
			for (int idx: level_updt[i+1]) if (ll<=r[idx]&&l[idx]<=rr&&idx<qidx){
				res[qidx].push_back(x[idx]);
			}
		}
	}

	for (int idx: query){
//		cout << res[idx].size() << ": ";
//		for (int x: res[idx]) cout << x << " ";
//		cout << "\n";
		sort(res[idx].begin(),res[idx].end());
		int sz = 0, last = -1;
		for (int x: res[idx]) sz += last!=x, last = x;
		cout << sz << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}


//	NHAM DE, DAO QUERY VOI UPDATE =))
//	for (int updt: add_set){
//		int ll = l[updt], rr = r[updt], xx = x[updt];
//		for (int idx: level_query[t[updt]]) if (ll<=v[idx]&&v[idx]<=rr){
//			res[idx].push_back(xx);
//		}
//		for (int i = t[updt]; i < n; i++){
//			ll = push_left(ll);
//			rr = push_right(rr);
////			cout << updt << " " << ll << ".." << rr << "\n";
//			for (int idx: level_query[i+1]) if (ll<=v[idx]&&v[idx]<=rr){
//				res[idx].push_back(xx);
//			}
//		}
//	}
