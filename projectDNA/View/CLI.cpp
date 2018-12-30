//
// Created by kierszen on 12/29/18.
//

#include <string>
#include <stdio.h>
#include <iostream>
#include "CLI.h"

std::string CLI::get_input()
{
  std::string input;
  std::cout<<"please enter your cmd and details: "<<std::endl;
  std::cin>>input;

  return input;
}
