#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "iostream"
#include "graphwidget.h"
#include "QFile"
#include "QTextStream"
#include "QFileDialog"
#include "QMessageBox"
#include <QSettings>   // Для сохранения настроек
#include <limits>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    GraphWidget *graph; // Виджет для отображения и управления графом
    Ui::MainWindow *ui; // Интерфейс главного окна

public:
    explicit MainWindow(QWidget *parent = 0); // Конструктор
    ~MainWindow(); // Деструктор

    void writeSettings(); // Для сохранения настроек
    void readSettings();  // Для восстановления настроек

    // Метод для выполнения поиска в глубину (DFS) между двумя узлами
    std::pair<bool, std::vector<int>> DFS(int from, int to, std::vector<int> marked, unsigned timer);

signals:
    void changeOpenFile(); // Сигнал для уведомления об изменении открытого файла

private:
    bool stop; // Флаг для остановки текущего процесса
    QSettings m_settings; // Объект для сохранения и загрузки настроек
    QString InputPath = ""; // Путь к последнему открытому файлу
    std::vector<int> shortPath; // Вектор для хранения кратчайшего пути
    int lastDijkstraSource; // Индекс начальной вершины для алгоритма Дейкстры

private slots:
    void deleteNode(); // Удаляет выбранные вершины графа
    void on_pb_CoordinatesOfAllNode_clicked(); // Выписывает координаты всех вершин графа
    void on_pb_LengthOfEdges_clicked(); // Выписывает длину всех рёбер графа
    void on_pb_ConnectGraph_clicked(); // Сделать граф полным
    void on_pb_DisconnectGraph_clicked(); // Удалить все рёбра в графе
    void on_OpenButton_clicked();  // Открыть файл с графом
    void on_saveButton_clicked();  // Сохранить граф в файл
    void on_pb_RemoveEdges_clicked(); // Удалить рёбра
    void on_pb_DeleteSelectedNodes_clicked(); // Удалить выбранные вершины
    void on_pb_CreateNode_clicked(); // Создать новую вершину
    void on_pb_CreateEdge_clicked(); // Создать новое ребро
    void on_pb_ClearAll_clicked(); // Очистить всё
    void on_pb_IncidenceListFile_clicked(); // Создание графа из списка инцидентности
    void on_pushStop_clicked(); // Остановка текущего процесса
    void on_pushAlgorithm_clicked(); // Запуск алгоритма Дейкстры
    void on_action_Open_file_triggered(); // Открыть файл (через меню)
    void on_action_Save_File_triggered(); // Сохранить файл (через меню)
    void on_action_createNode_triggered(); // Создать вершину (через меню)
    void on_action_createEdge_triggered(); // Создать ребро (через меню)
    void on_action_Algoritm_triggered(); // Запустить алгоритм (через меню)
    void on_action_delEdge_triggered(); // Удалить рёбра (через меню)
    void on_action_clear_all_triggered(); // Очистить всё (через меню)
    void on_pushFind_clicked(); // Найти кратчайший путь до выбранной вершины
};

#endif // MAINWINDOW_H
