// 3 classes used. Each time we pass object in other friend classes destructor is called after out of scope.
#include <iostream>

using namespace std;
class TestF;
class Test;
class TestFF{
    
    public:
    void setID(Test t);
    
    
    //public:
    
};
class Test{
    friend class TestF;
    friend void TestFF::setID(Test t);
    public:
    
    Test(int id,char command);
    ~Test();
    Test();
    
    int ID;
    char command;
    
    private:
    int secretCode;
    int id;
};
class TestF{
    public:
    
    void setSecretCode(Test test)
    {
        test.secretCode= 25;
        cout<<"Secret code is: "<<test.secretCode<<endl;
    }
    
    
};


void TestFF::setID(Test t){
    t.ID = 5;
    cout<<"ID is "<<t.ID<<endl;
    
}

Test::Test(int _id,char _command) : id(_id),command(_command){
    cout<< _id<<endl;
    cout<< _command<<endl;
}

Test::~Test()
{
    cout<<"Destructor called"<<endl;
}
Test::Test()
{
    cout<<"Constructor called"<<endl;
}

int main()
{
   cout << "Hello World" << endl; 
   Test test(115,'a');
   cout<<"before TestF object created"<<endl;
   TestF tfriend;
   
   TestFF tff;
   
   tfriend.setSecretCode(test);
   cout<<"after TestFF object created"<<endl;
   tff.setID(test);
   
   cout<<"before final destructor call or main exit"<<endl;
   return 0;
}