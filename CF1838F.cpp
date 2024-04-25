#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 110;
string arr[mxn];
int n;

pii ask(pii s = make_pair(1,1)){
	cout<<"? "<<s.fs<<' '<<s.sc<<endl;
	for(int i = 0;i<n;i++)cout<<arr[i]<<endl;
	pii re;
	cin>>re.fs>>re.sc;
	return re;
}

int main(){
	cin>>n;
	for(int i = 0;i<n;i++)arr[i] = string(n,'<');
	int d = 0;
	for(int i = 0;i<n;i++){
	}
}
