#include<bits/stdc++.h>

using namespace std;
int n, m, n1, n2;
long long k, a1[100005], a2[100005], b[100005];
long long cntGreater(long long x){
	long long res = 0;
	for (int i = 1, j = m; i <= n1; i++){
		while (j>1&&a1[i]*b[j]>x) j--;
		while (j<m&&a1[i]*b[j+1]<=x) j++;
//		j--;
		if (a1[i]*b[j]<=x){
			res += j;
		}
	}
	for (int i = 1, j = 1; i <= n2; i++){
		while (j<m&&a2[i]*b[j]>x) j++;
		while (j>1&&a2[i]*b[j-1]<=x) j--;
//		j++;
		if (a2[i]*b[j]<=x){
			res += m-j+1;
		}
	}
	return res;
}

int main(){
	cin >> k >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		if (a>=0) a1[++n1] = a; else a2[++n2] = a;
	};
	cin >> m; for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a1+1,a1+n1+1);
	sort(a2+1,a2+n2+1);
	sort(b+1,b+m+1);
	long long l = -1e18, h = 1e18, m, res;
	while (l<=h){
		m = l+h>>1;
		if (cntGreater(m)>=k){
			res = m;
			h =  m-1;
		} else l = m+1;
	}
	cout << res;
	
	
	return 0;
}
