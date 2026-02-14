
/* El objetivo es crear un programa donde se utilice una implementación propia de un objeto y su renderizado.

Para esto se debe saber utilizar coordenadas locales y sus correctas transformaciones a coordenadas globales 

Evitar el uso de matrices.

Utilizar raylib solo para:
La cámara
DrawPoint 3D
DrawLine 3D
DrawTriangle3D

Rúbrica entrega:

1-3:

El código debe estar completamente comentado. Esto significa:
En la primera línea de cada función debe decir 
1. Que hace la función 
Como lo hace
Ejemplo:
bool isPointInMesh( Vector3 point, Vector3 mesh){
//Esta funcion revisa si un punto dado se encuentra adentro de una mesh
//Para esto transforma el punto en local, y loopea por todos los planos de la mesh comparando el punto con las normales.
}

Por defecto, el objeto debe ser un cubo 

El código está correctamente separado en archivos

Se utilizan todas las funciones dadas

4:
Se crea un objeto el cual puede ser renderizado con líneas entre los vértices.

5: 
El objeto puede moverse a través del mundo con las flechas y puede ser rotado

+1 se usa la opción 2 para la rotación 

+1 se pueden crear varios objetos los cuales se guardan en un vector. Todos se pueden mover de manera independiente. Puedo remover objetos

+1 los objetos pueden escalar (cambiar su tamaño) según un Vector3 

+1 los objetos elijen sus vértices de manera aleatoria al ser creados a partir de un vector<vector<Vector3>> shapes.

+1 utiliza la definición IF_DEBUG para llamar los string de los objetos en el formato dado

Contiene al menos:
Cubo
Prisma
Dodecahedro

Código de ayuda:

Struct Object {

Vector3 pos;

//Option 1
Vector3 rot;

//Option 2
Vector3 up;
float rot;

Vector3 scale;

vector3<Vector3> vertices;

//Te ganas un besito extra si haces que cada figura tenga un color aleatorio (y que la actualmente seleccionada sea verde)
Color color;

Object(){
//Aquí viene como prisma triangular 
vertices[0] = Vector3 (0,0,0);
vertices[1] = Vector3 (1,0,0);
vertices[2] = Vector3 (0,1,0);
vertices[3] = Vector3 (0,0,1);
}

void draw();

std::string toString(){
 // El formato deb ser:
// pos: (0,0,0)
// scale: (0,0,0)
// rot vector: (0,0,0)
// rot angle: 0
// Vertices: {(0,0,0) , (0,0,0) , (0,0,0)}
}

}*/
#include "raylib.h"

void main()
{

}