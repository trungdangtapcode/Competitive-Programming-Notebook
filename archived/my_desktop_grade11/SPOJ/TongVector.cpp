#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii a1[25], a2[25];
int n, n1, n2, u, v;
map<ii,int> cnt1, cnt2;
long long int res;

void backtrack1(int k, ii x){
	if (k>=n1){
		cnt1[x]++;
		return;
	}
	backtrack1(k+1,x);
	backtrack1(k+1,{x.first+a1[k].first,x.second+a1[k].second});
}
void backtrack2(int k, ii x){
	if (k>=n2){
		cnt2[x]++;
		return;
	}
	backtrack2(k+1,x);
	backtrack2(k+1,{x.first+a2[k].first,x.second+a2[k].second});
}

int main(){
	cin >> n;
	n1 = n/2;
	n2 = n-n/2;
	for (int i = 0; i < n1; i++) cin >> a1[i].first >> a1[i].second;
	for (int i = 0; i < n2; i++) cin >> a2[i].first >> a2[i].second;
	cin >> u >> v;
	backtrack1(0,{0,0});
	backtrack2(0,{0,0});
	for (auto it: cnt1){
		ii tmp = {u-it.first.first,v-it.first.second};
		if (cnt2.count(tmp)) res += 1ll*it.second*cnt2[tmp];
	}
	cout << res;
	
	return 0;
}
