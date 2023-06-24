#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[2005], d, res;
unordered_map<int,vector<ii>> m;
int main(){
	freopen("PAIR.INP","r",stdin);
    freopen("PAIR.OUT","w",stdout);
    
	cin >> n >> d;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a,a+n);
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
//			v.push_back({a[i]+a[j],{j,i}});
			m[a[i]+a[j]].push_back({j,i});
		}
	}	
//	sort(v.begin(),v.end());

	for (auto it: m){
		int s = it.first;
		vector<ii> v = it.second;
		if (d==1&&m.count(s+1)){
			for (auto it: m[s+1]) v.push_back(it);
		}
		sort(v.begin(),v.end(),[](ii a, ii b){
			if (a.first==b.first) return a.second>b.second;
			return (a.first<b.first);
		});
		
		int cur = 0;
		int last_a = -1, last_b = n;
		for (auto it: v){
//			cout << a[it.first] << " + " << a[it.second] << " = " << s<< endl;
			int a = it.first, b = it.second;
			if (last_a<a&&b<last_b){
				cur++;
				last_a = max(last_a,a); last_b = min(last_b,b);
			}
		}
		res = max(res,cur);
	}
	
	cout << res;
	return 0;
}
