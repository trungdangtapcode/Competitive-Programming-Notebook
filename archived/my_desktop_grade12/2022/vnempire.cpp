#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;
typedef pair<int,ii> iii;
int n, cha[100005], res;
vector<i4> a;
vector<iii> edgelist;

int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.assign(n,{{0,0},{0,0}});
	for (int i = 0; i < n; i++){
		cin >> a[i].first.first >> a[i].first.second >> a[i].second.first;
		a[i].second.second = i;
	}
	sort(a.begin(),a.end(),[](i4 a, i4 b){
		return a.first.first<b.first.first;
	});
	for (int i = 0; i < n-1; i++){
		edgelist.push_back({a[i+1].first.first-a[i].first.first,{a[i+1].second.second,a[i].second.second}});
	}
	
	sort(a.begin(),a.end(),[](i4 a, i4 b){
		return a.first.second<b.first.second;
	});
	for (int i = 0; i < n-1; i++){
		edgelist.push_back({a[i+1].first.second-a[i].first.second,{a[i+1].second.second,a[i].second.second}});
	}
	
	sort(a.begin(),a.end(),[](i4 a, i4 b){
		return a.second.first<b.second.first;
	});
	for (int i = 0; i < n-1; i++){
		edgelist.push_back({a[i+1].second.first-a[i].second.first,{a[i+1].second.second,a[i].second.second}});
	}
	
	sort(edgelist.begin(),edgelist.end());
	for (int i = 0; i < n; i++) cha[i] = i;
	for (auto it: edgelist){
		if (hop(it.second.first,it.second.second)){
			res += it.first;
		}
	}
	cout << res;
		
	return 0;
}
