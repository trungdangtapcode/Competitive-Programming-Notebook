#include <bits/stdc++.h>

using namespace std;
int pref[1000005], n, p, q;
string s;
int val[4000005], lazy[4000005];
set<int> posClose;


void buildTree(int k, int l, int r){
	if (l == r) {
		val[k] = pref[l];
		lazy[k] = 0;
		return;
	}
	int m = (l+r)/2;
	buildTree(2*k,l,m);
	buildTree(2*k+1,m+1,r);
	val[k] = min(val[2*k],val[2*k+1]);
}
void downTree(int k){ //not leaf
	if (!lazy[k]) return;
	val[2*k] += lazy[k];
	lazy[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updateTree(int k, int l, int r, int u, int v, int x){
	//cout << l << " " << r <<"   "<< u<<" " << v << endl;
	if (v<l||u>r) return;
	if (u <= l && r <= v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	downTree(k); //update
	
	int m = (l+r)/2;
	updateTree(2*k,l,m,u,v,x);
	updateTree(2*k+1,m+1,r,u,v,x);
	val[k] = min(val[2*k],val[2*k+1]);
}
int INF = 1e7;
//int getTree(int k, int l, int r){ //return pos
//	if (l==r){ //down anti leaf
//		if (val[k]<2) return INF; else return l;
//	}
//	downTree(k);
//	
//	int m = (l+r)/2;
//	if (val[k]>=2) return l; //looking for r+1
//	return min(getTree(2*k,l,m),getTree(2*k+1,m+1,r));
//}
int getTree(int k, int l, int r){ //return pos
	if (l==r){ //down anti leaf
		if (val[k]<2) return INF; else return l;
	}
	downTree(k);
	
	int m = (l+r)/2;
	if (val[2*k+1]<2) return getTree(2*k+1,m+1,r); //looking for r+1
	else return min(getTree(2*k,l,m),m+1);
}

//
void flip(int x){
	s[x] = '(' + ')' - s[x];
	if (s[x] == '('){
		updateTree(1,1,n,x,n,+2);
		posClose.erase(x);
	} else {
		updateTree(1,1,n,x,n,-2);
		posClose.insert(x);
	}
} 
int findOpen(){
	int res = getTree(1,1,n); //first up to (min_pref >= 2) that alway is '('. ez proof
	//flip(res);
	return res;
}
int findClose(){
	int res = *posClose.begin();
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> q;
	cin >> s;
	s = " " + s;
	pref[0] = 0;
	for (int i = 1; i <= n; i++) pref[i] = pref[i-1] + (s[i]=='('?1:-1);
	buildTree(1,1,n);
	//for (int i = 1; i <=4*n; i++) cout << i<<". " << val[i] << endl;
	for (int i = 1; i <= n; i++) if (s[i]==')') posClose.insert(i);
	
	//flip(p);
	//cout << findOpen();
	//for (int i = 1; i <= n; i++) cout << s[i];
	//for (int i = 1; i <=4*n; i++) downTree(i);
	//for (int i = 1; i <=4*n; i++) cout << i<<". " << val[i] << endl;
	
	while (q--){
		cin >> p;
		flip(p);
		//cout << n << "-"<<q<<"-"<<s.substr(1,n);
		int cur = -1;
		if (s[p]==')'){
			cur = findClose();
		} else cur = findOpen();
		flip(cur);
		//for (int i = 1; i <= n; i++) cout << s[i]; cout << endl;
		cout << cur << " ";
	}
	
	
	return 0;
}
