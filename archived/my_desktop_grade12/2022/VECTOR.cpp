#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, n1, n2, u, v;
ii a1[105], a2[105];
long long res;
map<ii,int> mp;
int main(){
	cin >> n;
	n1 = n/2; n2 = n - n1;
	for (int i = 0; i < n1; i++) cin >> a1[i].first >> a1[i].second;
	for (int i = 0; i < n2; i++) cin >> a2[i].first >> a2[i].second;
	cin >> u >> v;
	for (int mask = 0; mask < (1<<n1); mask++){
		ii cur = {0,0};
		for (int i = 0; i < n1; i++) if (mask&(1<<i)) cur = {cur.first+a1[i].first,cur.second+a1[i].second};
		mp[cur]++;
	}
	for (int mask = 0; mask < (1<<n2); mask++){
		ii cur = {u,v};
		for (int i = 0; i < n2; i++) if (mask&(1<<i)) cur = {cur.first-a2[i].first,cur.second-a2[i].second};
		if (mp.count(cur)) res += mp[cur];
	}
	cout << res;
	return 0;
}
