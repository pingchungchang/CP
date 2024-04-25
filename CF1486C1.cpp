#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


inline int ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	int re;
	cin>>re;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int sb = ask(1,n);
	int l = 1,r = max(sb-1,1);
	while(l < r){
		int mid = (l+r+1)>>1;
		if(ask(mid,sb) == sb)l = mid;
		else r = mid-1;
	}
	if(l != sb&&ask(l,sb) == sb){
		cout<<"! "<<l<<endl;
		return 0;
	}
	l = sb+1,r = n;
	while(l<r){
		int mid = (l+r)>>1;
		if(ask(sb,mid) == sb)r = mid;
		else l = mid+1;
	}
	cout<<"! "<<l<<endl;
}
