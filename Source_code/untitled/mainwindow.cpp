#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include "aes.h"
#include "kruskal.h"
#include "Prim.h"
#include <QDesktopServices>
#include "Huffman.h"
#include "des.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_6->setPlaceholderText("0 1 4\n0 4 1\n0 5 2\n1 2 6\n1 5 3\n2 3 6\n2 5 5\n3 4 4\n3 5 5\n4 5 3");
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(start()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(aes_decode()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(run_Kruskal()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(run_Prim()));
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(run_Huffman_encode()));
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(run_Huffman_decode()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(run_DES_encode()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(run_DES_decode()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCrypto_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_actionDES_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_actionHuffman_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionThe_shortest_path_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::start()
{
    ui->textEdit_10->clear();

    uint8_t in[]= {
        0x00, 0x11, 0x22, 0x33,
        0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff
    };
    uint8_t out[16];
    uint8_t key[]={
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13,
        0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b,
        0x1c, 0x1d, 0x1e, 0x1f
    };
    QString content = ui->textEdit_5->toPlainText();
    QString key_content = ui->textEdit_4->toPlainText();

    // Remove spaces from the input string
    content.remove(QChar(' '));
    key_content.remove(QChar(' '));

    if (!content.isEmpty()) {
        QRegExp hexRegex("^[0-9a-fA-F]+$");
        if (hexRegex.exactMatch(content)) {
            QByteArray contentByteArray = QByteArray::fromHex(content.toUtf8());
            if (contentByteArray.size() == sizeof(in)) {
                memcpy(in, contentByteArray.constData(), sizeof(in));
            } else {
                ui->textEdit_10->append("Plaintext: You should enter 16 characters.");
                return;
            }
        } else {
            ui->textEdit_10->append("Plaintext: The characters entered must be hexadecimal.");
            return;
        }
    }
    if (!key_content.isEmpty()) {
        QRegExp hexRegex("^[0-9a-fA-F]+$");
        if (hexRegex.exactMatch(key_content)) {
            QByteArray contentByteArray = QByteArray::fromHex(key_content.toUtf8());
            if (contentByteArray.size() == 16) {
                memcpy(key, contentByteArray.constData(), sizeof(key));
            } else {
                ui->textEdit_10->append("Keys: You should enter 16 characters.");
                return;
            }
        } else {
            ui->textEdit_10->append("Keys: The characters entered must be hexadecimal.");
            return;
        }
    }

    runAES(in, key, out);
    QString result;
    for (int i = 0; i < sizeof(out); i++) {
        result += QString("%1 ").arg(out[i], 2, 16, QLatin1Char('0'));
    }
    ui->textEdit_10->append(result.trimmed());
}


void MainWindow::aes_decode(){
    ui->textEdit_5->clear();

    uint8_t out[16];
    uint8_t key[] = {
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13,
        0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b,
        0x1c, 0x1d, 0x1e, 0x1f
    };
    uint8_t msg[16];
    QString content = ui->textEdit_10->toPlainText();
    QString key_content = ui->textEdit_4->toPlainText();

    content.remove(QChar(' '));
    key_content.remove(QChar(' '));

    if (!content.isEmpty()) {
        QRegExp hexRegex("^[0-9a-fA-F]+$");
        if (hexRegex.exactMatch(content)) {
            QByteArray contentByteArray = QByteArray::fromHex(content.toUtf8());
            if (contentByteArray.size() == sizeof(out)) {
                memcpy(out, contentByteArray.constData(), sizeof(out));
            } else {
                ui->textEdit_5->append("Ciphertext: You should enter 32 characters.");
                return;
            }
        } else {
            ui->textEdit_5->append("Ciphertext: The characters entered must be hexadecimal.");
            return;
        }
    }else{
        return;
    }

    if (!key_content.isEmpty()) {
        QRegExp hexRegex("^[0-9a-fA-F]+$");
        if (hexRegex.exactMatch(key_content)) {
            QByteArray contentByteArray = QByteArray::fromHex(key_content.toUtf8());
            if (contentByteArray.size() == 16) {
                memcpy(key, contentByteArray.constData(), sizeof(key));
            } else {
                ui->textEdit_5->append("Keys: You should enter 32 characters.");
                return;
            }
        } else {
            ui->textEdit_5->append("Keys: The characters entered must be hexadecimal.");
            return;
        }
    }

    runAES_de(msg,key,out);

    QString result;
    for (int i = 0; i < sizeof(msg); i++) {
        result += QString("%1 ").arg(msg[i], 2, 16, QLatin1Char('0'));
    }
    ui->textEdit_5->append(result.trimmed());
}


void MainWindow::run_Kruskal(){
    ui->textEdit_8->clear();
    int m = 6;
    int n = 10;
    int edges[500][3];
    int graph[10][3] = {
        {0, 1, 4},
        {0, 4, 1},
        {0, 5, 2},
        {1, 2, 6},
        {1, 5, 3},
        {2, 3, 6},
        {2, 5, 5},
        {3, 4, 4},
        {3, 5, 5},
        {4, 5, 3}
    };
    QString content = ui->textEdit_6->toPlainText().trimmed();

    int m_v = ui->lineEdit->text().toInt();
    if (m_v) {
        m = m_v;
    }

    int n_v = ui->lineEdit_2->text().toInt();
    if (n_v) {
        n = n_v;
    }
    if (!content.isEmpty()) {
        QStringList lines = content.split('\n');
        for (int i = 0; i < n; ++i) {
            QStringList values = lines[i].split(' ');
            for (int j = 0; j < 3; ++j) {
                edges[i][j] = values[j].toInt();
            }
        }
    } else {
        for(int i = 0; i < 10; i++) {
            edges[i][0] = graph[i][0];
            edges[i][1] = graph[i][1];
            edges[i][2] = graph[i][2];
        }
    }
    QString result;
    result += QString::fromStdString(runKruskal(m, n, edges));
    std::cout<<runKruskal(m, n, edges);
    ui->textEdit_8->append(result);
}
void MainWindow::run_Prim(){
    ui->textEdit_8->clear();
    int m = 6;
    int n = 10;
    int edges[500][3];
    int graph[10][3] = {
        {0, 1, 4},
        {0, 4, 1},
        {0, 5, 2},
        {1, 2, 6},
        {1, 5, 3},
        {2, 3, 6},
        {2, 5, 5},
        {3, 4, 4},
        {3, 5, 5},
        {4, 5, 3}
    };
    QString content = ui->textEdit_6->toPlainText().trimmed();

    int m_v = ui->lineEdit->text().toInt();
    if (m_v) {
        m = m_v;
    }

    int n_v = ui->lineEdit_2->text().toInt();
    if (n_v) {
        n = n_v;
    }
    if (!content.isEmpty()) {
        QStringList lines = content.split('\n');
        for (int i = 0; i < n; ++i) {
            QStringList values = lines[i].split(' ');
            for (int j = 0; j < 3; ++j) {
                edges[i][j] = values[j].toInt();
            }
        }
    } else {
        for(int i = 0; i < 10; i++) {
            edges[i][0] = graph[i][0];
            edges[i][1] = graph[i][1];
            edges[i][2] = graph[i][2];
        }
    }
    QString result;
    result += QString::fromStdString(runPrim(m, n, edges));
    //std::cout<<runPrim(m, n, edges);
    ui->textEdit_8->append(result);
}

void MainWindow::on_pushButton_29_clicked()
{
    QDesktopServices::openUrl(QUrl("Frequency.txt"));
}

void MainWindow::run_Huffman_encode(){
    ui->textEdit_9->clear();
    std::string input = "I am from China";  // 默认值
    QString content = ui->textEdit_7->toPlainText().trimmed();

    if (!content.isEmpty()) {
        input = content.toStdString();  // 如果用户输入非空，则使用用户输入的内容
    }

    QString result;
    result += QString::fromStdString(runHuffman_encode(input));
    ui->textEdit_9->append(result);
}

void MainWindow::run_Huffman_decode(){
    ui->textEdit_7->clear();
    std::string input = "01010111";  // 默认值
    QString content = ui->textEdit_9->toPlainText().trimmed();

    if (!content.isEmpty()) {
        input = content.toStdString();  // 如果用户输入非空，则使用用户输入的内容
    }

    QString result;
    result += QString::fromStdString(runHuffman_decode(input));
    ui->textEdit_7->append(result);
}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("output.txt"));
}

void MainWindow::run_DES_encode() {
    ui->textEdit_20->clear();

    std::string My_message = "abcdefgh";
    std::string My_key = "abcdefgh";

    QString content = ui->textEdit_18->toPlainText().trimmed();
    QString key = ui->textEdit_19->toPlainText().trimmed();

    if (!content.isEmpty()) {
        My_message = content.toStdString();
    }

    if (!key.isEmpty()) {
        My_key = key.toStdString();
    }

    char *char_message = const_cast<char*>(My_message.c_str());
    char *char_key = const_cast<char*>(My_key.c_str());

    QString result = QString::fromStdString(runDES_encode(char_key, char_message));
    ui->textEdit_20->append(result);
}

void MainWindow::run_DES_decode(){
    ui->textEdit_18->clear();

    std::string My_message_hex="82182999414A23FB";
    std::string My_key = "abcdefgh";

    QString content = ui->textEdit_20->toPlainText().trimmed();
    QString key = ui->textEdit_19->toPlainText().trimmed();

    if (!content.isEmpty()) {
        My_message_hex = content.toStdString();
    }

    if (!key.isEmpty()) {
        My_key = key.toStdString();
    }

    char *char_message = const_cast<char*>(My_message_hex.c_str());
    char *char_key = const_cast<char*>(My_key.c_str());

    QString result = QString::fromStdString(runDES_decode(char_message,char_key));
    ui->textEdit_18->append(result);

}
