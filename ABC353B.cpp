#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
int N,K;
int arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K;
	for(int i = 0;i<N;i++)cin>>arr[i];
	int sum = 0,ans = 0;
	for(int i = 0;i<N;i++){
		sum += arr[i];
		if(sum>K){
			sum = arr[i];
			ans++;
		}
	}
	if(sum)ans++;
	cout<<ans<<'\n';
	return 0;
}
