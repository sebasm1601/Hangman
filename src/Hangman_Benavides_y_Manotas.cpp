#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

string mayuscula(string texto){
     for (int i = 0; i < texto.size(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

int r(){
    int numero=0;
    srand(time(0)); 
    numero=rand() % 10;
    return numero;
}

void jugarAhorcado() {
    char almacen[26]{};
    int lugar = 0;
    string palabras[] = {
        "PROGRAMACION",
        "AHORCADO",
        "COMPUTADORA",
        "JUEGO",
        "TECLADO",
        "TRABAJO",
        "VIDEOJUEGO",
        "CODIGO",
        "MONITOR",
        "SISTEMA"
    };
    string descubierta; 
    int esternocleidomastoideo = r();
    string palabra = palabras[esternocleidomastoideo];

    descubierta = string(palabra.size(), '_');

    int vidas = 6;   

  
    cout << "\n=== JUEGO DEL AHORCADO ===" << endl;
    cout << "Palabra a adivinar: " << descubierta << endl;
    cout << "Vidas: " << vidas << endl << endl;

    while (descubierta != palabra && vidas > 0) { 
        string entrada;
        cout << "Ingresa una letra: ";
        cin >> entrada;


        if (entrada.empty()) {
            cout << "Error: No puedes ingresar espacios en blanco." << endl;
            continue;
        }


        bool contieneEspacio = false;
        for (size_t i = 0; i < entrada.length(); i++) {
            if (isspace(entrada[i])) {
                contieneEspacio = true;
                break;
            }
        }

        if (contieneEspacio) {
            cout << "Error: No puedes ingresar espacios en blanco." << endl;
            continue;
        }

        if (entrada.length() != 1) {
            cout << "Error: Debes ingresar solo UNA letra." << endl;
            continue;
        }

        char c = entrada[0];

        if (!isalpha(c)) {
            cout << "Entrada invalida. Solo puedes ingresar letras." << endl;
            continue; 
        }

        c = toupper(c);
        
        bool yaUsada = false;
        for(size_t j = 0; j < 26; j++){
            if (almacen[j] == c){
                cout << "Esta letra ya la pusiste, intenta con otra" << endl;
                yaUsada = true;
                break;
            } 
        }
        
        if (yaUsada) continue;
                
        almacen[lugar] = c;
        lugar++;

        bool acierto = false;
        for (size_t i = 0; i < palabra.size(); i++) {
            if (palabra[i] == c) {
                descubierta[i] = c; 
                acierto = true;
            }
        }

        if (!acierto) {
            vidas--; 
            cout << "Fallaste! Te quedan " << vidas << " intentos." << endl;
        } else {
            cout << "Correcto!" << endl;
        }

        cout << "Palabra: " << descubierta << endl;
        cout << "Vidas: " << vidas << endl << endl;
    }

    if (descubierta == palabra) {
        cout << "\nGanaste! La palabra era: " << palabra << endl;
    } else {
        cout << "\nPerdiste! La palabra era: " << palabra << endl;
    }
}

int main() {
    int opcion;
    
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Jugar Ahorcado" << endl;
        cout << "2. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                jugarAhorcado();
                break;
            case 2:
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    } while(opcion != 2);
    
    return 0;
}
