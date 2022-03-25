#ifndef BRANDDELEGATE_H
#define BRANDDELEGATE_H


#include "QtWidgets"

class BrandDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    BrandDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};

#endif // BRANDDELEGATE_H
