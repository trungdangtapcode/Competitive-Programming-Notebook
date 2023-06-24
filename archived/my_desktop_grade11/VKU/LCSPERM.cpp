#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<int> a[100005], b[100005], x;
vector<ii> v;
int n, k;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0, x; i < n*k; i++){
		cin >> x;
		a[x].push_back(i);
	}
	for (int i = 0, x; i < n*k; i++){
		cin >> x;
		b[x].push_back(i);
	}
	
	for (int i = 1; i <= n; i++){
		for (int x: a[i]) for (int y: b[i]) v.push_back({x,y});
	}
	sort(v.begin(),v.end(),[](ii a, ii b){if (a.first==b.first) return a.second>b.second; return a.first<b.first;});
	for (ii it: v) x.push_back(it.second);
	
	int m = x.size();
	vector<int> lis(m+5,1e6);
	lis[0] = -1e6;
	for (int it: x){
		int pos = lower_bound(lis.begin(),lis.end(),it)-lis.begin();
		lis[pos] = it;
	}
	for (int i = m; i >= 1; i--) if (lis[i]<1e6){
		cout << i;
		return 0;
	}
	
	return 0;
}
