#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <tuple> //empaquetar variables
#include <string>
#include <Windows.h>
#include "InfInt.hpp"

using namespace std;


struct RSA
{
    static void generarClave();
    static vector<InfInt>encriptarMensaje(string, InfInt, InfInt); //Es un vector porque tiene muchos numeros. InfInt ayudará a encriptar numeros de grandes cifras.
    static string desencriptarMensaje(string, InfInt, InfInt); //Declaramos para poder devolver el texto original
};


InfInt MCD(InfInt a, InfInt b)
{
    if (b != 0)
        return MCD(b, a % b);
    return a;
}


//Cuando hay 3 variables sin valor usamos tuple
tuple<InfInt, InfInt, InfInt> euclides(InfInt a, InfInt b)
{
    InfInt MCD, x, y;

    if (a == 0)
    {
        return make_tuple(b, 0, 1); //devolvemos tuple, //bx + 0y = MCD(a,b) = 1
    }

    tie(MCD, x, y) = euclides(b % a, a);

    return make_tuple(MCD, y - (b / a) * x, x); // MCD , x, t

// euclides(e,phi) -> ed + phi*k = 1 

}

void RSA::generarClave()
{
    InfInt p, q, n, 𝜑, e, d;

    cout << endl;
    cout << " Escribe el numero primo p: "; cin >> p;
    cout << " Escribe el numero primo q: "; cin >> q;

    //Formula
    n = p * q;
    𝜑 = (p - 1) * (q - 1);

    do {
        cout << " Escribe un numero menor y coprimo con " << 𝜑 << " que tomara el valor de la clave publica 'e': "; cin >> e;
    } while (!(e < 𝜑 && MCD(e, 𝜑) == 1));

    d = get<1>(euclides(e, 𝜑));  //aplicar metodo de euclides para hallar la clave privada 'd'
    while (d < 0) d + d = 𝜑;  //d no puede ser negativo asi que escribo esa condicion

    cout << endl;
    cout << " El modulo [n] es: " << n << endl;
    cout << " La clave privada [d] es: " << d << endl;
    cout << " La clave publica [e] es: " << e << endl;
}



InfInt mod_potencia(InfInt base, InfInt exponente, InfInt mod)
{
    InfInt total = 1;

    while (--exponente >= 0)
    {
        total *= base;
        total %= mod;
    }
    return total;
}


inline vector<InfInt> RSA::encriptarMensaje(string mensaje, InfInt CPb_e, InfInt Modulo_n)
{
    vector<InfInt> Resultado;

    for (auto c : mensaje)  //pow(c,e) mod n
    {
        Resultado.push_back(mod_potencia((int)c, CPb_e, Modulo_n));
    }
    return Resultado;
}

inline string RSA::desencriptarMensaje(string mensaje, InfInt CPv_d, InfInt Modulo_n)
{

    vector <InfInt> msj;
    string temp("");
    string Resultado("");


    for (auto c : mensaje)
    {
        if (c == '-')
        {
            msj.push_back(temp);
            temp = "";
        }
        else
        { 
            temp += c;
        }
    }

    if (temp.length() > 0)
    {
        msj.push_back(temp);
    }


    for (auto c : msj)  //pow(c,e) mod n
    {
        auto numero = mod_potencia(c, CPv_d, Modulo_n);
        Resultado += (char)(numero.toInt());
    }
    return Resultado;
}


int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);


    while (1)
    {
        cout << endl;
        cout << " 1) Generar claves " << endl;
        cout << " 2) Encriptar " << endl;
        cout << " 3) Desencriptar " << endl;
        cout << " 4) Salir " << endl;
        cout << endl;
        cout << " Presione un numero: ";
        char opt;
        cin >> opt;

        if (opt == '1')
        {
            RSA::generarClave();
            //generar claves
        }
        else if (opt == '2')
        {
            string Mensaje;
            InfInt e, n;
            cout << endl;
            cout << " Mensaje: "; cin.ignore(); getline(cin, Mensaje);
            cout << " Clave publica (e): "; cin >> e;
            cout << " Modulo (n): "; cin >> n;
            cout << endl;

            auto r = RSA::encriptarMensaje(Mensaje, e, n);
            for (auto n : r)
            {
                cout << n << "-";
            }
            //encriptar
        }
        else if (opt == '3')
        {
            string Mensaje;
            InfInt d, n;

            cout << endl;
            cout << " Mensaje encriptado: "; cin.ignore(); getline(cin, Mensaje);
            cout << " Clave privada (d): "; cin >> d;
            cout << " Modulo (n): "; cin >> n;

            cout << endl;

            string r = RSA::desencriptarMensaje(Mensaje, d, n);
            cout << r;
            //desencriptar
        }

        else if (opt == '4')
        {
            break; //salir
        }
        cout << endl;
    }

}