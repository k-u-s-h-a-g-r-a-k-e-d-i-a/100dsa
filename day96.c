// Count Inversions
#include <stdio.h>

int merge(int arr[],int temp[],int l,int m,int r){
    int i=l,j=m,k=l,inv=0;
    while(i<m && j<=r){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv += (m-i);
        }
    }
    while(i<m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(i=l;i<=r;i++) arr[i]=temp[i];
    return inv;
}

int mergeSort(int arr[],int temp[],int l,int r){
    int inv=0;
    if(l<r){
        int m=(l+r)/2;
        inv+=mergeSort(arr,temp,l,m);
        inv+=mergeSort(arr,temp,m+1,r);
        inv+=merge(arr,temp,l,m+1,r);
    }
    return inv;
}

int main(){
    int n; scanf("%d",&n);
    int arr[n], temp[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("%d",mergeSort(arr,temp,0,n-1));
}
