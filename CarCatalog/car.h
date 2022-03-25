#ifndef CAR_H
#define CAR_H

#include <QLabel>
#include <QObject>
#include <QTableWidget>
#include "QString"

class Car: public QObject
{
    Q_OBJECT

public:
    Car(QString ID, QString Brand, QString Model, QString Horsepower, QString MaxTorque,
        QString AccelerationTime, QString ImageSource, QObject *parent = nullptr );
    virtual ~Car();

    void setID(QString ID);
    void setBrand(QString Name);
    void setModel(QString Name);
    void setHorsepower(QString Name);
    void setMaxTorque(QString Name);
    void setAccelerationTime(QString Name);
    void setImageSource(QString Name);

    QString getID();
    QString getBrand();
    QString getModel();
    QString getHorsepower();
    QString getMaxTorque();
    QString getAccelerationTime();
    QString getImageSource();
    static QString idCounter;
    static QStringList getBrands();
    QTableWidgetItem *picture = new QTableWidgetItem;

private:
    QString id;
    QString brand;
    QString model;
    QString horsepower;
    QString maxTorque;
    QString accelerationTime;
    QString imageSource;
};

#endif // CAR_H
