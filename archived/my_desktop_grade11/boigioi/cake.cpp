

#include <bits/stdc++.h>

using namespace std;
int n;
long long s;
int b[105];

bool check(long long int x){
	long long int res = 0;
	for (int i = 0; i < n; i++) res += (x/b[i]);
	return (res>=s);
}

int main(){
	
	cin >> s >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	//sort(b,b+n);
	
	
	long long int res = 0, l = 0, h = s*500+5, m;
	while (l <= h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			h = m -1;
		} else l = m + 1;
	}
	
	cout << res;
	
	
	return 0;
}
