#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
    char c=0;
    char *nm[3]={"alp","num","sign"};
    int arr[3]={0};
    printf("请输入一串字符：");
    
    while(scanf("%c",&c)!=EOF){
        if(c>='A'&&c<='Z'||c>='a'&&c<='z'){
            arr[0]++;
        }
        else if(c>='0'&&c<='9'){
            arr[1]++;
        }
        else if(c!='\n'){
            arr[2]++;
        }
    }
    int flag=0;
    for(int i=0;i<2;i++){
        flag=0;
        for(int j=2;j>i;j--){
            if(arr[j]>arr[j-1]){
                flag=1;
                int tp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tp;
                char *tmp=nm[j];
                nm[j]=nm[j-1];
                nm[j-1]=tmp;
            }
        }
        if(flag==0) break;
    }
    
    for(int k=0;k<=arr[0];k++){
        if(k==0){
            printf("%3d",arr[0]);
        }
        else{
            printf("*****");
        }


        if(k==arr[0]-arr[1]){
            printf("  %3d",arr[1]);
        }
        else if(k>arr[0]-arr[1]){
            printf(" *****");
        }


        if(k==arr[0]-arr[2]){
            printf("  %3d",arr[2]);
        }
        else if(k>arr[0]-arr[2]){
            printf(" *****");
        }


        printf("\n");
    }

    printf("%5s  %5s  %5s",nm[0],nm[1],nm[2]);


    system("pause");
    return 0;
}