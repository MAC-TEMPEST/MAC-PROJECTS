#include <iostream>

struct Point {
    int x;
    int y;
};

bool estValide(const Point& p1, const Point& p2, const Point& p3) {
    // Calcul de la pente entre les points
    int pente12 = (p2.y - p1.y) * (p3.x - p2.x);
    int pente23 = (p3.y - p2.y) * (p1.x - p3.x);
    int pente31 = (p1.y - p3.y) * (p2.x - p1.x);

    // Vérification si les pentes sont toutes du même signe
    return (pente12 > 0 && pente23 > 0 && pente31 > 0) ||
          (pente12 < 0 && pente23 < 0 && pente31 < 0);
}

int main() {
    // Exemple de points
    Point points[] = {
        {0, 0}, {1, 0}, {0, 1}, {1, 1}, {0.5, 0.5}
    };
    int nbPoints = sizeof(points) / sizeof(points[0]);

    // Affichage des points
    std::cout << "Points : " << std::endl;
    for (int i = 0; i < nbPoints; ++i) {
        std::cout << "(" << points[i].x << ", " << points[i].y << ")" << std::endl;
    }

    // Triangulation (algorithme simplifié)
    std::cout << "Triangles : " << std::endl;
    for (int i = 0; i < nbPoints; ++i) {
        for (int j = i + 1; j < nbPoints; ++j) {
            for (int k = j + 1; k < nbPoints; ++k) {
                if (estValide(points[i], points[j], points[k])) {
                    std::cout << "(" << i << ", " << j << ", " << k << ")" << std::endl;
                }
            }
        }
    }

    return 0;
}

