#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double baseSalary;
    double bonus;

public:
    Employee(int id, string name, double baseSalary, double bonus) {
        this->id = id;
        this->name = name;
        this->baseSalary = baseSalary;
        this->bonus = bonus;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getBaseSalary() const {
        return baseSalary;
    }

    double getBonus() const {
        return bonus;
    }

    double calculateTotalSalary() const {
        return baseSalary + bonus;
    }

    void displayInfo() const {
        cout << "Số: " << id << ", Tên: " << name 
             << ", Tiền lương: " << baseSalary 
             << ", Tiền thưởng: " << bonus 
             << ", Tổng lương: " << calculateTotalSalary() << endl;
    }
};

class SalaryManagementSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee(int id, string name, double baseSalary, double bonus) {
        Employee newEmployee(id, name, baseSalary, bonus);
        employees.push_back(newEmployee);
    }

    void displayAllEmployees() const {
        for (const auto& employee : employees) {
            employee.displayInfo();
        }
    }

    void displayEmployeeById(int id) const {
        for (const auto& employee : employees) {
            if (employee.getId() == id) {
                employee.displayInfo();
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }
};
int main() {
    SalaryManagementSystem sms;

    sms.addEmployee(1, "Thanh Muộn", 3000, 500);
    sms.addEmployee(2, "Đặng Việt", 3500, 450);
    sms.addEmployee(3, "Mỹ Chính", 2800, 400);

    cout << "Tất cả nhân viên:" << endl;
    sms.displayAllEmployees();

    cout << "\nNhân viên có mã số 1:" << endl;
    sms.displayEmployeeById(1);

    return 0;
}