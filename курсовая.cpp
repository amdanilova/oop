// ConsoleApplication18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
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
};

class WritingStationary : public IStationary {
protected:
    string color;
public:
    WritingStationary(string name = "", double price = 0, string color = "blue") :
        IStationary(name, price), color(color) {}

    void print();
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
    void print();
    ~Pencil() {};
    bool operator<(const IStationary& other);
    bool operator==(const IStationary& other);
};

class DrawingStationary : public IStationary {
protected:
    string category;
    DrawingStationary(string name = "", double price = 0,string category="standart" ) : IStationary(name, price) {};
    
    void print();
};

class Circular : public DrawingStationary {
public:
    string size;
    Circular(string name = "", double price = 0, string category = "standart" , string size = "big") : DrawingStationary(name, price, category),size(size) {};
    void print();
};

class Board : public DrawingStationary {
public:
    string material;
    double width;
    double height;
    Board(string name = "", double price = 0, string category = "standart", string size = "big", string material = "paper",double width=5.5, double height=7.7) : DrawingStationary(name, price, category),material(material),width(width),height(height) {};
    void print();
};

class PaintingStationary : public IStationary {
protected:
    string type;
public:
    PaintingStationary(string name = "", double price = 0, string type="new") : IStationary(name, price),type(type) {};
    void print();

};

class Paints : public PaintingStationary {
public:
    int colorsCount;
    Paints(string name = "", double price = 0, string type = "new", int colorsCount=10) : PaintingStationary(name, price, type),colorsCount(colorsCount) {};
    void print();
};

class Brush : public PaintingStationary {
public:
    int thickness;
    Brush(string name = "", double price = 0, string type = "new", int thickness=4 ) : PaintingStationary(name, price, type),thickness(thickness) {};
    void print();
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
        && color == pencil.color && thickness== pencil.thickness );
}

void Pen::print() {
    cout << "Pen(";
    WritingStationary::print();
    cout << ", type=" << type << ", ";
    cout << "model=" << model << ")" << endl;
}

void Pencil::print() {
    cout << "Pencil(";
    WritingStationary::print();
    cout << ", thickness=" << thickness << ")" << endl;
}
void PaintingStationary::print() {
    cout << name << ", price=" << price << ", " << "type=" << type;
}
void Paints::print() {
    cout << "Paints(";
    PaintingStationary::print();
    cout << "Count of colors=" << colorsCount <<")"<<endl ;
   
}
void Brush::print() {
    cout << "Brush(";
    PaintingStationary::print();
    cout << "thickness of brush" << thickness << ")" << endl;
}

void DrawingStationary::print() {
    cout << name << ", price=" << price << ", " << "category=" << category;
}
void Circular::print() {
    cout << "Circular(";
    DrawingStationary::print();
    cout << "Size of circular=" << size << ")" << endl;

}
void Board::print() {
    cout << "Board(";
    DrawingStationary::print();
    cout << "material of board" << material << ")" << endl;
    cout << "width of board" << width << ")" << endl;
    cout << "height" << height<< ")" << endl;
}

/*
void DrawingStationary::print() {
    cout << "category" << category << endl;

}
DrawingStationary::DrawingStationary() {};


void Circular::print() {
    cout << "size" << size << endl;
}

Circular::Circular() {}

void Board::print() {
    cout << "material" << material << endl;
    cout << "width" << width << endl;
    cout << "height" << height << endl;

}

Board::Board(double width=10.5, double height=12.5) {

    width = (rand() % 2000) / 10;
    height = (rand() % 2000) / 10;

}

void PaintingStationary::print() {
    cout << "type" << type << endl;
}

void Paints::print() {
    cout << "colorsCount" << colorsCount << endl;
}

Paints::Paints(int colorsCount = 10) {
    colorsCount = 1 + rand() % 30;
}

void Brush::print() {
    cout << "thickness" << thickness<< endl;


}

Brush::Brush(int thickness) {
    thickness = 1 + rand() % 12;
}
*/

int main() {
    Pen pen1("ErichKrause", 20, "blue", "EK", "PL-1");
    Pen pen2("ErichKrause", 25, "black", "EK", "PL-2");
    Pen pen3("ErichKrause", 35, "black", "EK", "PLS-3");
    Pen pen4("ErichKrause", 25, "black", "EK", "PL-2");

    IStationary* s;

    s = &pen1;

    pen1.print();
    pen2.print();
    pen3.print();

    s->print();

    cout << "pen1 < pen2: " << (pen1 < pen2) << endl;
    cout << "pen1 == pen2: " << (pen1 == pen2) << endl;
    cout << "pen4 == pen2: " << (pen4 == pen2) << endl;
    Pencil pencil1("ErichKrause", 20, "blue", 3.3);
    Pencil pencil2("ErichKrause", 25, "black", 4.8);
    IStationary* p;

    p = &pencil1;
    pencil1.print();
    pencil2.print();
    cout << "pencil1 < pencil2: " << (pencil1 < pencil2) << endl;
    cout << "pencil1 == pencil2: " << (pencil1 == pencil2) << endl;
    system("pause");
    return 0;
    
}