#include "packagesmodel.h"

PackagesModel::PackagesModel(PackagesList *packages, QObject *parent)
  : QAbstractItemModel(parent),
    m_packages(packages)
{
}

PackagesModel::~PackagesModel()
{
}

int PackagesModel::columnCount(const QModelIndex & parent)) const
{
    return 6;//TODO: What columns do we really want?
}

QVariant PackagesModel::data (const QModelIndex & index, int role = Qt::DisplayRole) const
{
    Package *package = m_packages.at(index.row());
    switch (index.column())
    {
        case 0:
            return package->statusText();
        case 1:
            return package->name();
        case 2:
            return package->actionText();
        case 3:
            return package->version();
        case 4:
            return package->repository();
        case 5:
            return package->groups();
    }
}

QModelIndex PackagesModel::index(int row, int column, const QModelIndex & parent) const
{
    //TODO:
}

QModelIndex PackagesModel::parent(const QModelIndex & index) const
{
    if (!index.isValid())
        return QModelIndex();
}

int PackagesModel::rowCount(const QModelIndex & parent) const
{
    return m_packages.count();
}
