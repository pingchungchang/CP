#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
int arr[mxn];

void subtask2(){
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		arr[i] -= arr[i-1];
	}
	//for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
	while(q--){
		int a,p;
		cin>>a>>p;
		if(p&1)cout<<arr[p]-a<<'\n';
		else cout<<arr[p]+a<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	subtask2();return 0;
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	while(q--){
		int a,p;
		cin>>a>>p;
		for(int i = 1;i<=p;i++){
			a = max(a-arr[i],arr[i]-a);
		}
		cout<<a<<'\n';
	}
	return 0;
}
