#ifndef LISTELEMENT_H
#define LISTELEMENT_H


class ListElement
{
private:
	int key;
	ListElement* next;
public:
	int getKey();
	ListElement(int key);
	friend class List;
};
///testowa linia

#endif // LISTELEMENT_H
