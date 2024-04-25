#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int ask(int sx,int ex,int sy,int ey){
	cout<<"? "<<sx<<' '<<ex<<' '<<sy<<' '<<ey<<endl;
	int re;
	cin>>re;
	return re;
}
int main(){
	int n;
	cin>>n;
	int l = 1,r = n;
	while(l != r){
		int mid = (l+r)/2;
		int k = ask(l,mid,1,n);
		if(mid-l+1 == k)l = mid+1;
		else r = mid;
	}
	int ans1 = l;
	l = 1,r = n;
	while(l != r){
		int mid = (l+r)/2;
		int k = ask(1,n,l,mid);
		if(k == mid-l+1)l = mid+1;
		else r = mid;
	}
	cout<<"! "<<ans1<<' '<<l<<endl;
	return 0;	
}

