#include<bits/stdc++.h>

using namespace std;
#define int long long
struct rec{
	int x, y, u,v;
	rec(){
		x = y = u = v = 0;
	}
	void get(){
		cin >> x >> y >> u >> v;
	}
	rec operator*(const rec& other){
		rec res;
		res.x = max(x,other.x);
		res.y = max(y,other.y);
		res.u = min(u,other.u);
		res.v = min(v,other.v);
		return res;
	}
	int area(){
		return max((u-x),0ll)*max((v-y),0ll);
	}
} r1, r2, r3;

main(){
	r1.get();
	r2.get();
	r3.get();
//	cout << (r1*r2).area() + (r1*r3).area() - (r1*r2*r3).area() << " " << r1.area() << "\n";
	cout << ((r1*r2).area() + (r1*r3).area() - (r1*r2*r3).area() < (r1).area()?"YES\n":"NO\n");
	
	return 0;
}
