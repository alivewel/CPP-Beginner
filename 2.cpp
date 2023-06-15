#include <iostream>
#include <string>
using namespace std;

struct ivector3d 
{
    int *array;
    int a;
};

// void scale(ivector3d *v, int k) 
// {
//     for (int i = 0; i != 3; ++i) {
//         v->array[i] = 1;
//         v->array[i] *= k;
//         std::cout << "X = " << v->array[i] << std::endl;
//     }
        
// }

void scale(ivector3d v, int k) 
{
    for (int i = 0; i != 3; ++i) {
        v.array[i] = 1;
        v.array[i] *= k;
        std::cout << "X = " << v.array[i] << std::endl;
    }
        
}

// void print(ivector3d *v) 
// {
//     for (int i = 0; i != 3; ++i)
//         v->array[i] *= k;
// }

int main () {
    int array[3];
    ivector3d iv3d;
    iv3d.array = array;
    iv3d.a = 1;
    std::cout << "Y = " << iv3d.a << std::endl;
    scale(iv3d, 2);
}