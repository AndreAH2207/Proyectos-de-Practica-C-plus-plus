#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Función para determinar si dos números son relativamente primos
bool sonRelativamentePrimos(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a == 1;
}

// Función para calcular la clave pública (e, n)
pair<int, int> calcularClavePublica(int p, int q) {
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 5; // Inicializar e como 2
    while (!sonRelativamentePrimos(e, phi_n)) {
        e++;
    }
    return make_pair(e, n);
}

// Función para calcular la clave privada (d, n)
pair<int, int> calcularClavePrivada(int p, int q, int e) {
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int d = 1;
    while ((d * e) % phi_n != 1) {
        d++;
    }
    return make_pair(d, n);
}

// Función para encriptar un mensaje
vector<int> encriptarMensaje(string mensaje, int e, int n) {
    vector<int> mensajeCifrado;
    for (char c : mensaje) {
        int m = (int)c; // Convertir el carácter en un número entero
        int c = 1;
        for (int i = 0; i < e; i++) { // Calcular m^e mod n iterativamente
            c = (c * m) % n;
        }
        mensajeCifrado.push_back(c);
    }
    return mensajeCifrado;
}

// Función para desencriptar un mensaje
string desencriptarMensaje(vector<int> mensajeCifrado, int d, int n) {
    string mensajeDesencriptado;
    for (int c : mensajeCifrado) {
        int m = 1;
        for (int i = 0; i < d; i++) { // Calcular c^d mod n iterativamente
            m = (m * c) % n;
        }
        char letra = (char)m; // Convertir el número entero en un carácter
        mensajeDesencriptado += letra;
    }
    return mensajeDesencriptado;
}

// Función principal
int main() 
{

    int p = 2; // Elegir dos números primos grandes
    int q = 13;
    pair<int, int> clavePublica = calcularClavePublica(p, q); // Calcular la clave pública
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