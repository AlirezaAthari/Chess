#include "game.h"
#include <QAbstractScrollArea>
#include "ui_game.h"
#include "chessboard.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->title->setText(title);
    ui->player_2->setText(black);
    ui->player_1->setText(white);
    ui->turn->setText(turn);
    setBoard();


}



void Game::setWhiteMans()
{

//    chessman *piece;
//    for(int i = 0; i < 8; i++) {
//        piece = new Pawn("White");
//        white.append(piece);
//    }
//    piece = new Rook("White");
//    white.append(piece);
//    piece = new Knight("White");
//    white.append(piece);
//    piece = new Bishop("White");
//    white.append(piece);
//    piece = new Queen("White");
//    white.append(piece);
//    piece = new King("White");
//    white.append(piece);
//    piece = new Bishop("White");
//    white.append(piece);
//    piece = new Knight("White");
//    white.append(piece);
//    piece = new Rook("White");
//    white.append(piece);
}

void Game::setBlackMans()
{
//    chessman *piece;
//    piece = new Rook("Black");
//    black.append(piece);
//    piece = new Knight("Black");
//    black.append(piece);
//    piece = new Bishop("Black");
//    black.append(piece);
//    piece = new Queen("Black");
//    black.append(piece);
//    piece = new King("Black");
//    black.append(piece);
//    piece = new Bishop("Black");
//    black.append(piece);
//    piece = new Knight("Black");
//    black.append(piece);
//    piece = new Rook("Black");
//    black.append(piece);
//    for(int i = 0; i < 8; i++) {
//        piece = new Pawn("Black");
//        black.append(piece);
    //    }
}

void Game::addPieceToDeaths(chessman * p)
{
    if(p->getColor() == "White") {
        whiteDeaths.append(p);
        for(size_t i = 0 , j = 0 , k = 0 ; i<whiteDeaths.size(); i++) {
                if(j == 16){
                    k++;
                    j = 0;
                }
                whiteDeaths[i]->setPos(30 + 50*j++,670 + 100*k);
        }
    }
    else{
        blackDeaths.append(p);
        for(size_t i = 0 , j = 0 , k = 0; i<blackDeaths.size(); i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            blackDeaths[i]->setPos(30 + 50*j++,880 + 100*k);
        }
    }
    alives.removeOne(p);

}

void Game::addPiece()
{
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Cell *c =chessBoard[i][j];
            if(i < 2) {
                static int m;
                c->setPiece(blacks[m]);
                alives.append(blacks[m]);
                chessScene.addItem(blacks[m++]);
            }
            if(i > 5) {
                static int n;
                c->setPiece(whites[n]);
                alives.append(whites[n]);
                chessScene.addItem(whites[n++]);
            }
        }
    }

}

void Game::reset()
{
    int m = 0; int n = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Cell *c =chessBoard[i][j];
            c->setOccupied(false);
            c->setPieceColor("NONE");
            c->piece = NULL;
            if(i < 2) {

                c->setPiece(blacks[m]);
                blacks[m]->setPiecePlaced(true);
                alives.append(blacks[m++]);

            }
            if(i > 5) {

                c->setPiece(whites[n]);
                whites[n]->setPiecePlaced(true);
                alives.append(whites[n++]);

            }

        }
    }
}

void Game::endGame() //exit
{

}

Game::~Game()
{
    delete ui;
}

void Game::setBlack(const QString & b)
{
    black = b;
}

void Game::setWhite(const QString & w)
{
    white = w;
}

void Game::setBoard()
{

    alives.clear();
    whiteDeaths.clear();
    blackDeaths.clear();
    turn="White";
    whites.clear();
    blacks.clear();
    cb = new ChessBoard;
    QVector<QVector<Cell *>> board;
    board = cb->drawBoard(0,0);
    setBlackMans();
    setWhiteMans();
    for (size_t i = 0 ; i < 8 ; i++ )
    {
        for (size_t j = 0; j< 8 ; j++)
        {
            chessScene.addItem(board[i][j]);
        }
    }
    QGraphicsView c(&chessScene);
    ui->chessboardscene = &c;
    ui->chessboardscene->show();
}

void Game::setTitle(const QString & t)
{
    title = t;
}

void Game::changeTurn()
{
    if(getTurn() == "Black")
        turn = "White";
    else turn = "Black";
}

QString Game::getTurn()
{
    return  turn;
}

void Game::on_pushButton_clicked() //undo
{

}


void Game::on_pushButton_2_clicked() //start
{
    setBoard();
    addPiece();
}
