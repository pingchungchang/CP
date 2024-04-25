#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(n == 1){
		cout<<"0\n";
		return;
	}
	else if(n == 2){
		vector<pii> ans;
		while(arr[0]>arr[1]){
			if(arr[0]>0){
				ans.push_back({1,0});
				arr[1] += arr[0];
			}
			else{
				ans.push_back({0,0});
				arr[0] += arr[0];
			}
		}
		cout<<ans.size()<<'\n';
		for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
		return;
	}
	vector<int> pos,neg;
	for(int i= 0;i<n;i++){
		if(arr[i]>0)pos.push_back(i);
		else if(arr[i]<0)neg.push_back(i);
	}
	vector<pii> ans;
	if(pos.empty()&&neg.empty()){
		cout<<"0\n";
		return;
	}
	if(pos.size()>neg.size()){
		int p = pos[0];
		while(arr[p]<20){
			ans.push_back({p,p});
			arr[p] += arr[p];
		}
		for(auto &i:neg){
			ans.push_back({i,p});
			arr[i] += arr[p];
		}
	}
	else{
		int p = neg[0];
		while(arr[p]>-20){
			ans.push_back({p,p});
			arr[p] += arr[p];
		}
		for(auto &i:pos){
			ans.push_back({i,p});
			arr[i] += arr[p];
		}
	}
	for(int i = 1;i<n;i++)ans.push_back({i,i-1});
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
