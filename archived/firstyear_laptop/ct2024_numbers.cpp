#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
int s, f, d[maxN*2];
vector<int> perm[maxN];

vector<int> getperm(int x){
	string s = to_string(x);
	vector<int> p(s.length());
	for (int i = 0; i < s.length(); i++) p[i] = i;
	vector<int> res;
	do {
		int sum = 0;
		for (int i = 0; i < s.length(); i++) sum = 10*sum+s[p[i]]-'0';
		if (sum!=x) res.push_back(sum);
    } while (next_permutation(p.begin(),p.end()));
	
	return res;
}
int idx(int num, int player){
	return num+player*maxN;
}
typedef pair<int,int> ii;
ii ridx(int x){
	return ii{x%maxN,x/maxN};
}

void solve(){
//	for (auto x: perm[102]){
//		cout << x << " ";
//	} cout << '\n';
	cin >> s >> f;
	queue<int> q;
	for (int i = 0; i < maxN*2; i++) d[i] = 1e9;
	int st = idx(s,0), en = idx(f,1), badend = idx(f,0), en2 = idx(9999,1), badend2 = idx(9999,0);	
	q.push(st);
	d[st] = 0;
	int cnt = 0;
	while (q.size()){
		int u = q.front();
		auto it = ridx(u); 
		q.pop();
		cnt++;
		int un = it.first, up = it.second, vp = 1-it.second;
//		cout << un << " " << up << "\n";
		if (un<1e4-1){
			int vn = un+1;
			int v = idx(vn,vp);
			if (v==badend||v==badend2) continue;
			if (d[v]>d[u]+1){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
		for (int vn: perm[un]){
			int v = idx(vn,vp);
			if (v==badend||v==badend2) continue;
			if (d[v]>d[u]+1){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
//	cout << cnt << "=\n";
	int res = min(d[en],d[en2]);
	if (res==1e9){
		cout << -1 << "\n";
		return;
	}
	assert(res%2);
//	cout << d[idx(4,1)] << "\n";
	cout << (res+1)/2 << "\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	for (int i = 0; i < 1e4; i++) perm[i] = getperm(i);
	int t; cin >> t;
	while (t--)
	solve();
}
