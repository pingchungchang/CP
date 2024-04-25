#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int n,q;
map<int,vector<int>> mp;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		mp[k].push_back(i);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(mp.find(a) == mp.end()){
			cout<<"-1\n";
		}
		else{
			if(mp[a].size()<b)cout<<"-1\n";
			else cout<<mp[a][b-1]<<'\n';
		}
	}
	return 0;
}
