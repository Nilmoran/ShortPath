#include "graphwidget.h"
#include "iostream"
#include <QKeyEvent>
#include <QtMath>
// Конструктор для создания сцены
GraphWidget::GraphWidget(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    // Создаём новую сцену для отображения графа
    setScene(scene);
    // Устанавливаем сцену в виджет
}

// Метод для изменения размеров окна
void GraphWidget::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0, 0, width()-2, height()-2);
    // Обновляем размер сцены, чтобы она соответствовала размеру окна
    QGraphicsView::resizeEvent(event);
    // Вызываем обработчик события изменения размера родительского класса
}

// Метод для отрисовки фона сцены
void GraphWidget::drawBackground(QPainter *painter, const QRectF &)
{
    QRectF sceneRect = this->sceneRect();
    // Закрашиваем фон белым цветом
    painter->fillRect(sceneRect, QColor(255, 255, 255, 255));
}

// Метод для добавления вершины в граф и на сцену
void GraphWidget::addNode()
{
    Node *node = new Node(this); // Создаём новую вершину
    scene->addItem(node); // Добавляем вершину на сцену

    listOfNode << node; // Добавляем вершину в список вершин
    changeIndecesOfAllVerteces(); // Обновляем индексы всех вершин
    int ii = node->getIndex();
    // Координаты появления вершин, установлены по диагонали чтобы не перекрывали друг друга
    node->setPos(QPointF(50 + ii * 10, 50 + ii * 10));
    update(); // Обновляем отображение сцены
}

// Метод для удаления ребра из графа и со сцены
void GraphWidget::deleteEdge(Edge *edge)
{
    scene->removeItem(edge); // Удаляем ребро со сцены
    edge->destNode()->removeEdge(edge); // Удаляем ребро из списка рёбер конечной вершины
    edge->sourceNode()->removeEdge(edge); // Удаляем ребро из списка рёбер начальной вершины
    delete edge; // Удаляем объект ребра
};

// Метод добавления вершин с заданной позицией и номером (создание вершин из матрицы инцидентности)
Node* GraphWidget::addNode1(QPointF position, int t)
{
    Node *node = new Node(this); // Создаём новую вершину
    node->setIndex(t); // Устанавливаем индекс вершины
    scene->addItem(node); // Добавляем вершину на сцену
    listOfNode << node; // Добавляем вершину в список вершин
    node->setPos(position); // Устанавливаем позицию вершины
    update(); // Обновляем отображение сцены
    return node; // Возвращаем указатель на созданную вершину
};

Edge* GraphWidget::addEdge(Node *source, Node *dest, unsigned length)
// Добавляем ребро с заданной длиной между двумя вершинами
{
    Edge *edge = new Edge(source, dest, length); // Создаём новое ребро
    scene->addItem(edge); // Добавляем ребро на сцену
    return edge; // Возвращаем указатель на созданное ребро
}

void GraphWidget::addEdge(Node *source, Node *dest)
// Добавляем ребро между двумя вершинами
{
    scene->addItem(new Edge(source, dest)); // Создаём и добавляем новое ребро на сцену
}

void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event)
// Обработчик события двойного клика мышкой
{
    // Если был произведён двойной клик левой кнопкой мыши
    if (event->button() == Qt::LeftButton)
    {
        Node *node = new Node(this); // Создаём новую вершину
        scene->addItem(node); // Добавляем вершину на сцену
        node->setPos(QPointF(event->pos().x(), event->pos().y())); // Устанавливаем позицию вершины на место клика
        listOfNode << node; // Добавляем вершину в список вершин
        changeIndecesOfAllVerteces(); // Обновляем индексы всех вершин
        update(); // Обновляем отображение сцены
    }
    // Если был произведён двойной клик правой кнопкой мыши
    else if (event->button() == Qt::RightButton)
    {
        Node *dest = static_cast<Node*>(itemAt(event->pos()));
        // Получаем вершину, на которую был произведён клик

        // Для всех выбранных вершин
        foreach (QGraphicsItem *item, scene->selectedItems())
        {
            bool isFindSameEdge = false; // Флаг для проверки существования прямого ребра
            bool isFindReverse = false; // Флаг для проверки существования обратного ребра
            Node *source = static_cast<Node*>(item); // Приведение текущей вершины к типу Node
            if (source == dest) continue; // Пропускаем, если источник и назначение совпадают

            int weightNum = 0; // Длина ребра

            // Проверка на существование обратного ребра
            foreach (Edge *compareEdge, source->edges())
            {
                if (compareEdge->sourceNode() == dest && compareEdge->destNode() == source)
                {
                    isFindReverse = true;
                    weightNum = static_cast<int>(compareEdge->getWeight());
                }
            }

            // Если обратное ребро не найдено, запрашиваем вес нового ребра
            if (!isFindReverse)
            {
                QMessageBox msgBox;
                QLabel *text = new QLabel("Вес ребра:");
                QSpinBox *weight = new QSpinBox();
                weight->setRange(0, 10000);
                msgBox.layout()->addWidget(text);
                msgBox.layout()->addWidget(weight);
                msgBox.exec();
                weightNum = weight->value(); // Получаем значение длины ребра от пользователя
                update(); // Обновляем отображение
            }

            // Проверка на существование прямого ребра
            foreach (Edge *compareEdge, source->edges())
            {
                if (compareEdge->sourceNode() == source && compareEdge->destNode() == dest)
                {
                    for (auto i : source->edges())
                    {
                        if (i->destNode() == dest)
                        {
                            i->setWeight(static_cast<unsigned>(weightNum)); // Обновляем вес существующего ребра
                        }
                    }
                    isFindSameEdge = true;
                    break;
                }
            }

            // Если прямое ребро уже существует, пропускаем создание нового
            if (isFindSameEdge) continue;

            // Создание нового ребра
            Edge *newEdge = new Edge(source, dest, static_cast<unsigned>(weightNum));
            scene->addItem(newEdge); // Добавляем новое ребро на сцену

            // Создание обратного ребра
            Edge *reverseEdge = new Edge(dest, source, static_cast<unsigned>(weightNum));
            scene->addItem(reverseEdge); // Добавляем обратное ребро на сцену
        }
    }
}

// Метод возвращает координаты вершины с индексом
QPointF GraphWidget::getPosOfNode(int index)
{
    return listOfNode.at(index)->pos();
}

// Метод возвращает количество вершин в списке вершин
int GraphWidget::getListOfNodeSize()
{
    return listOfNode.size();

}

// Метод для изменения индексов всех вершин, например, после удаления вершины
void GraphWidget::changeIndecesOfAllVerteces()
{
    foreach (Node *itemNode, listOfNode)
    {
        itemNode->setIndex(listOfNode.indexOf(itemNode)); // Присваивает каждой вершине новый индекс
        itemNode->update(); // Обновляет состояние вершины для отображения
    }
}

// Метод возвращает список всех рёбер графа
QVector<Edges*> GraphWidget::getEdges()
{
    QVector<Edges*> edgesList; // Создаёт вектор для хранения рёбер
    foreach (Node* node, listOfNode) // Перебирает все вершины в списке
    {
        foreach (Edge* edge, node->edges()) // Перебирает все рёбра каждой вершины
        {
            if (node->getIndex() == edge->destNode()->getIndex()) continue; // Игнорирует рёбра, идущие из вершины в неё же
            Edges* curr = new Edges;
            curr->source = node->getIndex(); // Устанавливает индекс исходящей вершины
            curr->dest = edge->destNode()->getIndex(); // Устанавливает индекс входящей вершины
            curr->weight = (int)edge->getWeight(); // Устанавливает вес ребра
            curr->edge = edge; // Сохраняет ссылку на само ребро
            edgesList << curr; // Добавляет ребро в список
        }
    }
    return edgesList; // Возвращает список рёбер
}

// Метод удаляет выбранные вершины со сцены
void GraphWidget::deleteSelectedItems()
{
    foreach (QGraphicsItem *itemNode, scene->selectedItems()) // Для каждой выбранной вершины
    {
        scene->removeItem(itemNode); // Убрать вершину из сцены
        listOfNode.removeAt(listOfNode.indexOf((Node *)itemNode)); // Убрать из списка вершин

        foreach (Edge *itemEdge, ((Node *)itemNode)->edges()) // Для каждого ребра, связанного с данной вершиной
        {
            if(!itemEdge->it->pixmap().isNull()) // Проверка, есть ли у ребра связанный анимированный объект
                scene->removeItem(itemEdge->it); // Удалить анимированный объект со сцены, если он есть
            scene->removeItem(itemEdge); // Убрать ребро из сцены
            itemEdge->destNode()->removeEdge(itemEdge); // Удалить ссылку на ребро из списка рёбер узла назначения
            itemEdge->sourceNode()->removeEdge(itemEdge); // Удалить ссылку на ребро из списка рёбер узла источника
            delete itemEdge; // Удалить объект ребра
        }
        delete itemNode; // Удалить объект вершины
    }
}

// Метод удаляет все вершины и рёбра со сцены
void GraphWidget::deleteAllItems()
{
   foreach (Node *itemNode, listOfNode)
   {
       scene->removeItem(itemNode); // Убрать вершину из сцены

       foreach (Edge *itemEdge, itemNode->edges()) // Для каждого ребра, связанного с данной вершиной
       {
           scene->removeItem(itemEdge); // Убрать ребро из сцены
           itemEdge->destNode()->removeEdge(itemEdge); // Удалить ссылку на ребро у узла назначения
           itemEdge->sourceNode()->removeEdge(itemEdge); // Удалить ссылку на ребро у узла источника
           delete itemEdge; // Удалить объект ребра
       }
       itemNode->edges().clear(); // Очистить список рёбер у вершины
       delete itemNode; // Удалить объект вершины
   }
   listOfNode.clear(); // Очистить список всех вершин
   scene->clear(); // Очистить всю сцену
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    // Вычисляет новый масштабный коэффициент после применения scaleFactor
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    // Проверяет, находится ли новый масштаб в пределах допустимых значений
    if (factor < 0.07 || factor > 100)
        return;

    // Применяет масштабирование к виджету
    scale(scaleFactor, scaleFactor);
}

// Метод создает граф из матрицы инцидентности из текстового файла
bool GraphWidget::createGraphFromInc(QString temp)
{
    QList<QString> nodes; // Список уникальных вершин
    QList<QStringList> child_of_nodes; // Список детей для каждой вершины
    temp = temp.trimmed(); // Убирает лишние пробелы с начала и конца строки
    QTextStream stream(&temp); // Использует QTextStream для чтения данных
    while (!stream.atEnd())
    {
        QString line = add_spaces_and_simplifie(stream.readLine(220)); // Читает и обрабатывает строку
        if (line.isEmpty()) continue; // Пропускает пустые строки
        QStringList list = line.split(":"); // Разделяет строку на название вершины и список детей
        if (list.first() == list.last()) return false; // Проверяет корректность разделения
        QString t = list.first().trimmed(); // Обрезает пробелы в названии вершины
        if (nodes.count(t) == 0)
            nodes << t; // Добавляет новую вершину, если она еще не встречалась
        QString t2 = list.last().trimmed(); // Обрезает пробелы в списке детей
        QStringList list_of_children = t2.split(" , ", Qt::SkipEmptyParts); // Формирует список детей
        child_of_nodes << list_of_children; // Добавляет список детей в общий список
    }
    QList<QString> all_n; // Список всех уникальных вершин
    for (int i = 0; i < nodes.size(); i++)
        if (!all_n.contains(nodes[i]))
            all_n << nodes[i];
    for (int i = 0; i < nodes.size(); i++)
        for (int k = 0; k < child_of_nodes[i].size(); k++)
            if (!all_n.contains(child_of_nodes[i][k]))
                all_n << child_of_nodes[i][k];
    bool ok = true; // Флаг для проверки, что все вершины - числа
    for (int i = 0; i < nodes.size(); i++)
        for (int k = 0; k < child_of_nodes[i].size(); k++)
        {
            child_of_nodes[i][k].toInt(&ok); // Преобразует вершину в число
        }
    if (!ok)
    {
        return false; // Возвращает false, если преобразование не удалось
    }
    int radius = 200; // Радиус расположения вершин по кругу
    double segments = (6.28) / all_n.size(); // Расчитывает углы между вершинами
    if (all_n.size() >= 16)
        radius = all_n.size() * 70 / 6; // Увеличивает радиус, если вершин много
    double current_angle = 0; // Начальный угол для размещения вершин

    foreach (QString str, all_n)
    {
        QPointF pos(radius * cos(current_angle) + 250, radius * sin(current_angle) + 250); // Вычисляет позицию вершины
        int k = str.toInt(); // Преобразует имя вершины в число
        int a, b; // Для хранения координат вершины
        a = static_cast<int>(pos.rx());
        b = static_cast<int>(pos.ry());
        pos.setX(a); pos.setY(b); // Устанавливает координаты вершины
        addNode1(pos, k); // Добавляет вершину на сцену
        update(); // Обновляет виджет
        current_angle += segments; // Увеличивает угол на значение сегмента
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        Node *a = findNode(nodes[i].toInt()); // Находит вершину по номеру
        for (int k = 0; k < child_of_nodes[i].size(); k++)
        {
            Node *b = findNode(child_of_nodes[i][k].toInt()); // Находит дочерние вершины
            if (a && b) // Если обе вершины найдены
            {
                addEdge(a, b); // Добавляет ребро между вершинами
            }
            else
                continue;
        }
    }
    return true; // Возвращает true, если граф успешно создан
}

// Вспомогательный метод для корректного чтения данных из файла
QString GraphWidget::add_spaces_and_simplifie(QString str_for_work)
{
    QChar symbs[2]{':',','};
    // Пробегаемся по всем символам, для которых нужно добавить пробелы
    for(int i = 0; i < 2; i++)
    {
        int a = -2;
        // Находим индексы символов, которые нужно изменить
        while((a = str_for_work.indexOf(symbs[i],a+2))!=-1)
        {
            // Вставляем пробелы перед и после символа
            str_for_work.insert(a, ' ');
            str_for_work.insert(a+2, ' ');
        }
    }
    // Упрощаем строку, удаляя дубликаты пробелов
    str_for_work = str_for_work.simplified();
    return str_for_work;
}

// Метод для поиска вершины графа
Node* GraphWidget::findNode(int val)
{
    Node *a;
    // По номеру надо найти вершину
    foreach (Node *itemNode, listOfNode)
    {
        if (itemNode->getIndex() == val) // Если номер вершины совпадает с искомым номером
        {
            a = static_cast<Node*>(itemNode); // Привести текущую вершину к типу Node
            return a; // Вернуть найденную вершину
        }
    }
    return nullptr; // Если вершина не найдена, вернуть nullptr
}
