#include <iostream>
#include <string>
using namespace std;

struct ivector3d 
{
    int array[3];
};

void scale(ivector3d *v, int k) 
{
    for (int i = 0; i != 3; ++i) {
        v->array[i] = 1;
        v->array[i] *= k;
        std::cout << "X = " << v->array[i] << std::endl;
    }
        
}

// void print(ivector3d *v) 
// {
//     for (int i = 0; i != 3; ++i)
//         v->array[i] *= k;
// }

int main () {
    ivector3d iv3d;
    scale(&iv3d, 2);
}