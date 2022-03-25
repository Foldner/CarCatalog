#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Car* car1 = new Car("0", "BMW", "X5 xDrive40i", "340", "450", "5,5", ":/images/car1.png", this);
    Car* car2 = new Car("1","Honda","Brio", "245", "221", "8,3",":/images/car2.png", this);
    Car* car3 = new Car("2","Toyota","Highlander", "89", "110", "10",":/images/car3.png", this);
    addCar(car1);
    addCar(car2);
    addCar(car3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return cars.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 7;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString value = "";
        Car* car = cars.at(index.row());

        switch(index.column())
        {
        case 0: value = car->getID(); break;
        case 1: value = value = car->getBrand(); break;
        case 2: value = value = car->getModel(); break;
        case 3: value = car->getHorsepower(); break;
        case 4: value = car->getMaxTorque(); break;
        case 5: value = car->getAccelerationTime(); break;
        //case 6: value = car->getImageSource(); break;
        default: value = ""; break;
        }

        return value;
    }
    if (role == Qt::DecorationRole && index.column() == 6)
    {
        Car* car = cars.at(index.row());
        return QPixmap(QPixmap(car->getImageSource()));
    }

    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Марка");
            case 2:
                return QString("Модель");
            case 3:
                return QString("Мощность двигателя, л.с.");
            case 4:
                return QString("Крутящий момент, Н*м");
            case 5:
                return QString("Разгон 0-100 км/ч");
            case 6:
                return QString("Изображение");
            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole || role == Qt::DecorationRole)
    {
        Car* car = cars.at(index.row());
        switch(index.column())
        {
        case 0: car->setID(value.toString()); break;
        case 1: car->setBrand(value.toString()); break;
        case 2: car->setModel(value.toString()); break;
        case 3: car->setHorsepower(value.toString()); break;
        case 4: car->setMaxTorque(value.toString()); break;
        case 5: car->setAccelerationTime(value.toString()); break;
        case 6: car->setImageSource(value.toString()); break;
        }
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyModel::addCar(Car *car)
{
    beginInsertRows(QModelIndex(), cars.size(), cars.size());
    cars.append(car);
    endInsertRows();
}

void MyModel::deleteCar(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    cars.removeAt(row);
    endRemoveRows();
}
