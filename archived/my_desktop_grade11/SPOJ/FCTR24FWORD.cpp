#include <bits/stdc++.h>

using namespace std;
string s, sK[505];
int pos[505], posK[505], n, m, k;
long long int x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k >> x;
	cin >> s;
	for (int i = 0; i < m; i++) cin >> sK[i], sort(sK[i].begin(),sK[i].end());
	for (int i = 0, j = 0; i < n; i++) if (s[i]=='#') pos[j++] = i; 
	
	x--;
	memset(posK,0,sizeof(posK));
	for (int i = m-1; x > 0; x /= k, i--)
		posK[i] = x%k; 
	
	for (int i = 0; i < m; i++){
		s[pos[i]] = sK[i][posK[i]];
	}
	cout << s << '\n';
	
	return 0;
}
