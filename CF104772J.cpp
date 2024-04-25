#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<pii> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v.push_back({k,0});
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v.push_back({k,1});
	}
	sort(v.begin(),v.end());
	int cnt = 0,ans1 = 0;
	for(auto &i:v){
		if(i.sc)cnt++;
		else if(cnt){
			cnt--;
			ans1++;
		}
	}
	cnt = 0;
	int ans2 = 0;
	for(auto &i:v){
		if(!i.sc)cnt++;
		else if(cnt){
			cnt--;
			ans2++;
		}
	}
	cout<<ans1+ans2-n+1<<'\n';
	for(int i = n-ans2;i<=ans1;i++)cout<<i<<' ';
	return 0;
}
