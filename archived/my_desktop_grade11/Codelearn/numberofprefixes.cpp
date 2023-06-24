#include <bits/stdc++.h>

using namespace std;

std::vector<int> numberOfPrefixes(std::vector<string> arr1, std::vector<string> arr2){
	int n1 = arr1.size(), n2 = arr2.size(); 
	vector<int> res(n2);
	for (int i = 0; i < n2; i++){
		for (int j = 0; j < n1; j++) 
			if (arr2[i].length()<=arr1[j].length()&&arr2[i]==arr1[j].substr(0,arr2[i].length())) res[i]++;
	}
	
	return res;
}

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	vector<string> arr1(n1);	
	vector<string> arr2(n2);	
	for (int i = 0; i < n1; i++) cin >> arr1[i];
	for (int i = 0; i < n2; i++) cin >> arr2[i];
	auto res = numberOfPrefixes(arr1,arr2);
	for (int i = 0; i < n2; i++){
		cout << res[i] << " ";
	}
	return 0;
}
