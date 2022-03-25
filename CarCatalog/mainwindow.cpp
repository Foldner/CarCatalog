#include "branddelegate.h"
#include "editcardialog.h"
#include "editdialogdelegate.h"
#include "imagedelegate.h"
#include "linedelegate.h"
#include "mainwindow.h"
#include "mymodel.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    tableView = new QTableView();
    myModel = new MyModel(this);

    tableView->setModel(myModel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    EditDialogDelegate* editDialogDelegate = new EditDialogDelegate(nullptr,this);
    tableView->setItemDelegateForColumn(0, editDialogDelegate);

    BrandDelegate* brandDelegate = new BrandDelegate();
    tableView->setItemDelegateForColumn(1,brandDelegate);

    LineDelegate* lineDelegate = new LineDelegate();
    tableView->setItemDelegateForColumn(2,lineDelegate);
    tableView->setItemDelegateForColumn(3,lineDelegate);
    tableView->setItemDelegateForColumn(4,lineDelegate);
    tableView->setItemDelegateForColumn(5,lineDelegate);

    ImageDelegate* imageDelegate = new ImageDelegate();
    tableView->setItemDelegateForColumn(6,imageDelegate);

    QGridLayout* layout= new QGridLayout();
    layout->addWidget(tableView,1,1,1,2);

    QPushButton* addCarButton = new QPushButton("Add row");
    QPushButton* deleteCarButton = new QPushButton("Delete row");

    layout->addWidget(addCarButton,2,1);
    layout->addWidget(deleteCarButton,2,2);

    QObject::connect(addCarButton,SIGNAL(clicked(bool)),this,SLOT(addRow()));
    QObject::connect(deleteCarButton,SIGNAL(clicked(bool)),this,SLOT(deleteRow()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(layout);
    this->setWindowTitle("CarCatalog");
    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow()
{
    EditCarDialog* addDialog = new EditCarDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Car* car = new Car(addDialog->id(),addDialog->brand(),addDialog->model(),
                           addDialog->horsepower(), addDialog->maxTorque(),
                           addDialog->accelerationTime(), addDialog->imageSource(), this);
        myModel->addCar(car);
    }

    addDialog->deleteLater();
}

void MainWindow::deleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    if (selList.isValid())
        myModel->deleteCar(selList.row());
}
