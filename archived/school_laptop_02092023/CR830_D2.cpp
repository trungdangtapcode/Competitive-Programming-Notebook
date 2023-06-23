#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
long long int x, cur;
gp_hash_table<long long int, bool> s;
gp_hash_table<long long int, vector<long long int>> p, del;
gp_hash_table<long long int, int> res;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q; cin >> q;
	while (q--){
		cin >> c >> x;
		if (c=='+'){
			s[x] = true;
		} else if (c=='-'){
			s[x] = false;
			for (auto i: p[x]) del[i].push_back(x);
			p[x].clear();
		} else {
			long long int tmp = 1;
			if (res[x]!=0) tmp = res[x];
			while (s[tmp*x]) p[(tmp++)*x].push_back(x);
			res[x] = tmp;
			cur = x*tmp;
			for (auto it: del[x]) if (!s[it]) cur = min(cur,it);
			cout << cur << "\n";
		}
	}
	
	return 0;
}
