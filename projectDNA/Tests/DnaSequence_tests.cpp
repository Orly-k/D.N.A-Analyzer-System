//
// Created by kierszen on 12/28/18.
//

#include "../Model/DnaSequence.h"
#include "../Model/Nucleotide.h"

using std::cout;
using std::endl;

void test_Dna()
{
    const char* seq1 = "ATCGTA";
    std::string seq2 = "actgtga";

    DnaSequence d1(seq1);
//    cout<<"d1 = "<<d1<<endl;
    DnaSequence d2(seq2);
//    cout<<"d2 = "<<d2<<endl;
    DnaSequence d(d2);
//    cout<<"d = "<<d<<endl;

    cout<<"d1[2] = "<<d1[2]<<endl;
    cout<<"d2[1] = "<<d2[1]<<endl;

    d1[2] = 't';
//    cout<<"d1 after d1[2] = t : "<<d1<<endl;
    cout<<"the length of d1 is: "<<d1.get_length()<<endl;
//    cout<<"content of d1 is: "<<d1<<endl;

    d = d1;
//    cout<<"d: "<<d<<endl;
    d = seq1;
//    cout<<"d: "<<d<<endl;
    d = seq2;
//    cout<<"d/: "<<d<<endl;
}