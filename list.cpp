#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L) = NULL;
    last(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = new elmlist;
    //-------------your code here-------------
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
     if (first(L) == NULL && last(L) == NULL)
    {
        first(L)= P;
        last(L) = P;
        next(P)=first(L);
        prev(first(L))=last(L);

    }
    else
    {
        next(P) = first(L);
        prev(first(L))= P;
        first(L) = P;
        next(last(L)) = P;
        prev(P) = last(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
        next(P)=first(L);
        prev(first(L))=last(L);
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L)=P;
        next(P)=first(L);
        prev(first(L)) = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = new elmlist;
    //-------------your code here-------------
    bool ketemu = false;
    P = first(L);
    do
    {
        if(info(P).ID == x.ID)
        {
            return P;
            ketemu = true;
        }
        P = next(P);
    }
    while(P!=first(L) && !ketemu);
    if (!ketemu)
    {
        return NULL;
    }
    //----------------------------------------
}

address findElmByName(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = new elmlist;
    //-------------your code here-------------
    bool ketemu = false;
    P = first(L);
    do
    {
        if(info(P).name == x.name)
        {
            return P;
            ketemu = true;
        }
        P = next(P);
    }
    while(P!=first(L) && !ketemu);
    if (!ketemu)
    {
        return NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L) == NULL && last(L) == NULL)
    {
        cout<<"List sudah kosong";
    }
    else
    {
        if(next(first(L)) == first(L))
        {
            P = first(L);
            next(P) = NULL;
            prev(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            P=first(L);
            first(L) =next(P);
            next(P)= NULL;
            prev(next(P)) = NULL;
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
      if (first(L) == NULL && last(L) == NULL)
    {
        cout<<"List sudah kosong";
    }
    else
    {
        if (next(first(L)) == first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            address Q = prev(last(L));
            P = last(L);
            next(P) = NULL;
            prev(P) = NULL;
            Q = last(L);
            prev(next(P)) = Q;
            next(Q) = first(L);

        }
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
   if (Prec != NULL && P != NULL)
    {
            address Q = new elmlist;
            Q = next(Prec);
            next(Prec) = P;
            prev(P)= Prec;
            next(P)= Q;
            prev(Q)= P;}


    }
    //----------------------------------------


void deleteAfter(List &L, address &Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (Prec!=NULL)
    {
        if (next(Prec) == last(L))
        {
            deleteLast(L, P);
        }
        else if(next(Prec)!=first(L))
        {
            P = next(Prec);
            address Q = new elmlist;
            Q = next(P);
            next(Prec) = Q;
            prev(Q) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else
        {
            deleteFirst(L, P);
        }
    }
    //----------------------------------------
}


