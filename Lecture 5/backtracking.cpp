#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(int board[4][4],int row,int col,int n){

	for(int i=row;i>=0;i--){
		if(board[i][col]){
			return false;
		}
	}

	int x = row;
	int y = col;

	while(x>=0 and y>=0){
		if(board[x][y]){
			return false;
		}

		x--;
		y--;
	}

	x = row;
	y = col;

	while(x>=0 and y<n){
		if(board[x][y]){
			return false;
		}

		x--;
		y++;
	}

	return true;
}

bool NQueens(int board[4][4],int row,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<"Q ";
				}else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}

		return true;
	}

	for(int col=0;col<n;col++){
		if(isSafe(board,row,col,n)){

			board[row][col] =1;

			bool restOfTheQueen = NQueens(board,row+1,n);

			if(restOfTheQueen){
				return true;
			}

			board[row][col] = 0;
		}
	}

	return false;
}

int countNQueens(int board[4][4],int row,int n){
	if(row==n){

		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		if(board[i][j]){
		// 			cout<<"Q ";
		// 		}else{
		// 			cout<<"_ ";
		// 		}
		// 	}
		// 	cout<<endl;
		// }

		return 1;
	}

	int count=0;

	for(int col=0;col<n;col++){
		if(isSafe(board,row,col,n)){

			board[row][col] =1;

			count+=countNQueens(board,row+1,n);

			board[row][col] = 0;
		}
	}

	return count;
}

void printNQueens(int board[4][4],int row,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]){
					cout<<"Q ";
				}else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		cout<<"*************************"<<endl;

		return;
	}

	for(int col=0;col<n;col++){
		if(isSafe(board,row,col,n)){

			board[row][col] =1;

			printNQueens(board,row+1,n);

			board[row][col] = 0;
		}
	}

}

bool ratInaMaze(char maze[4][4],int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return true;
	}

	if(sr>er or sc>ec){
		return false;
	}

	if(maze[sr][sc]=='X'){
		return false;
	}

	bool horizontal = ratInaMaze(maze,sr+1,sc,er,ec);
	bool vertical = ratInaMaze(maze,sr,sc+1,er,ec);

	if(horizontal or vertical){
		return true;
	}

	return false;
}

void printRatInaMaze(char maze[4][4],int sol[4][4],int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		sol[sr][sc] = 1;
		for(int i=0;i<=er;i++){
			for(int j=0;j<=ec;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"**********************"<<endl;

		return;
	}

	if(sr>er or sc>ec){
		return;
	}

	if(maze[sr][sc]=='X'){
		return;
	}

	sol[sr][sc]= 1;

	printRatInaMaze(maze,sol,sr+1,sc,er,ec);
	printRatInaMaze(maze,sol,sr,sc+1,er,ec);

	sol[sr][sc] = 0;
}

bool isPossible(int mat[9][9],int row,int col,int n,int num){

	for(int i=0;i<n;i++){
		if(mat[row][i]==num or mat[i][col]==num){
			return false;
		}
	}

	int starting_x = (row/3)*3;
	int starting_y = (col/3)*3;

	for(int i = starting_x;i<starting_x+3;i++){
		for(int j=starting_y;j<starting_y+3;j++){
			if(mat[i][j]==num){
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(int mat[9][9],int row,int col,int n){
	if(row==n){

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

	if(col==n){
		return sudokuSolver(mat,row+1,0,n);
	}

	if(mat[row][col]!=0){
		return sudokuSolver(mat,row,col+1,n);
	}

	for(int num=1;num<=9;num++){
		if(isPossible(mat,row,col,n,num)){

			mat[row][col] = num;

			bool restOfTheSudoku = sudokuSolver(mat,row,col+1,n);

			if(restOfTheSudoku){
				return true;
			}
		}
	}

	mat[row][col] = 0;
	return false;
}

int helper(vector<int> &nums,int si){
    if(si>=nums.size()){
        return 0;
    }
        
    int include = helper(nums,si+2) + nums[si];
    int skip = helper(nums,si+1);
        
    return max(include,skip);
}

int rob(vector<int>& nums) {
        return helper(nums,0);
}

int main(){
	// int n = 4;
	// int board[4][4] = {0};

	// cout<<NQueens(board,0,n)<<endl;

	// cout<<countNQueens(board,0,n)<<endl;

	// printNQueens(board,0,n);

	// char maze[][4] = {
	// 	{'0','0','0','0'},
	// 	{'0','0','0','X'},
	// 	{'0','0','0','0'},
	// 	{'0','X','0','0'},
	// };

	// int sol[4][4] = {0};

	// cout<<ratInaMaze(maze,0,0,3,3)<<endl;
	// printRatInaMaze(maze,sol,0,0,3,3);

	int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };

    int n = 9;
    cout<<sudokuSolver(mat,0,0,n)<<endl;

	return 0;
}