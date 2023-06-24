#include<bits/stdc++.h>

using namespace std;
int d[200005], n;
vector<int> edge[200005];

queue<set<int>> q; 
bool find(int x){
	return (q.front().find(x)!=q.front().end());
}
void popp(int x){
	q.front().erase(x);
	if (q.front().empty()) q.pop();
}
void inra(queue<set<int>> q){
	while (!q.empty()){
		cout << "(";
		for (auto it: q.front()) cout << it << ",";
		cout << ") ";
		q.pop();
	}
}

int main(){
	cin >> n;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	} 
	
	q.push({1}); d[1] = 1;
	while (!q.empty()){
		int x; cin >> x;
		if (!find(x)) return cout << "No", 0;
		int u = x; popp(x);
		set<int> tmp;
		for (auto v: edge[u]) if (!d[v]){
			d[v] = d[u] + 1;
			tmp.insert(v);
		}
		if (!tmp.empty()) q.push(tmp);
	}
	cout << "Yes";
	return 0;
}
