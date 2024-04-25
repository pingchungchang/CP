#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	int big = 0;
	int small = 1e9;
	for(int i = 0;i<=a1;i++){
		if(i*k1>n)break;
		int d = n-i*k1;
		big = max(big,i+min(a2,d/k2));
	}
	n -= a1*(k1-1)+a2*(k2-1);
	cout<<max(0,n)<<' '<<big;
}
