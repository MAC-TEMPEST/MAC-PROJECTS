#include <iostream>

//Fonction pour calculer la fractale de Mandelbrot
int mandelbrot(double x, double y, int max_iter){ //Declaration des parametres des limites de la factal
    double zx=0, zy=0; //initialisation des complex
    int iter=0; //declaration de l'iteration

    // Debut du while loop
    while (iter< max_iter &&(zx * zx + zx * zy)<4){
        double temp= zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = temp;
        iter++;
    }
    return iter; //affichage de l'iteration
}
int main(){
    int l = 80; //longeur de la factal
    int h = 40; //hauteur de la factal
    int max_iter = 100; //nombre d'iteration maximum ou limite de l'iteration

    //Affichage de la fractale
    //Debut de la boucle "for"
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < l; x++) {
            double rx=(x-l/2.0) * 3.5/l; //longuer du factal en fonction des coordonees x
            double ry=(y-h/2.0) * 2.0 /h; //Hauter du factal en fonction des coordonees y
            int iter= mandelbrot(rx, ry, max_iter);
            //debut de la boucle "if else"
            if (iter == max_iter){
                std::cout<<"+"; //Representation des iteration qui egalent le nombre max d'iteration graphiquement avec le symbol +
            }
            else
            {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl; //fin du "for loop"
    }
    return 0;
}