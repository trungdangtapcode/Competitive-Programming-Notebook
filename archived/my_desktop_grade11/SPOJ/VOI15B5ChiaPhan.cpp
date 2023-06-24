#include <bits/stdc++.h>

using namespace std;
int n;
bool f[500010];

int main(){
	
	cin >> n;
	vector <pair<pair<int,int>,int> > a (n);
	for (int i = 0; i < n; i++) cin >> a[i].first.first, a[i].second = i+1;
	for (int i = 0; i < n; i++) cin >> a[i].first.second;
	sort(a.begin(),a.end());
	
	long long int res = 0;
	priority_queue<pair<int,int>> pq;	
	for (int i = 0; i < n; i++){
		pq.push({a[i].first.second,a[i].second});
		if (i % 2== 0){
			res += pq.top().first;
			f[pq.top().second] = true;
			pq.pop();
		}
	}
	cout << res << endl;
	queue <int> q;	//2|d
	for (int i = 0; i < n; i++){
		if (f[a[i].second]) q.push(a[i].second);
		else {
			cout << a[i].second << " " << q.front() << endl;
			q.pop();
		}
	}
	
	
	return 0;
}
