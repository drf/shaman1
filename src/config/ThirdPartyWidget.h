#ifndef THIRDPARTYWIDGET_H
#define THIRDPARTYWIDGET_H

#include <QWidget>

namespace Ui {
    class ThirdPartyWidget;
}

class ServerWidget;

class ThirdPartyWidget : public QWidget
{
    Q_OBJECT

public:
    ThirdPartyWidget(QWidget *parent = 0);

    void setMirrorName(const QString &name);
    QString mirrorName() const;
    QStringList databases() const;
    void setDatabases(const QStringList &db);

private:
    void reload();

Q_SIGNALS:
    void prefer();
    void defer();
    void remove();

private:
    Ui::ThirdPartyWidget *m_ui;
    QList<ServerWidget*> m_serverWidgets;
};

#endif // THIRDPARTYWIDGET_H
