#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
priority_queue<ii, vector<ii>, greater<ii>> q;
int d[100005], k;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	memset(d,1,sizeof(d));
	cin >> k;
	for (int i = 1; i <= 9; i++){
		int v = i%k;
		if (d[v]>i){
			d[v] = i;
			q.push({d[v],v});
		}
	}
	
	while (!q.empty()){
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
//		cout << u << " " << du << endl;
		if (d[u]!=du) continue;
		if (u==0) break;
		for (int i = 0; i <= 9; i++){
			int v = (10*u+i)%k;
			if (d[v]>d[u]+i){
				d[v] = d[u] + i;
				q.push({d[v],v});
			}
		}
	}
	
	cout << d[0];
	return 0;
}
