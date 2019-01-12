//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "NewCmd.h"
#include "../Model/DnaSequence.h"

//SharedPtr<ICmd> NewCmd::create()
//{
//    return SharedPtr<ICmd> (new NewCmd);
//}

//bool NewCmd::reg = CmdFactory::registerToFactory("new", create);


void NewCmd::help()
{
    std::cout<<"new cmd"<<std::endl;
}

std::string NewCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    size_t id = data->getInc();
    std::string name;
    std::string item = " ";
    std::stringstream to_return;

    if (vec_size != 2 && vec_size != 3)
        return "Command new needs 2 or 3 arguments\n";

    if(vec_size == 3)
    {
        std::stringstream ss(arr[2]);

        if (arr[2][0] != '@')
            return "invalid sequence name!\n";

        while(std::getline(ss, item, '@')){}

        name = data->generateName(item);
    }
    else
        name = data->generateName(item);

    SharedPtr<IDna> pdna(new DnaSequence (arr[1]));
    SharedPtr<DnaData> pnewDna(new DnaData(id,pdna,name));
    data->addDna(pnewDna);
    to_return<<"["<<pnewDna->getId()<<"] "<<pnewDna->getName()<<": "<<arr[1]<<std::endl;

    return to_return.str();
}
