#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

private slots:
    void on_actionCrypto_triggered();

    void on_actionHuffman_triggered();

    void on_actionThe_shortest_path_triggered();

    void start();

    void aes_decode();

    void run_Kruskal();

    void run_Prim();

    void on_pushButton_29_clicked();

    void run_Huffman_encode();

    void run_Huffman_decode();

    void on_pushButton_clicked();

    void on_actionDES_triggered();

    void run_DES_encode();

    void run_DES_decode();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
