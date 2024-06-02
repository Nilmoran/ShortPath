/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenuFileExit;
    QAction *actionDeleteItem;
    QAction *action;
    QAction *action_Open_file;
    QAction *action_Save_File;
    QAction *action_createNode;
    QAction *action_createEdge;
    QAction *action_delEdge;
    QAction *action_clear_all;
    QAction *action_Algoritm;
    QAction *action_About;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *OpenButton;
    QPushButton *pb_IncidenceListFile;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_ConnectGraph;
    QPushButton *pb_DisconnectGraph;
    QPushButton *pb_LengthOfEdges;
    QPushButton *pb_CoordinatesOfAllNode;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_DeleteSelectedNodes;
    QPushButton *pb_RemoveEdges;
    QPushButton *pb_ClearAll;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_CreateNode;
    QPushButton *pb_CreateEdge;
    QLineEdit *lineEdit_Source;
    QLineEdit *lineEdit_Dest;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushAlgorithm;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushFind;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushStop;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *textBrowser;
    GraphWidget *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 800);
        MainWindow->setMinimumSize(QSize(900, 400));
        actionMenuFileExit = new QAction(MainWindow);
        actionMenuFileExit->setObjectName(QString::fromUtf8("actionMenuFileExit"));
        actionDeleteItem = new QAction(MainWindow);
        actionDeleteItem->setObjectName(QString::fromUtf8("actionDeleteItem"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_Open_file = new QAction(MainWindow);
        action_Open_file->setObjectName(QString::fromUtf8("action_Open_file"));
        action_Save_File = new QAction(MainWindow);
        action_Save_File->setObjectName(QString::fromUtf8("action_Save_File"));
        action_createNode = new QAction(MainWindow);
        action_createNode->setObjectName(QString::fromUtf8("action_createNode"));
        action_createEdge = new QAction(MainWindow);
        action_createEdge->setObjectName(QString::fromUtf8("action_createEdge"));
        action_delEdge = new QAction(MainWindow);
        action_delEdge->setObjectName(QString::fromUtf8("action_delEdge"));
        action_clear_all = new QAction(MainWindow);
        action_clear_all->setObjectName(QString::fromUtf8("action_clear_all"));
        action_Algoritm = new QAction(MainWindow);
        action_Algoritm->setObjectName(QString::fromUtf8("action_Algoritm"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 0));
        horizontalWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 232, 232);\n"
"border-radius: 15px;"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        OpenButton = new QPushButton(horizontalWidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setMinimumSize(QSize(40, 40));
        OpenButton->setMaximumSize(QSize(40, 40));
        OpenButton->setCursor(QCursor(Qt::PointingHandCursor));
        OpenButton->setToolTipDuration(0);
        OpenButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/open.png);"));

        horizontalLayout->addWidget(OpenButton);

        pb_IncidenceListFile = new QPushButton(horizontalWidget);
        pb_IncidenceListFile->setObjectName(QString::fromUtf8("pb_IncidenceListFile"));
        pb_IncidenceListFile->setMinimumSize(QSize(40, 40));
        pb_IncidenceListFile->setMaximumSize(QSize(40, 40));
        pb_IncidenceListFile->setCursor(QCursor(Qt::PointingHandCursor));
        pb_IncidenceListFile->setStyleSheet(QString::fromUtf8("image: url(:/icons/openlist.png);"));

        horizontalLayout->addWidget(pb_IncidenceListFile);

        saveButton = new QPushButton(horizontalWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(40, 40));
        saveButton->setMaximumSize(QSize(40, 40));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QString::fromUtf8("image: url(:/icons/savef.png);"));

        horizontalLayout->addWidget(saveButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_ConnectGraph = new QPushButton(horizontalWidget);
        pb_ConnectGraph->setObjectName(QString::fromUtf8("pb_ConnectGraph"));
        pb_ConnectGraph->setMinimumSize(QSize(40, 40));
        pb_ConnectGraph->setMaximumSize(QSize(40, 40));
        pb_ConnectGraph->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ConnectGraph->setStyleSheet(QString::fromUtf8("image: url(:/icons/fullgraph.png);"));

        horizontalLayout->addWidget(pb_ConnectGraph);

        pb_DisconnectGraph = new QPushButton(horizontalWidget);
        pb_DisconnectGraph->setObjectName(QString::fromUtf8("pb_DisconnectGraph"));
        pb_DisconnectGraph->setMinimumSize(QSize(40, 40));
        pb_DisconnectGraph->setMaximumSize(QSize(40, 40));
        pb_DisconnectGraph->setCursor(QCursor(Qt::PointingHandCursor));
        pb_DisconnectGraph->setStyleSheet(QString::fromUtf8("image: url(:/icons/breakgraph.png);"));

        horizontalLayout->addWidget(pb_DisconnectGraph);

        pb_LengthOfEdges = new QPushButton(horizontalWidget);
        pb_LengthOfEdges->setObjectName(QString::fromUtf8("pb_LengthOfEdges"));
        pb_LengthOfEdges->setMinimumSize(QSize(40, 40));
        pb_LengthOfEdges->setMaximumSize(QSize(40, 40));
        pb_LengthOfEdges->setCursor(QCursor(Qt::PointingHandCursor));
        pb_LengthOfEdges->setStyleSheet(QString::fromUtf8("image: url(:/icons/edges.png);"));

        horizontalLayout->addWidget(pb_LengthOfEdges);

        pb_CoordinatesOfAllNode = new QPushButton(horizontalWidget);
        pb_CoordinatesOfAllNode->setObjectName(QString::fromUtf8("pb_CoordinatesOfAllNode"));
        pb_CoordinatesOfAllNode->setEnabled(true);
        pb_CoordinatesOfAllNode->setMinimumSize(QSize(40, 40));
        pb_CoordinatesOfAllNode->setMaximumSize(QSize(40, 40));
        pb_CoordinatesOfAllNode->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CoordinatesOfAllNode->setStyleSheet(QString::fromUtf8("image: url(:/icons/nodes.png);"));

        horizontalLayout->addWidget(pb_CoordinatesOfAllNode);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pb_DeleteSelectedNodes = new QPushButton(horizontalWidget);
        pb_DeleteSelectedNodes->setObjectName(QString::fromUtf8("pb_DeleteSelectedNodes"));
        pb_DeleteSelectedNodes->setMinimumSize(QSize(40, 40));
        pb_DeleteSelectedNodes->setMaximumSize(QSize(40, 40));
        pb_DeleteSelectedNodes->setCursor(QCursor(Qt::PointingHandCursor));
        pb_DeleteSelectedNodes->setStyleSheet(QString::fromUtf8("image: url(:/icons/delnode.png);"));

        horizontalLayout->addWidget(pb_DeleteSelectedNodes);

        pb_RemoveEdges = new QPushButton(horizontalWidget);
        pb_RemoveEdges->setObjectName(QString::fromUtf8("pb_RemoveEdges"));
        pb_RemoveEdges->setMinimumSize(QSize(40, 40));
        pb_RemoveEdges->setMaximumSize(QSize(40, 40));
        pb_RemoveEdges->setCursor(QCursor(Qt::PointingHandCursor));
        pb_RemoveEdges->setStyleSheet(QString::fromUtf8("image: url(:/icons/deledge.png);"));

        horizontalLayout->addWidget(pb_RemoveEdges);

        pb_ClearAll = new QPushButton(horizontalWidget);
        pb_ClearAll->setObjectName(QString::fromUtf8("pb_ClearAll"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(40);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(pb_ClearAll->sizePolicy().hasHeightForWidth());
        pb_ClearAll->setSizePolicy(sizePolicy);
        pb_ClearAll->setMinimumSize(QSize(40, 40));
        pb_ClearAll->setMaximumSize(QSize(40, 40));
        pb_ClearAll->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ClearAll->setStyleSheet(QString::fromUtf8("image: url(:/icons/dellall.png);"));

        horizontalLayout->addWidget(pb_ClearAll);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pb_CreateNode = new QPushButton(horizontalWidget);
        pb_CreateNode->setObjectName(QString::fromUtf8("pb_CreateNode"));
        pb_CreateNode->setMinimumSize(QSize(40, 40));
        pb_CreateNode->setMaximumSize(QSize(40, 40));
        pb_CreateNode->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CreateNode->setStyleSheet(QString::fromUtf8("image: url(:/icons/addnode.png);"));

        horizontalLayout->addWidget(pb_CreateNode);

        pb_CreateEdge = new QPushButton(horizontalWidget);
        pb_CreateEdge->setObjectName(QString::fromUtf8("pb_CreateEdge"));
        pb_CreateEdge->setMinimumSize(QSize(40, 40));
        pb_CreateEdge->setMaximumSize(QSize(40, 40));
        pb_CreateEdge->setCursor(QCursor(Qt::PointingHandCursor));
        pb_CreateEdge->setStyleSheet(QString::fromUtf8("image: url(:/icons/addedge.png);"));

        horizontalLayout->addWidget(pb_CreateEdge);

        lineEdit_Source = new QLineEdit(horizontalWidget);
        lineEdit_Source->setObjectName(QString::fromUtf8("lineEdit_Source"));
        lineEdit_Source->setMinimumSize(QSize(40, 0));
        lineEdit_Source->setMaximumSize(QSize(50, 16777215));
        lineEdit_Source->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(lineEdit_Source);

        lineEdit_Dest = new QLineEdit(horizontalWidget);
        lineEdit_Dest->setObjectName(QString::fromUtf8("lineEdit_Dest"));
        lineEdit_Dest->setMinimumSize(QSize(40, 0));
        lineEdit_Dest->setMaximumSize(QSize(50, 16777215));
        lineEdit_Dest->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));

        horizontalLayout->addWidget(lineEdit_Dest);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushAlgorithm = new QPushButton(horizontalWidget);
        pushAlgorithm->setObjectName(QString::fromUtf8("pushAlgorithm"));
        sizePolicy.setHeightForWidth(pushAlgorithm->sizePolicy().hasHeightForWidth());
        pushAlgorithm->setSizePolicy(sizePolicy);
        pushAlgorithm->setMinimumSize(QSize(40, 40));
        pushAlgorithm->setMaximumSize(QSize(40, 40));
        pushAlgorithm->setCursor(QCursor(Qt::PointingHandCursor));
        pushAlgorithm->setStyleSheet(QString::fromUtf8("image: url(:/icons/algo.png);"));

        horizontalLayout->addWidget(pushAlgorithm);

        label = new QLabel(horizontalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(25, 25));
        label->setMaximumSize(QSize(25, 25));
        label->setStyleSheet(QString::fromUtf8("image: url(:/icons/speed.png);"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(55, 0));
        spinBox->setMaximumSize(QSize(55, 16777215));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding: 5px;"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(50);
        spinBox->setValue(100);

        horizontalLayout->addWidget(spinBox);

        pushFind = new QPushButton(horizontalWidget);
        pushFind->setObjectName(QString::fromUtf8("pushFind"));
        sizePolicy.setHeightForWidth(pushFind->sizePolicy().hasHeightForWidth());
        pushFind->setSizePolicy(sizePolicy);
        pushFind->setMinimumSize(QSize(40, 40));
        pushFind->setMaximumSize(QSize(40, 40));
        pushFind->setStyleSheet(QString::fromUtf8("border-image: url(:/icons/find.png);"));

        horizontalLayout->addWidget(pushFind);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushStop = new QPushButton(horizontalWidget);
        pushStop->setObjectName(QString::fromUtf8("pushStop"));
        sizePolicy.setHeightForWidth(pushStop->sizePolicy().hasHeightForWidth());
        pushStop->setSizePolicy(sizePolicy);
        pushStop->setMinimumSize(QSize(40, 40));
        pushStop->setMaximumSize(QSize(40, 40));
        pushStop->setCursor(QCursor(Qt::PointingHandCursor));
        pushStop->setStyleSheet(QString::fromUtf8("image: url(:/icons/return.png);"));

        horizontalLayout->addWidget(pushStop);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(horizontalWidget);

        horizontalWidget1 = new QWidget(centralWidget);
        horizontalWidget1->setObjectName(QString::fromUtf8("horizontalWidget1"));
        horizontalWidget1->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: rgb(225, 225, 225);"));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textBrowser = new QTextBrowser(horizontalWidget1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMaximumSize(QSize(300, 16777215));
        textBrowser->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(textBrowser);

        graphicsView = new GraphWidget(horizontalWidget1);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(graphicsView);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 6);

        verticalLayout_2->addWidget(horizontalWidget1);

        verticalLayout_2->setStretch(1, 5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\263\321\200\320\260\321\204\320\276\320\262 (Graphical graph editor)", nullptr));
        actionMenuFileExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        actionDeleteItem->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        action_Open_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_Save_File->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        action_createNode->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214  \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        action_createEdge->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\264\321\203\320\263\321\203", nullptr));
        action_delEdge->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\321\221\320\261\321\200\320\260", nullptr));
        action_clear_all->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        action_Algoritm->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        action_About->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#if QT_CONFIG(tooltip)
        OpenButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \320\263\321\200\320\260\321\204\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OpenButton->setText(QString());
#if QT_CONFIG(tooltip)
        pb_IncidenceListFile->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body style=\"background-color:white\"><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 \321\201\320\276 \321\201\320\277\320\270\321\201\320\272\320\276\320\274 \320\270\320\275\321\206\320\270\320\264\320\265\320\275\321\202\320\275\320\276\321\201\321\202\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_IncidenceListFile->setText(QString());
#if QT_CONFIG(tooltip)
        saveButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body style=\"background-color:white\"><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\260 \320\262 \321\204\320\260\320\271\320\273</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        saveButton->setText(QString());
#if QT_CONFIG(tooltip)
        pb_ConnectGraph->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\264\320\276 \320\277\320\276\320\273\320\275\320\276\320\263\320\276 \320\263\321\200\320\260\321\204\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_ConnectGraph->setText(QString());
#if QT_CONFIG(tooltip)
        pb_DisconnectGraph->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \321\200\320\265\320\261\321\200\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_DisconnectGraph->setText(QString());
#if QT_CONFIG(tooltip)
        pb_LengthOfEdges->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \321\200\320\265\320\261\320\265\321\200</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_LengthOfEdges->setText(QString());
#if QT_CONFIG(tooltip)
        pb_CoordinatesOfAllNode->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\320\265\321\200\321\210\320\270\320\275</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_CoordinatesOfAllNode->setText(QString());
#if QT_CONFIG(tooltip)
        pb_DeleteSelectedNodes->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_DeleteSelectedNodes->setText(QString());
#if QT_CONFIG(tooltip)
        pb_RemoveEdges->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_RemoveEdges->setText(QString());
#if QT_CONFIG(tooltip)
        pb_ClearAll->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_ClearAll->setText(QString());
#if QT_CONFIG(tooltip)
        pb_CreateNode->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_CreateNode->setText(QString());
#if QT_CONFIG(tooltip)
        pb_CreateEdge->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276 \320\274\320\265\320\266\320\264\321\203 \320\264\320\262\321\203\320\274\321\217 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\321\213\320\274\320\270 \320\262\320\265\321\200\321\210\320\270\320\275\320\260\320\274\320\270</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pb_CreateEdge->setText(QString());
#if QT_CONFIG(tooltip)
        lineEdit_Source->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\321\207\320\260\320\273\320\276 \320\264\321\203\320\263\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_Source->setText(QString());
#if QT_CONFIG(tooltip)
        lineEdit_Dest->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\272\320\276\320\275\320\265\321\206 \320\264\321\203\320\263\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushAlgorithm->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushAlgorithm->setText(QString());
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\210\320\260\320\263\320\260, \320\274\321\201</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QString());
#if QT_CONFIG(tooltip)
        pushFind->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\270\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\321\213</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushFind->setText(QString());
#if QT_CONFIG(tooltip)
        pushStop->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p style=\"background-color:white\"><span style=\" font-size:9pt; font-weight:600;\">\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\263\321\200\320\260\321\204 \320\262 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushStop->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\262\320\265\321\200\321\210\320\270\320\275\321\203 - \320\264\320\262\320\276\320\271\320\275\320\276\320\265 \320\275\320\260\320\266\320\260\321\202\320\270\320\265 \320\237\320\232\320\234.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'M"
                        "S Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\265 \321\200\320\265\320\261\321\200\320\276 - \320\262\321\213\320\264\320\265\320\273\320\270\321\202\320\265 \320\277\320\265\321\200\320\262\321\203\321\216 \320\262\320\265\321\200\321\210\320\270\320\275\321\203 \320\275\320\260\320\266\320\260\321\202\320\270\320\265\320\274 \320\233\320\232\320\234, \320\267\320\260\321\202\320\265\320\274 \320\267\320\260\320\266\320\260\321\202\321\214 Shift \320\270 \320\264\320\262\320\260\320\266\320\264\321\213 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\237\320\232\320\234 \320\277\320\276 \320\262\321\202\320\276\321\200\320\276\320\271 \320\262\320\265\321\200\321\210\320\270\320\275\320\265.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
