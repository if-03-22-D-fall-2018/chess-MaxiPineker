/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			Khnifes Kyrillus
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"
 #include <math.h>

bool are_coordinates_ok(File file1, Rank rank1, File file2, Rank rank2)
{
   return file1 <= 'h' && file1 >= 'a' && rank1 <= 8 && rank1 >= 1&&file2 <= 'h' && file2 >= 'a' && rank2 <= 8 && rank2 >= 1;
}

void init_chess_board(Chessboard chess_board)
{
  for (size_t y = 0; y < 8; y++)
  {
    for (size_t x = 0; x < 8; x++)
    {
      chess_board[y][x].is_occupied=false;
      chess_board[y][x].piece.type=NoPiece;
    }
  }
}

void setup_chess_board(Chessboard chess_board)
{
  init_chess_board(chess_board);
  for (char x = 'a'; x <= 'h'; x++)
  {
    add_piece(chess_board, x, 2, {White, Pawn});
    add_piece(chess_board, x, 7, {Black, Pawn});
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

struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank)
{
  if(file > 'h' || file < 'a' || rank > 8 || rank < 1)
  {
    return 0;
  }
  return &chess_board[rank-1][file-'a'];
}

bool is_square_occupied(ChessBoard chess_board,File file, Rank rank)
{
  struct ChessSquare* sqare = get_square(chess_board, file, rank);
  if (sqare != 0) {
    return sqare->is_occupied;
  }
  return false;
}

struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank)
{
  struct ChessSquare* square = get_square(chess_board, file, rank);
  struct ChessPiece piece_to_return = {White, NoPiece};
  if(square == 0)
  {
    return piece_to_return;
  }
  piece_to_return.type=square->piece.type;
  piece_to_return.color=square->piece.color;
  return piece_to_return;
}

bool remove_piece(ChessBoard chess_board, File file ,Rank rank)
{
  if(is_square_occupied(chess_board,file,rank))
  {
    chess_board[rank-1][file-'a'].is_occupied=false;
    chess_board[rank-1][file-'a'].piece.type=NoPiece;
    return true;
  }
  return false;
}

bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece)
{
  if (!is_square_occupied(chess_board,file,rank)&& file <= 'h' && file >= 'a' && rank <= 8 && rank >= 1)
  {
    chess_board[rank-1][file-'a'].piece=piece;
    chess_board[rank-1][file-'a'].is_occupied=true;
    return true;
  }
  return false;
}

bool is_piece(struct ChessPiece piece, enum Color color ,enum PieceType type)
{
  return piece.color == color && piece.type == type;
}

bool squares_share_rank(File file1, Rank rank1, File file2, Rank rank2)
{
  if (are_coordinates_ok(file1,rank1,file2,rank2))
  {
    return rank1==rank2;
  }
  return false;
}

bool squares_share_file(File file1, Rank rank1, File file2, Rank rank2)
{
  if (are_coordinates_ok(file1,rank1,file2,rank2))
  {
    return file1==file2;
  }
  return false;
}

bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2)
{
  if (are_coordinates_ok(file1,rank1,file2,rank2))
  {
    return fabs((double)file1-file2)==fabs((double)rank1-rank2);
  }
  return false;
}

bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2)
{
  return ((rank1 - 2 == rank2 || rank1 + 2 == rank2) && (file1 - 1 - 'a' == file2 - 'a' || file1 + 1 - 'a' == file2 - 'a')) || ((rank1 - 1 == rank2 || rank1 + 1 == rank2) && (file1 - 2 - 'a' == file2 - 'a' || file1 + 2 - 'a' == file2 - 'a'));
}


bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2)
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

bool squares_share_pawns_move(enum Color color, enum PawnMoves moves, File file1, Rank rank1, File file2, Rank rank2)
{
  if (color==White)
  {
    if (rank1>1)
    {
      if (moves==NormalMove)
      {
        if (rank1==2)
        {
          return file1==file2&&(rank1+1==rank2 || rank1+2==rank2);
        }
        else
        {
          return file1== file2&& rank1+1==rank2;
        }
      }
      else
      {
          return  rank1+1==rank2 && (file1+1==file2 || file1-1==file2);
      }
    }
  }
  else
  {
    if (rank1<8)
    {
      if (moves==NormalMove)
      {
        if (rank1==7)
        {
          return file1==file2&& (rank1-1==rank2 || rank1-2==rank2) ;
        }
        else
        {
          return file1==file2&& rank1-1==rank2;
        }
      }
      else
      {
          return  rank1-1==rank2 && (file1+1==file2 || file1-1==file2);
      }
    }
  }
  return false;
}

bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2)
{
  return squares_share_diagonal(file1,rank1,file2,rank2)||file1==file2||rank1==rank2;
}
