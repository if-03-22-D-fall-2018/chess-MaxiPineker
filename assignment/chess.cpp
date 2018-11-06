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
void setup_chess_board(ChessBoard chess_board){

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
 //White_Rook
 chess_board[0][0].piece.type=Rook;
 chess_board[0][0].piece.type=White;
 chess_board[0][0].is_occupied=true;
 chess_board[0][7].piece.type=Rook;
 chess_board[0][7].piece.type=White;
 chess_board[0][7].is_occupied=true;
 //black_rook
 chess_board[7][0].piece.type=Rook;
 chess_board[7][0].piece.type=Black;
 chess_board[7][0].is_occupied=true;
 chess_board[7][7].piece.type=Rook;
 chess_board[7][7].piece.type=Black;
 chess_board[7][7].is_occupied=true;
 //White_Knight
 chess_board[0][1].piece.type=Knight;
 chess_board[0][1].piece.color=White;
 chess_board[0][1].is_occupied=true;
 chess_board[0][6].piece.type=Knight;
 chess_board[0][6].piece.color=White;
 chess_board[0][6].is_occupied=true;
 //Black_Knight
 chess_board[7][1].piece.type=Knight;
 chess_board[7][1].piece.color=White;
 chess_board[7][1].is_occupied=true;
 chess_board[7][6].piece.type=Knight;
 chess_board[7][6].piece.color=White;
 chess_board[7][6].is_occupied=true;
 //White_Bishop
 chess_board[0][2].piece.type=Bishop;
 chess_board[0][2].piece.color=White;
 chess_board[0][2].is_occupied=true;
 chess_board[0][5].piece.type=Bishop;
 chess_board[0][5].piece.color=White;
 chess_board[0][5].is_occupied=true;
 //Black_Bishop
 chess_board[7][2].piece.type=Bishop;
 chess_board[7][2].piece.color=Black;
 chess_board[7][2].is_occupied=true;
 chess_board[7][5].piece.type=Bishop;
 chess_board[7][5].piece.color=Black;
 chess_board[7][5].is_occupied=true;
 //White King
 chess_board[0][3].piece.type=King;
 chess_board[0][3].piece.color=White;
 chess_board[0][3].is_occupied=true;
 //Black_King
 chess_board[7][3].piece.type=King;
 chess_board[7][3].piece.color=Black;
 chess_board[7][3].is_occupied=true;
 //White_Queen
 chess_board[0][4].piece.type=Queen;
 chess_board[0][4].piece.color=White;
 chess_board[0][4].is_occupied=true;
 //Black_Queen
 chess_board[7][4].piece.type=Queen;
 chess_board[7][4].piece.color=Black;
 chess_board[7][4].is_occupied=true;
}

 struct ChessSquare* get_square(ChessBoard chess_board,File file,Rank rank){

   if ((file > 'h' || file < 'a') && (rank > 8 || rank < 1)) {
     return 0;
   }

   return &chess_board[rank][file - 'a'];
}
struct ChessPiece get_piece(ChessBoard chess_board, File a, Rank rank){
    struct ChessPiece piece;
    if (file > 'h' || rank > 7 || rank < 0 || file 'a') {
      piece.type=NoPiece;
      return piece;
    }
    piece.type=chess_board[rank][file-'a'].piece.type;
    piece.colo=chess_board[rank][file-'a'].piec-color;
    return piece;
}
