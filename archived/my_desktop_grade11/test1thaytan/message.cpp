#include <bits/stdc++.h>
using namespace std;
typedef pair<int, long int> id;
vector<vector<id>> edges (3005);
//const int INF = 1e15;
vector<int> cha (3005); //this vector mean speed it uppp
//vector<int> rank (3005);

using namespace std;

int timcha(int x){ //update
	//cout << cha[x]<< "  "<<x << endl;
	if (cha[x]==x) return x;
	cha[x] = timcha(cha[x]);
	//rank[x] = rank[cha[x]];
	return cha[x];
}

void hop(int a, int b){
	if (timcha(a)==timcha(b)) return;
	else cha[cha[a]]=cha[b];
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		cha[i] = i;
	}
	
	for (int i = 0; i < m; i++){
		//for (int i = 0; i < n; i++) cout << cha[i] << " "; cout << endl;
		int a, b;
		cin >> a >> b;
		hop(a-1,b-1);
		//cout << "hi " << i << endl;
	}
	
	for (int i = 0; i < n; i++) timcha(i); //update nhanh con
	//for (int i = 0; i < n; i++) cout << cha[i] << " "; cout << endl;
	
	set<int> set_cha (cha.begin(),cha.begin()+n);
	cout << set_cha.size()-1 << endl;
}

int main(){
	//14/11 sua nham do thi vo huong
	int t;
	cin >> t;
	for (int i = 0; i< t; i++){
		solve();
	}
	
	return 0;
}
