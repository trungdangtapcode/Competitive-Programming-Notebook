#include<bits/stdc++.h>

using namespace std;
int a, b, n, m;
typedef pair<int,int> ii;
void solve(){
	cin >> a >> b >> n >> m;
	int l = 1, r = b, u = 1, d = a;
	multiset<ii> ms1, ms2;
	set<int> s;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		s.insert(i);
		ms1.insert({x,i});
		ms2.insert({y,i});
	}
	int res[2] = {0};
	for (int i = 1; i <= m; i++){
		int x, cnt = 0; char c;
		cin >> c >> x;
		if (c=='U'){
			u += x;
			while (ms1.size()&&(*ms1.begin()).first<u){
				auto it = ms1.begin();
				if (s.count((*it).second)) 
					s.erase((*it).second), cnt++;
				ms1.erase(it);
			}
		} else if (c=='D'){
			d -= x;
			while (ms1.size()&&(*ms1.rbegin()).first>d){
				auto it = ms1.end();
				it--;
				if (s.count((*it).second)) 
					s.erase((*it).second), cnt++;
				ms1.erase(it);
			}
		} else if (c=='L'){
			l += x;
			while (ms2.size()&&(*ms2.begin()).first<l){
				auto it = ms2.begin();
				if (s.count((*it).second)) 
					s.erase((*it).second), cnt++;
				ms2.erase(it);
			}
		} else {
			r -= x;
			while (ms2.size()&&(*ms2.rbegin()).first>r){
				auto it = ms2.end();
				it--;
				if (s.count((*it).second)) 
					s.erase((*it).second), cnt++;
				ms2.erase(it);
			}
		}
		res[i%2] += cnt;
//		cout << res[1] << " " << res[0] << ": ";
//		for (int x: s) cout << x << " "; 
//		cout << " => " << cnt << "\n";
	}
	cout << res[1] << " " << res[0] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

