#include <bits/stdc++.h>
#define fix cout <<"fixed" << endl;
using namespace std;
typedef pair<int, long int> id;
const int INF = 1e6;
vector<vector<int>> edge (3005);
vector<int> low, step, iscc; 
vector<bool> onStack;
stack<int> st;
int n, m, step_tick = 1, result = 0, nscc;

void dfs(int nodeU){
	step[nodeU] = step_tick;
	low[nodeU] = step_tick; //khoi assign (for)
	step_tick++;
	st.push(nodeU);
	
	//cout << nodeU << endl;
	for (auto& it: edge[nodeU]){
		int nodeV = it;
		if (step[nodeV]==-1) dfs(nodeV);
		low[nodeU] = min(low[nodeU],low[nodeV]);
	} 
	
	if (step[nodeU] == low[nodeU]){ //van con giu nguyen
		//result++;
		int nodeV;
		do {
			nodeV = st.top();
			st.pop();
			step[nodeV] = INF;
			low[nodeV] = INF;
			iscc[nodeV] = nscc;
		} while (nodeV != nodeU);
		nscc++;
	}
}

void bigGraph(){ //moi cum lien thong xem nhu 1 node

	//for (int i = 0; i < n; i++) cout << iscc[i] << " "; cout << endl;
	vector<int> bac (n,0); //bac vao
	for(int nodeU = 0; nodeU < n; nodeU++)
		for (auto& nodeV: edge[nodeU]){
			if (iscc[nodeU] != iscc[nodeV]) bac[iscc[nodeV]]++;
		} 
	for (int nodeU = 0; nodeU < nscc; nodeU++) if (bac[nodeU] == 0) result++;
	
}

void solve(){
	cin >> n >> m;
	
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b-1);
	}
	
	step.assign(n,-1);
	low.assign(n,-1);
	iscc.assign(n,-1);
	for (int i = 0; i < n; i++) if (step[i]==-1) dfs(i);
	bigGraph();
	
	//dfs(0); => 1
	cout << result;
}

int main(){
	solve();
	
	return 0;
}
