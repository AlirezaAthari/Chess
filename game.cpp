#include "game.h"
#include "qdebug.h"
#include "globals.h"

Game::Game(QString t, QString w, QString b, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Game)
{
    ui->setupUi(this);
    ui->title->setText(t);
    ui->player_1->setText(w);
    ui->player_2->setText(b);
    chessScene = new QGraphicsScene;
    chessScene->setSceneRect(0, 0, 1861, 960);
    ui->chessboardscene->setScene(chessScene);
    ui->chessboardscene->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->chessboardscene->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBoard();
}

void Game::setWhiteMans()
{

    chessman *piece;
    for (int i = 0; i < 8; i++)
    {
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
    for (int i = 0; i < 8; i++)
    {
        piece = new Pawn("Black");
        blacks.append(piece);
    }
}

void Game::addPiece()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            Cell *c = chessBoard[i][j];
            if (i < 2)
            {
                static int m;
                if (m == 16)
                    m = 0;
                c->setPiece(blacks[m]);
                alives.append(blacks[m]);
                QGraphicsItem *p = blacks[m];
                m++;
                chessScene->addItem(p);
            }
            if (i > 5)
            {
                static int n;
                if (n == 16)
                    n = 0;
                c->setPiece(whites[n]);
                alives.append(whites[n]);
                QGraphicsItem *p = whites[n];
                n++;
                chessScene->addItem(p);
            }
        }
    }
}

void Game::endGame() //exit
{
        mated = true;
        if (positiveplayer1 > positiveplayer2)
            checkDisplay->setPlainText("White won!");
        else checkDisplay->setPlainText("Black won!");
}

void Game::openReplacePawn()
{
    ReplacePawn *rp;
    rp = new ReplacePawn(this);
    rp->setModal(true);
    rp->show();
}

void Game::setChessScene()
{
    turnDisplay = new QGraphicsTextItem;
    player1Point = new QGraphicsTextItem;
    player2Point = new QGraphicsTextItem;
    checkDisplay = new QGraphicsTextItem;
    QFont font1;
    font1.setBold(true);
    font1.setPixelSize(16);
    turnDisplay = chessScene->addText("White" , font1);
    checkDisplay = chessScene->addText("Check!" , font1);
    player1Point = chessScene->addText(QString::number(positiveplayer1));
    player2Point= chessScene->addText(QString::number(positiveplayer2));
    checkDisplay->setDefaultTextColor(Qt::red);
    checkDisplay->setPos(25, 900);
    player1Point->setPos(143 , 732);
    player2Point->setPos(143 , 790);
    turnDisplay->setPos(143 , 842);
    checkDisplay->setVisible(false);

}

Game::~Game()
{
    delete player1Point;
    delete player2Point;
    delete checkDisplay;
    delete turnDisplay;
    delete movingPiece;
    for ( int i ; i < blackDeaths.size() ; i++ )
    {
        delete blackDeaths.at(i);
    }
    for ( int i ; i < whiteDeaths.size() ; i++ )
    {
        delete whiteDeaths.at(i);
    }
    for ( int i ; i < alives.size() ; i++ )
    {
        delete alives.at(i);
    }
    for ( int i ; i < 8 ; i++ )
    {
        for (int j = 0; j < 8; j++ )
        {
            delete chessBoard[i][j];
        }
    }
    delete chessScene;
    delete ui;
    delete this;
}

void Game::setBoard()
{
    cb = new ChessBoard();
    board.resize(64);
    cb->drawBoard(board, 565, 0);
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            QGraphicsItem *c = board[i][j];
            chessScene->addItem(c);
            chessBoard[i][j] = board[i][j];
        }
    }
    setBlackMans();
    setWhiteMans();
}
void Game::on_undoPushButton_clicked() //undo
{
    if (movesSeries.size() == 0)
    {
        return;
    }
    undoMove();
}

void Game::on_startPushButton_clicked() //start
{
    if (!startGame)
    {
        setChessScene();
        startGame = true;
        addPiece();
    }
}

void Game::on_resetPushButton_clicked()
{
    if (startGame)
    {
        positiveplayer1 = 0;
        positiveplayer2 = 0;
        mated = false;
        resetGame = true;
        movesSeries.clear();
        alives.clear();
        turn = "White";
        whites.clear();
        blacks.clear();
        board.clear();
        checkDisplay->setVisible(true);
        chessScene->clear();
        setChessScene();
        setBoard();
        addPiece();
    }
}

void Game::on_replacePawnPushButton_clicked()
{
    if (turn == "White")
    {
        if (movingPiece && movingPiece->getSymbol() == "P" && movingPiece->getCell()->row == 0)
        {
            openReplacePawn();
        }
        else
            return;
    }
    else
    {
        if (movingPiece && movingPiece->getSymbol() == "P" && movingPiece->getCell()->row == 7)
        {
            openReplacePawn();
        }
        else
            return;
    }
}

void Game::on_secondMovePushButton_clicked()
{
    if(movesSeries.size() >= 2)
    {
        int i = movesSeries.size()-1;
        if(movesSeries.at(i).at(0) == movesSeries.at(i-1).at(0)) return;
    }
    changeTurn();
    secondMove = true;
}

