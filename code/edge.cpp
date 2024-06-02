#include "edge.h"

// Этот конструктор инициализирует объект Edge,
// которые представляют начальный и конечный узлы ребра
Edge::Edge(Node *sourceNode, Node *destNode)
{
    // Отключает реакцию на нажатия мыши для данного элемента графического интерфейса
    setAcceptedMouseButtons(Qt::NoButton);
    // Устанавливает режим кэширования, улучшая производительность путем уменьшения количества необходимых перерисовок
    setCacheMode(DeviceCoordinateCache);
    // Сохраняем указатели на исходный и конечный узлы
    source = sourceNode;
    dest = destNode;
    // Добавляем текущее ребро к списку ребер
    source->addEdge(this);
    dest->addEdge(this);
    // Метод для корректной отрисовки ребра
    adjust();
    // Длина ребра по умолчанию
    length = 100;
    //flow = 0;
    // Цвет ребра по умолчанию
    color = Qt::black;

    // Создание таймера для отрисовки, установка временных ограничений и количество повторов
    timer = new QTimeLine;
    timer->setFrameRange(0,500);
    timer->setLoopCount(1);

    // Создание объекта анимации для ребра и привязывязка его к таймеру
    posAnim= new QGraphicsItemAnimation;
    posAnim->setTimeLine(timer);
    // Создание нового графического элемента для отображения
    it = new QGraphicsPixmapItem;
}

// Этот конструктор инициализирует ребро с возможностью указать его длину.
Edge::Edge(Node *sourceNode, Node *destNode, unsigned length) : Edge(sourceNode, destNode)
{
    setWeight(length);
}

// Метод для изменения цвета ребра и установления высокого значение Z-индекса, чтобы ребро отображалось поверх других элементов
void Edge::setColor(QBrush newColor)
{
    color = newColor;
    setZValue(999);
}

// Геттеры для получения указателей на исходный и конечный узлы ребра
Node *Edge::sourceNode() const
{
    return source;
}

Node *Edge::destNode() const
{
    return dest;
}

// Этот метод обеспечивает динамичное и корректное отображение ребер в графическом интерфейсе
// адаптируя их визуализацию в зависимости от расположения связанных узлов
void Edge::adjust()
{
    // Проверка наличия начального и конечного узла для ребра
    if (!source || !dest) return;

    // Создаем линию от начального до конечного узла
    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    // Вычисляем длину созданной линии
    qreal length = line.length();

    // Подготавливает элемент к изменению его геометрических характеристик
    // Это необходимо для обновления графической сцены и всех зависимых элементов после изменения положения узлов
    prepareGeometryChange();

    // Вычисление смещения концов ребра относительно узлов. Смещение нужно для создания отступа от узлов,
    // чтобы ребро визуально было связано с границей узла
    QPointF edgeOffset((line.dx() * 15) / length, (line.dy() * 15) / length);

    // Подсчет расстояния между узлами с учетом смещения, если длина ребра больше 30, иначе ребро "скрывается за двумя узлами"
    if (length > qreal(30.))
    {
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    }
    else
    {
        sourcePoint = destPoint = line.p1();
    }
}

// Геттер для получения длины ребра
qreal Edge::getWeight()
{
    return length;
}


// Этот метод устанавливает новую длину ребра, чтобы обновить отображение ребра после изменения его длины.
void Edge::setWeight(unsigned value)
{
    length = value;
    update();
}

// Этот метод возвращает ограничивающий прямоугольник, который определяет область,
// в которой может находиться элемент ребра для корректного его отображения.
QRectF Edge::boundingRect() const
{
    // Возвращает пустой прямоугольник если нет начального и конечного узла
    if (!source || !dest) return QRectF();

    qreal penWidth = 2;
    qreal extra = penWidth + 75;

    // Далее создается прямоугольник с координатами и размерами, основанными на координатах начальной
    // и конечной точек ребра, а затем этот прямоугольник корректируется на величину extra.
    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

// Этот метод отвечает за отрисовку ребра на графическом элементе
void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Проверка на наличие начального и конечного узла
    if (!source || !dest) return;
    // Рендер для сглаживания краев
    painter->setRenderHint(QPainter::Antialiasing);

    // Создаем ребро с вычисленными координатами начального и конечного узла
    QLineF line(sourcePoint, destPoint);

    // Если полученная длина равна 0, то прекращаем отрисовку ребра
    if (qFuzzyCompare(line.length(), qreal(0.))) return;

    // Устанавливаем "перо" для рисования с заданным цветом, толщиной 2 пикселя,
    // стилем сплошной линии, закругленными концами и соединениями
    painter->setPen(QPen(color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    // Отрисовываем линию
    painter->drawLine(line);

    // Устанавливаем размер шрифта для отображения текста на ребре
    QFont font;
    font.setPixelSize(15);
    painter->setFont(font);

    int weight = static_cast<int>(length);
    QString output;

    // Строка, содержащая информацию о весе ребра
    output += "W:" + QString::number(weight);

    // Отрисовка текста output черного цвета, в центре ребра, между его начальной и конечной точками
    painter->drawText((sourcePoint+destPoint)/2, output);
    painter->setBrush(Qt::black);
}
