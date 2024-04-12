#include<iostream>
#include<fstream>
#include<forward_list>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class TaskNode
{
    private:
        string title;
        string description;
        string dueDate;
    public:
        TaskNode(){}
        TaskNode(string &title,string &description, string &dueDate)
        {
            this->title=title;
            this->description=description;
            this->dueDate=dueDate;
        }
        string getTitle() { return title;}
        string getDescription() { return description;}
        string getDueDate() { return dueDate;}
        void printTask()
        {
            cout<<endl;
            cout<<" Task title: "<<title<<endl;
            cout<<" Task Description: "<<description<<endl;
            cout<<" Task Due Date: "<<dueDate<<endl;
        }
};
class TaskManager
{
    private:
        forward_list<TaskNode> tasks;
        TaskManager(){ loadTasks();}
        static bool isObjectCreated;
    protected:
        void loadTasks();
        void unloadTasks();
    public:
        static TaskManager* getTaskManager()
        {
            if(isObjectCreated==false){
                isObjectCreated=true;
                return new TaskManager();
            }
            else
                cout<<"\nYou can get only one task manager"<<endl;
            return nullptr;
        }
        int menu();
        void addTask();
        void deleteTask(string&);
        void viewAllTasks();
        ~TaskManager();

};
bool TaskManager::isObjectCreated=false;
