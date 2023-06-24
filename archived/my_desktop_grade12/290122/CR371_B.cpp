#include<bits/stdc++.h>

using namespace std;
int n, m, l, h, l_1, l_2, r_1, r_2, u_1, u_2, d_1, d_2, x;
int ask(int u, int v, int x, int y){
	cout << "? " << u << " " << v << " " << x << " " << y << endl;
	int res; cin >> res;
	return res;
}
//int ask(int u, int v, int x, int y){ //[ask] tu tra loi
//	if (u>x||v>y) cout << "wtf?? ";
//	int u1, u2, v1, v2, x1, x2, y1, y2, res = 0;
//	tie(u1,v1,x1,y1) = make_tuple(25633,6000,45095,36812); // = make_tuple(8,7,90,37); // = make_tuple(1,1,10,1); // = make_tuple(1,2,4,2);
//	tie(u2,v2,x2,y2) = make_tuple(7134,43330,26516,61810);// = make_tuple(4,64,4,100); // = make_tuple(5,5,5,10); // = make_tuple(1,6,4,9);
//	if (u<=u1&&v<=v1&&x1<=x&&y1<=y) res++;
//	if (u<=u2&&v<=v2&&x2<=x&&y2<=y) res++;
//	cout << "? " << u << " " << v << " " << x << " " << y << " --> " << res << "\n";
//	return res;
//}

int main(){
	cin >> n;
	//hcn1: trai[0], phai[1], tren[0], duoi[1]
	l = 1, h = n;
//	last = 0;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,1,n,m);
		if (x>=2){
			r_2 = m;
			h = m-1;
		} else l = m+1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,1,n,m);
		if (x>=1){
			r_1 = m;
			h = m-1;
		} else l = m+1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,m,n,n);
		if (x>=2){
			l_1 = m;
			l = m+1;
		} else h = m-1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,m,n,n);
		if (x>=1){
			l_2 = m;
			l = m+1;
		} else h = m-1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,1,m,n);
		if (x>=2){
			d_2 = m;
			h = m-1;
		} else l = m+1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(1,1,m,n);
		if (x>=1){
			d_1 = m;
			h = m-1;
		} else l = m+1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(m,1,n,n);
		if (x>=2){
			u_1 = m;
			l = m+1;
		} else h = m-1;
	}
	l = 1, h = n;
	while (l<=h){
		m = l+h>>1;
		x = ask(m,1,n,n);
		if (x>=1){
			u_2 = m;
			l = m+1;
		} else h = m-1;
	}
//	cout << l_1 << " " << r_1 << " " << l_2 << " " << r_2 << "\n";
//	cout << "> " << u_1 << " " << l_1 << " " << d_1 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_2 << "\n";
	if (ask(u_1,l_1,d_1,r_1)&&ask(u_2,l_2,d_2,r_2)) return cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_2 << "\n", 0;
	if (ask(u_1,l_2,d_1,r_2)&&ask(u_2,l_1,d_2,r_1)) return cout << "! " << u_1 << " " << l_2 << " " << d_1 << " " << r_2 << " " << u_2 << " " << l_1 << " " << d_2 << " " << r_1 << "\n", 0;
	if (r_1<l_2){
		cout << "! " << u_1 << " " << l_1 << " " << d_2 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_1 << " " << r_2 << "\n";
	} else {
		cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_2 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_1 << "\n";
	}
//	if (r_1<l_2&&d_1<u_2){
//		if (ask(u_1,l_1,d_1,r_1)&&ask(u_2,l_2,d_2,r_2)){
//			cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_2 << "\n";
//		} else cout << "! " << u_1 << " " << l_2 << " " << d_1 << " " << r_2 << " " << u_2 << " " << l_1 << " " << d_2 << " " << r_1 << "\n";
//	} else if (r_1<l_2){
//		cout << "hi";
//		if (ask(u_1,l_1,d_1,r_1)&&ask(u_2,l_2,d_2,r_2)){
//			cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_2 << "\n";
//		} else cout << "! " << u_1 << " " << l_1 << " " << d_2 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_1 << " " << r_2 << "\n";
//	} else {
//		if (ask(u_1,l_1,d_1,r_1)&&ask(u_2,l_2,d_2,r_2)){
//			cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_1 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_2 << "\n";
//		} else cout << "! " << u_1 << " " << l_1 << " " << d_1 << " " << r_2 << " " << u_2 << " " << l_2 << " " << d_2 << " " << r_1 << "\n";
//		
//	}
	return 0;
}
