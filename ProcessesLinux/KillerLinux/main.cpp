#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//using namespace std;

void terminateByName(const char* filename){
    std::string toKill(filename);
    std::string name="killall " + toKill;
    std::system(name.c_str());
}

void terminateByID(int id){
    std::string ID(std::to_string(id));
    std::string name="kill " + ID;
    system(name.c_str());
}

int main(int argc, char* argv[]) {
    char *toKill = getenv("PROC_TO_KILL");

    if (toKill!= nullptr) {
        std::string buff(toKill);
        std::stringstream streamP(toKill);
        while (streamP.getline(toKill, buff.size(), ',')) {
            std::string str(toKill);
            const char *ch = str.c_str();
            terminateByName(ch);
        }
        std::cout<<"killed all env processes"<<std::endl;
    }

    std::string option, flag, name;
    //std::cout<<argc<<std::endl;
    if (argc == 3) {
        option=argv[1];
        std::cout<<option<<std::endl;

        if(option=="--name"){
            std::string name(argv[2]);
            //std::cout<<name<<"\n";
            const char* filename=name.c_str();
            terminateByName(filename);
        }else if(option=="--id"){
            std::string a(argv[2]);
            //std::cout<<a<<"\n";
            terminateByID(atoi(argv[2]));
        }
    } else return 0;

    return 0;
}
