/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target,MountainArray & m) {
        int n=m.length();
        int low=0,high=n-1;

        while (low<high){
            int mid=(low+high)/2;
            int mv=m.get(mid);
            if (mv>m.get(mid+1))
                high=mid;
            else
                low=mid+1;

        }
        int peak=low;
        // cout<<"peak "<<peak<<endl;
        // BS:1
        low=0;
        high=peak;
        while (low<high){
            int mid=(low+high+1)/2;
            int mv=m.get(mid);
            if (mv>target)
                high=mid-1;
            else
                low=mid;
        }
        if (m.get(low)==target)
            return low;
        low=peak;
        high=n-1;
        while (low<high){
            int mid=(low+high)/2;
            int mv=m.get(mid);
            if (mv>target)
                low=mid+1;
            else
                high=mid;
        }
        if (m.get(low)==target)
            return low;
        return -1;
    }
};