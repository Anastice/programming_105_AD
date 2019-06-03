#include <iostream>
#include <cmath>
#include <locale>
#include <cstdlib>
using namespace std;
template<class T>
class vector3d
{
public:
    vector3d();
    ~vector3d();
    void SetVector(const char * const caption); //function allows you to enter the coordinates of the vector
    void display(const char * const caption); // function to display the vector on the screen
    void summ(vector3d *vec1, vector3d *vec2); // gets the sum vector
    void razn(vector3d *vec1, vector3d *vec2); //gets the difference vector
    void dlina(vector3d *vec1); // calculate the length of the vector
    void scalar(vector3d *vec1, vector3d *vec2); // scalar multiplies vectors
    void cosinus(vector3d *vec1, vector3d *vec2); // displays the cosine of the angle between the vectors
private:
    T x, y, z; // coordinates
};
template<class T>
vector3d<T>::vector3d() //class constructor
{
    x = T(0);
    y = T(0);
    z = T(0);
}
template<class T>
vector3d<T>::~vector3d() // empty destructor
{
}
template<class T>
void vector3d<T>::SetVector(const char * const caption)
{
    cout << caption << endl;
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;
    cout << "Z = ";
    cin >> z;
}
template<class T>
void vector3d<T>::summ(vector3d *vec1, vector3d *vec2)
{
    x = vec1->x + vec2->x;
    y = vec1->y + vec2->y;
    z = vec1->z + vec2->z;
}
template<class T>
void vector3d<T>::razn(vector3d *vec1, vector3d *vec2)
{
    x = vec1->x - vec2->x;
    y = vec1->y - vec2->y;
    z = vec1->z - vec2->z;
}
template<class T>
void vector3d<T>::dlina(vector3d *vec1)
{
    cout << "VECTOR LENGTH:" << endl;
    float u = sqrt((vec1->x * vec1->x) + (vec1->y * vec1->y) + (vec1->z * vec1->z));
    cout << u << endl;
}
template<class T>
void vector3d<T>::scalar(vector3d *vec1, vector3d *vec2)
{
    float dot = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
    cout << "THE RESULT OF SCALAR PRODUCT OF VECTORS:" << endl
            << dot << endl;
}
template<class T>
void vector3d<T>::cosinus(vector3d *vec1, vector3d *vec2)
{
    float dot = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
    float u = sqrt((vec1->x * vec1->x) + (vec1->y * vec1->y) + (vec1->z * vec1->z));
    float u2 = sqrt((vec2->x * vec2->x) + (vec2->y * vec2->y) + (vec2->z * vec2->z));
    //by the formula we find the cosine of the angle between the vectors
    float cos = (dot / (u * u2));
    cout << "COSINUS ANGLE BETWEEN VECTORS:" << endl
            << cos << endl;
}
template<class T>
void vector3d<T>::display(const char * const caption)
{
    cout << caption << endl
            << "Coordinate Vector:" << endl
            << "X = " << x << endl
            << "Y = " << y << endl
            << "Z = " << z << endl;
}
int main(int argc, char *argv[])
{
    locale::global(locale(""));
    //declare class instances, we have 2 vectors for work and one for results
    vector3d<float> *vector1 = new vector3d<float>;
    vector3d<float> *vector2 = new vector3d<float>;
    vector3d<float> *result_vector = new vector3d<float>;
    int p; // variable to select
    while (true)
    {
        cout << "------------------------MENU-------------------------" << endl
                << "\t1 - Addition of two vectors" << endl
                << "\t2 - The difference of two vectors" << endl
                << "\t3 - Calculate the length of the vector" << endl
                << "\t4 - The scalar product of vectors" << endl
                << "\t5 - Cosine of the angle between the vectors" << endl
                << "\t0 - Exit the program" << endl
                << "-----------------------------------------------------" << endl;
        cin >> p;
        system("cls"); // clear
        switch (p) // check selection and call the corresponding function
        {
        case 1:
            vector1->SetVector("Enter the coordinates of the vector1:");
            vector2->SetVector("Enter the coordinates of the vector2:");
            result_vector->summ(vector1, vector2);
            result_vector->display("-----------RESULT----------");
            break;
        case 2:
            vector1->SetVector("Enter the coordinates of the vector 1:");
            vector2->SetVector("Enter the coordinates of the vector 2:");
            result_vector->razn(vector1, vector2);
            result_vector->display("-----------RESULT----------");
            break;
        case 3:
            vector1->SetVector("Enter the coordinates of the vector:");
            result_vector->dlina(vector1);
            break;
        case 4:
            vector1->SetVector("Enter the coordinates of the vector 1:");
            vector2->SetVector("Enter the coordinates of the vector 2:");
            result_vector->scalar(vector1, vector2);
            break;
        case 5:
            vector1->SetVector("Enter the coordinates of the vector 1:");
            vector2->SetVector("Enter the coordinates of the vector 2:");
            result_vector->cosinus(vector1, vector2);
            break;
        case 0:
            exit(0);
            break;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
