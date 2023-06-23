#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

string st;
int n, q, cha[200005];
vector<iii> s;
int timcha(int x){
	return (cha[x]==x?x:timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	if (rand()%2) swap(pu,pv);
	cha[pu] = pv;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cha[i] = i;
	int res = n;
	while (q--){
		cin >> st;
		if (st=="persist"){
			s.push_back({-1,{0,0}});
		} else if (st=="union"){
			int x, y;
			cin >> x >> y;
//			if (hop(x,y)) res--, s.push_back({1,{x,y}}); WA kieu deo nao?? A A phai luu cai represent chu khong phai child node =)))
			x = timcha(x);
			y = timcha(y);
			if (x!=y){
				if (rand()%2) swap(x,y);
				cha[x] = y;
				res--;
				s.push_back({1,{x,y}});
			}
//			else s.push_back({0,{x,y}}); //child node is untouchable only the par represent for set
			cout << res << "\n";
		} else {
			while (s.back().first!=-1){
				int u = s.back().second.first, v = s.back().second.second, con = s.back().first;
				cha[u] = u; cha[v] = v;
				res += con;
				s.pop_back();
			}
			s.pop_back();
			cout << res << "\n";
		}
	}
	
	return 0;
}
