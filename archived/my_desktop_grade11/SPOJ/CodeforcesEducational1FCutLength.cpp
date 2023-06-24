#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair <double, double> pdd;
typedef tuple<double, double, double> tddd;
pdd p[1005];
tddd edge[1005], AB;
double x1, x2, y1, y2;


tddd pdd2tddd(pdd a, pdd b){
	tddd res;
	get<0>(res) = a.second - b.second;
	get<1>(res) = b.first - a.first;
	get<2>(res) = -(get<0>(res)*a.first + get<1>(res)*a.second);
	return res;
}

pdd tddd2pdd(tddd a, tddd b){
	pdd res;
	double mau = get<0>(a)*get<1>(b)-get<0>(b)*get<1>(a);
	if (mau == 0) return {1e7,1e7}; //song song k cat nhau. Neu trung nhau thi cat 2 dau "khop"
	double tu1 = get<2>(a)*get<1>(b) - get<2>(b)*get<1>(a);
	double tu2 = get<2>(a)*get<0>(b) - get<2>(b)*get<0>(a);
	//cout << tu2 << endl;
	return {-tu1/mau,tu2/mau};
}

double pdd2d(pdd a, pdd b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(9);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
	p[n] = p[0];
	for (int i = 0; i < n; i++) edge[i] = pdd2tddd(p[i],p[i+1]);
	
	for (int i = 0; i < m; i++){
		cin >> x1 >> x2 >> y1 >> y2;
		AB = pdd2tddd({x1,x2},{y1,y2});
		vector <pdd> vp;
		
		for (int i = 0; i < n; i++){
			pdd x;
			x = tddd2pdd(edge[i],AB);
			double p1x = p[i].first, p1y = p[i].second, p2x = p[i+1].first, p2y = p[i+1].second;
//			if ((p1x>p2x)||(p1x==p2x&&p1y>p2y)) swap(p1x,p2x), swap(p1y,p2y);
//			cout << p1x << " " << p1y << " " << p2x << " " << p2y << " " << x.first << " " << x.second<< '\n';
			if (p1x>p2x) swap(p1x,p2x);
			if (p1y>p2y) swap(p1y,p2y);
			if (x.first>=p1x-1e-7&&x.first<=p2x+1e-7&&x.second>=p1y-1e-7&&x.second<=p2y+1e-7){
				if (vp.empty()) vp.push_back(x);
				else if (abs(vp.back().first-x.first)>=1e-7||abs(vp.back().second-x.second)>=1e-7)
					vp.push_back(x); //van tinh "khop" nhung 2 not co dis = 0
			}
//			vp.push_back(x);
			cout << x.first << " " << x.second << endl;
		}
		
		//khop dau va cuoi
		if (vp.size()>1&&abs(vp.front().first-vp.back().first)<1e-7&&abs(vp.front().second-vp.back().second)<1e-7) vp.pop_back();
		
		//vo nghiem
		if (vp.empty()){
			cout << 0.00000001 << '\n';
			continue;
		} 
		
		sort(vp.begin(),vp.end());
//		for (auto it: vp) cout << "(" << it.first << "," << it.second << ") "; cout << endl;
		double sum = 0;
		for (int i = 0; i < vp.size()-1; i+=2){
			sum += pdd2d(vp[i],vp[i+1]);
		}
		cout << sum << '\n';
	}
	
	//cout << get<0>(AB[0]) << " " << get<1>(AB[0]) << " " << get<2>(AB[0]) << endl;
	//for (int i = 0; i < n; i++) cout << get<0>(edge[i]) <<" "<< get<1>(edge[i]) <<" "<< get<2>(edge[i]) << endl;
	
	
	return 0;
}
