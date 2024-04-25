#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string a,b;
	vector<int> v[2];
	cin>>n>>a>>b;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])v[a[i]-'a'].push_back(i+1);
	}
	vector<pii> ans;
	for(int i = 0;i<2;i++){
		while(v[i].size()>=2){
			ans.push_back({v[i].back(),v[i].end()[-2]});
			v[i].pop_back();v[i].pop_back();
		}
	}
	if(v[0].size()+v[1].size() == 1){
		cout<<-1;
		return 0;
	}
	if(v[0].size()+v[1].size()){
		ans.push_back({v[0][0],v[0][0]});
		ans.push_back({v[0][0],v[1][0]});
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
