#include <iostream>
#include <vector>
#include <algorithm>

//cool template class demo i guess
template<class T>
struct Node{
    T data;
    Node* next;

    Node(T data){
        this->data = data;
        this->next = nullptr;
    }

    Node* append(T data){
        Node * node = new Node(data);
        this->next = node;
        return node;

    }

    void print(){
        std::cout<< data << std::endl;
        if(next != nullptr){
            next->print();
        }
    }

}; 


struct Foo{
 int x;

    Foo(int x){
        this->x = x;
    }

    bool operator>(const Foo &rhs){
        return this->x > rhs.x;
    }
    bool operator<(const Foo & rhs){
        return this->x < rhs.x;
    }
    bool operator==(const Foo & rhs){
        return this->x == rhs.x;
    }

    //some operators u can overload are: all the comparison operators, increment / decrement, square brackets, and more 
};

int main(){

    Node<int> * node = new Node<int>(1);
    node->append(2)->append(3)->append(4)->append(5)->append(6)->append(7)->append(8)->append(9);
    //node->print();
    std::vector<Foo> foos = {Foo(2),Foo(3),Foo(4),Foo(5)};



    auto x = Foo(1);
    auto y = Foo(2);

    //this works because we overloaded the operator
    if(x > y){
        std::cout << "x is bigger" << std::endl;
    }


    //if we dont use operator overload inside this lambda function for sorting
    //the std sort comes from the algorithms header. Takes in the beginning and ending pointer of a vector, and then a lambda function tells it how to sort
    std::sort(
        foos.begin(), foos.end(), 
        [](const Foo& lhs, const Foo& rhs) -> bool{ return lhs.x > rhs.x; });

    std::sort(
        foos.begin(), foos.end(), ;

    return 0;  
}

