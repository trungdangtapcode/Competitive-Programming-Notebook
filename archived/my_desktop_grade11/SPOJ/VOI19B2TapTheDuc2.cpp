#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
long long int INF = 1e16;
int n, m, k, s[20], t[20], p[20];

typedef pair< long long int, pair<pair <long long int, int > ,pair<int, int> > > id; //{kc,{{l,v},{i,kho}}}
vector <id> edge[100005], unEdge[20][100005];
vector <long long int> d;
typedef pair< pair<bool,int>,pair<long long int, bool >> idDanhDau; // {thuoc Nam, chieu tu u}{khoang cach tu s, ok}
idDanhDau danhdau[100005];
bool danhdaucanhK[100005][20], inPath[100005];
long long int dp[100005][40];
int soBanDeTinh, thuTuBanDeTinh[20];
//bool DPcoDangChungMotKhoangDuong[100005][40][6]; //khoang duong not doan duong, 1 ban chi di chung dung 1 lan
//int lastDanhdau[100005][6]; //tro
bool dpThreadEnded[100005][40][6], dpThreadOpen[100005][40][6];
int dpSoBanDiChung[100005][40][6];

void dijsktra(int x, int y){
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push({0,{{-1,x},{-1,-1}}});
	
	while (!pq.empty()){
		int nodeU = pq.top().second.first.second;
		long long int distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it.second.first.second;
			long long int distUV = it.second.first.first;
			int wayV = it.second.second.first;
			int khoV = p[y];
			
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU + distUV;
				pq.push({d[nodeV],{{-1,nodeV},{-1,-1}}});
				unEdge[y][nodeV].clear();
				unEdge[y][nodeV].push_back({d[nodeU],{{distUV,nodeU},{wayV,khoV}}});
			} else if (distU+distUV==d[nodeV]) unEdge[y][nodeV].push_back({d[nodeU],{{distUV,nodeU},{wayV,khoV}}});
		}
	}
	return;
}
void initDanhDau(int x){
	memset(inPath,false,sizeof(inPath));
	inPath[s[1]] = true;
	memset(danhdau,0,sizeof(danhdau));
	vector <bool> visited (n+1,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		inPath[nodeU] = true;
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[1][nodeU]){
			int nodeV = it.second.first.second;
			int wayV = it.second.second.first;
			long long int distV = it.first;
			//long long int distUV = it.second.first.first;
			//cout << " - "<<wayV << endl;
			danhdau[wayV] = {{true,nodeV},{distV,false}}; //luu y: dang di nguoc
			if (nodeV!=s[1]) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}
void editDanhDau(int x, int y){
	//memset(danhdaucanhK,false,sizeof(danhdaucanhK));
	vector <bool> visited (n+1,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[y][nodeU]){
			int nodeV = it.second.first.second;
			int wayV = it.second.second.first;
			long long int distV = it.first;
			bool checkPath = danhdau[wayV].first.first;
			int checkNodeV = danhdau[wayV].first.second;
			long long int checkDistV = danhdau[wayV].second.first;
			int khoV = p[y];
			
			//cout<< nodeU << " " << nodeV << "-> so sanh: " << checkPath << " && " << nodeV << "==" << checkNodeV<< " && " << distV << "==" << checkDistV << "   " << khoV << endl;
			if (checkPath&&(nodeV==checkNodeV)&&((khoV==0&&distV==checkDistV)||khoV==1)) danhdau[wayV].second.second = true, danhdaucanhK[wayV][y] = true;
			
			if (nodeV!=s[y]) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}
vector <int> topo;
void toposort(){
	queue <int> listSource;
	int inDeg[100005];
	memset(inDeg,0,sizeof(inDeg));
	for (int i = 1; i <= n; i++)if (inPath[i]){
		for (auto& it : unEdge[1][i]) inDeg[it.second.first.second]++;
	}
	for (int i = 1; i <= n; i++)
    	if (!inDeg[i]&&inPath[i]) listSource.push(i), inDeg[i]--;
    
	while (!listSource.empty()) {
		int u = listSource.front();
		listSource.pop();
		topo.push_back(u);
		for (auto it : unEdge[1][u]) {
			int v = it.second.first.second;
			inDeg[v]--;
			if (!inDeg[v]) listSource.push(v), inDeg[v]--;
		}
	}
	return;
}

//bool visited[100005];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ifstream fi("input.inp");
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		edge[a].push_back({-1,{{c,b},{i,-1}}});
		edge[b].push_back({-1,{{c,a},{i,-1}}});
	}
	cin >> s[1] >> t[1]; p[1] = 0;
	for (int i = 2; i <= k; i++){
		cin >> p[i] >> s[i] >> t[i];
		if (p[i]) thuTuBanDeTinh[++soBanDeTinh] = i;
	}
	
	for (int i = 1; i <= k; i++){
		d.assign(n+1,INF);
		d[s[i]] = 0;
		dijsktra(s[i],i);
		//if (i==1) cout << d[t[1]] << endl;
	}
	initDanhDau(t[1]);
	memset(danhdaucanhK,false,sizeof(danhdaucanhK));
	for (int i = 2; i <= k; i++) editDanhDau(t[i],i);
	
	toposort();
	//for (auto& it : topo) cout << it << " "; cout << endl;
	//for (int i = 1; i <= n; i++) cout << inPath[i] <<" ";
	for (int i = 1; i <= n; i++) for (int j = 0; j < (1<<(soBanDeTinh+1)); j++) dp[i][j] = -INF;
	for (int j = 0; j < (1<<(soBanDeTinh+1)); j++) dp[t[1]][j] = 0;
	
	//memset(DPcoDangChungMotKhoangDuon,true,sizeof(DPcoDangChungMotKhoangDuon));
	memset(dpThreadEnded,false,sizeof(dpThreadEnded));
	memset(dpThreadOpen,false,sizeof(dpThreadOpen));
	memset(dpSoBanDiChung,0,sizeof(dpSoBanDiChung));
	//for (int i = 0; i < 6; i++) lastDanhdau[topo[0]][i] = topo[0];
	//bitmask 0001001 (.....so 2....so 1)
	for (int i = 0; i < topo.size(); i++) for (auto it : unEdge[1][topo[i]]){
		int u = topo[i];
		int v = it.second.first.second;
		int wayV = it.second.second.first;
		
		cout << u<< " " << v << ": ";
		for (int j = 0; j < (1<<(soBanDeTinh)); j++){
			
			bool coAiKhoTinhDiQuaHong = false;
			for (int t = 1; t <= k; t++) if (p[t]==0&&danhdaucanhK[wayV][t]) coAiKhoTinhDiQuaHong = true;//, cout << t << "<- ";
			//if (coAiKhoTinhDiQuaHong) dp[v][j] = max(dp[v][j],dp[u][bitmask]+it.second.first.first);
			
			for (int bitmask = 0; bitmask < (1<<(soBanDeTinh)); bitmask++){
				long long int distUV = 0;
				if (coAiKhoTinhDiQuaHong) distUV = it.second.first.first;
				int x = j,y = bitmask, soBanTrenDoanDuongNay = 0;
				bool check = true;
				for (int t = 1; t <= soBanDeTinh; t++){
					//dpThreadOpen[v][j][t] = (x%2==1&&danhdaucanhK[wayV][thuTuBanDeTinh[t]])||(dpThreadOpen[u][j][t]);
					//dpThreadEnded[v][j][t] = (dpThreadOpen[v][j][t]&&danhdaucanhK[wayV][thuTuBanDeTinh[t]]==false)||(dpThreadEnded[u][j][t]);
					//cout << dpThreadEnded[v][j][t] << endl;
					if (danhdaucanhK[wayV][thuTuBanDeTinh[t]]&& ((x%2==1&&y%2==0)||(x%2==1&&!dpThreadEnded[u][bitmask][t])) ) distUV = it.second.first.first;
					if (y%2>x%2) check = false; 
					//if (y%2==1||x%2==1) soBanTrenDoanDuongNay++;
					//DPcoDangChungMotKhoangDuong[v][j][t] = (DPcoDangChungMotKhoangDuong[u][bitmask][t]&&!danhdaucanhK[wayV][thuTuBanDeTinh[t]]);
					x /= 2;
					y /= 2;
				}
				//||(dp[u][bitmask]+distUV==dp[v][j]&&soBanDiChung[u][bitmask]+soBanTrenDoanDuongNay<soBanDiChung[v][j])
				if (check&&dp[u][bitmask]+distUV>dp[v][j]) {
					dp[v][j] = dp[u][bitmask]+distUV;
					int x = j,y = bitmask;
					//soBanDiChung[v][j] = soBanDiChung[u][bitmask]+soBanTrenDoanDuongNay;
					for (int t = 1; t <= soBanDeTinh; t++){
						dpThreadEnded[v][j][t] = (dpThreadOpen[u][bitmask][t]&&danhdaucanhK[wayV][thuTuBanDeTinh[t]]==false)||(dpThreadEnded[u][j][t]);
						dpThreadOpen[v][j][t] = (x%2==1&&danhdaucanhK[wayV][thuTuBanDeTinh[t]])||(dpThreadOpen[u][bitmask][t]);
						x /= 2;
						y /= 2;
					}
				}
			}
			
			cout << dp[v][j] << "{" << dpThreadEnded[v][j][1]<<"-" << dpThreadOpen[v][j][1] << "} ";
		}
		cout <<endl;
	}
	cout << dp[s[1]][(1<<soBanDeTinh)-1]; //s[1] last topo
	
	//for (int i = 0; i <= n; i++) for (int j = 0; j <= (1<<(k-1)); j++) dp[i][j] = -1;
	//for (int j = 0; j <= (1<<(k-1)); j++) dp[s[1]][j] = 0;
	//memset(visited,false,sizeof(visited));
	//dfs(t[1]);
	//toposort();;
	
	
	
	//for (int i = 1; i <= n; i++) cout << tongS[i] << " "; cout << endl;
	
	//for (int i = 1; i <= m ; i++) cout << "{"<< danhdau[i].first.first<<","<<danhdau[i].first.second<<","<< danhdau[i].second.first<<","<<danhdau[i].second.second << "} " ; cout << endl;
	
	//cout << tongS[s[1]];	
	//cout << s[2] << " -> " <<t[2] << endl;
	//cout <<  d[t[2]] << '\n';
//	for (int i = 1; i<= n;i++){
//		cout << i <<":  ";
//		for (auto&  it: unEdge[1][i]){
//			cout << " {"<<it.second.first.second<<","<<it.second.first.first<<","<<it.second.second.first<<","<<it.first<<","<<it.second.second.second<<"} ";
//		}
//		cout << endl;
//	}
	//for (int i = 1; i <= m; i++) cout << i << " " << danhdau[i] << endl;
	
	
	
	return 0;
}


//void dfs(int nodeU){
//	visited[nodeU] = true;
//	for (auto& it: unEdge[1][nodeU]){
//		int nodeV = it.second.first.second;
//		int wayV = it.second.second.first;
//		//long long int distUV = it.second.first.first;
//		for (int bitmask = 0; bitmask <= (1<<(k-1)); bitmask++){
//			long long int res = 0;
//			for (int i = 0; i <= (1<<(k-1)); i++){
//				
//			}
//			
//		}
//		
//	}
//	return;
//}
