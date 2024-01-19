
#include <iostream>
using namespace std;

class COvni {
protected:
    int x, y;
    string name;
    int color;
public:
    COvni() {};
    void setPosition(int x, int y);
    void getPosition(int* x, int* y);
    void setName(string name);
    string getName();
    void setColor(int color);
    int getColor();
};

