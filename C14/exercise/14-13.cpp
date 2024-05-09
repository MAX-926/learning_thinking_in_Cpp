//:C14:SynthesizedFunctions.cpp
//Functions that are synthesized by the compiler
#include<iostream>
using namespace std;

class GameBoard
{
    public:
        // GameBoard(){}
        GameBoard(){cout << "GameBoard()\n";}
        GameBoard(const GameBoard&){cout << "GameBoard(const GameBoard&)\n";}
        GameBoard& operator=(const GameBoard&){cout << "GameBoard::operator=()\n"; return *this;}
        ~GameBoard(){cout << "~GmaeBoard()\n";}
};

class Game
{
        GameBoard gb;//Composition (组合，gb是一个子对象，需要在Game类的构造函数初始化列表中进行构造)
    public:
        //Default GameBoard constructor called:
        Game(){cout << "Game()\n";}//所以这里的构造函数默认地调用了GameBoard的构造函数？
        //You must explicitly call the GameBoard
        //copy-constructor or the default constructor
        //is automatically called instead:
        Game(const Game& g):gb(g.gb){cout << "Game(const Game&)\n";}
        Game(int){cout << "Game(int)\n";}
        Game& operator=(const Game& g)
        {
            // You must explicitly call the GameBoard
            // assignment operator or no assignment at
            // all happens for gb! 
            gb = g.gb;
            cout << "Game::operator=()\n";
            return *this;
        }
        class Other{};//Nested class
        //Automatic type conversion:
        operator Other() const
        {
            cout << "Game::operator other()\n";
            return Other();
        }
        ~Game(){cout << "~Game()\n";}
};

class Chess:public Game
{
    public:
        Chess():Game(){cout << "Chess()\n";}
        Chess(const Chess& c):Game(c){cout << "Chess(const Chess&)\n";}
        Chess& operator=(const Chess& c){Game::operator=(c); cout << "Chess::operator=()\n";return *this;}
};

void f(Game::Other){}

class Checkers:public Game
{
    public:
    //Default base-class constructor called:
    Checkers(){cout << "Checkers()\n";}
    //You must explicitly call the base-class
    //copy constructor or the default constructor
    //will be automatically called instead
    Checkers(const Checkers& c):Game(c)
    {
        cout << "Checkers(const Checkers& c)\n";
    }
    Checkers& operator=(const Checkers& c)
    {
        //You must explicitly call the base-class
        //version of operator=() or no base-class
        //assignment will happen
        Game::operator=(c);
        cout << "Checkers::operator=()\n";
        return *this;
    }
};

int main()
{
    // Chess d1;// Default constructor
    // Chess d2(d1);// copy-constructor
    // //! Chess d3(1);// Error: no int constructor
    // d1 = d2;// operator= synthesized
    // f(d1);// Type-conversion IS inherited ！！！
    // Game::Other go;
    // //! d1 = go; // operator= not synthesized
    // // for differing types
    // Checkers c1, c2(c1);
    // c1 = c2; 
    Chess s1;
    Chess s2 = s1;
    Chess s3;
    s3 = s2;
}///:~