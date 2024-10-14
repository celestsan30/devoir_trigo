#include <iostream>


const float PI = 3.14159265;

// Fonction pour convertir les degrés en radians
float degrees_to_radians(float degrees) {
    return degrees * (PI / 180.0);
}

// Fonction pour calculer la factorielle
float factorial(int n) {
    float fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Fonction pour calculer la puissance x^n
float power(float nbr, int expo) {
    float result = 1;
    for (int i = 0; i < expo; ++i) {
        result *= nbr;
    }
    return result;
}

// Fonction pour calculer sin(x) avec le développement limité
float mon_sin(float x) {
    float sinx = 0;
    for (int n = 0; n < 10; ++n) {
        float term = power(-1, n) * power(x, 2*n + 1) / factorial(2*n + 1);
        sinx += term;
    }
    return sinx;
}

// Fonction pour calculer cos(x) avec le développement limité
float mon_cos(float x) {
    float cosx = 0;
    for (int n = 0; n < 10; ++n) {
        float term = power(-1, n) * power(x, 2*n) / factorial(2*n);
        cosx += term;
    }
    return cosx;
}

// Fonction pour calculer tan(x) = sin(x) / cos(x)
float ma_tan(float x) {
    float sinx = mon_sin(x);
    float cosx = mon_cos(x);
    if (cosx == 0) {
        std::cout << "Tangente indéfinie, division par zéro!" << std::endl;
        return 0;
    }
    return sinx / cosx;
}

int main() {
    float angle_degrees;

    // Entrée de l'utilisateur : l'angle en degrés et le nombre de termes
    std::cout << "Entrez l'angle en degrés : ";
    std::cin >> angle_degrees;

    // Conversion de l'angle en radians
    float angle_radians = degrees_to_radians(angle_degrees);

    // Calcul des valeurs par développement limité
    float sinx = mon_sin(angle_radians);
    float cosx = mon_cos(angle_radians);
    float tanx = ma_tan(angle_radians);

    // Affichage des résultats
    std::cout << "sin(" << angle_degrees << " degrés) = " << sinx << std::endl;
    std::cout << "cos(" << angle_degrees << " degrés) = " << cosx << std::endl;
    std::cout << "tan(" << angle_degrees << " degrés) = " << tanx << std::endl;

    return 0;
}

