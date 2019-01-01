#include <iostream>

#include "Model/Nucleotide.h"
//#include "Tests/Nucleotide_tests.cpp"
//#include "Tests/DnaSequence_tests.cpp"
#include "Model/DnaSequence.h"
//#include "View/CLI.h"
//#include "View/Parser.h"
#include "Controller/Execute.h"
//#include "View/CLI.h"

int main()
{
//    test_nuc();
//    test_Dna();
//    CLI c;
//    char* str = c.get_input();
//    Parser p;
//    p.parsing(str);
    Execute execute;
    execute.run();

    return 0;
}