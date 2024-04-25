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
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	while(q--){
		int tar;
		cin>>tar;
		int l = 1,r = n;
		while(l != r){
			int mid = (l+r)>>1;
			if(arr[mid]<tar)l = mid+1;
			else r = mid;
		}
		cout<<(arr[l]<tar?n+1:l)<<'\n';
	}
	return 0;
}
