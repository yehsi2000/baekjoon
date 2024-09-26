#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int space[50][50];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    cin.ignore(); 
    for(int i=0; i<n; ++i){
        string line;
        getline(cin,line);
        for(int j=0; j<m; ++j){
            space[i][j] = line[j]-'0';
        }
    }

    long long maxmult=0;
    long long div1sum1, div1sum2, div1sum3;
    long long div2sum1, div2sum2, div2sum3;
    //row-column division
    for(int rowPivot = 1; rowPivot < n; ++rowPivot){
        for(int columnPivot = 1; columnPivot < m; ++columnPivot){
            div1sum1=div1sum2=div1sum3=0;
            div2sum1=div2sum2=div2sum3=0;
            //calc sum with selected pivot
            for(int upperRow = 0; upperRow < rowPivot; ++upperRow){
                for(int left = 0; left < columnPivot; ++left){
                    div1sum1 += space[upperRow][left];
                }
                for(int right = columnPivot; right < m; ++right){
                    div1sum2 += space[upperRow][right];
                }
            }
            for(int lowerRow = rowPivot; lowerRow < n; ++lowerRow){
                for(int left=0; left < columnPivot; ++left){
                    div2sum1 += space[lowerRow][left];
                }
                for(int right = columnPivot; right<m; ++right){
                    div2sum2 += space[lowerRow][right];
                }
            }

            //deal sum result
            div1sum3 = div2sum1 + div2sum2;
            div2sum3 = div1sum1 + div1sum2;
            maxmult = max(maxmult,max(div1sum1 * div1sum2 * div1sum3, div2sum1 * div2sum2 * div2sum3));
        }
    }
    //column-row division
    for(int columnPivot=1; columnPivot < m; ++columnPivot){    
        for(int rowPivot=1; rowPivot < n; ++rowPivot){
            div1sum1=div1sum2=div2sum3=0;
            div2sum1=div2sum2=div1sum3=0;
            //calc sum with selected pivot
            //div1=upper left&right div2=upperwhole
            for(int leftColumn=0; leftColumn<columnPivot; ++leftColumn){
                for(int up=0; up<rowPivot; ++up){
                    div1sum1+=space[up][leftColumn];
                }
                for(int down=rowPivot; down<n; ++down){
                    div1sum2+=space[down][leftColumn];
                }
            }
            //div1=lowerwhole, div2=lower left&right
            for(int rightColumn=columnPivot; rightColumn<m; ++rightColumn){
                for(int up=0; up<rowPivot; ++up){
                    div2sum1+=space[up][rightColumn];
                }
                for(int down=rowPivot; down<n; ++down){
                    div2sum2+=space[down][rightColumn];
                }
            }

            //deal sum result
            div1sum3 = div2sum1 + div2sum2;
            div2sum3 = div1sum1 + div1sum2;
            maxmult = max(maxmult,max(div1sum1 * div1sum2 * div1sum3, div2sum1 * div2sum2 * div2sum3));
        }
    }
    //double row division
    if(n>=3){
        for(int first = 1; first<n-1; ++first){
            for(int second = first+1; second<n; ++second){
                long long sum1=0, sum2=0, sum3=0;
                for(int i=0; i<first; ++i){
                    for(int j=0; j<m; ++j){
                        sum1 += space[i][j];
                    }
                }
                for(int i=first; i<second; ++i){
                    for(int j=0; j<m; ++j){
                        sum2 += space[i][j];
                    }
                }
                for(int i=second; i<n; ++i){
                    for(int j=0; j<m; ++j){
                        sum3 += space[i][j];
                    }
                }
                maxmult = max(maxmult,sum1*sum2*sum3);
            }
        }
    }

    //double column division
    if(m>=3){
        for(int first = 1; first<m-1; ++first){
            for(int second = first+1; second<m; ++second){
                long long sum1=0, sum2=0, sum3=0;
                for(int i=0;i<n; ++i){
                    for(int j=0;j<first;++j) {
                        sum1+=space[i][j];
                    }
                }
                for(int i=0;i<n; ++i){
                    for(int j=first;j<second;++j){
                        sum2+=space[i][j];
                    }
                }
                for(int i=0;i<n; ++i){
                    for(int j=second;j<m;++j){
                        sum3+=space[i][j];
                    }
                }
                maxmult = max(maxmult,sum1*sum2*sum3);
            }
        }
    }
    cout << maxmult;
}