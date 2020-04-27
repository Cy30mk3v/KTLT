#define N 5
int solveKnightUntil(int x, int y, int movei, int board[N][N],
	int xMove[], int yMove[]);
bool checkSafe(int x, int y, int board[N][N]);
void printSolution(int board[N][N]);
bool solveKT();
int solveKnightUntil(int x, int y, int movei, int board[N][N],
	int xMove[N], int yMove[N]);
