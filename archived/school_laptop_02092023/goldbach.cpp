#include<bits/stdc++.h>

using namespace std;
bool p[1000005];
int n;

int main(){
	cin >> n;
	memset(p,1,sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i*i<=n; i++) if (p[i]) for (int j = i*i; j <= n; j+=i) p[j] = false;
	int res = 0;
	for (int i = 2; 2*i <= n; i++) if (p[i]&&p[n-i]) res++;
	cout << res;
	return 0;
}
