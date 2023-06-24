#include<bits/stdc++.h>

using namespace std;

const bool ch[] = {1,1,0,0,0,0,1,0,1,1};

int main(){
	
	int n, m; cin >> n >> m;
	for (int i = n; i <= m; i++){
		int tmp = i;
		bool check = true;
		while (tmp){
			if (!ch[tmp%10]){
				check = false;
				break;
			}
			tmp /= 10;
		}
		if (check) cout << i << " ";
	}
	
	return 0;
}
