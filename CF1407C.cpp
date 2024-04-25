#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int ask(int a,int b){
	cout<<"? "<<a<<' '<<b<<endl;
	int re;
	cin>>re;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int ans[n+1] = {};
	int big = 1;
	for(int i = 2;i<=n;i++){
		int a = ask(big,i),b = ask(i,big);
		if(a>b){
			ans[big] = a;
			big = i;
		}
		else{
			ans[i] = b;
		}
	}
	ans[big] = n;
	cout<<"! ";
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}
