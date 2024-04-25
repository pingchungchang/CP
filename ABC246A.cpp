#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	vector<pii> v(3);
	for(int i = 0;i<3;i++)cin>>v[i].fs>>v[i].sc;
	map<int,int> x;
	map<int,int> y;
	for(int i = 0;i<3;i++){
		if(x.count(v[i].fs) == 0)x[v[i].fs] = 1;
		else x[v[i].fs]++;
		if(y.count(v[i].sc) == 0)y[v[i].sc] = 1;
		else y[v[i].sc]++;
	}
	for(auto i:x){
		if(i.sc == 1)cout<<i.fs<<' ';
	}
	for(auto i:y)if(i.sc == 1)cout<<i.fs;
}

