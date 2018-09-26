
#include "board.hpp"

// void Board::print();

// class Board;

// default constructor
Board::Board(int r, int c){
   rows = r + 2;
   columns = c + 2;

   // initialize the board's available spaces
   board = new std::string*[rows];
   for(int a=0; a<rows; a++){
      board[a] = new std::string[columns];
      for(int b=1; b<columns; b++){
         board[a][b] = " ";
      }
   }

   // initialize the border's perimeter

   // top & bottom borders
   for(int a=0; a<columns; a++){
      board[0][a] = "-";
      board[(rows-1)][a] = "-";
   }
   // left & right borders
   for(int b=0; b<columns; b++){
      board[b][0] = "|";
      board[b][(columns-1)] = "|";
   }
}

void Board::print(){
   for(int r=0; r<rows; r++){
      for(int c=0; c<columns; c++){
         // std::cout << "board[" << r << "][" << c << "] = " << board[r][c] << std::endl;
         std::cout << board[r][c];
      }
      std::cout << std::endl;
   }
}

void Board::freeMemory(){
   for(int r=0; r<rows; r++){
      delete[] board[r];
   }
   delete[] board;
}

void Board::updateBoard(int x, int y){
   board[y][x] = "*";
}