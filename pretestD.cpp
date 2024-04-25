#include <bits/stdc++.h>
using namespace std;

int sx,sy;
int ex,ey;
int v[105][105];

void fv(int s,int e){
	int l = (e-s+1)/2;
	for(int i = 0;i<l;i++){
		for(int j = sx;j<=ex;j++){
			int tmp = v[j][i+s]+v[j][e-i];
			v[j][i+s] = tmp;
			v[j][e-i] = tmp;
		}
	}
}
void fh(int s,int e){
	int l = (e-s+1)/2;
	for(int i = 0;i<l;i++){
		for(int j = sy;j<=ey;j++){
			int tmp = v[s+i][j]+v[e-i][j];
			v[s+i][j] = tmp;
			v[e-i][j] = tmp;
		}
	}
}
void rl(int stx,int sty,int l){
	for(int i = 0;i<=l;i++){
		for(int j = i+1;j<=l;j++){
			int asd = v[stx+i][sty+j] + v[stx+j][sty+i];
//			cout<<stx+i<<' '<<stx+j<<' '<<stx+l-j<<' '<<sty+l-i<<endl;			
			v[stx+i][sty+j] = asd;
			v[stx+j][sty+i] = asd;
		}
	}
}
void lr(int stx,int sty,int l){
	for(int i = 0;i<l;i++){
		for(int j = l-i-1;j>=0;j--){
			int asd = v[stx+i][sty+j]+v[stx+l-j][sty+l-i];
			v[stx+i][sty+j] = asd;
			v[stx+l-j][sty+l-i] = asd;
		}
	}
}
int main(){
	sx = 1,sy=1;
	int k;
	cin>>ex>>ey>>k;
	for(int i = 1;i<=ex;i++){
		for(int j = 1;j<=ey;j++){
			cin>>v[i][j];
		}
	}
	for(int i = 0;i<k;i++){
		string x;
		int s;
		cin>>x>>s;
		int l = s;
		if(x == "R"){
			fv(ey-2*s+1,ey);
			ey = ey-s;
		}
		else if(x == "L"){
			fv(sy,sy+2*s-1);
			sy = sy+s;
		}
		else if(x == "U"){
			fh(sx,sx+2*s-1);
			sx = sx+s;
		}
		else if(x == "D"){
			fh(ex-2*s+1,ex);
			ex = ex-s;
		}
		else if(x == "LU"){
			lr(sx,sy,l);
			for(int i = 0;i<l;i++){
				for(int j = 0;j<l-i;j++){
					v[i+sx][j+sy] = 0;
				}
			}
		}
		else if(x =="LD"){
			rl(ex-l,sy,l);
			for(int i = 0;i<=l;i++){
				for(int j = i;j>=0;j--){
					v[ex-l+1+i][sy+j] = 0;
				}
			}
		}
		else if(x == "RU"){
			rl(sx,ey-l,l);
			for(int i = 0;i<=l;i++){
				for(int j = i+1;j<=l;j++){
					v[sx+i][ey-l+j] = 0;
				}
			}			
		}
		else if(x == "RD"){
			lr(ex-s,ey-s,l);
			for(int i = 0;i<l;i++){
				for(int j = l-1-i;j<l;j++){
					v[i+ex-s+1][j+ey-s+1] = 0;
				}
			}
		}
	
	}
	cout<<(ex-sx+1)<<' '<<(ey-sy+1)<<'\n';	
	for(int i = sx;i<=ex;i++){
		for(int j = sy;j<=ey;j++){
			cout<<v[i][j];
			if(j != ey)cout<<' ';
		}
		cout<<'\n';
	}	
}

/*
5 5 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/
