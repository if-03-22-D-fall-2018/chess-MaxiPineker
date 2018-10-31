/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>

  enum Color { White, Black };
  enum PieceType{
    Pawn, Knight, Rook, Bishop, Queen, King, NoPiece
  };

 struct ChessPiece{
   enum Color color;
   enum PieceType type;
 };

 struct ChessSquare{
   bool is_occupied;
   struct ChessPiece piece;
 };

 typedef ChessSquare ChessBoard[8][8];
 typedef ChessSquare Chessboard[8][8];

 bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);

 void init_chess_board(ChessBoard chess_board);

 typedef int Rank;
 typedef char File;
 struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank);

 bool is_square_occupied(ChessBoard chess_board,File file,Rank rank);

 bool add_piece(ChessBoard chess_board,File a,Rank rank, ChessPiece black_rook);

 struct ChessPiece get_piece(ChessBoard chess_board, File a, Rank rank);

 bool setup_chess_board(File file, Rank rank);

 bool remove_piece(ChessBoard chess_board, File a, Rank rank, ChessPiece black_rook);
