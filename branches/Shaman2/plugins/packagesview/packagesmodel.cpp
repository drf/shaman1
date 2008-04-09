#include "packagesmodel.h"

PackagesModel::PackagesModel(PackagesList *packages, QObject *parent)
{
}

PackagesModel::~PackagesModel()
{
}

int PackagesModel::columnCount(const QModelIndex & parent)) const
{
}

QVariant PackagesModel::data (const QModelIndex & index, int role = Qt::DisplayRole) const
{
}

QModelIndex PackagesModel::index(int row, int column, const QModelIndex & parent) const
{
}

QModelIndex PackagesModel::parent(const QModelIndex & index) const
{
    if (!index.isValid())
        return QModelIndex();
}

int PackagesModel::rowCount(const QModelIndex & parent) const
{
}
