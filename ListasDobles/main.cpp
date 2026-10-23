int main() {
    ListaDoble lista;
    int opcion, dato, donde;

    do {
        cout << "\n===== LISTA DOBLE =====" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Imprimir" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Dato a insertar: ";
                cin >> dato;
                cout << "1. Al inicio  2. Al final: ";
                cin >> donde;
                if (donde == 1)
                    lista.insertarInicio(dato);
                else
                    lista.insertarFinal(dato);
                break;

            case 2:
                cout << "Dato a eliminar: ";
                cin >> dato;
                lista.eliminar(dato);
                break;

            case 3: {
                cout << "Dato a buscar: ";
                cin >> dato;
                int pos = lista.buscar(dato);
                if (pos != -1)
                    cout << "El dato " << dato << " SI esta en la lista (posicion " << pos << ")." << endl;
                else
                    cout << "El dato " << dato << " NO esta en la lista." << endl;
                break;
            }

            case 4:
                lista.imprimirAdelante();
                lista.imprimirAtras();
                break;

            case 5:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 5);

    return 0;
}