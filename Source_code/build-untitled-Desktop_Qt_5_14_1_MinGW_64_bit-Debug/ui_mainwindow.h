/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCrypto;
    QAction *actionHuffman;
    QAction *actionThe_shortest_path;
    QAction *actionDES;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextEdit *textEdit_6;
    QLabel *label_6;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_7;
    QTextEdit *textEdit_8;
    QLabel *label_22;
    QLineEdit *lineEdit;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *lineEdit_2;
    QWidget *page_2;
    QTextEdit *textEdit_7;
    QLabel *label_5;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QTextEdit *textEdit_9;
    QLabel *label_8;
    QPushButton *pushButton_29;
    QPushButton *pushButton;
    QWidget *page_7;
    QTextEdit *textEdit_18;
    QLabel *label_15;
    QTextEdit *textEdit_19;
    QTextEdit *textEdit_20;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QWidget *page_3;
    QLabel *label_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label_4;
    QTextEdit *textEdit_10;
    QLabel *label;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 568);
        MainWindow->setMouseTracking(false);
        actionCrypto = new QAction(MainWindow);
        actionCrypto->setObjectName(QString::fromUtf8("actionCrypto"));
        actionHuffman = new QAction(MainWindow);
        actionHuffman->setObjectName(QString::fromUtf8("actionHuffman"));
        actionThe_shortest_path = new QAction(MainWindow);
        actionThe_shortest_path->setObjectName(QString::fromUtf8("actionThe_shortest_path"));
        actionDES = new QAction(MainWindow);
        actionDES->setObjectName(QString::fromUtf8("actionDES"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 841, 521));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setEnabled(true);
        textEdit_6 = new QTextEdit(page);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setGeometry(QRect(70, 70, 381, 191));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 220, 68, 15));
        pushButton_13 = new QPushButton(page);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(520, 260, 201, 81));
        pushButton_14 = new QPushButton(page);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(520, 380, 201, 71));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(240, 460, 68, 15));
        textEdit_8 = new QTextEdit(page);
        textEdit_8->setObjectName(QString::fromUtf8("textEdit_8"));
        textEdit_8->setGeometry(QRect(70, 300, 381, 151));
        label_22 = new QLabel(page);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(230, 270, 71, 16));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(660, 80, 51, 31));
        label_23 = new QLabel(page);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(520, 160, 121, 31));
        label_24 = new QLabel(page);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(520, 70, 121, 51));
        lineEdit_2 = new QLineEdit(page);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(660, 160, 51, 31));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        textEdit_7 = new QTextEdit(page_2);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));
        textEdit_7->setGeometry(QRect(40, 70, 381, 111));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 190, 68, 15));
        pushButton_17 = new QPushButton(page_2);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(520, 90, 171, 81));
        pushButton_18 = new QPushButton(page_2);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(520, 240, 171, 81));
        textEdit_9 = new QTextEdit(page_2);
        textEdit_9->setObjectName(QString::fromUtf8("textEdit_9"));
        textEdit_9->setGeometry(QRect(40, 310, 381, 91));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(210, 420, 68, 15));
        pushButton_29 = new QPushButton(page_2);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setGeometry(QRect(490, 410, 231, 41));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 460, 181, 28));
        stackedWidget->addWidget(page_2);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        textEdit_18 = new QTextEdit(page_7);
        textEdit_18->setObjectName(QString::fromUtf8("textEdit_18"));
        textEdit_18->setGeometry(QRect(70, 60, 381, 111));
        label_15 = new QLabel(page_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(110, 180, 351, 16));
        textEdit_19 = new QTextEdit(page_7);
        textEdit_19->setObjectName(QString::fromUtf8("textEdit_19"));
        textEdit_19->setGeometry(QRect(70, 240, 381, 51));
        textEdit_20 = new QTextEdit(page_7);
        textEdit_20->setObjectName(QString::fromUtf8("textEdit_20"));
        textEdit_20->setGeometry(QRect(70, 330, 381, 111));
        label_16 = new QLabel(page_7);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(140, 300, 241, 16));
        label_17 = new QLabel(page_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(110, 450, 341, 16));
        pushButton_12 = new QPushButton(page_7);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(550, 80, 161, 61));
        pushButton_9 = new QPushButton(page_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(550, 230, 161, 61));
        stackedWidget->addWidget(page_7);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 180, 351, 16));
        pushButton_10 = new QPushButton(page_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(550, 230, 161, 61));
        pushButton_11 = new QPushButton(page_3);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(550, 80, 161, 61));
        textEdit_4 = new QTextEdit(page_3);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(70, 240, 381, 51));
        textEdit_5 = new QTextEdit(page_3);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(70, 60, 381, 111));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 300, 231, 16));
        textEdit_10 = new QTextEdit(page_3);
        textEdit_10->setObjectName(QString::fromUtf8("textEdit_10"));
        textEdit_10->setGeometry(QRect(70, 340, 381, 111));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 460, 81, 16));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionThe_shortest_path);
        toolBar->addAction(actionHuffman);
        toolBar->addAction(actionCrypto);
        toolBar->addAction(actionDES);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCrypto->setText(QCoreApplication::translate("MainWindow", "AES", nullptr));
        actionHuffman->setText(QCoreApplication::translate("MainWindow", "Huffman", nullptr));
        actionThe_shortest_path->setText(QCoreApplication::translate("MainWindow", "Communication_path", nullptr));
        actionDES->setText(QCoreApplication::translate("MainWindow", "DES", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", nullptr));
        textEdit_6->setPlaceholderText(QString());
        label_6->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Kruskal", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Prim", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        textEdit_8->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Number of edges: ", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Number of nodes: ", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "10", nullptr));
        textEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "I am from China", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "String", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "encode", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "decode", nullptr));
        textEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "010101", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Open the frequency file", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Show encoded files", nullptr));
        textEdit_18->setPlaceholderText(QCoreApplication::translate("MainWindow", "abcdefgh", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Plaintext(Plain text needs to be 8 bytes)", nullptr));
        textEdit_19->setPlaceholderText(QCoreApplication::translate("MainWindow", "abcdefgh", nullptr));
        textEdit_20->setPlaceholderText(QCoreApplication::translate("MainWindow", "82182999414A23FB", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Keys(Key needs to be 8 bytes)", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Ciphertext(Cipher text in hexadecimal form)", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "DES_encode", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "DES_decode", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Plaintext(Plain text needs to be 16 bytes)", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "AES_decode", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "AES_encode", nullptr));
        textEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f", nullptr));
        textEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "00 11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Keys(Key needs to be 8 bytes)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ciphertext", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
