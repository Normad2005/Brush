#include <stdio.h>

int hIndex(int* citations, int citationsSize) {

    int l = 0, r = citationsSize - 1, mid, h;

    while(l <= r){
        mid = (l + r)/2;
        h = citationsSize - mid;
        if(citations[mid] == h)
            return h;
        else if(citations[mid] > h)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return citationsSize - l;
}
