
#include "GrafoMatriz.cxx"
#include <iostream>
#include <list>
int main(int argc, char const *argv[]) {
    Grafo<char, int> grafo;

    // Insertar vértices
    grafo.insertarVertice('A');
    grafo.insertarVertice('B');
    grafo.insertarVertice('C');
    grafo.insertarVertice('D');
    grafo.insertarVertice('E');
    grafo.insertarVertice('F');
    grafo.insertarVertice('G');
    grafo.insertarVertice('O');
    grafo.insertarVertice('Y');
    grafo.insertarVertice('v');


    //puentes 

    

    //fin puentes
    grafo.insertarArista('A', 'B', 10);
    grafo.insertarArista('A', 'C', 5);
    grafo.insertarArista('A', 'D', 5);
    grafo.insertarArista('D', 'A', 5);
    grafo.insertarArista('D', 'O', 5);
    grafo.insertarArista('B', 'C', 10);
    // Insertar aristas



    // grafo.insertarArista('A', 'B', 10);
    // grafo.insertarArista('B', 'A', 10);
    // grafo.insertarArista('A', 'C', 5);
    // grafo.insertarArista('C', 'A', 5);
    // grafo.insertarArista('A', 'E', 8);
    // grafo.insertarArista('E', 'A', 8);
    // grafo.insertarArista('B', 'D', 3);
    // grafo.insertarArista('D', 'B', 3);
    // grafo.insertarArista('B', 'F', 3);
    // grafo.insertarArista('F', 'B', 3);
    // grafo.insertarArista('F', 'E', 3);
    // grafo.insertarArista('E', 'F', 3);
    // grafo.insertarArista('C', 'G', 3);
    // grafo.insertarArista('G', 'C', 3);
    // grafo.insertarArista('O', 'Y', 3);
    // grafo.insertarArista('v', 'Y', 3);


        // Obtener la matriz de adyacencia
    int cantVertices = grafo.cantVertices();
    int** aristas = grafo.getAristas();
    std::cout << "Matriz de adyacencia:" << std::endl;
    for (int i = 0; i < cantVertices; i++) {
        for (int j = 0; j < cantVertices; j++) {
            std::cout << aristas[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "busqeuda:" << std::endl;
    grafo.BusquedaDFS('D');
    std::cout << "busqeuda:" << std::endl;
    grafo.BusquedaBfs('D');

    std::cout << "bucubnentes:" << std::endl;
    std::list<std::list<char>> componentes = grafo.componentesconectados();

    // Iterar sobre los componentes conectados e imprimirlos
    for (const auto& componente : componentes) {
        for (const auto& vertice : componente) {
            std::cout << vertice << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::pair<char, char>> puentes = grafo.aristaPuente();

    // Imprimir las aristas puente
    std::cout << "Aristas puente encontradas:" << std::endl;
    for (const auto& puente : puentes) {
        std::cout << puente.first << " -> " << puente.second << std::endl;
    }

    std::cout << std::endl;
    // Obtener cantidad de vértices y aristas
//     int cantVertices = grafo.cantVertices();
//     int cantAristas = grafo.cantAristas();
//     std::cout << "Cantidad de vertices: " << cantVertices << std::endl;
//     std::cout << "Cantidad de aristas: " << cantAristas << std::endl;

//     // Obtener los vértices
//     std::vector<char> vertices = grafo.getVertices();
//     std::cout << "Vertices: ";
//     for (char v : vertices) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;

//     // Obtener la matriz de adyacencia
//     int** aristas = grafo.getAristas();
//     std::cout << "Matriz de adyacencia:" << std::endl;
//     for (int i = 0; i < cantVertices; i++) {
//         for (int j = 0; j < cantVertices; j++) {
//             std::cout << aristas[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// std::cout << "busqeuda:" << std::endl;
//     grafo.BusquedaDFS('B');

//     // Eliminar una arista
//     grafo.eliminarArista('A', 'B');

//     // Eliminar un vértice
//     grafo.eliminarVertice('C');

//     // Obtener la matriz de adyacencia actualizada

//     std::cout << "Matriz de adyacencia actualizada:" << std::endl;
//     for (int i = 0; i < grafo.cantVertices(); i++) {
//         for (int j = 0; j < grafo.cantVertices(); j++) {
//             std::cout << grafo.getAristas()[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     grafo.insertarVertice('Z');
//     grafo.insertarArista('Z', 'B',244);
//     grafo.insertarArista('D', 'Z',34);
//     grafo.eliminarVertice('A');
//     grafo.recorridoPlano();
//     std::cout << "Matriz de adyacencia actualizada:" << std::endl;
//     for (int i = 0; i < grafo.cantVertices(); i++) {
//         for (int j = 0; j < grafo.cantVertices(); j++) {
//             std::cout << grafo.getAristas()[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }


//     grafo.recorridoPlano();
//     grafo.eliminarVertice('B');
//     std::cout << "Matriz de adyacencia actualizada:" << std::endl;
//     for (int i = 0; i < grafo.cantVertices(); i++) {
//         for (int j = 0; j < grafo.cantVertices(); j++) {
//             std::cout << grafo.getAristas()[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
    
    

    return 0;
}
