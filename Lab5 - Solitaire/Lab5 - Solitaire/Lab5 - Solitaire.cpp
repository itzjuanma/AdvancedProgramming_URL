#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;



struct Card_Node {
	char color;
	char suit;
	int value; // Valores = 1 para A, 11 para J, 12 para Q, 13 para K
	bool isup; // true para UP, false para DOWN
	Card_Node* next;
};

struct List_Node {
	int listno;//lista de tablero y base de cartas tienen un indice
	List_Node* next;
	Card_Node* cards;
};

struct List {
	Card_Node* top_head;//encabezado de baraja
	List_Node* foundation_head;//primeros puntos de la lista base
	List_Node* board_head;//primeros puntos de la lista tablero
	FILE* fptr;

	void create();// Incluye crear listabaraja, listabase y lista tablero
	void create_toplist();
	void create_boardlists();
	void create_foundlists();
	void printkart(Card_Node* kart);// imprime data del nodo 
	void printlists();// Imprimir todas las listas
	void printmenu();//Imprimir menu de elecciones
	bool addcardtolist(List_Node* selectedlist, Card_Node* transferedcard, int whichlisttype);//Agrega la carta transferida a la lista seleccionada, cuyo tipo de lista es ingresado por el programa
	void goster_TopToFoundation();//Obtiene las entradas y llama a la funcion relacionada
	void TopToFoundation(char s_color, char s_suit, int s_value);// Mueve una carta de la baraja a la base de cartas
	void goster_TopToBoard();
	void TopToBoard(int listindex, char s_color, char s_suit, int s_value);//Mueve una carta de la baraja al tablero
	void goster_BoardToBoard();
	void BoardToBoard(int fromwhere, int towhere, char s_color, char s_suit, int s_value);//Mueve las cartas de un mazo a otro
	void goster_BoardToFoundation();
	void BoardToFoundation(int fromwhere);//Mueve la ultima carta de un mazo a la base de cartas
	void islem_yap();//Requiere la seleccion del menu y llama a las funciones correspondientes
	bool istopempty, isboardempty;// Controla el fin del juego
	void clear_screen();
	void close();
};

List islem;
using namespace std;

int main()
{
	char secim;
	islem.create();
	if (!islem.fptr)//Si no encuentra el archivo solitario.txt el programa se cierra
		return 0;

	islem.istopempty = false;//Si la baraja esta vacia el valor se vuelve verdadero
	islem.isboardempty = false;//Si el trablero esta vacio el valor se vuelve verdadero

	while (1) {
		islem.printlists();
		islem.printmenu();
		cin >> secim;
		cin.ignore(10000, '\n');

		if (secim == '1') {
			islem.goster_TopToFoundation();
			cin.ignore(10000, '\n');
			getchar();
		}
		else if (secim == '2') {
			islem.goster_TopToBoard();
			cin.ignore(10000, '\n');
			getchar();
		}
		else if (secim == '3') {
			islem.goster_BoardToBoard();
			cin.ignore(10000, '\n');
			getchar();
		}
		else if (secim == '4') {
			islem.goster_BoardToFoundation();
			cin.ignore(10000, '\n');
		}
		else if (secim == '9') {
			islem.close();
			printf("\n\nEl juego se cierra y todas las cartas son borradas de la memoria. Presiona Enter para salir");
			cin.ignore(10000, '\n');
			getchar();
			break;
		}

		else
			cout << "Seleccion Invalida" << endl;

		if (!islem.top_head)// Revisa si la baraja esta vacia o no
			islem.istopempty = true;

		List_Node* traverse;
		traverse = islem.board_head;
		int counter = 0;
		while (traverse) {//Revisa si el tablero esta vacio o no
			if (!traverse->cards)
				counter++;
			traverse = traverse->next;
			if (counter == 7)// contador es igual 7 si todo el tablero esta vacio
				islem.isboardempty = true;
		}

		/*Cuando el juego se completa envia un mensaje al usuario*/
		if (islem.isboardempty && islem.istopempty) {//Para el ciclo while cuando el tablero y la baraja estan vacios
			printf("\n\n\n\t\t\t HAS GANADO!!!! FELICIDADES!\n");// 
			printf("\t\t\tHAS GANADO!!!! FELICIDADES!\n");
			printf("\t\t\tHAS GANADO!!!! FELICIDADES!\n");
			printf("\nTodas las cartas se borran de la memoria. presione ENTER");
			cin.ignore(1000, '\n');
			islem.close();
			getchar();
			break;
		}
	}

	return 0;
}

void List::create() {
	fptr = fopen("solitario.txt", "r+");
	if (!fptr) {
		cout << "El archivo 'solitario.txt' no se encuentra, el programa se cerrara." << endl;
		getchar();
		return;
	}
	fseek(fptr, 0, SEEK_SET);
	create_toplist();
	create_boardlists();
	create_foundlists();
}//Finaliza funcion crear

void List::create_toplist() {
	Card_Node* newnode, * final;
	char tempcolor, tempsuit, tempvalue[4], tempisup[4], garbage[10];//los valores temporales de la carta se cambiaran a enteros
	top_head = NULL;

	while (1) {//Este ciclo crea la lista de baraja enlasada con las listas
		newnode = new Card_Node;
		newnode->next = NULL;
		fscanf(fptr, "%c", &tempcolor);
		if (tempcolor == '*') {//El primer asterisco se lee
			fscanf(fptr, "%6c", garbage);//pasa otros cinco asteriscos y va a una nueva linea
			break;
		}
		else
			newnode->color = tempcolor;

		fscanf(fptr, " %c %s %s ", &tempsuit, tempvalue, tempisup);
		newnode->suit = tempsuit;

		/*Cambia el tipo de valor de arreglo de caracteres a enteros*/
		if (tempvalue[0] == 'A')	newnode->value = 1;
		else if (tempvalue[0] == 'J')newnode->value = 11;
		else if (tempvalue[0] == 'Q')newnode->value = 12;
		else if (tempvalue[0] == 'K')newnode->value = 13;
		else
			sscanf(tempvalue, "%d", &newnode->value);


		if (strcmp(tempisup, "Up") == 0)
			newnode->isup = true;
		if (strcmp(tempisup, "Down") == 0)
			newnode->isup = false;

		if (top_head == NULL) {//añade el primer nodo a la lista de baraja
			top_head = newnode;
			final = top_head;
		}
		else {//añade un nodo a una lista no vacia
			final->next = newnode;
			final = final->next;
		}
	}
}

void List::create_boardlists() {
	Card_Node* newnode, * final;//El punto final al ultimo nodo de cartas
	List_Node* newboardlist, * boardlist_final;//El punto del tablero al ultimo nodo del tablero
	char tempcolor, tempsuit, tempvalue[4], tempisup[8], garbage[10];

	int index = 1;//Indice que representa el inicio de la lista tablero

	newboardlist = new List_Node;//Crea el primer nodo del tablero
	board_head = newboardlist;
	boardlist_final = newboardlist;
	newboardlist->listno = index++;
	newboardlist->next = NULL;
	newboardlist->cards = NULL;

	while (!feof(fptr)) {//El ciclo crea las listas enlasadas al tablero
		newnode = new Card_Node;
		newnode->next = NULL;
		fscanf(fptr, "%c", &tempcolor);
		if (tempcolor == '*') {
			fscanf(fptr, "%6c", garbage);
			newboardlist = new List_Node;
			newboardlist->listno = index++;
			newboardlist->next = NULL;
			newboardlist->cards = NULL;
			boardlist_final->next = newboardlist;
			boardlist_final = boardlist_final->next;
			continue;
		}
		else
			newnode->color = tempcolor;

		fscanf(fptr, " %c %s %s ", &tempsuit, tempvalue, tempisup);
		newnode->suit = tempsuit;
		if (tempvalue[0] == 'A')	newnode->value = 1;
		else if (tempvalue[0] == 'J')newnode->value = 11;
		else if (tempvalue[0] == 'Q')newnode->value = 12;
		else if (tempvalue[0] == 'K')newnode->value = 13;
		else
			sscanf(tempvalue, "%d", &newnode->value);

		if (strcmp(tempisup, "Up") == 0)
			newnode->isup = true;
		if (strcmp(tempisup, "Down") == 0)
			newnode->isup = false;

		if (boardlist_final->cards == NULL) {
			boardlist_final->cards = newnode;
			final = boardlist_final->cards;
		}
		else {
			final->next = newnode;
			final = final->next;
		}
	}
}

void List::create_foundlists() {
	foundation_head = NULL;
	List_Node* newfoundlist, * foundlist_final;
	int index = 1;// Indice de espadas = 1, Indice de corazones = 2, Diamantes = 3, Treboles = 4

	/*Inicia la lista de espadas*/
	newfoundlist = new List_Node;
	newfoundlist->cards = NULL;
	newfoundlist->next = NULL;
	newfoundlist->listno = index++;
	foundation_head = newfoundlist;
	foundlist_final = newfoundlist;

	/*Inicia las otras tres listas*/
	for (int i = 0; i < 3; i++) {
		newfoundlist = new List_Node;
		newfoundlist->cards = NULL;
		newfoundlist->next = NULL;
		newfoundlist->listno = index++;
		foundlist_final->next = newfoundlist;
		foundlist_final = foundlist_final->next;
	}
}

void List::printkart(Card_Node* kart) {
	if (!kart->isup) {//Esconde la carta si esta boca abajo
		printf("X");
		return;
	}
	char a;
	if (kart->value == 1) a = 'A';
	else if (kart->value == 11) a = 'J';
	else if (kart->value == 12) a = 'Q';
	else if (kart->value == 13) a = 'K';
	else a = '\0';

	if (!a)printf("%c,%c,%d", kart->color, kart->suit, kart->value);
	else printf("%c,%c,%c", kart->color, kart->suit, a);
}

void List::printlists() {
	clear_screen();
	Card_Node* ct[7];
	Card_Node* foundct[4];
	Card_Node* topct;
	List_Node* listtraverse;


	cout << "Baraja:" << endl;
	topct = top_head;
	while (topct) {
		printkart(topct);
		printf("|");
		topct = topct->next;
	}

	cout << endl << "\nLista de tablero:" << endl;
	for (int i = 1; i < 8; i++)
		cout << i << ".List\t";
	cout << endl;

	listtraverse = board_head;
	for (int i = 0; i < 7; i++) {
		ct[i] = listtraverse->cards;
		listtraverse = listtraverse->next;
	}

	/*Imprime el trablero de las cartas*/
	for (int i = 0; i < 19; i++) {//El ciclo recorre el tablero y coloca las cartas boca abajo y boca arriba 
		for (int j = 0; j < 7; j++)
		{
			if (ct[j]) {//Si ct[j] no es nulo, imprime y pasa al siguiente nodo
				printkart(ct[j]);
				printf("\t");
				ct[j] = ct[j]->next;
			}
			else//Si es nulo, imprime un espacio
				printf("\t");
		}
		if (ct[0] || ct[1] || ct[2] || ct[3] || ct[4] || ct[5] || ct[6])
			printf("\n");//Si la ultima carta no es nula, va una nueva linea
		else
			break;//Si todas las cartas en una linea son nulos, rompe el ciclo for
	}

	cout << endl << "Base de cartas:" << endl;
	cout << "Espadas\tCorazones\tDiamantes\tTreboles" << endl;

	listtraverse = foundation_head;
	for (int i = 0; i < 4; i++) {
		foundct[i] = listtraverse->cards;
		listtraverse = listtraverse->next;
	}

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (foundct[j]) {
				printkart(foundct[j]);
				printf("\t");
				foundct[j] = foundct[j]->next;
			}
			else
				printf("\t");
		}
		if (foundct[0] || foundct[1] || foundct[2] || foundct[3])
			printf("\n");
		else
			break;
	}
	printf("\n\n");
}

void List::printmenu() {
	cout << "Seleccione una opcion:" << endl;
	cout << "\t1. Seleccionar de la baraja a la base de cartas" << endl;
	cout << "\t2. Seleccionar de la baraja al tablero" << endl;
	cout << "\t3. Mover en el tablero" << endl;
	cout << "\t4. Mover del tablero a la Base de cartas" << endl;
	cout << "Seleccione una opcion (1, 2, 3, or 4), (Presiones 9 para salir):";
}

bool List::addcardtolist(List_Node* selectedlist, Card_Node* transferedcard, int whichlisttype) {
	Card_Node* cardtraverser;
	cardtraverser = selectedlist->cards;
	if (whichlisttype == 1) {
		if (cardtraverser == NULL && transferedcard->value == 13) {//Si la lista esta vacia el valor de la carta debe ser K=13
			selectedlist->cards = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
		if (!cardtraverser)//Solo puede ser nulo si el valor de la carta es K=13
			return false;
		while (cardtraverser->next)
			cardtraverser = cardtraverser->next;

		if (!cardtraverser->isup) {//Si la carta esta boca abajo, el color y el valor de la carta no importa
			cardtraverser->next = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
		if (cardtraverser->isup)//Si la carta esta boca arriba, el color y el valor de la carta son importantes
			if (!(transferedcard->color == cardtraverser->color))//Si el color entre dos cartas son diferentes 
				if (cardtraverser->value - transferedcard->value == 1) {
					cardtraverser->next = transferedcard;
					transferedcard->next = NULL;
					return true;
				}
	}

	if (whichlisttype == 2) {
		if (cardtraverser == NULL && transferedcard->value == 1) {//Si la lista esta vacia el valor debe de ser A=1
			selectedlist->cards = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
		if (!cardtraverser)
			return false;

		while (cardtraverser->next)
			cardtraverser = cardtraverser->next;
		if (transferedcard->value - cardtraverser->value == 1) {//Si la lista no esta vacia, el ultimo valor de la lista - el valor de las cartas deben ser 1
			cardtraverser->next = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
	}

	if (whichlisttype == 3) {
		if (cardtraverser == NULL && transferedcard->value == 13) {//Si la lista esta vacia el valor de las cartas deben de ser K=13
			selectedlist->cards = transferedcard;
			return true;
		}
		if (!cardtraverser)
			return false;
		while (cardtraverser->next)
			cardtraverser = cardtraverser->next;

		if (!cardtraverser->isup) {//Si la carta esta boca abajo, el color y el valor entre cartas si importa
			cardtraverser->next = transferedcard;
			return true;
		}
		if (cardtraverser->isup)//Si la carta esta boca arriba, el color y el valor entre cartas son importantes
			if (!(transferedcard->color == cardtraverser->color))//Si el color entre dos cartartas adyacentes son diferentes
				if (cardtraverser->value - transferedcard->value == 1) {//list's last value - transfered card's value - must be 1
					cardtraverser->next = transferedcard;
					return true;
				}
	}
	if (whichlisttype == 4) {
		if (cardtraverser == NULL && transferedcard->value == 1) {//Si la lista esta vacia el valor debe ser A=1
			selectedlist->cards = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
		if (!cardtraverser)
			return false;

		while (cardtraverser->next)
			cardtraverser = cardtraverser->next;
		if (transferedcard->value - cardtraverser->value == 1) {
			cardtraverser->next = transferedcard;
			transferedcard->next = NULL;
			return true;
		}
	}

	return false;
}

void List::goster_TopToFoundation() {// wants input from use
	char Symbol_of_colors, Symbol_of_suits, tempvalue[4];
	int Symbol_of_numbers;
	cout << endl << "Seleccione una carta de la baraja:";
	scanf("%c %c %s", &Symbol_of_colors, &Symbol_of_suits, tempvalue);

	if (tempvalue[0] == 'A')	Symbol_of_numbers = 1;
	else if (tempvalue[0] == 'J')Symbol_of_numbers = 11;
	else if (tempvalue[0] == 'Q')Symbol_of_numbers = 12;
	else if (tempvalue[0] == 'K')Symbol_of_numbers = 13;
	else
		sscanf(tempvalue, "%d", &Symbol_of_numbers);

	TopToFoundation(Symbol_of_colors, Symbol_of_suits, Symbol_of_numbers);
}

void List::TopToFoundation(char s_color, char s_suit, int s_value) {
	List_Node* listtraverse;
	Card_Node* willbemoved = NULL, * cardtraverse, * cardtail, * temptop_head = top_head;

	if (top_head == NULL) {
		cout << "Si la baraja esta vacia, no se puede hacer este movimiento." << endl;
		return;
	}

	cardtraverse = top_head;
	cardtail = top_head;

	while (cardtraverse) {
		if (cardtraverse->color == s_color && cardtraverse->suit == s_suit && cardtraverse->value == s_value) {//Revisa si los datos de las cartas son iguales a los datos que el usuario ingreso
			willbemoved = cardtraverse;
			break;
		}
		cardtail = cardtraverse;
		cardtraverse = cardtraverse->next;
	}

	if (willbemoved == NULL) {
		cout << "La carte ingresada no esta en la baraja!" << endl;
		return;
	}

	int number;
	listtraverse = foundation_head;
	if (willbemoved->suit == 'E') number = 0;
	if (willbemoved->suit == 'C') number = 1;
	if (willbemoved->suit == 'D') number = 2;
	if (willbemoved->suit == 'T') number = 3;

	for (int i = 0; i < number; i++)
		listtraverse = listtraverse->next;


	if (cardtraverse == cardtail)
		temptop_head = temptop_head->next;
	else
		cardtail->next = cardtraverse->next;

	if (addcardtolist(listtraverse, willbemoved, 2)) {
		top_head = temptop_head;
		cout << "Movimiento completado!" << endl;
	}
	else {//Si no se completo 
		if (!(cardtraverse == cardtail))
			cardtail->next = willbemoved;
		cout << "Movimiento erroneo!" << endl;
	}
}

void List::goster_TopToBoard() {
	char Symbol_of_colors, Symbol_of_suits, tempvalue[4];
	int Symbol_of_numbers, a;
	cout << "Seleccione una carta de la baraja:";
	scanf("%c %c %s", &Symbol_of_colors, &Symbol_of_suits, tempvalue);

	if (tempvalue[0] == 'A')	Symbol_of_numbers = 1;
	else if (tempvalue[0] == 'J')Symbol_of_numbers = 11;
	else if (tempvalue[0] == 'Q')Symbol_of_numbers = 12;
	else if (tempvalue[0] == 'K')Symbol_of_numbers = 13;
	else
		sscanf(tempvalue, "%d", &Symbol_of_numbers);

	cout << "Selecciona el numero de la lista destino del tablero:";
	scanf("%d", &a);
	TopToBoard(a, Symbol_of_colors, Symbol_of_suits, Symbol_of_numbers);

}

void List::TopToBoard(int listindex, char s_color, char s_suit, int s_value) {
	List_Node* listtraverse;
	Card_Node* willbemoved = NULL, * cardtraverse, * cardtail, * temptop_head = top_head;

	if (top_head == NULL) {
		cout << "La baraja esta vacia, no se puede hacer este movimiento." << endl;
		return;
	}

	cardtraverse = top_head;
	cardtail = top_head;

	while (cardtraverse) {
		if (cardtraverse->color == s_color && cardtraverse->suit == s_suit && cardtraverse->value == s_value) {
			willbemoved = cardtraverse;
			break;
		}
		cardtail = cardtraverse;
		cardtraverse = cardtraverse->next;
	}

	if (willbemoved == NULL) {
		cout << "Ingreso una carto que no esta en la baraja!" << endl;
		return;
	}

	listtraverse = board_head;
	for (int i = 1; i < listindex; i++)//Moviendo del tablero 
		listtraverse = listtraverse->next;


	if (cardtraverse == cardtail)
		temptop_head = temptop_head->next;
	else
		cardtail->next = cardtraverse->next;

	if (addcardtolist(listtraverse, willbemoved, 1)) {// if 
		top_head = temptop_head;
		cout << "Movimiento completado!" << endl;
	}
	else {// if not successful
		if (!(cardtraverse == cardtail))
			cardtail->next = willbemoved;
		cout << "Movimiento erroneo!" << endl;
	}
}

void List::goster_BoardToBoard() {
	char Symbol_of_colors, Symbol_of_suits, tempvalue[4];
	int Symbol_of_numbers, source, destination;

	cout << "Seleccione el numero de la lista origen del mazo:";
	scanf("%d", &source);
	cout << "Seleccione el numero de la lista destino del mazo:";
	scanf("%d", &destination);

	cin.ignore(1000, '\n');
	cout << "Seleccione una carta del mazo origen para mover:";
	scanf("%c %c %s", &Symbol_of_colors, &Symbol_of_suits, tempvalue);

	if (tempvalue[0] == 'A')	Symbol_of_numbers = 1;
	else if (tempvalue[0] == 'J')Symbol_of_numbers = 11;
	else if (tempvalue[0] == 'Q')Symbol_of_numbers = 12;
	else if (tempvalue[0] == 'K')Symbol_of_numbers = 13;
	else
		sscanf(tempvalue, "%d", &Symbol_of_numbers);
	BoardToBoard(source, destination, Symbol_of_colors, Symbol_of_suits, Symbol_of_numbers);
}

void List::BoardToBoard(int fromwhere, int towhere, char s_color, char s_suit, int s_value) {
	List_Node* sourcelisttraverse = board_head, * targetlisttraverse = board_head;
	Card_Node* willbemoved = NULL, * cardtraverse, * cardtail, * temp_head;

	for (int i = 1; i < fromwhere; i++)
		sourcelisttraverse = sourcelisttraverse->next;
	temp_head = sourcelisttraverse->cards;
	cardtraverse = temp_head;
	cardtail = temp_head;


	while (cardtraverse) {
		if (cardtraverse->isup)
			if (cardtraverse->color == s_color && cardtraverse->suit == s_suit && cardtraverse->value == s_value) {
				willbemoved = cardtraverse;
				break;
			}
		cardtail = cardtraverse;
		cardtraverse = cardtraverse->next;
	}

	if (willbemoved == NULL) {
		cout << "Movimiento erroneo!" << endl;
		return;
	}

	for (int i = 1; i < towhere; i++)
		targetlisttraverse = targetlisttraverse->next;


	if (cardtraverse == cardtail)
		temp_head = NULL;
	else
		cardtail->next = NULL;

	if (addcardtolist(targetlisttraverse, willbemoved, 3)) {
		sourcelisttraverse->cards = temp_head;
		if (!cardtail->isup)
			cardtail->isup = true;
		cout << "Movimiento completado!" << endl;
		return;
	}
	if (!(cardtraverse == cardtail)) {
		cardtail->next = willbemoved;
		cout << "Movimiento erroneo!" << endl;
	}

}

void List::goster_BoardToFoundation() {
	int source;
	cout << "Selecciona el numero del mazo origen:";
	scanf("%d", &source);
	cin.ignore(1000, '\n');
	BoardToFoundation(source);
}

void List::BoardToFoundation(int fromwhere) {
	List_Node* sourcelisttraverse = board_head, * targetlisttraverse = foundation_head;
	Card_Node* willbemoved = NULL, * cardtraverse, * cardtail, * temp_head;
	for (int i = 1; i < fromwhere; i++)
		sourcelisttraverse = sourcelisttraverse->next;
	temp_head = sourcelisttraverse->cards;
	cardtraverse = temp_head;
	cardtail = temp_head;

	while (cardtraverse->next) {
		cardtail = cardtraverse;
		cardtraverse = cardtraverse->next;
	}//end while

	willbemoved = cardtraverse;


	int number;
	if (willbemoved->suit == 'E') number = 0;
	if (willbemoved->suit == 'C') number = 1;
	if (willbemoved->suit == 'D') number = 2;
	if (willbemoved->suit == 'T') number = 3;

	for (int i = 0; i < number; i++)
		targetlisttraverse = targetlisttraverse->next;


	if (cardtraverse == cardtail)
		temp_head = NULL;
	else
		cardtail->next = NULL;

	if (addcardtolist(targetlisttraverse, willbemoved, 4)) {
		sourcelisttraverse->cards = temp_head;
		if (!cardtail->isup)
			cardtail->isup = true;
		cout << "Movimiento completado!" << endl;
		return;
	}
	if (!(cardtraverse == cardtail)) {
		cardtail->next = willbemoved;
		cout << "Movimiento erroneo!" << endl;
	}
}

void List::clear_screen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void List::close() {
	List_Node* listtraverse;
	Card_Node* cardtraverse;

	/*Borra los nodos de la baraja*/
	cardtraverse = top_head;
	while (top_head) {
		cardtraverse = top_head;
		top_head = top_head->next;
		delete cardtraverse;
	}

	/*Borra los nodos del tablero*/
	listtraverse = board_head;
	while (board_head) {
		cardtraverse = board_head->cards;
		while (board_head->cards) {
			cardtraverse = board_head->cards;
			board_head->cards = board_head->cards->next;
			delete cardtraverse;
		}
		listtraverse = board_head;
		board_head = board_head->next;
		delete listtraverse;
	}

	/*Borra los nodos de la lista base*/
	listtraverse = foundation_head;
	while (foundation_head) {
		cardtraverse = foundation_head->cards;
		while (foundation_head->cards) {
			cardtraverse = foundation_head->cards;
			foundation_head->cards = foundation_head->cards->next;
			delete cardtraverse;
		}
		listtraverse = foundation_head;
		foundation_head = foundation_head->next;
		delete listtraverse;
	}

	fclose(fptr);
}

