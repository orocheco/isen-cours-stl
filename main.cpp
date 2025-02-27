#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>


/**
 * STL : rappels
 * O. Rochecouste
 * 2025
 */

// std::vector
void tuto_vector() {
    // vecteur de chaines de caractères
    std::vector<std::string> v1;
    // vecteur d'entiers
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // ajouter un élement à la fin du vecteur
    v1.push_back("premier");
    // affichage
    std::cout << "taille v1: " << v1.size() <<  std::endl;
    // modifier un élement (notation tableau)
    v1[0] = "premier_update";
    // affichage
    std::cout << "taille: " << v1.size() << ", élement[0]=" <<  v1[0] << std::endl;
    // notation object (plus safe)
    v1.at(0) = "premier_update";
    // affichage
    std::cout << "taille: " << v1.size() << ", élement[0]=" <<  v1.at(0) << std::endl;
    // supprimer le dernier élement
    v1.pop_back();
    // utilisation try/catch pour la méthode at.()
    try {
        // v1 est vide : donc ceci ne devrait pas fonctionner
        std::cout << "taille: " << v1.size() << ", élement[0]=" << v1.at(0) << " ou " << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "erreur: " << e.what() << std::endl;
    }


    // Effacer un élément à une position donnée
    if (!v2.empty()) {
        std::cout << "Avant erase, taille v2: " << v2.size() << std::endl;
        v2.erase(v2.begin() + 4); // Supprime le 5ème élément (index 4)
        std::cout << "Après erase, taille v2: " << v2.size() << std::endl;
    }

    // Parcourir le vecteur avec un itérateur
    std::cout << "Parcours de v2 avec un itérateur : ";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Utilisation des itérateurs inversés
    std::cout << "Parcours inverse de v2 : ";
    for (auto it = v2.rbegin(); it != v2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Utilisation de la boucle basée sur la plage (range-based for loop)
    std::cout << "Utilisation de la boucle for range-based : ";
    for (const auto& element : v2) {
        std::cout << element << " ";
    }



    // itérateur
    // on peut utiliser auto
    std::vector<int>::iterator it1 = v2.begin();

    // afficher le premier élément
    std::cout << "premier élément: " << *it1 << std::endl;
    std::cout << "second élément: " << *(++it1) << std::endl;

    // insérer à la seconde position avec un itérateur
    v2.insert(it1, 99);
    std::cout << "Insertion : V2: [";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;


    // supprimer avec un itérateur
    v2.erase(it1);

    std::cout << "Suppression : V2: [";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "]" << std::endl;

    // Rechercher une valeur
    auto it_find = std::find(v2.begin(), v2.end(), 99);
    if (it_find == v2.end()) {
        // nothing found
        std::cout << "Unable to find value in vector" << std::endl;
    } else {
        std::cout << "Value found: " << *it_find << std::endl;
    }

    // Effacer tous les éléments du vecteur
    v2.clear();
    std::cout << "Après clear(), taille v2: " << v2.size() << std::endl;

}

// Fonction pour std::map
void tuto_map() {
    std::cout << "=== std::map ===" << std::endl;

    std::map<std::string, int> map = {{"un", 1}, {"deux", 2}, {"trois", 3}};

    map["quatre"] = 4; // Ajouter un élément
    std::cout << "taille map: " << map.size() << std::endl;

    map["un"] = 10; // Modifier un élément
    std::cout << "map['un'] = " << map.at("un") << std::endl;

    map.erase("deux"); // Supprimer un élément
    std::cout << "Après erase, taille map: " << map.size() << std::endl;

    // Gestion des exceptions pour at()
    try {
        std::cout << "map['inexistant'] = " << map.at("inexistant") << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "erreur: " << e.what() << std::endl;
    }

    // Itérateur classique
    std::cout << "Itérateur classique : ";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << "{" << it->first << " : " << it->second << "} ";
    }
    std::cout << std::endl;

    // Itérateur inversé
    std::cout << "Itérateur inversé : ";
    for (auto it = map.rbegin(); it != map.rend(); ++it) {
        std::cout << "{" << it->first << " : " << it->second << "} ";
    }
    std::cout << std::endl;

    // Boucle range-based
    std::cout << "Boucle range-based : ";
    for (const auto& [key, value] : map) {
        std::cout << "{" << key << " : " << value << "} ";
    }
    std::cout << std::endl;
}

// Fonction pour std::list
void tuto_list() {
    std::cout << "=== std::list ===" << std::endl;
    std::list<std::string> l1;
    std::list<int> l2 = {1, 2, 3, 4, 5};

    l1.push_back("premier");
    std::cout << "taille l1: " << l1.size() << std::endl;

    l1.front() = "premier_update";
    std::cout << "premier élément l1: " << l1.front() << std::endl;

    l1.pop_back();
    std::cout << "taille l1 après pop_back: " << l1.size() << std::endl;

    if (!l2.empty()) {
        std::cout << "Avant erase, taille l2: " << l2.size() << std::endl;
        auto it = l2.begin();
        std::advance(it, 2);
        l2.erase(it); // Supprime le 3ème élément
        std::cout << "Après erase, taille l2: " << l2.size() << std::endl;
    }

    // Itérateur classique
    std::cout << "Itérateur classique : ";
    for (auto it = l2.begin(); it != l2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Itérateur inversé
    std::cout << "Itérateur inversé : ";
    for (auto it = l2.rbegin(); it != l2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Boucle range-based
    std::cout << "Boucle range-based : ";
    for (const auto& element : l2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Fonction pour std::deque
void tuto_deque() {
    std::cout << "=== std::deque ===" << std::endl;

    std::deque<std::string> d1;
    std::deque<int> d2 = {1, 2, 3, 4, 5};

    d1.push_back("premier");
    std::cout << "taille d1: " << d1.size() << std::endl;

    d1[0] = "premier_update";
    std::cout << "d1[0]: " << d1[0] << std::endl;

    d1.pop_back();
    std::cout << "taille d1 après pop_back: " << d1.size() << std::endl;

    if (!d2.empty()) {
        std::cout << "Avant erase, taille d2: " << d2.size() << std::endl;
        d2.erase(d2.begin() + 2);
        std::cout << "Après erase, taille d2: " << d2.size() << std::endl;
    }

    // Itérateur classique
    std::cout << "Itérateur classique : ";
    for (auto it = d2.begin(); it != d2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Itérateur inversé
    std::cout << "Itérateur inversé : ";
    for (auto it = d2.rbegin(); it != d2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Boucle range-based
    std::cout << "Boucle range-based : ";
    for (const auto& element : d2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Fonction pour std::array
void tuto_array() {
    std::cout << "=== std::array ===" << std::endl;
    std::array<std::string, 1> a1 = {"premier"};
    std::array<int, 5> a2 = {1, 2, 3, 4, 5};

    std::cout << "taille a1: " << a1.size() << std::endl;

    a1[0] = "premier_update";
    std::cout << "a1[0]: " << a1[0] << std::endl;

    try {
        std::cout << "Accès hors limite : " << a1.at(1) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "erreur: " << e.what() << std::endl;
    }

    std::cout << "Avant modification, a2[2] = " << a2[2] << std::endl;
    a2[2] = 42;
    std::cout << "Après modification, a2[2] = " << a2[2] << std::endl;

    // Itérateur classique
    std::cout << "Itérateur classique : ";
    for (auto it = a2.begin(); it != a2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Itérateur inversé
    std::cout << "Itérateur inversé : ";
    for (auto it = a2.rbegin(); it != a2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Boucle range-based
    std::cout << "Boucle range-based : ";
    for (const auto& element : a2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Tri d'un std::vector
void sort_vector() {
    std::vector<int> v = {5, 3, 9, 1, 4};
    std::cout << "Vector avant tri : ";
    for (const auto& e : v) std::cout << e << " ";
    std::cout << std::endl;

    std::sort(v.begin(), v.end()); // Tri croissant

    std::cout << "Vector après tri : ";
    for (const auto& e : v) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri d'un std::list
void sort_list() {
    std::list<int> l = {5, 3, 9, 1, 4};
    std::cout << "List avant tri : ";
    for (const auto& e : l) std::cout << e << " ";
    std::cout << std::endl;

    l.sort(); // Tri croissant directement avec std::list::sort

    std::cout << "List après tri : ";
    for (const auto& e : l) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri d'un std::map (Les clés sont toujours triées)
void sort_map() {
    std::map<int, std::string> m = {
        {3, "trois"},
        {1, "un"},
        {4, "quatre"},
        {2, "deux"}
    };

    std::cout << "Map (triée par clé par défaut) : ";
    for (const auto& [key, value] : m) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << std::endl;
}

// Tri d'un std::array
void sort_array() {
    std::array<int, 5> arr = {5, 3, 9, 1, 4};
    std::cout << "Array avant tri : ";
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << std::endl;

    std::sort(arr.begin(), arr.end()); // Utilisation de std::sort

    std::cout << "Array après tri : ";
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri d'un std::deque
void sort_deque() {
    std::deque<int> d = {5, 3, 9, 1, 4};
    std::cout << "Deque avant tri : ";
    for (const auto& e : d) std::cout << e << " ";
    std::cout << std::endl;

    std::sort(d.begin(), d.end()); // Utilisation de std::sort

    std::cout << "Deque après tri : ";
    for (const auto& e : d) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri personnalisé dans un std::vector
void sort_vector_custom() {
    std::vector<int> v = {5, 3, 9, 1, 4};
    std::cout << "Vector avant tri personnalisé : ";
    for (const auto& e : v) std::cout << e << " ";
    std::cout << std::endl;

    // Tri décroissant avec lambda
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    std::cout << "Vector après tri personnalisé (décroissant) : ";
    for (const auto& e : v) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri personnalisé dans un std::list
void sort_list_custom() {
    std::list<int> l = {5, 3, 9, 1, 4};
    std::cout << "List avant tri personnalisé : ";
    for (const auto& e : l) std::cout << e << " ";
    std::cout << std::endl;

    // Tri décroissant avec lambda
    l.sort([](int a, int b) { return a > b; });

    std::cout << "List après tri personnalisé (décroissant) : ";
    for (const auto& e : l) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri personnalisé dans un std::map (tri par valeur)
void sort_map_custom() {
    std::map<int, std::string> m = {
        {3, "trois"},
        {1, "un"},
        {4, "quatre"},
        {2, "deux"}
    };

    std::cout << "Map avant tri personnalisé : ";
    for (const auto& [key, value] : m) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << std::endl;

    // Trier par valeur (utilisation de std::vector pour trier par valeur)
    std::vector<std::pair<int, std::string>> vec(m.begin(), m.end());
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second < b.second; // Tri par valeur (ordre alphabétique)
    });

    std::cout << "Map après tri personnalisé (par valeur) : ";
    for (const auto& [key, value] : vec) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << std::endl;
}

// Tri personnalisé dans un std::array
void sort_array_custom() {
    std::array<int, 5> arr = {5, 3, 9, 1, 4};
    std::cout << "Array avant tri personnalisé : ";
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << std::endl;

    // Tri décroissant avec std::greater
    std::sort(arr.begin(), arr.end(), std::greater<int>());

    std::cout << "Array après tri personnalisé (décroissant) : ";
    for (const auto& e : arr) std::cout << e << " ";
    std::cout << std::endl;
}

// Tri personnalisé dans un std::deque
void sort_deque_custom() {
    std::deque<int> d = {5, 3, 9, 1, 4};
    std::cout << "Deque avant tri personnalisé : ";
    for (const auto& e : d) std::cout << e << " ";
    std::cout << std::endl;

    // Tri croissant avec std::greater
    std::sort(d.begin(), d.end(), std::greater<int>());

    std::cout << "Deque après tri personnalisé (décroissant) : ";
    for (const auto& e : d) std::cout << e << " ";
    std::cout << std::endl;
}



int main() {

    tuto_vector();
    tuto_map();
    tuto_list();
    tuto_deque();
    tuto_array();

    // le tri avec la STL
    sort_vector();
    sort_map();
    sort_list();
    sort_deque();
    sort_array();

    // tri utilisant un foncteur custom
    sort_array_custom();
    sort_map_custom();
    sort_list_custom();
    sort_deque_custom();
    sort_array_custom();

    return 0;
}
