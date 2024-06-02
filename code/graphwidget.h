#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QList>
#include "edge.h"
#include "node.h"

struct Edges   // Структура для хранения информации о рёбрах
{
    Edge *edge; // Указатель на объект ребра
    int source; // Номер вершины-источника
    int dest;   // Номер вершины-назначения
    int weight; // Вес ребра
};

class GraphWidget : public QGraphicsView // Виджет для рисования вершин и рёбер
{
    Q_OBJECT

public:
    QGraphicsScene *scene; // Окно, на котором рисуются все элементы
    QList<Node *> listOfNode; // Список вершин, отображающихся на окне

    // Конструктор
    explicit GraphWidget(QWidget *parent = 0);

    // Возвращает местоположение вершины с номером index
    QPointF getPosOfNode(int index);

    // Возвращает количество вершин
    int getListOfNodeSize();

    // Переименовывает вершины после удаления некоторых вершин
    void changeIndecesOfAllVerteces();

    // Возвращает список всех рёбер графа
    QVector<Edges *> getEdges();

    // Добавляет вершину в граф
    void addNode();

    // Удаляет ребро из графа
    void deleteEdge(Edge *edge);

    // Добавляет вершину в граф с заданной позицией и номером (для создания вершин из матрицы инцидентности)
    Node* addNode1(QPointF position, int t);

    // Добавляет ребро в граф с указанием длины
    Edge *addEdge(Node *source, Node *dest, unsigned length);

    // Добавляет ребро в граф
    void addEdge(Node *source, Node *dest);

    // Удаляет все вершины из графа
    void deleteAllItems();

    // Создаёт граф из списка инцидентности
    bool createGraphFromInc(QString temp);

    // Добавляет пробелы и упрощает строку
    QString add_spaces_and_simplifie(QString str_for_work);

    // Поиска вершины графа
    Node* findNode(int val);

public slots:
    // Удаляет выбранные вершины из графа
    void deleteSelectedItems();

protected:
    // Масштабирует вид
    void scaleView(qreal scaleFactor);

    // Отрисовывает фон
    void drawBackground(QPainter *painter, const QRectF &rect);

    // Обрабатывает событие изменения размера окна
    void resizeEvent(QResizeEvent *event);

    // Обрабатывает событие двойного щелчка мышью
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // GRAPHWIDGET_H
