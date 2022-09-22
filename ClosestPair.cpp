#include <bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

double find_distance(pair<double, double> p1, pair<double, double> p2, pair<double, double> &min1, pair<double, double> &min2)
{
    //if new pair has shorter distance compared to the old pair of points, then update the closest pairs
    if (sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)) < sqrt((min1.first - min2.first) * (min1.first - min2.first) + (min1.second - min2.second) * (min1.second - min2.second)))
    {
        min1 = p1;
        min2 = p2;
    }
    //returns the distance computed between the two points
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double find_closest_distance(vector<pair<double,double>> sorted_x,vector<pair<double,double>> sorted_y,pair<double,double> &min1,pair<double,double> &min2){
	int s=sorted_x.size();
	if(s<=1){
		return DBL_MAX;
	}
	pair<double,double> p1,p2,p3,p4={DBL_MAX,DBL_MAX};
	vector<pair<double,double>> left_x;
	vector<pair<double, double>> right_x;
	for (int i = 0; i < s; i++)
	{
		if(i< s/2){
			left_x.push_back(sorted_x[i]);
		}
		else {
			right_x.push_back(sorted_y[i]);
		}
	}

	int mid=left_x.back().first;
	
	vector<pair<double,double>> left_y,right_y;
	for(auto x: sorted_y){
		if(x.first<=mid){
		 left_y.push_back(x);
		}
		else{  
			right_y.push_back(x);
		}
	}
	double d1=find_closest_distance(left_x,left_y,p1,p2);
	double d2=find_closest_distance(right_x,right_y,p3,p4);

	if(d1<d2){
		min1=p1;
		min2=p2;
	}
	else {
		min1=p3;
		min2=p4;
	}

	double d=min(d1,d2);
	vector<pair<double,double>> band;

	for(auto x:sorted_y){
		if(x.first>mid-d) 
			band.push_back(x);
	}

	 for (int i = 0; i < band.size(); i++) 
    {
        for (int j = i + 1; j < band.size() && band[j].second < band[i].second + d; j++)
        {
            if (find_distance(band[i], band[j], p1, p2) < d)
            {
                min1 = band[i];
                min2 = band[j];
                d = find_distance(band[i], band[j], p1, p2);
            }
        }
    }
	return d;
}

int main(){
	vector<pair<double,double>> points={
		{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}
	};
	sort(points.begin(),points.end());
	vector<pair<double,double>> sorted_x=points;

	sort(points.begin(),points.end(),sortbysec);
	vector<pair<double,double>> sorted_y=points;

	pair<double,double>min1={DBL_MAX,DBL_MAX};
	pair<double,double>min2={DBL_MAX,DBL_MAX};

	double x=find_closest_distance(sorted_x,sorted_y,min1,min2);

	cout << "The closest pair of points are (" << min1.first << "," << min1.second << ") "
         << "and "
         << "(" << min2.first << "," << min2.second << ") " << endl;
    cout << "The distance between them is " << x << " units" << endl;

	return 0;

}