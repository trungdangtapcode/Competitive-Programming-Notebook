#include<bits/stdc++.h>

using namespace std;

long long w[20005], d[20005], sufW[20005], sufD[20005], sufWD[20005];
int best[20005], n;
long long cost(int i, int j){
	return sufWD[i]-sufWD[j+1]-(sufW[i]-sufW[j+1])*sufD[j];
}
long long eval(int i, int j){
	return cost(1,i)+cost(i+1,j)+cost(j+1,n+1);
}
void solve(int l, int r, int from, int to){
	if (l>r) return;
	int m = (l+r)/2;
	best[m] = from;
	for (int i = from+1; i <= to; i++) if (eval(m,best[m])>eval(m,i)) best[m] = i;
	solve(l,m-1,from,best[m]);
	solve(m+1,r,best[m],to);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> w[i] >> d[i];
	}
	for (int i = n; i > 0; i--){
		sufW[i] = w[i] + sufW[i+1];
		sufD[i] = d[i] + sufD[i+1];
		sufWD[i] = w[i]*sufD[i] + sufWD[i+1];
	}
	solve(1,n,1,n);
	long long res = 1e16;
	for (int i = 1; i <= n; i++) res = min(res,eval(i,best[i]));
	cout << res << "\n";
//	for (int i = 1; i <= n; i++) cout << best[i] << " ";
	
	
	return 0;
}
