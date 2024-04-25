#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;char trump;
	cin>>n>>trump;
	map<char,deque<char>> mp;
	for(int i = 0;i<n*2;i++){
		string s;
		cin>>s;
		mp[s[1]].push_back(s[0]);
	}
	for(auto &i:mp)sort(i.sc.begin(),i.sc.end());
	vector<string> arr,brr;
	if(mp[trump].size()>=n){
		for(int i = 0;i<n;i++){arr.push_back(string(1,mp[trump].back())+trump);mp[trump].pop_back();}
		for(auto &i:mp)for(auto &j:i.sc)brr.push_back(string(1,j)+i.fs);
		for(int i = 0;i<n;i++)cout<<brr[i]<<' '<<arr[i]<<'\n';
		return;
	}
	for(auto &i:mp){
		if(i.fs == trump)continue;
		while(i.sc.size()>=2){
			arr.push_back(string(1,i.sc.back())+i.fs);
			i.sc.pop_back();
			brr.push_back(string(1,i.sc.front())+i.fs);
			i.sc.pop_front();
		}
	}
	while(!mp[trump].empty()&&arr.size()<n){
		arr.push_back(string(1,mp[trump].back())+trump);
		mp[trump].pop_back();
	}
	if(arr.size()<n){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	for(auto &i:mp)for(auto &j:i.sc)brr.push_back(string(1,j)+i.fs);
	for(int i = 0;i<n;i++)cout<<brr[i]<<' '<<arr[i]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
