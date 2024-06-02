#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>

// Основная функция main, с которой начинается выполнение программы
int main(int argc, char *argv[])
{
    // Создаем объект QApplication, который управляет ресурсами приложения
    QApplication a(argc, argv);

    // Создаем основной объект главного окна
    MainWindow w;

    // Отображаем главное окно на экране
    w.show();

    // Запускаем основной цикл приложения
    // a.exec() запускает обработку событий в приложении, пока приложение не будет закрыто
    return a.exec();
}
