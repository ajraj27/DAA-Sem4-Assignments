#include<bits/stdc++.h>
using namespace std;

int arr[4][4] = {0};
int vis[4] = {0};
int final_path[5];
int final_weight = INT_MAX;

void add_edge(int u,int v,int x){
	arr[u][v] = x;
	arr[v][u] = x;
}

void copy(int n,int curr_path[]){
    for(int i = 0;i < n;i++)
        final_path[i] = curr_path[i];
    final_path[n] = curr_path[0];
}

int first_min(int j,int n){
	int min = INT_MAX;
	for(int i = 0;i < n;i++){
		if(arr[j][i] < min && i != j)
			min = arr[j][i];
	}
	return min;
}

int second_min(int i,int n){
	int first_min = INT_MAX;
	int second_min = INT_MAX;
	for(int j = 0;j < n;j++){
		if(arr[i][j] <= first_min){
			second_min = first_min;
			first_min = arr[i][j];
		}
		else if(arr[i][j] <= second_min && arr[i][j] != first_min)
			second_min = arr[i][j];
	}
	return second_min;
}

void TSP_traverse(int curr_path[],int curr_bound,int curr_weight,int level,int n){
	if(level == n){
		if(arr[curr_path[level-1]][curr_path[0]] != 0){
			int result = curr_weight + arr[curr_path[level-1]][0];
			if(result < final_weight){
			    final_weight = result;
			    copy(n,curr_path);
			}
		}
	} else {
		for(int i = 0;i < n;i++){
    		if(arr[curr_path[level-1]][i] != 0 && vis[i] == 0){
    		    int temp = curr_bound;
    			int weight = arr[curr_path[level-1]][i];
    			curr_weight += weight;
    			if(level == 1)
    				curr_bound = curr_bound - (first_min(curr_path[level-1],n) + first_min(i,n) / 2);
    			else
    				curr_bound = curr_bound - (second_min(curr_path[level-1],n) + first_min(i,n) / 2);
    			if(curr_bound + weight < final_weight){
    				curr_path[level] = i;
    				vis[i] = 1;
    				TSP_traverse(curr_path,curr_bound,curr_weight,level+1,n);
    			}
    			
    			curr_weight -= arr[curr_path[level-1]][i]; 
            	curr_bound = temp; 
  				
	            for(int i = 0;i < n;i++)
	            	vis[i] = 0;
        	    for (int j=0; j<=level-1; j++) 
            	    vis[curr_path[j]] = true; 
   			}
    	}
	}
}

void TSP(int n){
	int curr_bound = 0;
	int curr_weight = 0;
	int curr_path[n];
	for(int i = 0;i < n;i++){
		curr_bound += first_min(i,n) + second_min(i,n);
	}
	if(curr_bound % 2 == 0)
		curr_bound /= 2;
	else 
		curr_bound = curr_bound/2 + 1;
    curr_path[0] = 0;
    vis[0] = 1;
    TSP_traverse(curr_path,curr_bound,curr_weight,1,n);
}

int main(){
	int n,e,u,v,x;
	cout << "Enter no of vertices" << endl;
	cin >> n;
	cout << "Enter no of edges" << endl;
	cin >> e;
	cout << "Enter edges along with their weights" << endl;
	for(int i = 0;i < e;i++){
		cin >> u >> v >> x;
		add_edge(u,v,x);
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	TSP(n);
	cout << "Minimum cost: " << final_weight << endl; 
    cout << "Path Taken: " << endl; 
    for (int i=0; i<=n; i++) 
        printf("%d ", final_path[i]); 
  
    return 0; 
}