#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Load
{
private:
    int id;
    string name;
    double voltage;
    double current;
    double pf;
    bool on;

public:
    Load()
    {
        id = 0;
        name = "";
        voltage = 0;
        current = 0;
        pf = 0;
        on = false;
    }

    Load(int i, string n, double v, double c, double p, bool s)
    {
        id = i;
        name = n;
        voltage = v;
        current = c;
        pf = p;
        on = s;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    double getVoltage()
    {
        return voltage;
    }

    double getCurrent()
    {
        return current;
    }

    double getPF()
    {
        return pf;
    }

    bool getStatus()
    {
        return on;
    }

    void setStatus(bool s)
    {
        on = s;
    }

    double getPower()
    {
        if (on)
            return voltage * current * pf / 1000;
        return 0;
    }

    void show()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Voltage: " << voltage << " V" << endl;
        cout << "Current: " << current << " A" << endl;
        cout << "Power Factor: " << pf << endl;

        if (on)
            cout << "Status: ON" << endl;
        else
            cout << "Status: OFF" << endl;

        cout << "Power: " << getPower() << " kW" << endl;
        cout << "----------------------" << endl;
    }
};


class EnergySystem
{
private:
    vector<Load> loads;

public:

    bool idAlreadyExists(int id)
    {
        for (int i = 0; i < loads.size(); i++)
        {
            if (loads[i].getId() == id)
                return true;
        }

        return false;
    }

    void addLoad()
    {
        int id;
        string name;
        double voltage, current, pf;

        cout << "\nEnter ID: ";
        cin >> id;

        if (id <= 0 || idAlreadyExists(id))
        {
            cout << "Invalid or duplicate ID.\n";
            return;
        }

        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);

        if (name == "")
        {
            cout << "Name cannot be empty.\n";
            return;
        }

        cout << "Enter voltage: ";
        cin >> voltage;

        cout << "Enter current: ";
        cin >> current;

        cout << "Enter power factor: ";
        cin >> pf;

        if (voltage <= 0 || current <= 0 || pf <= 0 || pf > 1)
        {
            cout << "Invalid input.\n";
            return;
        }

        Load temp(id, name, voltage, current, pf, false);

        loads.push_back(temp);

        cout << "Load added successfully.\n";
    }

    void showAll()
    {
        if (loads.size() == 0)
        {
            cout << "\nNo loads available.\n";
            return;
        }

        cout << "\n===== All Loads =====\n";

        for (int i = 0; i < loads.size(); i++)
        {
            loads[i].show();
        }
    }

    void searchLoad()
    {
        string name;
        bool found = false;

        cin.ignore();

        cout << "\nEnter name to search: ";
        getline(cin, name);

        if (name == "")
        {
            cout << "Search name cannot be empty.\n";
            return;
        }

        for (int i = 0; i < loads.size(); i++)
        {
            if (loads[i].getName().find(name) != string::npos)
            {
                loads[i].show();
                found = true;
            }
        }

        if (!found)
            cout << "Load not found.\n";
    }

    void changeStatus()
    {
        int id;

        cout << "\nEnter ID: ";
        cin >> id;

        for (int i = 0; i < loads.size(); i++)
        {
            if (loads[i].getId() == id)
            {
                if (loads[i].getStatus())
                {
                    loads[i].setStatus(false);
                    cout << "Load turned OFF.\n";
                }
                else
                {
                    loads[i].setStatus(true);
                    cout << "Load turned ON.\n";
                }

                return;
            }
        }

        cout << "Load not found.\n";
    }

    void totalPower()
    {
        double total = 0;

        for (int i = 0; i < loads.size(); i++)
        {
            total = total + loads[i].getPower();
        }

        cout << "\nTotal Power: " << total << " kW\n";

        if (total > 100)
            cout << "Warning: Load is high.\n";
        else
            cout << "Load is normal.\n";
    }

    void checkPF()
    {
        if (loads.size() == 0)
        {
            cout << "No data available.\n";
            return;
        }

        cout << "\n===== Power Factor Check =====\n";

        for (int i = 0; i < loads.size(); i++)
        {
            cout << loads[i].getName() << ": ";

            if (loads[i].getPF() < 0.8)
                cout << "Low Power Factor";
            else
                cout << "Normal";

            cout << endl;
        }
    }

    void save()
    {
        ofstream file("loads.txt");

        for (int i = 0; i < loads.size(); i++)
        {
            file << loads[i].getId() << endl;
            file << loads[i].getName() << endl;
            file << loads[i].getVoltage() << endl;
            file << loads[i].getCurrent() << endl;
            file << loads[i].getPF() << endl;
            file << loads[i].getStatus() << endl;
        }

        file.close();
    }

    void loadData()
    {
        ifstream file("loads.txt");

        if (!file)
            return;

        int id;
        string name;
        double voltage, current, pf;
        bool status;

        while (file >> id)
        {
            file.ignore();

            getline(file, name);

            file >> voltage;
            file >> current;
            file >> pf;
            file >> status;

            Load temp(id, name, voltage, current, pf, status);

            loads.push_back(temp);
        }

        file.close();
    }
};


int main()
{
    EnergySystem system;

    system.loadData();

    int choice;

    do
    {
        
        cout << " Electrical Load Management\n";
        cout << "==============================\n";
        cout << "1. Add Load\n";
        cout << "2. Show All Loads\n";
        cout << "3. Search Load\n";
        cout << "4. Turn Load ON/OFF\n";
        cout << "5. Total Power\n";
        cout << "6. Check Power Factor\n";
        cout << "0. Exit\n";
        cout << "==============================\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addLoad();
            break;

        case 2:
            system.showAll();
            break;

        case 3:
            system.searchLoad();
            break;

        case 4:
            system.changeStatus();
            break;

        case 5:
            system.totalPower();
            break;

        case 6:
            system.checkPF();
            break;

        case 0:
            system.save();
            cout << "Data saved. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}