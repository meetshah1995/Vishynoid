#ifndef PIECE
#define PIECE
#include<list>
enum pieceType={empty, pawn, rook, bishop, knight, queen, king}
class Piece{
	public:
	pieceType type;
	int pieceValue;
	Postion pos;
	bool alive;
	Piece(const Position p){
		pos=p;
		alive=true;
	}
	list<Move> getMoves(const int[][] board){
	}
}

#endif
