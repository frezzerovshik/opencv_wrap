//
//  main.cpp
//  aocd_second
//
//  Created by Артем Шарапов on 16.10.2020.
//  Copyright © 2020 Artem Sharapov. All rights reserved.
//

#include "labs.hpp"

using namespace cv;

int main(int argc, char** argv){
    Mat image = loadImage("/Users/frez2zerovshik/Documents/Универ/Четвёртый курс/Cv/aocd_second/aocd_second/main.jpg"); // Загружаем картинку
    imshow("image", image);
    Mat imageAffine = makeAffineTransitions(image, 27, 1.45); //Поворачиваем и масштабируем
    imshow("affine image", imageAffine);
    Mat imagePolar = getLogPolarImage(image); //Переводим картинку в полярно-логарифмические координаты
    Mat imageAffinePolar = getLogPolarImage(imageAffine);
    imshow("image polar", imagePolar);
    imshow("image affine polar", imageAffinePolar);
    Mat readyImage = prepareImageToCorrelation(imagePolar); //подготавливаем картинку
    Mat templ = croppImage(imageAffinePolar); //Обрезаем черные полосы на шаблоне
    Mat correlationPicture = getCorrelationImage(readyImage, templ); //Получаем корреляционное изображение
    imshow("prepared image", readyImage);
    imshow("correlation", correlationPicture);
    waitKey(0);
    return 0;
}
