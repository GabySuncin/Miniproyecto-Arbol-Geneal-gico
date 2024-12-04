# MiniproyectoArbolGenealogico
Miniproyecto

¿En que consiste?
El miniproyecto es un arbol genealogico de una familia. Se utiliza especificamente arbol binario y no se utiliza librería "set" para realizarlo, sino que, en cambio, toda la estructura del codigo se maneja directamente con el uso de Nodos y punteros. 

Funciones:
Consta de 2 funciones principales y de 2 auxiliares. 

Funciones Principales:
1.Función Insertar Miembros: Es la funcion más importante debido a que es la que nos permite ingresar los miembros familiares al arbol genealógico. Esta se encarga de crear el nodo raiz y de por cada miembro crearle un nodo y asignarle la relación correspondiente. Tiene como parametros, el nodo raiz, el miembro que se desea ingresar, y el parentesco. Es una funcion de tipo "Por Valor" especificamente Node* , por lo que se regresa el nodo raiz actualizado, que sería el arbol actualizado. 
2.Función Imprimir Arbol: Esta funcion permite imprimir por niveles y de forma escalonada nuestro arbol genealógico creado. Tiene como parametros el nodo raiz, que es practicamente todo nuestro arbol hasta el momento y el segundo parametro es el nivel de inicio del arbol. La función es de tipo void, porque solo necesitamos leer, no necesitamos guardar o actualizar ningun dato. 

Funciones Auxiliares: 
1.Función MenuPrincipal: Despliega el las opciones de menu y guarda la opción elegida por el usuario. Es una funcion de tipo void, por lo que el parametro de la opcion se guarda por referencia. 
2.Función AskMember: Se encarga de recolectar los datos de cada miembro familiar, al ser una acción repetitiva decidí hacerla una función. Esta es de tipo void, por lo que el paramentro del miembro se guarda por referencia. 