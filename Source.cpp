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

            //////////////////////////////////TurnInfo\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

            if (i == 3)
            {
                std::cout << "                    Turn #" << turnnumber;
                turnnumber++;
            }

            if (i == 4 && turncheck % 2 == 0)
            {
                std::cout << "                  Black turn!";
                turncheck++;
            } else if (i == 4 && turncheck % 2 == 1) {

                std::cout << "                  White turn!";
                turncheck++;
            }

            //////////////////////////////////TurnInfo\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

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


    bool isMoveOK(Position& from, Position& to) {
       
        if (to.posX < 0 || to.posX > 7 || to.posY < 0 || to.posY > 7)
        {


            std::cout << "XOD GOVNO";
            return false;
        }

        if (board[from.posX][from.posY] == PieceType::EMPTY) 
        {
            std::cout << "XOD GOVNO";
            return false;
        }
        

        return true;
    }

    void Move(Position& from, Position& to) {
        std::cout <<'\n';//"MOVE\n";




        std::cout << "\nPlease enter youre move from(X,Y): " << '\n';
        std::cin >> from.posX >> from.posY;


        while (from.posX < 0 || from.posX > 7 || from.posY < 0 || from.posY > 7) {

            std::cout << "Incorrect input. Enter numbers between 0 and 7.\n" << "Please enter youre move from(X,Y): \n";
            std::cin >> from.posX >> from.posY;
        }

        std::cout << "Please enter youre move to(X,Y): " << '\n';
        std::cin >> to.posX >> to.posY;

        while (to.posX < 0 || to.posX > 7 || to.posY < 0 || to.posY > 7) {
            std::cout << "Incorrect input. Enter numbers between 0 and 7.\n" << "Please enter youre move to(X,Y): \n";
            std::cin >> to.posY >> to.posX;
        }

        if (!(board[to.posX][to.posY] == PieceType::EMPTY))
        {

        }

            board[to.posX][to.posY] = board[from.posX][from.posY];
            board[from.posX][from.posY] = PieceType::EMPTY;







        if (board[to.posX][to.posY] == PieceType::WHITE)
        {

            
            board[to.posX-1][to.posY-1] = PieceType::BLACK;
            board[to.posX][to.posY] = PieceType::EMPTY;
            //or

            //board[to.posX][to.posY] = board[from.posX][from.posY];
            //board[from.posX][from.posY] = PieceType::EMPTY;
            //board[to.posX][to.posY] = PieceType::EMPTY;
            //board[to.posX - 1][to.posY - 1] = PieceType::BLACK;
        }
            
        //if (board[to.posX][to.posY] == PieceType::BLACK)
        //{
        //    board[to.posX][to.posY] = board[from.posX][from.posY];
        //    board[from.posX][from.posY] = PieceType::EMPTY;
        //    board[to.posX][to.posY] = PieceType::EMPTY;
        //    board[to.posX + 1][to.posY + 1] = PieceType::WHITE;

        //    //or
        //    
        //    //board[to.posX][to.posY] = board[from.posX][from.posY];
        //    //board[from.posX][from.posY] = PieceType::EMPTY;
        //    //board[to.posX][to.posY] = PieceType::EMPTY;
        //    //board[to.posX - 1][to.posY - 1] = PieceType::WHITE;
        //    
        //}





    }


   
private:
    int turnnumber = 1;
    int turncheck = 0;

    std::vector<std::vector<PieceType>> board;

};





int main() {
    Checkerboard checkerboard;
    checkerboard.PrintBoard();
    

    while (GameIsRunning()) 
    {

      checkerboard.Move(from, to);
      checkerboard.PrintBoard();

 
    }






    return 0;
}