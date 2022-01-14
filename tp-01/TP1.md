# TP1 - Introduction au C++


## Exercice 1 - Compilation et exécution

1. Quels sont les avantages et désavantages d'un langage dit "*compilé*" (C, C++, Pascal) ou "*semi-compilé*" (Java) comparé à un langage dit "*interpreté*" (Python, PHP, Javascript, etc) ?
```
avantage:
 + plus efficace (traduit en langage machine)

désavantages: 
 - il faut recompilé pour chaque plateforme 
 - il faut recompilé si les dépendances changent

 +/- gestion de la mémoire plus présente
```

1. Quelle est la différence entre une erreur de compilation et une erreur d'exécution ? (à quel moment se produisent-elles ? dans quelles circonstances ? comment les identifier ? comment les corriger ? ...)
```
Une erreur de compilation est une erreur syntaxique ou sémantique, elle ce produit 
durant la phase de compilation, par exemple un ";" oublié, ou un probème de type, 
le message d'erreur du compilateur nous aide à les corriger.

Une erreur d'exécution se produit pendant l'exécution du programme lorsqu'il se 
comporte pas de la façon attendue, par exemple un fichier que l'on doit ouvrir 
mais qui n'existe pas ou une division par 0, elles sont très difficile à debugger.
```

2. Que signifie en pratique l'expression "*undefined behavior*" (UB) ? Peut-on compiler un programme contenant du code classifié UB par le standard ? Si oui, que peut-il se produire au moment de son exécution ?
```
L'expression "*undefined behavior*" signifie que le comportement du code n'est pas spécfié par le standart c++.
Il peut se produire une exécution différente en fonction du context, de l'architecture...etc.
Un tel programme est néamoins compilable.
```

## Exercice 2 - Primitives et initialisation

En C++, il existe plein de syntaxes différentes pour initialiser une variable de type primitif (int, char, bool, ...) :

```cpp
int v;       // pas d'initialisation            -> valeur indéfinie
int v = 2;   // initialisation avec '= value'   -> value
int v {};    // initialisation avec '{}'        -> tous les bits à 0
int v { 2 }; // initialisation avec '{ value }' -> value
int v(2);    // initialisation avec '(value)'   -> value
```

1. Parmi les lignes suivantes, lesquelles déclenchent des erreurs de compilation ? Quelles sont ces erreurs et comment les corriger ?\
Mêmes questions en ajoutant l'option `-Werror` à la compilation.\
Vous pouvez utiliser [CompilerExplorer](https://www.godbolt.org/z/rPPoro) pour tester la compilation de petits snippets de code.

```cpp
short       s0;
const short s1; // constante non initialisé

const int i1 = 2;

bool b2{false};
bool b3{i1}; // int(4 octets) -> bool (1bit) 
bool b4;

unsigned       u5{0x10};
unsigned short us6 = -10;
unsigned long  ul7{b3 + u5 + us6};

char c8{"a"}; // " délimite une string, il faut utilisé ' pour char
char c9 = -10;

double       d10{i1};
double&      d11{d10};
double&      d12; // une référence doit être initialisé
const double d13{.0f};

int        i14 = i1;
int&       i15 = i1; // si i15 est une référence sur i1 alors i15 doit être de type const int&
int&       i16 = b2; // doit être de type const int& car un objet de type 
// int est crée pour boxé b2 en int pour faire une référence dessus

const int& i17{i14};
```

2. Pouvez-vous donner la valeur de `s0` ? De `ul7` ?
```
les valeurs de s0 et ul7 sont considéré comme undefined behavor : 
s0 n'est pas initialisé et ul7 comporte us6 qui est unsigned short de valeur -10 < 0.
```


## Exercice 3 - Les fonctions et leurs paramètres

1. Remplacez les `XX` par les bons types, de manière à ce que le programme compile et affiche `42`.

```cpp
#include <iostream>

int add(const int a, const int b) {
  return a + b;
}

void add_to(int& a, const int b) {
  a += b;
}

void another_add_to(int* a, const int b) {
  *a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  another_add_to(&y, y);
  add_to(y, 2);
  std::cout << y << std::endl;

  return 0;
}
```

2. En C++, vous pouvez passer vos paramètres par valeur, par référence et par référence constante.
Quelles sont les différences entre ces différentes méthodes de passage ?
Dans quels contextes est-il préférable de passer par valeur ? Par référence ? Et par référence constante ?
```
passage par valeur : tous les champs des objets passé en paramètre sont empilé sur la pile d'appel. 
On l'utilise uniquement pour les types primitifs car très couteux pour les objets.

passage par référence:  la référence de l'objets est empilé et on peut accédé/modifié l'objet depuis sa référence. 
On l'utilise lorsque l'on veux pouvoir modifier des objets.

passage par référence constante :  la référence de l'objets est empilé mais l'accès en mémoire est en read-only. 
On l'utilise lorsque l'on a besoin de la valeur d'un objet que l'on ne souhaite pas modifier.
```

3. Modifiez les signatures des fonctions suivantes de manière à ce que le passage de paramètres soit le plus efficace et sécurisé possible.
Vous pouvez vous aidez des commentaires pour comprendre comment les fonctions utilisent leurs paramètres.
```cpp
// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string& s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float dt, std::string& errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(const std::vector<int>& values, const int* negative_indices_out, size_t& negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(const char* str1, const char* str2);
```


## Exercice 4 - `std::string` et `std::vector`

1. Ecrivez un programme qui utilise `std::cin` pour lire une variable de type `std::string`, puis calcule et affiche pour chaque lettre miniscule ('a', 'b', ..., 'z') le nombre des fois où elle apparaît.\
Le comptage des lettres se fera dans une fonction `count_lower` prenant une chaîne de caractères en paramètre et renvoyant un `std::vector<unsigned int>`. La première case du tableau contiendra le nombre d'occurences de 'a', la seconde de 'b', etc.\
Vous afficherez ce tableau dans une seconde fonction `display_lower_occ`.\
Essayez d'utiliser les signatures qui rendront votre programme le plus efficace possible.

2. Modifiez le programme pour que l'utilisateur puisse entrer plusieurs chaînes de caractères, jusqu'à ce qu'il entre la chaîne "QUIT".\
Vous afficherez en plus des occurrences la concaténation de toutes les chaînes de caractères renseignées par l'utilisateur.


## Exercice 5 - Traducteur malade

Dans la vie, on se retrouve souvent face à du code tout pourri qu'il faut débugguer. Afin de vous préparer psychologiquement aux tourments de votre futur métier de programmeur, vous allez devoir corriger le code du programme que vous trouverez dans le dossier `tp-01` du dépôt https://github.com/Laefy/CPP_Learning_Code/.

---

Ce programme consiste en un traducteur, censé s'utiliser comme suit :
```b
# Ajoute une nouvelle traduction au dictionnaire dict.txt (il est créé s'il n'existe pas).
./translator -d path/to/dict.txt -a chat cat

# Utilise le dictionnaire dict.txt pour traduire la phrase "le chat est beau"
./translator -d path/to/dict.txt le chat est beau
```

Voici le format attendu pour le fichier dict.txt :
```b
bonjour hello
cheval horse
tu you
```
---

1. Pour commencer, essayez de faire en sorte que le programme compile.\
Un indice : si seulement on pouvait bannir les chaînes de caractères de type char*.

2. Une fois que le programme compile, essayez de le lancer, afin de constater que le programme est bourré de bug.\
Placez un breakpoint sur la première ligne du `main`, lancez le programme en mode debug et itérez d'instruction en instruction, tout en inspectant le contenu des variables.\
Cela vous permettra d'identifier d'où viennent les problèmes pour réussir à les corriger.

> Dans VSCode, vous pouvez placer des breakpoints avec F9, lancer un programme en mode debug via F5 (il faut modifier le fichier launch.json pour passer des arguments au programme), exécuter l'instruction courante avec F10, entrer dans un appel de fonction avec F11 et en sortir avec Shift+F11. Afin de voir le contenu des variables, ouvrez le panneau d'exécution (`View > Run`) et regardez dans la section `Variables`.

> Voici la liste des types de problèmes que trouverez dans le programme :
>- passage par valeur au lieu de référence,
>- mauvais usage de `std::vector`,
>- condition inversée ou au mauvais endroit.

3. Si vous parvenez à corriger tous les bugs, vous pouvez faire une dernière passe sur le programme afin de remplacer les passages par valeur coûteux par des passages par const-ref, et ajouter les `const` sur toutes les variables qui ne sont pas modifiées après leur initialisation.   

---

Céline Noël, Stéphane Vialette, Mathias Weller  
C++ Master 1    
2020 - 2021
