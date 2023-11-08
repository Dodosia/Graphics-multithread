#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consistent_thread.h"
#include "multithread.h"
#include "parallel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Последовательный

    QVector<double> x(5), y(5);
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    x[4] = 4;

    ui->spinBox->setRange(0, 10000);
    ui->spinBox_2->setRange(0, 10000);
    ui->spinBox_3->setRange(0, 10000);
    ui->spinBox_4->setRange(0, 10000);
    ui->spinBox_5->setRange(0, 10000);
    ui->spinBox_6->setRange(0, 10000);
    ui->spinBox_7->setRange(0, 10000);
    ui->spinBox_8->setRange(0, 10000);
    ui->spinBox_9->setRange(0, 10000);
    ui->spinBox_10->setRange(0, 10000);

    ui->spinBox->setValue(2000);
    ui->spinBox_2->setValue(2000);

    ui->spinBox_3->setValue(3000);
    ui->spinBox_4->setValue(3000);

    ui->spinBox_5->setValue(4000);
    ui->spinBox_6->setValue(4000);

    ui->spinBox_7->setValue(5000);
    ui->spinBox_8->setValue(5000);

    ui->spinBox_9->setValue(6000);
    ui->spinBox_10->setValue(6000);

    n1 =  ui->spinBox->value();
    m1 =  ui->spinBox_2->value();

    n2 =  ui->spinBox_3->value();
    m2 =  ui->spinBox_4->value();

    n3 =  ui->spinBox_5->value();
    m3 =  ui->spinBox_6->value();

    n4 =  ui->spinBox_7->value();
    m4 =  ui->spinBox_8->value();

    n5 =  ui->spinBox_9->value();
    m5 =  ui->spinBox_10->value();

    Consistent_Thread ct1(n1, m1);
    y[0] = ct1.time;
    Consistent_Thread ct2(n2, m2);
    y[1] = ct2.time;
    Consistent_Thread ct3(n3, m3);
    y[2] = ct3.time;
    Consistent_Thread ct4(n4, m4);
    y[3] = ct4.time;
    Consistent_Thread ct5(n5, m5);
    y[4] = ct5.time;

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(250,0,0));
    ui->widget->graph(0)->setPen(pen);

    //Многопоточный 2 потока

    QVector<double> x1(5), y1(5);
    x1[0] = 0;
    x1[1] = 1;
    x1[2] = 2;
    x1[3] = 3;
    x1[4] = 4;

    Multithread mt1(n1, m1);
    y1[0] = mt1.time2;
    Multithread mt2(n2, m2);
    y1[1] = mt2.time2;
    Multithread mt3(n3, m3);
    y1[2] = mt3.time2;
    Multithread mt4(n4, m4);
    y1[3] = mt4.time2;
    Multithread mt5(n5, m5);
    y1[4] = mt5.time2;

    ui->widget->addGraph();
    ui->widget->graph(1)->setData(x1, y1);

    QPen pen1;
    pen1.setWidth(2);
    pen1.setColor(QColor(0,250,0));
    ui->widget->graph(1)->setPen(pen1);

    //4 потока
    QVector<double> x3(5), y3(5);
    x3[0] = 0;
    x3[1] = 1;
    x3[2] = 2;
    x3[3] = 3;
    x3[4] = 4;

    y3[0] = mt1.time4;
    y3[1] = mt2.time4;
    y3[2] = mt3.time4;
    y3[3] = mt4.time4;
    y3[4] = mt5.time4;

    ui->widget->addGraph();
    ui->widget->graph(2)->setData(x3, y3);

    QPen pen3;
    pen3.setWidth(2);
    pen3.setColor(QColor(0,150,150));
    ui->widget->graph(2)->setPen(pen3);

    //8 потоков
    QVector<double> x4(5), y4(5);
    x4[0] = 0;
    x4[1] = 1;
    x4[2] = 2;
    x4[3] = 3;
    x4[4] = 4;

    y4[0] = mt1.time8;
    y4[1] = mt2.time8;
    y4[2] = mt3.time8;
    y4[3] = mt4.time8;
    y4[4] = mt5.time8;

    ui->widget->addGraph();
    ui->widget->graph(3)->setData(x4, y4);

    QPen pen4;
    pen4.setWidth(2);
    pen4.setColor(QColor(150,150,150));
    ui->widget->graph(3)->setPen(pen4);

    //Параллельный
    QVector<double> x2(5), y2(5);
    x2[0] = 0;
    x2[1] = 1;
    x2[2] = 2;
    x2[3] = 3;
    x2[4] = 4;

    Parallel p1(n1, m1);
    y2[0] = p1.time;
    Parallel p2(n2, m2);
    y2[1] = p2.time;
    Parallel p3(n3, m3);
    y2[2] = p3.time;
    Parallel p4(n4, m4);
    y2[3] = p4.time;
    Parallel p5(n5, m5);
    y2[4] = p5.time;

    ui->widget->addGraph();
    ui->widget->graph(4)->setData(x2, y2);

    QPen pen2;
    pen2.setWidth(2);
    pen2.setColor(QColor(0,0,250));
    ui->widget->graph(4)->setPen(pen2);


    //Название осей и область видимости

    ui->widget->xAxis->setLabel("Размер матрицы");
    ui->widget->yAxis->setLabel("Время, мс");
    ui->widget->xAxis->setRange(0, 4);
    ui->widget->yAxis->setRange(0, 1000);

    //Название графиков (Legend)

    ui->widget->legend->setVisible(true);
    ui->widget->graph(0)->setName("Последовательный");
    ui->widget->graph(1)->setName("2 потока");
    ui->widget->graph(2)->setName("4 потока");
    ui->widget->graph(3)->setName("8 потоков");
    ui->widget->graph(4)->setName("Параллельный");


    QCPTextElement *legendTitle = new QCPTextElement(ui->widget);
    legendTitle->setLayer(ui->widget->legend->layer());
    legendTitle->setFont(QFont("sans", 7, QFont::Bold));

    ui->widget->legend->addElement(0, 0, legendTitle);

    //Таблица
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Размер"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Посл., мс"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("2 пот., мс"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("4 пот., мс"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("8 пот., мс"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Пар., мс"));

    //Подгонаяем размер под окно
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* header2 = ui->tableWidget->verticalHeader();
    header2->setSectionResizeMode(QHeaderView::Stretch);

    //Заполняем

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(ct1.n) + "x" + QString::number(ct1.m)));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(ct2.n) + "x" + QString::number(ct2.m)));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(ct3.n) + "x" + QString::number(ct3.m)));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(QString::number(ct4.n) + "x" + QString::number(ct4.m)));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(QString::number(ct5.n) + "x" + QString::number(ct5.m)));

    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(ct1.time)));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(ct2.time)));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(ct3.time)));
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(ct4.time)));
    ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(ct5.time)));

    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(mt1.time2)));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(mt2.time2)));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(mt3.time2)));
    ui->tableWidget->setItem(3, 2, new QTableWidgetItem(QString::number(mt4.time2)));
    ui->tableWidget->setItem(4, 2, new QTableWidgetItem(QString::number(mt5.time2)));

    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(mt1.time4)));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(mt2.time4)));
    ui->tableWidget->setItem(2, 3, new QTableWidgetItem(QString::number(mt3.time4)));
    ui->tableWidget->setItem(3, 3, new QTableWidgetItem(QString::number(mt4.time4)));
    ui->tableWidget->setItem(4, 3, new QTableWidgetItem(QString::number(mt5.time4)));

    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(mt1.time4)));
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem(QString::number(mt2.time4)));
    ui->tableWidget->setItem(2, 4, new QTableWidgetItem(QString::number(mt3.time4)));
    ui->tableWidget->setItem(3, 4, new QTableWidgetItem(QString::number(mt4.time4)));
    ui->tableWidget->setItem(4, 4, new QTableWidgetItem(QString::number(mt5.time4)));

    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(p1.time)));
    ui->tableWidget->setItem(1, 5, new QTableWidgetItem(QString::number(p2.time)));
    ui->tableWidget->setItem(2, 5, new QTableWidgetItem(QString::number(p3.time)));
    ui->tableWidget->setItem(3, 5, new QTableWidgetItem(QString::number(p4.time)));
    ui->tableWidget->setItem(4, 5, new QTableWidgetItem(QString::number(p5.time)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    n1 =  ui->spinBox->value();
    m1 =  ui->spinBox_2->value();

    n2 =  ui->spinBox_3->value();
    m2 =  ui->spinBox_4->value();

    n3 =  ui->spinBox_5->value();
    m3 =  ui->spinBox_6->value();

    n4 =  ui->spinBox_7->value();
    m4 =  ui->spinBox_8->value();

    n5 =  ui->spinBox_9->value();
    m5 =  ui->spinBox_10->value();

    QVector<double> x(5), y(5);
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    x[4] = 4;

    Consistent_Thread ct1(n1, m1);
    y[0] = ct1.time;
    Consistent_Thread ct2(n2, m2);
    y[1] = ct2.time;
    Consistent_Thread ct3(n3, m3);
    y[2] = ct3.time;
    Consistent_Thread ct4(n4, m4);
    y[3] = ct4.time;
    Consistent_Thread ct5(n5, m5);
    y[4] = ct5.time;

    ui->widget->graph(0)->setData(x, y);

    QVector<double> x1(5), y1(5);
    x1[0] = 0;
    x1[1] = 1;
    x1[2] = 2;
    x1[3] = 3;
    x1[4] = 4;

    Multithread mt1(n1, m1);
    y1[0] = mt1.time2;
    Multithread mt2(n2, m2);
    y1[1] = mt2.time2;
    Multithread mt3(n3, m3);
    y1[2] = mt3.time2;
    Multithread mt4(n4, m4);
    y1[3] = mt4.time2;
    Multithread mt5(n5, m5);
    y1[4] = mt5.time2;

    ui->widget->graph(1)->setData(x1, y1);

    QVector<double> x3(5), y3(5);
    x3[0] = 0;
    x3[1] = 1;
    x3[2] = 2;
    x3[3] = 3;
    x3[4] = 4;

    y3[0] = mt1.time4;
    y3[1] = mt2.time4;
    y3[2] = mt3.time4;
    y3[3] = mt4.time4;
    y3[4] = mt5.time4;

    ui->widget->graph(2)->setData(x3, y3);

    QVector<double> x4(5), y4(5);
    x4[0] = 0;
    x4[1] = 1;
    x4[2] = 2;
    x4[3] = 3;
    x4[4] = 4;

    y4[0] = mt1.time8;
    y4[1] = mt2.time8;
    y4[2] = mt3.time8;
    y4[3] = mt4.time8;
    y4[4] = mt5.time8;

    ui->widget->graph(3)->setData(x4, y4);

    QVector<double> x2(5), y2(5);
    x2[0] = 0;
    x2[1] = 1;
    x2[2] = 2;
    x2[3] = 3;
    x2[4] = 4;

    Parallel p1(n1, m1);
    y2[0] = p1.time;
    Parallel p2(n2, m2);
    y2[1] = p2.time;
    Parallel p3(n3, m3);
    y2[2] = p3.time;
    Parallel p4(n4, m4);
    y2[3] = p4.time;
    Parallel p5(n5, m5);
    y2[4] = p5.time;

    ui->widget->graph(4)->setData(x2, y2);

    ui->widget->replot();

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(ct1.n) + "x" + QString::number(ct1.m)));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(ct2.n) + "x" + QString::number(ct2.m)));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(ct3.n) + "x" + QString::number(ct3.m)));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(QString::number(ct4.n) + "x" + QString::number(ct4.m)));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(QString::number(ct5.n) + "x" + QString::number(ct5.m)));

    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(ct1.time)));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(ct2.time)));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(ct3.time)));
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(ct4.time)));
    ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(ct5.time)));

    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(mt1.time2)));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(mt2.time2)));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(mt3.time2)));
    ui->tableWidget->setItem(3, 2, new QTableWidgetItem(QString::number(mt4.time2)));
    ui->tableWidget->setItem(4, 2, new QTableWidgetItem(QString::number(mt5.time2)));

    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(mt1.time4)));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(mt2.time4)));
    ui->tableWidget->setItem(2, 3, new QTableWidgetItem(QString::number(mt3.time4)));
    ui->tableWidget->setItem(3, 3, new QTableWidgetItem(QString::number(mt4.time4)));
    ui->tableWidget->setItem(4, 3, new QTableWidgetItem(QString::number(mt5.time4)));

    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(mt1.time8)));
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem(QString::number(mt2.time8)));
    ui->tableWidget->setItem(2, 4, new QTableWidgetItem(QString::number(mt3.time8)));
    ui->tableWidget->setItem(3, 4, new QTableWidgetItem(QString::number(mt4.time8)));
    ui->tableWidget->setItem(4, 4, new QTableWidgetItem(QString::number(mt5.time8)));

    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(p1.time)));
    ui->tableWidget->setItem(1, 5, new QTableWidgetItem(QString::number(p2.time)));
    ui->tableWidget->setItem(2, 5, new QTableWidgetItem(QString::number(p3.time)));
    ui->tableWidget->setItem(3, 5, new QTableWidgetItem(QString::number(p4.time)));
    ui->tableWidget->setItem(4, 5, new QTableWidgetItem(QString::number(p5.time)));
}

