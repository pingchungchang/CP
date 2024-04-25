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
map<int,int> mp;

bool f(int now){
	int more = 0;
	for(auto &it:mp){
		if(it.fs>now)more += it.sc;
		else more += it.sc-1;
	}
	int k = 0;
	for(int i = 1;i<=now;i++){
		if(mp.find(i) == mp.end())k++;
	}
	if(more/2>=k)return true;
	else return false;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	int l = 0,r = n;
	while(l != r){
		int mid = (l+r+1)>>1;
		if(f(mid))l = mid;
		else r = mid-1;
	}
	cout<<l;
}

