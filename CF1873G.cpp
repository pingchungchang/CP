#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int n = s.size();
	vector<int> v;
	int len = 0;
	for(auto &i:s){
		if(i == 'B'){
			v.push_back(len);
			len = 0;
		}
		else len++;
	}
	v.push_back(len);
	ll sum = 0;
	for(auto &i:v)sum += i;
	cout<<sum-*min_element(v.begin(),v.end())<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
