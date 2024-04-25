#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    printf("Lumberjacks: \n");
    scanf("%d\n",&n);
    for(int i = 0;i<n;i++){
        int a,b;
        int done = 0;
        int sum =0;
        scanf("%d ",&a);
        for(int j = 0;j<9;j++){
            if(j == 8){
                scanf("%d\n",&b);
               // cout<<"here"<<b;
            }
            else scanf("%d ",&b);
            if(sum*(b-a)<0){
                done = 1;
            }
            sum = b-a;
            a=b;
        }
        if(done == 0){
            printf("Ordered\n");
        }
        else printf("Unordered\n");
    }
}
