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
#include "chess.h"

bool setup_chess_board(ChessBoard chess_board)
{
  return false;
}

void init_chess_board(ChessBoard chess_board)
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)  {
      chess_board[i][j].is_occupied = false;
      chess_board[i][j].piece.type = NoPiece;
    }
  }
}

struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank)
{
  return 0;
}

struct ChessPiece get_piece(ChessBoard chess_board, File a, Rank rank)
{
  struct ChessPiece p;
  return p;
}

bool is_square_occupied(ChessBoard chess_board,File file,Rank rank)
{
  return false;
}

bool add_piece(ChessBoard chess_board,File a,Rank rank, ChessPiece black_rook)
{
  return false;
}


bool remove_piece(ChessBoard chess_board, File file, Rank rank)

{
  return false;
}


bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type)
{
    return (piece.color == color && piece.type == type);
}

bool 	squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_pawns_move (enum Color color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}


bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return false;
}
