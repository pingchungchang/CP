#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	map<int,int> m;
	for(int i = 0;i<n;i++){
		if(m.count(v[i]) == 0)m[v[i]] = 1;
		else m[v[i]]++;
	}
	pair<int,int> p;
	for(auto it = m.begin();it != m.end();it++){
		if(it->second>p.second){
			p.first = it->first;
			p.second = it->second;
		}
	}
	cout<<n-p.second<<'\n';
	int former = -1;
	for(int i =0;i<n;i++){
		if(v[i] == p.first){
			for(int j = i-1;j>former;j--){
				if(v[j]>p.first){
					cout<<2<<' '<<1+j<<' '<<j+2<<'\n';
				}
				else cout<<1<<' '<<1+j<<' '<<j+2<<'\n';
			}
			former = i;
		}
	}
	for(int i = former+1;i<n;i++){
		if(v[i]>p.first){
			cout<<2<<' '<<i+1<<' '<<i<<'\n';
		}
		else cout<<1<<' '<<i+1<<' '<<i<<'\n';
	}
}
