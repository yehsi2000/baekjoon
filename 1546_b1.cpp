#include <cstdio>
double scores[1000];
int main(){
    int n;
    scanf("%d", &n);
    double max =0;
    for(int i=0; i<n; ++i){
        scanf("%lf", scores+i);
        if(scores[i]>max) max = scores[i];
    }
    double sum=0;
    for(int i=0; i<n; ++i){
        scores[i] = scores[i]/max*100.f;
        sum += scores[i];
    }
    printf("%lf", sum/static_cast<double>(n));    
}