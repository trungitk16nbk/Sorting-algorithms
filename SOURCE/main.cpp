#include "Command.h"

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> command;

    for (int i = 0; i < argc; ++i)
        command.push_back(string(argv[i]));

    if (argc == 2 && command[1] == "-help")
    {
        Help();
    }
    else if (argc > 3)
    {
        Process(command);
    }
    else
    {
        cout << "Command not found!!!  \n";
        cout << "Pls Try " << command[0] << " --help for get more infomation!" << endl;
    }
    return 0;
}