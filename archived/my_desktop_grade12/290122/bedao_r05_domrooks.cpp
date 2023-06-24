#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii prvx[200005], prvy[200005];
int n, col[200005], sz;
int res = 1;
const int p = 1e9+7;

int main(){
	
	cin >> n;
	for (int i = 0, x, y; i < n; i++){
		cin >> x >> y;
//		if (prvx[x].first!=0&&prvy[y].first!=0){
//			int tmp1, tmp2;
//			if (prvy[prvx[x].first].first!=x) tmp1 = prvy[prvx[x].first].first; else tmp1 = prvy[prvx[x].first].second;
////			if (prvx[prvy[y].first].first!=y) tmp2 = prvx[prvy[y].first].first; else tmp2 = prvx[prvy[y].first].second;
////			if (tmp1!=0&&tmp2!=0) cout << ;
//			if (tmp1==prvy[y].first) res = 2*res%p;
//		}
		
		if (prvx[x].first==0) prvx[x].first = y; else prvx[x].second = y;
		if (prvy[y].first==0) prvy[y].first = x; else prvy[y].second = x;
	}
	for (int i = 1; i <= 2e5; i++) if (col[i]==0&&prvy[i].second!=0){
		col[i] = 1;
		int y = i, x = prvy[i].first;
		while (true){
			if (prvx[x].second==0) break;
			if (prvx[x].first!=y) y = prvx[x].first; else y = prvx[x].second;
			col[y] = 1;
			if (prvy[y].second==0) break;
			if (prvy[y].first!=x) x = prvy[y].first; else x = prvy[y].second;
			if (y==i&&x==prvy[i].first){
				res = 2*res%p;
				break;
			};
		}
	}
	
	cout << res;
	
	return 0;
}
