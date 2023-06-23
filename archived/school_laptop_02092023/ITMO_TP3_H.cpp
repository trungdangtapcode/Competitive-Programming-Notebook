#include<bits/stdc++.h>

using namespace std;
int n, m;
long long int wa, wb, a[100005], b[100005], s, res, cur;
int main(){
	cin >> n >> m >> s >> wa >> wb;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a+1,a+n+1,[](long long int a, long long int b){ return (a>b);});
	sort(b+1,b+m+1,[](long long int a, long long int b){ return (a>b);});
	for (int i = 1; i <= m; i++) cur += b[i];
	for (int i = 0, j = m; i <= n; i++){
		cur += a[i];
		while (j>0&&wa*i+wb*j>s) cur -= b[j--];
		if (wa*i+wb*j<=s){
			res = max(res,cur);
		}
	}
	cout << res;
	
	return 0;
}
