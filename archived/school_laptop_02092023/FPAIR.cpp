#include<bits/stdc++.h>

using namespace std;
int n, m, k, p[100005];
vector<int> v1[20], v2[20];
bool check_group[20][100005];

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		cin >> p[i];
	}
	for (int i = 0; i < k; i++){
		for (int j = 1; j < 19; j++){
			if ((i%(1<<j))<(1<<(j-1))){
				v1[j].push_back(i);
				check_group[j][i] = true;
			} else v2[j].push_back(i);
		}
	}
	for (int i = 1; i < 6; i++){
//		for (auto x: v1[i]) cout << x << " ";
//		cout << "  vs  ";
//		for (auto x: v2[i]) cout << x << " ";
		for (int j = 0; j < k; j++) cout << check_group[i][j] << " ";
		cout << endl;
	}
	
//	dijkstra(idx);
	
	return 0;
}
