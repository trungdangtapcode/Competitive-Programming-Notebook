#include <bits/stdc++.h>

using namespace std;
int n, deg[4005];
long long int a[4005];
vector <int> edge[4005];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) if (abs(a[i]-a[j])==1||abs(a[i]-a[j])==8||abs(a[i]-a[j])==9){
			edge[i].push_back(j);
			deg[i]++;
		}
	}
	
	//bool clean = false;
	int cnt = 0;
	while (true){
		int res = -1, j = -1;
		for (int i = 0; i < n; i++) if (deg[i]>res) res = deg[i], j = i;
		if (res==0) break;
		deg[j] = 0;
		for (auto& it: edge[j]){
			if (deg[it]!=0) deg[it]--;
		}
		cnt++;
	}
	cout << cnt;
	
	return 0;
}
