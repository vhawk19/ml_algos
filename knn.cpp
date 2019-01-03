#include <bits/stdc++.h>
using namespace std;

struct Point{
	int val;
	double x,y;
	double distance;
}temp;

bool comparison(Point a,Point b){
	return(a.distance<b.distance);
}
int classifyPoint(vector<Point> a,int n,int k,Point p){
	for(auto& i:a){
		i.distance=sqrt((i.x-p.x)*(i.x-p.x)+(i.y-p.y)*(i.y-p.y));
	}
	sort(a.begin(),a.end(),comparison);
	int freq1=0;
	int freq2=0;
	for(int i=0;i<k;i++){
		if(a.at(i).val==0){
			freq1++;
		}
		else if(a.at(i).val==1){
			freq2++;
		}
	}

	if(freq1>freq2){
		return 0;
	}
	return 1;
}

int main(){
	int n,val,k=3;
	double x,y;
	vector<Point> dataset;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y>>val;
		temp.x=x;
		temp.y=y;
		temp.val=val;
		dataset.push_back(temp);
	}
	cin>>x>>y;
	temp.x=x;
	temp.y=y;
	cout<<classifyPoint(dataset,dataset.size(),k,temp);
}
