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
	bool flag = true;
	for(auto &i:arr)cin>>i,flag= flag&&(!i);
	if(flag){
		cout<<"0\n";
		return;
	}
	vector<pii> v1(33),v2(33);
	if(*max_element(arr,arr+n)>0){
		v1.clear();
		int big = max_element(arr,arr+n)-arr;
		int val = arr[big];
		while(abs(*min_element(arr,arr+n))>val){
			v1.push_back({big,big});
			val += val;
		}
		for(int i = 0;i<n;i++){
			if(arr[i]<0){
				v1.push_back({i,big});
			}
		}
		for(int i = 1;i<n;i++)v1.push_back({i,i-1});
	}
	if(*min_element(arr,arr+n)<0){
		v2.clear();
		int big = min_element(arr,arr+n)-arr;
		int val = arr[big];
		while(abs(*max_element(arr,arr+n))>abs(val)){
			v2.push_back({big,big});
			val += val;
		}
		for(int i = 0;i<n;i++){
			if(arr[i]>0)v2.push_back({i,big});
		}
		for(int i = n-2;i>=0;i--)v2.push_back({i,i+1});
	}
	if(v1.size()>v2.size()){
		swap(v1,v2);
	}
	cout<<v1.size()<<'\n';
	for(auto &i:v1)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
