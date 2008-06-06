#ifndef SHAMANTREEWIDGETITEM_H
#define SHAMANTREEWIDGETITEM_H

#include <QTreeWidgetItem>

class ShamanTreeWidgetItem : public QTreeWidgetItem
{
public:
	ShamanTreeWidgetItem();
	virtual ~ShamanTreeWidgetItem();
	
	virtual bool operator<(const QTreeWidgetItem &other) const;
};

#endif /*SHAMANTREEWIDGETITEM_H*/
