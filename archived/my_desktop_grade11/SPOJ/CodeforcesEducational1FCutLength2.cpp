#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair <double, double> pdd;
typedef tuple<double, double, double> tddd;
pdd p[1005];
tddd AB;
double x1, x2, y1, y2;


tddd pdd2tddd(pdd a, pdd b){
	if (a==b) return tddd{0,-1,1e8};
	tddd res;
	get<0>(res) = a.second - b.second;
	get<1>(res) = b.first - a.first;
	get<2>(res) = -(get<0>(res)*a.first + get<1>(res)*a.second);
	return res;
}

pdd tddd2pdd(tddd a, tddd b){
	pdd res;
	double mau = get<0>(a)*get<1>(b)-get<0>(b)*get<1>(a);
	if (mau == 0) if (get<2>(a)==get<2>(b)) return {1e7,1e7}; else return {-1e7,-1e7};
	double tu1 = get<2>(a)*get<1>(b) - get<2>(b)*get<1>(a);
	double tu2 = get<2>(a)*get<0>(b) - get<2>(b)*get<0>(a);
	return {-tu1/mau,tu2/mau};
}

double pdd2d(pdd a, pdd b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

vector <pdd> f(pdd a, pdd b, tddd c){
	vector <pdd> res;
	tddd d = pdd2tddd(a,b);
	pdd x = tddd2pdd(c,d);
	if (x.first==1e7){
		res.push_back(a);
		res.push_back(b);
	} else if (x.first==-1e7) {
	} else {
		double p1x = a.first, p1y = a.second, p2x = b.first, p2y = b.second;
		if (p1x>p2x) swap(p1x,p2x);
		if (p1y>p2y) swap(p1y,p2y);
		if (x.first>=p1x-1e-7&&x.first<=p2x+1e-7&&x.second>=p1y-1e-7&&x.second<=p2y+1e-7)
			res.push_back(x);
	}
	return res;
}

vector <pdd> sieve(vector <pdd> a){
	sort(a.begin(),a.end());
	vector <bool> b(a.size(),true);
	for (int i = 0; i < a.size()-1; i++){
		if (abs(a[i].first-a[i+1].first)<1e-7&&abs(a[i].second-a[i+1].second)<1e-7) b[i] = false;
	}
	vector <pdd> res;
	for (int i = 0; i < a.size(); i++) if (b[i]) res.push_back(a[i]);
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(9);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	p[n] = p[0];
	
	for (int i = 0; i < m; i++){
		cin >> x1 >> x2 >> y1 >> y2;
		AB = pdd2tddd({x1,x2},{y1,y2});
		vector <pdd> vp;
		
		for (int i = 0; i < n; i++){
			vector <pdd> x = f(p[i],p[i+1],AB);
			for (auto& it: x) vp.push_back(it);
		}
		
		vp = sieve(vp);
		
		for (auto it: vp) cout << "(" << it.first << "," << it.second << ") "; cout << endl;
		if (vp.empty()||vp.size()%2==1){
			cout << 0.00000001 << '\n';
			continue;
		}
		
		double sum = 0;
		for (int i = 0; i < vp.size()-1; i+=2){
			sum += pdd2d(vp[i],vp[i+1]);
		}
		cout << sum << '\n';
	}
	
	
	return 0;
}
