#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Funci�n para determinar si dos n�meros son relativamente primos
bool sonRelativamentePrimos(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a == 1;
}

// Funci�n para calcular la clave p�blica (e, n)
pair<int, int> calcularClavePublica(int p, int q) {
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 5; // Inicializar e como 2
    while (!sonRelativamentePrimos(e, phi_n)) {
        e++;
    }
    return make_pair(e, n);
}

// Funci�n para calcular la clave privada (d, n)
pair<int, int> calcularClavePrivada(int p, int q, int e) {
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int d = 1;
    while ((d * e) % phi_n != 1) {
        d++;
    }
    return make_pair(d, n);
}

// Funci�n para encriptar un mensaje
vector<int> encriptarMensaje(string mensaje, int e, int n) {
    vector<int> mensajeCifrado;
    for (char c : mensaje) {
        int m = (int)c; // Convertir el car�cter en un n�mero entero
        int c = 1;
        for (int i = 0; i < e; i++) { // Calcular m^e mod n iterativamente
            c = (c * m) % n;
        }
        mensajeCifrado.push_back(c);
    }
    return mensajeCifrado;
}

// Funci�n para desencriptar un mensaje
string desencriptarMensaje(vector<int> mensajeCifrado, int d, int n) {
    string mensajeDesencriptado;
    for (int c : mensajeCifrado) {
        int m = 1;
        for (int i = 0; i < d; i++) { // Calcular c^d mod n iterativamente
            m = (m * c) % n;
        }
        char letra = (char)m; // Convertir el n�mero entero en un car�cter
        mensajeDesencriptado += letra;
    }
    return mensajeDesencriptado;
}

// Funci�n principal
int main() 
{

    int p = 2; // Elegir dos n�meros primos grandes
    int q = 13;
    pair<int, int> clavePublica = calcularClavePublica(p, q); // Calcular la clave p�blica
    pair<int, int> clavePrivada = calcularClavePrivada(p, q, clavePublica.first); // Calcular la clave privada
    string mensaje = "COMPUTACIONAL"; // Mensaje a encriptar
    vector<int> mensajeCifrado = encriptarMensaje(mensaje, clavePublica.first, clavePublica.second); // Encriptar el mensaje

    string mensajeDesencriptado = desencriptarMensaje(mensajeCifrado, clavePrivada.first, clavePrivada.second); // Desencriptar el mensaje
    cout << "Mensaje original: " << mensaje << endl;
    cout << "Mensaje cifrado: ";
    for (int c : mensajeCifrado) {
        cout << c << " ";
    }
    cout << endl;
    cout << "Mensaje desencriptado: " << mensajeDesencriptado << endl;
    return 0;

}