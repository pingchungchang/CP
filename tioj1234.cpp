#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	if(n == 2){
		cout<<"1\n1/2";
		return 0;
	}
	vector<pair<double,pair<int,int>>> v;
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<i;j++){
			if(gcd(j,i) == 1){
				double k = (double)j/(double)i;
				v.push_back(make_pair(k,make_pair(j,i)));
			}
		}
	}
//	for(auto i:v){
//		cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<'\n';
//	}
	sort(v.begin(),v.end());
	cout<<(int)v.size()<<'\n';
	cout<<v[n-1].second.first<<'/'<<v[n-1].second.second;
}
