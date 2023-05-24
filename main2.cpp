
#include "MatrizconVecores.cxx"
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


    grafo.recorridoPlano();
    // Output: A B C D E
    std::cout << std::endl;
    // Realizar una búsqueda DFS desde el vértice 'A'
    grafo.BusquedaDFS('A');
    // Output: A B C D E
    std::cout << std::endl;
    // Realizar una búsqueda BFS desde el vértice 'A'
    grafo.BusquedaBfs('A');
    std::cout << std::endl;

    std::vector<std::pair<char, char>> puentes = grafo.aristaPuente();

    // Imprimir las aristas puente
    std::cout << "Aristas puente encontradas:" << std::endl;
    for (const auto& puente : puentes) {
        std::cout << puente.first << " -> " << puente.second << std::endl;
    }



    std::vector<int> caminoEuler = grafo.algoritmoFleury();
    std::vector<char>vertices = grafo.getVertices();
    // Imprimir el camino de Euler
    std::cout << "Camino de Euler: ";
    for (int i = 0; i < caminoEuler.size(); i++) {
        std::cout << vertices[caminoEuler[i]] << " ";
    }
    std::cout << std::endl;



    // std::list<std::list<char>> componentes = grafo.componentesconectados();
    // // Recorrer e imprimir cada componente conectado
    // for (const auto& componente : componentes) {
    //     for (const auto& vertice : componente) {
    //         std::cout << vertice << " ";
    //     }
    //     std::cout << std::endl;
    // }


    //     //Obtener la matriz de adyacencia
    // int cantVertices = grafo.cantVertices();
    // std::vector<std::vector<int>> aristas = grafo.getAristas();
    // std::cout << "Matriz de adyacencia:" << std::endl;
    // for (int i = 0; i < cantVertices; i++) {
    //     for (int j = 0; j < cantVertices; j++) {
    //         std::cout << aristas[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // grafo.eliminarArista('A', 'C');
    // grafo.insertarArista('F', 'A',244);
    //         //Obtener la matriz de adyacencia
    // cantVertices = grafo.cantVertices();
    // aristas = grafo.getAristas();
    // std::cout << "Matriz de adyacencia:" << std::endl;
    // for (int i = 0; i < cantVertices; i++) {
    //     for (int j = 0; j < cantVertices; j++) {
    //         std::cout << aristas[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // grafo.eliminarVertice('A');

    // cantVertices = grafo.cantVertices();
    // aristas = grafo.getAristas();
    // std::cout << "Matriz de adyacencia:" << std::endl;
    // for (int i = 0; i < cantVertices; i++) {
    //     for (int j = 0; j < cantVertices; j++) {
    //         std::cout << aristas[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    Grafo<char, int> grafoe;
    grafoe.insertarVertice('A');
    grafoe.insertarVertice('B');
    grafoe.insertarVertice('C');
    grafoe.insertarVertice('D');
    // grafoe.insertarVertice('E');
    // grafoe.insertarVertice('F');



    grafoe.insertarArista('A', 'B', 10);
    grafoe.insertarArista('B', 'A', 10);
    // grafoe.insertarArista('A', 'E', 10);
    // grafoe.insertarArista('E', 'A', 10);
    // grafoe.insertarArista('B', 'C', 5);
    // grafoe.insertarArista('C', 'B', 5);
    // grafoe.insertarArista('C', 'A', 5);
    // grafoe.insertarArista('A', 'C', 5);
    // grafoe.insertarArista('C', 'F', 5);
    // grafoe.insertarArista('F', 'C', 5);
    // grafoe.insertarArista('D', 'A', 5);
    // grafoe.insertarArista('A', 'D', 5);
    // grafoe.insertarArista('E', 'D', 5);
    // grafoe.insertarArista('D', 'E', 5);
    // grafoe.insertarArista('E', 'C', 5);
    // grafoe.insertarArista('C', 'E', 5);
    // grafoe.insertarArista('F', 'E', 5);
    // grafoe.insertarArista('E', 'F', 5);

    grafoe.insertarArista('A', 'D', 10);
    grafoe.insertarArista('D', 'A', 10);
    grafoe.insertarArista('D', 'C', 10);
    grafoe.insertarArista('C', 'D', 10);
    grafoe.insertarArista('C', 'B', 10);
    grafoe.insertarArista('B', 'C', 10);
    grafoe.insertarArista('D', 'B', 10);
    grafoe.insertarArista('B', 'D', 10);
std::vector<int> eulerPath = grafo.algoritmoFleury();

    // Mostrar el camino Euleriano
    if (eulerPath.empty()) {
        std::cout << "No existe un camino Euleriano en el grafo." << std::endl;
    } else {
        std::cout << "Camino Euleriano: ";
        for (int i = eulerPath.size() - 1; i >= 0; i--) {
            std::cout << eulerPath[i] << " ";
        }
        std::cout << std::endl;
    }


    std::cout << std::endl;
    std::cout << "Prueba Dijsktra" << std::endl;

    Grafo<char, int> grafoDI;
    grafoDI.insertarVertice('s');
    grafoDI.insertarVertice('t');
    grafoDI.insertarVertice('x');
    grafoDI.insertarVertice('y');
    grafoDI.insertarVertice('z');

    grafoDI.insertarArista('s', 't', 10);
    grafoDI.insertarArista('s', 'y', 5);
    grafoDI.insertarArista('t', 'y', 2);
    grafoDI.insertarArista('t', 'x', 1);
    grafoDI.insertarArista('y', 't', 3);
    grafoDI.insertarArista('y', 'z', 2);
    grafoDI.insertarArista('y', 'x', 9);
    grafoDI.insertarArista('x', 'z', 4);
    grafoDI.insertarArista('z', 'x', 6); 
    grafoDI.insertarArista('z', 's', 6); 

    grafoDI.dijkstras('s');

    // grafoDI.longestPathDijkstra('s');

    return 0;
}
