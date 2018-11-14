/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"

bool is_square_ok (File file, Rank rank) {
  return file - 'a' < 8 && file - 'a' >= 0 && rank < 8 && rank >= 0;
}


bool are_coordinates_ok(File file1, Rank rank1, File file2, Rank rank2)
{
   return file1 <= 'h' && file1 >= 'a' && rank1 <= 8 && rank1 >= 1&&file2 <= 'h' && file2 >= 'a' && rank2 <= 8 && rank2 >= 1;
}
bool setup_chess_board(ChessBoard chess_board)
 {
   init_chess_board(chess_board);
   for (char c = 'a'; c <= 'h'; c++) {
     add_piece(chess_board, c, 2, {White, Pawn});
     add_piece(chess_board, c, 7, {Black, Pawn});
   }
   add_piece(chess_board, 'a', 1, {White, Rook});
   add_piece(chess_board, 'h', 1, {White, Rook});
   add_piece(chess_board, 'b', 1, {White, Knight});
   add_piece(chess_board, 'g', 1, {White, Knight});
   add_piece(chess_board, 'c', 1, {White, Bishop});
   add_piece(chess_board, 'f', 1, {White, Bishop});
   add_piece(chess_board, 'd', 1, {White, Queen});
   add_piece(chess_board, 'e', 1, {White, King});

   add_piece(chess_board, 'a', 8, {Black, Rook});
   add_piece(chess_board, 'h', 8, {Black, Rook});
   add_piece(chess_board, 'b', 8, {Black, Knight});
   add_piece(chess_board, 'g', 8, {Black, Knight});
   add_piece(chess_board, 'c', 8, {Black, Bishop});
   add_piece(chess_board, 'f', 8, {Black, Bishop});
   add_piece(chess_board, 'd', 8, {Black, Queen});
   add_piece(chess_board, 'e', 8, {Black, King});
 }

 void init_chess_board (ChessBoard chess_board) {
   for (size_t y = 0; y < 8; y++) {
     for (size_t x = 0; x < 8; x++) {
       chess_board[y][x].is_occupied = false;
     }
   }
 }
struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank)
{
  if ( (file > 'h' || (file < 'a' && rank > 8) || rank < 1)) {
    return 0;
  }
  return &chess_board[rank -1][file - 'a'];
}

struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
{
  return get_square(chess_board,file,rank)->piece;
}

bool is_square_occupied(ChessBoard chess_board,File file,Rank rank)
{

  return chess_board[rank - 1][file - 'a'].is_occupied;

}

bool add_piece(ChessBoard chess_board,File file,Rank rank, ChessPiece piece)
{
  if (!is_square_occupied(chess_board,file,rank)&& file <= 'h' && file >= 'a' && rank <= 8 && rank >= 1)
{
  chess_board[rank-1][file-'a'].piece=piece;
 chess_board[rank-1][file-'a'].is_occupied=true;
 return true;
}
return false;
}


bool remove_piece(ChessBoard chess_board, File file, Rank rank){
  if (is_square_occupied(chess_board,file,rank))
   {
     chess_board[rank-1][file-'a'].is_occupied = false;
     chess_board[rank-1][file-'a'].piece.type = NoPiece;
      return true;
    }
    return false;
}


bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type)
{
    return (piece.color == color && piece.type == type);
}

bool 	squares_share_file (File file1, Rank rank1, File file2, Rank rank2)
{
  if (are_coordinates_ok(file1,rank1,file2,rank2))
 {
   return file1==file2;
 }
  return false;
}

bool 	squares_share_rank (File file1, Rank rank1, File file2, Rank rank2)
{
  if (are_coordinates_ok(file1,rank1,file2,rank2))
{
  return rank1==rank2;
}
  return false;
}

bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r) {
  if (is_square_ok(s1_f, s1_r - 1) && is_square_ok(s2_f, s2_r - 1)) {
    for (int i = 1; i < 9; i++) {
      bool is_lower_than_one = i < 1;
      if (!is_lower_than_one && (s1_r - i == s2_r || s1_r + i == s2_r) &&
          (s1_f - i - 'a' == s2_f - 'a' || s1_f - 'a' + i == s2_f - 'a')) {
        return true;
      }
    }
  }
  return false;
}

bool 	squares_share_knights_move (File file1, Rank rank1, File file2, Rank rank2)
{
  return ((rank1 - 2 == rank2 || rank1 + 2 == rank2) && (file1 - 1 - 'a' == file2 - 'a' || file1 + 1 - 'a' == file2 - 'a')) || ((rank1 - 1 == rank2 || rank1 + 1 == rank2) && (file1 - 2 - 'a' == file2 - 'a' || file1 + 2 - 'a' == file2 - 'a'));
}


bool 	squares_share_pawns_move (enum Color color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if (color == White) {
    if (move == NormalMove) {
      if (s1_r == 1) return false;
      bool is_at_starting_line = s1_r == 2;
      bool normal_move = (s1_f == s2_f && s1_r + 1 == s2_r);
      if (is_at_starting_line) {
        return normal_move || (s1_f == s2_f && s1_r + 2 == s2_r);
      }
      return normal_move;
    }
    else {
      return (s1_f + 1 == s2_f || s1_f - 1 == s2_f ) && s1_r + 1 == s2_r;
    }
  }
  else {
    if (move == NormalMove) {
      if (s1_r == 8) return false;
      bool is_at_starting_line = s1_r == 7;
      bool normal_move = (s1_f == s2_f && s1_r - 1 == s2_r);
      if (is_at_starting_line) {
        return normal_move || (s1_f == s2_f && s1_r - 2 == s2_r);
      }
      return normal_move;
    }
    else {
      return (s1_f == s2_f && s1_r - 1 == s2_r) || ((s1_f + 1 == s2_f || s1_f - 1 == s2_f) && s1_r - 1 == s2_r);
    }
  }
}

bool 	squares_share_queens_move (File file1, Rank rank1, File file2, Rank rank2)
{
  return squares_share_diagonal(file1,rank1,file2,rank2)||squares_share_file(file1,rank1,file2,rank2)||squares_share_rank(file1,rank1,file2,rank2);
}


bool 	squares_share_kings_move (File file1, Rank rank1, File file2, Rank rank2)
{
  bool move_up= rank1+1==rank2 && file1==file2;
  bool move_down= rank1-1==rank2 && file1==file2;
  bool move_right= rank1==rank2 && file1+1==file2;
  bool move_left= rank1==rank2 && file1-1==file2;
  bool move_right_up= rank1+1==rank2 && file1+1==file2;
  bool move_right_down= rank1-1==rank2 && file1+1==file2;
  bool move_left_up= rank1+1==rank2 && file1-1==file2;
  bool move_left_down= rank1-1==rank2 && file1-1==file2;
  return move_up || move_down || move_left || move_right || move_left_up || move_right_up || move_left_down || move_right_down;
 }
