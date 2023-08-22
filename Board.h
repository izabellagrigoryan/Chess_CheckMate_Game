#ifndef BOARD_H
#define BOARD_H

#include "Matrix.h"
class Pair
{
public:	
	int x, y;
	void setX(int x)
	{ 
		this->x = x;
	}

	int getX(){ return this->x; }
	void setY(int y){ this->y = y; }
	int getY(){ return this->y; }

	bool operator!=(Pair xy)
	{
		if (this->getX() == xy.x && this->getY() == xy.y)
			return false;
		return true;
	}
	
	bool operator==(Pair xy)
	{
		if (this->getX() == xy.x && this->getY() == xy.y)
			return true;
		return false;
	}

	void operator=(Pair xy)
	{
		this->x = xy.x;
		this->y = xy.y;
	}

	Pair() {}
	Pair(int x, int y) :x(x), y(y) {}
};

class Square
{
	char m_color;
	char m_name;
public:
	bool free = true;
	Pair xy;

	Square(){}
	Square(char color, char name, int x, int y)
	{
		this->xy.setX(x);
		this->xy.setY(y);
		this->m_color = color;
		this->m_name = name;
		this->free = true;
	}
};

class Board :public Matrix<Square>
{
public:
	Square** m_matrix;

	bool isOccupied(Pair xy)
	{
		int x = xy.getX();
		int y = xy.getY();
		return m_matrix[x][y].free;
	}

	bool isOccupied(int x, int y)
	{
		return m_matrix[x][y].free;
	}

	Pair getSquarePlace(int x, int y)
	{
		return m_matrix[x][y].xy;
	}

	Board() :Matrix(8, 8)
	{
		m_matrix = arr;
	}
	virtual ~Board() {}
};

class ChessBoard :public Board {
public:
	ChessBoard() :Board() {}

	ChessBoard(const ChessBoard& board)
	{
		size1 = board.size1;
		size2 = board.size2;
		arr = new Square* [size1];
		for (int i = 0; i < size1; i++)
			arr[i] = new Square[size2];

		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++)
			{
				arr[i][j].free = board.arr[i][j].free;
				arr[i][j].xy = board.arr[i][j].xy;
			}
	}

	ChessBoard& operator=(const ChessBoard& board)
	{
		if (this->m_matrix != board.m_matrix)
		{
			for (int i = 0; i < this->size1; i++)
			{
				delete[] arr[i];
				arr[i] = nullptr;
			}
			delete[] arr;
			arr = nullptr;

			this->size1 = board.size1;
			this->size2 = board.size2;

			this->arr = new Square* [size1];
			for (int i = 0; i < size1; i++)
				this->arr[i] = new Square[size2];

			for (int i = 0; i < size1; i++)
				for (int j = 0; j < size2; j++)
				{
					//this->arr[i][j] = board.arr[i][j];
					this->arr[i][j].free = board.arr[i][j].free;
					this->arr[i][j].xy = board.arr[i][j].xy;
				}
		}
		return *this;
	}

	virtual ~ChessBoard() {}
};

#endif