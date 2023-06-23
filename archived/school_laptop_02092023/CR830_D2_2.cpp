#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
char c;
long long int x;
set<long long int> s;
map<long long int, vector<long long int>> p;
map<long long int, long long int> res;
vector<pair<char,long long int>> query;
map<long long int, set<long long int>> kmul_able;
int main(){
	
	int q; cin >> q;
	while (q--){
		cin >> c >> x;
		query.push_back({c,x});
		if (c=='+'){
			if (s.count(x)) continue;
			s.insert(x);
			p[x].push_back(x);
			for (auto it: p[x]){
//				cout << x << " " << it << " -> ";
				long long int cur = x + it;
				while (s.count(cur)) p[cur].push_back(it), cur += it;
				p[cur].push_back(it);
				res[it] = cur; 
			}
		}
	}
	vector<long long int> d;
	for (auto it: res){
		d.clear();
//		cout << it.first << " " << it.second << endl;
		for (long long int i = it.first; i <= it.second; i+= it.first) d.push_back(i);
		kmul_able[it.first] = (set<long long int> (d.begin(),d.end()));
	}
	
	
	//it starts
	for (auto it: query){
		c = it.first; x = it.second;
		if (c=='+') for (auto i: p[x]) kmul_able[i].erase(x);
		else if (c=='-') for (auto i: p[x]) kmul_able[i].insert(x);
		else if (kmul_able.count(x)) cout << *kmul_able[x].begin() << "\n";
		else cout << x << "\n";
	}
	
	
	return 0;
}
