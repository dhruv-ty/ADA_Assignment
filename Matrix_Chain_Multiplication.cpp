#include <iostream>
#include <climits>
using namespace std;
#define MAX 10

int look_up[MAX][MAX];
int mcm(int dims[], int i, int j) {
if (j <= i + 1) 
        return 0;
    int min = INT_MAX; 

    if (look_up[i][j] == 0){
       for (int k = i + 1; k <= j - 1; k++) {

            int cost = mcm(dims, i, k); 
            cost += mcm(dims, k, j); 

            cost += dims[i] * dims[k] * dims[j]; 
            if (cost < min) 
              min = cost;
        } 
        look_up[i][j] = min;
    } 
 return look_up[i][j];
}

int main(){

    cout<<"Enter the size of the Matrix order Array:\n";
    int n;
    cin>>n;
    cout<<"Enter the Input Array\n";
    int dims[n];
    for(int i=0;i<n;i++)
    cin>>dims[i];
    cout << "The minimum cost is " << mcm(dims, 0, n - 1);
return 0;
}
