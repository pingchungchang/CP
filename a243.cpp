#include <iostream>
using namespace std;

int v1[101][101] = {};
int v2[101][101] = {};
int ans[101][101] = {};
int main(){
	int m,n,o,p;
	cin>>m>>n>>o>>p;
	if(n != o){
		cout<<"Error";
		return 0;
	}
	for(int i =0;i<m;i++){
		for(int j =0;j<n;j++){
			cin>>v1[i][j];
		}
	}
	for(int i =0;i<o;i++){
		for(int j =0;j<p;j++){
			cin>>v2[i][j];
		}
	}
	for(int i =0;i<m;i++){
		for(int j =0;j<p;j++){
			for(int l =0;l<n;l++){
				ans[i][j]+= v1[i][l]*v2[l][j];
			}
		}
	}
	for(int i =0;i<m;i++){
		for(int j =0;j<p;j++){
			cout<<ans[i][j];
			//if(j != p-1)cout<<' ';
			cout<<' ';
		}
		cout<<'\n';
	}
}
