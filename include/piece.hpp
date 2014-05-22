#ifndef PIECE
#define PIECE
#include<iostream>
#include<list>
#include "constants.hpp"
#include "move.hpp"
#include "position.hpp"
using namespace std;
enum pieceType {empty, pawn, rook, bishop, knight, queen, king};

class Piece{
	public:
	pieceType type;
	int pieceValue;
	Position pos;
	int color;	
	bool alive;
	Piece(){
		pos=Position();
		alive=false;
		color=0;
	}
	Piece(Position p, int pc){
		pos=p;
		alive=true;
		color=pc;
	}
	
	list<Move> knightMoves(const int board[8][8]){
		list<Move> ret;
		if (!alive)
			return ret;
		
		const int x=pos.x;
		const int y=pos.y;
		if(isValid(x-1,y+2) && ( board[x-1][y+2]==0 || board[x-1][y+2]== -color)  )  
			ret.push_front(Move(pos, Position(x-1,y+2) ));
		if(isValid(x+1,y+2) && (board[x+1][y+2]==0 || board[x+1][y+2]== -color)) 
			ret.push_front(Move(pos, Position(x+1,y+2)));
		if(isValid(x+2,y+1) && (board[x+2][y+1]==0 || board[x+2][y+1]== -color )) 
			ret.push_front(Move(pos, Position(x+2,y+1)));
		if(isValid(x-2,y+1) && ( board[x-2][y+1]==0 || board[x-2][y+1]== -color )) 
			ret.push_front(Move(pos, Position(x-2,y+1)));
		if(isValid(x-1,y-2) && ( board[x-1][y-2]==0 || board[x-1][y-2]== -color )) 
			ret.push_front(Move(pos, Position(x-1,y-2)));
		if(isValid(x+1,y-2) && (board[x+1][y-2]==0 || board[x+1][y-2]== -color ))  
			ret.push_front(Move(pos, Position(x+1,y-2)));
		if(isValid(x+2,y-1) && ( board[x+2][y-1]==0 || board[x+2][y-1]== -color )) 
			ret.push_front(Move(pos, Position(x+2,y-1)));
		if(isValid(x-2,y-1) &&  ( board[x-2][y-1]==0 || board[x-2][y-1]== -color )) 
			ret.push_front(Move(pos, Position(x-2,y-1)));						 
		return ret;
	}
	list<Move> kingMoves(const int board[8][8]){
			list<Move> ret;
			if (!alive)
			return ret;
		
			const int x=pos.x;
			const int y=pos.y;
			for(int i=-1;i<=1;i++){
				for(int j=-1;j<=1;j++){
					if(i==0 && j==0)
						continue;
					if(isValid(x+i,y+j) && (board[x+i][y+j]==(-color) || board[x+i][y+j]==0))
						ret.push_front(Move(pos, Position(x+i,y+j)));
				}
			}
		}
	list<Move> queenMoves(const int board[8][8]){
		list<Move> ret;
		if (!alive)
			return ret;
		
		const int x=pos.x;
		const int y=pos.y;
		//up
		for(int otherx=x, othery=y+1; othery<=7;othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//down
		for(int otherx=x, othery=y-1; othery>=0;othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//right
		for(int otherx=x+1, othery=y; otherx<=7;otherx++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//left
		for(int otherx=x-1, othery=y; otherx>=0;otherx--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//upright
		for(int otherx=x+1, othery=y+1; otherx<=7 && othery<=7;otherx++,othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//downright
		for(int otherx=x+1, othery=y-1; otherx>=0 && othery<=7;otherx++,othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//upleft
		for(int otherx=x-1, othery=y+1; otherx>=0 && othery<=7;otherx--,othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//downleft
		for(int otherx=x-1, othery=y-1; otherx>=0 && othery>=0;otherx--,othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		return ret;
	}
	list<Move> bishopMoves(const int board[8][8]){
		list<Move> ret;
		if (!alive)
			return ret;
		
		const int x=pos.x;
		const int y=pos.y;
		//upright
		for(int otherx=x+1, othery=y+1; otherx<=7 && othery<=7;otherx++,othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//downright
		for(int otherx=x+1, othery=y-1; otherx>=0 && othery<=7;otherx++,othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//upleft
		for(int otherx=x-1, othery=y+1; otherx>=0 && othery<=7;otherx--,othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//downleft
		for(int otherx=x-1, othery=y-1; otherx>=0 && othery>=0;otherx--,othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		return ret;
	}
	list<Move> emptyMoves(const int board[8][8]){
		list<Move> ret;
		return ret;
	}
	list<Move> pawnMoves(const int board[8][8]){
		list<Move> ret;
		if (!alive)
			return ret;
		int x=pos.x;
		int y=pos.y;
		int change= color==1 ? 1 : -1;
		if(y!=7 && board[x][y+change]==0) //one step ahead
			ret.push_front(Move(pos, Position(x,y+change))); 
		if((y==1 && color== 1 || y==6 && color==-1) && board[x][y+2*change]==0)//two steps ahead
			ret.push_front(Move(pos, Position(x, y+2*change)));
		if(x!=7 && board[x+1][y+change]== (-color))//one step ahead, and one to the right
			ret.push_front(Move(pos, Position(x+1,y+change)));
		if(x!=0 && board[x-1][y+change]== (-color))//one step ahead and one to the left
			ret.push_front(Move(pos, Position(x-1, y+change)));
		return ret;
	}
	
	list<Move> rookMoves(const int board[8][8]){
		list<Move> ret;
		if (!alive)
			return ret;
		
		const int x=pos.x;
		const int y=pos.y;
		//up
		for(int otherx=x, othery=y+1; othery<=7;othery++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//down
		for(int otherx=x, othery=y-1; othery>=0;othery--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//right
		for(int otherx=x+1, othery=y; otherx<=7;otherx++){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		//left
		for(int otherx=x-1, othery=y; otherx>=0;otherx--){
			if(board[otherx][othery]==0)
				ret.push_front(Move(pos, Position(otherx, othery)));
			if(board[otherx][othery]==color)
				break;
			if(board[otherx][othery]==(-color)){
				ret.push_front(Move(pos, Position(otherx,othery)));
				break;
			}
		}
		return ret;
	}
	list<Move> getMoves(const int board[8][8]){
		list<Move> ret;
		if(!alive)
			return ret;
		switch(type){
			case empty: return emptyMoves(board);
				break;
			case pawn: return pawnMoves(board);
				break;
			case bishop: return bishopMoves(board);
				break;
			case rook: return rookMoves(board);
				break;
			case knight: return knightMoves(board);
				break;
			case king: return kingMoves(board);
				break;
			case queen: return queenMoves(board);
				break;
		}
	}
};
#endif
