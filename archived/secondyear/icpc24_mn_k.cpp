#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

#define For(i,a,b) for(int i=a;i<=b;i++)

int mm;
int n, numPac, m;

#define ii pair<int,int>
#define iii pair<ii,int>
iii a[10001];
string name[] = {"N","E","S","W"};

vector<iii> brute(int pos, int u, int v){
	vector<iii> res(4,{{u,v},-1});
	for (int i = 0; i < 4; i++) res[i].second = i;
//	return res;
	for (int i = pos; i <= m; i++){
		char c; int x;
		cin >> c >> x;
//		cout << c << " " << x << "\n";
		vector<iii> nres;
		for (auto it: res){
			int u = it.first.first, v = it.first.second,
				d = it.second;
//			cout << u << " " << v << " " << name[d] << "  =>  ";
			if (c=='A'){
				if (d==0){
					v -= x;
					v = (v+n)%n;
				} else if (d==1){
					u += x;
					u = (u+n)%n;
				} else if (d==2){
					v += x;
					v = (v+n)%n;
				} else {
					u -= x;
					u = (u+n)%n;
				}
			} else if (c=='R') {
				d = (d+x)%4;
			} else {
				u = x%n, v = x/n;
			}
			u = (u%n+n)%n;
			v = (v%n+n)%n;
//			cout << u << " " << v << " " << name[d] << "\n";
			nres.push_back({{u,v},d});
		}
//		cout << "\n";
		res = nres;
	}
	return res;
}

int oprot = 0, opmovex = 0, opmovey = 0;
void solve(){
	cin >> n >> numPac >> m;
	For(i,1,numPac){
		int x, y, d;
		cin >> x >> y >> d;
		a[i] = {ii(y, x), --d};
	}
	vector<iii> newop;
	vector<iii> mybrute;
	for (int i = 1; i <= m; i++){
		char c; int x;
		cin >> c >> x;
		if (c=='A'){
			if (oprot==0){
				opmovex += x;
			} else if (oprot==1){
				opmovey += x; 
			} else if (oprot==2){
				opmovex -= x;
			} else {
				opmovey -= x;
			}
		} else if (c=='R'){
			oprot = (oprot+x)%4;
		} else {
			mybrute = brute(i+1,x%n,x/n);
			break;
		}
	}
	if (mybrute.size()){
		for (int i = 1; i <= numPac; i++){
			int d = a[i].second;
			d = (d+oprot)%4;
			auto it = mybrute[d];
			cout << it.first.second << " " << it.first.first << "\n";
		}
	} else { //NO Z :(
		for (int i = 1; i <= numPac; i++){
			int u = a[i].first.first, v = a[i].first.second, d = a[i].second;
//			cout << u << " " << v << "\n";
			int fixDirect = (d+oprot)%4;
			if (d==0){ //north
				u += opmovey;
				v -= opmovex;
			} else if (d==1){ //east
				u += opmovex;
				v += opmovey;
			} else if (d==2){ //south
				u -= opmovey;
				v += opmovex;
			} else if (d==3){ //west
				u -= opmovex;
				v -= opmovey;
			} 
			u = (u%n+n)%n;
			v = (v%n+n)%n;
			cout << v << " " << u << "\n";
		}
	}
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif

	int tc = 1;
//	cin >> tc;
	while(tc--){
		solve();
	}

}



