#ifndef PACKAGESMODEL_H
#define PACKAGESMODEL_H

#include <QAbstractItemModel>

class PackagesModel : public QAbstractItemModel
{
    Q_OBJECT
    public:
        PackagesModel(PackagesList *packages, QObject *parent);
        ~PackagesModel();

        virtual int columnCount(const QModelIndex & parent = QModelIndex()) const;
        virtual QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const;
        virtual QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
        virtual QModelIndex parent(const QModelIndex & index) const;
        virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;

    private:
        PackagesList *m_packages;
};

#endif
