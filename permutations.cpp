#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> permute(string v){
	vector<string>vv;
	int a[10]={1,2,6,24,120,720};
	for (int i=6;i<10;i++){
		a[i]=a[i-1]*(i+1);
	}
	vv.push_back(v);
	int n=v.size()-1;
	for (int i=1;i<a[n];i++){
		if (i%720*7*8*9==0){
			swap(v[n],v[n-9]);
			vv.push_back(v);
		}
		if (i%720*7*8==0){
			swap(v[n],v[n-8]);
			vv.push_back(v);
		}
		if (i%720*7==0){
			swap(v[n],v[n-7]);
			vv.push_back(v);
		}
		if (i%720==0){
			swap(v[n],v[n-6]);
			vv.push_back(v);
		}
		if (i%120==0){
			swap(v[n],v[n-5]);
			vv.push_back(v);
		}
		if (i%24==0){
			swap(v[n],v[n-4]);
			vv.push_back(v);
		}
		else if (i%6==0){
			swap(v[n],v[n-3]);
			vv.push_back(v);
		}
		else if (i%2==0){
			swap(v[n],v[n-2]);
			vv.push_back(v);
		}
		else{
			swap(v[n-1],v[n]);
			vv.push_back(v);
			if ((i+1)%5040*8*9==0)
				swap(v[n],v[n-7]);
			if ((i+1)%5040*8==0)
				swap(v[n],v[n-6]);
			if ((i+1)%5040==0)
				swap(v[n],v[n-5]);
			if ((i+1)%720==0)
				swap(v[n],v[n-4]);
			if ((i+1)%120==0)
				swap(v[n],v[n-3]);
			if ((i+1)%24==0)
				swap(v[n],v[n-2]);
			else if ((i+1)%6==0){
				swap(v[n],v[n-1]);
			}

		}
	}
	return vv;
}
int main(){
	long long sum=0;
	vector<string>vvv=permute("012345");
	sort(vvv.begin(),vvv.end());
	// for (vector<int >v:vvv){
		// if (v[0]!=0){
		// 	vector<int>vv={0,2,3,5,7,11,13,17};
		// 	for (int i=1;i<8;i++){
		// 		if ((v[i]*100+v[i+1]*10+v[i+2])%vv[i]==0)
		// 			sum+=v[0]*1000000000+v[1]*100000000+v[2]*10000000+v[3]*1000000+v[4]*100000+v[5]*10000+v[6]*1000+v[7]*100+v[8]*10+v[9];
		// 	}
		// }
		// for (int j:v)
		// 	cout<<j;
		// cout<<endl;
	
	cout<<vvv.size()<<endl;
}