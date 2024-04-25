#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	int sum = 0;
	for(auto &i:arr)cin>>i,sum ^= i;
	vector<tuple<int,int,int>> ans;
	auto f = [&](int a,int b,int c){
		arr[a] = arr[b] = arr[c] = arr[a]^arr[b]^arr[c];
	};
	for(int i = 2;i<n;i+=2){
		ans.push_back(make_tuple(i-2,i-1,i));
		f(i-2,i-1,i);
	}
	for(int i = 1;i<n;i+=2){
		if(i != n-1&&i != n-2)ans.push_back(make_tuple(i-1,i,n-2));
	}
	if((n-3)&1){
		if(sum == 0){
			cout<<"YES\n";
			cout<<ans.size()<<'\n';
			for(auto &i:ans)cout<<get<0>(i)+1<<' '<<get<1>(i)+1<<' '<<get<2>(i)+1<<'\n';
			return 0;
		}
		else cout<<"NO\n";
		return 0;
	}
	else{
		cout<<"YES\n";
		cout<<ans.size()<<'\n';
		for(auto &i:ans)cout<<get<0>(i)+1<<' '<<get<1>(i)+1<<' '<<get<2>(i)+1<<'\n';
		return 0;
	}
}
