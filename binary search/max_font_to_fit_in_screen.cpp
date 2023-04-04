class Solution {
public:
    bool is_valid(int h,int w,int mid,string &text,FontInfo fontInfo){
        int h2=fontInfo.getHeight(mid);
        long long w2=0;
        for (char i:text){
            if (w2>w)
                return false;
            w2=w2+fontInfo.getWidth(mid,i);
        }
        if (h2<=h and w2<=w)
            return true;
        return false;
        
    }
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int low=0;
        int high=fonts.size()-1;
        if (!is_valid(h,w,fonts[low],text,fontInfo))
            return -1;
        while (low+1<high){
            int mid=(low+high)/2;
            if (is_valid(h,w,fonts[mid],text,fontInfo))
                low=mid;
            else
                high=mid;
        }
        if (is_valid(h,w,fonts[high],text,fontInfo))
            low=high;
        return fonts[low];
    }
};