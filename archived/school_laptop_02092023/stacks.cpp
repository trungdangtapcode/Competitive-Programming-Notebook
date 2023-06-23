#include<bits/stdc++.h>

using namespace std;
int n;
stack<int> ngan[25];
queue<int> doi[25];

void in(int pos){
	cout << "[" << pos << "]: \n";
	cout << "stack: ";
	stack<int> x = ngan[pos];
	while (!x.empty()){
		cout << x.top() << "->";
		x.pop();
	}
	cout << endl;
	cout << "queue: ";
	queue<int> y = doi[pos];
	while (!y.empty()){
		cout << y.front() << "->";
		y.pop();
	}
	cout << endl;
}

void dichuyen(int pos, int l, int r){ //stack thu pos dang co gia tri tu l -> r
//	for (int i = 1; i <= n+1; i++) in(i);
	if (l==r){
//		cout << l << " at pos " << pos << endl;
//		ngan[l].pop(); 
		return;
	}
	int m = (l+r)/2;
	for (int i = 0; i < r-l+1; i++){
		int x = doi[pos].front();
		doi[pos].pop();
		cout << 2*pos-1 << " ";
		if (x<=m){
			doi[pos+1].push(x);
			cout << 2*pos << " ";
		} else{
			ngan[pos].push(x);
		};	
	}
	dichuyen(pos+1,l,m);
	while (!ngan[pos].empty()){
		doi[pos+1].push(ngan[pos].top());
		ngan[pos].pop();
		cout << 2*pos << " ";
	}
	dichuyen(pos+1,m+1,r);
}

int main(){
	
	cin >> n;
	for (int i = 0, a; i < (1<<n); i++){
		cin >> a;
		doi[1].push(a);
	}
	dichuyen(1,1,(1<<n));
	
	return 0;
}
