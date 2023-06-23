#include<bits/stdc++.h>

using namespace std;

struct node{
	vector<array<int,2>> to;
	vector<int> s;
	
	void add(int x){
		x += 1e9;
		array<int,2> ae = {-1,-1};
		if (to.size()==0) to.push_back(ae), s.push_back(0);
		int u = 0;
		s[0]++;
		for (int i = 30; i >= 0; i--){
			bool tmp = (x&(1<<i));
			if (to[u][tmp]==-1){
				to[u][tmp] = to.size();
				to.push_back(ae);
				s.push_back(0);
			}
			u = to[u][tmp];
			s[u]++;
		}
	}
	void remove(int x){
		x += 1e9;
		int u = 0;
		s[0]--;
		for (int i = 30; i >= 0; i--){
			bool tmp = (x&(1<<i));
			u = to[u][tmp];
			s[u]--;
		}
	}
	int find(int x){
		x += 1e9;
		array<int,2> ae = {-1,-1};
		if (to.size()==0) to.push_back(ae), s.push_back(0);
		int u = 0, res = 0;
		for (int i = 30; i >= 0; i--){
			bool tmp = (x&(1<<i));
//			cout << tmp << " " << u << " " << res << endl;
			if (tmp){
				if (to[u][0]!=-1) res += s[to[u][0]];
			}
			if (to[u][tmp]==-1) return res;
			u = to[u][tmp];
		}
		return res;
	}
	
};

node trie[100005];
int n, q, a[100005], x, y;
long long int sum, res;

void updt(int x, int y, int z, bool addOnly){
	for (; x <= n; x += x&-x){
		if (!addOnly) trie[x].remove(y);
		trie[x].add(z);
	}
}
int gett(int x, int y){
	if (x<=0) return 0;
	int res = 0;
	for (; x > 0; x -= x&-x) res += trie[x].find(y);
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(i,-1,a[i],1);
		res += i-1-gett(i-1,a[i]+1);
	}
//	cout << res << endl;
	cin >> q;
	while (q--){
		cin >> x >> y;
		y = (y+sum)%2000000001-1000000000;
		res -= x-1-gett(x-1,a[x]+1);
		res -= gett(n,a[x])-gett(x,a[x]);
		updt(x,a[x],a[x]+y,0);
		a[x]= a[x]+y;
		res += x-1-gett(x-1,a[x]+1);
		res += gett(n,a[x])-gett(x,a[x]);
		cout << res << endl;
		sum += res;
	}
	
//	node x;
//	x.add(10);
//	x.add(10);
//	x.add(10);
//	x.add(9);
//	x.remove(9);
//	x.add(11);
//	cout << x.find(11);
}
