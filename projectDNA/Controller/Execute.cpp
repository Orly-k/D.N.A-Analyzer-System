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
    int i = 0;
    std::string func_output;
    while(i != -1)
    {
        s = cli.get_input();
        arr = p.parsing(s);
        SharedPtr<ICmd> cmd = CmdFactory::getInstance()->getCmd(arr[0]);
        func_output = cmd->RunCmd(data, arr);

        if(func_output != "quit")
            cli.print_output(func_output);
        else
        {
            i = -1;
            cli.print_output("Thank you for using Dnalanyzer.\nGoodbye!\n");
        }
    }
}
