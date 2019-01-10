//
// Created by kierszen on 12/29/18.
//

#include "Execute.h"
#include "CmdFactory.h"

Execute::Execute()
{
    data = SharedPtr<DataCollection>(new DataCollection());
}

void Execute::run()
{
    int i = 3;
    std::string func_output;
    while(i--)
    {
        s = cli.get_input();
        arr = p.parsing(s);
        SharedPtr<ICmd> cmd = CmdFactory::getCmd(arr[0]);
        func_output = cmd->RunCmd(data, arr);
        cli.print_output(func_output);
    }
}
