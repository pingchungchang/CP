#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	map<string,set<int>> mp;
	int pts[3] = {};
	mp.clear();
	for(int i = 0;i<3;i++){
		for(int j = 0;j<n;j++){
			string s;
			cin>>s;
			mp[s].insert(i);
		}
	}
	for(auto i:mp){
		if(i.sc.size() == 1)pts[*i.sc.begin()]+=3;
		else if(i.sc.size() == 2)for(auto &j:i.sc)pts[j] ++;
	}
	for(auto &i:pts)cout<<i<<' ';cout<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

