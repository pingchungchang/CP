#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int arr[mxn];
bitset<mxn> chose;
int n,k;

bool f(int lim){
	bool flag = false;
	chose.reset();
	int c = 0;
	for(int i = 0;i<n;i++){
		if(i == 0){
			if(arr[i]<=lim)chose[i] = true,c++;
		}
		else{
			if(chose[i-1])c++;
			else if(arr[i]<=lim)chose[i] = true,c++;
		}
	}
	if(c>=k)flag = true;
	chose.reset();
	c = 1;
	for(int i = 1;i<n;i++){
		if(chose[i-1])c++;
		else if(arr[i]<=lim)chose[i] = true,c++;
	}
	if(c>=k)flag = true;
	return flag;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int l = *min_element(arr,arr+n),r = *max_element(arr,arr+n);
	while(l != r){
		int mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}
