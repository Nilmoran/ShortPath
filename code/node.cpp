#include "edge.h"
#include "node.h"
#include "graphwidget.h"

#include<QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

// Геттер для получения минимального расстояния до узла
int Node::getDist() const
{
    return dist;
}

// Сеттер для установки нового минимального расстояния до узла после применения алгоритма
void Node::setDist(int value)
{
    dist = value;
    update();
}

Node::Node(GraphWidget *graphWidget): graph(graphWidget)
{
    setFlags(ItemIsSelectable | ItemIsMovable); //  Флаг, который делает узел выбираемым и перемещаемым
    setFlag(ItemSendsGeometryChanges); // Флаг, который позволяет узлу отправлять изменения своей геометрии
    setCacheMode(DeviceCoordinateCache); // Флаг, устанавливает режим кэширования, чтобы улучшить производительность при отрисовке
    setZValue(+1); // Устанавливает Z-значение для узла, чтобы он отображался поверх других элементов с меньшим Z-значением
}

// Метод добавляет ребро в список ребер, связанных с этим узлом, и вызывает метод adjust() для корректировки положения ребра
void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

// Метод удаляет ребро из списка ребер, связанных с этим узлом
void Node::removeEdge(Edge *deletedEdge)
{
    edgeList.removeAll(deletedEdge);
}

// Метод возвращает список всех ребер, связанных с этим узлом
QList<Edge *> Node::edges()
{
    return edgeList;
}

// Геттер для получения индекса узла
int Node::getIndex()
{
    return index;
}

// Сеттер для установки нового индекса узла
void Node::setIndex(int index)
{
    this->index = index;
}

// Метод возвращает ограничивающий прямоугольник для узла с небольшим отступом
// Этот прямоугольник определяет область, в которой находиться кликабельная область узла
QRectF Node::boundingRect() const
{
    qreal adjust = 20;
    return QRectF( -15 - adjust, -15 - adjust, 33 + adjust, 33 + adjust);
}

// Делает кликабельную область, в которой находится узел, круглой, а не прямоугольной,
// что позволяет более точно определять границы узла для взаимодействий с ним
// например, при клике или перетаскивании
QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-15, -15, 30, 30);
    return path;
}

// Метод отвечает за визуальное представление узла
// Обработка различных состояний узла, в зависимости от взаимодействия пользователя
// А также отвечает за отрисовку минимального расстояния до узла
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    if (option->state & QStyle::State_Sunken) // Заливка узла желтым цветом при перетаскивании
    {
        painter->setBrush(QColor(254, 254, 34, 255));
    }
    if (option->state & QStyle::State_Selected)// Заливка узла желтым цветом при выделении
    {
        painter->setBrush(QColor(254, 254, 34, 255));
    }
    else
    {
        painter->setBrush(QColor(191, 255, 148, 255)); // Заливка узла светло-зеленым цветом (по умолчанию)
    }

    // Задаем границы узла с заданными параметрами
    painter->setPen(QPen(QColor(130, 180, 130, 255), 3));

    // Отрисовка самого узла с выбранным цветом
    painter->drawEllipse(-15, -15, 30, 30);

    // Задаем параметры для отрисовки индекса узла
    painter->setPen(QPen(Qt::black));
    painter->setFont(QFont("Roboto", 9));

    // Устанавливает Z-значение для узла, чтобы он отображался поверх других элементов
    setZValue(1300);

    // Преобразования индекса узла в строку
    QString text = QString::number(index);

    // Отрисовка индекса узла в его центре с учётом, количества цифр в индексе узла
    if (index < 10)
    {
        painter->drawText(-4, 5, text);
    }
    else
    {
        painter->drawText(-8, 5, text);
    }


    text = QString::number(dist); // Преобразуем значение минимального расстояния до узла в строку
    // Устанавливаем шрифт и цвет для текста расстояния
    painter->setFont(QFont("Roboto", 10, 100));
    painter->setPen(QPen(Qt::red));

    painter->drawText(-20, -20, text); // Отрисовка минимального расстояния до узла в верхнем левом углу узла
}

// Этот метод отслеживает изменения, происходящие с узлом
// Когда позиция узла изменяется, обновляются все связанные с ним ребра с помощью метода adjust().
QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    }

    // Возвращаем изменение для дальнейшей обработки
    return QGraphicsItem::itemChange(change, value);
}

// Метод регистрирует нажатие на вершину мышкой для обновления состояния узла
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

// Метод регистрирует отпускание вершины мышкой для обновления состояния узла
void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

// Метод для изменения пропускной способности от выделенного узла до узла назначения
void Node::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // Вызов базового обработчика события контекстного меню
    QGraphicsItem::contextMenuEvent(event);

    // Проверка, что текущий узел выбран
    if (!this->isSelected())
        return;

    // Создаем контекстное меню
    QMenu menu;
    QAction *new_val = menu.addAction("Изменить пропускную способность"); // Добавляем действие для изменения пропускной способности
    menu.addSeparator(); // Добавляем разделитель в меню
    QAction *selected_action = menu.exec(event->screenPos()); // Отображаем меню и получаем выбранное действие

    // Проверяем, выбрано ли действие для изменения пропускной способности
    if (selected_action == new_val)
    {
        // Создаем окно для ввода новых значений
        QMessageBox msgBox;
        QSpinBox *dest = new QSpinBox(); // Индекс узла назначения
        QSpinBox *weight = new QSpinBox(); // Пропускная способность между узлами
        QLabel *destLabel = new QLabel("Укажите индекс узла назначения:"); // Подпись для ввода индекса узла назначения
        QLabel *weightLabel = new QLabel("Укажите новую пропускную\nспособность между узлами:"); // Подпись для ввода пропускной способности
        weight->setRange(0, 10000); // Устанавливаем диапазон значений для пропускной способности
        dest->setRange(0, graph->getEdges().size()); // Устанавливаем диапазон значений для индекса узла назначения

        // Создаем компоновку для размещения виджетов в диалоговом окне
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(destLabel); // Добавляем подпись для ввода индекса узла назначения
        layout->addWidget(dest); // Добавляем поле для ввода индекса узла назначения
        layout->addWidget(weightLabel); // Добавляем подпись для ввода пропускной способности
        layout->addWidget(weight); // Добавляем поле для ввода пропускной способности

        // Создаем виджет для диалогового окна и устанавливаем его компоновку
        QWidget *dialogWidget = new QWidget;
        dialogWidget->setLayout(layout);
        msgBox.layout()->addWidget(dialogWidget); // Добавляем виджет в диалоговое окно
        msgBox.exec(); // Отображаем диалоговое окно

        // Получаем введенные значения
        int destNum = dest->value();
        int weightNum = weight->value();

        // Изменение веса ребра и обратного ребра
        for (auto i : edges()) // Проходим по всем рёбрам, исходящим из текущего узла
        {
            if (i->destNode()->getIndex() == destNum) // Проверяем, что целевой узел ребра соответствует введенному индексу
            {
                i->setWeight(static_cast<unsigned>(weightNum)); // Устанавливаем новую пропускную способность

                // Найти и изменить вес обратного ребра
                Node* destNode = i->destNode();
                for (auto j : destNode->edges()) // Проходим по всем рёбрам, исходящим из целевого узла
                {
                    if (j->destNode()->getIndex() == this->getIndex()) // Проверяем, что целевой узел ребра соответствует текущему узлу
                    {
                        j->setWeight(static_cast<unsigned>(weightNum)); // Устанавливаем новую пропускную способность для обратного ребра
                        break; // Найдено обратное ребро, можно выходить из цикла
                    }
                }
            }
        }
        update(); // Обновляем отображение узла
    }
    setSelected(false); // Снимаем выделение с узла
}
