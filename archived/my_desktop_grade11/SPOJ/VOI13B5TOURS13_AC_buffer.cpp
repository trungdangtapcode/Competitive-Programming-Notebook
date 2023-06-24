#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>

using namespace std;

template <class T>
inline void in(T &x)
{
	register T c = getchar();
	x = 0;
	T neg = 0;
	for (; ((c < 48 || c>57) && c != '-'); c = getchar());
	if (c == '-') { neg = 1; c = getchar(); }
	for (; c > 47 && c < 58; c = getchar()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}


typedef pair<int,int> ii;
typedef vector<ii>::iterator iter;
typedef pair<ii,pair<iter,int>> pack;
vector<ii> edge[1010];
int d[1010];
priority_queue<pack, vector<pack>, greater<pack> > pq;
int t, n, m, nodeU, nodeV, distUV, distU, nodeBU;
iter it, itU;

int dijsktra(int s) {
	pq = priority_queue<pack, vector<pack>, greater<pack> > ();
	memset(d, 0x3f, sizeof(d)); 
	d[s] = 0;
	pq.push(pack(make_pair(0, s),make_pair(edge[0].end(),-1)));
	while(!pq.empty()) {
		nodeU = pq.top().first.second; 
		distU = pq.top().first.first;
		itU = pq.top().second.first;
		nodeBU = pq.top().second.second;
		pq.pop();
		if (nodeU == n+1) return d[n+1];
		
		if (distU==d[nodeU]) 
		for (it = edge[nodeU].begin(); it != edge[nodeU].end(); it++) {
			nodeV = it->first; 
			if (nodeV == s) nodeV = n+1;
			distUV = it->second;
			if (d[nodeV] > d[nodeU] + distUV) {
				d[nodeV] = d[nodeU] + distUV;
				pq.push(pack(make_pair(d[nodeV], nodeV),make_pair(it,nodeU)));
				break;
			}
		}	
		if (nodeU!=s)
		for (itU++ ; itU != edge[nodeBU].end(); itU++) {
			nodeV = itU->first; 
			if (nodeV == s) nodeV = n+1;
			distUV = itU->second;
			if (d[nodeV] > d[nodeBU] + distUV) {
				d[nodeV] = d[nodeBU] + distUV;
				pq.push(pack(make_pair(d[nodeV], nodeV),make_pair(itU,nodeBU))); 
				break;
			}
		}
	}
	return -1;
}

int main() {
	in(t);
	while(t--) {
	    in(n); in(m);
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 1; i <= m; i++) {
			in(nodeU); in(nodeV); in(distUV);
			edge[nodeU].push_back(ii(nodeV, distUV));
		}
		for (int i = 1; i <= n; i++) sort(edge[i].begin(),edge[i].end(),[](ii a, ii b){return a.second<b.second;});
		for (int i = 1; i <= n; i++) write(dijsktra(i)), putchar('\n');
	}
	return 0;
}

