#include <iostream>
#include "ex2_arbore_general.h"
using namespace std;

bool esteNegativ(const int& val) {
    return val < 0;
}

bool descrescator(const int& a, const int& b) {
    return a > b;   

int main() {
    Tree<int> t;

    Tree<int>::Node* radacina = t.add_node(1);           
    Tree<int>::Node* n5 = t.add_node(5, radacina);
    Tree<int>::Node* n3 = t.add_node(3, radacina);
    Tree<int>::Node* n8 = t.add_node(8, radacina);
    Tree<int>::Node* n7 = t.add_node(7, n3);
    Tree<int>::Node* n2 = t.add_node(2, n3);

    cout << "=== Arborele initial ===\n";
    t.print();

    cout << "\nNumar total de descendenti ai radacinii: " << t.count() << "\n";
    cout << "Numarul de descendenti ai nodului 3:     " << t.count(n3) << "\n";

    Tree<int>::Node* nod = t.get_node(n5);
    cout << "\nget_node(n5) -> valoare: " << nod->value << "\n";
    cout << "get_node(nullptr) -> radacina: " << t.get_node()->value << "\n";

    cout << "\n=== find: primul nod cu valoare < 0 ===\n";
    Tree<int>::Node* gasit = t.find(esteNegativ);
    if (!gasit) cout << "Niciun nod negativ gasit.\n";

    t.add_node(-9, n5);
    cout << "Dupa adaugarea lui -9 ca fiu al lui 5:\n";
    gasit = t.find(esteNegativ);
    if (gasit) cout << "Primul negativ gasit: " << gasit->value << "\n";

    cout << "\n=== insert: adaug 99 la pozitia 1 in copiii radacinii ===\n";
    t.insert(radacina, 99, 1);
    t.print();

    cout << "\n=== sort: copiii radacinii in ordine descrescatoare ===\n";
    t.sort(radacina, descrescator);
    t.print();

    cout << "\n=== sort: copiii radacinii cu operator< (crescator) ===\n";
    t.sort(radacina, nullptr);
    t.print();

    cout << "\n=== delete_node: sterg nodul 3 (si copiii lui 7, 2) ===\n";
    t.delete_node(n3);
    t.print();

    cout << "\nNumar total de descendenti dupa stergere: " << t.count() << "\n";

    cout << "\n=== Arbore de string-uri ===\n";
    Tree<string> ts;
    Tree<string>::Node* r = ts.add_node("Animale");
    Tree<string>::Node* mam = ts.add_node("Mamifere", r);
    Tree<string>::Node* pas = ts.add_node("Pasari",   r);
    ts.add_node("Caine", mam);
    ts.add_node("Pisica", mam);
    ts.add_node("Vultur", pas);
    ts.add_node("Porumbel", pas);
    ts.print();

    return 0;
}
