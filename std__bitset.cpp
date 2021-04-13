#include <iostream>
#include <bitset>
#define M 32
using namespace std;

/*
A bitset is an array of bool but each boolean value
is not stored separately instead bitset optimizes
the space such that each bool takes 1 bit space 
only. One limitation of bitset is that N must be
known at compile time.

Bitset starts its indexing backwards, for example
for 10110 , 1 is at indices 1,2 and 4.

Bitset can be constructed using integer number as well 
as binary string via constructors. The main function
defined for bitset class are operator[],count,size
,reset etc.
*/

int main()
{
    //default constructor initializes all bits to 0
    bitset<M> bset1;
    //bset2 is initialized with bits of 20
    bitset<M> bset2(20);
    //bset3 is initialized with bits of the specified binary string
    bitset<M> bset3(string("1100"));

    cout << bset1 << endl;
    cout << bset2 << endl;
    cout << bset3 << endl;
    cout << endl;

    //declaring set8 with capacity of 8 bits
    bitset<8> set8;
    //setting first bit (or 6th index)
    set8[1] = 1;
    set8[4] = set8[1];
    cout << set8 << endl;

    //count function returns number of set bits in bitset
    int ct1 = set8.count();
    int ct0 = set8.size() - ct1;
    cout << "ct1 = " << ct1 << " "
         << "ct0 = " << ct0 << "\n";
    //test function returns 1 if bit is set else returns 0
    cout << "bool representation of " << set8 << " : ";
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";
    cout << endl;
    //any function returns true if atleast 1 bit is set
    if (!set8.any())
        cout << "set 8 has not bit set \n";
    if (!bset1.any())
        cout << "bset1 has no bit set\n";
    //none function returns true if none of the bit is set
    if (!bset1.none())
        cout << "bset1 has some bit set\n";
    //bset.set() sets all bits
    cout << set8.set() << endl;

    //bset.set(pos,b) makes bset[pos] = b;
    cout << set8.set(3, 0) << endl;

    //bset.set(pos) makes bset[pos]=1
    cout << set8.set(3) << endl;

    //reset function makes all bits 0
    cout << set8.reset(2) << endl;
    cout << set8.reset() << endl;

    //flip function flips all bits
    cout << set8.flip(2) << endl;
    cout << set8.flip() << endl;

    //converting decimal number to binary using bitset
    int num = 100;
    cout << bitset<8>(num) << "\n";
    return 0;
}