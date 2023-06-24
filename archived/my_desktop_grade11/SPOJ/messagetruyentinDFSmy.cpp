#include <bits/stdc++.h>
#define fix cout <<"fixed" << endl;
using namespace std;
typedef pair<int, long int> id;
const int INF = 1e6;
vector<vector<int>> edge (3005);
vector<int> low, step, boss; //children and boss
vector<int> onStack, children; 
stack<int> st;
int n, m, step_tick = 1, result = 0;

void dfs(int nodeU){ //Tarjan
	step[nodeU] = step_tick;
	low[nodeU] = step_tick; //khoi assign (for)
	step_tick++;
	st.push(nodeU);
	onStack[nodeU] = true;
	
	//cout << nodeU << endl;
	for (auto& it: edge[nodeU]){
		int nodeV = it;
		if (step[nodeV]==-1) dfs(nodeV);
		children[nodeV] = true;
		if (onStack[nodeV]) low[nodeU] = min(low[nodeU],low[nodeV]); else children[boss[nodeV]] = true;
	} 
	
	if (step[nodeU] == low[nodeU]){ //van con giu nguyen
		//result++;
		int nodeV;
		do {
			nodeV = st.top();
			st.pop();
			onStack[nodeV] = false; 
			low[nodeV] = step[nodeU];
			boss[nodeV] = nodeU;
		} while (nodeV != nodeU);
	}
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
	boss.assign(n,-1);
	onStack.assign(n,false);
	children.assign(n,false);
	for (int i = 0; i < n; i++) if (step[i]==-1) dfs(i), children[i] = false;
	//bigGraph();
	//for (int i = 0; i < n; i++) cout << children[i] << " "; cout << endl;
	
	//dfs(0); => 1
	//cout << result;
	cout << count(children.begin(),children.end(),false);
}

int main(){
	solve();
	
	return 0;
}
