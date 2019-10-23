#include <iostream>
#include <ctime>
using namespace std;

template <class T>
class list
{
private:

    //Елемент списку

    class Element
    {
    public:
        T data; // Інформація, яка зберігається в списку
        Element *address;// Адресса наступного елементу
        int count = 0;

        Element(T data = T(), Element *address = nullptr)
        {
            this->data = data;
            this->address = address;
        }
    };

    Element *head;
    Element *tempreory;

public:

    list() {head = nullptr;}
    ~list() {clear();}

    void push_back(T data);
    int &operator [] (int i);
    int size(){return head->count;}
    int clear();
    void sort();
    void push_front(T data);
    void include(int element, T data);
    void pop_back(); //1
    void pop_front(); //2
    void remove(int p);//3

};

template <class T>
void list<T>::push_back(T data)
{
    Element *Next_Element = new Element(data);


    if (head == nullptr)
        head = Next_Element;
    else
    {   
        if (head->address == nullptr)
            head->address = Next_Element;
        else
        {
           tempreory = head->address;

            while (tempreory->address != nullptr)
                tempreory = tempreory->address;

            tempreory->address = Next_Element;
        }
    }
    head->count++;
}

template <class T>
int &list<T>::operator [] (int j)
{
    tempreory = head;

    for (int i = 0;i < j; i++) {
        tempreory = tempreory->address;
    }

    return tempreory->data;
}

template <class T>
int list<T>::clear()
{
    if(head == nullptr)
        return 0;
    else
    {
        tempreory = head;

        for (;head->count > 0; head->count--) {
            for (int i = 1; i < head->count; ++i) {
                tempreory = tempreory->address;
            }
            delete tempreory;
            tempreory = head;
        }

        head = nullptr;
    }

    return 0;
}

template <class T>
void list<T>::sort()
{
    T t;
    for (int a = 1;a < head->count; a++) {
        for (int b = head->count - 1;b >= a; b--) {
            if (this->operator[](b-1) > this->operator[](b))
            {
                t = this->operator[](b-1);
                this->operator[](b-1) = this->operator[](b);
                this->operator[](b) = t;
            }
        }
    }
}

template <class T>
void list<T>::push_front(T data)
{
    Element *el_front = new Element(data);

    el_front->count = head->count;
    el_front->address = head;

    head = el_front;
    head->count++;
}

template <class T>
void list<T>::include(int element, T data)
{
    Element *nw_el = new Element(data);
    tempreory = head;

    for (int i = 0; i < element - 1; ++i) {
        tempreory = tempreory->address;
    }

    nw_el->address = tempreory->address;
    tempreory->address = nw_el;
    head->count++;
}

template <class T>
void list<T>::pop_back()
{
    tempreory = head;
    for (int i = 0; i < head->count; i++)
        tempreory = tempreory->address;

    delete tempreory;
    head->count--;

}

template <class T>
void list<T>::pop_front()
{
    tempreory = head->address;
    tempreory->count = head->count;

    delete head;

    head = tempreory;
    head->count--;
}

template <class T>
void list<T>::remove(int p)
{
    tempreory = head;
    Element *tempreory2;

    for (int i = 0;i < p; i++) {
        tempreory = tempreory->address;
    }

    tempreory2 = tempreory->address;
    delete tempreory;

    tempreory = head;
    for (int i = 0;i < p; i++) {
        tempreory = tempreory->address;
    }

    tempreory = tempreory2;
    head->count--;
}

int main()
{
    srand(time(NULL));

    list<int> ls;

    cout << "Заповнення списку.\n";
    for (int i = 0; i < 10; i++) {
        //ls.push_back(rand() % 10);
        ls.push_back(i);
    }
//    ls.push_back(0);

//    cout << "Вміст списку: ";
//    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i] << " ";
//    }
//    cout << endl;

//    cout << "Впорядкований список: ";
//    ls.sort();

//    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i] << " ";
//    }
//    cout << endl;

//    cout << "Розмір: " << ls.size() << endl;

//    cout << "Додавання нового елементу на початок: ";

//    ls.push_front(18);

//    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i] << " ";
//    }
//    cout << endl;

//    cout << "Додавання нового елементу в довільне місце: ";

//    ls.include(4, 31);

//    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i] << " ";
//    }
//    cout << endl;

//    cout << "Розмір: " << ls.size() << endl << endl;

//    ls.pop_back();
//    ls.pop_front();
//    ls.remove(4);

//    cout << "Вміст списку: ";
//    for (int i = 0; i < ls.size(); ++i) {
//        cout << ls[i] << " ";
//    }
//    cout << endl;

//    cout << "Видалення списку\n\n";

//    ls.clear();

//    cout << "Список видалено\n";

    return 0;
}
