#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<long long int, long long int>, pair<long long int, long long int>> matrix2x2;
matrix2x2 matrix = {{19ll,7ll},{6ll,20ll}};  
//matrix2x2 matrixNghiem = {{1,0},{0,0}};
long long int n, p = 1e9 + 7;

matrix2x2 AnhanB(matrix2x2 a, matrix2x2 b){ 
	return {{(a.first.first*b.first.first+a.first.second*b.second.first)%p
		,(a.first.first*b.first.second+a.first.second*b.second.second)%p}
		,{(a.second.first*b.first.first+a.second.second*b.second.first)%p
		,(a.second.first*b.first.second+a.second.second*b.second.second)%p}};
	//return x;
}

matrix2x2 AmuB(matrix2x2 a, long long int b){
	matrix2x2 matrix1 = {{1,0},{0,1}};
	
	while (b > 0){
		if (b%2 == 1) matrix1 = AnhanB(matrix1,a);
		a = AnhanB(a,a);
		b /= 2;
	}
	return matrix1;
}

int main(){
	//array<array<int, 2>,2> x;
	cin >> n;
	
	//matrix2x2 matrix1 = {{1,0},{0,1}};
	//for (int i = 0; i < n; i++) matrix1 = AnhanB(matrix1,matrix);
	cout << AmuB(matrix,n).first.first;
	
	return 0;
}
