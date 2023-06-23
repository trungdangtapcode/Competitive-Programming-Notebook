#include<bits/stdc++.h>

using namespace std;
long long int x, cur;
map<long long int, bool> s;
map<long long int, vector<long long int>> p, del;
map<long long int, long long int> res;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q; cin >> q;
	while (q--){
		cin >> c >> x;
		if (c=='+'){
			s[x] = true;
		} else {
			long long int tmp = 1;
			if (res.count(x)) tmp = res[x];
			while (s.count(x*tmp)) p[(tmp++)*x].push_back(x);
			res[x] = tmp;
			cur = x*tmp;
			for (auto it: del[x]) if (!s.count(it)) cur = min(cur,it);
			cout << cur << "\n";
		}
	}
	
	return 0;
}
