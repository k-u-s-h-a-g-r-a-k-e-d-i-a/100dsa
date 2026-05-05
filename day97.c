// Meeting Rooms (max non-overlapping)
#include <stdio.h>
#include <stdlib.h>

typedef struct{int start,end;} Interval;

int cmp(const void *a,const void *b){
    return ((Interval*)a)->end - ((Interval*)b)->end;
}

int main(){
    int n; scanf("%d",&n);
    Interval arr[n];

    for(int i=0;i<n;i++) scanf("%d %d",&arr[i].start,&arr[i].end);

    qsort(arr,n,sizeof(Interval),cmp);

    int count=1, last=arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start>=last){
            count++;
            last=arr[i].end;
        }
    }
    printf("%d",count);
}
