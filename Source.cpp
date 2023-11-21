#include <iostream>
#include <vector>

const int boardsize = 8;

enum class PieceType {
    EMPTY,
    WHITE,
    BLACK,
};

struct Position {
    int posX = 0;
    int posY = 0;
};



int posX = 0;
int posY = 0;

Position from = { posX,posY };
Position to = { posX, posY };




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

    void PrintBoard() {
        std::cout << "   0   1   2   3   4   5   6   7  \n";
        for (int i = 0; i < boardsize; ++i) {
            std::cout << i << ' ';

            for (int j = 0; j < boardsize; ++j) {
                switch (board[j][i]) {
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


    void StartBoard() {
        board.resize(boardsize, std::vector<PieceType>(boardsize, PieceType::EMPTY));

        //Placing pieces for a standard position
        for (int i = 0; i < 3; ++i) {
            for (int j = (i % 2 == 0) ? 1 : 0; j < boardsize; j += 2) {
                board[j][i] = PieceType::BLACK;
            }
        }

        for (int i = boardsize - 3; i < boardsize; ++i) {
            for (int j = (i % 2 == 0) ? 1 : 0; j < boardsize; j += 2) {
                board[j][i] = PieceType::WHITE;
            }
        }
    }


    bool isMoveOK(Position& from, Position& to, bool isYourTurn) {
        // TODO: Implement logic to check if the move is valid
        if (from.posX == 0)
        {
            //std::cout << "XOD GOVNO";
           // return false;
        }
        // This would involve checking if the move is within bounds, if there's a piece at the 'from' position,
        // if the 'to' position is empty, and if the move follows the rules of the game.
        return true; // Placeholder, replace with actual logic
    }

    void Move(Position& from, Position& to) {
        std::cout << "MOVE";
   
        board[to.posX][to.posY] = board[from.posX][from.posY];
        board[from.posX][from.posY] = PieceType::EMPTY;

    }


   


};

//
//
//void EnterMove() {
//
//    int posY = 0;
//    int posX = 0;
//
//    Position from = { posY,posX };
//    Position to = { posY, posX };
//
//    std::cin >> from.posY >> from.posX;
//    std::cout << "Please enter youre move to(Y, X) : " << '\n';
//    std::cin >> to.posY >> to.posX;
//
//
//    while (from.posX < 0 || from.posX > 7 || from.posY < 0 || from.posY > 7)
//    {
//        std::cout << "Incorrect input. Enter numbers between 0 and 7.\n" << "Move piece\n";//runs if input out of range
//        std::cin >> from.posY >> from.posX;
//        std::cout << "Please enter youre move to(Y, X) : " << '\n';
//        std::cin >> to.posY >> to.posX;
//    }
//
//}





int main() {
    Checkerboard checkerboard;
    checkerboard.PrintBoard();
    

    int turncheck = 0;

    while (GameIsRunning()) {

        if (turncheck % 2 == 0) {
            std::cout << "Black turn!\t Please enter youre move from (X,Y): " << '\n';
            turncheck++;
        }
        else {
            std::cout << "White turn!\t Please enter youre move from (X,Y): " << '\n';
            turncheck++;
        }


        //////////////////////////void EnterMove()\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  
            std::cin >> from.posX >> from.posY;
   

            while (from.posX < 0 || from.posX > 7 || from.posY < 0 || from.posY > 7) {

                std::cout << "Incorrect input. Enter numbers between 0 and 7.\n" << "Please enter youre move from(X,Y) : \n";
                std::cin >> from.posX >> from.posY;
            }

            std::cout << "Please enter youre move to(X,Y) : " << '\n';  
            std::cin >> to.posX >> to.posY;

            while (to.posX < 0 || to.posX > 7 || to.posY < 0 || to.posY > 7) {
                std::cout << "Incorrect input. Enter numbers between 0 and 7.\n" << "Please enter youre move to(X,Y) : \n";
                std::cin >> to.posY >> to.posX;
            }
         //////////////////////////void EnterMove()\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 


        bool isYourTurn = true;
        if (checkerboard.isMoveOK(from, to, isYourTurn)) {
            std::cout << "\n\n";
            std::cout << "The move is valid.\n";
            checkerboard.Move(from, to);

            std::cout << "\n\n";
            checkerboard.PrintBoard(); // Print the board after the move
        }
        else {
            std::cout << "The move is invalid.\n";
        }




    }






    return 0;
}