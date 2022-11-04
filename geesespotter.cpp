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
    delete[] board;
    board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim);

void printBoard(char *board, std::size_t xdim, std::size_t ydim)
{
    std::size_t sum{0};

    for(std::size_t i{0}; i < ydim ; ++i)
    {
        for(std::size_t f{0}; f < xdim; ++f)
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
            sum += 1;
        }
    }
}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim);

void hideBoard(char *board, std::size_t xdim, std::size_t ydim)
{
    for(std::size_t i{0}; i<= (xdim*ydim); ++i)
    {
        board[i] |= hiddenBit();
    }
}
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
    std::size_t position {xloc-1 + (xdim*(yloc-1))};
    if (board[position] & hiddenBit())
    {
        //if hidden
        board[position] ^= markedBit();
        std::cout << board[position];
        return 0;
    }
    else
    {
        return 2;
    }
}
void computeNeighbors(char *board,std::size_t xdim,std::size_t ydim);

void computeNeighbors(char *board,std::size_t xdim,std::size_t ydim)
{

}


int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc);
int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc)
{
    return 0;
}

bool isGameWon(char *board,std::size_t xdim,std::size_t ydim);
bool isGameWon(char *board,std::size_t xdim,std::size_t ydim)
{
    return true;
}