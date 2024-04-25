#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	map<int,int> mp;
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		mp[k]++;
	}
	for(auto &i:mp)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
