#include <iostream>


template <typename T>
class NombreComplexe {
private:
    T reel;
    T imaginaire;

public:

    NombreComplexe()  {
        reel= 0, imaginaire=0;
    }


    NombreComplexe(T r, T i)  {
         reel=r, imaginaire=i;
    }

    // Deep copy constructor
    NombreComplexe(const NombreComplexe& other) {
     reel=other.reel, imaginaire=other.imaginaire ;
     }


    void afficher() const {
        cout << reel;
        if (imaginaire >= 0) {
            cout << " + " << imaginaire << "i" << endl;
        } else {
           cout << " - " << -imaginaire << "i" << endl;
        }
    }

    NombreComplexe operator+(const NombreComplexe& other)  {
        return NombreComplexe(reel + other.reel, imaginaire + other.imaginaire);
    }

    NombreComplexe operator-(const NombreComplexe& other)  {
        return NombreComplexe(reel - other.reel, imaginaire - other.imaginaire);
    }

    NombreComplexe operator*(const NombreComplexe& other)  {
        int realPart = reel * other.reel - imaginaire * other.imaginaire;
        int imaginaryPart = reel * other.imaginaire + imaginaire * other.reel;
        return NombreComplexe(realPart, imaginaryPart);
    }

    NombreComplexe operator/(const NombreComplexe& other)  {
        int denominator = other.reel * other.reel + other.imaginaire * other.imaginaire;
        int realPart = (reel * other.reel + imaginaire * other.imaginaire) / denominator;
        int imaginaryPart = (imaginaire * other.reel - reel * other.imaginaire) / denominator;
        return NombreComplexe(realPart, imaginaryPart);
    }

    bool operator==(const NombreComplexe& other)  {
        return (reel == other.reel && imaginaire == other.imaginaire);
    }

};

 int main() {
       NombreComplexe<int> c1(3, 4);
    NombreComplexe<int> c2(1, -2);
     c1.afficher();
    c2.afficher();
    (c1 + c2).afficher();
    (c1 - c2).afficher();
    (c1* c2).afficher();
    (c1 / c2).afficher();
    cout << "c1 == c2: " << (c1 == c2) << endl;

    return 0;
}


