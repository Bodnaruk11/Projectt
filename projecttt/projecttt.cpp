#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
private:
    string title;
    size_t year;
    size_t capacity;
    size_t price;
public:
    Car(string _title = "", size_t _year = 0, size_t _capacity = 0, size_t _price = 0)
        : title(_title), year(_year), capacity(_capacity), price(_price) {}

    string getTitle()
    {
        return this->title;
    }
    size_t getYear()
    {
        return this->year;
    }
    size_t getCapacity()
    {
        return this->capacity;
    }
    size_t getPrice()
    {
        return this->price;
    }

    void setTitle(string _title)
    {
        this->title = _title;
    }
    void setYear(size_t _year)
    {
        this->year = _year;
    }
    void setCapacity(size_t _capacity)
    {
        this->capacity = _capacity;
    }
    void setPrice(size_t _price)
    {
        this->price = _price;
    }
};

class Salon
{
private:
    vector<Car> cars;
public:
    Salon() {}

    void addCar(const Car& _car)
    {
        cars.push_back(_car);
    }
    void removeCarFromPosition(size_t _pos)
    {
        if (_pos < cars.size() && _pos > 0)
        {
            cars.erase(cars.begin() + _pos - 1);
        }
        else
            throw exception("error: wrong element position");
    }
    void show()
    {
        cout << endl;

        for (int i = 0; i < cars.size(); i++)
        {
            cout << "Car #" << (i + 1) << "" << endl;
            cout << "\tName: " << cars[i].getTitle() << endl;
            cout << "\tYear: " << cars[i].getYear() << endl;
            cout << "\tCapacity: " << cars[i].getCapacity() << endl;
            cout << "\tPrice: " << cars[i].getPrice() << endl;
            cout << endl;
        }

        cout << endl;
    }
    void sortBy(int _reason)
    {
        switch (_reason)
        {
        case 1:
            for (int i = 0; i < cars.size(); i++) {
                for (int j = i + 1; j < cars.size(); j++)
                {
                    if (cars[j].getTitle().length() < cars[i].getTitle().length()) {
                        Car temp = cars[i];
                        cars[i] = cars[j];
                        cars[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < cars.size(); i++) {
                for (int j = i + 1; j < cars.size(); j++)
                {
                    if (cars[j].getYear() < cars[i].getYear()) {
                        Car temp = cars[i];
                        cars[i] = cars[j];
                        cars[j] = temp;
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < cars.size(); i++) {
                for (int j = i + 1; j < cars.size(); j++)
                {
                    if (cars[j].getCapacity() < cars[i].getCapacity()) {
                        Car temp = cars[i];
                        cars[i] = cars[j];
                        cars[j] = temp;
                    }
                }
            }
            break;
        case 4:
            for (int i = 0; i < cars.size(); i++) {
                for (int j = i + 1; j < cars.size(); j++)
                {
                    if (cars[j].getPrice() < cars[i].getPrice()) {
                        Car temp = cars[i];
                        cars[i] = cars[j];
                        cars[j] = temp;
                    }
                }
            }
            break;
        default:
            break;
        }
    }
};

int main()
{
    bool running = true;
    string command;
    Salon salon;
    // add
    // show
    // exit

    do
    {
        cout << "--> ";
        getline(cin, command);

        if (command.compare("add") == 0)
        {
            cout << "Mark: ";
            getline(cin, command);
            string carTitle = command;

            cout << "Year: ";
            getline(cin, command);
            int year = atoi(command.c_str());

                cout << "Capacity: ";
            getline(cin, command);
            int capacity = atoi(command.c_str());

            cout << "Price: ";
            getline(cin, command);
            int price = atoi(command.c_str());

            salon.addCar(Car(carTitle, year, capacity, price));
        }
        else if (command.compare("show") == 0)
        {
            salon.show();
        }
        else if (command.compare("sort") == 0)
        {
            string line;
            getline(cin, line);
            salon.sortBy(atoi(line.c_str()));
        }
        else if (command.compare("exit") == 0)
        {
            running = false;
        }

    } while (running);

    return 0;
}