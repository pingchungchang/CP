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
	if(n<=8){
		int arr[n];
		for(int i = 0;i<n;i++)arr[i] = i+1;
		do{
			bool flag = true;
			for(int i = 1;i<n;i++)if(abs(arr[i]-arr[i-1])>4||abs(arr[i]-arr[i-1])<2)flag = false;
			if(flag){
				for(auto &i:arr)cout<<i<<' ';cout<<'\n';
				return;
			}
		}while(next_permutation(arr,arr+n));
		cout<<"-1\n";
		return;
	}
	vector<int> ans;
	int p;
	for(p = 1;p<=n;p+=2)ans.push_back(p);
	p = ans.back();
	if(n&1){
		ans.push_back(p-3);
		ans.push_back(p-1);
		ans.push_back(p-5);
		p -= 7;
	}
	else{
		ans.push_back(p-3);
		ans.push_back(p+1);
		ans.push_back(p-1);
		ans.push_back(p-5);
		p-= 7;
	}
	for(;p>=1;p-= 2)ans.push_back(p);
	for(auto &i:ans)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
