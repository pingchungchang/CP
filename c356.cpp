#include <stdio.h>

//using namespace std;

int main(){
    int n;
    int row = 0;
    int column = 0;
    scanf("%d\n",&n);
    char ans[n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            char c;
            scanf("%c",&c);
            if(i == j)ans[i] = c;
        }
    }
    printf("%s",ans);
}//fail
