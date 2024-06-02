#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_settings("VEB", "MyProgram")  // Инициализация объекта для сохранения настроек
{
    ui->setupUi(this);  // Настройка пользовательского интерфейса
    setWindowIcon(QIcon(":/help/Default.png"));  // Установка иконки окна
    readSettings();  // Восстановление настроек

    // Настройка графического представления графа
    graph = ui->graphicsView;
    graph->setDragMode(QGraphicsView::RubberBandDrag);  // Установка режима перетаскивания
    graph->setOptimizationFlags(QGraphicsView::DontSavePainterState);  // Установка флагов оптимизации
    graph->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);  // Установка режима обновления вида
    graph->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // Установка точки привязки трансформации
    graph->setInteractive(true);  // Включение интерактивного режима
    graph->setRenderHint(QPainter::Antialiasing);  // Включение сглаживания при рендеринге
}


MainWindow::~MainWindow()
{
    delete ui;  // Удаление пользовательского интерфейса
    writeSettings();  // Сохранение настроек перед закрытием программы
}

void MainWindow::readSettings()
{
    // Чтение настроек
    m_settings.beginGroup("/Settings");  // Начало группы настроек

    int nWidth = m_settings.value("/width", width()).toInt();  // Чтение ширины окна
    int nHeight = m_settings.value("/height", height()).toInt();  // Чтение высоты окна
    QString nInputPath = m_settings.value("/fileData", "").toString();  // Чтение пути к входному файлу
    InputPath = nInputPath;  // Сохранение пути к входному файлу
    resize(nWidth, nHeight);  // Изменение размера окна

    m_settings.endGroup();  // Завершение группы настроек
}

void MainWindow::writeSettings()
{
    // Запись настроек
    m_settings.beginGroup("/Settings");  // Начало группы настроек
    m_settings.setValue("/width", width());  // Запись ширины окна
    m_settings.setValue("/height", height());  // Запись высоты окна
    m_settings.setValue("/fileData", InputPath);  // Запись пути к входному файлу
    m_settings.endGroup();  // Завершение группы настроек
}

void MainWindow::deleteNode()
// Удаляет выбранные вершины графа
{
    graph->deleteSelectedItems();  // Удаление выбранных элементов графа
    graph->changeIndecesOfAllVerteces();  // Изменение индексов всех вершин графа
}

void MainWindow::on_pb_CoordinatesOfAllNode_clicked()
// Выписывает координаты всех вершин графа
{
    QString s = "Координаты вершин: \n\n";  // Начальная строка с заголовком
    for (int i = 0; i < graph->getListOfNodeSize(); i++)  // Проход по всем вершинам графа
    {
        s += QString("%1 - ( %2, %3 )\n").arg(i).arg(graph->getPosOfNode(i).x()).arg(graph->getPosOfNode(i).y());  // Добавление координат вершины
    }
    s.chop(1);  // Удаление последнего символа новой строки
    ui->textBrowser->setText(s);  // Отображение текста в textBrowser
}

void MainWindow::on_pb_LengthOfEdges_clicked()
// Выписывает длину всех рёбер графа
{
    QString s = "Веса рёбер:\n\n";  // Начальная строка с заголовком
    int i = 0;
    foreach (Edges *item, graph->getEdges())  // Проход по всем рёбрам графа
    {
        s += QString("%1. ( %2, %3 ) - %4\n").arg(++i).arg(item->source).arg(item->dest).arg(item->weight);  // Добавление информации о рёбрах
    }
    s.chop(1);  // Удаление последнего символа новой строки
    ui->textBrowser->setText(s);  // Отображение текста в textBrowser
}

// Метод дополняющий граф до полносвязного
void MainWindow::on_pb_ConnectGraph_clicked()
{
    on_pb_DisconnectGraph_clicked(); // Удаляем все существующие рёбра, чтобы избежать дубликатов

    int ic = 0, jc;
    foreach (Node* i, graph->listOfNode) // Проходим по каждой вершине в графе
    {
        jc = 0;
        foreach (Node* j, graph->listOfNode) // Проходим по каждой вершине для создания рёбер
        {
            if (ic <= jc) break; // Если индексы совпадают, выходим из внутреннего цикла, чтобы избежать дубликатов

            graph->scene->addItem(new Edge(j, i)); // Добавляем ребро от j к i
            graph->scene->addItem(new Edge(i, j)); // Добавляем обратное ребро от i к j
            jc++;
        }
        ic++;
    }
}

// Метод для удаления всех ребер в графе
void MainWindow::on_pb_DisconnectGraph_clicked()
{
    foreach (Node* Node, graph->listOfNode) // Проходим по каждой вершине в графе
    {
        foreach (Edge *edge, Node->edges()) // Проходим по каждому ребру, связанному с данной вершиной
        {
            graph->scene->removeItem(edge); // Удаляем ребро

            edge->destNode()->removeEdge(edge); // Удаляем ребро из списка рёбер узла назначения
            edge->sourceNode()->removeEdge(edge); // Удаляем ребро из списка рёбер исходного узла

            delete edge; // Удаляем объект ребра
        }
    }
}

// Метод для загрузки графа из файла с расширением .graph
void MainWindow::on_OpenButton_clicked()
{
    // Открываем диалоговое окно для выбора файла с заданным по умолчанию путем к корневой папке с программой
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть граф", InputPath, "Graph file (*.graph)");
    // Проверка на пустое имя файла
    if (!fileName.isEmpty())
    {
        QFile file(fileName); // Создаём объект файла с выбранным именем
        // Если файл успешно открыт только на чтение
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file); // Создаём поток для чтения данных из файла
            on_pb_ClearAll_clicked(); // Очищаем текущее состояние графа
            graph->getEdges().clear(); // Очищаем список рёбер
            graph->listOfNode.clear(); // Очищаем список вершин

            QFileInfo fi(file); // Получаем информацию о файле.
            QString fn4 = fi.absolutePath(); // Получаем абсолютный путь к файлу
            InputPath = fn4; // Сохраняем путь к файлу

            int vertices_count, edges_count;
            in >> vertices_count; // Считываем количество вершин
            // Проходим по каждой вершине
            for (int i = 0; i < vertices_count; i++)
            {
                int id, x, y;
                in >> id >> x >> y; // Считываем координаты вершины

                Node *Node1 = new Node(graph); // Создаём новую вершину
                Node1->setIndex(id); // Устанавливаем индекс вершины
                Node1->setPos(x, y); // Устанавливаем позицию вершины
                graph->scene->addItem(Node1); // Добавляем вершину на сцену
                graph->listOfNode << Node1; // Добавляем вершину в список вершин
            }
            graph->update(); // Обновляем экран

            bool accept = true;
            in >> edges_count; // Считываем количество рёбер
            for (int i = 0; i < edges_count; i++)
            {
                accept = true;
                int uid, vid;
                unsigned length;
                in >> uid >> vid >> length; // Считываем данные о ребрах графа

                Node *source = graph->findNode(uid); // Находим вершину-источник по индексу
                Node *dest = graph->findNode(vid); // Находим вершину-назначение по индексу

                // Проверяем, нет ли уже такого ребра
                foreach (Edges *edge, graph->getEdges())
                {
                    if (edge->source == uid && edge->dest == vid)
                        accept = false;
                }

                if (accept)
                {
                    graph->scene->addItem(new Edge(source, dest, length)); // Добавляем ребро на сцену
                }
            }
            graph->update(); // Обновляем экран

            file.close(); // Закрываем файл

            // Открываем файл ещё раз для отображения его содержимого в текстовом виде на экране
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file);
                ui->textBrowser->setText(in.readAll()); // Читаем и отображаем содержимое файла
            }
            file.close(); // Закрываем файл
        }
        else
        {
            // Если файл не удалось открыть, показываем сообщение об ошибке
            QMessageBox::information(this, "Невозможно открыть файл", file.errorString());
            return;
        }
    }
    else
        return; // Если файл не выбран, ничего не делаем
}


// Метод для сохранения графа в файл с расширением .graph
void MainWindow::on_saveButton_clicked()
{
    // Открываем диалоговое окно для сохранения графа в файл с раширением .graph по пути по умолчанию в корневой папке с программой
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить граф", InputPath, "Graph file (*.graph)");
    // Проверка на пустое имя файла
    if (!fileName.isEmpty())
    {
        QFile file(fileName); // Создаём объект файла с выбранным именем
        // Если файл успешно открыт только на запись
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file); // Создаём поток для записи данных из файла
            int n = graph->getListOfNodeSize(); // Получаем количество вершин
            out <<  n << Qt::endl; // Записываем количество вершин в файл
            for (int i = 0; i < n; i++)
                // Записываем каждую вершину в файл
                out << i << " " << graph->getPosOfNode(i).x() << " " << graph->getPosOfNode(i).y() << Qt::endl;
            int i = 0;
            foreach (Edges *item, graph->getEdges())
                i = i + 1; // Считаем количество рёбер
            out << i << Qt::endl; // Записываем количество рёбер в файл
            foreach (Edges *item, graph->getEdges())
                // Записываем каждое ребро в файл
                out << item->source << " " << item->dest << " " << item->weight << Qt::endl;
            file.close(); // Закрываем файл
        }
        else
        {
            // Если файл не удалось открыть, показываем сообщение об ошибке
            QMessageBox::information(this, "Невозможно открыть файл", file.errorString());
            return;
        }
    }
    else
        return; // Если файл не выбран, ничего не делаем
}

// Метод для удаления всех рёбер
void MainWindow::on_pb_RemoveEdges_clicked()
{
    on_pb_DisconnectGraph_clicked(); // Вызываем метод для удаления всех рёбер
}

// Метод для удаления выбранных вершин
void MainWindow::on_pb_DeleteSelectedNodes_clicked()
{
    deleteNode(); // Вызываем метод для удаления выбранных вершин
}

// Метод для создания новой вершины
void MainWindow::on_pb_CreateNode_clicked()
{
    graph->addNode(); // Вызываем метод для добавления новой вершины в граф
}


// Метод для создания ребра между двумя вершинами
void MainWindow::on_pb_CreateEdge_clicked()
{
    Node *source;
    Node *dest;

    // Получаем индексы исходной и целевой вершины из текстовых полей
    int Source1 = (ui->lineEdit_Source->text()).toInt();
    int Dest1 = (ui->lineEdit_Dest->text()).toInt();

    // Находим вершины по их индексам
    source = graph->findNode(Source1);
    dest = graph->findNode(Dest1);

    // Добавляем ребро от исходной вершины к целевой
    graph->addEdge(source, dest);
    // Добавляем обратное ребро для обеспечения ненаправленного графа
    graph->addEdge(dest, source);
}

// Метод для очистки графа
void MainWindow::on_pb_ClearAll_clicked()
{
    // Удаляем все элементы из графа
    graph->deleteAllItems();

    // Обновляем текстовое поле с инструкциями для пользователя
    ui->textBrowser->setText("Добавить новую вершину - двойное нажатие ЛКМ.\n\n"
                             "Добавить новое ребро - выделите первую вершину нажатием ЛКМ, "
                             "затем зажать Shift и дважды нажмите ПКМ по второй вершине.");
}

// Метод для создания графа из файла со списком инцидентности
void MainWindow::on_pb_IncidenceListFile_clicked()
{
    // Открываем диалоговое окно для выбора текстового файла по пути по умолчанию в корневой папке с программой
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл со списком инцидентности", InputPath, "Text files (*.txt)");
    // Проверка на пустое имя файла
    if (fileName.isEmpty())
        return;

    QFile file(fileName); // Создаём объект файла с выбранным именем
    // Если файл успешно открыт только на запись
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Очищаем текущий граф
        on_pb_ClearAll_clicked();

        // Создаём граф из содержимого файла
        if (!graph->createGraphFromInc(file.readAll())) {
            // Если в файле ошибка, выводим сообщение об ошибке
            QMessageBox error;
            error.setText("Ошибка в файле! Вершины должны быть пронумерованы исключительно числами!");
            error.exec();
        }

        file.close();

        // Открываем файл ещё раз для чтения
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            // Обновляем текстовое поле содержимым файла
            ui->textBrowser->setText(in.readAll());
        }
        file.close();
    }
}


void MainWindow::on_pushAlgorithm_clicked()
{
    // Проверка на пустоту графа
    if (graph->getListOfNodeSize() == 0)
    {
        QMessageBox::information(this, "Ошибка", "Граф пустой, невозможно выполнить алгоритм.");
        return;
    }

    // Проверка, выделена ли начальная вершина
    Node* startNode = nullptr;
    foreach (QGraphicsItem* item, graph->scene->selectedItems())
    {
        startNode = qgraphicsitem_cast<Node*>(item);
        if (startNode)
        {
            break;
        }
    }

    if (!startNode)
    {
        QMessageBox::information(this, "Ошибка", "Пожалуйста, выберите начальную вершину.");
        return;
    }

    // Удаляем вычисленные кратчайшие расстояния, если они уже были
    for (int i=0; i<graph->getListOfNodeSize(); i++)
    {
        graph->findNode(i)->setDist(0);
    }

    // Начальная вершина определена
    unsigned source = static_cast<unsigned>(startNode->getIndex());

    ui->pushFind->setDisabled(false);

    // Таймер для анимации
    unsigned timer = static_cast<unsigned>(ui->spinBox->value());

    // Инициализация векторов для родительских вершин, расстояний и отмеченных вершин
    std::vector<int> VParent(static_cast<unsigned>(graph->getListOfNodeSize()), 0);
    std::vector<int> SDist(static_cast<unsigned>(graph->getListOfNodeSize()), INT_MAX);
    std::vector<bool> marked(static_cast<unsigned>(graph->getListOfNodeSize()), false);

    // Установка расстояния до начальной вершины как 0
    SDist[source] = 0;

    int dMin;
    unsigned vMin = 0, u = 0;

    // Основной цикл алгоритма
    for (int p = 0; p < graph->getListOfNodeSize(); p++)
    {
        // Проверка на остановку
        if (stop)
        {
            stop = false;
            return;
        }

        // Поиск вершины с минимальным расстоянием
        dMin = INT_MAX;
        for (unsigned i = 0; i < SDist.size(); i++)
        {
            if (SDist[i] < dMin && !marked[i])
            {
                dMin = SDist[i];
                vMin = i;
            }
        }

        // Если минимальное расстояние равно бесконечности, завершить алгоритм
        if (dMin == INT_MAX)
            return;

        // Отметить текущую вершину как обработанную
        marked[vMin] = true;
        graph->findNode(static_cast<int>(vMin))->setSelected(true);

        // Обработка всех смежных рёбер
        for (auto i : graph->findNode(static_cast<int>(vMin))->edges())
        {
            u = static_cast<unsigned>(i->destNode()->getIndex());

            // Анимация изменения цвета ребра
            for (int j = 10; j < 255; j += 10)
            {
                i->setColor(QColor(j, 0, 0));
                i->update();
                Sleep(timer / 40);
                QCoreApplication::processEvents();
            }

            // Обновление расстояния и родительской вершины, если найден более короткий путь
            if (SDist[vMin] + i->getWeight() < SDist[u])
            {
                for (int j = 10; j < 255; j += 10)
                {
                    i->setColor(QColor(255 - j, j, 0));
                    i->update();
                    Sleep(timer / 40);
                    QCoreApplication::processEvents();
                }

                SDist[u] = SDist[vMin] + i->getWeight();
                graph->findNode(static_cast<int>(u))->setDist(SDist[u]);
                VParent[u] = static_cast<int>(vMin);

                QCoreApplication::processEvents();
                Sleep(timer / 2);

                for (int j = 0; j < 255; j += 10)
                {
                    i->setColor(QColor(0, 255 - j, 0));
                    i->update();
                    Sleep(timer / 40);
                    QCoreApplication::processEvents();
                }
            }
            else
            {
                Sleep(timer / 2);
                for (int j = 0; j < 255; j += 10)
                {
                    i->setColor(QColor(255 - j, 0, 0));
                    i->update();
                    Sleep(timer / 40);
                    QCoreApplication::processEvents();
                }
            }
        }
        graph->findNode(static_cast<int>(vMin))->setSelected(false);
    }

    // Сохранение кратчайшего пути
    shortPath = VParent;
    lastDijkstraSource = source;
}


void MainWindow::on_pushFind_clicked()
{
    // Проверка, был ли уже выполнен алгоритм Дейкстры
    if (shortPath.empty())
    {
        QMessageBox::information(this, "Ошибка", "Сначала выполните алгоритм Дейкстры.");
        return;
    }

    // Проверка, выделена ли конечная вершина
    Node* destNode = nullptr;
    foreach (QGraphicsItem* item, graph->scene->selectedItems())
    {
        destNode = qgraphicsitem_cast<Node*>(item);
        if (destNode)
        {
            break;
        }
    }

    if (!destNode)
    {
        QMessageBox::information(this, "Ошибка", "Пожалуйста, выберите конечную вершину.");
        return;
    }

    int dest = destNode->getIndex();

    // Использование начальной вершины из алгоритма Дейкстры
    int source = lastDijkstraSource;

    // Сброс цвета всех рёбер
    for (auto i : graph->getEdges())
    {
        i->edge->setColor(QColor(0, 0, 0));
        i->edge->update();
    }

    unsigned timer = static_cast<unsigned>(ui->spinBox->value());

    // Проверка, что начальная и конечная вершины различны
    if (source == dest)
    {
        QMessageBox::information(this, "Ошибка", "Начальная и конечная вершины совпадают.");
        return;
    }

    // Создание пути от конечной вершины к начальной
    int p = dest;
    while (p != source)
    {
        bool edgeFound = false;
        for (auto i : graph->getEdges())
        {
            if (i->dest == p && i->source == shortPath[p])
            {
                // Выделение ребра
                for (int j = 0; j < 255; j += 10)
                {
                    i->edge->setColor(QColor(j, 0, 0));
                    i->edge->update();
                    Sleep(timer / 40);
                    QCoreApplication::processEvents();
                }
                edgeFound = true;

                // Выделение обратного ребра
                for (auto j : graph->getEdges())
                {
                    if (j->source == p && j->dest == shortPath[p])
                    {
                        for (int k = 0; k < 255; k += 10)
                        {
                            j->edge->setColor(QColor(k, 0, 0));
                            j->edge->update();
                            Sleep(timer / 40);
                            QCoreApplication::processEvents();
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (!edgeFound)
        {
            QMessageBox::information(this, "Ошибка", "Путь не найден.");
            return;
        }
        Sleep(timer / 2);
        p = shortPath[p];
    }
}

void MainWindow::on_pushStop_clicked()
{
    stop = true;
    foreach (Edges* curr, graph->getEdges()) //
    {
        curr->edge->setColor(QColor(0, 0, 0, 255));
        curr->edge->setZValue(0);
        curr->edge->update();
    }
    for (int i=0; i<graph->getListOfNodeSize(); i++)
    {
        graph->findNode(i)->setDist(0);
    }
    ui->textBrowser->setText("Добавить новую вершину - двойное нажатие ЛКМ.\n\n"
                             "Добавить новое ребро - выделите первую вершину нажатием ЛКМ,"
                             "затем зажать Shift и дважды нажмите ПКМ по второй вершине.");
}

// Метод для создания графа из файла
void MainWindow::on_action_Open_file_triggered()
{
    on_OpenButton_clicked();
}

// Метод для сохранения графа в файл
void MainWindow::on_action_Save_File_triggered()
{
    on_saveButton_clicked();
}
// Метод создания новой вершины в графе
void MainWindow::on_action_createNode_triggered()
{
    on_pb_CreateNode_clicked();
}

// Метод создания нового ребра между вершинами в графе
void MainWindow::on_action_createEdge_triggered()
{
    on_pb_CreateEdge_clicked();
}

// Метод для запуска алгоритма Дейкстры для поиска кратчайших путей от начальной вершины
void MainWindow::on_action_Algoritm_triggered()
{
    on_pushAlgorithm_clicked();
}

// Метод удаления всех рёбер из графа
void MainWindow::on_action_delEdge_triggered()
{
    on_pb_DisconnectGraph_clicked();
}

// Метод очистки графа, удаление всех вершин и рёбер
void MainWindow::on_action_clear_all_triggered()
{
    on_pb_ClearAll_clicked();
}
