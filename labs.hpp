//
//  labs.hpp
//  aocd_second
//
//  Created by Артем Шарапов on 17.10.2020.
//  Copyright © 2020 Artem Sharapov. All rights reserved.
//

#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

/*Функции для работы с файлами*/
cv::Mat loadImage(const std::string &filename); // Загрузить изображение из файла
void writeImage(cv::Mat& image, const std::string &filename);                    //Записать изображение в файл

/*Функция для получения корреляционной картины*/
cv::Mat getCorrelationImage(cv::Mat &image, cv::Mat &templ); // Нормировать полученную корреляционную картину не нужно

/*Функции для вычислений*/
cv::Point2f getCenter(cv::Mat &image); //Получить центральную точку изображения
cv::Size getSize(cv::Mat &image); //Получить размеры изображения
double getRadius(cv::Mat &image); //Получить радиус для полярно-логарифмической системы координат

/*Функции для работы с изображением в полярно-логарифмических координатах*/
cv::Mat croppImage(cv::Mat &image);
cv::Mat getLogPolarImage(cv::Mat &image); //Перевести изображение в полярно-логарифмическую систему координат
cv::Mat prepareImageToCorrelation(cv::Mat &image); //Подготовить основное изображение к вычислению взаимокорреляционной функции
cv::Mat makeAffineTransitions(cv::Mat &image, float angle, float scale); //Выполнить поворот и масштабирование изображения


