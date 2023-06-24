#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

typedef pair<int, int> toado;
typedef pair<pair<int,int>, toado> id;
int n, m, x, y;
bool a[300][300];
int d[300][300][5];
//trace[300][300][5];
int INF = 1e5;
//0 = Bac, 1 = Dong, 2 = Nam, 3 = Tay, (INPAST)

void dijsktra(toado x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push({{1,2},x});
	
	while (!pq.empty()){
		toado nodeU = pq.top().second;
		int distU = pq.top().first.first;
		int pastU = pq.top().first.second;
		pq.pop();
		
		if (nodeU.first>n||nodeU.first<1||nodeU.second>m||nodeU.second<1) continue; //wall
		if (distU!=d[nodeU.first][nodeU.second][pastU]||a[nodeU.first][nodeU.second]) continue;
		
		//cout << nodeU.first<<" " << nodeU.second << " = " <<d[nodeU.first][nodeU.second][pastU] << " | " << " Past = " << pastU<< endl;
		if (pastU == 0){ //Bac -> Bac or Tay
			toado nodeV = {nodeU.first-1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second][0]+1<d[nodeV.first][nodeV.second][0]){
				d[nodeV.first][nodeV.second][0] = d[nodeU.first][nodeU.second][0]+1;
				pq.push({{d[nodeV.first][nodeV.second][0],0},nodeV});
			}
			nodeV = {nodeU.first,nodeU.second-1}; 
			if (d[nodeU.first][nodeU.second][0]+1<d[nodeV.first][nodeV.second][3]){
				d[nodeV.first][nodeV.second][3] = d[nodeU.first][nodeU.second][0]+1; //3 3
				pq.push({{d[nodeV.first][nodeV.second][3],3},nodeV});
			}
		}
		if (pastU == 1){ //Dong -> Dong or Bac
			toado nodeV = {nodeU.first,nodeU.second+1}; 
			if (d[nodeU.first][nodeU.second][1]+1<d[nodeV.first][nodeV.second][1]){
				d[nodeV.first][nodeV.second][1] = d[nodeU.first][nodeU.second][1]+1;
				pq.push({{d[nodeV.first][nodeV.second][1],1},nodeV});
			}
			nodeV = {nodeU.first-1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second][1]+1<d[nodeV.first][nodeV.second][0]){
				d[nodeV.first][nodeV.second][0] = d[nodeU.first][nodeU.second][1]+1;
				pq.push({{d[nodeV.first][nodeV.second][0],0},nodeV});
			}
		}
		if (pastU == 2){ //Nam -> Nam or Dong
			toado nodeV = {nodeU.first+1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second][2]+1<d[nodeV.first][nodeV.second][2]){
				d[nodeV.first][nodeV.second][2] = d[nodeU.first][nodeU.second][2]+1;
				pq.push({{d[nodeV.first][nodeV.second][2],2},nodeV});
			}
			nodeV = {nodeU.first,nodeU.second+1}; 
			if (d[nodeU.first][nodeU.second][2]+1<d[nodeV.first][nodeV.second][1]){
				d[nodeV.first][nodeV.second][1] = d[nodeU.first][nodeU.second][2]+1;
				pq.push({{d[nodeV.first][nodeV.second][1],1},nodeV});
			}
		}
		if (pastU == 3){ //Tay -> Tay or Nam
			toado nodeV = {nodeU.first,nodeU.second-1}; 
			if (d[nodeU.first][nodeU.second][3]+1<d[nodeV.first][nodeV.second][3]){
				d[nodeV.first][nodeV.second][3] = d[nodeU.first][nodeU.second][3]+1;
				pq.push({{d[nodeV.first][nodeV.second][3],3},nodeV});
			}
			nodeV = {nodeU.first+1,nodeU.second}; 
			if (d[nodeU.first][nodeU.second][3]+1<d[nodeV.first][nodeV.second][2]){
				d[nodeV.first][nodeV.second][2] = d[nodeU.first][nodeU.second][3]+1;
				pq.push({{d[nodeV.first][nodeV.second][2],2},nodeV});
			}
		}
	}
}



pair<int, int> maxD(toado x){
	int ans = INF, k;
	for (int i= 0; i < 4; i++) if (ans>d[x.first][x.second][i]) ans=d[x.first][x.second][i], k = i;
	return {ans,k}; 
	//return {max(max(d[x.first][x.second][0],d[x.first][x.second][1]),max(d[x.first][x.second][2],d[x.first][x.second][3])),}
}
toado trace(toado x, int a){
	//int a = maxD(x).second; //di nguoc
	if (a==0) return {x.first+1,x.second};
	if (a==1) return {x.first,x.second-1};
	if (a==2) return {x.first-1,x.second};
	if (a==3) return {x.first,x.second+1};
}
int tima(toado x, int s){
	for (int i = 0; i < 4; i++) if (d[x.first][x.second][i]==s) return i;
}
void truyvet(toado x, int a){
	toado y = trace(x,a);
	if (y!=toado{0,1}) truyvet(y,tima(y,d[x.first][x.second][a]-1));
	cout << x.first << " " << x.second << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
	cin >> x >> y;
	
	memset(d,1,sizeof(d));	
	d[1][1][2] = 1;
	dijsktra({1,1});
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) cout << d[i][j][2]<< " ";
//		cout << endl;	
//	}
	if (maxD({x,y}).first>500) cout << 0; 
	else{
		cout << maxD({x,y}).first << endl;
		truyvet({x,y},maxD({x,y}).second);
	}
	return 0;
}
