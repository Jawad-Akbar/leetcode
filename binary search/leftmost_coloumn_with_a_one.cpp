int call_for_row(BinaryMatrix  &mat,int row,int n){
    int low=0;
    int high=n-1;
    if (mat.get(row,n-1)==0)
        return -1;
    while (low+1<high){
        int mid=(low+high)/2;
        if (mat.get(row,mid)==0)
            low=mid;
        else
            high=mid;
    }
    if (mat.get(row,low)==1)
        high=low;
    return high;
}
int leftMostColumnWithOne(BinaryMatrix &mat) {
    auto k=mat.dimensions();
    int rows=k[0];
    int cols=k[1];
    int minrow=200;
    for (int i=0;i<rows;i++){
        int kk=call_for_row(mat,i,cols);
        if (kk!=-1)
            minrow=min(minrow,kk);
    }
    if (minrow==200)
        minrow=-1;
    return minrow;
}