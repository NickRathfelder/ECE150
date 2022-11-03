#include "geesespotter_lib.h"

#include <iostream>

char *createBoard(std::size_t xdim, std::size_t ydim);

char *createBoard(std::size_t xdim, std::size_t ydim)
{
    char *board{new char[xdim*ydim]{}};

    for(std::size_t i{0}; i <= (xdim*ydim);++i)
    {
        board[i] = 0;
    }
    return board;
}

void cleanBoard(char *board);

void cleanBoard(char *board)
{
    delete board;
    board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim);

void printBoard(char *board, std::size_t xdim, std::size_t ydim)
{
    std::size_t sum{0};

    for(std::size_t i{0}; i <= ydim ; ++i)
    {
        for(std::size_t f{0}; f <= xdim; ++f)
        {
            if(board[sum] & hiddenBit())
            {
                std::cout << "*";
            }
            else if(board[sum] & markedBit())
            {
                std::cout << "M";
            }
            else
            {
                std::cout << (board[sum] & valueMask());
            }
            std::cout << " ";
            sum += 1;
        }
        std::cout << "\n";
    }
}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim);

void hideBoard(char *board, std::size_t xdim, std::size_t ydim)
{
    for(std::size_t i; i<= (xdim*ydim); ++i)
    {
        board[i] |= hiddenBit();
    }
}
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
    if(board[xloc*yloc] & hiddenBit())
    {
        board[xloc*yloc] ^= markedBit();
        return 0;
    }
    else
    {
        return 2;
    }
}