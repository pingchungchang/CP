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
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<=n;i++){
		cout<<*lower_bound(arr,arr+m,i)-i<<'\n';
	}
	return 0;
}
