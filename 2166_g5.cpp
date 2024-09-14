#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<double,double>> points;
    for(int i=0; i<n; ++i){
        double x,y;
        scanf("%lf %lf", &x, &y);
        points.push_back({x,y});
    }
    points.push_back(points[0]);
    double size = 0;
    for(int i=0; i<points.size()-1; ++i){
        double x1 = points[i].first;
        double y1 = points[i].second;
        double x2 = points[i+1].first;
        double y2 = points[i+1].second;
        size += x1*y2-x2*y1;
    }
    printf("%.1lf\n",abs(size)/2.f);
}