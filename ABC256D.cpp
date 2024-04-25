#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<pii> v(n);
	for(int i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
	sort(v.begin(),v.end());
	vector<pii> ans = {make_pair(-1,-1)};
	for(auto &i:v){
		if(ans.back().sc>=i.fs){
			ans.back().sc = max(ans.back().sc,i.sc);
		}
		else{
			ans.push_back(i);
		}
	}
	for(int i = 1;i<ans.size();i++)cout<<ans[i].fs<<' '<<ans[i].sc<<'\n';
	return 0;
}

