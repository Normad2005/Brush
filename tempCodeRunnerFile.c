#include <stdio.h>

int hIndex(int* citations, int citationsSize) {
    
    for(int i=0;i<citationsSize;i++){
        int l = 0, r = citationsSize - 1, mid;
        while(l <= r){
            mid = (l + r)/2;
            if(citations[mid] < i)
                l = mid+1;
            else if(citations[mid] > i){
                r = mid-1;
            }
            else{
                if(citations[mid] == i)
                    return mid;
            }
        }
    }
}
