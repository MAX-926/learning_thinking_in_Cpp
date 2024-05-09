// g++ 12-15.cpp -o composition.exe -include 12-14.cpp
#include<iostream>
#include"E:\thinking in C++\C12\exercise\12-14.cpp"
using namespace std;

class BirdHouse
{
    private:
        Bird b;
        Bird* bp;
        Bird& bq;
    public:
        BirdHouse(Bird b1, Bird b2, Bird b3):b(b1), bp(&b2), bq(b3){}
        // BirdHouse(const BirdHouse& bh){b = bh.b; bp = bh.bp;}
        BirdHouse& operator=(const BirdHouse& bh){b = bh.b, bp = bh.bp; bq = bh.bq;}
        friend ostream& operator<<(ostream& os, const BirdHouse& bh)
        {
            return os << "bh.b: " << bh.b << endl 
                      << "bh.bp: " << bh.bp << endl
                      << "bh.bq: " << bh.bq << endl;
        }
};

int main()
{
    Bird b1, b2, b3;
    BirdHouse bh(b1, b2, b3);
    cout << bh;
    //
}