#include <iostream> // Para entrada/salida (cin, cout)
#include <list> // Para usar listas enlazadas
#include <vector> // Para usar vectores dinámicos
#include <string> // Para usar strings

using namespace std;

int n; // Variable global para almacenar la opción del menú


class HashTable {
private:

// Número de "buckets" (espacios) en la tabla hash
    int capacity;

// Tabla hash representada como un vector de listas
// Cada posición del vector contiene una lista de pares (clave, valor)
    vector<list<pair<string, int>>> table;

// Función hash: convierte una clave (string) en un índice del vector
    int hashFunction (const string key) {
    int hashValue = 0;
        
    // Recorre cada carácter de la clave
    for (char ch: key) {  
        hashValue += ch;     // os valores ASCII de los caracteres
    }
    // Retorna el índice dentro del rango válido (0 a capacity-1)
    return hashValue % capacity; 
}

public:
// Constructor: inicializa la tabla con el tamaño especificado
HashTable (int size) : capacity (size) {
table.resize(capacity); // Crea 'capacity' buckets vacíos
}
// Inserta o actualiza un par clave-valor en la tabla
void insert (const string& key, int value) {
int index = hashFunction (key); // Calcula en qué bucket va

// Busca si la clave ya existe en ese bucket
for (auto& pair : table[index]) {
    if (pair.first == key) {
        pair.second = value;  // Si existe, actualiza el valor
        return;
    }
}
// Si no existe, agrega el nuevo par al final de la lista
table[index].emplace_back(key, value);
}

// Busca una clave y retorna su valor asociado
    int search (const string& key) {
        int index = hashFunction (key);  // Calcula en qué bucket buscar
        
        // Recorre todos los pares en ese bucket
        for (const auto& pair : table [index]) {
            if (pair.first == key) {
                return pair.second;  // Si encuentra la clave, retorna el valor
            }
        }
        return -1;  // Si no encuentra la clave, retorna -1
    }
    
    // Elimina un par clave-valor de la tabla
    void remove (const string& key) {
        int index = hashFunction(key);  // Calcula en qué bucket está
        auto& entries = table[index];   // Obtiene referencia a la lista del bucket
        
        // Recorre la lista usando iteradores
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->first == key) {
                entries.erase(it);  // Elimina la entrada encontrada
                return;
            }
        }
    }
    
    // Muestra todo el contenido de la tabla hash
    void display () {
        // Recorre cada bucket de la tabla
        for (int i = 0; i < capacity; ++i) {
            cout << "Bucket " << i << ": ";
            
            // Muestra todos los pares en ese bucket
            for (const auto &pair : table[i]) {
                cout << "(" << pair.first << ": " << pair.second << ") ";
            }
            cout << endl;  // Salta de línea después de mostrar un bucket completo
        }
    }
};

HashTable ht(100);  // Crea una tabla hash global con 100 buckets

// Función que muestra el menú interactivo
void menu() {
    do {
        // Muestra las opciones disponibles
        cout << "Menu para la utilizacion del metodo hash, presione: " << endl;
        cout << "1. Insertar datos" << endl;
        cout << "2. Buscar un dato" << endl;
        cout << "3. Remover un dato" << endl;
        cout << "4. Mostrar todos los datos" << endl;
        cout << "5. Salir." << endl;
        cin >> n;  // Lee la opción del usuario
        
        switch (n) {
            case 1: {  // INSERTAR
                string x;
                int y;
                cout << "Ingrese una palabra: ";
                cin >> x;
                cout << "Ingrese un numero: ";
                cin >> y;        
                ht.insert(x, y);  // Inserta el par en la tabla
                break;
            }
            case 2: {  // BUSCAR
                string x;
                cout << "Ingrese una palabra a buscar: ";
                cin >> x;
                int resultado = ht.search(x);  // Busca la palabra
                
                // Muestra el resultado de la búsqueda
                if (resultado != -1)
                    cout << "Valor encontrado: " << resultado << endl;
                else
                    cout << "Palabra no encontrada" << endl;
                break;
            }
            case 3: {  // REMOVER
                string x;
                cout << "Ingrese una palabra a remover: ";
                cin >> x;
                ht.remove(x);  // Elimina la palabra de la tabla
                break;
            }
            case 4: {  // MOSTRAR TODO
                ht.display();  // Muestra el contenido completo de la tabla
                break;
            }
            case 5: {  // SALIR
                cout << "Tenga un buen dia! " << endl;
                break;
            }
            default: {  // OPCIÓN INVÁLIDA
                cout << "Numero ingresado fuera del rango." << endl;
                break;
            }
        }
    } while (n != 5);  // Repite el menú hasta que el usuario elija salir
}

int main() {
    menu();  // Inicia el programa mostrando el menú
    return 0;
}
