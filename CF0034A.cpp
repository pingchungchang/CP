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
	int arr[n+1];
	for(int i = 0;i<n;i++)cin>>arr[i];arr[n] = arr[0];
	pii ans = {0,1};
	for(int i = 1;i<=n;i++){
		if(abs(arr[ans.fs]-arr[ans.sc])>abs(arr[i]-arr[i-1]))ans = {i-1,i};
	}
	cout<<ans.fs%n+1<<' '<<ans.sc%n+1<<'\n';
	return 0;
}
