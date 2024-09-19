#include <iostream>
#include <cmath>
using namespace std;

double ax, ay, bx, by, cx, cy, dx, dy;

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0));
}

double calc(double ratio){
    return dist(ratio*(bx-ax)+ax,ratio*(by-ay)+ay,ratio*(dx-cx)+cx,ratio*(dy-cy)+cy);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double startx = 0; double endx = 1;
    while(endx-startx > 1e-9){
        double px = (2*startx+endx)/3.0;
        double qx = (startx+endx*2)/3.0;
        double pdist = calc(px);
        double qdist = calc(qx);
        if(pdist > qdist){
            // f(p)>f(q) lo=p
            startx = px;
        } else {
            // f(p)<-f(q) hi=q
            endx = qx;
        }
    }
    cout.precision(10);
    cout<<fixed<<calc(endx);
    return 0;
}