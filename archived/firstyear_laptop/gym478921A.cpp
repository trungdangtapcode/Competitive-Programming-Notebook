#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN];
int main(){
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i =1 ; i <= n; i++){
		cin >> a[i];
		pq.push(a[i]);
	};
	int cur =1;
	while (pq.size()){
		int u = pq.top();
		pq.pop();
		if (u<cur) continue;
//		a[i] = cur;
		cur++;
	}
	cout << cur;
	
	return 0;
}
