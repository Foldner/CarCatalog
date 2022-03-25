#include "editcardialog.h"
#include "car.h"

EditCarDialog::EditCarDialog(QWidget* pwgt): QDialog(pwgt)
{
    editIDLine = new QLineEdit();
    editBrandComboBox = new QComboBox();
    editModelLine = new QLineEdit();
    editHorsepowerLine = new QLineEdit();
    editMaxTorqueLine = new QLineEdit();
    editAccelerationTimeLine = new QLineEdit();

    QStringList brands = Car::getBrands();
    foreach  (QString brand, brands)
    {
        editBrandComboBox->addItem(brand);
    }

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(new QLabel("id"),1,1);
    layout->addWidget(editIDLine,1,2);

    layout->addWidget(new QLabel("Марка"),2,1);
    layout->addWidget(editBrandComboBox,2,2);

    layout->addWidget(new QLabel("Модель"),3,1);
    layout->addWidget(editModelLine,3,2);

    layout->addWidget(new QLabel("Макс. мощность"),4,1);
    layout->addWidget(editHorsepowerLine,4,2);

    layout->addWidget(new QLabel("Крутящий момент"),5,1);
    layout->addWidget(editMaxTorqueLine,5,2);

    layout->addWidget(new QLabel("Время разгона"),6,1);
    layout->addWidget(editAccelerationTimeLine,6,2);

    QPushButton* buttonOk = new QPushButton("&ОК");

    layout->addWidget(buttonOk,7,1,1,2);

    QObject::connect(buttonOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(layout);
    this->setWindowTitle("Добавление/редактура");

    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditCarDialog::id() const
{
    return editIDLine->text();
}
QString EditCarDialog::brand() const
{
    return editBrandComboBox->currentText();
}
QString EditCarDialog::model() const
{
    return editModelLine->text();
}
QString EditCarDialog::horsepower() const
{
    return editHorsepowerLine->text();
}
QString EditCarDialog::maxTorque() const
{
    return editMaxTorqueLine->text();
}
QString EditCarDialog::accelerationTime() const
{
    return editAccelerationTimeLine->text();
}
QString EditCarDialog::imageSource() const
{
    if (editBrandComboBox->currentText() == "BMW") return ":/images/car1.png";
    if (editBrandComboBox->currentText() == "Honda") return ":/images/car2.png";
    else return ":/images/car3.png";
}

void EditCarDialog::setUpDialog(QString id, QString brand, QString model, QString horsepower,
                                QString maxTorque, QString accelerationTime)
{
    editIDLine->setText(id);

    int ind = editBrandComboBox->findText(brand);
    if (ind>=0)
    {
        editBrandComboBox->setCurrentIndex(ind);
    }

    editModelLine->setText(model);
    editHorsepowerLine->setText(horsepower);
    editMaxTorqueLine->setText(maxTorque);
    editAccelerationTimeLine->setText(accelerationTime);
}
