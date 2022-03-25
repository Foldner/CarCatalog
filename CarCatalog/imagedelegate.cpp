#include "imagedelegate.h"
#include "QtWidgets"
#include "editcardialog.h"

ImageDelegate::ImageDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

QWidget *ImageDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
