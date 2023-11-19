#include <iostream>
#include <vector>

const int boardsize = 8;

enum class PieceType {
    EMPTY,
    WHITE,
    BLACK,
};

struct Position {
    int posY = 0;
    int posX = 0;
};



bool GameIsRunning() {
    return true;
}







class Checkerboard
{
public:
    Checkerboard() {
        StartBoard();
    }
    std::vector<std::vector<PieceType>> board;





    void StartBoard() {
        board.resize(boardsize, std::vector<PieceType>(boardsize, PieceType::EMPTY));

        //Placing pieces for a standard position
        for (int i = 0; i < 3; ++i) {
            for (int j = (i % 2 == 0) ? 1 : 0; j < boardsize; j += 2) {
                board[i][j] = PieceType::BLACK;
            }
        }

        for (int i = boardsize - 3; i < boardsize; ++i) {
            for (int j = (i % 2 == 0) ? 1 : 0; j < boardsize; j += 2) {
                board[i][j] = PieceType::WHITE;
            }
        }
    }





 

    void PrintBoard() {
        std::cout << "   0   1   2   3   4   5   6   7  \n";
        for (int i = 0; i < boardsize; ++i) {
            std::cout << i << ' ';

            for (int j = 0; j < boardsize; ++j) {
                switch (board[i][j]) {
                case PieceType::EMPTY:
                    std::cout << "[ ] ";
                    break;
                case PieceType::WHITE:
                    std::cout << "[W] ";
                    break;
                case PieceType::BLACK:
                    std::cout << "[B] ";
                    break;
                default:
                    std::cout << "ERROR";
                    break;
                }

            }
            std::cout << '\n';
        }
    }





    //bool isMoveOK(Position& from, Position& to) {
    //   
    //    if (from.posX == 0)
    //    {
    //        std::cout << "XOD GOVNO";
    //    }
    //    
    //    return true;
    //}

    void Move(Position& from, Position& to) {
        std::cout << "\nMOVE\n";
   
        board[to.posY][to.posX] = board[from.posY][from.posX];
        board[from.posY][from.posX] = PieceType::EMPTY;

    }



};




int main() {
    Checkerboard checkerboard;

    // Example: Print the initial board
    checkerboard.PrintBoard();

    // Example: Check if a move is valid
    
    int posY = 0;
    int posX = 0;


    while (GameIsRunning()) {
        int turncheck = 1;

        Position from = {posY,posX};
        Position to = {posY, posX};


        if (turncheck % 2 == 0) {
            std::cout << "Black turn!\t Please enter youre move from (Y,X): " << '\n';
            turncheck++;
        }
        else {
            std::cout << "White turn!\t Please enter youre move from (Y,X): " << '\n';
            turncheck++;
        }

        std::cin >> from.posY >> from.posX;
        std::cout<<"Please enter youre move to(Y, X) : " << '\n';
        std::cin >> to.posY >> to.posX;



        bool isYourTurn = true;
        if (true /*checkerboard.isMoveOK(from, to) */) {

            std::cout << "\n\nThe move is valid.\n\n\n";
            checkerboard.Move(from, to);
            checkerboard.PrintBoard(); // Print the board after the move
        }
        else {
            std::cout << "The move is invalid.\n";
        }




    }






    return 0;
}