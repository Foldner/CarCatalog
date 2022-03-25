#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H

#include "QtWidgets"

class ImageDelegate: public QStyledItemDelegate
{
    Q_OBJECT

public:
    ImageDelegate(QObject *parent = nullptr, QWidget* parentWidget = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    private:
    QWidget* dparentWidget;
};

#endif // IMAGEDELEGATE_H
