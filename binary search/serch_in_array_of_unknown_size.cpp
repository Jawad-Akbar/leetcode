#include <vector>
#include <algorithm>
using namespace std;
int search(const ArrayReader& reader, int target) {
    int inf=pow(2,31)-1;
    int low=0;
    int high=1e4+10;
    while (low+1<high){
        int mid=(low+high)/2;
        int z=reader.get(mid);
        if (z>target or z==inf)
            high=mid;
        else
            low=mid;
    }
    if (reader.get(low)==target)
        return low;
    else if (reader.get(high)==target)
        return high;
    return -1;
}
int main(){
}