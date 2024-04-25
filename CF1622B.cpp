#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	string s;
	cin>>s;
	set<int> like,dis;
	int p = 1;
	for(auto &i:s)if(i == '0')dis.insert(p++);
	for(;p<=n;p++)like.insert(p);
	set<pll> st1,st2;
	for(int i = 0;i<n;i++){
		if(s[i]== '1'){
			if(like.find(arr[i])!=like.end())like.erase(arr[i]);
			else st1.insert({arr[i],i});
		}
		else{
			if(dis.find(arr[i])!=dis.end())dis.erase(arr[i]);
			else st2.insert({arr[i],i});
		}
	}
	int ans[n];
	for(int i = 0;i<n;i++)ans[i] = arr[i];
	for(auto &i:st1){
		ans[i.sc] = *like.begin();
		like.erase(*like.begin());
	}
	for(auto &i:st2){
		ans[i.sc] = *dis.begin();
		dis.erase(*dis.begin());
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
