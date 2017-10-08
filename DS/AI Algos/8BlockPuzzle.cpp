/*
Bibliography:
https://www.cs.princeton.edu/courses/archive/spr10/cos226/assignments/8puzzle.html
https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html

Special thanks to:
https://n-puzzle-solver.appspot.com/
http://mypuzzle.org/sliding
-------------------------------------------------------------------------------

Author: George Mocanu, 2017
E-mail: razboi4@yahoo.com

Tested under gcc version 5.4.0
*/

#include <iostream>
#include <queue>

// change grid size here
#define BOARDSIZE 3

#define st first
#define nd second

const int vert[4] = {-1, 0, 1, 0};
const int oriz[4] = {0, 1, 0, -1};

class Board {
private:
	std::vector<int> steps; 
	int tiles[BOARDSIZE][BOARDSIZE];
	int row0, col0;

public:
	Board(): row0(0), col0(0){};
	Board operator=(const Board&);
	Board* moveTile(int);
	void getBoard();
	void printBoard();
	void printSolution(int);
	int hamming(int [][BOARDSIZE]);
	int manhattan(int [][BOARDSIZE]);
	int stepsNumber() const;
	int lastStep() const;
	int blankRow() const;
	int blankCol() const;
	bool equals(int [][BOARDSIZE]);

	friend int inversionCounter(const Board&);
};

struct cmp
{
    bool operator()(std::pair<int, Board> const& i, std::pair<int, Board> const& j) const
    {
        return i.st > j.st;
    }
};

int* findXPos(int goal[][BOARDSIZE], int x)
{
	int* pos = new int();

	for(int i = 0; i < BOARDSIZE; ++ i)
		for(int j = 0; j < BOARDSIZE; ++ j)
			if (goal[i][j] == x){
				*pos = i;
				*(pos + 1) = j;
				return pos;
			}
}

void goalBoard(int goal[][BOARDSIZE])
{
	for (int i = 0; i < BOARDSIZE; ++ i)
		for (int j = 0; j < BOARDSIZE; ++ j)
			goal[i][j] = (i * BOARDSIZE + j + 1) % (BOARDSIZE * BOARDSIZE);
}

Board Board::operator=(const Board& op)
{
	this->steps = op.steps;
	this->row0 = op.row0;
	this->col0 = op.col0;

	for (int i = 0; i < BOARDSIZE; ++ i)
		for (int j= 0 ; j < BOARDSIZE; ++ j)
			this->tiles[i][j] = op.tiles[i][j];

	return *this;
}

Board* Board::moveTile(int direction)
{
	Board* tmp = new Board();
	*tmp = *this;

	int a = tmp->row0 + vert[direction];
	int b = tmp->col0 + oriz[direction];

	tmp->tiles[tmp->row0][tmp->col0] = tmp->tiles[a][b];
	tmp->tiles[a][b] = 0;
	tmp->row0 = a;
	tmp->col0 = b;
	tmp->steps.push_back(direction);

	return tmp;
}

void Board::getBoard()
{
	for (int i = 0; i < BOARDSIZE; ++ i)
		for (int j = 0; j < BOARDSIZE; ++ j) {
			std::cin >> this->tiles[i][j];

			if (this->tiles[i][j] == 0) {
				this->col0 = j;
				this->row0 = i;
			}
		}
}

void Board::printBoard()
{
	for (int i = 0; i < BOARDSIZE; ++ i) {
		for (int j = 0; j < BOARDSIZE; ++ j)
			std::cout << tiles[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "\n";
}

void Board::printSolution(int step)
{
	if (step > 0) {
		Board *tmp = this->moveTile((this->steps[step - 1] + 2) % 4);
		tmp->printSolution(step - 1);
	}

	this->printBoard();

}

int Board::manhattan(int goal[][BOARDSIZE])
{
	int manDist = 0;

	for (int i = 0; i < BOARDSIZE; ++ i)
		for (int j = 0; j < BOARDSIZE; ++ j) {
			int* pos = findXPos(goal, this->tiles[i][j]);
			manDist += (i - *pos < 0 ? *pos - i : i - *pos) + (j - *(pos + 1) < 0 ? *(pos + 1) - j : j - *(pos + 1));
		}

	return manDist + this->steps.size() - 1;
}

int Board::stepsNumber() const
{
	return this->steps.size();
}

int Board::lastStep() const
{
	if (this->stepsNumber() > 0)
		return this->steps.back();

	return -4;
}

int Board::blankRow() const
{
	return this->row0;
}

int Board::blankCol() const
{
	return this->col0;
}

bool Board::equals(int goal[BOARDSIZE][BOARDSIZE])
{
	for (int i = 0; i < BOARDSIZE; ++ i)
		for (int j = 0; j < BOARDSIZE; ++ j)
			if (this->tiles[i][j] != goal[i][j])
				return false;

	return true;
}

int inversionCounter(const Board& op)
{
	int invCount = 0;

	for (int i = 0; i < BOARDSIZE * BOARDSIZE; ++ i) {
		if (*(*op.tiles + i) == 0)
			continue;

		for (int j = i + 1; j < BOARDSIZE * BOARDSIZE; ++ j)
			if (*(*op.tiles + j) && *(*op.tiles + i) > *(*op.tiles + j))
				++ invCount;
	}

	return invCount;
}

bool isSolvable(const Board& op)
{
	int invNum = inversionCounter(op);


	if (BOARDSIZE & 1 && !(invNum & 1))
		return true;
	if (!(BOARDSIZE & 1) && ((!(op.blankRow() & 1) && invNum & 1) || (op.blankRow() & 1 && !(invNum & 1))))
			return true;

	return false;
}

void solve(const Board& start, int goal[][BOARDSIZE])
{
	if (!isSolvable(start)) {
		std::cout << "\nThe board is not solvable!\n";
		return;
	}

	std::priority_queue<std::pair<int, Board>, std::vector<std::pair<int, Board> >, cmp> Q;
	Q.push(std::make_pair(0, start));

	while (!Q.empty()) {
		Board curr = Q.top().nd;
		Q.pop();

		if (curr.equals(goal)) {
			char ch;

			std::cout << "\nIt takes " << curr.stepsNumber() << " moves to reach the goal state.\n";
			std::cout << "\nPress y if you want to display the moves.\n";
			std::cin >> ch;

			if (ch == 'y')
				curr.printSolution(curr.stepsNumber());

			return;
		}

		for (int k = 0; k < 4; ++ k) {
			if ((curr.lastStep() + 2) % 4 == k)
				continue;

			int a = curr.blankRow() + vert[k];
			int b = curr.blankCol() + oriz[k];

			if (a < BOARDSIZE && a >= 0 && b < BOARDSIZE && b >= 0) {
				Board *tmp = curr.moveTile(k);

				Q.push(std::make_pair((*tmp).manhattan(goal), *tmp));
			}
		} 
	}
}

int main()
{
	Board start;
	int goal[BOARDSIZE][BOARDSIZE];

	std::cout << "Insert initial board:\n";
	start.getBoard();
	goalBoard(goal);
	solve(start, goal);

	return 0;
}