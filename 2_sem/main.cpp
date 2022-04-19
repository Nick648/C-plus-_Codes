#include <stdlib.h>
#include <stdio.h>
#include "Appl.h"
int main()
{
	Appl ob_app;
	ob_app.bild_tree_objects(); // построение дерева объектов
	return ob_app.exec_app(); // запуск системы
	//return(0);
}
