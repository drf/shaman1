#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>

namespace Ui {
    class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = 0);

    QString server() const;
    void setServer(const QString &server);

Q_SIGNALS:
    void prefer();
    void defer();
    void remove();

private:
    Ui::ServerWidget *m_ui;
};

#endif // SERVERWIDGET_H
