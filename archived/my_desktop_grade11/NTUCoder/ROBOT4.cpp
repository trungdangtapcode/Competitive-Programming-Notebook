#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

typedef pair<int, int> toado;
typedef pair<pair<int,int>, toado> id;
int n, m, x, y;
bool a[300][300];
int d[300][300];
int INF = 1e5;
toado trace[300][300];
//0 = Bac, 1 = Dong, 2 = Nam, 3 = Tay, (INPAST)

void dijsktra(toado x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push({{1,2},x});
	
	while (!pq.empty()){
		toado nodeU = pq.top().second;
		int distU = pq.top().first.first;
		int pastU = pq.top().first.second;
		pq.pop();
		
		if (nodeU.first>n||nodeU.second<1||nodeU.second>m||nodeU.second<1) continue; //wall
		if (distU!=d[nodeU.first][nodeU.second]||a[nodeU.first][nodeU.second]) continue;
		
		//cout << nodeU.first<<" " << nodeU.second << " = " <<d[nodeU.first][nodeU.second] << " | " <<trace[nodeU.first][nodeU.second].first<<" "<<trace[nodeU.first][nodeU.second].second << " Past = " << pastU<< endl;
		if (pastU == 0){ //Bac -> Bac or Tay
			toado nodeV = {nodeU.first-1,nodeU.second};  //DIT ME NHAM ÐTNB VOI OXY (X VA Y BI NGUOC, x la doc, y la ngang moi dung)
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],0},nodeV});
			}
			nodeV = {nodeU.first,nodeU.second-1}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],3},nodeV});
			}
		}
		if (pastU == 1){ //Dong -> Dong or Bac
			toado nodeV = {nodeU.first,nodeU.second+1}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],1},nodeV});
			}
			nodeV = {nodeU.first-1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],0},nodeV});
			}
		}
		if (pastU == 2){ //Nam -> Nam or Dong
			toado nodeV = {nodeU.first+1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],2},nodeV});
			}
			nodeV = {nodeU.first,nodeU.second+1}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],1},nodeV});
			}
		}
		if (pastU == 3){ //Tay -> Tay or Nam
			toado nodeV = {nodeU.first,nodeU.second-1}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],3},nodeV});
			}
			nodeV = {nodeU.first+1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
				trace[nodeV.first][nodeV.second] = nodeU;
				pq.push({{d[nodeV.first][nodeV.second],2},nodeV});
			}
		}
//		if (pastU == -1){ //Dong or Nam
//			toado nodeV = {nodeU.first,nodeU.second+1}; 
//			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
//				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
//				trace[nodeV.first][nodeV.second] = nodeU;
//				pq.push({{d[nodeV.first][nodeV.second],1},nodeV});
//			}
//			nodeV = {nodeU.first+1,nodeU.second}; 
//			if (d[nodeU.first][nodeU.second]+1<d[nodeV.first][nodeV.second]){
//				d[nodeV.first][nodeV.second] = d[nodeU.first][nodeU.second]+1;
//				trace[nodeV.first][nodeV.second] = nodeU;
//				pq.push({{d[nodeV.first][nodeV.second],2},nodeV});
//			}
//		}
	}
}

void truyvet(toado x){
	//if (trace[x.first][x.second]==toado{-1,69}) return;
	toado y = trace[x.first][x.second];
	if (y!=toado{-1,69}) truyvet(y);
	cout << x.first << " " << x.second << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m; //>> x >> y; //DIT ME MAY X Y
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	cin >> x >> y;
	
	trace[1][1] = {-1,69};
	memset(d,1,sizeof(d));	
	d[1][1] = 1;
	dijsktra({1,1});
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) cout << d[i][j] << " ";
//		cout << endl;	
//	}
	if (d[x][y]>500) cout << 0; 
	else{
		cout << d[x][y] << endl;
		truyvet({x,y});
	}
	return 0;
}
