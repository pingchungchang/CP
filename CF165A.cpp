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
int main(){
	io
	int n;
	cin>>n;
	map<int,vector<pii>> x,y;
	int arr[n] = {};
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		x[a].push_back({b,i});
		y[b].push_back({a,i});
	}
	for(auto &i:x)sort(_all(i.sc));
	for(auto &i:y)sort(_all(i.sc));
	for(auto &i:x){
		for(int j= 1;j<(int)i.sc.size()-1;j++){
			arr[i.sc[j].sc]|=1;
		}
	}
	for(auto &i:y){
		for(int j = 1;j<(int)i.sc.size()-1;j++){
			arr[i.sc[j].sc]|=2;
		}
	}
	int ans = 0;
	for(auto &i:arr)if(i == 3)ans++;
	cout<<ans;
}

