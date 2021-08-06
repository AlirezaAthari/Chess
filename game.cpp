#include "game.h"
#include "qdebug.h"
#include "globals.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->title->setText(title);
    ui->player_2->setText(black);
    ui->player_1->setText(white);
    ui->turn->setText(turn);
    chessScene = new QGraphicsScene;
    ui->chessboardscene->setScene(chessScene);
    setBoard();
}



void Game::setWhiteMans()
{

    chessman *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("White");
        whites.append(piece);
    }
    piece = new Rook("White");
    whites.append(piece);
    piece = new Knight("White");
    whites.append(piece);
    piece = new Bishop("White");
    whites.append(piece);
    piece = new Queen("White");
    whites.append(piece);
    piece = new King("White");
    whites.append(piece);
    piece = new Bishop("White");
    whites.append(piece);
    piece = new Knight("White");
    whites.append(piece);
    piece = new Rook("White");
    whites.append(piece);
}

void Game::setBlackMans()
{
    chessman *piece;
    piece = new Rook("Black");
    blacks.append(piece);
    piece = new Knight("Black");
    blacks.append(piece);
    piece = new Bishop("Black");
    blacks.append(piece);
    piece = new Queen("Black");
    blacks.append(piece);
    piece = new King("Black");
    blacks.append(piece);
    piece = new Bishop("Black");
    blacks.append(piece);
    piece = new Knight("Black");
    blacks.append(piece);
    piece = new Rook("Black");
    blacks.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("Black");
        blacks.append(piece);
        }
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
                QGraphicsItem * p = blacks[m];
                m++;
                chessScene->addItem(p);
            }
            if(i > 5) {
                static int n;
                c->setPiece(whites[n]);
                alives.append(whites[n]);
                QGraphicsItem * p = whites[n];
                n++;
                chessScene->addItem(p);
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

            Cell *c = chessBoard[i][j];
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
    cb = new ChessBoard();
    QVector<QVector<Cell *>> board;
    board.resize(64);
    cb->drawBoard(board,270,0);
//    for (size_t i = 0 ; i < 8 ; i++ ) //for test
//    {
//        for (size_t j = 0; j< 8 ; j++)
//        {
//            Cell * c = board[i][j];
//            qDebug() << c->getAddress() << c->getPieceColor() << c->row << c->column;
//        }
//    }
    for (size_t i = 0 ; i < 8 ; i++ )
    {
        for (size_t j = 0; j< 8 ; j++)
        {
            QGraphicsItem * c = board[i][j];
            chessScene->addItem(c);
            chessBoard[i][j] = board[i][j];
        }
    }
    setBlackMans();
    setWhiteMans();
    /*QGraphicsView c(chessScene);
    ui->chessboardscene = &c;
    ui->chessboardscene->show();*/
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
