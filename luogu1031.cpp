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
	int arr[n];
	int sum = 0;
	for(auto &i:arr)cin>>i,sum += i;
	sum /= n;
	for(auto &i:arr)i -= sum;
	for(int i = 1;i<n;i++)arr[i] += arr[i-1];
	ll ans = 0;
	for(int i = 0;i<n;i++)if(arr[i])ans++;
	cout<<ans;
}
