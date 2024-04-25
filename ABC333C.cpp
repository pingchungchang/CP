#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<ll> v;
vector<ll> all;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll now = 1;
	while(now<=2e18){
		v.push_back(now);
		if(now>=1e18)break;
		now = now*10+1;
	}
	for(int i = 0;i<v.size();i++){
		for(int j = i;j<v.size();j++){
			for(int k = j;k<v.size();k++){
				all.push_back(v[i]+v[j]+v[k]);
			}
		}
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	int n;
	cin>>n;
	cout<<all[n-1];
}
