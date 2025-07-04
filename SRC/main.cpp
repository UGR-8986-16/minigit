#include "MiniGit.hpp"
#include <iostream>
#include <sstream>

int main()
{
    MiniGitSystem mg;
    std::string line;

    std::cout << "Welcome to MiniGit!\n";
    std::cout << "Type 'init', 'add <file>', 'commit -m \"message\"', or 'exit'.\n";

    while (true)
    {
        std::cout << "\nEnter a command: ";
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "init")
        {
            mg.init();
        }
        else if (command == "exit")
        {
            break;
        }
        else if (command == "add")
        {
            std::string filename;
            iss >> filename;
            if (!filename.empty())
                mg.add(filename);
            else
                std::cout << "Usage: add <filename>\n";
        }
        else if (command == "commit")
        {
            std::string dash;
            iss >> dash;

            std::string message;
            std::getline(iss, message);

            if (dash == "-m")
            {
                if (!message.empty() && message[0] == ' ')
                    message.erase(0, 1);
                if (!message.empty() && message.front() == '"')
                    message.erase(0, 1);
                if (!message.empty() && message.back() == '"')
                    message.pop_back();

                mg.commit(message);
            }
            else
            {
                std::cout << "Usage: commit -m \"your message\"\n";
            }
        }
        else if (command == "log")
        {
            mg.log();
        }
        else if (command == "branch")
        {
            std::string branchName;
            iss >> branchName;
            if (!branchName.empty())
            {
                mg.branch(branchName);
            }
            else
            {
                std::cout << "Usage: branch <branch-name>\n";
            }
        }
        else if (command == "checkout")
        {
            std::string branchName;
            std::cin >> branchName;
            mg.checkout(branchName);
        }
        else if (command == "merge")
        {
            std::string branchName;
            std::cin >> branchName;
            mg.merge(branchName);
        }
        else if (command == "diff")
        {
            std::string filename;
            std::cin >> filename;
            mg.diff(filename);
        }

        else
        {
            std::cout << "Unknown command. Try 'init', 'add <file>', 'commit -m \"msg\"', or 'exit'.\n";
        }
    }

    return 0;
}
