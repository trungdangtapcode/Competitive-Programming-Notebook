#include<bits/stdc++.h>

using namespace std;

int val[1000005], cnt[1000005];
void updt(int k, int l, int r, int u, int v, int x){
	if (u>r||l>v) return;
	if (u<=l&&r<=v){
		cnt[k] += x;
		if (cnt[k]) val[k] = r-l+1;
		else if (l!=r) val[k] = val[2*k]+val[2*k+1]; else val[k] = 0; 
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	if (cnt[k]) val[k] = r-l+1;
	else val[k] = val[2*k] + val[2*k+1];
}
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;
int n;
vector<i4> vec;
int main(){
//	updt(1,0,30000,10,19,1);
//	updt(1,0,30000,15,29,1);
//	updt(1,0,30000,10,19,-1);
//	cout << val[1];
	cin >> n;
	for (int i = 0, x, y, u, v; i < n; i++){
		cin >> x >> y >> u >> v;
		vec.push_back({{x,1},{y,v-1}});
		vec.push_back({{u,-1},{y,v-1}});
	}
	sort(vec.begin(),vec.end());
	int res =0;
	for (int i = 0, j = 0; i <= 30000; i++){
		while (j<vec.size()&&vec[j].first.first<=i){
			updt(1,0,30000,vec[j].second.first,vec[j].second.second,vec[j].first.second);
			j++;
		}
		res += val[1];
	}
	cout << res;
	
	return 0;
}
