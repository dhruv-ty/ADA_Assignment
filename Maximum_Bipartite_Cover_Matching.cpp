#include <iostream>

#define M 6
#define N 6
using namespace std;
bool bipartiteGraph[M][N];  
bool bipartiteMatch(int u, bool visited[], int assign[]) {
   for (int v = 0; v < N; v++) {  
      if (bipartiteGraph[u][v] && !visited[v]) {   
         visited[v] = true;   
         if (assign[v] < 0 || bipartiteMatch(assign[v], visited, assign)) {
            assign[v] = u;    
            return true;
         }
      }
   }
   return false;
}
int maxMatch() {
    int assign[N];  
   for(int i = 0; i<N; i++)
      assign[i] = -1; 
   int jobCount = 0;
for (int u = 0; u < M; u++) {    
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;    
      if (bipartiteMatch(u, visited, assign))   
         jobCount++;
   }
   return jobCount;
}
int main() {
   cout<<"******Maximum Bipartite Matching ********\n\n";
   cout<<"Enter the Adjacency Matrix:\n";
   for(int i=0;i<M;i++)
   for(int j=0;j<N;j++)
   cin>>bipartiteGraph[i][j];
   cout << "\nMaximum number of applicants matching for job: " << maxMatch();
}
