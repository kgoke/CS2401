/**
 * @file othello.h
 * @author Keegan Goecke
 * @brief Class file for othello.h
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef OTHELLO_H
#define OTHELLO_H
#include "piece.h"
#include "game.h"
#include "colors.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <string>

namespace main_savitch_14{

    class Othello:public game{
        public:
            // constructor
            Othello();
            // stumps
            game* clone( )const;
            void compute_moves(std::queue<std::string>& moves)const;
            void display_status( )const;
            int evaluate()const;
            bool is_game_over()const;
            bool is_legal(const std::string& move)const;

            // must be overridden
            void make_move(const std::string& move);
            void restart();

            // other functions
            void printboard()const; // displays the board
            int get_passes(){return passes;}    // gets the number of passes
            void up(int a, int b);  // flips pieces in the upward direction
            void down(int a, int b);    // flips pieces in the downard direction
            void right(int a, int b);   // flips pieces to the right
            void left(int a, int b);    // flips pieces to the left
            void u_right(int a, int b); // flips pieces up and to the right
            void u_left(int a, int be); // flips pieces up and to the left
            void d_right(int a, int b); // flips pieces down and to the right
            void d_left(int a, int b);  // flips pieces down and to the left
            bool human_val() const; // checks if human has any valid moves
            game::who winning( ) const; // returns who is winning the game
            
        private:
            piece board[8][8];
            int w_score;
            int b_score;
            int passes;
            bool quit;
    };
}

#endif