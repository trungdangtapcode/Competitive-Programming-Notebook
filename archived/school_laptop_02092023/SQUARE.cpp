//suc vat code toan bug

#include <bits/stdc++.h>

using namespace std;
#define ld long double
struct Point {
    ld x, y;
} a, b, c, d, e;

struct PT {
    ld A, B, C;
};

PT build(const Point &a, const Point &b) {
    return {b.y - a.y, - (b.x - a.x), - a.x * b.y + a.y * b.x};
}

Point GiaoDiem(const PT &p1, const PT &p2) {
    if (p2.A * p1.B - p1.A * p2.B == 0) return {INT_MIN,INT_MIN};
    ld X = (ld) (- p1.B * p2.C + p2.B * p1.C) / (p2.A * p1.B - p1.A * p2.B);
    ld Y = (ld) (p1.A * p2.C - p2.A * p1.C) / (p2.A * p1.B - p1.A * p2.B);
    return {X, Y};
}

bool CheckGiaoDiem(const Point &I, const Point &A, const Point &B) {
    ld Xmin = min(A.x, B.x);
    ld Xmax = max(A.x, B.x);
    ld Ymin = min(A.y, B.y);
    ld Ymax = max(A.y, B.y);
    return I.x >= Xmin && I.x <= Xmax && I.y >= Ymin && I.y <= Ymax;
}

Point TimGiaoDiem(const PT &p, const Point &A, const Point &B) {
    PT AB = build(A, B);
    Point I = GiaoDiem(p, AB);
    if(CheckGiaoDiem(I, A, B)) return I; else return {INT_MIN, INT_MIN};
}
Point TimGiaoDiem(const Point &D, const Point &E, const Point &A, const Point &B) {
    PT AB = build(A, B);
    PT DE = build(D, E);
    Point I = GiaoDiem(DE, AB);
    if(CheckGiaoDiem(I, A, B)&&CheckGiaoDiem(I, D, E)) return I; else return {INT_MIN, INT_MIN};
}
ld dist(const Point &a, const Point &b) {
    return (ld) sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

ld S(const Point &a, const Point &b, const Point &c) {
    return abs(0.5 * (1.0 * (b.x - a.x) * (c.y - a.y) - 1.0 * (c.x - a.x) * (b.y - a.y)));
}

void write(ld x) {
    cout << setprecision(5) << fixed << x << endl;
} 

bool PointInTriangle(const Point &m) {
    ld s1 = S(m, a, b);
    ld s2 = S(m, b, c);
    ld s3 = S(m, a, c);
    ld ss = S(a, b, c);
    return (s1 + s2 + s3 == ss);
}

bool CatPQ() {
    PT DE = build(d, e);

    return (
        (TimGiaoDiem(d, e, a, b).x != INT_MIN && TimGiaoDiem(d, e, b, c).x != INT_MIN) ||
        (TimGiaoDiem(d, e, a, b).x != INT_MIN && TimGiaoDiem(d, e, a, c).x != INT_MIN) ||
        (TimGiaoDiem(d, e, b, c).x != INT_MIN && TimGiaoDiem(d, e, a, c).x != INT_MIN)
    );
}
ld FindPQ() {
    PT DE = build(d, e);
    PT AB = build(a, b);
    PT AC = build(a, c);
    PT BC = build(b, c);
    
    ld res = 0;
    if(TimGiaoDiem(DE, a, b).x != INT_MIN && TimGiaoDiem(DE, b, c).x != INT_MIN) res = max(res,dist(GiaoDiem(DE, AB),GiaoDiem(DE, BC)));
    if(TimGiaoDiem(DE, a, b).x != INT_MIN && TimGiaoDiem(DE, a, c).x != INT_MIN) res = max(res,dist(GiaoDiem(DE, AB),GiaoDiem(DE, AC)));
    if(TimGiaoDiem(DE, b, c).x != INT_MIN && TimGiaoDiem(DE, a, c).x != INT_MIN) res = max(res,dist(GiaoDiem(DE, BC),GiaoDiem(DE, AC)));
    return res;
}
#define int long long
typedef pair<int,int> ii;
int n, m;
map<ii,bool> mp;
Point trans(int x){
	Point res;
	if (x<=n){
		res.x = 0;
		res.y = n-x+1;
	} else if (x<=2*n){
		res.y = 0;
		res.x = x-n-1;
	} else if (x<=3*n){
		res.x = n;
		res.y = x-2*n-1;
	} else {
		res.y = n;
		res.x = n-(x-3*n)+1;
	}
	return res;
}

main(){
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	cin >> n >> m;
	vector<ii> vec;
	int res = 1;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		if (u>v) swap(u,v);
		vector<pair<ld,ld>> p;
		if (mp[{u,v}]) continue;
		for (auto it: vec){
			int x = it.first, y = it.second;
			if ((x<u&&u<y&&y<v)||(u<x&&x<v&&v<y)){
				Point a, b, c, d;
				a = trans(u);
				b = trans(v);
				c = trans(x);
				d = trans(y);
				p.push_back({TimGiaoDiem(a,b,c,d).x,TimGiaoDiem(a,b,c,d).y});
//				cout << TimGiaoDiem(a,b,c,d).x << " " << TimGiaoDiem(a,b,c,d).y << endl;
			}
		}
		mp[{u,v}] = 1;
		p.push_back({1e9,1e9});
		int cnt = 0;
		sort(p.begin(),p.end());
		for (int i = 0; i < p.size()-1; i++){
			if (p[i+1].first-p[i].first>1e-9||p[i+1].second-p[i].second>1e-9) cnt++;
		}
//		for (auto it: p) cout << it << " -";
//		cout << cnt << endl;
		res += cnt+1;
		vec.push_back({u,v});
	}
	cout << res;


    return 0;
}

//bug fixing by Watame0606
