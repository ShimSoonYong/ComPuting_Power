#include <iostream>
#include <string>
using namespace std;

class dog
{
    public:
        dog()
        {
            _legs = 4;
            _bark = true;
        }

        void setDogSize(string dogSize)
        {
            _dogsize = dogSize;
        }

        virtual void setEars(string type)
        {
            _earType = type;
        }
    
    private:
        string _dogsize, _earType;
        int _legs;
        bool _bark;
};

class breed : public dog
{
    public:
        breed(string color, string size)
        {
            _color = color;
            setDogSize(size);
        }

        string getColor()
        {
            return _color;
        }

        void setEars(string length, string type)
        {
            _earLength = length;
            _earType = type;
        }
    
    protected:
        string _color, _earLength, _earType;
};

int main()
{
    dog mongrel;
    string col;
    cout << "Enter a color for a dog. " << endl;
    cin >> col;
    breed labrador(col, "large");
    mongrel.setEars("pointy");
    labrador.setEars("long", "floppy");
    cout << "Cody is a " << labrador.getColor() << " labrador" << endl;
}