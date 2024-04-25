#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll,ll>
#define ll long long
bool cmp(pll a,pll b){
	if(a.second != b.second)return a.second<b.second;
	else return a.first<b.first;
}
void solve(){
	vector<pll> v(3);
	for(int i =0 ;i<3;i++)cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end(),cmp);
	if(v[1].second == v[2].second){
		cout<<v[2].first-v[1].first<<'\n';
	}
	else cout<<0<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
