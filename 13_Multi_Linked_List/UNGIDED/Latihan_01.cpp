#include <iostream>
#include <string>
using namespace std;

struct ProjectNode {
    string projectName;
    int duration; 
    ProjectNode* nextProject;
};

struct EmployeeNode {
    string employeeName;
    string employeeID;
    ProjectNode* projectHead; 
    EmployeeNode* nextEmployee;
};

EmployeeNode* employeeHead = nullptr;

void addEmployee(const string& name, const string& id) {
    EmployeeNode* newEmployee = new EmployeeNode{name, id, nullptr, employeeHead};
    employeeHead = newEmployee;
}

void addProject(const string& employeeID, const string& projectName, int duration) {
    EmployeeNode* currentEmployee = employeeHead;
    while (currentEmployee) {
        if (currentEmployee->employeeID == employeeID) {
            ProjectNode* newProject = new ProjectNode{projectName, duration, currentEmployee->projectHead};
            currentEmployee->projectHead = newProject;
            return;
        }
        currentEmployee = currentEmployee->nextEmployee;
    }
    cout << "Employee with ID " << employeeID << " not found.\n";
}

void deleteProject(const string& employeeID, const string& projectName) {
    EmployeeNode* currentEmployee = employeeHead;
    while (currentEmployee) {
        if (currentEmployee->employeeID == employeeID) {
            ProjectNode* prevProject = nullptr;
            ProjectNode* currentProject = currentEmployee->projectHead;
            while (currentProject) {
                if (currentProject->projectName == projectName) {
                    if (prevProject) {
                        prevProject->nextProject = currentProject->nextProject;
                    } else {
                        currentEmployee->projectHead = currentProject->nextProject;
                    }
                    delete currentProject;
                    cout << "✅ Project \"" << projectName << "\" removed from " 
                         << currentEmployee->employeeName << ".\n";
                    return;
                }
                prevProject = currentProject;
                currentProject = currentProject->nextProject;
            }
            cout << "⚠️ Project \"" << projectName << "\" not found for " 
                 << currentEmployee->employeeName << ".\n";
            return;
        }
        currentEmployee = currentEmployee->nextEmployee;
    }
    cout << "⚠️ Employee with ID " << employeeID << " not found.\n";
}

void displayEmployees() {
    cout << "==================== EMPLOYEE DIRECTORY ====================\n";
    EmployeeNode* currentEmployee = employeeHead;
    while (currentEmployee) {
        cout << "👤 Employee: " << currentEmployee->employeeName << "\n";
        cout << "   ID       : " << currentEmployee->employeeID << "\n";
        cout << "   Projects :\n";

        ProjectNode* currentProject = currentEmployee->projectHead;
        if (!currentProject) {
            cout << "     (No projects assigned)\n";
        } else {
            while (currentProject) {
                cout << "     📂 " << currentProject->projectName 
                     << " - Duration: " << currentProject->duration << " months\n";
                currentProject = currentProject->nextProject;
            }
        }
        cout << "-----------------------------------------------------------\n";
        currentEmployee = currentEmployee->nextEmployee;
    }
    cout << "===========================================================\n";
}

int main() {
    addEmployee("Andi", "P001");
    addEmployee("Budi", "P002");
    addEmployee("Citra", "P003");

    addProject("P001", "Mobile Application", 12);
    addProject("P002", "Accounting System", 8);
    addProject("P003", "E-commerce", 10);

    addProject("P001", "Data Analysis", 6);

    deleteProject("P001", "Mobile Application");

    displayEmployees();

    return 0;
}
