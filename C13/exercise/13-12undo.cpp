#include<cstddef> // Size_t
#include<fstream>
#include<iostream>
#include<new>
using namespace std;
ofstream out("Framis.out");

unsigned char* get_pool(void);
bool* get_alloc_map(void);

class Framis
{
        enum{sz = 10 };
        char c[sz]; // To take up space, not used
        static unsigned char pool[];
        static bool alloc_map[];
    public:
        enum{psize = 100}; //Frami allowed
        Framis() {out << "Framis()\n";}
        ~Framis(){out << "~Framis() ... ";}
        // void* operator new(size_t) throw(bad_alloc);
        // void operator delete(void*);
        friend bool* get_alloc_map(void){return alloc_map;}
        friend unsigned char* get_pool(void){return pool;}
};
unsigned char Framis::pool[psize*sizeof(Framis)];
bool Framis::alloc_map[psize] = {false};
// Size is ignored -- assume a Framis object
// void* Framis::operator new(size_t) throw(bad_alloc)
// {
//     for(int i = 0; i < psize; i++)
//     {
//         if(!alloc_map[i])
//         {
//             out << "using block " << i << " ... ";
//             alloc_map[i] = true; // Mark it used
//             return pool + (i * sizeof(Framis));
//         }
//         out << "out of memory" << endl;
//         throw bad_alloc();
//     }
// }

// void Framis::operator delete(void* m)
// {
//     if(!m) return; // Check for null pointer
//     // Assume it was created in the pool
//     // Calculate which block number it is:
//     unsigned long block = (unsigned long)m - (unsigned long)pool;
//     block /= sizeof(Framis);
//     out << "freeing block " << block << endl;
//     // Mark it free:
//     alloc_map[block] = false;
// }


void* operator new(size_t sz, unsigned char* pool_i, bool* alloc) throw(bad_alloc)
{
    int i;
    for(i = 0; i < 100; i++)
    {
        if(!alloc[i])
        {
            alloc[i] = true;
            return pool_i + i*sz;
        } 
    }
    cout << "out of memory\n";
    throw bad_alloc();
}

void operator delete(void* p, bool* alloc, unsigned char* pool_i)
{
    if(!p) return;
    unsigned  long i = (unsigned long)p - (unsigned long)pool_i;
    i /= sizeof(Framis);
    alloc[i] = false;
}

int main()
{
    Framis* fp = new(get_pool(), get_alloc_map()) Framis;
    return 0;
}