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
	int n,d;
	cin>>n>>d;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)if(i != j&&abs(arr[i]-arr[j])<=d)ans++;
	cout<<ans;
}
