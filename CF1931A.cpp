#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string arr[100];

void solve(){
	int n;
	cin>>n;
	cout<<arr[n]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:arr)i = string(3,'z');
	for(char i = 'a';i<='z';i++){
		for(char j = 'a';j<='z';j++){
			for(char k = 'a';k<='z';k++){
				string tmp = string(1,i)+j+k;
				int s = i-'a'+1+j-'a'+1+k-'a'+1;
				arr[s] = min(arr[s],tmp);
			}
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
