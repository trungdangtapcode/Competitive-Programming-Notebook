#include<bits/stdc++.h>

using namespace std;
const int N = 105;

#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)

int n, m;
int a[N][N][N], b[N][N][N];

void add(int x, int y, int z, int w){
	for(int i=x;i<=n;i+=i&(-i))
	for(int j=y;j<=n;j+=j&(-j))	
	for(int k=z;k<=n;k+=k&(-k))
	{
		a[i][j][k] += w;
	}
}

int get(int x, int y, int z){
	int ans = 0;
	for(int i=x;i>0;i-=i&(-i))
	for(int j=y;j>0;j-=j&(-j))	
	for(int k=z;k>0;k-=k&(-k))
	{
		ans += a[i][j][k];
	}
	return ans;
}

int tv(int x, int y, int z,
	int u, int v, int w){
	
	int ans = get(x, y, z);
	
	ans -= get(u - 1, y, z);
	ans -= get(x, v - 1, z);
	ans -= get(x, y, w - 1);
	
	ans += get(u - 1, v - 1, z);
	ans += get(u - 1, y, w - 1);
	ans += get(x, v - 1, w - 1);
		
	ans -= get(u - 1, v - 1, w - 1);
	return ans;
}

void solve(){
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	cin >> n >> m;
	while(m--){
		string str; cin >> str;
		if(str[0] == 'U'){
			int x, y, z, w;
			cin >> x >> y >> z >> w;
			add(x, y, z, -b[x][y][z]);
			add(x, y, z, w);
			b[x][y][z] = w;
		}else{
			int u, v, w;
			cin >> u >> v >> w;
			
			int x, y, z;
			cin >> x >> y >> z;
		
			cout << tv(x, y, z, u, v, w) << "\n";
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
	cin >> tc;
	while(tc--){
		solve();
	}
			
}


