#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> edge[500005];
int n, k, beginning;
bool inK[500005];
long long int nearest[500005], farest1[500005], farest2[500005], totalK;
int brance[500005];
void calcInK(int u, int p){
	for (auto it: edge[u]){
		int v = it.first;
		int c = it.second;
		if (v==p) continue; //do thi cay nen khong can visited[]
		calcInK(v,u);
		inK[u] |= inK[v];
		if (inK[v]) totalK += c;
	}
}
void calcNearest(int u, int p, int c){
	if (inK[u]) nearest[u] = 0; else nearest[u] = nearest[p] + c;

	for (auto it: edge[u]){
		int v = it.first;
		int c = it.second;
		if (v==p) continue;
		calcNearest(v,u,c);
	}
}
void calcFarest1(int u, int p){ //farest[beginning] is right then calc2 can calc all farest
	for (auto it: edge[u]){
		int v = it.first;
		int c = it.second;
		if (v==p) continue;
		if (!inK[v]) c = 0;
		calcFarest1(v,u);
		if (farest1[u] < farest1[v] + c){
			farest2[u] = farest1[u];
			farest1[u] = farest1[v] + c;
			brance[u] = v;
		} else if (farest2[u]<farest1[v] + c){
			farest2[u] = farest1[v] + c;
		};
	}
}
void calcFarest2(int u, int p, int c){
	long long int x = (brance[p]==u?farest2[p]:farest1[p])+c;
	if (farest1[u] < x){
		farest2[u] = farest1[u];
		farest1[u] = x;
		brance[u] = p;
	} else if (farest2[u] < x){
		farest2[u] = x;
	};
	for (auto it: edge[u]){
		int v = it.first;
		int c = it.second;
		if (v==p) continue;
		if (!inK[v]) c = 0;
		calcFarest2(v,u,c);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1, in1, in2, in3; i < n; i++){
		cin >> in1 >> in2 >> in3;
		edge[in1].push_back({in2,in3});
		edge[in2].push_back({in1,in3});
	}
	for (int i = 0; i < k; i++){
		cin >> beginning;
		inK[beginning] = true;
	}
	calcInK(beginning,-1);
	calcNearest(beginning,-1,0);
	calcFarest1(beginning,-1);
	calcFarest2(beginning,-1,0);
//	for (int i = 1; i <= n; i++) cout << farest1[i] << " ";
	for (int i = 1; i <= n; i++) cout << nearest[i]+totalK*2-farest1[i] << '\n';
	
	return 0;
}


//	if (inK[u]) nearest[u] = 0; else nearest[u] = nearest[v] + c;
//		if (inK[v]) nearest[v] = 0; else nearest[v] = nearest[p] + c;

//	cout << u << " " << p << " " << c << " "; //nearest[] not boolean
//
//	cout << inK[u] << " " << nearest[u] << " " << nearest[p]+c << endl;
