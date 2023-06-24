//do h[i] doi 1 khac nhau => co the O(n^2). h[i] <= n

#include <bits/stdc++.h>

using namespace std;
int h[1005], p[1005], a, b, res = 0, n;
bool used[1005]; //used[~height] -> boolean

int main(){
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) if (!used[h[i]]){
		int cur = -1; //cur~h[i]
		for (int j = 1, better = 0; j <= n; j++) if (!used[j]){ //j~h[i], better~i
			if (better==p[i]) {
				if (j>h[i]) cur = j;
				break;
			}
			better++;
		}
		if (cur!=-1) { 
			res += b;
			used[cur] = true;
		} else res += a;
		used[h[i]] = true;
	}
	cout << res;
	
	return 0;
}
