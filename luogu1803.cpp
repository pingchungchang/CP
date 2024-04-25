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
	for(auto &i:arr)cin>>i.sc>>i.fs;
	sort(arr,arr+n);
	int ans = 0,r = -1;
	for(auto &i:arr){
		if(r<=i.sc)ans++,r = i.fs;
	}
	cout<<ans;
}
