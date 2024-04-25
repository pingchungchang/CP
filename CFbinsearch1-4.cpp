#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int arr[100005];
int n,q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	cin>>q;
	while(q--){
		int s,e;
		cin>>s>>e;
		int l = 1,r = n;
		while(l != r){
			int mid = (l+r+1)>>1;
			if(arr[mid]>=s)r = mid-1;
			else l = mid;
		}
		if(arr[l]>=s)s = l-1;
		else s = l;
		l = 1,r = n;
		while(l != r){
			int mid = (l+r+1)>>1;
			if(arr[mid]>e)r = mid-1;
			else l = mid;
		}
		if(arr[l]>e)e = l-1;
		else e = l;
		cout<<e-s<<' ';
	}
	return 0;
}
