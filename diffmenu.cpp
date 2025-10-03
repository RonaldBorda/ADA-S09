#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
int n;

class HashTable {
private:
// Número de "buckets" (espacios) en la tabla hash
    int capacity;

// Tabla hash representada como un vector de listas
    vector<list<pair<string, int>>> table;

// Función hash
    int hashFunction (const string key) {
    int hashValue = 0;
    for (char ch: key) {  
        hashValue += ch;     // os valores ASCII de los caracteres
         // Retorna el indice dentro del rango
    }
    return hashValue % capacity; 
}

public:

HashTable (int size) : capacity (size) {
table.resize(capacity);
}

void insert (const string& key, int value) {
int index = hashFunction (key);
for (auto& pair : table[index]) {
    if (pair.first == key) {
        pair.second = value; 
        return;
    }
}
table[index].emplace_back(key, value);
}


int search (const string& key) {
int index = hashFunction (key);
for (const auto& pair : table [index]) {
if (pair.first == key) {
    return pair.second;
    }
    }
return -1; 
}

void remove (const string& key) {
int index = hashFunction(key);
auto& entries = table[index];
for (auto it = entries.begin(); it != entries.end(); ++it) {
    if (it->first == key) {
        entries.erase(it); // Elimina la entrada
        return;
        }
    }
}

void display () {
for (int i = 0; i < capacity; ++i) {
    cout << "Bucket " << i << ": ";
    for (const auto &pair : table[i]) {
        cout << "(" << pair.first << ": " << pair.second << ") ";
        cout << std::endl;
    }
}
}
};

HashTable ht(100); 

void menu() {

    do {
    cout << "Menu para la utilización del metodo hash, presione: " << endl;
    cout << "1. Insertar datos" << endl;
    cout << "2. Buscar un dato" << endl;
    cout << "3. Remover un dato" << endl;
    cout << "4. Mostrar todos los datos" << endl;
    cout << "5. Salir." << endl;
    cin >> n;
    
    switch (n) {
        case 1: {
            string x;
            int y;
            cout << "Ingrese una palabra: " ;
            cin >> x;
            cout << "Ingrese un numero: " ;
            cin >> y;        
            ht.insert(x, y);
            break;
        }

        case 2: {
            string x;
            cout << "Ingrese una palabra a buscar: " ;
            cin >> x;
            ht.search(x);
            break;
        }

        case 3: {
            string x;
            cout << "Ingrese una palabra a remover: " ;
            cin >> x;
            ht.remove(x);
            break;
        }

        case 4: {
            ht.display();
        }

        case 5: {
            cout << "Tenga un buen dia! " << endl;
            break;
        }

        default: {
            cout << "Numero ingresado fuera del rango.";
            break;
        }
    }
    } while (n != 5);
}

int main() {

menu();


}
