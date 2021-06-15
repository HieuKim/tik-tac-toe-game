#include <raylib.h> // Raylib. // Tic-Tac-Toe game.
#include<iostream>
using namespace std;
class grid {
public:
	bool cell1;
	bool cell2;
	bool cell3;
	bool cell4;
	bool cell5;
	bool cell6;
	bool cell7;
	bool cell8;
	bool cell9;
	bool state;
};
class cross {
public:
	//int StartX;
	//int StartY;
	//int EndX;
	//int EndY;
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
	int player = 2;
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

//static int State = 0;
//static int player = 1;

void DrawCross(Vector2 startPosX1, Vector2 endPosY1, Vector2 startPosX2, Vector2 endPosY2, Color color);
void DrawGrid();
//void switchCurrentPlayer();

int main()
{
	grid Board;
	Board.cell1 = false;
	Board.cell2 = false;
	Board.cell3 = false;
	Board.cell4 = false;
	Board.cell5 = false;
	Board.cell6 = false;
	Board.cell7 = false;
	Board.cell8 = false;
	Board.cell9 = false;

	cr circle1;
	circle1.centerX = 50;
	circle1.centerY = 50;
	circle1.radius = 20;
	circle1.color = BLANK;
	circle1.is = false;

	cr circle2;
	circle2.centerX = 150;
	circle2.centerY = 50;
	circle2.radius = 20;
	circle2.color = BLANK;
	circle2.is = false;

	cr circle3;
	circle3.centerX = 250;
	circle3.centerY = 50;
	circle3.radius = 20;
	circle3.color = BLANK;
	circle3.is = false;

	cr circle4;
	circle4.centerX = 50;
	circle4.centerY = 150;
	circle4.radius = 20;
	circle4.color = BLANK;
	circle4.is = false;

	cr circle5;
	circle5.centerX = 150;
	circle5.centerY = 150;
	circle5.radius = 20;
	circle5.color = BLANK;
	circle5.is = false;

	cr circle6;
	circle6.centerX = 250;
	circle6.centerY = 150;
	circle6.radius = 20;
	circle6.color = BLANK;
	circle6.is = false;

	cr circle7;
	circle7.centerX = 50;
	circle7.centerY = 250;
	circle7.radius = 20;
	circle7.color = BLANK;
	circle7.is = false;

	cr circle8;
	circle8.centerX = 150;
	circle8.centerY = 250;
	circle8.radius = 20;
	circle8.color = BLANK;
	circle8.is = false;

	cr circle9;
	circle9.centerX = 250;
	circle9.centerY = 250;
	circle9.radius = 20;
	circle9.color = BLANK;
	circle9.is = false;
	// Create cross.
	cross Cross1;
	Cross1.lineX1 = { 30, 30 }; //{x,y}
	Cross1.lineY1 = { 60, 60 };
	Cross1.lineX2 = { 30, 60 };
	Cross1.lineY2 = { 60, 30 };
	Cross1.color = BLANK;
	Cross1.is = false;
	Cross1.number = 1;

	cross Cross2;
	Cross2.lineX1 = { 130, 30 }; //{x,y}
	Cross2.lineY1 = { 160, 60 };
	Cross2.lineX2 = { 130, 60 };
	Cross2.lineY2 = { 160, 30 };
	Cross2.color = BLANK;
	Cross2.is = false;
	Cross2.number = 2;

	cross Cross3;
	Cross3.lineX1 = { 230, 30 }; //{x,y}
	Cross3.lineY1 = { 260, 60 };
	Cross3.lineX2 = { 230, 60 };
	Cross3.lineY2 = { 260, 30 };
	Cross3.color = BLANK;
	Cross3.is = false;
	Cross3.number = 3;

	cross Cross4;
	Cross4.lineX1 = { 30, 130 }; //{x,y}
	Cross4.lineY1 = { 60, 160 };
	Cross4.lineX2 = { 30, 160 };
	Cross4.lineY2 = { 60, 130 };
	Cross4.color = BLANK;
	Cross4.is = false;
	Cross4.number = 4;

	cross Cross5;
	Cross5.lineX1 = { 130, 130 };
	Cross5.lineY1 = { 160, 160 };
	Cross5.lineX2 = { 130, 160 };
	Cross5.lineY2 = { 160, 130 };
	Cross5.color = BLANK;
	Cross5.is = false;
	Cross5.number = 5;

	cross Cross6;
	Cross6.lineX1 = { 230, 130 };
	Cross6.lineY1 = { 260, 160 };
	Cross6.lineX2 = { 230, 160 }; //{230,160}
	Cross6.lineY2 = { 260, 130 }; //{260,130}
	Cross6.color = BLANK;
	Cross6.is = false;
	Cross6.number = 6;

	cross Cross7;
	Cross7.lineX1 = { 30, 230 }; //{30,230}
	Cross7.lineY1 = { 60, 260 };
	Cross7.lineX2 = { 30, 260 };//{30,260}
	Cross7.lineY2 = { 60, 230 };
	Cross7.color = BLANK;
	Cross7.is = false;
	Cross7.number = 7;

	cross Cross8;
	Cross8.lineX1 = { 130, 230 };//{130,230}
	Cross8.lineY1 = { 160, 260 };
	Cross8.lineX2 = { 130, 260 };
	Cross8.lineY2 = { 160, 230 };
	Cross8.color = BLANK;
	Cross8.is = false;
	Cross8.number = 8;

	cross Cross9;
	Cross9.lineX1 = { 230, 230 };
	Cross9.lineY1 = { 260, 260 };
	Cross9.lineX2 = { 260, 230 };
	Cross9.lineY2 = { 230, 260 };
	Cross9.color = BLANK;
	Cross9.is = false;
	Cross9.number = 9;

	int playerNumber = 1;
	Board.state = false;
	InitWindow(600, 300, "Tic++"); // Create window 300x300 with title "Tic++". {X,Y}
	SetTargetFPS(60); // Cap the FPS at 60.
	//SetTargetFPS(1);
	// Grid horizontal line #1.
	while (!WindowShouldClose())
	{
		//Grid state = false 1 
		//Grid state = true  2 
		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell1)) {
			if ((IsMouseButtonPressed(0)) && (!Cross1.is) && Board.state) {
				circle1.color = RED;
				circle1.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle1.is) && !Board.state) {
				Cross1.color = RED;
				Cross1.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell2)) {
			if ((IsMouseButtonPressed(0)) && (!Cross2.is) && Board.state) {
				circle2.color = RED;
				circle2.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle2.is) && !Board.state) {
				Cross2.color = RED;
				Cross2.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 0) && (GetMouseY() < 100) && (!Board.cell3)) {
			if ((IsMouseButtonPressed(0)) && (!Cross3.is)&& Board.state) {
				circle3.color = RED;
				circle3.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle3.is) && !Board.state) {
				Cross3.color = RED;
				Cross3.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}

		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell4)) {
			if ((IsMouseButtonPressed(0)) && (!Cross4.is) && Board.state) {
				circle4.color = RED;
				circle4.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle4.is) && !Board.state) {
				Cross4.color = RED;
				Cross4.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell5)) {
			if ((IsMouseButtonPressed(0)) && (!Cross5.is) && Board.state) {
				circle5.color = RED;
				circle5.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle5.is) && !Board.state) {
				Cross5.color = RED;
				Cross5.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 100) && (GetMouseY() < 200) && (!Board.cell6)) {
			if ((IsMouseButtonPressed(0)) && (!Cross6.is) && Board.state) {
				circle6.color = RED;
				circle6.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle6.is) && !Board.state) {
				Cross6.color = RED;
				Cross6.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 0) && (GetMouseX() < 100) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell7)) {
			if ((IsMouseButtonPressed(0)) && (!Cross7.is) && Board.state) {
				circle7.color = RED;
				circle7.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle7.is) && !Board.state) {
				Cross7.color = RED;
				Cross7.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 100) && (GetMouseX() < 200) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell8)) {
			if ((IsMouseButtonPressed(0)) && (!Cross8.is) && Board.state) {
				circle8.color = RED;
				circle8.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle8.is) && !Board.state) {
				Cross8.color = RED;
				Cross8.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		if ((GetMouseX() > 200) && (GetMouseX() < 300) && (GetMouseY() > 200) && (GetMouseY() < 300) && (!Board.cell9)) {
			if ((IsMouseButtonPressed(0)) && (!Cross9.is) && Board.state) {
				circle9.color = RED;
				circle9.is = true;
				Board.state = false;
				//Board.cell1 = true;
			}
			if ((IsMouseButtonPressed(0)) && (!circle9.is) && !Board.state) {
				Cross9.color = RED;
				Cross9.is = true;
				Board.state = true;
				//Board.cell1 = true;
			}
		}
		// Game reset code.
		if (IsKeyPressed(KEY_SPACE)) {
			circle1.color = BLANK; circle1.is = false;
			Cross1.color = BLANK; Cross1.is = false;
			circle2.color = BLANK; circle2.is = false;
			Cross2.color = BLANK; Cross2.is = false;
			circle3.color = BLANK; circle3.is = false;
			Cross3.color = BLANK; Cross3.is = false;
			circle4.color = BLANK; circle4.is = false;
			Cross4.color = BLANK; Cross4.is = false;
			circle5.color = BLANK; circle5.is = false;
			Cross5.color = BLANK; Cross5.is = false;
			circle6.color = BLANK; circle6.is = false;
			Cross6.color = BLANK; Cross6.is = false;
			circle7.color = BLANK; circle7.is = false;
			Cross7.color = BLANK; Cross7.is = false;
			circle8.color = BLANK; circle8.is = false;
			Cross8.color = BLANK; Cross8.is = false;
			circle9.color = BLANK; circle9.is = false;
			Cross9.color = BLANK; Cross9.is = false;
			Board.cell1 = false;
			Board.cell2 = false;
			Board.cell3 = false;
			Board.cell4 = false;
			Board.cell5 = false;
			Board.cell6 = false;
			Board.cell6 = false;
			Board.cell8 = false;
			Board.cell9 = false;
			Board.state = false;
		}
		// Render.
		BeginDrawing();
		ClearBackground(RAYWHITE);
		// Draw grid.
		DrawLine(ln1StartPosX, ln1StartPosY, ln1EndPosX, ln1EndPosY, BLACK); // Draw horizontal grid line #1.
		DrawLine(ln2StartPosX, ln2StartPosY, ln2EndPosX, ln2EndPosY, BLACK); // Draw horizontal grid line #2.
		DrawLine(ln3StartPosX, ln3StartPosY, ln3EndPosX, ln3EndPosY, BLACK); // Draw vertical grid line #1.
		DrawLine(ln4StartPosX, ln4StartPosY, ln4EndPosX, ln4EndPosY, BLACK); // Draw vertical grid line #2.
		DrawLine(ln6StartPosX, ln6StartPosY, ln6EndPosX, ln6EndPosY, BLACK); // Draw vertical grid line #3.
		//Draw Instruction
		DrawText("Press Space to restart", 400, 50, 14, RED);
		//DrawText("Press Backspace to redo", 400, 250, 14, RED);
		// Draw circles.
		DrawCircle(circle1.centerX, circle1.centerY, circle1.radius, circle1.color);
		DrawCircle(circle2.centerX, circle2.centerY, circle2.radius, circle2.color);
		DrawCircle(circle3.centerX, circle3.centerY, circle3.radius, circle3.color);
		DrawCircle(circle4.centerX, circle4.centerY, circle4.radius, circle4.color);
		DrawCircle(circle5.centerX, circle5.centerY, circle5.radius, circle5.color);
		DrawCircle(circle6.centerX, circle6.centerY, circle6.radius, circle6.color);
		DrawCircle(circle7.centerX, circle7.centerY, circle7.radius, circle7.color);
		DrawCircle(circle8.centerX, circle8.centerY, circle8.radius, circle8.color);
		DrawCircle(circle9.centerX, circle9.centerY, circle9.radius, circle9.color);
	
		// Draw Crosses.
		//DrawLineV(Cross1.lineX1, , ln1EndPosX, ln1EndPosY, BLACK);
		DrawCross(Cross1.lineX1, Cross1.lineY1, Cross1.lineX2, Cross1.lineY2, Cross1.color);
		DrawCross(Cross2.lineX1, Cross2.lineY1, Cross2.lineX2, Cross2.lineY2, Cross2.color);
		DrawCross(Cross3.lineX1, Cross3.lineY1, Cross3.lineX2, Cross3.lineY2, Cross3.color);
		DrawCross(Cross4.lineX1, Cross4.lineY1, Cross4.lineX2, Cross4.lineY2, Cross4.color);
		DrawCross(Cross5.lineX1, Cross5.lineY1, Cross5.lineX2, Cross5.lineY2, Cross5.color);
		DrawCross(Cross6.lineX1, Cross6.lineY1, Cross6.lineX2, Cross6.lineY2, Cross6.color);
		DrawCross(Cross7.lineX1, Cross7.lineY1, Cross7.lineX2, Cross7.lineY2, Cross7.color);
		DrawCross(Cross8.lineX1, Cross8.lineY1, Cross8.lineX2, Cross8.lineY2, Cross8.color);
		DrawCross(Cross9.lineX1, Cross9.lineY1, Cross9.lineX2, Cross9.lineY2, Cross9.color);
		cout << "Player " << playerNumber;
		EndDrawing();

	}
		CloseWindow();
		//cout << "Player " << playerNumber;

		return 0;
	}
void DrawCross(Vector2 startPosX1, Vector2 endPosY1, Vector2 startPosX2, Vector2 endPosY2, Color color)
{
	//cross b;
	//b = *a;
	DrawLineV(startPosX1, endPosY1, color);
	DrawLineV(startPosX2, endPosY2, color);
}
void DrawGrid()
{
	DrawLine(ln1StartPosX, ln1StartPosY, ln1EndPosX, ln1EndPosY, BLACK); // Draw horizontal grid line #1.
	DrawLine(ln2StartPosX, ln2StartPosY, ln2EndPosX, ln2EndPosY, BLACK); // Draw horizontal grid line #2.
	DrawLine(ln3StartPosX, ln3StartPosY, ln3EndPosX, ln3EndPosY, BLACK); // Draw vertical grid line #1.
	DrawLine(ln4StartPosX, ln4StartPosY, ln4EndPosX, ln4EndPosY, BLACK); // Draw vertical grid line #2.
	DrawLine(ln6StartPosX, ln6StartPosY, ln6EndPosX, ln6EndPosY, BLACK); // Draw vertical grid line #3.
}
