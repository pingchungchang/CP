#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,m;
	cin>>n>>m;
	int sum = 0;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		int cnt = 0,z = 0;
		while(i%10 == 0){
			z++;
			cnt++;
			i/=10;
		}
		while(i){
			cnt++;
			i/=10;
		}
		sum += cnt;
		i = z;
	}
	sort(arr,arr+n,greater<int>());
	for(int i = 0;i<n;i+=2)sum -= arr[i];
	cout<<(sum>m?"Sasha\n":"Anna\n");
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
