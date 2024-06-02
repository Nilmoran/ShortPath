#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>

class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class Node : public QGraphicsItem // Класс узлов графа
{
private:
    int index; // Индекс узла
    QList<Edge *> edgeList; // Список ссылок на рёбера, с которыми соединен узел
    QPointF newPos; // Координаты узла на экране
    GraphWidget *graph; // Ссылка на виждет, на котором должн отображаться узел
    int dist = 0;

public:
    Node(GraphWidget *graphWidget); // Конструктор

    void addEdge(Edge *edge); // Добавить к этому узлу ребро
    QList<Edge *> edges(); // Вернуть список рёбер, с которыми соединена этот узел
    void removeEdge(Edge *deletedEdge); // Удалить ребро от этого узла

    // Геттер и сеттер для получения/установки индекса узла
    int getIndex();
    void setIndex(int index);

    // Геттер и сеттер для получения/установки минимального расстояния до узла
    int getDist() const;
    void setDist(int value);

protected:
    QRectF boundingRect() const; // Задает координаты прямоугольника (кликабельную область), внутри которого будет узел
    QPainterPath shape() const; // Делает кликабельную область, в которой находится вершина, кругом, а не прямоугольником
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Рисует вершину

    QVariant itemChange(GraphicsItemChange change, const QVariant &value); // Регистрирует изменение положения узла
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // Регистрирует нажатие на узел мышкой
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // Регистрирует отпускание узел мышкой
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) Q_DECL_OVERRIDE; // Метод для изменения пропускной способности от выделенного узла до узла назначения
};

#endif // NODE_H
