// ConsoleApplication18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CompareException : public exception {};

class IStationary
{
protected:
    string name;
    double price;

public:
    IStationary(string name = "", double price = 0) : name(name), price(price) {}
    virtual ~IStationary() {};

    virtual bool operator<(const IStationary& other) = 0;
    virtual bool operator==(const IStationary& other) = 0;
    virtual void print() = 0;
    virtual void save(ostream& f) = 0;
    virtual void load(ostream& f) = 0;
};

class WritingStationary : public IStationary {
protected:
    string color;
public:
    WritingStationary(string name = "", double price = 0, string color = "blue") :
        IStationary(name, price), color(color) {}

    ~WritingStationary() {}

    void print();

    void save(ostream& f) {};
    void load(ostream& f) {};
};

class Pen : public WritingStationary {
public:
    string type;
    string model;
    Pen(string name = "", double price = 0,
        string color = "blue",
        string type = "unknown",
        string model = "none") : WritingStationary(name, price, color),
        type(type), model(model) {}

    ~Pen() {}

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};

class Pencil : public WritingStationary {
public:
    double thickness;
    Pencil(string name = "", double price = 0,
        string color = "blue",
        double thickness = 0.5) : WritingStationary(name, price, color),
        thickness(thickness) {}

    ~Pencil() {};

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};

class DrawingStationary : public IStationary {
public:
    string category;
    DrawingStationary(string name = "", double price = 0, string category = "standart") : IStationary(name, price) {};

    void print();
    void save(ostream& f) {};
    void load(ostream& f) {};
};

class Circular : public DrawingStationary {
public:
    string size;
    Circular(string name = "", double price = 0, string category = "standart", string size = "big") : DrawingStationary(name, price, category), size(size) {};

    ~Circular() {}

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};

class Board : public DrawingStationary {
public:
    string material;
    double width;
    double height;
    Board(string name = "", double price = 0, string category = "standart", string size = "big", string material = "paper", double width = 5.5, double height = 7.7) : DrawingStationary(name, price, category), material(material), width(width), height(height) {};

    ~Board() {}

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};

class PaintingStationary : public IStationary {
protected:
    string type;
public:
    PaintingStationary(string name = "", double price = 0, string type = "new") : IStationary(name, price), type(type) {};
    void print();
    void save(ostream& f) {};
    void load(ostream& f) {};
};

class Paints : public PaintingStationary {
public:
    int colorsCount;
    Paints(string name = "", double price = 0, string type = "pastel", int colorsCount = 10) :
        PaintingStationary(name, price, type), colorsCount(colorsCount) {};

    ~Paints() {}

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};

class Brush : public PaintingStationary {
public:
    int thickness;
    Brush(string name = "", double price = 0, string type = "new", int thickness = 4) : PaintingStationary(name, price, type), thickness(thickness) {};

    ~Brush() {}

    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
    void print();
};


class BaseContainer : public vector<IStationary*> {};

/*
template<class T>
class StationaryContainer : private BaseContainer {
public:
    void push(T *stationary) {
        BaseContainer::push(stationary);
    }

    long long size() {
        return BaseContainer::size();
    }

    void pop() {
        BaseContainer::pop();
    }

    T * front() {
        return (T *) BaseContainer::front();
    }
};
*/
class StationaryContainer : public BaseContainer {
public:
    StationaryContainer() {}
    void push(IStationary* o) {
        BaseContainer::push_back(o);
    }
};

void WritingStationary::print() {
    cout << name << ", price=" << price << ", " << "color=" << color;
}

bool Pen::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Pen)) {
        throw CompareException();
    }

    const Pen& pen = (Pen&)other;

    return (name < pen.name ? true : (price < pen.price ? true : false));
}

bool Pen::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Pen)) {
        return false;
    }

    const Pen& pen = (Pen&)other;

    return (name == pen.name && price == pen.price
        && color == pen.color && type == pen.type && model == pen.model);
}

void Pen::print() {
    cout << "Pen(";
    WritingStationary::print();
    cout << ", type=" << type << ", ";
    cout << "model=" << model << ")" << endl;
}

bool Pencil::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Pencil)) {
        throw CompareException();
    }

    const Pencil& pencil = (Pencil&)other;

    return (name < pencil.name ? true : (price < pencil.price ? true : false));
}

bool Pencil::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Pencil)) {
        return false;
    }

    const Pencil& pencil = (Pencil&)other;

    return (name == pencil.name && price == pencil.price
        && color == pencil.color && thickness == pencil.thickness);
}

void Pencil::print() {
    cout << "Pencil(";
    WritingStationary::print();
    cout << ", thickness=" << thickness << ")" << endl;
}

void PaintingStationary::print() {
    cout << name << ", price=" << price << ", " << "type=" << type;
}

bool Paints::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Paints)) {
        throw CompareException();
    }

    const Paints& paints = (Paints&)other;

    return (name < paints.name ? true : (colorsCount < paints.colorsCount ? true : false));
}

bool Paints::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Paints)) {
        return false;
    }

    const Paints& paints = (Paints&)other;

    return (name == paints.name && price == paints.price
        && colorsCount == paints.colorsCount && type == paints.type);
}

void Paints::print() {
    cout << "Paints(";
    PaintingStationary::print();
    cout << ", count of colors=" << colorsCount << ")" << endl;
}

bool Brush::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Brush)) {
        throw CompareException();
    }

    const Brush& brush = (Brush&)other;

    return (name < brush.name ? true : (thickness < brush.thickness ? true : false));
}

bool Brush::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Brush)) {
        return false;
    }

    const Brush& brush = (Brush&)other;

    return (name == brush.name && price == brush.price
        && thickness == brush.thickness && type == brush.type);
}

void Brush::print() {
    cout << "Brush(";
    PaintingStationary::print();
    cout << ", thickness of brush=" << thickness << ")" << endl;
}

void DrawingStationary::print() {
    cout << name << ", price=" << price << ", " << "category=" << category;
}

bool Circular::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Circular)) {
        throw CompareException();
    }

    const Circular& circular = (Circular&)other;

    return (name < circular.name ? true : (size < circular.size ? true : false));
}

bool Circular::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Circular)) {
        return false;
    }

    const Circular& circular = (Circular&)other;

    return (name == circular.name && price == circular.price
        && category == circular.category && size == circular.size);
}

void Circular::print() {
    cout << "Circular(";
    DrawingStationary::print();
    cout << ", size of circular=" << size << ")" << endl;
}

bool Board::operator<(const IStationary& other) {
    if (typeid(other) != typeid(Board)) {
        throw CompareException();
    }

    const Board& board = (Board&)other;

    return (name < board.name ? true : (width * height < board.width * board.height ? true : false));
}

bool Board::operator==(const IStationary& other) {
    if (typeid(other) != typeid(Board)) {
        return false;
    }

    const Board& board = (Board&)other;

    return (name == board.name && price == board.price
        && category == board.category && material == board.material
        && height == board.height && width == board.width);
}

void Board::print() {
    cout << "Board(";
    DrawingStationary::print();
    cout << ", material of board=" << material;
    cout << ", width * height=" << width << " * " << height << ")" << endl;
}


void print_main_menu() {
    cout << "MAIN MENU" << endl;
    cout << "1. Add Pen" << endl;
    cout << "2. Add Pencil" << endl;
    cout << "3. Add Brush" << endl;
    cout << "4. Print All" << endl;
    cout << "5. Search" << endl;
    cout << "6. Exit" << endl;
}

int get_main_menu() {
    int m;
    do {
        print_main_menu();
        cin >> m;
    } while (m < 0 || m > 6);

    return m;
}

int main() {
    StationaryContainer stationaryContainer;
    double price;
    Pen* pen;
    Pencil* pencil;
    Brush* brush;

    int m = get_main_menu();

    while (m != 6) {
        switch (m)
        {
        case 1:
            price = rand() % 30 + 20;
            pen = new Pen("ErichKrause", price, "blue", "EK", "PL-1");
            stationaryContainer.push(pen);

            break;
        case 2:
            price = rand() % 30 + 60;
            pencil = new Pencil("Koch-i-noor", price, "black", 1.0);
            stationaryContainer.push(pencil);
            break;

        case 3:
            price = rand() % 100 + 100;
            brush = new Brush("Masters", price, "horse", 4);
            stationaryContainer.push(brush);
            break;

        case 4:
            for (auto st : stationaryContainer) {
                st->print();
            }
            break;

        case 5:
            /* code */
            break;


        default:
            break;
        }

        m = get_main_menu();
    }
