#include "editdialogdelegate.h"
#include "QtWidgets"
#include "editcardialog.h"

EditDialogDelegate::EditDialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}


bool EditDialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *mymodel,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditCarDialog* editDialog = new EditCarDialog(dparentWidget);

        QString id = mymodel->data(mymodel->index(index.row(),0,index)).toString();
        QString brand = mymodel->data(mymodel->index(index.row(),1,index)).toString();
        QString model = mymodel->data(mymodel->index(index.row(),2,index)).toString();
        QString horsepower = mymodel->data(mymodel->index(index.row(),3,index)).toString();
        QString maxTorque = mymodel->data(mymodel->index(index.row(),4,index)).toString();
        QString accelerationTime = mymodel->data(mymodel->index(index.row(),5,index)).toString();


        editDialog->setUpDialog(id, brand, model, horsepower, maxTorque, accelerationTime);

        if (editDialog->exec() == QDialog::Accepted)
        {
            mymodel->setData(mymodel->index(index.row(),0,index),editDialog->id());
            mymodel->setData(mymodel->index(index.row(),1,index),editDialog->brand());
            mymodel->setData(mymodel->index(index.row(),2,index),editDialog->model());
            mymodel->setData(mymodel->index(index.row(),3,index),editDialog->horsepower());
            mymodel->setData(mymodel->index(index.row(),4,index),editDialog->maxTorque());
            mymodel->setData(mymodel->index(index.row(),5,index),editDialog->accelerationTime());
        }

         editDialog->deleteLater();
    }
    return false;
}

QWidget *EditDialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
