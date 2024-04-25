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
	int n;
	cin>>n;
	int arr[2] = {};
	while(n--){
		int a,b;
		cin>>a>>b;
		arr[0]+=a,arr[1] += b;
	}
	cout<<(arr[0]==arr[1]?"Draw":arr[0]>arr[1]?"Takahashi":"Aoki");
}
