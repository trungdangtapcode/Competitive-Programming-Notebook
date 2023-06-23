
/*
#include<bits/stdc++.h>

using namespace std;
typedef long double ld;

ld det(ld a, ld b, ld c, ld d){
	return (a*d-b*c);
}
pair<pair<ld,ld>,bool> cat(ld xa,ld ya,ld xb,ld yb,ld xp,ld yp,ld xq,ld yq){
	ld a1, a2, b1, b2, c1, c2, xab, yab, xpq, ypq;
	if (xa>xb) swap(xa,xb), swap(ya,yb);
	if (xp>xq) swap(xp,xq), swap(yp,yq);
	xab = xb - xa;
	yab = yb - ya;
	a1 = -yab;
	b1 = xab;
	c1 = -(xa*a1+ya*b1);
//	cout << yb << " - " << ya << " = "<< yb - ya << endl;
	xpq = xq - xp;
	ypq = yq - yp;
	a2 = -ypq;
	b2 = xpq;
	c2 = -(xp*a2+yp*b2);
	ld detA = det(b1,c1,b2,c2);
	ld detB = det(c1,a1,c2,a2);
	ld detAB = det(a1,b1,a2,b2);
//	cout << xa << " " << ya << " " << xb << " " << yb << " -> " << a1 << " " << b1 << " " << c1 << endl;
	if (detAB==0){
		return {{-1,-1},0};
	} else {
		long double tmp = (long double)detA/detAB;
		if (1.0*xa<=tmp&&tmp<=1.0*xb&&1.0*xp<=tmp&&tmp<=1.0*xq) return {{(long double)detA/detAB,(long double)detB/detAB},1};
		else return {{c1,-1},0};
	}
}
int main(){
//	cout << cat(0,1,2,3,0,3,2,1).first.first; 
	cout << setprecision(6);
	ld xa, ya, xb, yb, xc, yc, xd, yd, xe, ye;
	vector<pair<ld,ld>> v;
	cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd >> xe >> ye;
	if (xa==x){
	}
	pair<pair<ld,ld>,bool> tmp;
	tmp = cat(xa,ya,xb,yb,xd,yd,xe,ye);
//	cout << tmp.first.first << " " << tmp.first.second << endl;
	if (tmp.second) v.push_back({tmp.first.first,tmp.first.second});
	tmp = cat(xb,yb,xc,yc,xd,yd,xe,ye);
	if (tmp.second) v.push_back({tmp.first.first,tmp.first.second});
	tmp = cat(xc,yc,xa,ya,xd,yd,xe,ye);
	if (tmp.second) v.push_back({tmp.first.first,tmp.first.second});
	cout << v.size() << endl;
//	for (auto it: v){
//		cout << it.first << " " << it.second << endl;
//	}
	cout << sqrt((v[0].first-v[1].first)*(v[0].first-v[1].first)+(v[0].second-v[1].second)*(v[0].second-v[1].second));
	
	return 0;
}
*/
