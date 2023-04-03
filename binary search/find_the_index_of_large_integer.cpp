int getIndex(ArrayReader &reader) {
    int n=reader.length();
    int low=0;
    int high=n-1;
    while (low<high){
        int size=(high-low+1);
        if (size%2==0){
            int l=low;
            int r=low+size/2-1;
            int x=r+1;
            int y=high;
            int k=reader.compareSub(l,r,x,y);
            if (k==1)
                high=r;
            if (k==-1)
                low=x;
        }
        else{
            int l=low;
            int r=low+size/2-1;
            int x=r+1;
            int y=high-1;
            int k=reader.compareSub(l,r,x,y);
            if (k==1)
                high=r;
            if (k==-1)
                low=x;
            if (k==0)
                low=high;
        }
    }
    return low;
}