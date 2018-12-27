//
// Created by kierszen on 12/25/18.
//
#include "../Model/Nucleotide.h"

using std::cout;
using std::endl;

void test_nuc()
{
    Nucleotide n1;
    Nucleotide n3;
    Nucleotide n2('a');
//    Nucleotide n4('h');

    n1 = 'g';
    n3 = n2;

    std::cout<<"n1: "<<n1<<endl;
    std::cout<<"n2: "<<n2<<endl;
    std::cout<<"n3: "<<n3<<endl;
//    std::cout<<"n4: "<<n4<<endl;

    cout<<"n1"<<n1.getNucleotide()<<endl;
    cout<<"n2 (a) pair: "<<n2.getPair()<<endl;

}





