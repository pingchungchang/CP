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
	pii arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i].fs,arr[i].sc = i+1;
	sort(arr,arr+n);
	int sum = 0;
	ll ans = 0;
	for(auto &i:arr){
		ans += sum;
		sum += i.fs;
	}
	for(auto &i:arr)cout<<i.sc<<' ';cout<<'\n';
	cout<<fixed<<setprecision(2)<<ans/(long double)n;
}
