#include <bits/stdc++.h>

using namespace std;
set<long long int> s;
int q, x;
long long int y, nxt, dis, cnt, cur, res;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> q;
	s.insert(2e18); //do them if truong hop den cuoi
	while (q--){
		cin >> x >> y;
		if (x==1){
			if (s.count(y)) s.erase(y); else s.insert(y);
			continue;
		}
		if (!s.count(1)) {
			cout << -1 << '\n';
			continue;
		}
		cur = 1; res = 1;
		while (cur < y){
			auto it = s.upper_bound(cur+1);
			nxt = min(y,*it-1);
			dis = *(--it);
			cnt = (nxt-cur+dis-1)/dis; //floor-up (nxt-cur)/dis; co the qua neu buoc di qua dai
			cur += cnt*dis; //cnt (so buoc di) la 1 so nguyen
			res += cnt;
		}
		cout << res << '\n';
	}
	
	return 0;
}
