#include <iostream>
#include "parser.cpp"
// #include <stdio.h>

// Parser : Recursive@ decent parser || Get X or X^2
// Reduce Equation : Membre gauche - membre droite || no
// Solve : Dépend degré polynolme || ok

// Organiser code propre + 

int ft_pow_2(const int nb) {
    return nb * nb;
}

double ft_sqrt(const int nb) {
    double sqrt;
    double temp;

    sqrt = nb / 2;
    temp = 0;

    while(sqrt != temp){
        temp = sqrt;
        sqrt = (nb / temp + temp) / 2;
    }
    return sqrt;
}

int discriminant(const int a, const int b, const int c) {
    return ft_pow_2(b) - (4 * a * c);
}

double delta_null(const int a, const int b) {
    return -b / (a + a);
}

void delta_positif(const int a, const int b, const int delta) {
    double soluce_positive;
    double soluce_negative;
    double square_delta;

    square_delta = ft_sqrt(delta);
    soluce_positive = (-b + square_delta) / (a + a);
    soluce_negative = (-b - square_delta) / (a + a);
    std::cout << "Delta > 0 : Solution 1 = " << soluce_positive << " / Solution 2 = " << soluce_negative << std::endl;
    return ;
}

int main(int ac, char** av){

    int a = 0;
    int b = 0;
    int c = 5;
    int delta;
    double solution;
    const char *equation;
    char membre[3][200];

    if (ac != 2)
        return 1;
    equation = av[1];
    // int lenght = 0;
    // while (equation[lenght] != 0) {
    //     lenght++;
    // }
    int i = 0;
    int base_membre = 0;
    int index_membre = 0;
    char charactere;
    while (equation[i] != '\0') {
        charactere = equation[i];
        if (charactere == '=') {
            base_membre++;
            index_membre = 0;
            i++;
        }
        else if (charactere != ' '){
            membre[base_membre][index_membre] = charactere;
            index_membre++;
            // if index_membre >= 2 return Error_2
        }
        i++;
    }
    // std::cout << "Membre gauche :" << membre[0] << " / Membre droite : " << membre[1] << std::endl;
    // Parsing -> Reduce Form

    parser(membre[0]);
    // parser(membre[1]);
    
    // Reduce Form -> Soluce
    // On traite la forme réduite ici
    // if (a == 0 && b == 0) {
    //     if (c == 0) {
    //         std::cout << "Tous les nbs réels sont solutions." << std::endl;
    //         return 0;
    //     }
    //     std::cout << "\033[0;31m Il n'y a pas de solutions.\033[0m" << std::endl;
    //     return 0;
    // }
    // if (a == 0) {
    //     std::cout << "Dégré Polynomial : 1" << std::endl;
    //     double solve = -(double)c / (double)b;
    //     std::cout << "Solution : " << solve << std::endl;
    //     return 0;
    // }
    // std::cout << "Dégré Polynomial : 2" << std::endl;
    // delta = discriminant(a, b, c);
    // if (delta == 0) {
    //     solution = delta_null(a, b);
    //     std::cout << "Delta == 0 : " << solution << std::endl;
    //     return 0;
    // }
    // else if (delta > 0) {
    //     delta_positif(a, b, delta);
    //     return 0;
    // }
    // // Peut être calculer la racine complexe
    // std::cout << "Pas de solution" << std::endl;
    return 0;
}