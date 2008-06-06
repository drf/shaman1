#include "ShamanTreeWidgetItem.h"

ShamanTreeWidgetItem::ShamanTreeWidgetItem()
 : QTreeWidgetItem()
{
}

ShamanTreeWidgetItem::~ShamanTreeWidgetItem()
{
}

bool ShamanTreeWidgetItem::operator<(const QTreeWidgetItem &other) const
{
    int column = treeWidget() ? treeWidget()->sortColumn() : 0;
    
    if ( column != 4 )
        return text(column) < other.text(column);
    else
        return data(column, Qt::UserRole).toInt() < other.data(column, Qt::UserRole).toInt(); 
}
