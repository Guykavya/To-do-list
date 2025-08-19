#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
int id = 0;
int save = 0;
class task
{
public:
    int id; // class to take inputs for the data
    std::string desc;
    task(int id, std::string desc)
    {
        this->id = id;
        this->desc = desc;
    }
};
void title() // title
{
    std::cout << "=======================================================" << std::endl
              << "                    TO DO LIST" << std::endl
              << "=======================================================" << std::endl;
}
void menu()
{
    std::cout << "[1] to add Task" << std::endl
              << "[2] to view the task list" << std::endl
              << "[3] to delete a task" << std::endl
              << "[4] to save the list" << std::endl
              << "[5] Back" << std::endl;
}
void main_menu()
{
    std::cout << "[1] Create new Task file" << std::endl
              << "[2] Load Task file" << std::endl
              << "[3] Exit the program" << std::endl;
}
int main()
{
    title();

    std::vector<task> tasks; // it collects all the tasks
    while (true)
    {
        system("cls");
        title();
        main_menu();

        int choice;
        std::cout << "Enter your choice->";
        std::cin >> choice;
        system("cls");
        title();

        if (choice == 1)
        {
            while (true)
            {
                std::cout << "Creating new file...." << std::endl;
                menu();
                int ch;
                std::cout << "Enter your choice >";
                std::cin >> ch;
                system("cls");
                title();
                if (ch == 1)
                {
                    std::cout << "Enter the task description" << std::endl;
                    std::cin.ignore();
                    std::string desc;
                    std::getline(std::cin, desc);
                    id++;
                    tasks.push_back(task(id, desc));
                    std::cout << "Task added successfully!" << std::endl;
                    system("pause");
                }
                else if (ch == 2)
                {
                    std::cout << "Task List:" << std::endl;
                    std::cout << "*********************************************" << std::endl;
                    for (int i = 0; i < tasks.size(); i++)
                    {
                        std::cout << tasks[i].id << "|" << tasks[i].desc << std::endl;
                    }
                    std::cout << "*********************************************" << std::endl;
                    system("pause");
                }
                else if (ch == 3)
                {
                    int del;
                    std::cout << "Enter the id of the task you want to delete" << std::endl;
                    std::cin >> del;

                    bool found = false;

                    for (int i = 0; i < tasks.size(); i++)
                    {
                        if (tasks[i].id == del)
                        {
                            tasks.erase(tasks.begin() + i);
                            std::cout << "Task " << del << " deleted!" << std::endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        std::cout << "Task with ID " << del << " not found !" << std::endl;
                    }

                    system("pause");
                }
                else if (ch == 4)
                {
                    std::string name;
                    std::cout << "Enter the name for the to do list:";
                    std::cin >> name;
                    std::cout << "Saving file..." << std::endl;
                    std::string filename = name + ".txt";

                    std::ofstream task(filename);
                    std::ofstream f("list.txt", std::ios::app);
                    if (!task)
                    {
                        std::cout << "Error in creating of the file" << std::endl;
                    }
                    else
                    {
                        for (int i = 0; i < tasks.size(); i++)
                        {
                            task << tasks[i].id << " | " << tasks[i].desc << std::endl;
                        }
                        std::cout << "File saved successfully !" << std::endl;
                        f << filename << std::endl;
                    }
                    f.close();
                    task.close();
                    save++;
                    system("pause");
                }
                else if (ch == 5)
                {
                    if (save == 0)
                    {
                        std::cout << "Closing file without saving..." << std::endl;
                        system("pause");
                    }
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            std::cout << "Preparing to Load file" << std::endl;
            std::ifstream load("list.txt");
            std::vector<std::string> files;
            std::string line;
            while (std::getline(load, line))
            {
                files.push_back(line);
            }
            load.close();
            if (files.empty())
            {
                std::cout << "No saved list found !" << std::endl;
                system("pause");
                continue;
            }
            std::cout << "Available files" << std::endl;
            std::cout << "============================================================" << std::endl;
            for (int i = 0; i < files.size(); i++)
            {
                std::cout << "[" << i + 1 << "]" << files[i] << std::endl;
            }
            std::cout << "============================================================" << std::endl;
            int ch;
            std::cout << "Enter the number of the file you want to load:-";
            std::cin >> ch;
            if (ch < 1 || ch > files.size())
            {
                std::cout << "Invalid choice!" << std::endl;
                system("pause");
            }
            else
            {
                std::cout << "Opening" << files.at(ch - 1) << "..." << std::endl;
                std::ifstream infile(files.at(ch - 1));
                if (!infile)
                {
                    std::cout << "Error loading the file!" << std::endl;
                }
                else
                {
                    std::cout << "============== FILE CONTENT ==============" << std::endl;
                    std::string l;
                    while (std::getline(infile, l))
                    {
                        std::cout << l << std::endl;
                    }
                    std::cout << "============== FILE CONTENT ==============" << std::endl;
                }
                system("pause");
            }
        }
        else if (choice == 3)
        {
            {
                std::cout << "Saving your work" << std::endl;
                Sleep(1000);
                std::cout << "Exiting..." << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Invalid choice !! enter the valid choice" << std::endl;
            system("pause");
        }
    }
    return 0;
}