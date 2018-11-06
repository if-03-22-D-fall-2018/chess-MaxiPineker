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

 //White_Pawn
 for (size_t i = 0; i < 8; i++)
 {
   chess_board[1][i].piece.type=Pawn;
   chess_board[1][i].piece.color=White;
   chess_board[1][i].is_occupied=true;
 }
 //Black_Pawn
 for (size_t i = 0; i < 8; i++)
 {
   chess_board[6][i].piece.type=Pawn;
   chess_board[6][i].piece.color=Black;
   chess_board[6][i].is_occupied=true;
 }
