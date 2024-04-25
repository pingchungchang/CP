#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int C = 0;
int one = 0;
int ask(int i,int j,int k){
	C++;
	if(C>25000)exit(0);
	cout<<"? "<<i<<' '<<j<<' '<<k<<endl;
	string re;
	cin>>re;
	return re == "Yes";
}

bool cmp(int a,int b){
	return ask(b,one,a);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	one = 1;
	for(int i = 2;i<=n;i++){
		if(ask(one,one,i))one = i;
	}
	int arr[n];
	for(int i = 1;i<=n;i++)arr[i-1] = i;
	sort(arr,arr+n,cmp);
	int ans[n] = {};
	for(int i = 0;i<n;i++){
		ans[arr[i]-1] = i+1;
	}
	cout<<"! ";for(auto &i:ans)cout<<i<<' ';
	cout<<endl;
	return 0;
}
