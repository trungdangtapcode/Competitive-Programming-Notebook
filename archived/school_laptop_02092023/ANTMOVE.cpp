#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, l, m;
vector<iii> a;
vector<ii> v, query;
int cnt[100005], res[100005];
int main(){
	
	cin >> n >> l >> m;
	a.assign(n,{0,{0,0}});
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second.first >> a[i].second.second;
	}
	sort(a.begin(),a.end());
	for (int i = 0, c = 0; i < n; i++){
		if (a[i].second.second==1) c++;
		else cnt[i] = c;
	}
	for (int i = n-1, c = 0; i >= 0; i--){
		if (a[i].second.second==0) c++;
		else cnt[i] = c;
	}
	v.push_back({1e9,-1});
	for (int i = 0; i < n; i++){
		if (a[i].second.second){
			v.push_back({l-a[i].first,a[i+cnt[i]].second.first});
		} else {
			v.push_back({a[i].first,a[i-cnt[i]].second.first});
		}
	}
	
	sort(v.begin(),v.end());
	for (int i = 0; i < m; i++){
		int t;
		cin >> t;
		query.push_back({t,i});
	}
	sort(query.begin(),query.end());
	for (int i = 0, j = 0, sum = 0; i < m; i++){
		while (v[j].first<=query[i].first) sum += v[j++].second;
		res[query[i].second] = sum;
	}
	for (int i = 0; i < m; i++) cout << res[i] << " ";
	return 0;
}
