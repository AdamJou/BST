#include "bst.h"

// d - pomocnicza w zliczaniu operacji
int d;



//poniewaz root jest zmienna prywatna jest oddzielna metoda
// ktora pozwala uzytkownikowi wywolac metode add zaczynajaca sie od roota
void BST::add( string x,node* t)
{
    d++;
    //addC to pomocniczy licznik operacji
    //ktory zlicza tylko operacje wstawiania aby nie pomieszaly
    //sie one z operacjami przy usuwaniu, szukaniu
    addC++;
    //dodawanie elementow na prawa strone
    if(t->data < x)
    {
            addC++;
            //jesli po prawej stronie danego liscia nic nie ma
            //to tworzy nowy wezel
         if(t->right ==nullptr)
         {

            t->right = new node;
            t->right->parent = t;
            t->right->data = x;
            //last - pomocniczy wskaznik potrzebny do poprawnego zliczania
            //wysokosci po usunieciu ostatniego elementu, wskazuje on na ostatni dodany element
            //parent wskazuje na rodzica nowo dodanego liscia

            last = t->right;
            return;
         }
         else
            //jesli cos juz jest po prawej stronie wezla, wywolujemy rekurencyjnie add
            add(x,t->right);
    }
    else
    {   //analogicznie jak powyzej tylko dla lewej strony
         addC++;
         if(t->left == nullptr)
         {

             t->left = new node;
             t->left->parent=t;
             t->left->data = x;
            last = t->left;
             return;
         }

            else add(x,t->left);

    }



}
void BST::insert(string x)
{
    //metoda pozwalajaca przekazac w mainie dane slowo
     d=0;
     //ilosc operacji ustawiona na 1 po to aby nie zliczac wszystkich
     //operacji dla kazdego slowa tylko dla 100,200 itd
     //de facto ustawiona jest na 1 poniewaz wliczam juz ponizszego ifa wiec zwiekszam 0 o 1
     addC=1;
     //jesli drzewo jest puste
     if(root == nullptr)
        {

            root = new node;
            root->data = x;
            last = root;

        }
    else

        add(x,root);
    addC++;
    //warunek aktualizujacy wysokosc drzewa
    if(depth < d) depth = d;
}

void BST::print(node* t)
{
    if(t == nullptr)
        return;

  if(t->left !=nullptr)
        print(t->left);
    cout << t->data << endl;
  if(t->right != nullptr)
        print(t->right);

}

void BST::show()
{
    //metoda do wywolania printa w mainie
    if(root==nullptr)
        cout<<"Nic tu nie ma";
    else
    print(root);
}








BST::node* BST::find(string x,node* t)
{


   c++;
   if(t->data == x) return t;
   else
   {
       c++;
       if(t->data > x && t->left != nullptr) return find(x, t->left);
       else
       {
           c++;
           if(t->data < x && t->right != nullptr)
           {


               return find(x, t->right);

           }

           else
           return nullptr;
       }
   }



}



void BST::updateDepth(node* t, int glebokosc)
{
    c++;
    if(root->left == nullptr && root->right == nullptr)
    {
        if (depth < glebokosc )
        {
            depth = glebokosc;  //sprawdza czy potem znalazl w glebszej
        }

    }
    else
    {
        glebokosc++;
        c++;
        if(root->left != nullptr)
        {
            updateDepth(root->left, glebokosc);

        }

        c++;
        if(root->right != nullptr)
        {
            updateDepth(root->right, glebokosc);

        }
    }


}

void BST::removeLast()
{
    c++;
    if(last == nullptr) //last wskaznik na osattni dodany element
    {
        cout<<"puste drzewo";
        return;
    }

    c++;
    if(last->parent->left == last) //jezeli rodzic ostatniego elementu z lewej strony jest rowny ostatniemu elementowi to czyscimy ten element
    {
        last->parent->left = nullptr;

    }
    else  last->parent->right = nullptr;
    delete last;
    last = nullptr;



}
