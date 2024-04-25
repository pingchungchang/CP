#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<int> v[6];
	for(int i = 0;i<6;i++){
		int k;
		cin>>k;
		while(k--){
			int t;
			cin>>t;
			t--;
			v[i].push_back(t);
		}
	}
	int ans = 0;
	for(int i = 0;i<pow(6,6);i++){
		vector<int> rest;
		int tmp = i;
		for(int j = 0;j<6;j++){
			rest.push_back(tmp%6);
			tmp/=6;
		}
		bool flag = true;
		for(int j = 0;j<6;j++){
			for(auto &k:v[j]){
				if(rest[k] == j)flag = false;
			}
		}
		if(flag)ans++;
	}
	cout<<ans;
}
