// Stand: 01.12.2025 - Schwaiger
#pragma once
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;

// Eine Liste für eine beliebige Klasse T
template<class T> class List
{
private:
    list<T>* meineListe;
    mutable mutex m;      // Mutex für Thread-Sicherheit

public:
    List()   //Konstruktor mit dynamischer Erzeugung einer Liste vom Typ list 
    {
        meineListe = new list<T>;
    }

    ~List()
    {
        // ggf. nicht löschen, falls Elemente anders verwaltet werden
        delete meineListe;
    }


    void add(T obj);                 // hängt das Objekt am Ende der Liste an.
    void add(int index, T obj);      // fügt das Objekt an Position index ein.

    bool contains(T obj);            // true, wenn Objekt enthalten ist.

    T get(int index);                // liefert Listenelement an Position index.

    T remove(int index);             // entfernt Element an Position index.

    bool remove(T obj);              // entfernt das erste Vorkommen von obj.

    int size();                      // Anzahl der Elemente in der Liste.
};


template<class T> int List<T>::size()
{
    lock_guard<mutex> lock(m);
    return (int)meineListe->size();
}

// Neues Element in die Liste einfügen (am Ende)
template<class T> void List<T>::add(T obj)
{
    lock_guard<mutex> lock(m);
    meineListe->push_back(obj);
}

// Neues Element an Position index einfügen
template<class T> void List<T>::add(int index, T obj)
{
    lock_guard<mutex> lock(m);

    if (index < 0 || index >(int)meineListe->size())
        return;

    typename list<T>::iterator it = meineListe->begin();
    advance(it, index);
    meineListe->insert(it, obj);
}

template<class T> bool List<T>::contains(T obj)
{
    lock_guard<mutex> lock(m);

    bool found = (std::find(meineListe->begin(), meineListe->end(), obj) != meineListe->end());
    return found;
}

template<class T> T List<T>::get(int index)
{
    lock_guard<mutex> lock(m);

    if (index < 0 || index >= (int)meineListe->size())
        return 0;

    int i = 0;
    for (auto& cursor : *meineListe)
    {
        if (i == index)
            return cursor;
        i++;
    }
    return 0;
}

template<class T> T List<T>::remove(int index)
{
    lock_guard<mutex> lock(m);

    if (index < 0 || index >= (int)meineListe->size())
        return 0;

    typename list<T>::iterator it = meineListe->begin();
    advance(it, index);

    T tmp = *it;
    meineListe->erase(it);
    return tmp;
}

template<class T> bool List<T>::remove(T obj)
{
    lock_guard<mutex> lock(m);

    if (obj == 0)
        return false;

    for (typename std::list<T>::iterator it = meineListe->begin(); it != meineListe->end(); ++it)
    {
        if ((*it) == obj)
        {
            meineListe->erase(it);
            return true;
        }
    }
    return false;
}
