#include <bits/stdc++.h>

using namespace std;

int hardMinSwaps(std::vector<int> arr){
	int n = arr.size();
	for (int i = 0; i < n; i++) arr[i]--;
	int res = 0;
	for (int i = 0; i < n; i++){
		while (i!=arr[i]){
			swap(arr[i],arr[arr[i]]);
			res++;
		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << hardMinSwaps(a);
}
