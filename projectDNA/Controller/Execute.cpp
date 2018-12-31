//
// Created by kierszen on 12/29/18.
//

#include <string>
#include "Execute.h"
#include "CmdFactory.h"


void Execute::run()
{
//    while
    s = cli.get_input();
    arr = p.parsing(s);
    SharedPtr<ICmd> cmd = CmdFactory::getCmd(arr[0]);
    cmd->RunCmd(data, arr);
}
