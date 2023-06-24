#include <bits/stdc++.h>

using namespace std;
vector <pair<int,int>> a;
int n, m;

bool check(int x){ //greedy check
	vector <pair<int,int>> b(a.begin(),a.begin()+x);
	sort(b.begin(),b.end());
	b.push_back({-1,-1}); //b[x], phan tu ao tranh bi loi
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<x&&b[j].first<=i) pq.push(b[j++].second);
		if (!pq.empty()){ //dang co xe cho vao vi tri (i)
			if (pq.top()<i) return false; //xe dang cho do ko dc dap dung (min{all request}) 
			pq.pop(); //tham lam: ok, them chiec xe do (min) vao vi tri (i)
		}
	}
	return pq.empty(); 
	//neu duyet het vi tri roi ma van con xe dang cho (request) ko dc dap ung
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		a.resize(m);
		for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
		int low = 0, high = m, mid, res = 0;
		while (low<=high){
			mid = (high+low)/2;
			if (check(mid)){
				res = mid;
				low = mid+1;
			} else high = mid-1;
		}
		cout << res << '\n';
	}
	
	return 0;
}
