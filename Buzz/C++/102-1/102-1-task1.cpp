#include <iostream>
#include <string>

using namespace std;


struct BoardSquare
{
	enum E
	{
		X,O,Empty
	};
};

struct WinningPlayer
{
	enum E
	{
		X, O, Stalemate, None
	};
};

class Board
{
private:
	int _width;
	BoardSquare::E* _squares;

public:
	Board(int width) : _width(width)
	{
		_squares = new BoardSquare::E[width * width];
		for (auto i = 0; i < GetTotalSquares(); i++)
			_squares[i] = BoardSquare::Empty;
	}

	~Board()
	{
		delete[] _squares;
	}

	int GetWidth() { return _width; }
	int GetTotalSquares() { return _width * _width; }

	BoardSquare::E GetSquare(int index)
	{
		return _squares[index];
	}

	void SetSquare(int index, BoardSquare::E square)
	{
		_squares[index] = square;
	}
};

class IRuleEngine
{
public:
	virtual WinningPlayer::E GetWinningPlayer(Board& board, int& moves) = 0;
};

class Game
{
private:
	Board& _board;
	IRuleEngine& _ruleEngine;
	int _moves = 0;
public:
	Game(Board& board, IRuleEngine& ruleEngine) : _board(board), _ruleEngine(ruleEngine)
	{
	}

	WinningPlayer::E Run()
	{
		WinningPlayer::E winningPlayer, currentPlayer = WinningPlayer::X;

		while ((winningPlayer = _ruleEngine.GetWinningPlayer(_board, _moves)) == WinningPlayer::None)
		{
			Render();
			cout << "\n";

			int input;
			cout << "Move for " << (currentPlayer == WinningPlayer::X ? 'X' : 'O') << ": ";
			cin >> input;
			cin.ignore();

			input -= 1;
			if (input < 0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::Empty)
			{
				cout << "Invalid Move!\n";
				continue;
			}
			else
			{
				_moves++;
			}

			_board.SetSquare(input, currentPlayer == WinningPlayer::X ? BoardSquare::X : BoardSquare::O);
			currentPlayer = currentPlayer == WinningPlayer::X ? WinningPlayer::O : WinningPlayer::X;
		}
		return winningPlayer;
	}

private:
	void Render()
	{
		for (auto i = 1; i <= _board.GetTotalSquares(); i++)
		{
			cout << GetrSquareChar(i, _board.GetSquare(i - 1)) << " ";
			if ((i % _board.GetWidth()) == 0)
				cout << "\n";
		}
	}

	char GetrSquareChar(int index, BoardSquare::E square)
	{
		switch (square)
		{
		case BoardSquare::X: return 'X';
		case BoardSquare::O: return 'O';
		}

		return index + '0';
	}
};

class NullRuleEngine : public IRuleEngine
{
public:
	virtual WinningPlayer::E GetWinningPlayer(Board& board, int& moves)
	{
		int width = board.GetWidth();
		
		// horizontal
		int index = 0;
		int indexend = width - 2;
		for (int i = 0;i < width;i++) // 5 row steps
		{
			for (; index < indexend; index++)  // 3 steps
			{
				if (board.GetSquare(index) == BoardSquare::X && board.GetSquare(index + 1) == BoardSquare::X && board.GetSquare(index + 2) == BoardSquare::X)
					return WinningPlayer::X;

				if (board.GetSquare(index) == BoardSquare::O && board.GetSquare(index + 1) == BoardSquare::O && board.GetSquare(index + 2) == BoardSquare::O)
					return WinningPlayer::O;
			}
			index += 3;
			indexend += width; // same index end though next row
		}

		// vertical
		index = 0;
		indexend = width;
		for (int i = 0; i < width - 2; i++) // 3 row steps
		{
			for (; index < indexend; index++) // 5
			{
				if (board.GetSquare(index) == BoardSquare::X && board.GetSquare(index + width) == BoardSquare::X && board.GetSquare(index + width + width) == BoardSquare::X)
					return WinningPlayer::X;

				if (board.GetSquare(index) == BoardSquare::O && board.GetSquare(index +  width) == BoardSquare::O && board.GetSquare(index + width + width) == BoardSquare::O)
					return WinningPlayer::O;
			}
			index += width;
			indexend += width;
		}

		// back slash
		index = 0;
		indexend = width - 2;
		for (int i = 0; i < indexend; i++) // 3
		{
			for (; index < width - 2; index++) // 3
			{
				if (board.GetSquare(index) == BoardSquare::X && board.GetSquare(index + width + 1) == BoardSquare::X && board.GetSquare(index + width + width + 2) == BoardSquare::X)
					return WinningPlayer::X;

				if (board.GetSquare(index) == BoardSquare::O && board.GetSquare(index + width + 1) == BoardSquare::O && board.GetSquare(index + width + width + 2) == BoardSquare::O)
					return WinningPlayer::O;
			}
			index += 3;
			indexend += width;
		}

		// forward slash
		index = 2;
		indexend = width;
		for (int i = 0; i < width - 2; i++) // 3
		{
			for (; index < indexend; index++) // 3
			{
				if (board.GetSquare(index) == BoardSquare::X && board.GetSquare(index + width) == BoardSquare::X && board.GetSquare(index + width + width) == BoardSquare::X)
					return WinningPlayer::X;

				if (board.GetSquare(index) == BoardSquare::O && board.GetSquare(index + width) == BoardSquare::O && board.GetSquare(index + width + width) == BoardSquare::O)
					return WinningPlayer::O;
			}
			index += 3;
			indexend += width;
		}

		if (moves == board.GetTotalSquares())
			return WinningPlayer::Stalemate;
		else
			return WinningPlayer::None;
	}
};

void DisplayResult(WinningPlayer::E winningplayer)
{
	if (winningplayer == WinningPlayer::O)
	{
		cout << " Result: O is the Winner!\n";
	}
	else if (winningplayer == WinningPlayer::X)
	{
		cout << " Result: X is the Winner!\n";
	}
	else if (winningplayer == WinningPlayer::Stalemate)
	{
		cout << " Result: The game is a Stalemate!\n";
	}
	else
	{
		cout << " Result: NONE (something is not right)\n";
	}
}

int main()
{
	Board board(3);
	NullRuleEngine ruleEngine;
	Game game(board, ruleEngine);
	
	DisplayResult(game.Run());

	cout << " Press enter to exit...";
	cin.get();
	return 0;
}
