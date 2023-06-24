#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[2005], d, res;
vector<pair<int,ii>> m;
int main(){
//	freopen("PAIR.INP","r",stdin);
//  freopen("PAIR.OUT","w",stdout);
    
	cin >> n >> d;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a,a+n);
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			m.push_back({a[j]+a[i],{j,i}});
		}
	}	
	sort(m.begin(),m.end());
	m.push_back({-1,{-1,-1}});
	
	int last_s = -1, s = m[0].first;
	vector<ii> v, last_v, tmp;
	for (auto it: m){
		if (it.first==s){
			v.push_back(it.second);
			continue;
		}
		tmp = v;
		if (last_s==s-1&&d==1){
			for (auto it: last_v) tmp.push_back(it);
		}
		sort(tmp.begin(),tmp.end(),[](ii a, ii b){
			if (a.first==b.first) return a.second>b.second;
			return (a.first<b.first);
		});
		
		int cur = 0;
		int last_a = -1, last_b = n;
		for (auto it: tmp){
			int a = it.first, b = it.second;
			if (last_a<a&&b<last_b){
				cur++;
				last_a = max(last_a,a); last_b = min(last_b,b);
			}
		}
		res = max(res,cur);
		
		last_v = v;
		v.clear();
		v.push_back(it.second);
		last_s = s;
		s = it.first;
	}
	
	cout << res;
	return 0;
}
