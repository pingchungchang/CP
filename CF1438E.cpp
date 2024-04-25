#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 2e5+10;
ll N;
ll arr[mxn];
vector<pii> v1,v2;

void GO(vector<pii> &ans){
	for(int i = 1;i<=N;i++){
		ll high = 1;
		while(high<=arr[i])high<<=1;
		ll sum = 0;
		for(int j = i+2;j<=N;j++){
			sum += arr[j-1];
			if((arr[i]^arr[j]) == sum)ans.push_back(pii(i,j));
			if(sum>high)break;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	GO(v1);
	reverse(arr+1,arr+N+1);
	GO(v2);
	for(auto &i:v2)i.fs = N-i.fs+1,i.sc = N-i.sc+1,swap(i.fs,i.sc);
	for(auto &i:v2)v1.push_back(i);
	sort(v1.begin(),v1.end());
	v1.resize(unique(v1.begin(),v1.end())-v1.begin());
	cout<<v1.size()<<'\n';
}
