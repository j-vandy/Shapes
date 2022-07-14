/* Author: Jackson Vanderheyden */

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
       virtual void printShape() = 0; 
};

/*The TwoDShape is an abstract class that has 
two undefined functions, getArea() and getPerimeter(),
which both return doubles*/
class TwoDShape : public Shape {
    protected:
        int numberOfSides;
    public:
       virtual double getArea() = 0;
       virtual double getPerimeter() = 0;
       int getNumberOfSides() {
           return numberOfSides;
       }
};

/*The ThreeDShape is an abstract class that has 
two undefined functions, getVolume() and getSurfaceArea(),
which both return doubles*/
class ThreeDShape : public Shape {
    public:
        virtual double getVolume() = 0;
        virtual double getSurfaceArea() = 0;
};

class Square : public TwoDShape {
    private:
        double lengthOfSides;
    public:
        Square() {lengthOfSides = 1; numberOfSides = 4;};
        Square(double x) : lengthOfSides(x) {numberOfSides = 4;};

        void printShape() {
            cout << "----------\n|        |\n|        |\n|        |\n----------\n";
        }

        double getArea() {
            return lengthOfSides * lengthOfSides;
        }

        double getPerimeter() {
            return lengthOfSides * 4;
        }

        int getNumberOfSides() {
            return numberOfSides;
        }
};

class EquailateralTriangle : public TwoDShape {
    private:
        double lengthOfSides;
    public:
        EquailateralTriangle() {lengthOfSides = 1; numberOfSides = 3;};
        EquailateralTriangle(int x) : lengthOfSides(x) {numberOfSides = 3;};

        void printShape() {
            cout << "     *     \n    ***    \n   *****   \n  *******  \n ********* \n***********\n";
        }

        double getArea() {
            return sqrt(3) / 4 * lengthOfSides * lengthOfSides;
        }

        double getPerimeter() {
            return lengthOfSides * 3;
        }
};

class Cube : public ThreeDShape {
    private:
        double lengthOfSides;
    public:
        Cube() {lengthOfSides = 1;};
        Cube(int x) : lengthOfSides(x) {};

        void printShape() {
            cout << "**PRINTS A BEAUTIFUL CUBE**";
        }

        double getVolume() {
            return lengthOfSides * lengthOfSides * lengthOfSides;
        }

        double getSurfaceArea() {
            return lengthOfSides * lengthOfSides * 6;
        }
};

int main() {
    Square s(10);
    EquailateralTriangle t(10);
    Cube c(10);

    TwoDShape *arrOf2DShapes[] = {&s, &t};

    Shape *arrOfShapes[] = {&s, &t, &c};
    
    for(int i =0; i < 2; i++) {
        cout << "Shapes area: " << arrOf2DShapes[i] -> getArea() << endl;
    }

    cout << "Shapes volume: " << c.getVolume() << "\n\n" << endl;

    for(int i =0; i < 3; i++) {
        arrOfShapes[i] -> printShape();
        cout << "\n";
    }

    return 0;
}