#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(v.empty()||v.size()<2)v.push_back(k);
		else{
			if((ll)(v.back()-v[v.size()-2])*(k-v.back())>=0){
				v.pop_back();
			}
			v.push_back(k);
		}
	}
	cout<<v.size()<<'\n';
	for(auto i:v)cout<<i<<' ';
	cout<<'\n';
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

