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
    for(std::size_t f{0}; f < xdim*ydim; ++f)
    {
        if((f % xdim == 0) && (f!=0))
        {
            std::cout << "\n";
        }
        if(board[sum] & markedBit())
        {
            std::cout << "M";
        }
        else if(board[sum] & hiddenBit())
        {
            std::cout << "*";
        }
        else
        {
            std::cout << (board[sum] & valueMask());
        }
        sum += 1;
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
    std::size_t position {xloc + (xdim*(yloc))};
    if(board[position] & hiddenBit())
    {
        board[position] ^= markedBit();
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
    std::size_t position {xloc + (xdim*(yloc))};
    if(board[position] & markedBit())
    {
        std::cout <<"Zero";
        return 0;
    }
    else if((board[position] & hiddenBit()) == false)
    {
        std::cout << "Two";
        return 2;
    }
    else
    //reveal
    {
        board[position] &= ~hiddenBit();
        int x{xloc};
        int y{yloc};
        if((board[position] & valueMask()) == 9)
        {
            std::cout << "Nine";
            return 9;
        }
        else if((board[position] & valueMask()) == 0)
        {
            for (int xAdd{-1}; xAdd<2; ++xAdd)
            {
                for(int yAdd{-1}; yAdd<2; ++yAdd)
                {
                    if ((x+xAdd < 0) || (x+xAdd > xdim-1) || (y+yAdd <0) || (y+yAdd > ydim-1))
                    {
                        continue;
                    }
                    else
                    {
                       board[(xloc+xAdd) + (xdim*(yloc+yAdd))] &= ~hiddenBit();
                    }
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
        
    }
}

bool isGameWon(char *board,std::size_t xdim,std::size_t ydim);
bool isGameWon(char *board,std::size_t xdim,std::size_t ydim)
{
    for (std::size_t i{0}; i < (xdim*ydim); ++i)
    {
        if(((board[i] & hiddenBit()) == false) || ((board[i] & valueMask()) == 9))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}