#include "branddelegate.h"
#include "QtWidgets"
#include "car.h"

BrandDelegate::BrandDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *BrandDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList brands = Car::getBrands();
    foreach  (QString brand, brands)
    {
        cmb->addItem(brand);
    }
    return cmb;
}

void BrandDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void BrandDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}
