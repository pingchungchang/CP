#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

string arr[101];

bool check(char a,char b,char c,char d,char e){
	return a == 's'&&b == 'n'&&c == 'u'&&d == 'k'&&e == 'e';
}

int solve(){
	int n,m;
	cin>>n>>m;
	arr[0] = string(m+2,'#');
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "#"+arr[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(i+4<=n){
				if(check(arr[i][j],arr[i+1][j],arr[i+2][j],arr[i+3][j],arr[i+4][j])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,j,i+1,j,i+2,j,i+3,j,i+4,j);
					return 0;
				}
				else if(check(arr[i+4][j],arr[i+3][j],arr[i+2][j],arr[i+1][j],arr[i][j])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+4,j,i+3,j,i+2,j,i+1,j,i,j);
					return 0;
				}
			}
			if(j+4<=m){
				string a = "";
				a+=arr[i][j];a+=arr[i][j+1];a+=arr[i][j+2];a+=arr[i][j+3];a+=arr[i][j+4];
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,j,i,j+1,i,j+2,i,j+3,i,j+4);
					return 0;
				}
				reverse(a.begin(),a.end());
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,j+4,i,j+3,i,j+2,i,j+1,i,j);
					return 0;
				}
			}
			if(i+4<=n&&j+4<=m){
				string a = "";a+=arr[i][j];a +=arr[i+1][j+1];a+=arr[i+2][j+2];a+=arr[i+3][j+3];a+=arr[i+4][j+4];
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i,j,i+1,j+1,i+2,j+2,i+3,j+3,i+4,j+4);
					return 0;
				}
				reverse(a.begin(),a.end());
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+4,j+4,i+3,j+3,i+2,j+2,i+1,j+1,i,j);
					return 0;
				}
			}
			if(i+4<=n&&j-4>=1){
				string a = "";a+=arr[i][j];a+=arr[i+1][j-1];a+=arr[i+2][j-2];a+=arr[i+3][j-3];a+=arr[i+4][j-4];
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+0,j+0,i+1,j-1,i+2,j-2,i+3,j-3,i+4,j-4);
					return 0;
				}
				reverse(a.begin(),a.end());
				if(check(a[0],a[1],a[2],a[3],a[4])){
					printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",i+4,j-4,i+3,j-3,i+2,j-2,i+1,j-1,i,j);
					return 0;
				}
			}
		}
	}
	assert(false);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
