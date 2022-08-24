/**
 * @file othello.cc
 * @author Keegan Goecke
 * @brief Implementation file for othello.h
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "othello.h"
#include "game.h"
#include "colors.h"
#include "piece.h"
#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;
namespace main_savitch_14{
    
    Othello::Othello(){
        // sets all board peices to empty
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board[i][j].set_e();
            }
        }
        // sets private varibale to defaults
        w_score = 0;
        b_score = 0;
        passes = 0;
        quit = false;
    }
    void Othello::restart(){
        // sets all baord pieces to empty
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board[i][j].set_e();
            }
        }
        // sets initial board pieces
        board[3][3].set_w();
        board[4][4].set_w();
        board[3][4].set_b();
        board[4][3].set_b();
        // sets private members to their defaults
        w_score = 0;
        b_score = 0;
        passes = 0;
        quit = false;
        // calls restart func in game class
        game::restart();
    }
    void Othello::make_move(const string& move){
        // cheat code for fun
        if(move == "ABBY"){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    board[i][j].set_b();
                }
            }
        }
        // checks if user is quitting game
        if(move[0] == 'q' || move[0] == 'Q'){
            quit = true;    // quites the game
            return;
        }
        // passing
        if(move == "xx" || move == "XX"){
            if(passes < 2){
                passes++;
                game::make_move(move);
                return;
            }
        }
        // adds piece to board
        int row, col;
        col = int(toupper(move[0]) - 'A');  // gets col
        row = int(move[1] - '1');   // gets row
        if(next_mover() == HUMAN){  // checks if human move
            board[row][col].set_b();    // sets piece to black
        }
        if(next_mover() == COMPUTER){   // checks if computer move
            board[row][col].set_w();    // sets piece to whiteg
        }
        // resets passes
        if(move != "XX" && move != "xx"){
            passes = 0;
        }
        // flipps board peices
        up(row, col);       // correct
        down(row, col);     // correct
        right(row, col);    // correct
        left(row, col);     // correct
        u_right(row, col);  // correct
        u_left(row, col);   // correct
        d_right(row, col);  // correct
        d_left(row, col);   // correct
        game::make_move(move);  // calls game::make_move() funct
    }
    game* Othello::clone()const{
        return new Othello(*this);
    }
    void Othello::compute_moves(queue<string>& moves)const{
        string mv = "  ";   // black string of size 2
        // loops through letters (colums)
        for(char let = 'A'; let < 'I'; ++let){
            // sets mv[0] to colum letter
            mv[0] = let;
            // loops through numbers(rows)
            for(char num = '1'; num < '9'; ++num){
                // sets mv[1] to row number
                mv[1] = num;
                // checks if mv is a legal move
                if(is_legal(mv)){
                    moves.push(mv); // adds mv to the stack
                }
            }
        }
        // check if list of valid moves is empty
        if(moves.empty()){
            moves.push("XX");   // adds skip to the stack
        }
    }
    int Othello::evaluate()const{
        int score;
        int b = 0;
        int w = 0;
        // gets pieces from board
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_b()){
                    b++;
                }
                if(board[i][j].is_w()){
                    w++;
                }
            }
        }
        score = w - b;  // sets score to w - b
        return score;   // returns score
    }
    bool Othello::is_game_over()const{
        int empty_count = 0;
        // checks for empty spots
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_e()){
                    empty_count++; // updates count
                }
            }
        }
        if(empty_count == 0){
            return true;
        }
        // checks if there is not white/black pieces left
        int w = 0;
        int b = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_w()){
                    w++;
                }
                if(board[i][j].is_b()){
                    b++;
                }
            }
        }
        if(w == 0 || b == 0){
            return true;
        }
        // check both playrs passed
        if(passes >= 2){
            return true;
        }
        // check if user is quitting game
        if(quit){
            return true;
        }
        return false;   // returns false if all checks are invalid
    }
    bool Othello::is_legal(const string& move)const{
        // cheat code for fun
        if(move == "ABBY"){
            return true;
        }
        // gets row and col of move
        int col = int(toupper(move[0]) - 'A');//columns
        int row = int(move[1] - '1');//rows
        // checks if user is quitting game
        if(move[0] == 'q' || move[0] == 'Q'){
            return true;
        }
        // checks if user is passing move
        if(move == "XX" || move == "xx"){
           if(next_mover() == COMPUTER){
               return true;
           }
           if(next_mover() == HUMAN){
               if(human_val() == false){
                   return true;
               }else{
                   return false;
               }
           }
        }
        // checks if peice is valid spot on board
        if(row >= 0 || row <= 7 || col >= 0 || col <= 7){
            if(!board[row][col].is_e()){
                return false;
            }else{
                // checks if mover is computer
                if(next_mover() == COMPUTER){
                    if(row != 0){
                        // check up is black
                        if(board[row - 1][col].is_b()){
                            // checks upward direction of piece
                            for(int i = row - 1; i >= 0; --i){
                                if(board[i][col].is_e()){
                                    break;  // breaks if hits and emtpy piece
                                }
                                if(board[i][col].is_w()){
                                    return true;   // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(row != 7){
                        // check down is black
                        if(board[row + 1][col].is_b()){
                            // checks downward direction of piece
                            for(int i = row + 1; i <= 7; ++i){
                                if(board[i][col].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][col].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(col != 0){
                        // check right is black
                        if(board[row][col - 1].is_b()){
                            // checks right direction of piece
                            for(int i = col - 1; i >= 0; --i){
                                if(board[row][i].is_e()){
                                    break;  // breaks if hits empty
                                }
                                if(board[row][i].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(col != 7){
                        // check left is black
                        if(board[row][col + 1].is_b()){
                            // checks left direction of piece
                            for(int i = col + 1; i <= 7; ++i){
                                if(board[row][i].is_e()){
                                    break;  // breaks if hits an empty piece
                                }
                                if(board[row][i].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(row != 0 && col != 0){
                        // check up right is black
                        if(board[row - 1][col - 1].is_b()){
                            // check up and right direction of piece
                            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][j].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(row != 7 && col != 0){
                        // check down right is black
                        if(board[row + 1][col - 1].is_b()){
                            // check donw and right direction of piece
                            for(int i = row + 1, j = col - 1; i <= 7 && j >= 0; ++i, --j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][j].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(row != 7 && col != 7){
                        // check up left is black
                        if(board[row + 1][col + 1].is_b()){
                            // check up and left direction of piece
                            for(int i = row + 1, j = col + 1; i <= 7 && i <= 7; ++i, ++j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][j].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                    if(row != 0 && col != 7){
                        // check down left is black
                        if(board[row - 1][col + 1].is_b()){
                            // chekc down and left direction of piece
                            for(int i = row - 1, j = col + 1; i >= 0 && j <= 7; --i, ++j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][j].is_w()){
                                    return true;    // true if hits a white piece
                                }
                            }
                        }
                    }
                }
                // checks if mover is human
                if(next_mover() == HUMAN){
                    if(row != 0){
                        // check up is white
                        if(board[row - 1][col].is_w()){
                            // checks upward direction
                            for(int i = row - 1; i >= 0; --i){
                                if(board[i][col].is_e()){
                                    break;  // breaks if hits an empty piece
                                }
                                if(board[i][col].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if(row != 7){
                        // check down is white
                        if(board[row + 1][col].is_w()){
                            // checks downward direction
                            for(int i = row + 1; i <= 7; ++i){
                                if(board[i][col].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][col].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if(col != 0){
                        // check right is white
                        if(board[row][col - 1].is_w()){
                            // checks right direction
                            for(int i = col - 1; i >= 0; --i){
                                if(board[row][i].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[row][i].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if(col != 7){
                        // check left is white
                        if(board[row][col + 1].is_w()){
                            // checks left direction
                            for(int i = col + 1; i <= 7; ++i){
                                if(board[row][i].is_e()){
                                    break;  // breaks if hits an empty piece
                                }
                                if(board[row][i].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if( row != 0 && col != 0){
                        // check up right is white
                        if(board[row - 1][col - 1].is_w()){
                            // checks up and right direction
                            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits an empty piece
                                }
                                if(board[i][j].is_b()){
                                    return true;    // true if hits and empty a black piece
                                }
                            }
                        }
                    }
                    if(row != 7 && col != 0){
                        // check down right is white
                        if(board[row + 1][col - 1].is_w()){
                            // checks downa and right direction
                            for(int i = row + 1, j = col - 1; i <= 7 && j >= 0; ++i, --j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits and empty piece
                                }
                                if(board[i][j].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if(row != 7 && col != 7){
                        // check up left is white
                        if(board[row + 1][col + 1].is_w()){
                            // checks up and left direction
                            for(int i = row + 1, j = col + 1; i <= 7 && i <= 7; ++i, ++j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits an empty piece
                                }
                                if(board[i][j].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                    if(row != 0 && col != 7){
                        // check down left is white
                        if(board[row - 1][col + 1].is_w()){
                            // checks down and left direction
                            for(int i = row - 1, j = col + 1; i >= 0 && j <= 7; --i, ++j){
                                if(board[i][j].is_e()){
                                    break;  // breaks if hits a empty piece
                                }
                                if(board[i][j].is_b()){
                                    return true;    // true if hits a black piece
                                }
                            }
                        }
                    }
                }
                
            }
        }
        return false;   // returns false if all requirements are valid

    }
    void Othello::display_status( )const{
        int w = 0;
        int b = 0;
        // gets scores;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_b()){
                    b++;
                }else if(board[i][j].is_w()){
                    w++;
                }
            }
        }
        // prints board
        printboard();
        // prints scores
        cout << B_BLACK << "  WHITE: "<< RESET << BLACK << B_WHITE << w << RESET;
        cout << B_BLACK << " BLACK: " << RESET << BLACK << B_WHITE <<  b << RESET << endl;
        // displays quit and pass options
        cout << "Skip - XX   Quit - Q" << endl;
    
    }
    void Othello::up(int a, int b){
        if(a != 7){
            // checks if player is computer
            if(next_mover() == COMPUTER){
                // moves in the downawrd direction
                for(int i = a + 1; i <= 7; ++i){
                    if(board[i][b].is_e()){
                        break;  // breaks if hits an empty piece
                    }
                    if(board[i][b].is_w()){
                        // moves in downward direction if white
                        for(int j = a + 1; j <= 7; ++j){
                            if(board[j][b].is_w()){
                                break;  // breaks if hits white
                            }else{
                                board[j][b].flip(); // flips if hits black
                            }
                        }
                        break;  // breaks after peices have been flipped
                    }
                }
            }
            // checks if player is human
            if(next_mover() == HUMAN){
                // moves downward direction
                for(int i = a + 1; i <= 7; ++i){
                    if(board[i][b].is_e()){
                        break;  // breaks if hits an empty piece
                    }
                    if(board[i][b].is_b()){
                        for(int j = a + 1; j <= 7; ++j){
                            if(board[j][b].is_b()){
                                break;  // breaks if hits a black piece
                            }else{
                                board[j][b].flip(); // flips if hits a white piece
                            }
                        }
                        break;  // breaks after pieces have been flipped
                    }
                }
            }
        }
    }
    void Othello::down(int a, int b){
        if(a != 0){
            // checks if mover is computer
            if(next_mover() == COMPUTER){
                // moves in upward direction
                for(int i = a - 1; i >= 0; --i){
                    if(board[i][b].is_e()){
                        break;  // if hits empty piece breaks
                    }
                    if(board[i][b].is_w()){
                        // moves in upward direction
                        for(int j = a - 1; j >= 0; --j){
                            if(board[j][b].is_w()){
                                break;  // breaks if hits a white piece
                            }else{
                                board[j][b].flip(); // flips if hits white
                            }
                        }
                        break;  // breaks after pieces flipped
                    }
                }
            }
            // checks if mover is human
            if(next_mover() == HUMAN){
                // moves in upward direction
                for(int i = a - 1; i >= 0; --i){
                    if(board[i][b].is_e()){
                        break;  // breaks if hits empty piece
                    }
                    if(board[i][b].is_b()){
                        // moves in upward direction
                        for(int j = a - 1; j >= 0; --j){
                            if(board[j][b].is_b()){
                                break;  // breaks if hits black piece
                            }else{
                                board[j][b].flip(); // flips if hits a white piece
                            }
                        }
                        break;  // breaks after pieces flipped
                    }
                }
            }
        }
    }
    void Othello::left(int a, int b){
        if(b != 7){
            // checks if mover is computer
            if(next_mover() == COMPUTER){
                // moves in right direction
                for(int i = b + 1; i <= 7; ++i){
                    if(board[a][i].is_e()){
                        break;  // breaks if hits empty peice
                    }
                    if(board[a][i].is_w()){
                        // moves in right direction
                        for(int j = b + 1; j <= 7; ++j){
                            if(board[a][j].is_w()){
                                break;  // breaks if hits white piece
                            }else{
                                board[a][j].flip(); // flips if hits black piece
                            }   
                        }
                        break;  // breaks after pieces flipped
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = b + 1; i <= 7; ++i){
                    if(board[a][i].is_e()){
                        break;
                    }
                    if(board[a][i].is_b()){
                        for(int j = b + 1; j <= 7; ++j){
                            if(board[a][j].is_b()){
                                break;
                            }else{
                                board[a][j].flip();
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    void Othello::right(int a, int b){
        if(b != 0){
            if(next_mover() == COMPUTER){
                for(int i = b - 1; i >= 0; --i){
                    if(board[a][i].is_e()){
                        break;
                    }
                    if(board[a][i].is_w()){
                        for(int j = b - 1; j >= 0; --j){
                            if(board[a][j].is_w()){
                                break;
                            }else{
                                board[a][j].flip();
                            }
                        }
                        break;
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = b - 1; i >= 0; --i){
                    if(board[a][i].is_e()){
                        break;
                    }
                    if(board[a][i].is_b()){
                        for(int j = b - 1; j >= 0; --j){
                            if(board[a][j].is_b()){
                                break;
                            }else{
                                board[a][j].flip();
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    void Othello::d_left(int a, int b){
        if(a != 0 && b != 7){
            if(next_mover() == COMPUTER){
                for(int i = a - 1, j =b + 1; i >= 0 && j <= 7; --i, ++j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_w() == true){
                        for(int c = a - 1, d = b + 1; c >= 0 && d <= 7; --c, ++d){
                            if(board[c][d].is_w()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = a - 1, j =b + 1; i >= 0 && j <= 7; --i, ++j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_b() == true){
                        for(int c = a - 1, d = b + 1; c >= 0 && d <= 7; --c, ++d){
                            if(board[c][d].is_b()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
        }
    }
    void Othello::d_right(int a, int b){
        if(a != 0 && b != 0){
            if(next_mover() == COMPUTER){
                for(int i = a - 1, j =b -1; i >= 0 && j >= 0; --i, --j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_w() == true){
                        for(int c = a - 1, d = b -1; c >= 0 && d >= 0; --c, --d){
                            if(board[c][d].is_w()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = a - 1, j =b -1; i >= 0 && j >= 0; --i, --j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_b() == true){
                        for(int c = a - 1, d = b -1; c >= 0 && d >= 0; --c, --d){
                            if(board[c][d].is_b()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
        }
    }
    void Othello::u_left(int a, int b){
        if( a != 7 && b != 7){
            if(next_mover() == COMPUTER){
                for(int i = a + 1, j = b + 1; i <= 7 && j <= 7; ++i, ++j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_w() == true){
                        for(int c = a + 1, d = b + 1; c <= 7 && d <= 7; ++c, ++d){
                            if(board[c][d].is_w()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = a + 1, j =b + 1; i <= 7 && j <= 7; ++i, ++j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_b() == true){
                        for(int c = a + 1, d = b + 1; c <= 7 && d <= 7; ++c, ++d){
                            if(board[c][d].is_b()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
        }
    }
    void Othello::u_right(int a, int b){
        if(a != 7 && b != 0){
            if(next_mover() == COMPUTER){
                for(int i = a + 1, j =b -1; i <= 7 && j >= 0; ++i, --j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_w() == true){
                        for(int c = a + 1, d = b -1; c <= 7 && d >= 0; ++c, --d){
                            if(board[c][d].is_w()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
            if(next_mover() == HUMAN){
                for(int i = a + 1, j =b -1; i <= 7 && j >= 0; ++i, --j){
                    if(board[i][j].is_e() == true){
                        break;
                    }
                    if(board[i][j].is_b() == true){
                        for(int c = a + 1, d = b -1; c <= 7 && d >= 0; ++c, --d){
                            if(board[c][d].is_b()){
                                break;
                        }else{
                            board[c][d].flip();
                        }
                    }
                    break;
                    }
                }
            }
        }
    }
    void Othello::printboard()const{
        // displays logo
        cout << B_BLACK << " ██  █████ █  █ ████ █    █     ██ " << RESET << endl;
        cout << B_BLACK << "█  █   █   █  █ █    █    █    █  █" << RESET << endl;
        cout << B_BLACK << "█  █   █   ████ ██   █    █    █  █" << RESET << endl;
        cout << B_BLACK << "█  █   █   █  █ █    █    █    █  █" << RESET << endl;
        cout << B_BLACK << " ██    █   █  █ ████ ████ ████  ██ " << RESET << endl;
        // prints the board                                  
        cout << WHITE << B_BLACK << "    A   B   C   D   E   F   G   H  " << RESET << endl;
        cout << BLACK << B_BLACK << "  " << B_GREEN << ".---.---.---.---.---.---.---.---." << RESET << endl;
        int num = 1;
        for(int i = 0; i < 8; i++, num++){
            cout << B_BLACK << WHITE << num  << " " << RESET;
            for(int j = 0; j < 8; j++){
                cout << B_GREEN << BLACK << "| " << RESET;
                if(board[i][j].is_w()){
                    cout << B_GREEN << WHITE << "● " << RESET;
                }else if(board[i][j].is_b()){
                    cout << B_GREEN << BLACK << "● " << RESET;
                }else{
                    cout << B_GREEN << "  " << RESET;
                }
            }
            cout << B_GREEN << BLACK << "|" << RESET << endl;
            if(i < 7){
                cout << B_BLACK << "  " << B_GREEN << BLACK << "|---|---|---|---|---|---|---|---|" << RESET << endl;
            }
        }
        cout << B_BLACK << "  " << B_GREEN << BLACK << "'---'---'---'---'---'---'---'---'" << RESET << endl;
    }
    game::who Othello::winning( )const{
        int b = 0;
        int w = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_b()){
                    b++;
                }
                if(board[i][j].is_w()){
                    w++;
                }
            }
        }
        if(b > w){
            return HUMAN;
        }
        
        return COMPUTER;
    }
    bool Othello::human_val() const{
        string mv = "  ";   // black string of size 2
        // loops through letters (colums)
        for(char let = 'A'; let < 'I'; ++let){
            // sets mv[0] to colum letter
            mv[0] = let;
            // loops through numbers(rows)
            for(char num = '1'; num < '9'; ++num){
                // sets mv[1] to row number
                mv[1] = num;
                // checks if mv is a legal move
                if(is_legal(mv)){
                    return true;
                }
            }
        }
        return false;
    }
}