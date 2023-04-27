class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for (int i:mat[0]){
            bool t=true;
            for (int j=1;j<mat.size();j++)
                t=(t and binary_search(mat[j].begin(),mat[j].end(),i));
            if (t)
                return i;
        }
        return -1;
    }
};