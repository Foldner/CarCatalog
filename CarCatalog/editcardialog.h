#ifndef EDITCARDIALOG_H
#define EDITCARDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "car.h"


class EditCarDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit *editIDLine;
    QComboBox *editBrandComboBox;
    QLineEdit *editModelLine;
    QLineEdit *editHorsepowerLine;
    QLineEdit *editMaxTorqueLine;
    QLineEdit *editAccelerationTimeLine;

public:
    EditCarDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString brand() const;
    QString model() const;
    QString horsepower() const;
    QString maxTorque() const;
    QString accelerationTime() const;
    QString imageSource() const;

    void setUpDialog(QString id, QString brand, QString model, QString horsepower,
                     QString maxTorque, QString accelerationTime);
};

#endif // EDITCARDIALOG_H
