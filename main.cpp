#include <QCoreApplication>

#include <iostream>
#include <vector>

#include <CImg.h>
#include <armadillo>

#define ARMA_DONT_USE_WRAPPER

using namespace std;
using namespace cimg_library;
using namespace arma;

int imageWidth; //ширина изображения
int imageHeight;  //высота  изображения

int n = 1; //размер округи
int v = 9; //длина вектора

mat bubbleSort(mat x, int size)
{
    mat e = x;
    int j;
    for (int i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (e(0, j) > e(0, j + 1))
            {
                int temp = e(0, j + 1);
                e(0, j + 1) = e(0, j);
                e(0, j) = temp;
            }
        }
    }
    return e;
}

void start(const char * file, const char *outputFile)
{
    cout << "Start..." << endl;
    CImg <unsigned char> image(file);
    imageWidth=image.width();
    imageHeight=image.height();

    CImg <unsigned char> image_out = image;

    int k;
    for (int indexW = n; indexW < imageWidth - n; indexW++){
        for (int indexH = n; indexH < imageHeight - n; indexH++){
            mat R = mat(1, v);
            mat G = mat(1, v);
            mat B = mat(1, v);

            k = 0;
            for (int i = indexW - 1; i < indexW + 2; i++){
                for (int j = indexH - 1; j < indexH + 2; j++) {
                    R(0, k) = (int)image(i, j, 0, 0);
                    G(0, k) = (int)image(i, j, 0, 1);
                    B(0, k) = (int)image(i, j, 0, 2);
                    k++;
               }
            }
            R = bubbleSort(R, 9);
            G = bubbleSort(G, 9);
            B = bubbleSort(B, 9);
            double color[3];
            color[0] = R(0, 4);
            color[1] = G(0, 4);
            color[2] = B(0, 4);
            image_out.draw_point(indexW, indexH, color);
        }
    }
    image_out.save(outputFile);
    cout << "Finish" << endl;
}

int main()
{
    start("images/image2.bmp", "result_images/out_image2.bmp");
    start("images/image3.bmp", "result_images/out_image3.bmp");
    start("images/image4.bmp", "result_images/out_image4.bmp");
    return 0;
}
