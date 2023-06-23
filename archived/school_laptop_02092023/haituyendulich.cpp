#include<bits/stdc++.h>

using namespace std;

int a[1000005], mp[1000005], n, res_x, res_y;
string s;
bool check(int x){
	memset(mp,0,sizeof(mp));
	for (int i = 1, j = x; j <= n; i++, j++){
		if (mp[a[j]-a[i-1]]){
			res_x = mp[a[j]-a[i-1]];
			res_y = i;
			return true;
		}
		mp[a[j]-a[i-1]] = i;
	} 
	return false;
}

int main(){
	ios:sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	cin >> s;
	n = s.length();
	s = "#" + s;
	for (int i = 1; i <= n; i++){
		a[i] = s[i] - '0';
		a[i] += a[i-1];
	}
	int l = 1, h = n, m, res;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			l = m+1;
		} else h = m-1;
	}
	cout << res_x << " " << res_x+res-1 << " " << res_y << " " << res_y+res-1;
	
	
	return 0;
}
