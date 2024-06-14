#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int T = 150, maxN = 2e3+5;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n, m, check[maxN][maxN];
string s[maxN];
map<char,int> mp;
int idx(char c){
	if (mp.count(c)) return mp[c];
	return mp[c] = mp.size();
}
struct Wood{
	int x, y, u, v, cnt;
	Wood(int _x = 1e9, int _y = 1e9, int _u = -1e9, int _v = -1e9, int _cnt = 0){
		x = _x, y = _y, u = _u, v = _v, cnt = _cnt;
	}
	Wood operator+(Wood &other){
		return Wood(min(x,other.x),min(y,other.y),max(u,other.u),max(v,other.v),cnt+other.cnt);
	}
	int diff(){
		return (u-x+1)*(v-y+1)-cnt;
	}
} wood[T+5];
vector<ii> vec[T+5];
priority_queue<ii, vector<ii>, greater<ii>> pq;
void pick(int x, int y){
	if (x<1||x>n||y<1||y>m) return;
	if (check[x][y]) return;
	int id = idx(s[x][y]);
	for (auto it: vec[id]){
		int i = it.first, j = it.second;
		check[i][j] = 1;
	}
	pq.push({wood[id].diff(),id});
}
void pick2(int x, int y, int myid){
	if (x<1||x>n||y<1||y>m) return;
	if (check[x][y]) return;
	int id = idx(s[x][y]);
	for (auto it: vec[id]){
		int i = it.first, j = it.second;
		check[i][j] = 1;
	}
	wood[myid] = wood[myid] + wood[id];
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
		for (int j = 1; j <= m; j++){
			int id = idx(s[i][j]);
			wood[id].x = min(wood[id].x,i);
			wood[id].y = min(wood[id].y,j);
			wood[id].u = max(wood[id].u,i);
			wood[id].v = max(wood[id].v,j);
			wood[id].cnt++;
			vec[id].push_back({i,j});
		}
	}	
	pick(1,1);
	pick(1,m);
	pick(n,1);
	pick(n,m);
	int res = 0;
	while (pq.size()){
		int diff = pq.top().first, id = pq.top().second;
		pq.pop();
		if (diff==0){
			res++;
			for (auto it: vec[id]){
				int x = it.first, y = it.second;
				for (int i = 0; i < 4; i++) pick(x+dx[i],y+dy[i]);
			}
			continue;
		}
//		for (int i = 0; i <= n; i++)
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cout << check[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/
//RAIN
