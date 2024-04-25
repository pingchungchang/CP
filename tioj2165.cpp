#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e5+10;
int cnt[mxn];
int arr[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		ll sum = 0;
		for(int j = i;j<n&&(sum += arr[j])<mxn;j++){
			cnt[sum]++;
		}
	}
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		cout<<cnt[k]<<'\n';
	}
	return 0;
}
