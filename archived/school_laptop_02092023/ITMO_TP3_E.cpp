#include<bits/stdc++.h>

using namespace std;
int n;
long long int s, w[100005], c[100005], curw, curc, res;
int main(){
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0, j = -1; i < n; i++){
		while (j<n&&curw<=s) j++, curw += w[j], curc += c[j];
		curw -= w[j], curc -= c[j], j--;
		if (curw<=s){
			res = max(res,curc);
		}
		curw -= w[i], curc -= c[i];
	}
	cout << res;
	
	return 0;
}
