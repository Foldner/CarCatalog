#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mymodel.h"
#include "QTableView"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addRow();
    void deleteRow();

private:
    Ui::MainWindow *ui;
    MyModel *myModel;
    QTableView *tableView;
};
#endif // MAINWINDOW_H
