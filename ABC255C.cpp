#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll x,a,d,n;
	cin>>x>>a>>d>>n;
	ll lst = a+(n-1)*d;
	if(lst>x&&a>x){
		cout<<abs(x-min(a,lst));
		return 0;
	}
	else if(lst<x&&a<x){
		cout<<x-max(a,lst);
		return 0;
	}
	if(a>lst){
		swap(a,lst);
		d = -d;
	}
	if(d == 0){
		cout<<abs(x-a);
		return 0;
	}
	ll dif = (x-a)/d*d+a;
	ll dif2 = (x-a)/d*d+d+a;
	cout<<min(abs(dif-x),abs(dif2-x));
	return 0;
}

