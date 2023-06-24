#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int n, m, t, Cmin;
long long int k;
vector<int> edge[1005], res;
int c[1005][1005], d[1005];
const int INF = 1e9;
int in1, in2, in3;

bool inPath[1005], inPath_visited[1005];
bool inPath_get(int u){
	if (u==t) return inPath[u] = true; //ket thuc de quy
	if (inPath_visited[u]) return inPath[u]; //visited tranh loop
	inPath_visited[u] = true;
	for (auto& v: edge[u]) inPath[u] |= inPath_get(v);
	return inPath[u];
}

void dijkstra(int x){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0,x});
	
	while (!pq.empty()){
		int nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		
		if (d[nodeU]!=distU) continue;
		for (auto& nodeV: edge[nodeU]){
			int distUV = c[nodeU][nodeV];
			if (d[nodeV]>distU+distUV){
				d[nodeV] = distU+distUV;
				pq.push({d[nodeV],nodeV});
			}
		}
	}
	return;
}

long long int dp[1005][105];
long long int getDP(int nodeU, int distU){
//	cout << nodeU << " " << distU << "  " << d[nodeU] << endl;
	if (distU>d[nodeU]+Cmin||!inPath[nodeU]) return 0; //gio ngu roi tuong lai van ngu (ko thoa)	
	if (dp[nodeU][distU-d[nodeU]]!=-1) return dp[nodeU][distU-d[nodeU]]; 
	//[distU-d[nodeU]] de giam bo nho. same range; 
	//thoa: d[nodeU]<=distU<=d[nodeU]+Cmin (range)
	
	if (nodeU==t) dp[nodeU][distU-d[nodeU]]=1; //0
	else dp[nodeU][distU-d[nodeU]] = 0;
	for (auto& nodeV: edge[nodeU]){
		int distUV = c[nodeU][nodeV]; //cout << "("<< nodeU << ","<<nodeV<<") "<<c[nodeU][nodeV]<<'\n';
		dp[nodeU][distU-d[nodeU]] += getDP(nodeV,distU+distUV);
	}
	return dp[nodeU][distU-d[nodeU]];
}

void calc(int nodeU, int distU){
	if (distU>d[nodeU]+Cmin||!inPath[nodeU]) return;
//	cout << nodeU << " " << distU << "   k = " << k << endl;
	res.push_back(nodeU);
	
	if (nodeU==t) k--;
	for (auto& nodeV: edge[nodeU]){
		int distUV = c[nodeU][nodeV];
		if (k>getDP(nodeV,distU+distUV)) k -= getDP(nodeV,distU+distUV);
		else {
			calc(nodeV,distU+distUV);
			break;
		}
	}
	return;
}

int main(){
	
	cin >> n >> m >> t >> k;
	//init
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) c[i][j] = INF;
	for (int i = 1; i <= n; i++) for (int j = 0; j <= 100; j++) dp[i][j] = -1;
	
	Cmin = INF;
	for (int i = 0; i < m; i++){
		cin >> in1 >> in2 >> in3;
		Cmin = min(Cmin,in3);
		c[in1][in2] = in3;
		edge[in1].push_back(in2);
	}
	//init
	for (int i = 1; i <= n; i++) sort(edge[i].begin(),edge[i].end());
	inPath_get(1);
	if (!inPath[1]) {cout << -1 << '\n'; return 0;}
	for (int i = 1; i <= n; i++) d[i] = INF; d[1] = 0;
	
	dijkstra(1);
	getDP(1,0);
	calc(1,0);
	if (k>dp[1][0]) {cout << -1; return 0;}
	if (res.back()==t||true){
		cout << res.size() << '\n';
		for (auto& it: res) cout << it << " ";
	} else cout << -1 << endl;
	
	cout << endl;
//	for (int i = 1; i <= n; i++) cout << getDP(3,2) << " "; cout << endl;
	return 0;
}
