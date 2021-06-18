#include <raylib.h> // Raylib. // Tic-Tac-Toe game.
#include<iostream>
using namespace std;
class grid {
public:
	bool state;
	bool  cell[9]; 
	int slot[9];	//0=empty, 1=cross, 2=circle
};
class cross {
public:
	Vector2 lineX1;
	Vector2 lineY1;
	Vector2 lineX2;
	Vector2 lineY2;
	int		number;
	Color	color;
	bool	is;
};
class cr {
public:
	int centerX;
	int centerY;
	float radius;
	Color color;
	bool is;
	int number;
	//int player = 2;
};
int ln1StartPosX = 0;
int ln1StartPosY = 100;
int ln1EndPosX = 300;
int ln1EndPosY = 100;
// Grid horizontal line #2.
int ln2StartPosX = 0;
int ln2StartPosY = 200;
int ln2EndPosX = 300;
int ln2EndPosY = 200;

// Grid vertical line #1.
int ln3StartPosX = 100;
int ln3StartPosY = 0;
int ln3EndPosX = 100;
int ln3EndPosY = 300;
// Grid vertical line #2.
int ln4StartPosX = 200;
int ln4StartPosY = 0;
int ln4EndPosX = 200;
int ln4EndPosY = 300;
// Grid vertical line #3.
int ln6StartPosX = 300;
int ln6StartPosY = 0;
int ln6EndPosX = 300;
int ln6EndPosY = 300;


void DrawCross(Vector2 startPosX1, Vector2 endPosY1, Vector2 startPosX2, Vector2 endPosY2, Color color);
void DrawGrid(grid &, cross** , cr**);
//void UpdateBoard(grid&,int);


int main()
{
	grid Board;
	Board.state = false;
	for (int i = 0; i < 9; i++)
	{
		Board.cell[i] = false;   // Empty
		Board.slot[i] = 0;
	}
	cr** CirO = new cr* [3];
	for (int i = 0; i < 3; i++) {
		CirO[i] = new cr[3];
		for (int j = 0; j < 3; j++) {
			CirO[i][j].centerX = 50 * (j + j + 1);
			CirO[i][j].centerY = 50 * (i + i +1);
			CirO[i][j].radius = 20;
			CirO[i][j].color = BLANK;
			CirO[i][j].is = false;
		}
	}
	cross** CrX = new cross * [3];   //j = X, i =Y
	for (int i = 0; i < 3; i++) {
		CrX[i] = new cross[3];
		for (int j = 0; j < 3; j++) {
			CrX[i][j].lineX1 = { static_cast<float>(30 + 100 * j), static_cast<float>(30 + 100 * i) }; //{x,y} static_cast<float>(30 + 100*j)
			CrX[i][j].lineY1 = { static_cast<float>(60 + 100 * j), static_cast<float>(60 + 100 * i) };
			CrX[i][j].lineX2 = { static_cast<float>(30 + 100 * j), static_cast<float>(60 + 100 * i) };
			CrX[i][j].lineY2 = { static_cast<float>(60 + 100 * j), static_cast<float>(30 + 100 * i) };
			CrX[i][j].color = BLANK;
			CrX[i][j].is = false;
			CrX[i][j].number = 1;
		}
	}

	InitWindow(600, 300, "Tic++"); // Create window 300x300 with title "Tic++". {X,Y}
	SetTargetFPS(60); // Cap the FPS at 60.
	//int playerNumber = 1;
	//int cell = 0;
	while (!WindowShouldClose())
	{
		//Grid state = false 1 
		//Grid state = true  2 
		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell[0])) 
		{
			if ((IsMouseButtonPressed(0)) && (!CrX[0][0].is) && Board.state) {//CirO CrX
				CirO[0][0].color = RED;
				CirO[0][0].is = true;
				Board.state = false;
				Board.slot[0] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[0][0].is) && !Board.state) {
				CrX[0][0].color = RED;
				CrX[0][0].is = true;
				Board.state = true;
				Board.slot[0] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell[1])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[0][1].is) && Board.state) {//CirO CrX
				CirO[0][1].color = RED;
				CirO[0][1].is = true;
				Board.state = false;
				Board.slot[1] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[0][1].is) && !Board.state) {
				CrX[0][1].color = RED;
				CrX[0][1].is = true;
				Board.state = true;
				Board.slot[1] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell[2])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[0][2].is) && Board.state) {//CirO CrX
				CirO[0][2].color = RED;
				CirO[0][2].is = true;
				Board.state = false;
				Board.slot[2] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[0][2].is) && !Board.state) {
				CrX[0][2].color = RED;
				CrX[0][2].is = true;
				Board.state = true;
				Board.slot[2] = 1;
				//Board.cell1 = true;
			}
		}

		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell[3])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[1][0].is) && Board.state) {//CirO CrX
				CirO[1][0].color = RED;
				CirO[1][0].is = true;
				Board.state = false;
				Board.slot[3] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[1][0].is) && !Board.state) {
				CrX[1][0].color = RED;
				CrX[1][0].is = true;
				Board.state = true;
				Board.slot[3] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell[4])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[1][1].is) && Board.state) {//CirO CrX
				CirO[1][1].color = RED;
				CirO[1][1].is = true;
				Board.state = false;
				Board.slot[4] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[1][1].is) && !Board.state) {
				CrX[1][1].color = RED;
				CrX[1][1].is = true;
				Board.state = true;
				Board.slot[4] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell[5])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[1][2].is) && Board.state) {//CirO CrX
				CirO[1][2].color = RED;
				CirO[1][2].is = true;
				Board.state = false;
				Board.slot[5] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[1][2].is) && !Board.state) {
				CrX[1][2].color = RED;
				CrX[1][2].is = true;
				Board.state = true;
				Board.slot[5] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell[6])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[2][0].is) && Board.state) {//CirO CrX
				CirO[2][0].color = RED;
				CirO[2][0].is = true;
				Board.state = false;
				Board.slot[6] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[2][0].is) && !Board.state) {
				CrX[2][0].color = RED;
				CrX[2][0].is = true;
				Board.state = true;
				Board.slot[6] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell[7])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[2][1].is) && Board.state) {//CirO CrX
				CirO[2][1].color = RED;
				CirO[2][1].is = true;
				Board.state = false;
				//Board.cell1 = true;
				Board.slot[7] = 2;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[2][1].is) && !Board.state) {
				CrX[2][1].color = RED;
				CrX[2][1].is = true;
				Board.state = true;
				Board.slot[7] = 1;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell[8])) {
			if ((IsMouseButtonPressed(0)) && (!CrX[2][2].is) && Board.state) {//CirO CrX
				CirO[2][2].color = RED;
				CirO[2][2].is = true;
				Board.state = false;
				Board.slot[8] = 2;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!CirO[2][2].is) && !Board.state) {
				CrX[2][2].color = RED;
				CrX[2][2].is = true;
				Board.state = true;
				Board.slot[8] = 1;
				//Board.cell1 = true;
			}
		}

		cout << "State " << Board.state;
		DrawGrid(Board, CrX, CirO);

	}
		CloseWindow();
		for (int i = 0; i < 3; i++)
		{
			delete[] CirO[i];
		}

		delete[] CirO;
		for (int i = 0; i < 3; i++)
		{
			delete[] CrX[i];
		}

		delete[] CrX;

		return 0;
	}
void DrawCross(Vector2 startPosX1, Vector2 endPosY1, Vector2 startPosX2, Vector2 endPosY2, Color color) {
	//cross b;
	//b = *a;
	DrawLineV(startPosX1, endPosY1, color);
	DrawLineV(startPosX2, endPosY2, color);
}
void DrawGrid(grid& name, cross** CrX0, cr** CrO)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
DrawText("Press Space to restart", 400, 50, 14, RED);

DrawLine(ln1StartPosX, ln1StartPosY, ln1EndPosX, ln1EndPosY, BLACK); // Draw horizontal grid line #1.
DrawLine(ln2StartPosX, ln2StartPosY, ln2EndPosX, ln2EndPosY, BLACK); // Draw horizontal grid line #2.
DrawLine(ln3StartPosX, ln3StartPosY, ln3EndPosX, ln3EndPosY, BLACK); // Draw vertical grid line   #1.
DrawLine(ln4StartPosX, ln4StartPosY, ln4EndPosX, ln4EndPosY, BLACK); // Draw vertical grid line   #2.
DrawLine(ln6StartPosX, ln6StartPosY, ln6EndPosX, ln6EndPosY, BLACK); // Draw vertical grid line   #3.
for (int i = 0; i < 9; i++)
{
	if (i < 3)
	{
		switch (name.slot[i])
		{
		case 0:
			//nothing
			break;
		case 1:
			//drawCross(...);
			DrawCross(CrX0[0][i].lineX1, CrX0[0][i].lineY1, CrX0[0][i].lineX2, CrX0[0][i].lineY2, CrX0[0][i].color);
			break;
		case 2:
			//drawCircle(...)
			DrawCircle(CrO[0][i].centerX, CrO[0][i].centerY, CrO[0][i].radius, CrO[0][i].color);
			break;
		}
	}
	else if (i < 6 && i>2)
	{
		switch (name.slot[i])
		{
		case 0:
			//nothing
			break;
		case 1:
			//drawCross(...);
			DrawCross(CrX0[1][i-3].lineX1, CrX0[1][i-3].lineY1, CrX0[1][i-3].lineX2, CrX0[1][i-3].lineY2, CrX0[1][i-3].color);
			break;
		case 2:
			//drawCircle(...)
			DrawCircle(CrO[1][i-3].centerX, CrO[1][i-3].centerY, CrO[1][i-3].radius, CrO[1][i-3].color);
			break;
		}
	}
	else
	{
		switch (name.slot[i])
		{
		case 0:
			//nothing
			break;
		case 1:
			//drawCross(...);
			DrawCross(CrX0[2][i-6].lineX1, CrX0[2][i-6].lineY1, CrX0[2][i-6].lineX2, CrX0[2][i-6].lineY2, CrX0[2][i-6].color);
			break;
		case 2:
			//drawCircle(...)
			DrawCircle(CrO[2][i-6].centerX, CrO[2][i-6].centerY, CrO[2][i-6].radius, CrO[2][i-6].color);
			break;
		}
	}
}
EndDrawing();

}
//void UpdateBoard(bool* state, bool* position);
/*void UpdateBoard(grid & name, int cell)
{
	int i = 0;
	i = cell;
	name.cell[i] = true;
}*/
