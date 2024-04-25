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
	cin>>n;
	map<string,int> mp;
	vector<pair<string,int>> op;
	int big = 0;
	for(int i = 1;i<=n;i++){
		string s;
		int k;
		cin>>s>>k;
		mp[s]+=k;
		op.push_back({s,k});
	}
	for(auto &i:mp)big = max(big,i.sc);
	map<string,int> sum;
	for(auto &i:op){
		sum[i.fs] += i.sc;
		if(mp[i.fs] == big&&sum[i.fs]>=big){
			cout<<i.fs;
			return 0;
		}
	}
}
