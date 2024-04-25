#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n*2);
	for(int i =0;i<n;i++){
		cin>>v[i];
	}
	for(int i = 0;i<n;i++){
		v[i+n] = v[i];
	}
	vector<int> v2(n*2);
	for(int i = 0;i<n*2;i++){
		for(int j = i-1;j>=0;j--){
			if(v[j] == v[i]){
				v2[i] = j;
				break;
			}
		}
	}
}
