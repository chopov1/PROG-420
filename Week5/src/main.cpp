#include <iostream>

struct Point{
private:
    int x, y;

public:

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    //this is bassicly an overide for a constructor that is called when passing a struct by value. A new point is created inside the method and its values are copied over. 
    Point(Point &p1){
        this->x = p1.x;
        this->y = p1.y;
        std::cout << "COPIED" << std::endl;
    }


};

//by default c++ passes by value
//passing value is takes more resourcs then pass by reference. The severity of the performance hit depends on the size of the data
void fooVal(std::string s){
    s.append(" UGLY DUCKLING");
}

//use ampersand to get an address to variable, so we pass by reference.
void fooRef(std::string &s){
    s.append(" UGLY DUCKLING");
}

//We can see the constructor for point is triggered if passing by value
//when we pass a point struct here, it is pass by value so the constructor of point which takes in a reference of its own type is used, and the point being passed into the method is passed into that constructor as the argument. 
void bar(Point p){
    //nothing happens with p, but a new p is created to be used within this method regardless
}

int main(){
    std::string s = std::string("poopybaby");
    fooVal(s);
    fooRef(s);
    std::cout << s << std::endl;

    Point p = Point(1,2);
    bar(p);

    
    return 0;
}