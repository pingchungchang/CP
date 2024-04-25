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
	if(n == 1){
		cout<<"Yes\n1\n";
		return 0;
	}
	if(n&1){
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	int a = 0,b = n-1;
	int now = 0;
	for(int i = 0;i<n;i++){
		if(i&1){
			cout<<b-now<<' ';
			now = b--;
		}
		else{
			cout<<a+n-now<<' ';
			now = a++;
		}
	}
	return 0;
}
