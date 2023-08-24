#include "Chess_Game.h"
#include <fstream>
#include <string>


ChessGame::ChessGame() {
    m_chess_board = new ChessBoard();
    init();
    init_square();
    draw_board();
};

ChessGame::~ChessGame() {
    delete m_chess_board;
    for (int i = 0; i < m_figures.size(); i++)
        delete m_figures[i];
};

int ChessGame::convert_to_int(char st)
{
    if (st == 'A')
        return static_cast<int>(latin_letters::A);
    else if (st == 'B')
        return static_cast<int>(latin_letters::B);
    else if (st == 'C')
        return static_cast<int>(latin_letters::C);
    else if (st == 'D')
        return static_cast<int>(latin_letters::D);
    else if (st == 'E')
        return static_cast<int>(latin_letters::E);
    else if (st == 'F')
        return static_cast<int>(latin_letters::F);
    else if (st == 'G')
        return static_cast<int>(latin_letters::G);
    else if (st == 'H')
        return static_cast<int>(latin_letters::H);

    return 0;

};

char ChessGame::convert_to_char(int i)
{
    if (i == 1)
        return 'A';
    else if (i == 2)
        return 'B';
    else if (i == 3)
        return 'C';
    else if (i == 4)
        return 'D';
    else if (i == 5)
        return 'E';
    else if (i == 6)
        return 'F';
    else if (i == 7)
        return 'G';
    else if (i == 8)
        return 'H';

    return 0;

};

void ChessGame::init()
{
    int x, y;

    std::ifstream inputFile; 
    inputFile.open("Figures.txt");

    if (inputFile.is_open()) 
    {
        std::string line = "";

        while (std::getline(inputFile,line))
        {
            Figure* figure;
            m_figures_count = 0;
            char color = line[0];
            char name = line[1];
            y = convert_to_int(line[2]);
            x = line[3] - '0';
            Pair place;
            x = 8 - x; y = y - 1;

            place.setX(x); place.setY(y);

            try
            {
                if (x >= 0 && x < 8 && y >= 0 && y < 8)
                {
                    if (name == 'P')
                        figure = new Pawn(color, name, place);
                    else if (name == 'R')
                        figure = new Rook(color, name, place);
                    else if (name == 'B')
                        figure = new Bishop(color, name, place);
                    else if (name == 'N')
                        figure = new Knight(color, name, place);
                    else if (name == 'Q')
                        figure = new Queen(color, name, place);
                    else if (name == 'K')
                        figure = new King(color, name, place);
                    else int i = 0;

                    m_figures.push_back(figure);
                    m_figures_count++;
                }
                else
                    throw std::string("Figure is out of the ChessBoard");
            }
            catch (std::string msg)
            {
                std::cout << msg << std::endl;
            }
        }

        inputFile.close(); 
    }
    else {
        std::cerr << "Unable to open the file." << std::endl;
    }
};

void ChessGame::init_square()
{
    for (int i = 0; i < m_figures.size(); i++)
    {
        int x = m_figures[i]->getPlace().getX();
        int y = m_figures[i]->getPlace().getY();

        m_chess_board->m_matrix[x][y].free = false;
    }
};

void ChessGame::draw_board()
{
    std::cout << std::endl << "       A        B        C        D        E        F        G        H    ";

    char color, name, sign = '_';
    int number = 8;

    for (int i = 0; i < 32; i++)
    {
        if (i % 4 == 2 && i != 2)
        {
            number--;
            std::cout << std::endl << " " << number << " ";
        }
        else if (i == 2) std::cout << std::endl << " " << number << " ";
        else
            std::cout << std::endl << "   " ;

        if (i == 0 || i % 4 != 0)
        {
            (sign == '_') ? sign = '_' : sign = ' ';
        }
        if (i != 0 && i % 4 == 0)
        {
            (sign == '_') ? sign = ' ' : sign = '_';
        }
        for (int j = 0; j < 8; j++)
        {
            if (i % 4 == 2)
            {
                int xcoord = number + 8 - (number * 2);
                if (!m_chess_board->m_matrix[xcoord][j].free)
                {
                    for (int k = 0; k < m_figures.size(); k++)
                    {
                        int x = m_figures[k]->getPlace().getX();
                        int y = m_figures[k]->getPlace().getY();
                        if (x == xcoord && y == j)
                        {
                            color = m_figures[k]->getColor();
                            name = m_figures[k]->getName();
                            std::cout << sign << sign << sign << color << name << sign << sign << sign << sign;
                            break;
                        }
                    }
                }
                else
                    std::cout << sign << sign << sign << sign << sign << sign << sign << sign << sign;
            }
            else
                std::cout << sign << sign << sign << sign << sign << sign << sign << sign << sign;

            (sign == '_') ? sign = ' ' : sign = '_';
        }
    }
    std::cout << std::endl << std::endl;
}

void new_allocate_for_figures(std::vector<Figure*>& m_figures_temp, std::vector<Figure*>& m_figures)
{

    for (int g = 0; g < m_figures.size(); g++)
    {
        char color = m_figures[g]->getColor();
        char name = m_figures[g]->getName();
        Pair place = m_figures[g]->getPlace();
        Figure* figure;

        if (name == 'P')
            figure = new Pawn(color, name, place);
        else if (name == 'R')
            figure = new Rook(color, name, place);
        else if (name == 'B')
            figure = new Bishop(color, name, place);
        else if (name == 'N')
            figure = new Knight(color, name, place);
        else if (name == 'Q')
            figure = new Queen(color, name, place);
        else if (name == 'K')
            figure = new King(color, name, place);
        else int i = 0;

        m_figures_temp.push_back(figure);
    }
}

void ChessGameCheckMate::start()
{
    bkxy = getBlackKingPlace(m_figures);
    wkxy = getWhiteKingPlace(m_figures);

    checkMateForBlackKing();
    if (!checkings())
    {
        std::vector<Pair> allLegalMovesBlackKingTemp = allLegalMovesBlackKing;
        for (int i = 0; i < allLegalMovesBlackKingTemp.size(); i++)
        {
            ChessBoard m_board_temp = *m_chess_board;
            m_board_temp.m_matrix[bkxy.x][bkxy.y].free = true;

            bkxy = allLegalMovesBlackKingTemp[i];            
            m_board_temp.m_matrix[bkxy.x][bkxy.y].free = false;

            std::vector<Figure*> m_figures_temp;
            new_allocate_for_figures(m_figures_temp, m_figures);

            setBlackKingPlace(m_figures_temp, bkxy);

            for (int k = 0; k < m_figures.size(); k++)
            {
                m_figures_temp.clear();
                new_allocate_for_figures(m_figures_temp, m_figures);
                setBlackKingPlace(m_figures_temp, bkxy);

                Pair xy = m_figures_temp[k]->getPlace();
                std::vector<Pair> allLegalMovTemp;
                if(xy != bkxy)
                   allLegalMovTemp = m_figures_temp[k]->AllLegalMoves(m_board_temp, xy, bkxy);
                
                for (int m = 0; m < allLegalMovTemp.size(); m++)
                {
                    m_board_temp.m_matrix[m_figures_temp[k]->m_place.getX()][m_figures_temp[k]->m_place.getY()].free = true;

                    m_figures_temp[k]->setPlace(allLegalMovTemp[m]);
                    m_board_temp.m_matrix[m_figures_temp[k]->m_place.getX()][m_figures_temp[k]->m_place.getY()].free = false;

                    checkMateForBlackKing(m_figures_temp, m_board_temp);
                    if (checkings())
                    {
                        Pair place = m_figures_temp[k]->getPlace();
                        
                        char letter = convert_to_char(bkxy.getY() + 1);
                        int f = 8 - bkxy.getX();
                        std::cout << "BK" << letter << f << "  -  " ;

                        letter = convert_to_char(place.getY() + 1);
                        int x = 8 - place.getX();

                        std::cout << m_figures_temp[k]->getColor() << m_figures_temp[k]->getName() << letter << x << std::endl;
                        
                       // break;
                    }
                }
            }
        }
        
    }
};

bool ChessGameCheckMate::checkings()
{
    if (isNearWhiteKing)
    {
        std::cout << "The White King can't be near to the Black King" << std::endl;
        return true;
    }
    else if (isMate)
    {
        std::cout << "It is Check and Mate" << std::endl;
        return true;
    }
    else if (isCheck)
    {
        std::cout << "It is Check" << std::endl;
        return true;
    }
    else if (isStale)
    {
        std::cout << "It is Stale" << std::endl;
        return true;
    }

    return false;
}

void ChessGameCheckMate::setBlackKingPlace(std::vector<Figure*> &m_figures_t, Pair xy)
{
    for (int i = 0; i < m_figures_t.size(); i++)
    {
        char color = m_figures_t[i]->getColor();
        char name = m_figures_t[i]->getName();

        if (color == 'B' && name == 'K')
            m_figures_t[i]->setPlace(xy);
    }
};

void ChessGameCheckMate::setWhiteKingPlace(std::vector<Figure*> &m_figures_t, Pair xy)
{
    for (int i = 0; i < m_figures_t.size(); i++)
    {
        char color = m_figures_t[i]->getColor();
        char name = m_figures_t[i]->getName();

        if (color == 'W' && name == 'K')
            m_figures_t[i]->setPlace(xy);
    }
};

Pair ChessGameCheckMate::getBlackKingPlace(std::vector<Figure*> &m_figures)
{
    Pair xy(-1, -1);
    for (int i = 0; i < m_figures.size(); i++)
    {
        char color = m_figures[i]->getColor();
        char name = m_figures[i]->getName();

        if (color == 'B' && name == 'K')
            return m_figures[i]->getPlace();
    }
    return xy;
};

Pair ChessGameCheckMate::getWhiteKingPlace(std::vector<Figure*> &m_figures)
{
    Pair xy(0, 0);
    for (int i = 0; i < m_figures.size(); i++)
    {
        char color = m_figures[i]->getColor();
        char name = m_figures[i]->getName();

        if (color == 'W' && name == 'K')
            return m_figures[i]->getPlace();
    }
    return xy;
};

bool ChessGameCheckMate::checkAreKingsNear(Pair bkxy, Pair wkxy)
{
    int rowDistance = std::abs(bkxy.x - wkxy.x);
    int colDistance = std::abs(bkxy.y - wkxy.y);

    return (rowDistance <= 1 && colDistance <= 1);
};

// Main function
void ChessGameCheckMate::checkMateForBlackKing(std::vector<Figure*> m_figures_t, ChessBoard& m_chess_board)
{
    isMate = false;
    isCheck = false;
    isStale = false;

    if (bkxy != Pair(-1, -1))
    {
        isNearWhiteKing = checkAreKingsNear(bkxy, wkxy);

        if (!isNearWhiteKing)
        {
            std::vector<Pair> allLegalMovesT;
            std::vector<Pair> allLegalMovesAllFiguresT;
            std::vector<Pair> allLegalMovesBlackKingT;

            for (int i = 0; i < m_figures_t.size(); i++)
            {
                
                Pair xy = m_figures_t[i]->getPlace();
                if (bkxy != xy)
                {
                    allLegalMovesT = m_figures_t[i]->AllLegalMoves(m_chess_board, xy, bkxy);
                    allLegalMovesAllFiguresT.insert(allLegalMovesAllFiguresT.end(), allLegalMovesT.begin(), allLegalMovesT.end());
                }
                else
                    allLegalMovesBlackKingT = m_figures_t[i]->AllLegalMoves(m_chess_board, xy, bkxy);
            }

            int count = 0;
            int count_atfirst = allLegalMovesBlackKingT.size();

            for (int i = 0; i < allLegalMovesAllFiguresT.size(); i++)
            {
                for (int j = 0; j < allLegalMovesBlackKingT.size(); j++)
                {
                    if (allLegalMovesAllFiguresT[i] == bkxy)
                    {
                        isCheck = true;
                    }

                    if (allLegalMovesAllFiguresT[i] == allLegalMovesBlackKingT[j])
                    {
                        allLegalMovesBlackKingT.erase(allLegalMovesBlackKingT.begin() + j);

                        count++;
                    }
                }
            }

            if (count >= count_atfirst)
            {
                if (isCheck == true)
                    isMate = true;
                else
                    isStale = true;
            }
        }
    }
    else
        std::cout << "Black King is out of the ChessBoard" << std::endl;

};

void ChessGameCheckMate::checkMateForBlackKing()
{
    isMate = false;
    isCheck = false;
    isStale = false;

    if (bkxy != Pair(-1, -1))
    {
        isNearWhiteKing = checkAreKingsNear(bkxy, wkxy);

        if (!isNearWhiteKing)
        {
            for (int i = 0; i < m_figures.size(); i++)
            {
                Pair xy = m_figures[i]->getPlace();
                if (bkxy != xy)
                {
                    allLegalMoves = m_figures[i]->AllLegalMoves(*m_chess_board, xy, bkxy);
                    allLegalMovesAllFigures.insert(allLegalMovesAllFigures.end(), allLegalMoves.begin(), allLegalMoves.end());
                }
                else
                    allLegalMovesBlackKing = m_figures[i]->AllLegalMoves(*m_chess_board, xy, bkxy);
            }

            int count = 0;
            int count_atfirst = allLegalMovesBlackKing.size();

            for (int i = 0; i < allLegalMovesAllFigures.size(); i++)
            {
                for (int j = 0; j < allLegalMovesBlackKing.size(); j++)
                {
                    if (allLegalMovesAllFigures[i] == bkxy)
                    {
                       isCheck = true;
                    }

                    if (allLegalMovesAllFigures[i] == allLegalMovesBlackKing[j])
                    {
                        allLegalMovesBlackKing.erase(allLegalMovesBlackKing.begin() + j);

                        count++;    
                    }
                }
            }

            if (count >= count_atfirst)
            {
                if (isCheck == true)
                    isMate = true;
                else
                    isStale = true;
            }
        }
    }
    else
        std::cout << "Black King is out of the ChessBoard" << std::endl;
   
};