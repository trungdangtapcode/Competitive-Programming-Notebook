#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n;
vector<ii> a;

bool check(int x){
	vector<ii> time;
	for (int i = 0; i < n; i++) time.push_back({a[i].first-x/a[i].second,a[i].first+x/a[i].second});
	sort(time.begin(),time.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1, j = 0; i <= n; i++){
		while (time[j].first<=i&&j<n) pq.push(time[j++].second); 
		if (pq.empty()) return false;
		if (pq.top()<i) return false;
		pq.pop();
	}
	return true;
}

int main(){
	freopen("CUUHO.INP","r",stdin);
	freopen("CUUHO.OUT","w",stdout);

	cin >> n;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}	
	int l = 0, h = 1e8, m, res;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			h = m-1;
		} else l = m+1;
	}
	cout << res;
	
	return 0;
}
