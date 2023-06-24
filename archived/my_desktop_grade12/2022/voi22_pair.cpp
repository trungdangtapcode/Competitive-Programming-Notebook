#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, d, a[2005], res;
map<int,ii> mp;
vector<iii> v;

bool check[2005];
int solve(vector<ii> v){
	sort(v.begin(),v.end(),[](ii a, ii b){
		return (a.first==b.first?a.second>b.second:a.first<b.first);	
	});
	int res = 0;
	for (auto it: v){
		int u = it.first, v = it.second;
		if (!check[u]&&!check[v]){
			check[u] = check[v] = true;
			res++;
		}
	}
	for (auto it: v){
		int u = it.first, v = it.second;
		check[u] = check[v] = false;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("PAIR.INP","r",stdin);
//	freopen("PAIR.OUT","w",stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++) v.push_back({a[i]+a[j],{i,j}});
	}	
	sort(v.begin(),v.end());
	for (int i = 0, j = 0; i < v.size(); i++){
		if (v[i].first!=v[j].first){
			mp[v[j].first] = {j,i-1};
			j = i;
		}
		if (i==v.size()-1){ //v[i] = v[j] right now
			mp[v[j].first] = {j,i};
		}
	}
	for (auto it: mp){
		int s = it.first, l = it.second.first, r = it.second.second;
		vector<ii> cur_v;
		for (int i = l; i <= r; i++) cur_v.push_back(v[i].second);
		if (d&&mp.count(s+1)){
			int l = mp[s+1].first, r = mp[s+1].second;
			for (int i = l; i <= r; i++) cur_v.push_back(v[i].second);
		}
		res = max(res,solve(cur_v));
	}
	cout << res;
	return 0;
}
