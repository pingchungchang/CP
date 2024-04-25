#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	map<int,vector<int>> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		mp[k].push_back(i);
	}
	int ans = 1;
	int l = 1,r = 1;
	for(auto nums:mp){
		int p1 = 0,p2 = 0;
		while(p2 != nums.sc.size()&&p1 != nums.sc.size()){
			int tmp = (p2-p1+1)*2-(nums.sc[p2]-nums.sc[p1]+1);
			if(tmp>ans){
				ans = tmp;
				l = nums.sc[p1],r= nums.sc[p2];
				p2++;
			}
			else if(tmp>0){
				p2++;
			}
			else{
				p1++;
			}
		}
	}
	cout<<arr[l]<<' '<<l<<' '<<r<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

