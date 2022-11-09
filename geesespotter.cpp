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
    std::size_t xloc{0};
    std::size_t yloc{0};
    std::size_t sum{0};
    for(std::size_t i{0}; i< xdim*ydim; ++i)
    {
        std::cout << i << ": ";
        sum = 0;
        xloc = i % ydim;
        yloc = i / ydim;
        if((board[i] & valueMask()) == 9)
        {
            std::cout << sum << "\n";
            continue;
        }
        else
        {
            for (int x{-1}; x<2; ++x)
            {
                for(int y{-1}; y<2; ++y)
                {
                    if ((xloc+x >(xdim*ydim - 1)) || (xloc+x > xdim-1) || ((yloc +y) > (xdim*ydim - 1) || ((yloc + y) > ydim-1)))
                    {
                        continue;
                    }
                    else if((board[(xloc+x) + (xdim*(yloc+y))] & valueMask()) == 9)
                    {
                        sum+=1;
                    }
                }
            }
        }
        std::cout << sum << "\n";
        board[i] &= sum;
    }
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc);

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc)
{
    std::size_t position {xloc + (xdim*(yloc))};
    if(board[position] & markedBit())
    {
        return 0;
    }
    else if((board[position] & hiddenBit()) == false)
    {
        return 2;
    }
    else
    //reveal
    {
        board[position] &= ~hiddenBit();
        if((board[position] & valueMask()) == 9)
        {
            return 9;
        }
        else if((board[position] & valueMask()) == 0)
        {
            for (int x{-1}; x<2; ++x)
            {
                for(int y{-1}; y<2; ++y)
                {
                    if ((xloc+x >(xdim*ydim - 1)) || (xloc+x > xdim-1) || ((yloc +y) > (xdim*ydim - 1) || ((yloc + y) > ydim-1)))
                    {
                        continue;
                    }
                    else
                    {
                       board[(xloc+x) + (xdim*(yloc+y))] &= ~hiddenBit();
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