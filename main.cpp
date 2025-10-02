#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class HashTable {
    private:
    
    int capacity;
    
    vector<list<pair<string, int>>> table;
    
    int hashFunction (const string& key){
        int hashValue = 0;
        for(char ch: key){
            hashValue += ch;
        }
        return hashValue % capacity;
    }
    
    public:
    
    HashTable(int size) : capacity (size){
        table.resize (capacity);
    }
    
    void insert (const string& key, int value){
        int index = hashFunction (key);
        
        for (auto& pair : table [index]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }
    
    int search (const string& key){
        int index = hashFunction(key);
        for (const auto& pair: table[index]){
            if (pair.first ==key){
                return pair.second;
            }
        }
        return -1;
    }
    
    void remove (const string&key){
        int index = hashFunction(key);
        auto& entries = table[index];
        for (auto it = entries.begin(); it != entries.end(); ++it){
            if(it->first == key){
                entries.erase(it);
                return;
            }
        }
    }
    
    void display (){
        for (int i=0; i<capacity; ++i){
            cout << "Bucket "<< i << ": ";
            for (const auto& pair : table[i]){
                cout << " {"<<pair.first<<": "<<pair.second<<"} ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int opcion;
    string key;
    int value;
    
    HashTable tabla(10);

    do {
        cout << "\n===== MENU HASH TABLE =====" << endl;
        cout << "1. Agregar (insertar)" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: 
                cout << "Ingresa clave (string): ";
                cin >> key;
                cout << "Ingresa valor (int): ";
                cin >> value;
                tabla.insert(key, value);
                cout << "Elemento agregado correctamente." << endl;
                break;

            case 2: 
                cout << "Ingresa clave a eliminar: ";
                cin >> key;
                tabla.remove(key);
                cout << "Si la clave existia, fue eliminada." << endl;
                break;

            case 3: 
                cout << "Ingresa clave a buscar: ";
                cin >> key;
                value = tabla.search(key);
                if(value != -1)
                    cout << "Valor encontrado: " << value << endl;
                else
                    cout << "Clave no encontrada." << endl;
                break;

            case 4:
                cout << "\nContenido de la tabla:\n";
                tabla.display();
                break;

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    } while(opcion != 5);

    return 0;
}