#include<iostream>
#include<math.h>

#define GRID_SIZE 1001

using namespace std;

typedef struct{
	int x, y;
}Pair;

const int directions = 4;
int dir = 0;
Pair max_step_int = { 1,2 };
Pair step_int; //{step, interval counter}
Pair dirs[] = {/*used in step*/ {1,0}, {0,1},{-1,0},{0,-1} /*used in sum*/, {1,1},{-1,-1},{1,-1},{-1,1}};
Pair coord;
int dataSquare = 361527;
int partTwo = 0;
Pair coord2 = { GRID_SIZE / 2 , GRID_SIZE / 2 };
int grid[GRID_SIZE][GRID_SIZE];

int main() {
	grid[coord2.y][coord2.x] = 1;

	for (int i = 2; i <= dataSquare; i++) {
		//PART ONE
		coord = { coord.x + dirs[dir].x , coord.y + dirs[dir].y }; //zrobiono krok
		if (++step_int.x == max_step_int.x) {
			dir = (dir + 1) % directions; //obrót
			if (++step_int.y == max_step_int.y) {
				max_step_int.x++; //nastêpna iloœæ kroków bêdzie o 1 wiêksza
				step_int.y = 0;
			}
			step_int.x = 0;
		}

		coord2 = { GRID_SIZE / 2 + coord.x, GRID_SIZE / 2 + coord.y };
		//PART TWO
		grid[coord2.y][coord2.x] = []()->int{
			int s = 0;
			for (int i = 0; i < 8; i++) s += grid[coord2.y + dirs[i].y][coord2.x + dirs[i].x];
			return s;
		}();

		if (grid[coord2.y][coord2.x] > dataSquare && !partTwo) partTwo = grid[coord2.y][coord2.x];
	}

	cout << abs(coord.x) + abs(coord.y) << endl;
	cout << partTwo << endl;
	system("pause");
	return 0;
}