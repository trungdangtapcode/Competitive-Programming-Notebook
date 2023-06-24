#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int n, m, c;
int a[1000005];


int minTree[4000005], maxTree[4000005];
void buildTree(int l, int r, int k){
	//cout << l <<" " << r << " " << k << endl; 
	if (l==r) {
		minTree[k] = a[l];
		maxTree[k] = a[l];
		return;
	}
	int mid = (l+r)/2;
	buildTree(l,mid,2*k);
	buildTree(mid+1,r,2*k+1);
	minTree[k] = min(minTree[2*k],minTree[2*k+1]);
	maxTree[k] = max(maxTree[2*k],maxTree[2*k+1]);
}

int getMax(int l, int r, int k, int x, int y){
	if (y<l||x>r) return -INF;
	if (x<=l&&y>=r) return maxTree[k];
	int mid = (l+r)/2;
	return max(getMax(l,mid,2*k,x,y),getMax(mid+1,r,2*k+1,x,y));
}

int getMin(int l, int r, int k, int x, int y){
	if (y<l||x>r) return INF;
	if (x<=l&&y>=r) return minTree[k];
	int mid = (l+r)/2;
	return min(getMin(l,mid,2*k,x,y),getMin(mid+1,r,2*k+1,x,y));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	buildTree(0,n-1,1);
	//for (int i = 0; i <= 100; i++) cout << i << ". " << maxTree[i] << " " << minTree[i] << endl;
	//cout << getMin(0,n-1,1,1,3);
	bool b = true;
	for (int i = 0; i < n-m+1; i++){
		//cout << getMin(0,n-1,1,i,i+m-1) << " " <<  getMax(0,n-1,1,i,i+m-1)<< endl;
		if (getMax(0,n-1,1,i,i+m-1) - getMin(0,n-1,1,i,i+m-1) <= c) {
			printf("%d\n",i+1);
			if (b) b = false; //gan gia tri chac ton 1 khoang thoi gian
		}
	}
	if (b) printf("NONE\n");
	
	return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//const long long int INF = 1e9;
//long long int n, m, c;
//long long int a[1000005];
//
//
//long long int minTree[4000005], maxTree[4000005];
//void buildTree(long long int l, long long int r, long long int k){
//	//cout << l <<" " << r << " " << k << endl; 
//	if (l==r) {
//		minTree[k] = a[l];
//		maxTree[k] = a[l];
//		return;
//	}
//	long long int mid = (l+r)/2;
//	buildTree(l,mid,2*k);
//	buildTree(mid+1,r,2*k+1);
//	minTree[k] = min(minTree[2*k],minTree[2*k+1]);
//	maxTree[k] = max(maxTree[2*k],maxTree[2*k+1]);
//}
//
//long long int getMax(long long int l, long long int r, long long int k, long long int x, long long int y){
//	if (y<l||x>r) return -INF;
//	if (x<=l&&y>=r) return maxTree[k];
//	long long int mid = (l+r)/2;
//	return max(getMax(l,mid,2*k,x,y),getMax(mid+1,r,2*k+1,x,y));
//}
//
//long long int getMin(long long int l, long long int r, long long int k, long long int x, long long int y){
//	if (y<l||x>r) return INF;
//	if (x<=l&&y>=r) return minTree[k];
//	long long int mid = (l+r)/2;
//	return min(getMin(l,mid,2*k,x,y),getMin(mid+1,r,2*k+1,x,y));
//}
//
//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	cin >> n >> m >> c;
//	for (long long int i = 0; i < n; i++){
//		scanf("%lld",&a[i]);
//	}
//	buildTree(0,n-1,1);
//	//for (int i = 0; i <= 100; i++) cout << i << ". " << maxTree[i] << " " << minTree[i] << endl;
//	//cout << getMin(0,n-1,1,1,3);
//	bool b = true;
//	for (long long int i = 0; i < n-m+1; i++){
//		//cout << getMin(0,n-1,1,i,i+m-1) << " " <<  getMax(0,n-1,1,i,i+m-1)<< endl;
//		if (getMax(0,n-1,1,i,i+m-1) - getMin(0,n-1,1,i,i+m-1) <= c) {
//			b = false;
//			//	
//			cout << i+1 << endl;
//		}
//	}
//	if (b) cout << "NONE\n";
//	
//	
//	return 0;
//}
