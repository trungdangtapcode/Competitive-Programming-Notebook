#include<bits/stdc++.h>

using namespace std;
int n, m, res1, res2, sign[] = {0,1};
char c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
//			c = getchar();
			cin >> c;
			res1 += abs(c-'0'-(i+j)&1);
			res2 += abs(c-'0'-(!((i+j)&1)));
		}
//		getchar();
	}
	cout << min(res1,res2);
	
	return 0;
}
