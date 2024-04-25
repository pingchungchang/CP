#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i = 0;i<n;i++){
		char c;
		cin>>c;
		int tmp = 0;
		if(c == 'L')tmp = 0;
		else tmp = 1;
		if(v.empty()||v.back() != tmp)v.push_back(tmp);
	}
	//for(auto &i:v)cout<<i;cout<<endl;
	int cnt = v.size()/2;
	if(cnt<=k){
		cout<<n-1;
		return 0;
	}
	else cout<<n-v.size()+k*2;
}
