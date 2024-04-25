#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int n,q;
int arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	while(q--){
		int tar;
		cin>>tar;
		int l = 1,r = n;
		while(l != r){
			int mid = (l+r)>>1;
			if(arr[mid]>=tar)r = mid;
			else l = mid+1;
		}
		cout<<(arr[l]==tar?"YES\n":"NO\n");
	}
	return 0;
}
