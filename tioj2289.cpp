#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
pii arr[mxn*4];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=q;i++)cin>>arr[i].fs>>arr[i].sc;
	sort(arr+1,arr+q+1,[](pii a,pii b){return a.sc<b.sc;});
	int r = 0;
	int ans = 0;
	for(int i = 1;i<=q;i++){
		if(r<arr[i].fs)r = arr[i].sc,ans++;
	}
	cout<<ans;
}
