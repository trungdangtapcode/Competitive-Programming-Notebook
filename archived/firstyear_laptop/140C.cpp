#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n;
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		mp[a]++;
	}
	priority_queue<ii> pq;
	for (auto it: mp) pq.push({it.second,it.first});
	vector<int> r1, r2, r3;
	while (pq.size()>=3){
		auto it1 = pq.top(); pq.pop();
		auto it2 = pq.top(); pq.pop();
		auto it3 = pq.top(); pq.pop();
		it1.first--;
		it2.first--;
		it3.first--;
		r1.push_back(it1.second);
		r2.push_back(it2.second);
		r3.push_back(it3.second);
		if (it1.first>0) pq.push(it1);
		if (it2.first>0) pq.push(it2);
		if (it3.first>0) pq.push(it3);
	}
	cout << r1.size() << "\n";
	for (int i = 0; i < r1.size(); i++){
		vector<int> v({r1[i],r2[i],r3[i]});
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for (auto it: v) cout << it << " "; cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

