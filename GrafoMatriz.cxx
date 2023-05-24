//Matriz de adyacencia
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<list>

template <class T, class U> 
class Grafo {

private:
	std::vector<T> vertices; //lista de vertices que me dan el indice en la matriz
	U** aristas; //definir la matriz con doble apuntador (memoria dinámica)
public:

	//Grafo();//constructor

	Grafo() {
    aristas = nullptr;
	}
	void setVertices(std::vector<T> v);//set para los vertices 
	void setAristas(U** a);//set para las aristas
	std::vector<T> getVertices(){return vertices;}//get para los vertices 
	U** getAristas() {
    return aristas;
	}//get para las aristas

//función que define la cantidad de vertices, retorna un entero 
	int cantVertices() { return vertices.size(); }

//función que define la cantidad de aristas, retorna un entero 
//recorre la matriz y si existe un peso aumenta el contador de aristas
	int cantAristas() {
		int suma = 0;
		for (int i = 0; i < cantVertices(); i++) {
			for (int j = 0; j < cantVertices(); j++) {
				if (*(*(aristas+i)+j) != 0)  suma++;
			}
		}
		return suma;
	}

//función que busca un vertice retorna la posición, en el vector inicial
//T debe poderse comparar, si es un TAD es necesario sobrecargarlo o hacer una función que compare
	int buscarVertice(T vert) {
		int ind = -1;
		for (int i = 0; i < cantVertices(); i++) {
			if (vertices[i] == vert)  ind = i;
		}
		return ind;
	}

//función para insertar un vertice retorna un bool
	bool insertarVertice(T vert) {
		bool res = false;//dice si lo pudo insertar o si ya estaba
		if (buscarVertice(vert) == -1) { 
			vertices.push_back(vert); //aumenta el vector de vertices
			U** nmatriz = new U*[cantVertices()]; //crea una nueva matriz del tamaño que ahora tiene el vector de vertices
			for (int i = 0; i < cantVertices(); i++) {
				*(nmatriz+i) = new U[cantVertices()];
			}
			for (int i = 0; i < cantVertices()-1; i++) {
				for (int j = 0; j < cantVertices()-1; j++) {
					*(*(nmatriz+i)+j) = *(*(aristas+i)+j); //copia la matriz anterior
				}
			}
			for (int i = 0; i < cantVertices(); i++) { //llenas la última fila y col con 0 (sin isertar aristas)
				nmatriz[i][cantVertices() - 1] = 0;
                nmatriz[cantVertices() - 1][i] = 0;
			}
			for (int i = 0; i < cantVertices()-1; i++) { //borrar la matriz anterior
				delete[] *(aristas+i);
			}
			delete[] aristas;
			aristas = nmatriz; //asignar la nueva matriz en aristas
		}
		return res;
	}

  //función que inserta una arista retora un bool
	bool insertarArista(T ori, T des, U cos) { 
		bool res = false;
		int i_ori = buscarVertice(ori);//buscar que los vertices existen y obtener sus posiciones
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			if (*(*(aristas+i_ori)+i_des) == 0) {//no existía y asigna el costo, si existía no lo cambia
				*(*(aristas+i_ori)+i_des) = cos;
				res = true;
			}
		}
		return res;
	}

//función que busca la arista y retornar el costo (positivo)
	U buscarArista(T ori, T des) {
		U res = -1;
		int i_ori = buscarVertice(ori); //busca los indices de los vertices
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			res = *(*(aristas+i_ori)+i_des); //busca el valor que está en esas posiciones
		}
		return res;
	}

//función que elimina el vertice retorna un bool
//similar a: 	bool insertarVertice(T vert)
//se crea una matriz más pequeña copiar los datos menos los que están en esa posición
    
//función que elimina la arista retorna un bool
	bool eliminarArista(T ori, T des) {
		bool res = false;
		int i_ori = buscarVertice(ori); //busca los indices de la matriz
		int i_des = buscarVertice(des);
		if ( i_ori != -1 && i_des != -1 ) {
			*(*(aristas+i_ori)+i_des) = 0; //remplaza el costo anterior en esa posición por un 0
			res = true;
		}
		return res;
	}


	bool eliminarVertice(T vert) {
		bool res = false;
		int vertPos = buscarVertice(vert);
		int cantidadanterior=cantVertices();
		if (vertPos != -1) {
			vertices.erase(vertices.begin() + vertPos); // Eliminar el vértice del vector de vértices

			// Crear una nueva matriz de adyacencia más pequeña
			U** newAristas = new U*[cantVertices() ];
			for (int i = 0; i < cantVertices() ; i++) {
				newAristas[i] = new U[cantVertices() ];
			}

			int newRow = 0;
			int newCol = 0;
			for (int i = 0; i < cantidadanterior; i++) {
				if (i != vertPos) {
					newCol = 0;
					for (int j = 0; j < cantidadanterior; j++) {
						if (j != vertPos) {
							newAristas[newRow][newCol] = aristas[i][j];
							//std::cout << "en la pocicion matriz nueva "<< newRow<< ","<<newCol << "  de la matrixz vieja "<< i<<"," << j<< " el valor aristas[i][j]"<<std::endl;
							newCol++;
							
						}
					}
					newRow++;
				}
			}

			// Eliminar la fila y columna correspondientes al vértice eliminado en la nueva matriz
			// for (int i = 0; i < cantVertices() - 1; i++) {
			// 	for (int j = vertPos; j < cantVertices() - 1; j++) {
			// 		newAristas[i][j] = newAristas[i][j + 1];
			// 	}
			// }
			// for (int i = vertPos; i < cantVertices() - 1; i++) {
			// 	for (int j = 0; j < cantVertices() - 1; j++) {
			// 		newAristas[i][j] = newAristas[i + 1][j];
			// 	}
			// }

			// Eliminar la matriz de adyacencia anterior
			for (int i = 0; i < cantVertices(); i++) {
				delete[] aristas[i];
			}
			delete[] aristas;

			// Actualizar el puntero a la nueva matriz de adyacencia
			aristas = newAristas;

			res = true;
		}

		return res;
	}

	void recorridoPlano(){
		for (char v : vertices) {
        	std::cout << v << " ";
    	}
	}
	void BusquedaDFS(T Inicio){

		if(vertices.empty()){	

			std::cout << " el Grafo esta vacio "<<std::endl;
			return;
		}

		int indiceIni  = buscarVertice(Inicio);
		if(indiceIni == -1 ){

			std::cout << "El vértice de inicio no existe en el grafo." << std::endl;
        	return;

		}


		std::vector<bool> visitados(vertices.size(), false);

		std::stack<int> pila;

		pila.push(indiceIni);
		//visitados[indiceIni] = true;

		while (!pila.empty())
		{
			int actual = pila.top();
        	pila.pop();
			if(visitados[actual] == false)
				std::cout << vertices[actual] << " ";

			visitados[actual] = true;
			std::vector<int> adyacentes = obtenerAdyacentes(actual);

			for (int i = adyacentes.size() -1; i >= 0; i--) {
				int adyacente = adyacentes[i];
				if (!visitados[adyacente]) {
					// Marcar el vértice adyacente como visitado y colocarlo en la pila
					
					pila.push(adyacente);
				}
			}

		}
		
		std::cout << std::endl;

	}

	void BusquedaBfs(T Inicio){
		
		if(vertices.empty()){	

			std::cout << " el Grafo esta vacio "<<std::endl;
			return;
		}

		int indiceIni  = buscarVertice(Inicio);
		if(indiceIni == -1 ){

			std::cout << "El vértice de inicio no existe en el grafo." << std::endl;
        	return;

		}


		std::vector<bool> visitados(vertices.size(), false);

		std::queue<int> cola;


		cola.push(indiceIni);
		while (!cola.empty())
		{
			int actual = cola.front();
        	cola.pop();
			if(visitados[actual] == false)
				std::cout << vertices[actual] << " ";

			visitados[actual] = true;
			std::vector<int> adyacentes = obtenerAdyacentes(actual);

			for (int i = 0; i < adyacentes.size(); i++) {
				int adyacente = adyacentes[i];
				if (!visitados[adyacente]) {
					// Marcar el vértice adyacente como visitado y colocarlo en la pila
					
					cola.push(adyacente);
				}
			}

		}

		std::cout << std::endl;
	}

	std::list<std::list<T>> componentesconectados() {
		std::vector<bool> visitados(vertices.size(), false);
		std::list<std::list<T>> componentes;

		for (int i = 0; i < vertices.size(); i++) {
			if (!visitados[i]) {
				std::list<T> componente;
				std::stack<int> pila;
				pila.push(i);

				while (!pila.empty()) {
					int actual = pila.top();
					pila.pop();

					if (!visitados[actual]) {
						componente.push_back(vertices[actual]);
						visitados[actual] = true;
						std::vector<int> adyacentes = obtenerAdyacentes(actual);

						for (int i = adyacentes.size() - 1; i >= 0; i--) {
							int adyacente = adyacentes[i];
							if (!visitados[adyacente]) {
								pila.push(adyacente);
							}
						}
					}
				}

				componentes.push_back(componente);
			}
		}

		return componentes;
	}



	std::vector<int> obtenerAdyacentes(int v) {
		std::vector<int> adyacentes;

		// Recorrer la fila correspondiente al vértice en la matriz de adyacencia
		for (int i = 0; i < vertices.size(); i++) {
			if (aristas[v][i] != 0) {
				adyacentes.push_back(i);
			}
		}

		// std::cout << "inicio: " << v <<" " << "adyacente: ";
		// for(auto f : adyacentes){
		// 	std::cout <<vertices[f]<< " ";
		// }
		// std::cout <<std::endl;
		return adyacentes;
	}

	//aristas puente (retorne un vector que diga para cada arista si es o no puente)
	//aristas puente (retorna un vector que contiene las aristas puente como pares de vértices)
	std::vector<std::pair<T, T>> aristaPuente() {
		std::vector<std::pair<T, T>> puentes; // Vector de puentes
		std::vector<bool> visitados(vertices.size(), false);
		std::vector<int> tiempos(vertices.size(), -1); // Tiempo de descubrimiento para cada nodo
		std::vector<int> tiemposMin(vertices.size(), -1); // Tiempo mínimo alcanzable desde cada nodo
		int tiempo = 0; // Variable para llevar el tiempo de descubrimiento

		for (int i = 0; i < cantVertices(); i++) {
			if (!visitados[i]) {
				dfsAristaPuente(i, -1, visitados, tiempos, tiemposMin, tiempo, puentes);
			}
		}

		return puentes;
	}

	void dfsAristaPuente(int nodo, int padre, std::vector<bool>& visitados, std::vector<int>& tiempos,
		std::vector<int>& tiemposMin, int& tiempo, std::vector<std::pair<T, T>>& puentes) {
		visitados[nodo] = true;
		tiempos[nodo] = tiempo;
		tiemposMin[nodo] = tiempo;
		tiempo++;

		for (int i = 0; i < vertices.size(); i++) {
			if (aristas[nodo][i] != 0) {
				if (!visitados[i]) {
					dfsAristaPuente(i, nodo, visitados, tiempos, tiemposMin, tiempo, puentes);
					tiemposMin[nodo] = std::min(tiemposMin[nodo], tiemposMin[i]);

					if (tiempos[nodo] < tiemposMin[i]) {
						puentes.push_back(std::make_pair(vertices[nodo], vertices[i]));
					}
				}
				else if (i != padre) {
					tiemposMin[nodo] = std::min(tiemposMin[nodo], tiempos[i]);
				}
			}
		}
	}


};
