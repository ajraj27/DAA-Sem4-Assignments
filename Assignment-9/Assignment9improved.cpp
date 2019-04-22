#include <iostream> 
#include <vector> 
#include <thread> 
#include <math.h>
#define sizeLimit 20
  
using namespace std; 

int size;
int mat[sizeLimit][sizeLimit];
int cofactor[sizeLimit];
int determinant(int mat2[sizeLimit][sizeLimit], int s)     
{
    int det = 0;
    if (s == 2) {   
        return mat2[0][0] * mat2[1][1] - mat2[0][1] * mat2[1][0]; 
    } 
    else {   
        int mat3[sizeLimit][sizeLimit]; 
        for(int x = 0; x < s; x++) {
           int subi = 0;
           for (int i = 1; i < s; i++) { 
               int subj = 0; 
               for (int j = 0; j < s; j++) { 
                   if (j != x) { 
                       mat3[subi][subj] = mat2[i][j]; 
                       subj++; 
                   }   
               }
               subi++;
           }
           det = det + pow(-1,x) * mat2[0][x] * determinant(mat3,s-1);
        }
        return det;
    }
}  
  
void createThread(int x, int s) {
    int mat2[sizeLimit][sizeLimit];
    int subi = 0;
    for (int i = 1; i < s; i++) { 
       int subj = 0; 
       for (int j = 0; j < s; j++) { 
           if (j != x) { 
               mat2[subi][subj] = mat[i][j]; 
               subj++; 
           }   
       }
       subi++;
    }
    cofactor[x] = pow(-1,x) * mat[0][x] * determinant(mat2,s-1);
}

int main() 
{ 
    int i, j, finalDet = 0; 
    cin >> size;
    vector < thread > th;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> mat[i][j];
        }
    }

    for(int x = 0; x < size; x++){
        th.push_back(thread(createThread,x,size));
    }

    for(int i = 0; i < size; i++) 
    th[i].join();
      
    for(int i = 0; i < size; i++)
    finalDet += cofactor[i];

    cout << finalDet << endl; 
      
    return 0; 
} 
