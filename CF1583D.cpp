#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
int arr[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = -n+1;i<n;i++){
		int sh = max(1,-i+1);
		cout<<"? ";for(int j = 1;j<n;j++)cout<<sh+i<<' ';cout<<sh<<endl;
		int re;
		cin>>re;
		arr[re] = -i;
	}
	int big = *max_element(arr+1,arr+n+1);
	int sh = n-big;
	for(int i =1;i<=n;i++)arr[i] += sh;
	cout<<"! ";for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
}
