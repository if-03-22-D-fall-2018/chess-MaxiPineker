/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			Khnifes Kyrillus
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>
 #ifndef ___CHESS_H
 #define ___CHESS_H
 enum Color
 {
   White, Black
 };

 enum PawnMoves
 {
   CaptureMove, NormalMove
 };
 enum PieceType
 {
   Pawn, Rook, Knight, Bishop, Queen, King, NoPiece
 };

 struct ChessPiece
 {
     enum Color color;
     enum PieceType type;
 };

 struct ChessSquare
 {
     bool is_occupied;
     struct ChessPiece piece;
 };


 typedef unsigned int Rank;
 typedef unsigned char File;
 typedef ChessSquare ChessBoard[8][8];
 typedef ChessSquare Chessboard[8][8];
 void init_chess_board(Chessboard chess_board);
 void setup_chess_board(Chessboard chess_board);
 bool is_square_occupied(ChessBoard chess_board,File file, Rank rank);

 struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank);
 bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece);
 struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank);
 bool remove_piece(ChessBoard chess_board, File file ,Rank rank);
 bool is_piece(struct ChessPiece piece, enum Color color ,enum PieceType type);

 bool squares_share_rank(File file1, Rank rank1, File file2, Rank rank2);
 bool squares_share_file(File file1, Rank rank1, File file2, Rank rank2);
 bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2);

 bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2);
 bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2);
 bool squares_share_pawns_move(enum Color color, enum PawnMoves moves, File file1, Rank rank1, File file2, Rank rank2);
 bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2);
 #endif
