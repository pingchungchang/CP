#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if(n&1)cout<<"-1\n";
	else{
		int arr[n+1];
		for(int i = 1;i<=n;i++)arr[i] = i;
		for(int i = 1;i+i<=n;i++)swap(arr[i],arr[n-i+1]);
		for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	}
	return 0;
}
