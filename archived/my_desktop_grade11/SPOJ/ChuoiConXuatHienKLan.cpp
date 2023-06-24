#include <bits/stdc++.h>

using namespace std;

int hashS[50005], basepow[50005], n, k;
string s;
const int p = 1e9+7, base = 31;
unordered_map<int,int> cnt;

int getHash(int x, int y){
	return (hashS[y]-1ll*hashS[x-1]*basepow[y-x+1]+1ll*p*p)%p;
}

bool check(int x){
	cnt.clear();
	for (int i = 1, tmp; i <= n-x+1; i++){
		tmp = getHash(i,i+x-1);
		cnt[tmp]++;
		if (cnt[tmp]>=k) return true;
	}
	return false;
}

int main(){
	basepow[0] = 1;
	for (int i = 1; i <= 50000; i++) basepow[i] = (1ll*basepow[i-1]*base)%p;
	
	cin >> n >> k >> s;
	s = " " + s;
	
	for (int i = 1; i <= n; i++){
		hashS[i] = (1ll*hashS[i-1]*base+s[i]-'a'+1)%p;	
	}
	
	int res = 0, l = 0, h = n, m;
	while (l<=h){
		m = (l+h)>>1;
		if (check(m)){
			res = m;
			l = m + 1;
		} else h = m - 1;
	}
	cout << res;
	
//	cout << getHash(1,3)-getHash(4,6);
	
	return 0;
}
