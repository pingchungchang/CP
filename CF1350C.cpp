#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int lpf[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	map<int,vector<int>> mp;
	for(auto &i:arr){
		vector<pair<int,int>> v;
		while(i != 1){
			if(v.empty()||v.back().fs != lpf[i])v.push_back({lpf[i],1});
			else v.back().sc++;
			i/=lpf[i];
		}
		for(auto &i:v)mp[i.fs].push_back(i.sc);
	}
	ll ans = 1;
	for(auto &i:mp){
		int p = 0;
		sort(i.sc.begin(),i.sc.end());
		if(i.sc.size() == n-1){
			p = i.sc[0];
		}
		else if(i.sc.size() == n){
			p = i.sc[1];
		}
		else p = 0;
		while(p--)ans *= i.fs;
	}
	cout<<ans;
}
