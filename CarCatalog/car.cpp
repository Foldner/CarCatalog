#include "car.h"
#include <QTableWidget>

Car::Car(QString ID, QString Brand, QString Model, QString Horsepower, QString MaxTorque,
                 QString AccelerationTime, QString ImageSource, QObject *parent): QObject(parent)
{
    id = ID;
    brand = Brand;
    model = Model;
    horsepower = Horsepower;
    maxTorque = MaxTorque;
    accelerationTime = AccelerationTime;
    imageSource = ImageSource;
    //QTableWidgetItem *picture = new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap(QPixmap(imageSource).scaled(50,50,Qt::IgnoreAspectRatio)));
    //QPixMap pix;
//    picture->setData( QT::DecorationRole, QPixMap("car.png"));
//    QLabel *pictureLabel = new QLabel;
//    QTableWidgetItem *item = new QTableWidgetItem
//    item = new QTableWidgetItem;
//    item ->setData(QT::DecoraionRole, pix)
}

void Car::setID(QString value)
{
    id = value;
}
void Car::setBrand(QString value)
{
    brand = value;
}
void Car::setModel(QString value)
{
    model = value;
}
void Car::setHorsepower(QString value)
{
    horsepower = value;
}
void Car::setMaxTorque(QString value)
{
    maxTorque = value;
}
void Car::setAccelerationTime(QString value)
{
    accelerationTime = value;
}
void Car::setImageSource(QString value)
{
    imageSource = value;
    //picture->setData(Qt::DecorationRole, QPixmap(QPixmap(imageSource).scaled(50,50,Qt::IgnoreAspectRatio)));
}

QString Car::getID()
{
    return id;
}
QString Car::getBrand()
{
    return brand;
}
QString Car::getModel()
{
    return model;
}
QString Car::getHorsepower()
{
    return horsepower;
}
QString Car::getMaxTorque()
{
    return maxTorque;
}
QString Car::getAccelerationTime()
{
    return accelerationTime;
}
QString Car::getImageSource()
{
    return imageSource;
}

QStringList Car::getBrands()
{
    QStringList value;
    value.append("BMW");
    value.append("Honda");
    value.append("Toyota");
    return value;
}
Car::~Car()
{
}
