#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;

bool backtracking(int sudoku[][9], bool rows[][10], bool cols[][10], bool boxs[][10], int index, int n){
	int n2 = n*n;
	int rowNum = index / n2, colNum = index%n2;
	if (index == n2*n2) return true;

	if (sudoku[rowNum][colNum] != 0)
		return backtracking(sudoku, rows, cols, boxs, index + 1, n);

	for (int i = 1; i <= n2; i++){
		if (!rows[rowNum][i] && !cols[colNum][i] &&
			!boxs[rowNum / n*n + colNum / n][i]){
			rows[rowNum][i] = true;
			cols[colNum][i] = true;
			boxs[rowNum / n*n + colNum / n][i] = true;
			sudoku[rowNum][colNum] = i;
			if (backtracking(sudoku, rows, cols, boxs, index + 1, n)) return true;
			sudoku[rowNum][colNum] = 0;
			rows[rowNum][i] = false;
			cols[colNum][i] = false;
			boxs[rowNum / n*n + colNum / n][i] = false;
		}
	}
	return false;
}

int main(){
	int n;
	bool blankline = false;
	while (cin>>n){
		int sudoku[9][9] = { 0 };
		bool rows[9][10] = { 0 }, cols[9][10] = { 0 }, boxs[9][10] = { 0 };
		bool hasSolution = true;

		for (int i = 0; i < n*n; i++)
			for (int j = 0; j < n*n; j++){
				cin>>sudoku[i][j];
				if (sudoku[i][j]){
					if (rows[i][sudoku[i][j]] || cols[j][sudoku[i][j]] ||
						boxs[i / n*n + j / n][sudoku[i][j]]){
						hasSolution = false;
					}
					rows[i][sudoku[i][j]] = true;
					cols[j][sudoku[i][j]] = true;
					boxs[i / n*n + j / n][sudoku[i][j]] = true;
				}
			}

		if (blankline) printf("\n");
		blankline = true;

		if (n == 1){
			printf("1\n");
			continue;
		}

		if (!hasSolution){
			printf("NO SOLUTION\n");
		}
		else{
			if (backtracking(sudoku, rows, cols, boxs, 0, n)){
				for (int i = 0; i < n*n; i++){
					for (int j = 0; j < n*n; j++){
						if (j) printf(" ");
						printf("%d", sudoku[i][j]);
					}
					printf("\n");
				}
			}
			else{
				printf("NO SOLUTION\n");
			}
		}

	}
}
//參考 http://knightzone.org/?p=2017
