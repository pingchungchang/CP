#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i = 0;i<n;i++){
		int a;
		cin>>a;
		if(a == 0)continue;
		v.push_back(a);
	}
	if(v.size()<k){
		cout<<v.size();
		return 0;
	}
	int l = v[k-1];
	int p = k-1;
	for(int i = k;i<v.size();i++){
		if(v[i] != l){
			break;
		}
		p = i;
	}
	cout<<p+1;
	return 0;
}
