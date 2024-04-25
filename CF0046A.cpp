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
	int now = 0;
	for(int i = 1;i<n;i++){
		now = (now+i)%n;
		cout<<now+1<<' ';
	}
	return 0;
}
