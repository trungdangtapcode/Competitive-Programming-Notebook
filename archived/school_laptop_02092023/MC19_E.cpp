#include<bits/stdc++.h>

using namespace std;
multiset<int> ms[1000005];
typedef pair<int,int> ii;
vector<ii> sweep_add[1000005], sweep_del[1000005];
int n, w;
long long cur;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> w;
	for (int i = 0, l, x; i < n; i++){
		cin >> l;
		for (int j = 0; j < l; j++){
			cin >> x;
			sweep_add[j].push_back({x,i});
			sweep_del[w-(l-j)+1].push_back({x,i});
		}
		if (l<w){
			sweep_add[0].push_back({0,i});
			sweep_del[w-l+1].push_back({0,i});
			sweep_add[l+1].push_back({0,i});
			sweep_del[w].push_back({0,i});
		}
	}
	for (int i = 0; i < w; i++){
		for (auto it: sweep_add[i]) cur-=(ms[it.second].empty()?0:*ms[it.second].rbegin()), ms[it.second].insert(it.first), cur+=*ms[it.second].rbegin();
		for (auto it: sweep_del[i]) cur-=*ms[it.second].rbegin(), ms[it.second].erase(ms[it.second].find(it.first)), cur+=(ms[it.second].empty()?0:*ms[it.second].rbegin());
		cout << cur << " ";
		
	}
	
	
	return 0;
}
