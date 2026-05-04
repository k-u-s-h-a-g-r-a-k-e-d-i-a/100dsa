// Bucket Sort (0 to 1)
#include <stdio.h>

int main(){
    int n; scanf("%d",&n);
    float arr[n];

    for(int i=0;i<n;i++) scanf("%f",&arr[i]);

    // Simple bubble sort as placeholder
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                float t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
        }
    }

    for(int i=0;i<n;i++) printf("%.2f ",arr[i]);
}
