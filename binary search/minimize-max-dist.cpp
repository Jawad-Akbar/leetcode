class Solution {
public:

    bool poss(double d,int k,vector<int>& stations){
        int new_s=0;
        for (int i=0;i<stations.size()-1;i++){
            double dist=stations[i+1]-stations[i];
            new_s+=floor(dist/d);
        }
        return (k>=new_s);
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double l=0;
        double h=1e8;
        while (h-l>0.0000001){
            double d=(l+h)/2;
            if (poss(d,k,stations))
                h=d;
            else
                l=d;
        }
        return l;
    }
};