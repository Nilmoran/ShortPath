#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include <math.h>
#include <QtMath>
#include <QPainter>
#include "node.h"
#include <QtWidgets>
#include <iostream>
#include <QRegion>

class Edge : public QGraphicsItem
{
    Q_INTERFACES(QGraphicsItem)
private:
    // Указатели на исходный и конечный узлы
    Node *source, *dest;
    // Расстояние между исходным и конечным узлом
    QPointF sourcePoint;
    QPointF destPoint;
    // Цвет ребра
    QBrush color;

    // Анимация ребра
    QGraphicsItemAnimation *posAnim;
    // Таймер, необходимый для времени анимации
    QTimeLine *timer;
    // Графическая сцена, по сути поле на котором размещается граф
    QGraphicsScene* scene;
    // Длина ребра
    unsigned length;
public:
    // Конструкторы класса с возможность установить значение длины либо умолчанию (100) либо произвольной длины
    Edge(Node *sourceNode, Node *destNode);
    Edge(Node *sourceNode, Node *destNode, unsigned length);

    // Метод возвращает ограничивающий прямоугольник, который определяет область,
    // в которой может находиться элемент ребра
    QRectF boundingRect() const;

    // Метод возращает указатели на исходный и конечный узлы
    Node *sourceNode() const;
    Node *destNode() const;

    // Метод обеспечивает динамичное и корректное отображение ребер в графическом интерфейсе
    void adjust();
    // Метод для изменения цвета ребра
    void setColor(QBrush newColor);

    // Геттер и сеттер для получения/установки длины ребра
    qreal getWeight(); //Возвращает длину ребра
    void setWeight(unsigned value);
    QGraphicsPixmapItem	*it; //объект на ребре
protected:
    // метод отвечает за отрисовку ребра на графическом элементе
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // EDGE_H
