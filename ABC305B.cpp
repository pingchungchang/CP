#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int arr[] = {3,1,4,1,5,9};
	char a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	int s = a-'A',e = b-'A';
	int ans= 0;
	for(int i = s;i<e;i++)ans += arr[i];
	cout<<ans;
}
