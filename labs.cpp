//
//  labs.cpp
//  aocd_second
//
//  Created by Артем Шарапов on 17.10.2020.
//  Copyright © 2020 Artem Sharapov. All rights reserved.
//

#include "labs.hpp"

using namespace cv;
using namespace std;

Mat loadImage(const string &filename) {
    Mat m = imread(filename);   //Считываем изображение из файла
    resize(m, m, Size(), 0.4, 0.4); //Уменьшаем изображение до удобных для работы размеров
    return m;
}

void writeImage(Mat& image, const string &filename) {
    imwrite(filename, image);
}

Mat getCorrelationImage(Mat &image, Mat &templ) {
    Mat correlationImage;
    matchTemplate(image, templ, correlationImage, TM_CCORR_NORMED);
    normalize(correlationImage, correlationImage,0,1,NORM_MINMAX, -1, Mat());
    return correlationImage;
}

Point2f getCenter(Mat &image) {
    return Point2f(image.cols / 2, image.rows / 2);
}

Size getSize(Mat &image) {
    return Size(image.cols, image.rows);
}

double getRadius(Mat &image) {
    return sqrt(pow(image.cols,2)+pow(image.rows, 2)) * 50;
}

//Обрезать лишние чёрные полосы на изображении в полярно-логарифмических координатах
Mat croppImage(Mat &image) {
    Mat result = image;
    Rect frame(0, image.rows / 2, image.cols, image.rows / 2);
    result(frame).copyTo(result);
    return result;
}

Mat getLogPolarImage(Mat &image) {
    Mat result = image;
    warpPolar(image, result, getSize(image), getCenter(image), getRadius(image), INTER_LINEAR+WARP_FILL_OUTLIERS+WARP_POLAR_LOG);
    rotate(result, result, ROTATE_90_COUNTERCLOCKWISE);
    return result;
}

Mat prepareImageToCorrelation(Mat &image) {
    Mat result = image;
    result = croppImage(result);
    vconcat(result, result, result);
    hconcat(result, result, result);
    return result;
}

Mat makeAffineTransitions(Mat &image, float angle, float scale) {
    Mat result;
    Mat M = getRotationMatrix2D(getCenter(image), angle, scale);
    warpAffine(image, result, M, getSize(image));
    return result;
}
