#include<bits/stdc++.h>
//cay: m = n - 1
//co tplt cay thi m = n - tplt
//cu them 1 canh thi co them 1 chu trinh (luc dau cay co 0 chu trinh)
//=> m = n - tplt + ans => ans = m - n + tplt = so chu trinh
//o day ta tinh truc tiep (ko dung cong thuc)

using namespace std;
#define int long long
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> va, vb;
int cha[100005], n, m;

int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}
void reset(){
	for (int i = 1; i <= n; i++) cha[i] = i;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	reset();
	int res = 0;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		if (!hop(u,v)) res++;
	}
	cout << res;
	
	
	return 0;
}
