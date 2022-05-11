#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string killer_dir="../../KillerLinux/cmake-build-debug/KillerLinux";
void showActiveProcesses() {
    system("ps -e");
}

void killProcesses(std::string toKill) {
    string name=killer_dir+" "+toKill;
    system(name.c_str());
}

int main() {
    showActiveProcesses();
    setenv("PROC_TO_KILL", "thunderbird,rhythmbox", 0);
    killProcesses("");
    unsetenv("PROC_TO_KILL");
    showActiveProcesses();

    //This is the alternative interface: put "checker" variable into switch instead of "option"
    //variable so you can  type '--id' or '--name' as an option.

//    std::cout<<"Put '--name' to kill by name, or '--id' to killProcesses by id:\n";
//    string command;
//    cin >> command;
//    int checker;
//    if(command == "--id") checker=1;
//    else if(command == "--name")checker =2;
//    else checker=0;

    int option;
    cout << "Put 1 to kill by id, 2 to killProcesses by name\n";
    cin >> option;
    switch(option){
        case 1: {
            int id;
            cin >> id;
            string proc = "--id ";
            proc += to_string(id);
            //cout << command << endl;
            killProcesses((proc));
            break;
        }
        case 2: {
            string name;
            cin >> name;
            string proc = "--name " + name;
            //cout << command << endl;
            killProcesses(proc);
            break;
        }
        default:
            break;
    }

    return 0;
}